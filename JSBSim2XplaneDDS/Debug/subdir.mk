################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../CheckStatus.cpp.o \
../DDSInterface.cpp.o \
../JSBSim.cpp.o \
../JSBSim2XPLANE.cpp.o \
../JSBSimDcps.cpp.o \
../JSBSimDcps_impl.cpp.o \
../JSBSimSplDcps.cpp.o 

CPP_SRCS += \
../CheckStatus.cpp \
../DDSInterface.cpp \
../JSBSim.cpp \
../JSBSim2XPLANE.cpp \
../JSBSimDcps.cpp \
../JSBSimDcps_impl.cpp \
../JSBSimSplDcps.cpp 

OBJS += \
./CheckStatus.o \
./DDSInterface.o \
./JSBSim.o \
./JSBSim2XPLANE.o \
./JSBSimDcps.o \
./JSBSimDcps_impl.o \
./JSBSimSplDcps.o 

CPP_DEPS += \
./CheckStatus.d \
./DDSInterface.d \
./JSBSim.d \
./JSBSim2XPLANE.d \
./JSBSimDcps.d \
./JSBSimDcps_impl.d \
./JSBSimSplDcps.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


