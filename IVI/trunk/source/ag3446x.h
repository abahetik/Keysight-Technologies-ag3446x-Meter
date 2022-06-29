/*****************************************************************************
 *                       Agilent/Keysight 3446X Series
 *----------------------------------------------------------------------------
 * Copyright 2013 - 2021, National Instruments, Corporation.  All Rights Reserved. 
 *----------------------------------------------------------------------------
 *                                                                          
 * Title:    ag3446x.h                                        
 * Purpose:  Agilent/Keysight 3446X Series                                       
 *           instrument driver declarations.                                
 *                                                                          
 ****************************************************************************/

#ifndef __AG3446X_HEADER
#define __AG3446X_HEADER

#include <ivi.h>
#include <ividmm.h>

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define AG3446X_MAJOR_VERSION                2     /* Instrument driver major version   */
#define AG3446X_MINOR_VERSION                5     /* Instrument driver minor version   */
                                                                
#define AG3446X_CLASS_SPEC_MAJOR_VERSION     4     /* Class specification major version */
#define AG3446X_CLASS_SPEC_MINOR_VERSION     1     /* Class specification minor version */

#define AG3446X_SUPPORTED_INSTRUMENT_MODELS  "34460A,34461A,34465A,34470A, EDU34450A"
    
#define AG3446X_DRIVER_VENDOR                "National Instruments"
    
#ifdef  _IVI_mswin64_
#define AG3446X_DRIVER_DESCRIPTION           "Agilent/Keysight Technologies 3446X Series Digital Multimeters [Compiled for 64-bit.]"
#else                    
#define AG3446X_DRIVER_DESCRIPTION           "Agilent/Keysight Technologies 3446X Series Digital Multimeters"
#endif
    
#define AG3446X_IO_SESSION_TYPE              "NI-VISA"

/**************************************************************************** 
 *------------------------------ Useful Macros -----------------------------* 
 ****************************************************************************/
    
    /* Define models: 34460A, 34461A, 34465A,EDU34450A */
#define AG3446X_VAL_MODEL_UNKNOWN			 0
#define AG3446X_VAL_MODEL_34460A             60
#define AG3446X_VAL_MODEL_34461A             61
#define AG3446X_VAL_MODEL_34465A             65 
#define AG3446X_VAL_MODEL_34470A             70 
#define AG3446X_VAL_MODEL_EDU34450A          50 	

/**************************************************************************** 
 *---------------------------- Attribute Defines ---------------------------* 
 ****************************************************************************/

    /*- IVI Inherent Instrument Attributes ---------------------------------*/    

        /* User Options */
#define AG3446X_ATTR_RANGE_CHECK                   IVI_ATTR_RANGE_CHECK                    /* ViBoolean */
#define AG3446X_ATTR_QUERY_INSTRUMENT_STATUS       IVI_ATTR_QUERY_INSTRUMENT_STATUS        /* ViBoolean */
#define AG3446X_ATTR_CACHE                         IVI_ATTR_CACHE                          /* ViBoolean */
#define AG3446X_ATTR_SIMULATE                      IVI_ATTR_SIMULATE                       /* ViBoolean */
#define AG3446X_ATTR_RECORD_COERCIONS              IVI_ATTR_RECORD_COERCIONS               /* ViBoolean */
#define AG3446X_ATTR_INTERCHANGE_CHECK             IVI_ATTR_INTERCHANGE_CHECK              /* ViBoolean */
        
        /* Driver Information  */
#define AG3446X_ATTR_SPECIFIC_DRIVER_PREFIX                   IVI_ATTR_SPECIFIC_DRIVER_PREFIX                   /* ViString, read-only  */
#define AG3446X_ATTR_SUPPORTED_INSTRUMENT_MODELS              IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS              /* ViString, read-only  */
#define AG3446X_ATTR_GROUP_CAPABILITIES                       IVI_ATTR_GROUP_CAPABILITIES                       /* ViString, read-only  */
#define AG3446X_ATTR_INSTRUMENT_MANUFACTURER                  IVI_ATTR_INSTRUMENT_MANUFACTURER                  /* ViString, read-only  */
#define AG3446X_ATTR_INSTRUMENT_MODEL                         IVI_ATTR_INSTRUMENT_MODEL                         /* ViString, read-only  */
#define AG3446X_ATTR_INSTRUMENT_FIRMWARE_REVISION             IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION             /* ViString, read-only  */
#define AG3446X_ATTR_SPECIFIC_DRIVER_REVISION                 IVI_ATTR_SPECIFIC_DRIVER_REVISION                 /* ViString, read-only  */
#define AG3446X_ATTR_SPECIFIC_DRIVER_VENDOR                   IVI_ATTR_SPECIFIC_DRIVER_VENDOR                   /* ViString, read-only  */
#define AG3446X_ATTR_SPECIFIC_DRIVER_DESCRIPTION              IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION              /* ViString, read-only  */
#define AG3446X_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, read-only   */
#define AG3446X_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, read-only   */

        /* Advanced Session Information */
#define AG3446X_ATTR_LOGICAL_NAME                  IVI_ATTR_LOGICAL_NAME                   /* ViString, read-only  */
#define AG3446X_ATTR_IO_RESOURCE_DESCRIPTOR        IVI_ATTR_IO_RESOURCE_DESCRIPTOR         /* ViString, read-only  */
#define AG3446X_ATTR_DRIVER_SETUP                  IVI_ATTR_DRIVER_SETUP                   /* ViString, read-only  */
    
    /*- Instrument-Specific Attributes -------------------------------------*/

    /*- Basic Instrument Operation -----------------------------------------*/
#define AG3446X_ATTR_FUNCTION                 IVIDMM_ATTR_FUNCTION                     /* ViInt32   */
#define AG3446X_ATTR_RANGE                    IVIDMM_ATTR_RANGE                        /* ViReal64  */
#define AG3446X_ATTR_RESOLUTION_ABSOLUTE      IVIDMM_ATTR_RESOLUTION_ABSOLUTE          /* ViReal64  */
#define AG3446X_ATTR_EDU34450A_RESOLUTION     IVIDMM_ATTR_EDU34450A_RESOLUTION		   /* ViInt32   */ 
#define AG3446X_ATTR_TRIGGER_SOURCE           IVIDMM_ATTR_TRIGGER_SOURCE               /* ViInt32   */
#define AG3446X_ATTR_TRIGGER_DELAY            IVIDMM_ATTR_TRIGGER_DELAY                /* ViReal64  */
                                                                            
    /*- AC Measurements ----------------------------------------------------*/
#define AG3446X_ATTR_AC_MIN_FREQ              IVIDMM_ATTR_AC_MIN_FREQ                  /* ViReal64  */
#define AG3446X_ATTR_AC_MAX_FREQ              IVIDMM_ATTR_AC_MAX_FREQ                  /* ViReal64  */

    /*- Frequency Measurements ---------------------------------------------*/
#define AG3446X_ATTR_FREQ_VOLTAGE_RANGE       IVIDMM_ATTR_FREQ_VOLTAGE_RANGE           /* ViReal64  */

    /*- Temperature Measurements -------------------------------------------*/
#define AG3446X_ATTR_TEMP_TRANSDUCER_TYPE     IVIDMM_ATTR_TEMP_TRANSDUCER_TYPE         /* ViInt32   */

        /* Resistance Temperature Device */
#define AG3446X_ATTR_TEMP_RTD_ALPHA           IVIDMM_ATTR_TEMP_RTD_ALPHA               /* ViReal64  */
#define AG3446X_ATTR_TEMP_RTD_RES             IVIDMM_ATTR_TEMP_RTD_RES                 /* ViReal64  */

        /* Thermistor */
#define AG3446X_ATTR_TEMP_THERMISTOR_RES      IVIDMM_ATTR_TEMP_THERMISTOR_RES          /* ViReal64  */

    /*- MultiPoint Measurements---------------------------------------------*/
#define AG3446X_ATTR_SAMPLE_COUNT             IVIDMM_ATTR_SAMPLE_COUNT                 /* ViInt32   */
#define AG3446X_ATTR_SAMPLE_TRIGGER           IVIDMM_ATTR_SAMPLE_TRIGGER               /* ViInt32   */
#define AG3446X_ATTR_SAMPLE_INTERVAL          IVIDMM_ATTR_SAMPLE_INTERVAL              /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_COUNT            IVIDMM_ATTR_TRIGGER_COUNT                /* ViInt32   */
#define AG3446X_ATTR_MEAS_COMPLETE_DEST       IVIDMM_ATTR_MEAS_COMPLETE_DEST           /* ViInt32   */

    /*- Configuration Information  -----------------------------------------*/
#define AG3446X_ATTR_APERTURE_TIME            IVIDMM_ATTR_APERTURE_TIME                /* ViReal64 */
#define AG3446X_ATTR_APERTURE_TIME_UNITS      IVIDMM_ATTR_APERTURE_TIME_UNITS          /* ViInt32  */
#define AG3446X_ATTR_AUTO_RANGE_VALUE         IVIDMM_ATTR_AUTO_RANGE_VALUE             /* ViReal64, read-only */

    /*- Trigger Slope  -----------------------------------------------------*/
#define AG3446X_ATTR_TRIGGER_SLOPE            IVIDMM_ATTR_TRIGGER_SLOPE                /* ViInt32   */

    /*- Auto Zero Mode -----------------------------------------------------*/
#define AG3446X_ATTR_AUTO_ZERO                IVIDMM_ATTR_AUTO_ZERO                    /* ViInt32   */
	
	/*- Thermocouple -------------------------------------------------------*/ 
#define AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC   IVIDMM_ATTR_TEMP_TC_FIXED_REF_JUNC	   /* ViReal64  */
#define AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE    IVIDMM_ATTR_TEMP_TC_REF_JUNC_TYPE		   /* ViInt32   */
#define AG3446X_ATTR_TEMP_TC_TYPE             IVIDMM_ATTR_TEMP_TC_TYPE				   /* ViInt32   */


    /*- ag3446x-Specific Attributes ----------------------------------------*/
    
    /*- Other Group Attributes ---------------*/
#define AG3446X_ATTR_VOLT_AUTO_IMPEDANCE      	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1001L)  /* ViBoolean */
#define AG3446X_ATTR_CURR_TERMINAL            	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1002L)  /* ViInt32   */
#define AG3446X_ATTR_NULL_AUTO_ENABLED        	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1003L)  /* ViBoolean */
#define AG3446X_ATTR_NULL_VALUE              	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1004L)  /* ViReal64  */
#define AG3446X_ATTR_NULL_ENABLED            	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1005L)  /* ViBoolean */
#define AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER 	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1006L)  /* ViInt32   */
#define AG3446X_ATTR_TRIGGER_LEVEL			  	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1007L)  /* ViReal64  */
#define AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED 	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1010L)  /* ViBoolean */
#define AG3446X_ATTR_POWER_LIMIT_ENABLED    	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1011L)  /* ViBoolean */
	
#define AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED 		(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1012L)	 /* ViBoolean */
#define AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED 			(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1013L)	 /* ViBoolean */
	
#define AG3446X_ATTR_TEMP_TC_CHECK_ENABLED  	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1014L)  /* ViBoolean */
#define AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ 	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1015L)  /* ViReal64  */
	
#define AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED 			(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1016L)  /* ViBoolean */
	
#define AG3446X_ATTR_SECONDARY_FUNCTION     	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1017L)  /* ViInt32   */
#define AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED 	(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1018L)  /* ViBoolean */

/*- Memory Group Attributes ---------------*/
#define AG3446X_ATTR_DATA_POINT_COUNT         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2001L)  /* ViInt32   */
#define AG3446X_ATTR_AUTO_RECALL_ENABLE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2002L)  /* ViBoolean */
	
#define AG3446X_ATTR_MEM_FORM_READING_SEPARATOR 		(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2003L)  /* ViInt32   */
#define AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED		(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2004L)  /* ViBoolean */
#define AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED			(IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2005L)  /* ViBoolean */

/*- Calibrate Group Attributes ---------------*/
#define AG3446X_ATTR_SECURITY_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3001L)  /* ViBoolean */
#define AG3446X_ATTR_CAL_VALUE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3002L)  /* ViReal64  */
#define AG3446X_ATTR_CAL_STRING               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3003L)  /* ViString  */

/*- Calculate Group Attributes ---------------*/
#define AG3446X_ATTR_LIMIT_ENABLED            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4001L)  /* ViBoolean */
#define AG3446X_ATTR_HIST_LOWER_RANGE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4002L)  /* ViReal64  */
#define AG3446X_ATTR_HIST_UPPER_RANGE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4003L)  /* ViReal64  */
#define AG3446X_ATTR_HIST_ENABLED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4004L)  /* ViBoolean */
#define AG3446X_ATTR_HIST_AUTO_RANGE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4005L)  /* ViBoolean */
#define AG3446X_ATTR_HIST_POINT               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4006L)  /* ViInt32   */
#define AG3446X_ATTR_LOWER_LIMIT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4007L)  /* ViReal64  */
#define AG3446X_ATTR_UPPER_LIMIT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4008L)  /* ViReal64  */
#define AG3446X_ATTR_SCALE_ENABLED            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4009L)  /* ViBoolean */
#define AG3446X_ATTR_AVER_ENABLED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4010L)  /* ViBoolean */
#define AG3446X_ATTR_SCALE_AUTO_REFERENCE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4011L)  /* ViBoolean */
#define AG3446X_ATTR_SCALE_FUNCTION           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4012L)  /* ViInt32   */
#define AG3446X_ATTR_SCALE_DBM_REFERENCE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4013L)  /* ViReal64  */
#define AG3446X_ATTR_SCALE_DB_REFERENCE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4014L)  /* ViReal64  */
#define AG3446X_ATTR_SCALE_GAIN				  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4015L)  /* ViReal64  */   
#define AG3446X_ATTR_SCALE_OFFSET			  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4016L)  /* ViReal64  */   
#define AG3446X_ATTR_SCALE_REFERENCE		  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4017L)  /* ViReal64  */   
#define AG3446X_ATTR_SCALE_UNIT		  		  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4018L)  /* ViString  */    
#define AG3446X_ATTR_SCALE_UNIT_ENABLED		  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4019L)  /* ViBoolean */ 
#define AG3446X_ATTR_SMOOTHING_RESPONSE		  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4020L)  /* ViInt32   */
#define AG3446X_ATTR_SMOOTHING_ENABLED		  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4021L)  /* ViBoolean */
#define AG3446X_ATTR_TREND_CHART_ENABLED	  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4022L)  /* ViBoolean */

/*- Configure Group Attributes ---------------*/
#define AG3446X_ATTR_CONF_MEAS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5001L)  /* ViInt32   */
    
    /*- Supported Models: 34460A, 34461A, 34465A, 34470A -----------------------------------*/
#define AG3446X_ATTR_ID_QUERY_RESPONSE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)    /* ViString, Read Only */
#define AG3446X_ATTR_MODEL                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)    /* ViInt32   */
#define AG3446X_ATTR_RANGE_CHANGE_MODE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5002L)

/**************************************************************************** 
 *------------------------ Attribute Value Defines -------------------------* 
 ****************************************************************************/

    /*- Defined values for attribute AG3446X_ATTR_FUNCTION -*/
#define AG3446X_VAL_DC_VOLTS              IVIDMM_VAL_DC_VOLTS    
#define AG3446X_VAL_AC_VOLTS              IVIDMM_VAL_AC_VOLTS    
#define AG3446X_VAL_DC_CURRENT            IVIDMM_VAL_DC_CURRENT  
#define AG3446X_VAL_AC_CURRENT            IVIDMM_VAL_AC_CURRENT  
#define AG3446X_VAL_2_WIRE_RES            IVIDMM_VAL_2_WIRE_RES  
#define AG3446X_VAL_4_WIRE_RES            IVIDMM_VAL_4_WIRE_RES           
#define AG3446X_VAL_FREQ                  IVIDMM_VAL_FREQ                 
#define AG3446X_VAL_PERIOD                IVIDMM_VAL_PERIOD               
#define AG3446X_VAL_TEMPERATURE           IVIDMM_VAL_TEMPERATURE
#define AG3446X_VAL_CONTINUITY            (IVIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 1L)
#define AG3446X_VAL_DIODE                 (IVIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 2L)
#define AG3446X_VAL_DC_VOLTS_RATIO        (IVIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 3L)
#define AG3446X_VAL_CAPACITANCE			  (IVIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 4L)		

    /*- Defined values for attribute AG3446X_ATTR_RANGE -*/
#define AG3446X_VAL_AUTO_RANGE_ON         IVIDMM_VAL_AUTO_RANGE_ON            
#define AG3446X_VAL_AUTO_RANGE_OFF        IVIDMM_VAL_AUTO_RANGE_OFF           
#define AG3446X_VAL_AUTO_RANGE_ONCE       IVIDMM_VAL_AUTO_RANGE_ONCE          

    /*- Defined values for attribute AG3446X_ATTR_TRIGGER_SOURCE -*/
	/*- Defined values for attribute AG3446X_ATTR_SAMPLE_TRIGGER -*/ 
#define AG3446X_VAL_IMMEDIATE             IVIDMM_VAL_IMMEDIATE
#define AG3446X_VAL_EXTERNAL              IVIDMM_VAL_EXTERNAL 
#define AG3446X_VAL_SOFTWARE_TRIG         IVIDMM_VAL_SOFTWARE_TRIG
#define AG3446X_VAL_TIMER                 (IVIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 1L)
#define AG3446X_VAL_INTERNAL              (IVIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 2L) 

    /*- Defined values for attribute AG3446X_ATTR_TEMP_TRANSDUCER_TYPE -*/
#define AG3446X_VAL_THERMOCOUPLE          IVIDMM_VAL_THERMOCOUPLE
#define AG3446X_VAL_2_WIRE_RTD            IVIDMM_VAL_2_WIRE_RTD
#define AG3446X_VAL_4_WIRE_RTD            IVIDMM_VAL_4_WIRE_RTD
#define AG3446X_VAL_2_WIRE_THER           IVIDMM_VAL_THERMISTOR 
#define AG3446X_VAL_4_WIRE_THER           (IVIDMM_VAL_TRANSDUCER_SPECIFIC_EXT_BASE + 1L)
    
    /*- Defined values for attribute AG3446X_ATTR_AUTO_ZER0 -*/
#define AG3446X_VAL_AUTO_ZERO_OFF         IVIDMM_VAL_AUTO_ZERO_OFF    
#define AG3446X_VAL_AUTO_ZERO_ON          IVIDMM_VAL_AUTO_ZERO_ON     
#define AG3446X_VAL_AUTO_ZERO_ONCE        IVIDMM_VAL_AUTO_ZERO_ONCE

    /*- Defined values for attribute AG3446X_ATTR_TRIGGER_DELAY -*/
#define AG3446X_VAL_AUTO_DELAY_ON         IVIDMM_VAL_AUTO_DELAY_ON    
#define AG3446X_VAL_AUTO_DELAY_OFF        IVIDMM_VAL_AUTO_DELAY_OFF   

    /*- Defined values for attribute AG3446X_ATTR_TRIGGER_SLOPE -*/
#define AG3446X_VAL_POSITIVE              IVIDMM_VAL_POSITIVE  
#define AG3446X_VAL_NEGATIVE              IVIDMM_VAL_NEGATIVE  

    /*- Defined values for attribute AG3446X_ATTR_APERTURE_TIME_UNITS -*/
#define AG3446X_VAL_SECONDS               IVIDMM_VAL_SECONDS          
#define AG3446X_VAL_POWER_LINE_CYCLES     IVIDMM_VAL_POWER_LINE_CYCLES
	
	/*- Defined values for Temperature Thermocouple Reference Junction Type -*/ 
#define AG3446X_VAL_TEMP_REF_JUNC_INTERNAL      IVIDMM_VAL_TEMP_REF_JUNC_INTERNAL
#define AG3446X_VAL_TEMP_REF_JUNC_FIXED         IVIDMM_VAL_TEMP_REF_JUNC_FIXED

	/*- Defined values for Temperature Thermocouple Type -*/  
#define AG3446X_VAL_TEMP_TC_E             IVIDMM_VAL_TEMP_TC_E
#define AG3446X_VAL_TEMP_TC_J             IVIDMM_VAL_TEMP_TC_J
#define AG3446X_VAL_TEMP_TC_K             IVIDMM_VAL_TEMP_TC_K
#define AG3446X_VAL_TEMP_TC_N             IVIDMM_VAL_TEMP_TC_N
#define AG3446X_VAL_TEMP_TC_R             IVIDMM_VAL_TEMP_TC_R
#define AG3446X_VAL_TEMP_TC_T             IVIDMM_VAL_TEMP_TC_T
    
    /*- Instrument specific attribute value definitions -*/

    /*- Defined values for attribute AG3446X_ATTR_SCALE_DBM_REFERENCE -*/
#define AG3446X_VAL_2     						2
#define AG3446X_VAL_4                           4
#define AG3446X_VAL_8                           8
#define AG3446X_VAL_16                          16
#define AG3446X_VAL_50                          50
#define AG3446X_VAL_75                          75
#define AG3446X_VAL_93                          93
#define AG3446X_VAL_110                         110
#define AG3446X_VAL_124                         124
#define AG3446X_VAL_125                         125
#define AG3446X_VAL_135                         135
#define AG3446X_VAL_150                         150
#define AG3446X_VAL_250                         250
#define AG3446X_VAL_300                         300
#define AG3446X_VAL_500                         500
#define AG3446X_VAL_600                         600
#define AG3446X_VAL_800                         800
#define AG3446X_VAL_900                         900
#define AG3446X_VAL_1000                        1000
#define AG3446X_VAL_1200                        1200
#define AG3446X_VAL_8000                        8000

/*- Defined values for attribute AG3446X_ATTR_SCALE_FUNCTION -*/
#define AG3446X_VAL_SCALE_FUNC_DB               1
#define AG3446X_VAL_SCALE_FUNC_DBM              2
#define AG3446X_VAL_SCALE_FUNC_PCT				3 
#define AG3446X_VAL_SCALE_FUNC_SCAL				4

/*- Defined values for attribute AG3446X_ATTR_HIST_POINT -*/
#define AG3446X_VAL_10                          10
#define AG3446X_VAL_20                          20
#define AG3446X_VAL_40                          40
#define AG3446X_VAL_100                         100
#define AG3446X_VAL_200                         200
#define AG3446X_VAL_400                         400

/*- Defined values for attribute AG3446X_ATTR_CLEAR_OPER -*/
#define AG3446X_VAL_CLEAR_ALL                   1
#define AG3446X_VAL_CLEAR_LIMIT                 2
#define AG3446X_VAL_CLEAR_HIST                  3
#define AG3446X_VAL_CLEAR_AVER                  4

/*- Defined values for attribute AG3446X_ATTR_CONF_MEAS -*/
#define AG3446X_VAL_CONF_MEAS_CONT              1
#define AG3446X_VAL_CONF_MEAS_AC_CURRENT        2
#define AG3446X_VAL_CONF_MEAS_DC_CURRENT        3
#define AG3446X_VAL_CONF_MEAS_DIODE             4
#define AG3446X_VAL_CONF_MEAS_FREQ              5
#define AG3446X_VAL_CONF_MEAS_PER               6
#define AG3446X_VAL_CONF_MEAS_RES               7
#define AG3446X_VAL_CONF_MEAS_FRES              8
#define AG3446X_VAL_CONF_MEAS_TEMP              9
#define AG3446X_VAL_CONF_MEAS_AC_VOLTAGE        10
#define AG3446X_VAL_CONF_MEAS_DC_VOLTAGE        11
#define AG3446X_VAL_CONF_MEAS_DC_VOLTAGE_RATIO  12
#define AG3446X_VAL_CONF_MEAS_CAP               13 

/*- Defined values for attribute AG3446X_ATTR_CURR_TERMINAL -*/
#define AG3446X_VAL_CURR_TERM_3                 3
#define AG3446X_VAL_CURR_TERM_10                10

/*- Defined values for Memory Data Operation -*/
#define AG3446X_VAL_MEM_DATA_OPER_DOWNLOAD      1
#define AG3446X_VAL_MEM_DATA_OPER_STORE         2
#define AG3446X_VAL_MEM_DATA_OPER_UPLOAD        3

/*- Defined values for Memory State File Operation -*/
#define AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD    1
#define AG3446X_VAL_MEM_STATE_FILE_OPER_STORE   2
#define AG3446X_VAL_MEM_STATE_FILE_OPER_RECALL  3

/*- Defined values for Memory Preference File Operation -*/
#define AG3446X_VAL_MEM_PREF_FILE_OPER_LOAD     1
#define AG3446X_VAL_MEM_PREF_FILE_OPER_STORE    2

/*- Defined values for Memory Directory Operation -*/
#define AG3446X_VAL_MEM_DIR_OPER_SELECT         1
#define AG3446X_VAL_MEM_DIR_OPER_MAKE           2
#define AG3446X_VAL_MEM_DIR_OPER_REMOVE         3

/*- Defined values for Memory File Operation -*/
#define AG3446X_VAL_MEM_FILE_OPER_COPY          1
#define AG3446X_VAL_MEM_FILE_OPER_MOVE          2
#define AG3446X_VAL_MEM_FILE_OPER_DELETE        3

/*- Defined values for Number of Measurements -*/ 
#define AG3446X_VAL_SMOOTHING_RESPONSE_SLOW		1
#define AG3446X_VAL_SMOOTHING_RESPONSE_MEDIUM	2
#define AG3446X_VAL_SMOOTHING_RESPONSE_FAST		3   

/*- Defined values for Memory Format Reading Separator -*/ 
#define AG3446X_VAL_SEPARATOR_COM               1
#define AG3446X_VAL_SEPARATOR_SEM               2
#define AG3446X_VAL_SEPARATOR_TAB               3

/*- Defined values for Secondary Function -*/  
#define AG3446X_VAL_SEC_FUNC_OFF                1
#define AG3446X_VAL_SEC_FUNC_CALC               2  
#define AG3446X_VAL_SEC_FUNC_VDC                3 
#define AG3446X_VAL_SEC_FUNC_VAC                4 
#define AG3446X_VAL_SEC_FUNC_CDC                5 
#define AG3446X_VAL_SEC_FUNC_CAC                6
#define AG3446X_VAL_SEC_FUNC_PER                7
#define AG3446X_VAL_SEC_FUNC_FREQ               8
#define AG3446X_VAL_SEC_FUNC_PTP                9
#define AG3446X_VAL_SEC_FUNC_SENS               10

#define AG3446X_VAL_RANGE_CHANGE_FAST           1
#define AG3446X_VAL_RANGE_CHANGE_CONT           2

#define AG3446X_VAL_SLOW                        1
#define AG3446X_VAL_MEDIUM                      2
#define AG3446X_VAL_FAST                        3

/**************************************************************************** 
 *---------------- Instrument Driver Function Declarations -----------------* 
 ****************************************************************************/

    /*- Init and Close Functions -------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_init (ViRsrc resourceName, ViBoolean IDQuery,
                                  ViBoolean resetDevice, ViSession *vi);
ViStatus _VI_FUNC  ag3446x_InitWithOptions (ViRsrc resourceName, ViBoolean IDQuery,
                                             ViBoolean resetDevice, ViConstString optionString, 
                                             ViSession *newVi);
ViStatus _VI_FUNC  ag3446x_close (ViSession vi);   

    /*- Coercion Info Functions --------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_GetNextCoercionRecord (ViSession vi,
                                                   ViInt32 bufferSize,
                                                   ViChar record[]);
    
    /*- Locking Functions --------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_LockSession (ViSession vi, ViBoolean *callerHasLock);   
ViStatus _VI_FUNC  ag3446x_UnlockSession (ViSession vi, ViBoolean *callerHasLock);

    /*- Basic Instrument Operation -----------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureMeasurement (ViSession vi, ViInt32 measFunction, ViReal64 range, 
                                                  ViReal64 resolution);
ViStatus _VI_FUNC ag3446x_ConfigureSecondaryMeasurement (ViSession vi, ViInt32 secondaryFunction);

ViStatus _VI_FUNC  ag3446x_ConfigureTrigger     (ViSession vi, ViInt32 triggerSource,
                                                  ViReal64 triggerDelay);
ViStatus _VI_FUNC  ag3446x_Read                 (ViSession vi, ViInt32 maxTime, ViReal64 *reading);
ViStatus _VI_FUNC  ag3446x_Fetch                (ViSession vi, ViInt32 maxTime, ViReal64 *reading);
ViStatus _VI_FUNC  ag3446x_Abort                (ViSession vi);
ViStatus _VI_FUNC  ag3446x_Initiate             (ViSession vi);
ViStatus _VI_FUNC  ag3446x_IsOverRange                  (ViSession vi, ViReal64 measurementValue,
                                                          ViBoolean *isOverRange);
ViStatus _VI_FUNC ag3446x_FetchHistogramMeasurement(ViSession vi, ViChar readings[1024]);

ViStatus _VI_FUNC ag3446x_ReadHistogramMeasurement(ViSession vi, ViChar readings[1024]);

ViStatus _VI_FUNC ag3446x_ReadStatisticsMeasurement(ViSession vi, ViReal64* standardDeviationValue, ViReal64* averageValue, 
                  ViReal64* countValue, ViReal64* maximumValue, ViReal64* minimumValue, ViReal64* peakToPeakValue);

ViStatus _VI_FUNC ag3446x_FetchStatisticsMeasurement(ViSession vi, ViReal64* standardDeviationValue, ViReal64* averageValue, 
                  ViReal64* countValue, ViReal64* maximumValue, ViReal64* minimumValue, ViReal64* peakToPeakValue);

ViStatus _VI_FUNC ag3446x_ReadMeasurementMemory(ViSession vi, ViInt32 readCount, ViBoolean enableWait, ViReal64 result[]);

ViStatus _VI_FUNC ag3446x_ReadLastMeasurement(ViSession vi, ViReal64* lastResult);

ViStatus _VI_FUNC ag3446x_ReadMeasurementCount(ViSession vi, ViInt32* dataPoints);

ViStatus _VI_FUNC ag3446x_ReadSecondaryMeasurement (ViSession vi, ViInt32 numberOfReadings, ViReal64 reading[3]);

    /*- Multi Point Measurement --------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureMeasCompleteDest (ViSession vi, ViInt32 measCompleteDest);
ViStatus _VI_FUNC  ag3446x_ConfigureMultiPoint (ViSession vi, ViInt32 triggerCount, 
                                                 ViInt32 sampleCount, ViInt32 sampleTrigger, ViReal64 sampleInterval);
ViStatus _VI_FUNC ag3446x_ConfigurePretrigger (ViSession vi, ViInt32 preTriggerCount);
ViStatus _VI_FUNC  ag3446x_ReadMultiPoint (ViSession vi, ViInt32 maxTime, ViInt32 arraySize, 
                                            ViReal64 readingArray[], ViInt32 *actualPts);
ViStatus _VI_FUNC  ag3446x_FetchMultiPoint (ViSession vi, ViInt32 maxTime, ViInt32 arraySize, 
                                             ViReal64 readingArray[], ViInt32 *actualPts); 
    
    /*- AC Measurement -----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureACBandwidth (ViSession vi, ViReal64 minFreq, ViReal64 maxFreq);
    

    /*- Frequency Measurement ----------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureFrequencyVoltageRange (ViSession vi, ViReal64 frequencyVoltageRange);

ViStatus _VI_FUNC ag3446x_ConfigureFrequencyTimeout (ViSession vi, ViBoolean enableAutoTimeout);
    
    /*- Temperature Measurement --------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureTransducerType (ViSession vi, ViInt32 transducerType);

ViStatus _VI_FUNC  ag3446x_ConfigureRTD (ViSession vi, ViReal64 alpha, ViReal64 resistance);

ViStatus _VI_FUNC ag3446x_ConfigureRTDAdvanced (ViSession vi, ViBoolean enablePowerLimit, 
												ViBoolean enableOffsetCompensation);

ViStatus _VI_FUNC  ag3446x_ConfigureThermistor (ViSession vi, ViReal64 resistance);

ViStatus _VI_FUNC ag3446x_ConfigureThermocouple (ViSession vi, ViInt32 thermocoupleType, 
												 ViInt32 RefJunctionType);

ViStatus _VI_FUNC ag3446x_ConfigureFixedRefJunction (ViSession vi, ViReal64 fixedRefJunction);

ViStatus _VI_FUNC ag3446x_ConfigureThermocoupleCheckEnabled (ViSession vi, ViBoolean enableTcCheck);

ViStatus _VI_FUNC ag3446x_ConfigureRefJunctionOffsetAdjustment (ViSession vi, ViReal64 adjustment);

ViStatus _VI_FUNC ag3446x_ConfigureThermistorPowerLimit (ViSession vi, ViBoolean enablePowerLimit);

    /*- Software Trigger ---------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_SendSoftwareTrigger (ViSession vi);

    /*- AutoRange Value ----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_GetAutoRangeValue (ViSession vi, ViReal64 *autoRangeValue); 

    /*- Device Information -------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_GetApertureTimeInfo (ViSession vi, ViReal64 *apertureTime, 
                                                 ViInt32 *apertureTimeUnits);  

ViStatus _VI_FUNC ag3446x_ConfigureApertureTime (ViSession vi, ViInt32 apertureTimeUnit,
											     ViReal64 apertureTime);
    /*- Trigger Slope  -----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureTriggerSlope (ViSession vi, ViInt32 polarity); 

	/*- Trigger Level ------------------------------------------------------*/
ViStatus _VI_FUNC ag3446x_ConfigureTriggerLevel (ViSession vi, ViReal64 triggerLevel); 

    /*- Auto Zero Mode -----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureAutoZeroMode (ViSession vi, ViInt32 autoZeroMode);

    /*- Memory Group Functions ---------------------------------------------*/
ViStatus _VI_FUNC ag3446x_ConfigureReadingMemory(ViSession vi, ViInt32 measurementCounts);

ViStatus _VI_FUNC ag3446x_QueryFileList(ViSession vi, ViInt32* memoryUsed, ViInt32* memoryFree, 
                  ViChar fileListing[512]);

ViStatus _VI_FUNC ag3446x_ConfigureFile(ViSession vi, ViInt32 operation, ViChar sourceFile[], 
                  ViChar destinationFile[]);

ViStatus _VI_FUNC ag3446x_ConfigureDirectory(ViSession vi, ViInt32 operation, ViChar folder[]);

ViStatus _VI_FUNC ag3446x_ValidateStateFile(ViSession vi, ViChar stateFile[], ViBoolean* isValid);

ViStatus _VI_FUNC ag3446x_ConfigureDataTransition(ViSession vi, ViInt32 operation, ViChar fileName[], 
                  ViChar binaryBlock[]);

ViStatus _VI_FUNC ag3446x_ConfigureStateFile(ViSession vi, ViInt32 operation, ViChar fileName[], 
                  ViBoolean enableAutoRecall);

ViStatus _VI_FUNC ag3446x_ConfigurePreferenceFile(ViSession vi, ViInt32 operation, ViChar fileName[]);

ViStatus _VI_FUNC ag3446x_ConfigureDataTransitionFormat (ViSession vi, ViInt32 separator, 
														 ViBoolean enableReadingInfo, 
                  										 ViBoolean enableRowLimit);

    /*- Configure Group Functions ----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureVoltageImpedance(ViSession vi, ViBoolean enableAutoImpedance);

ViStatus _VI_FUNC  ag3446x_ConfigureCurrentTerminals(ViSession vi, ViInt32 terminalValue);

ViStatus _VI_FUNC  ag3446x_ConfigureNullOperation(ViSession vi, ViBoolean enableNullFunction, ViReal64 nullValue, 
                   ViBoolean enableAutoValue);

ViStatus _VI_FUNC  ag3446x_ConfigureMeasurementTriggerParameters(ViSession vi, ViInt32 type);

ViStatus _VI_FUNC  ag3446x_ConfigureSmoothing (ViSession vi, ViInt32 numberOfMeasurements, ViBoolean enableSmoothing);

ViStatus _VI_FUNC  ag3446x_ConfigureTrendChartEnabled (ViSession vi, ViBoolean enableTrendChart); 

ViStatus _VI_FUNC  ag3446x_ConfigureResistance (ViSession vi, ViBoolean enablePowerLimit,
											    ViBoolean enableOffsetCompensation);

ViStatus _VI_FUNC ag3446x_ConfigureRangeChangeMode (ViSession vi, ViInt32 rangeChangeMode);

    /*- Calibrate Group Functions ----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ConfigureCalibrationSecurity(ViSession vi, ViChar securityCode[], ViBoolean enableSecurity);

ViStatus _VI_FUNC  ag3446x_Calibrate(ViSession vi, ViReal64 calibrationValue, ViChar calibrationMessage[], 
                   ViBoolean enableCalibrationStore, ViBoolean *calibrationResult);

ViStatus _VI_FUNC  ag3446x_CalibrateADC(ViSession vi, ViBoolean *calibrationResult);

    /*- Calculate Group Functions ----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_ClearCalculateData(ViSession vi, ViInt32 clearOperation);

ViStatus _VI_FUNC  ag3446x_ConfigureScale(ViSession vi, ViReal64 relativeValue, ViReal64 referenceResistance, 
                   ViInt32 scalingFunction, ViBoolean autoReference, ViBoolean enableScaling);

ViStatus _VI_FUNC  ag3446x_ConfigureScaleAdvanced(ViSession vi, ViReal64 gainValue, ViReal64 offsetValue, 
                   ViReal64 referenceValue);

ViStatus _VI_FUNC  ag3446x_ConfigureScaleUnit (ViSession vi, ViBoolean enableScaleUnit, 
				   ViChar scaleUnit[]);

ViStatus _VI_FUNC  ag3446x_ConfigureAverage(ViSession vi, ViBoolean enableAverage);

ViStatus _VI_FUNC  ag3446x_ConfigureLimit(ViSession vi, ViReal64 lowerLimit, ViReal64 upperLimit, 
                   ViBoolean enableLimit);

ViStatus _VI_FUNC  ag3446x_ConfigureHistogram(ViSession vi, ViReal64 lowerRange, ViReal64 upperRange, 
                   ViBoolean enableHistogram, ViBoolean autoHistogramRange, ViInt32 binCounts);

    /*- Error Functions ----------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_error_query (ViSession vi, ViInt32 *errorCode,
                                         ViChar errorMessage[]);

ViStatus _VI_FUNC  ag3446x_GetError (ViSession vi, ViStatus *code, 
                                      ViInt32 bufferSize, ViChar description[]);
ViStatus _VI_FUNC  ag3446x_ClearError (ViSession vi);

ViStatus _VI_FUNC  ag3446x_error_message (ViSession vi, ViStatus errorCode,
                                           ViChar errorMessage[256]);
    
    /*- Interchangeability Checking Functions ------------------------------*/
ViStatus _VI_FUNC  ag3446x_GetNextInterchangeWarning (ViSession vi, 
                                                      ViInt32 bufferSize, 
                                                      ViChar warnString[]);
ViStatus _VI_FUNC  ag3446x_ResetInterchangeCheck (ViSession vi);
ViStatus _VI_FUNC  ag3446x_ClearInterchangeWarnings (ViSession vi);

    /*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC  ag3446x_InvalidateAllAttributes (ViSession vi);
ViStatus _VI_FUNC  ag3446x_reset (ViSession vi);
ViStatus _VI_FUNC  ag3446x_ResetWithDefaults (ViSession vi);
ViStatus _VI_FUNC  ag3446x_self_test (ViSession vi, ViInt16 *selfTestResult,
                                       ViChar selfTestMessage[]);
ViStatus _VI_FUNC  ag3446x_revision_query (ViSession vi, 
                                            ViChar instrumentDriverRevision[],
                                            ViChar firmwareRevision[]);
ViStatus _VI_FUNC  ag3446x_Disable (ViSession vi);

ViStatus _VI_FUNC  ag3446x_viWrite (ViSession vi, ViByte buffer[], ViInt64 count, ViInt64 *returnCount);
ViStatus _VI_FUNC  ag3446x_viRead (ViSession vi, ViInt64 bufferSize, ViByte buffer[], ViInt64 *returnCount);
	/* Obsolete Direct IO Functions. */
ViStatus _VI_FUNC  ag3446x_WriteInstrData (ViSession vi, ViConstString writeBuffer); 
ViStatus _VI_FUNC  ag3446x_ReadInstrData  (ViSession vi, ViInt32 numBytes, 
                                            ViChar rdBuf[], ViInt32 *bytesRead);

    /*- Set, Get, and Check Attribute Functions ----------------------------*/
ViStatus _VI_FUNC  ag3446x_GetAttributeViInt32 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 *value);
ViStatus _VI_FUNC  ag3446x_GetAttributeViReal64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 *value);
ViStatus _VI_FUNC  ag3446x_GetAttributeViString (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 bufSize, ViChar value[]); 
ViStatus _VI_FUNC  ag3446x_GetAttributeViSession (ViSession vi, ViConstString channelName, ViAttr attribute, ViSession *value);
ViStatus _VI_FUNC  ag3446x_GetAttributeViBoolean (ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean *value);

ViStatus _VI_FUNC  ag3446x_SetAttributeViInt32 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC  ag3446x_SetAttributeViReal64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC  ag3446x_SetAttributeViString (ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value); 
ViStatus _VI_FUNC  ag3446x_SetAttributeViSession (ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC  ag3446x_SetAttributeViBoolean (ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);

ViStatus _VI_FUNC  ag3446x_CheckAttributeViInt32 (ViSession vi, ViConstString channelName, ViAttr attribute, ViInt32 value);
ViStatus _VI_FUNC  ag3446x_CheckAttributeViReal64 (ViSession vi, ViConstString channelName, ViAttr attribute, ViReal64 value);
ViStatus _VI_FUNC  ag3446x_CheckAttributeViString (ViSession vi, ViConstString channelName, ViAttr attribute, ViConstString value); 
ViStatus _VI_FUNC  ag3446x_CheckAttributeViSession (ViSession vi, ViConstString channelName, ViAttr attribute, ViSession value);
ViStatus _VI_FUNC  ag3446x_CheckAttributeViBoolean (ViSession vi, ViConstString channelName, ViAttr attribute, ViBoolean value);

/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/

#define AG3446X_WARN_OVER_RANGE                           IVIDMM_WARN_OVER_RANGE
#define AG3446X_ERROR_MAX_TIME_EXCEEDED                   IVIDMM_ERROR_MAX_TIME_EXCEEDED                  
#define AG3446X_ERROR_TRIGGER_NOT_SOFTWARE                IVIDMM_ERROR_TRIGGER_NOT_SOFTWARE
#define AG3446X_ERROR_INVALID_MODEL_TYPE                  (IVI_SPECIFIC_ERROR_BASE + 1L)

        /*- Advanced Session Information -*/
#define AG3446X_ATTR_IO_SESSION_TYPE                      IVI_ATTR_IO_SESSION_TYPE
#define AG3446X_ATTR_IO_SESSION                           IVI_ATTR_IO_SESSION  

/**************************************************************************** 
 *---------------------------- End Include File ----------------------------* 
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __AG3446X_HEADER */
