################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Capitals.cpp \
../src/Game.cpp \
../src/UI.cpp \
../src/User.cpp \
../src/UserDB.cpp 

OBJS += \
./src/Capitals.o \
./src/Game.o \
./src/UI.o \
./src/User.o \
./src/UserDB.o 

CPP_DEPS += \
./src/Capitals.d \
./src/Game.d \
./src/UI.d \
./src/User.d \
./src/UserDB.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


