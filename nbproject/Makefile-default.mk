#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_layer/_7_SEGMENT/_7_segment.c ECU_layer/CHAR_LCD/ecu_char_lcd.c ECU_layer/KEYPAD/ecu_keypad.c ECU_layer/LED/ecu_led.c ECU_layer/MOTOR/ecu_motor.c ECU_layer/PUSH_BUTTON/ecu_push_button.c ECU_layer/RELAY/ecu_relay.c ECU_layer/ecu_layer_initializaton.c MCAL_layer/ADC/hal_ADC.c MCAL_layer/CCP1/hal_ccp1.c MCAL_layer/EEPROM/hal_eeprom.c MCAL_layer/GPIO/hal_GPIO.c MCAL_layer/INTERRUPT/mcal_interrupt_manger.c MCAL_layer/INTERRUPT/mcal_external_interrupt.c MCAL_layer/INTERRUPT/mcal_internal_interrupt.c MCAL_layer/SPI/hal_spi.c MCAL_layer/TIMER0/hal_timer0.c MCAL_layer/TIMER1/hal_timer1.c MCAL_layer/TIMER2/hal_timer2.c MCAL_layer/TIMER3/hal_timer3.c MCAL_layer/USART/hal_usart.c MCAL_layer/device_config.c application.c MCAL_layer/I2C/i2c_master.c MCAL_layer/I2C/i2c_master_example.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1 ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1 ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1 ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1 ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1 ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1 ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1 ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1 ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1 ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1 ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1 ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1 ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1 ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1.d ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1.d ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1.d ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1.d ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1.d ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1.d ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1.d ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1.d ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1.d ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1.d ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1.d ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1 ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1 ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1 ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1 ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1 ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1 ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1 ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1 ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1 ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1 ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1 ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1 ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1 ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1

# Source Files
SOURCEFILES=ECU_layer/_7_SEGMENT/_7_segment.c ECU_layer/CHAR_LCD/ecu_char_lcd.c ECU_layer/KEYPAD/ecu_keypad.c ECU_layer/LED/ecu_led.c ECU_layer/MOTOR/ecu_motor.c ECU_layer/PUSH_BUTTON/ecu_push_button.c ECU_layer/RELAY/ecu_relay.c ECU_layer/ecu_layer_initializaton.c MCAL_layer/ADC/hal_ADC.c MCAL_layer/CCP1/hal_ccp1.c MCAL_layer/EEPROM/hal_eeprom.c MCAL_layer/GPIO/hal_GPIO.c MCAL_layer/INTERRUPT/mcal_interrupt_manger.c MCAL_layer/INTERRUPT/mcal_external_interrupt.c MCAL_layer/INTERRUPT/mcal_internal_interrupt.c MCAL_layer/SPI/hal_spi.c MCAL_layer/TIMER0/hal_timer0.c MCAL_layer/TIMER1/hal_timer1.c MCAL_layer/TIMER2/hal_timer2.c MCAL_layer/TIMER3/hal_timer3.c MCAL_layer/USART/hal_usart.c MCAL_layer/device_config.c application.c MCAL_layer/I2C/i2c_master.c MCAL_layer/I2C/i2c_master_example.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1: ECU_layer/_7_SEGMENT/_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/_7_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1 ECU_layer/_7_SEGMENT/_7_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.d ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1: ECU_layer/CHAR_LCD/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/CHAR_LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1 ECU_layer/CHAR_LCD/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.d ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1: ECU_layer/KEYPAD/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ECU_layer/KEYPAD/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.d ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1: ECU_layer/MOTOR/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1 ECU_layer/MOTOR/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.d ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1: ECU_layer/PUSH_BUTTON/ecu_push_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/PUSH_BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1 ECU_layer/PUSH_BUTTON/ecu_push_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.d ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1: ECU_layer/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ECU_layer/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.d ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1: ECU_layer/ecu_layer_initializaton.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1 ECU_layer/ecu_layer_initializaton.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.d ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1: MCAL_layer/ADC/hal_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 MCAL_layer/ADC/hal_ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.d ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1: MCAL_layer/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 MCAL_layer/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1: MCAL_layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 MCAL_layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1: MCAL_layer/GPIO/hal_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1 MCAL_layer/GPIO/hal_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1: MCAL_layer/INTERRUPT/mcal_interrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1 MCAL_layer/INTERRUPT/mcal_interrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1: MCAL_layer/INTERRUPT/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1 MCAL_layer/INTERRUPT/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1: MCAL_layer/INTERRUPT/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1 MCAL_layer/INTERRUPT/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1: MCAL_layer/SPI/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1 MCAL_layer/SPI/hal_spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.d ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1: MCAL_layer/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1 MCAL_layer/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.d ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1: MCAL_layer/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1 MCAL_layer/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.d ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1: MCAL_layer/TIMER2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1 MCAL_layer/TIMER2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.d ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1: MCAL_layer/TIMER3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1 MCAL_layer/TIMER3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.d ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1: MCAL_layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1 MCAL_layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.d ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1: MCAL_layer/I2C/i2c_master.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1 MCAL_layer/I2C/i2c_master.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.d ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1: MCAL_layer/I2C/i2c_master_example.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1 MCAL_layer/I2C/i2c_master_example.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.d ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1: ECU_layer/_7_SEGMENT/_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/_7_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1 ECU_layer/_7_SEGMENT/_7_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.d ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/_7_SEGMENT/_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1: ECU_layer/CHAR_LCD/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/CHAR_LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1 ECU_layer/CHAR_LCD/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.d ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/CHAR_LCD/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1: ECU_layer/KEYPAD/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1 ECU_layer/KEYPAD/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.d ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/KEYPAD/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1: ECU_layer/MOTOR/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1 ECU_layer/MOTOR/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.d ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/MOTOR/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1: ECU_layer/PUSH_BUTTON/ecu_push_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/PUSH_BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1 ECU_layer/PUSH_BUTTON/ecu_push_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.d ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/PUSH_BUTTON/ecu_push_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1: ECU_layer/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/RELAY" 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1 ECU_layer/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.d ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1: ECU_layer/ecu_layer_initializaton.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1 ECU_layer/ecu_layer_initializaton.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.d ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_layer_initializaton.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1: MCAL_layer/ADC/hal_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1 MCAL_layer/ADC/hal_ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.d ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/hal_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1: MCAL_layer/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 MCAL_layer/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1: MCAL_layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1 MCAL_layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1: MCAL_layer/GPIO/hal_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1 MCAL_layer/GPIO/hal_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1: MCAL_layer/INTERRUPT/mcal_interrupt_manger.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1 MCAL_layer/INTERRUPT/mcal_interrupt_manger.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_interrupt_manger.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1: MCAL_layer/INTERRUPT/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1 MCAL_layer/INTERRUPT/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1: MCAL_layer/INTERRUPT/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1 MCAL_layer/INTERRUPT/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/INTERRUPT/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1: MCAL_layer/SPI/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1 MCAL_layer/SPI/hal_spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.d ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/SPI/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1: MCAL_layer/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1 MCAL_layer/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.d ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1: MCAL_layer/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1 MCAL_layer/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.d ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1: MCAL_layer/TIMER2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1 MCAL_layer/TIMER2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.d ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1: MCAL_layer/TIMER3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1 MCAL_layer/TIMER3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.d ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1: MCAL_layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1 MCAL_layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.d ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1: MCAL_layer/I2C/i2c_master.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1 MCAL_layer/I2C/i2c_master.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.d ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1: MCAL_layer/I2C/i2c_master_example.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1 MCAL_layer/I2C/i2c_master_example.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.d ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/i2c_master_example.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Motor_Control.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
