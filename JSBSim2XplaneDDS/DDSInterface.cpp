/*
 * DDSInterface.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: sim-paf
 */

#include "DDSInterface.h"
#include "ccpp_JSBSim.h"
#include "JSBSim.h"
#include <iostream>
#include <fstream>

//char *topicName[]={"position","velocity","acceleration","DAQDATA","atitude","simulation","atmosphere","aerosurfaces","gears","inertia","aero","aerocoefficient","geometric","propulsion","initialConditions","subSystems","subSystemOut"};

char *topicName[]={"JSBSIMDATA","DAQDATA","FDMCMD","DAQANALOGDATA","CDUDATA"};
namespace JSBSim {


DDSInterface::DDSInterface( ){


	bool autodispose_unregistered_instances = false;


	createParticipant("MirageIFSim","MirageIFSim"); //same name for domain and partition
	cout<<"Participant Created!"<<endl;

	fdmdataType = new fdmdataTypeSupport();

	cout<<fdmdataType->get_type_name()<<" fdmdataType created!"<<endl;


	createTopic(fdmdataType,topicName[0],fdmdataTopic);
	cout<<"fdmdata Topic Created!"<<endl;



//	createPublisher();
//	cout<<"Publisher Created! "<<endl;
	createSubscriber();
	cout<<"Subscriber Created! "<<endl;
	//bool autodispose_unregistered_instances = false;



	fdmdataReader = fdmdataDataReader::_narrow(createDataReader(fdmdataTopic));
	cout<<"DataReader for FDM Data Created!"<<endl;

	// TODO Auto-generated constructor stub

}

void DDSInterface::createParticipant(const char *domainName, const char * partitionName){
	dpf = DomainParticipantFactory::get_instance();
	checkHandle(dpf.in(), "DDS::DomainParticipantFactory::get_instance");
	participant = dpf->create_participant(domainName, PARTICIPANT_QOS_DEFAULT, NULL,
	  STATUS_MASK_NONE);
	checkHandle(participant.in(), "DDS::DomainParticipantFactory::create_participant");
	partition = partitionName;
}


void DDSInterface::deleteParticipant(){

	status = dpf->delete_participant(participant.in());
	checkStatus(status, "DDS::DomainParticipant::delete_participant ");
}


void DDSInterface::createTopic(TypeSupport *ts, char *topicName, Topic_var &topic){


	 CORBA::String_var typeName;
	 typeName = ts->get_type_name();

	 status=ts->register_type(participant.in(),typeName);
	 checkStatus(status, "register_type");
	 Duration_t t;
	 t.sec = 1;
	 topic = participant->find_topic(topicName, t);

	 status = participant->get_default_topic_qos(reliable_topic_qos);
	 checkStatus(status, "DDS::DomainParticipant::get_default_topic_qos");
	 //reliable_topic_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
	 //reliable_topic_qos.durability.kind = TRANSIENT_DURABILITY_QOS;

	 /* Make the tailored QoS the new default. */
	 status = participant->set_default_topic_qos(reliable_topic_qos);
	 checkStatus(status, "DDS::DomainParticipant::set_default_topic_qos");

	 /* Use the changed policy when defining the HelloWorld topic */
	 if(topic == NULL)
	 {
		 cout <<"topic not found creating topic"<<endl;
	 topic = participant->create_topic(topicName, typeName, reliable_topic_qos,
			 NULL, STATUS_MASK_NONE);
	 checkHandle(topic.in(), "DDS::DomainParticipant::create_topic ()");
	 } else cout << "topic found!"<<endl;


}

void DDSInterface::createPublisher(){
	DataReaderQos qos;
	qos.reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
	status = participant->get_default_publisher_qos(pub_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
	pub_qos.partition.name.length(1);
	pub_qos.partition.name[0] = partition;

	publisher = participant->create_publisher(pub_qos, NULL, STATUS_MASK_NONE);
	checkHandle(publisher.in(), "DDS::DomainParticipant::create_publisher");
}

void DDSInterface::deletePublisher()
{
	status = participant->delete_publisher(publisher.in());
    checkStatus(status, "DDS::DomainParticipant::delete_publisher ");
}

void DDSInterface::createSubscriber()
{
  int status = participant->get_default_subscriber_qos(sub_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_subscriber_qos");
  sub_qos.partition.name.length(1);
  sub_qos.partition.name[0] = partition;
  subscriber = participant->create_subscriber(sub_qos, NULL, STATUS_MASK_NONE);
  checkHandle(subscriber.in(), "DDS::DomainParticipant::create_subscriber");
}

void DDSInterface::deleteSubscriber()
{
  status = participant->delete_subscriber(subscriber);
  checkStatus(status, "DDS::DomainParticipant::delete_subscriber ");
}

DataWriter_ptr DDSInterface::createDataWriter(bool autodispose_unregistered_instances, Topic_var &topic){
	DataWriter_ptr writer;
	status = publisher->get_default_datawriter_qos(dw_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
	status = publisher->copy_from_topic_qos(dw_qos, reliable_topic_qos);
	checkStatus(status, "DDS::Publisher::copy_from_topic_qos");
	// Set autodispose to false so that you can start
	// the subscriber after the publisher
	dw_qos.writer_data_lifecycle.autodispose_unregistered_instances =
	autodispose_unregistered_instances;
	writer = publisher->create_datawriter(topic.in(), dw_qos, NULL,
	STATUS_MASK_NONE);
	checkHandle(writer, "DDS::Publisher::create_datawriter");
	return writer;
}

void DDSInterface::deleteDataWriter(DataWriter_ptr writer){
	status = publisher->delete_datawriter(writer);
		checkStatus(status, "DDS::Publisher::delete_datawriter ");
}

DataReader_ptr DDSInterface::createDataReader(Topic_var &topic)
{
	DataReaderQos qos;
	subscriber->get_default_datareader_qos(qos);
	qos.history.depth = 5;
//	qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
//	qos.durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;
	DataReader_ptr reader = subscriber->create_datareader(topic.in(),
    qos, NULL, STATUS_MASK_NONE);
	checkHandle(reader, "DDS::Subscriber::create_datareader ()");
	return reader;
}


void DDSInterface::deleteDataReader(DataReader_ptr reader)
{
	status = subscriber->delete_datareader(reader);
	checkStatus(status, "DDS::Subscriber::delete_datareader ");
}


bool DDSInterface::Run(fdmdata &fdm){

	fdmdataSeq fdmdataList;
	SampleInfoSeq info;
	InstanceHandleSeq insthandleseq;


	fdmdataReader->get_matched_publications(insthandleseq);   // to be commented
	//cout<<"length: "<<insthandleseq.length()<<endl;

	ReturnCode_t status = fdmdataReader->take(fdmdataList, info, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);

	checkStatus(status, "fdmdataReader::take");

	if( status != RETCODE_OK) return false;

	fdm = fdmdataList[0];


	if (insthandleseq.length()!=0)
		return true;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void DDSInterface::readFDMTopic(){

	fdmdataSeq fdmdataList;
	SampleInfoSeq info;
	//cout<<"In FDMCMDtopic"<<endl;
	InstanceHandleSeq insthandleseq;

	fdmdataReader->get_matched_publications(insthandleseq);   // to be commented
	//cout<<"length: "<<insthandleseq.length()<<endl;

	ReturnCode_t status = fdmdataReader->take(fdmdataList, info, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);

	checkStatus(status, "fdmdataReader::take");

	if( status != RETCODE_OK) return ;


	//return fdmdataList[0];
	//populateFDMTopic(fdmdataList[0]);



}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void DDSInterface::populateFDMTopic(fdmdata & fdmdataRecieved){
	//cout<<"phi_rad "<<fdmdataRecieved.phi_rad<<endl;
	//cout<<"theta_rad "<<fdmdataRecieved.theta_rad<<endl;
	//cout<<"psi_rad "<<fdmdataRecieved.psi_rad<<endl;

}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


DDSInterface::~DDSInterface() {
	//mgr->deleteWriter();
	//deletePublisher();
	deleteDataReader(fdmdataReader);
	deleteSubscriber();
	deleteParticipant();

}

} /* namespace JSBSim */
