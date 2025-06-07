################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../asw/components/ccbkgtcexec/src/CCBKGTCExecB.cpp \
../asw/components/ccbkgtcexec/src/CCBKGTCExecS.cpp 

CPP_DEPS += \
./asw/components/ccbkgtcexec/src/CCBKGTCExecB.d \
./asw/components/ccbkgtcexec/src/CCBKGTCExecS.d 

OBJS += \
./asw/components/ccbkgtcexec/src/CCBKGTCExecB.o \
./asw/components/ccbkgtcexec/src/CCBKGTCExecS.o 


# Each subdirectory must supply rules for building sources it contributes
asw/components/ccbkgtcexec/src/%.o: ../asw/components/ccbkgtcexec/src/%.cpp asw/components/ccbkgtcexec/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/freertos_osswr/Source" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/attitude_pid_ctrl/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/components/uahphotsat/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/components/ccobsmng/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service129/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/emu_sat_attitude/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service09/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service128/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service04/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/emu_watchdog_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service06/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/device_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service02/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service19/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service12/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service20/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service05/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_sys_data_pool/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service03/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_tm_handler/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service17/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_service01/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/obt_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/dataclasses/CDTCExecCtrl/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/dataclasses/CDTCAcceptReport/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_tc_handler/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/pus_tc_accept_report/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/dataclasses/CDTCMemDescriptor/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/emu_adc_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/tc_rate_ctrl/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/tc_queue_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/config/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/freertos_osswr/Source/portable/ThirdParty/GCC/Posix" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/emu_hw_timecode_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/crc/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/emu_gss/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/ccsds_pus/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/tmtc_dyn_mem/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/serialize/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/components/cchk_fdirmng/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/components/ccbkgtcexec/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/edroom_glue/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/components/cctcmanager/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/edroomsl/edroombp/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/edroomsl/edroomsl/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/edroomsl/edroomsl_types/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/freertos_osswr/Source/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/freertos_osswr/Source/portable/ThirdParty/GCC/Posix/MemMang" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/dataclasses/CDEvAction/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/dataclasses/CDTCHandler/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/service_libraries/pus_services/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/sc_channel_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/emu_sc_channel_drv/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/freertos_osswr/Source/portable/ThirdParty/GCC/Posix" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/freertos_osswr/Source/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/config/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/asw/edroom_glue/include" -I"/home/atcsol/git/proyecto/uah_photsat_freertos/llsw/freertos_osswr" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-asw-2f-components-2f-ccbkgtcexec-2f-src

clean-asw-2f-components-2f-ccbkgtcexec-2f-src:
	-$(RM) ./asw/components/ccbkgtcexec/src/CCBKGTCExecB.d ./asw/components/ccbkgtcexec/src/CCBKGTCExecB.o ./asw/components/ccbkgtcexec/src/CCBKGTCExecS.d ./asw/components/ccbkgtcexec/src/CCBKGTCExecS.o

.PHONY: clean-asw-2f-components-2f-ccbkgtcexec-2f-src

