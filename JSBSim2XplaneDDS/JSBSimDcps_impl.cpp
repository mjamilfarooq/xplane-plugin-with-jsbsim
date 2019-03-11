#include "JSBSimDcps_impl.h"
#include "gapi.h"
#include "gapi_loanRegistry.h"
#include "JSBSimSplDcps.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


extern c_bool
__JSBSim_fdmdata__copyIn(
    c_base base,
    struct JSBSim::fdmdata *from,
    struct _JSBSim_fdmdata *to);

extern void
__JSBSim_fdmdata__copyOut(
    void *_from,
    void *_to);

// DDS JSBSim::fdmdata TypeSupportFactory Object Body

 DDS::DataWriter_ptr 
JSBSim::fdmdataTypeSupportFactory::create_datawriter (gapi_dataWriter handle)
{
    return new JSBSim::fdmdataDataWriter_impl(handle);
}

 DDS::DataReader_ptr 
JSBSim::fdmdataTypeSupportFactory::create_datareader (gapi_dataReader handle)
{
    return new JSBSim::fdmdataDataReader_impl (handle);
}


 DDS::DataReaderView_ptr 
JSBSim::fdmdataTypeSupportFactory::create_view (gapi_dataReaderView handle)
{
    return new JSBSim::fdmdataDataReaderView_impl (handle);
}

// DDS JSBSim::fdmdata TypeSupport Object Body

 JSBSim::fdmdataTypeSupport::fdmdataTypeSupport(void) :
    TypeSupport_impl(
        __JSBSim_fdmdata__name(),
        __JSBSim_fdmdata__keys(),
        JSBSim::fdmdataTypeSupport::metaDescriptor,
        (gapi_copyIn) __JSBSim_fdmdata__copyIn,
        (gapi_copyOut) __JSBSim_fdmdata__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<JSBSim::fdmdataSeq, JSBSim::fdmdata>,
        new  JSBSim::fdmdataTypeSupportFactory())
{
    // Parent constructor takes care of everything.
}

 JSBSim::fdmdataTypeSupport::~fdmdataTypeSupport(void)
{
    // Parent destructor takes care of everything.
}

 DDS::ReturnCode_t
JSBSim::fdmdataTypeSupport::register_type(
    DDS::DomainParticipant_ptr domain,
    const char * type_name) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

 char *
JSBSim::fdmdataTypeSupport::get_type_name() THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS JSBSim::fdmdata DataWriter_impl Object Body

 JSBSim::fdmdataDataWriter_impl::fdmdataDataWriter_impl (
    gapi_dataWriter handle
) : DDS::DataWriter_impl(handle)
{
    // Parent constructor takes care of everything.
}

 JSBSim::fdmdataDataWriter_impl::~fdmdataDataWriter_impl(void)
{
    // Parent destructor takes care of everything.
}

 DDS::InstanceHandle_t
JSBSim::fdmdataDataWriter_impl::register_instance(
    const JSBSim::fdmdata & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
}

 DDS::InstanceHandle_t 
JSBSim::fdmdataDataWriter_impl::register_instance_w_timestamp(
    const fdmdata & instance_data,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataWriter_impl::unregister_instance(
    const JSBSim::fdmdata & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);
}

 DDS::ReturnCode_t 
JSBSim::fdmdataDataWriter_impl::unregister_instance_w_timestamp(
    const fdmdata & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataWriter_impl::write(
    const JSBSim::fdmdata & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataWriter_impl::write_w_timestamp(
    const fdmdata & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataWriter_impl::dispose(
    const JSBSim::fdmdata & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}

 DDS::ReturnCode_t 
JSBSim::fdmdataDataWriter_impl::dispose_w_timestamp(
    const fdmdata & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataWriter_impl::writedispose(
    const JSBSim::fdmdata & instance_data,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose(&instance_data, handle);
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataWriter_impl::writedispose_w_timestamp(
    const fdmdata & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

 DDS::ReturnCode_t 
JSBSim::fdmdataDataWriter_impl::get_key_value(
    fdmdata & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
JSBSim::fdmdataDataWriter_impl::lookup_instance(
	const JSBSim::fdmdata & instance_data) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::lookup_instance(&instance_data);
}

// DDS JSBSim::fdmdata DataReader_impl Object Body

 JSBSim::fdmdataDataReader_impl::fdmdataDataReader_impl (
    gapi_dataReader handle
) : DDS::DataReader_impl(handle)
{
    // Parent constructor takes care of everything.
}

 JSBSim::fdmdataDataReader_impl::~fdmdataDataReader_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::read(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::take(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::read_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::take_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReader_impl::read_next_sample(
    JSBSim::fdmdata & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReader_impl::take_next_sample(
    JSBSim::fdmdata & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::read_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::take_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::read_next_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::take_next_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReader_impl::read_next_instance_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReader_impl::take_next_instance_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReader_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
JSBSim::fdmdataDataReader_impl::return_loan(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 ) {
        if (received_data.length() == info_seq.length() && 
            received_data.release() == info_seq.release() ) {
            if (!received_data.release()) {
                status = DataReader_impl::return_loan( received_data.get_buffer(),
                                                       info_seq.get_buffer() );

                if ( status == DDS::RETCODE_OK ) {
                    if ( !received_data.release() ) {
                        JSBSim::fdmdataSeq::freebuf( received_data.get_buffer(false) );
                        received_data.replace(0, 0, NULL, false);
                        DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                        info_seq.replace(0, 0, NULL, false);
                    }
                } else if ( status == DDS::RETCODE_NO_DATA ) {
                    if ( received_data.release() ) {
                        status = DDS::RETCODE_OK;
                    } else {
                        status = DDS::RETCODE_PRECONDITION_NOT_MET;
                    }
                }
            }
        } else {
            status = DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReader_impl::get_key_value(
    JSBSim::fdmdata & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
JSBSim::fdmdataDataReader_impl::lookup_instance(
    const JSBSim::fdmdata & instance) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

 DDS::ReturnCode_t 
JSBSim::fdmdataDataReader_impl::check_preconditions(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples)
{
    DDS::ReturnCode_t status = DDS::RETCODE_PRECONDITION_NOT_MET;
    
    if ( received_data.length() == info_seq.length() &&
         received_data.maximum() == info_seq.maximum() &&
         received_data.release() == info_seq.release() ) {
        if ( received_data.maximum() == 0 || received_data.release() ) {
            if (received_data.maximum() == 0 ||
				max_samples <= static_cast<CORBA::Long>(received_data.maximum()) ||
				max_samples == DDS::LENGTH_UNLIMITED ) {
                status = DDS::RETCODE_OK;
            }
        }
    }
    return status;
}


// DDS JSBSim::fdmdata DataReaderView_impl Object Body

 JSBSim::fdmdataDataReaderView_impl::fdmdataDataReaderView_impl (
    gapi_dataReaderView handle
) : DDS::DataReaderView_impl(handle)
{
    // Parent constructor takes care of everything.
}

 JSBSim::fdmdataDataReaderView_impl::~fdmdataDataReaderView_impl(void)
{
    // Parent destructor takes care of everything.
}


 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::read(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::take(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::read_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::take_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReaderView_impl::read_next_sample(
    JSBSim::fdmdata & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::read_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReaderView_impl::take_next_sample(
    JSBSim::fdmdata & received_data,
    DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::take_next_sample(&received_data, sample_info);
}


 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::read_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::take_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::read_next_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::take_next_instance(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReaderView_impl::read_next_instance_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReaderView_impl::take_next_instance_w_condition(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = JSBSim::fdmdataDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK ) {
        status = DataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


 DDS::ReturnCode_t
JSBSim::fdmdataDataReaderView_impl::return_loan(
    JSBSim::fdmdataSeq & received_data,
    DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 ) {
        if (received_data.length() == info_seq.length() && 
            received_data.release() == info_seq.release() ) {
            if (!received_data.release()) {
                status = DataReaderView_impl::return_loan( received_data.get_buffer(),
                                                       info_seq.get_buffer() );

                if ( status == DDS::RETCODE_OK ) {
                    if ( !received_data.release() ) {
                        JSBSim::fdmdataSeq::freebuf( received_data.get_buffer(false) );
                        received_data.replace(0, 0, NULL, false);
                        DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                        info_seq.replace(0, 0, NULL, false);
                    }
                } else if ( status == DDS::RETCODE_NO_DATA ) {
                    if ( received_data.release() ) {
                        status = DDS::RETCODE_OK;
                    } else {
                        status = DDS::RETCODE_PRECONDITION_NOT_MET;
                    }
                }
            }
        } else {
            status = DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }
    return status;
}


 DDS::ReturnCode_t 
JSBSim::fdmdataDataReaderView_impl::get_key_value(
    JSBSim::fdmdata & key_holder,
    DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::get_key_value(&key_holder, handle);
}

 DDS::InstanceHandle_t 
JSBSim::fdmdataDataReaderView_impl::lookup_instance(
    const JSBSim::fdmdata & instance) THROW_ORB_EXCEPTIONS
{
    return DataReaderView_impl::lookup_instance(&instance);
}



const char * ::JSBSim::fdmdataTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"JSBSim\"><Struct name=\"fdmdata\"><Member name=\"ID\"><Long/>"
"</Member><Member name=\"Velocity_Kts\"><Double/></Member><Member name=\"Roll_deg\"><Double/></Member>"
"<Member name=\"Pitch_deg\"><Double/></Member><Member name=\"Altitude_ft\"><Double/></Member><Member name=\"VerticleVelocity_fpm\">"
"<Double/></Member><Member name=\"Heading_deg\"><Double/></Member><Member name=\"SideSlip\"><Double/></Member>"
"<Member name=\"MachNumber\"><Double/></Member><Member name=\"AtmosphereTemperature\"><Double/></Member>"
"<Member name=\"GValue\"><Double/></Member><Member name=\"SimTime\"><Double/></Member><Member name=\"SimTimeGMT\">"
"<Double/></Member><Member name=\"FlapPosition\"><Double/></Member><Member name=\"AltitudeAboveSeaLevel_ft\">"
"<Double/></Member><Member name=\"Latitude\"><Double/></Member><Member name=\"Longitude\"><Double/></Member>"
"<Member name=\"TotalFuel\"><Double/></Member><Member name=\"FuelTank1\"><Double/></Member><Member name=\"FuelTank2\">"
"<Double/></Member><Member name=\"FuelTank3\"><Double/></Member><Member name=\"FuelTank4\"><Double/></Member>"
"<Member name=\"RPMEngine1\"><Long/></Member><Member name=\"RPMEngine2\"><Long/></Member><Member name=\"RPMEngine3\">"
"<Long/></Member><Member name=\"RPMEngine4\"><Long/></Member><Member name=\"RPMPercentEngine1\"><Long/>"
"</Member><Member name=\"RPMPercentEngine2\"><Long/></Member><Member name=\"RPMPercentEngine3\"><Long/>"
"</Member><Member name=\"RPMPercentEngine4\"><Long/></Member><Member name=\"TorqueEngine1\"><Long/></Member>"
"<Member name=\"TorqueEngine2\"><Long/></Member><Member name=\"TorqueEngine3\"><Long/></Member><Member name=\"TorqueEngine4\">"
"<Long/></Member><Member name=\"FuelFlowEngine1\"><Double/></Member><Member name=\"FuelFlowEngine2\"><Double/>"
"</Member><Member name=\"FuelFlowEngine3\"><Double/></Member><Member name=\"FuelFlowEngine4\"><Double/>"
"</Member><Member name=\"OilPressureEngine1\"><Double/></Member><Member name=\"OilPressureEngine2\"><Double/>"
"</Member><Member name=\"OilPressureEngine3\"><Double/></Member><Member name=\"OilPressureEngine4\"><Double/>"
"</Member><Member name=\"OilTemperatureEngine1\"><Double/></Member><Member name=\"OilTemperatureEngine2\">"
"<Double/></Member><Member name=\"OilTemperatureEngine3\"><Double/></Member><Member name=\"OilTemperatureEngine4\">"
"<Double/></Member><Member name=\"GearboxOilPressureEngine1\"><Double/></Member><Member name=\"GearboxOilPressureEngine2\">"
"<Double/></Member><Member name=\"GearboxOilPressureEngine3\"><Double/></Member><Member name=\"GearboxOilPressureEngine4\">"
"<Double/></Member><Member name=\"EGTEngine1\"><Double/></Member><Member name=\"EGTEngine2\"><Double/>"
"</Member><Member name=\"EGTEngine3\"><Double/></Member><Member name=\"EGTEngine4\"><Double/></Member>"
"<Member name=\"OilCoolFlapExtensionEngine1\"><Double/></Member><Member name=\"OilCoolFlapExtensionEngine2\">"
"<Double/></Member><Member name=\"OilCoolFlapExtensionEngine3\"><Double/></Member><Member name=\"OilCoolFlapExtensionEngine4\">"
"<Double/></Member><Member name=\"OilQuantityEngine1\"><Double/></Member><Member name=\"OilQuantityEngine2\">"
"<Double/></Member><Member name=\"OilQuantityEngine3\"><Double/></Member><Member name=\"OilQuantityEngine4\">"
"<Double/></Member><Member name=\"UtilityHydraulicPressure\"><Double/></Member><Member name=\"UtilityHydraulicQuantity\">"
"<Double/></Member><Member name=\"BoosterHydraulicPressure\"><Double/></Member><Member name=\"BoosterHydraulicQuantity\">"
"<Double/></Member><Member name=\"AuxiliaryHydraulicPressure\"><Double/></Member><Member name=\"AuxiliaryHydraulicQuantity\">"
"<Double/></Member></Struct></Module></MetaData>";
