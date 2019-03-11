#ifndef JSBSIMSPLTYPES_H
#define JSBSIMSPLTYPES_H

#include "ccpp_JSBSim.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __JSBSim_JSBSim__load (c_base base);

extern c_metaObject __JSBSim_fdmdata__load (c_base base);
extern const char * __JSBSim_fdmdata__keys (void);
extern const char * __JSBSim_fdmdata__name (void);
struct _JSBSim_fdmdata ;
extern  c_bool __JSBSim_fdmdata__copyIn(c_base base, struct JSBSim::fdmdata *from, struct _JSBSim_fdmdata *to);
extern  void __JSBSim_fdmdata__copyOut(void *_from, void *_to);
struct _JSBSim_fdmdata {
    c_long ID;
    c_double Velocity_Kts;
    c_double Roll_deg;
    c_double Pitch_deg;
    c_double Altitude_ft;
    c_double VerticleVelocity_fpm;
    c_double Heading_deg;
    c_double SideSlip;
    c_double MachNumber;
    c_double AtmosphereTemperature;
    c_double GValue;
    c_double SimTime;
    c_double SimTimeGMT;
    c_double FlapPosition;
    c_double AltitudeAboveSeaLevel_ft;
    c_double Latitude;
    c_double Longitude;
    c_double TotalFuel;
    c_double FuelTank1;
    c_double FuelTank2;
    c_double FuelTank3;
    c_double FuelTank4;
    c_long RPMEngine1;
    c_long RPMEngine2;
    c_long RPMEngine3;
    c_long RPMEngine4;
    c_long RPMPercentEngine1;
    c_long RPMPercentEngine2;
    c_long RPMPercentEngine3;
    c_long RPMPercentEngine4;
    c_long TorqueEngine1;
    c_long TorqueEngine2;
    c_long TorqueEngine3;
    c_long TorqueEngine4;
    c_double FuelFlowEngine1;
    c_double FuelFlowEngine2;
    c_double FuelFlowEngine3;
    c_double FuelFlowEngine4;
    c_double OilPressureEngine1;
    c_double OilPressureEngine2;
    c_double OilPressureEngine3;
    c_double OilPressureEngine4;
    c_double OilTemperatureEngine1;
    c_double OilTemperatureEngine2;
    c_double OilTemperatureEngine3;
    c_double OilTemperatureEngine4;
    c_double GearboxOilPressureEngine1;
    c_double GearboxOilPressureEngine2;
    c_double GearboxOilPressureEngine3;
    c_double GearboxOilPressureEngine4;
    c_double EGTEngine1;
    c_double EGTEngine2;
    c_double EGTEngine3;
    c_double EGTEngine4;
    c_double OilCoolFlapExtensionEngine1;
    c_double OilCoolFlapExtensionEngine2;
    c_double OilCoolFlapExtensionEngine3;
    c_double OilCoolFlapExtensionEngine4;
    c_double OilQuantityEngine1;
    c_double OilQuantityEngine2;
    c_double OilQuantityEngine3;
    c_double OilQuantityEngine4;
    c_double UtilityHydraulicPressure;
    c_double UtilityHydraulicQuantity;
    c_double BoosterHydraulicPressure;
    c_double BoosterHydraulicQuantity;
    c_double AuxiliaryHydraulicPressure;
    c_double AuxiliaryHydraulicQuantity;
};

#endif
