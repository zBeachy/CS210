################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ItemFreq.cpp \
../Menu.cpp \
../main.cpp 

CPP_DEPS += \
./ItemFreq.d \
./Menu.d \
./main.d 

OBJS += \
./ItemFreq.o \
./Menu.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./ItemFreq.d ./ItemFreq.o ./Menu.d ./Menu.o ./main.d ./main.o

.PHONY: clean--2e-

