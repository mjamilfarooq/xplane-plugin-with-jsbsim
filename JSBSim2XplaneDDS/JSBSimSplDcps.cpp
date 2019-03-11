#include "JSBSimSplDcps.h"
#include "ccpp_JSBSim.h"

const char *
__JSBSim_fdmdata__name(void)
{
    return (const char*)"JSBSim::fdmdata";
}

const char *
__JSBSim_fdmdata__keys(void)
{
    return (const char*)"ID";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>

c_bool
__JSBSim_fdmdata__copyIn(
    c_base base,
    struct ::JSBSim::fdmdata *from,
    struct _JSBSim_fdmdata *to)
{
    c_bool result = TRUE;

    to->ID = (c_long)from->ID;
    to->Velocity_Kts = (c_double)from->Velocity_Kts;
    to->Roll_deg = (c_double)from->Roll_deg;
    to->Pitch_deg = (c_double)from->Pitch_deg;
    to->Altitude_ft = (c_double)from->Altitude_ft;
    to->VerticleVelocity_fpm = (c_double)from->VerticleVelocity_fpm;
    to->Heading_deg = (c_double)from->Heading_deg;
    to->SideSlip = (c_double)from->SideSlip;
    to->MachNumber = (c_double)from->MachNumber;
    to->AtmosphereTemperature = (c_double)from->AtmosphereTemperature;
    to->GValue = (c_double)from->GValue;
    to->SimTime = (c_double)from->SimTime;
    to->SimTimeGMT = (c_double)from->SimTimeGMT;
    to->FlapPosition = (c_double)from->FlapPosition;
    to->AltitudeAboveSeaLevel_ft = (c_double)from->AltitudeAboveSeaLevel_ft;
    to->Latitude = (c_double)from->Latitude;
    to->Longitude = (c_double)from->Longitude;
    to->TotalFuel = (c_double)from->TotalFuel;
    to->FuelTank1 = (c_double)from->FuelTank1;
    to->FuelTank2 = (c_double)from->FuelTank2;
    to->FuelTank3 = (c_double)from->FuelTank3;
    to->FuelTank4 = (c_double)from->FuelTank4;
    to->RPMEngine1 = (c_long)from->RPMEngine1;
    to->RPMEngine2 = (c_long)from->RPMEngine2;
    to->RPMEngine3 = (c_long)from->RPMEngine3;
    to->RPMEngine4 = (c_long)from->RPMEngine4;
    to->RPMPercentEngine1 = (c_long)from->RPMPercentEngine1;
    to->RPMPercentEngine2 = (c_long)from->RPMPercentEngine2;
    to->RPMPercentEngine3 = (c_long)from->RPMPercentEngine3;
    to->RPMPercentEngine4 = (c_long)from->RPMPercentEngine4;
    to->TorqueEngine1 = (c_long)from->TorqueEngine1;
    to->TorqueEngine2 = (c_long)from->TorqueEngine2;
    to->TorqueEngine3 = (c_long)from->TorqueEngine3;
    to->TorqueEngine4 = (c_long)from->TorqueEngine4;
    to->FuelFlowEngine1 = (c_double)from->FuelFlowEngine1;
    to->FuelFlowEngine2 = (c_double)from->FuelFlowEngine2;
    to->FuelFlowEngine3 = (c_double)from->FuelFlowEngine3;
    to->FuelFlowEngine4 = (c_double)from->FuelFlowEngine4;
    to->OilPressureEngine1 = (c_double)from->OilPressureEngine1;
    to->OilPressureEngine2 = (c_double)from->OilPressureEngine2;
    to->OilPressureEngine3 = (c_double)from->OilPressureEngine3;
    to->OilPressureEngine4 = (c_double)from->OilPressureEngine4;
    to->OilTemperatureEngine1 = (c_double)from->OilTemperatureEngine1;
    to->OilTemperatureEngine2 = (c_double)from->OilTemperatureEngine2;
    to->OilTemperatureEngine3 = (c_double)from->OilTemperatureEngine3;
    to->OilTemperatureEngine4 = (c_double)from->OilTemperatureEngine4;
    to->GearboxOilPressureEngine1 = (c_double)from->GearboxOilPressureEngine1;
    to->GearboxOilPressureEngine2 = (c_double)from->GearboxOilPressureEngine2;
    to->GearboxOilPressureEngine3 = (c_double)from->GearboxOilPressureEngine3;
    to->GearboxOilPressureEngine4 = (c_double)from->GearboxOilPressureEngine4;
    to->EGTEngine1 = (c_double)from->EGTEngine1;
    to->EGTEngine2 = (c_double)from->EGTEngine2;
    to->EGTEngine3 = (c_double)from->EGTEngine3;
    to->EGTEngine4 = (c_double)from->EGTEngine4;
    to->OilCoolFlapExtensionEngine1 = (c_double)from->OilCoolFlapExtensionEngine1;
    to->OilCoolFlapExtensionEngine2 = (c_double)from->OilCoolFlapExtensionEngine2;
    to->OilCoolFlapExtensionEngine3 = (c_double)from->OilCoolFlapExtensionEngine3;
    to->OilCoolFlapExtensionEngine4 = (c_double)from->OilCoolFlapExtensionEngine4;
    to->OilQuantityEngine1 = (c_double)from->OilQuantityEngine1;
    to->OilQuantityEngine2 = (c_double)from->OilQuantityEngine2;
    to->OilQuantityEngine3 = (c_double)from->OilQuantityEngine3;
    to->OilQuantityEngine4 = (c_double)from->OilQuantityEngine4;
    to->UtilityHydraulicPressure = (c_double)from->UtilityHydraulicPressure;
    to->UtilityHydraulicQuantity = (c_double)from->UtilityHydraulicQuantity;
    to->BoosterHydraulicPressure = (c_double)from->BoosterHydraulicPressure;
    to->BoosterHydraulicQuantity = (c_double)from->BoosterHydraulicQuantity;
    to->AuxiliaryHydraulicPressure = (c_double)from->AuxiliaryHydraulicPressure;
    to->AuxiliaryHydraulicQuantity = (c_double)from->AuxiliaryHydraulicQuantity;
    return result;
}

void
__JSBSim_fdmdata__copyOut(
    void *_from,
    void *_to)
{
    struct _JSBSim_fdmdata *from = (struct _JSBSim_fdmdata *)_from;
    struct ::JSBSim::fdmdata *to = (struct ::JSBSim::fdmdata *)_to;
    to->ID = (::DDS::Long)from->ID;
    to->Velocity_Kts = (::DDS::Double)from->Velocity_Kts;
    to->Roll_deg = (::DDS::Double)from->Roll_deg;
    to->Pitch_deg = (::DDS::Double)from->Pitch_deg;
    to->Altitude_ft = (::DDS::Double)from->Altitude_ft;
    to->VerticleVelocity_fpm = (::DDS::Double)from->VerticleVelocity_fpm;
    to->Heading_deg = (::DDS::Double)from->Heading_deg;
    to->SideSlip = (::DDS::Double)from->SideSlip;
    to->MachNumber = (::DDS::Double)from->MachNumber;
    to->AtmosphereTemperature = (::DDS::Double)from->AtmosphereTemperature;
    to->GValue = (::DDS::Double)from->GValue;
    to->SimTime = (::DDS::Double)from->SimTime;
    to->SimTimeGMT = (::DDS::Double)from->SimTimeGMT;
    to->FlapPosition = (::DDS::Double)from->FlapPosition;
    to->AltitudeAboveSeaLevel_ft = (::DDS::Double)from->AltitudeAboveSeaLevel_ft;
    to->Latitude = (::DDS::Double)from->Latitude;
    to->Longitude = (::DDS::Double)from->Longitude;
    to->TotalFuel = (::DDS::Double)from->TotalFuel;
    to->FuelTank1 = (::DDS::Double)from->FuelTank1;
    to->FuelTank2 = (::DDS::Double)from->FuelTank2;
    to->FuelTank3 = (::DDS::Double)from->FuelTank3;
    to->FuelTank4 = (::DDS::Double)from->FuelTank4;
    to->RPMEngine1 = (::DDS::Long)from->RPMEngine1;
    to->RPMEngine2 = (::DDS::Long)from->RPMEngine2;
    to->RPMEngine3 = (::DDS::Long)from->RPMEngine3;
    to->RPMEngine4 = (::DDS::Long)from->RPMEngine4;
    to->RPMPercentEngine1 = (::DDS::Long)from->RPMPercentEngine1;
    to->RPMPercentEngine2 = (::DDS::Long)from->RPMPercentEngine2;
    to->RPMPercentEngine3 = (::DDS::Long)from->RPMPercentEngine3;
    to->RPMPercentEngine4 = (::DDS::Long)from->RPMPercentEngine4;
    to->TorqueEngine1 = (::DDS::Long)from->TorqueEngine1;
    to->TorqueEngine2 = (::DDS::Long)from->TorqueEngine2;
    to->TorqueEngine3 = (::DDS::Long)from->TorqueEngine3;
    to->TorqueEngine4 = (::DDS::Long)from->TorqueEngine4;
    to->FuelFlowEngine1 = (::DDS::Double)from->FuelFlowEngine1;
    to->FuelFlowEngine2 = (::DDS::Double)from->FuelFlowEngine2;
    to->FuelFlowEngine3 = (::DDS::Double)from->FuelFlowEngine3;
    to->FuelFlowEngine4 = (::DDS::Double)from->FuelFlowEngine4;
    to->OilPressureEngine1 = (::DDS::Double)from->OilPressureEngine1;
    to->OilPressureEngine2 = (::DDS::Double)from->OilPressureEngine2;
    to->OilPressureEngine3 = (::DDS::Double)from->OilPressureEngine3;
    to->OilPressureEngine4 = (::DDS::Double)from->OilPressureEngine4;
    to->OilTemperatureEngine1 = (::DDS::Double)from->OilTemperatureEngine1;
    to->OilTemperatureEngine2 = (::DDS::Double)from->OilTemperatureEngine2;
    to->OilTemperatureEngine3 = (::DDS::Double)from->OilTemperatureEngine3;
    to->OilTemperatureEngine4 = (::DDS::Double)from->OilTemperatureEngine4;
    to->GearboxOilPressureEngine1 = (::DDS::Double)from->GearboxOilPressureEngine1;
    to->GearboxOilPressureEngine2 = (::DDS::Double)from->GearboxOilPressureEngine2;
    to->GearboxOilPressureEngine3 = (::DDS::Double)from->GearboxOilPressureEngine3;
    to->GearboxOilPressureEngine4 = (::DDS::Double)from->GearboxOilPressureEngine4;
    to->EGTEngine1 = (::DDS::Double)from->EGTEngine1;
    to->EGTEngine2 = (::DDS::Double)from->EGTEngine2;
    to->EGTEngine3 = (::DDS::Double)from->EGTEngine3;
    to->EGTEngine4 = (::DDS::Double)from->EGTEngine4;
    to->OilCoolFlapExtensionEngine1 = (::DDS::Double)from->OilCoolFlapExtensionEngine1;
    to->OilCoolFlapExtensionEngine2 = (::DDS::Double)from->OilCoolFlapExtensionEngine2;
    to->OilCoolFlapExtensionEngine3 = (::DDS::Double)from->OilCoolFlapExtensionEngine3;
    to->OilCoolFlapExtensionEngine4 = (::DDS::Double)from->OilCoolFlapExtensionEngine4;
    to->OilQuantityEngine1 = (::DDS::Double)from->OilQuantityEngine1;
    to->OilQuantityEngine2 = (::DDS::Double)from->OilQuantityEngine2;
    to->OilQuantityEngine3 = (::DDS::Double)from->OilQuantityEngine3;
    to->OilQuantityEngine4 = (::DDS::Double)from->OilQuantityEngine4;
    to->UtilityHydraulicPressure = (::DDS::Double)from->UtilityHydraulicPressure;
    to->UtilityHydraulicQuantity = (::DDS::Double)from->UtilityHydraulicQuantity;
    to->BoosterHydraulicPressure = (::DDS::Double)from->BoosterHydraulicPressure;
    to->BoosterHydraulicQuantity = (::DDS::Double)from->BoosterHydraulicQuantity;
    to->AuxiliaryHydraulicPressure = (::DDS::Double)from->AuxiliaryHydraulicPressure;
    to->AuxiliaryHydraulicQuantity = (::DDS::Double)from->AuxiliaryHydraulicQuantity;
}

