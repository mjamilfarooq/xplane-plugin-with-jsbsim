/*
 * DDSInterface.h
 *
 *  Created on: Nov 8, 2012
 *      Author: sim-paf
 */

#ifndef DDSINTERFACE_H_
#define DDSINTERFACE_H_

//#include "FGFDMExec.h"
//#include "DDSEntityManager.h"

#include "ccpp_dds_dcps.h"
#include "CheckStatus.h"
#include "JSBSimDcps_impl.h"
#include "string.h"


namespace JSBSim {

using namespace DDS;

class DDSInterface{
public:
	DDSInterface();
	bool InitModel();
	bool Run(fdmdata&);
	virtual ~DDSInterface();


	//DDSEntityManager *mgr;
	DomainParticipantFactory_var dpf;
	DomainParticipant_var participant;

	Publisher_var publisher;
	Subscriber_var subscriber;

	/* QosPolicy holders */
	TopicQos reliable_topic_qos;
	TopicQos setting_topic_qos;
	PublisherQos pub_qos;
	DataWriterQos dw_qos;
	SubscriberQos sub_qos;

	DataWriter_ptr createDataWriter(bool autodispose_unregistered_instances, Topic_var &topic);



	Topic_var fdmdataTopic;
	fdmdataTypeSupport_var fdmdataType;
	//fdmdataDataWriter_var fdmdataWriter;
	fdmdataDataReader_var fdmdataReader;

	ReturnCode_t status;

	CORBA::String_var partition;

	void createParticipant(const char *, const char *);
	void deleteParticipant();
	void createTopic(TypeSupport *ts, char *topicName, Topic_var &topic);
	void createPublisher();
	void deletePublisher();
	void createSubscriber();
	void deleteSubscriber();


	void createDataWriter(bool autodispose_unregistered_instances, DataWriter_ptr writer, Topic_var &topic);
	void deleteDataWriter(DataWriter_ptr writer);

	DataReader_ptr createDataReader(Topic_var &topic);
	void deleteDataReader(DataReader_ptr reader);

	void publishfdmdataTopic();
	void readFDMTopic();
	void populateFDMTopic(fdmdata & fdmdata);

};

} /* namespace JSBSim */
#endif /* DDSINTERFACE_H_ */
