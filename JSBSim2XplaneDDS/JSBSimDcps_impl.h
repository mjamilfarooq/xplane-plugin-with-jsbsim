#ifndef JSBSIMDCPS_IMPL_H_
#define JSBSIMDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_JSBSim.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


namespace JSBSim {

    class  fdmdataTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        fdmdataTypeSupportFactory() {}
        virtual ~fdmdataTypeSupportFactory() {}
    private:
        ::DDS::DataWriter_ptr 
        create_datawriter (gapi_dataWriter handle);
    
        ::DDS::DataReader_ptr 
        create_datareader (gapi_dataReader handle);
    
        ::DDS::DataReaderView_ptr 
        create_view (gapi_dataReaderView handle);
    };
    
    class  fdmdataTypeSupport : public virtual fdmdataTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type(
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name() THROW_ORB_EXCEPTIONS;    
    
        fdmdataTypeSupport (void);
        virtual ~fdmdataTypeSupport (void);
    
    private:
        fdmdataTypeSupport (const fdmdataTypeSupport &);
        void operator= (const fdmdataTypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef fdmdataTypeSupportInterface_var fdmdataTypeSupport_var;
    typedef fdmdataTypeSupportInterface_ptr fdmdataTypeSupport_ptr;
    
    class  fdmdataDataWriter_impl : public virtual fdmdataDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance(
            const fdmdata & instance_data) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
            const fdmdata & instance_data,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
            const fdmdata & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value(
            fdmdata & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const fdmdata & instance_data) THROW_ORB_EXCEPTIONS;
    
    
        fdmdataDataWriter_impl (
            gapi_dataWriter handle
        );
    
        virtual ~fdmdataDataWriter_impl (void);
    
    private:
        fdmdataDataWriter_impl(const fdmdataDataWriter_impl &);
        void operator= (const fdmdataDataWriter &);
    };
    
    class  fdmdataDataReader_impl : public virtual fdmdataDataReader,
                                        public ::DDS::DataReader_impl
    {
        friend class fdmdataDataReaderView_impl;
    public:
        virtual ::DDS::ReturnCode_t read(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            fdmdata & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            fdmdata & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value(
            fdmdata & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const fdmdata & instance) THROW_ORB_EXCEPTIONS;
    
        fdmdataDataReader_impl (
            gapi_dataReader handle
        );
    
        virtual ~fdmdataDataReader_impl(void);
    
    private:
        fdmdataDataReader_impl(const fdmdataDataReader &);
        void operator= (const fdmdataDataReader &);
    
        static ::DDS::ReturnCode_t check_preconditions(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class  fdmdataDataReaderView_impl : public virtual fdmdataDataReaderView,
                                        public ::DDS::DataReaderView_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample(
            fdmdata & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample(
            fdmdata & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan(
            fdmdataSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value(
            fdmdata & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance(
            const fdmdata & instance) THROW_ORB_EXCEPTIONS;
    
        fdmdataDataReaderView_impl (
            gapi_dataReader handle
        );
    
        virtual ~fdmdataDataReaderView_impl(void);
    
    private:
        fdmdataDataReaderView_impl(const fdmdataDataReaderView &);
        void operator= (const fdmdataDataReaderView &);
    };
    
}

#endif
