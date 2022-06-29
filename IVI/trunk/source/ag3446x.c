/**********************************************************************************
 *  Copyright 2013 - 2021, National Instruments, Corporation.  All Rights Reserved. *
 **********************************************************************************/


/*****************************************************************************
 *  Agilent/Keysight 3446X Series Instrument Driver
 *  LabWindows/CVI Instrument Driver
 *  Original Release:
 *  By: Xudong Yong, National Instruments, Shanghai China
 *
 *  Modification History:
 *
 *       07/12/2013 - Instrument Driver Created.
 *
 *       09/10/2014 - [zsu] Fix CAR#491077, modify the coerced rangetable to
 *                    coerced the max value to the right value.
 *
 *       01/30/2015 - [HL] Updated driver to comply with IVI-2014 generation.
 *                         Fix a bug in setting attribute AG3446X_ATTR_RESOLUTION_ABSOLUTE.
 *                         Fix a bug in function ag3446x_ConfigureLimit and ag3446x_ConfigureHistogram.
 *                    [ZW] Fix a bug in function ag3446x_ReadMultiPoint by using command "READ?".
 *		 03/31/2015 - [YL] Add support for new model 34465A and 34470A.
 *						   Fixed CAR 522470.
 *						   Fixed CAR 523384.
 *						   New attributes:
 *								AG3446X_ATTR_SAMPLE_TRIGGER
 *								AG3446X_ATTR_SAMPLE_INTERVAL
 * 								AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC
 *								AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE
 *								AG3446X_ATTR_TEMP_TC_TYPE
 *								AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER 	
 *								AG3446X_ATTR_TRIGGER_LEVEL			  	
 *								AG3446X_ATTR_APERTURE_TIME_NPLC       	 
 *								AG3446X_ATTR_APERTURE_TIME_SECONDS    	 
 *								AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED 	
 *								AG3446X_ATTR_POWER_LIMIT_ENABLED    	
 *								AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED 		
 *								AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED 			
 *								AG3446X_ATTR_TEMP_TC_CHECK_ENABLED  	
 *								AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ 	
 *								AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED 			
 *								AG3446X_ATTR_SECONDARY_FUNCTION     	
 *								AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED 	 
 *								AG3446X_ATTR_MEM_FORM_READING_SEPARATOR 		
 *								AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED		
 *								AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED			
 *								AG3446X_ATTR_SCALE_GAIN				     
 *								AG3446X_ATTR_SCALE_OFFSET			     
 *								AG3446X_ATTR_SCALE_REFERENCE		     
 *								AG3446X_ATTR_SCALE_UNIT		  		      
 *								AG3446X_ATTR_SCALE_UNIT_ENABLED		   
 *								AG3446X_ATTR_SMOOTHING_RESPONSE		  
 *								AG3446X_ATTR_SMOOTHING_ENABLED		  
 *								AG3446X_ATTR_TREND_CHART_ENABLED
 *								AG3446X_ATTR_RANGE_CHANGE_MODE
 *								
 *							New Hidden Attributes:
 *								AG3446X_ATTR_SAMPLE_INTERVAL_MIN    		
 *								AG3446X_ATTR_CALC_FUNC_ENABLED      		
 *								AG3446X_ATTR_OPTION                 		
 *								AG3446X_ATTR_TRIGGER_LEVEL_DCV      		
 *								AG3446X_ATTR_TRIGGER_LEVEL_DCI      		
 *								AG3446X_ATTR_TRIGGER_LEVEL_ACV      		
 *								AG3446X_ATTR_TRIGGER_LEVEL_ACI      		
 *								AG3446X_ATTR_TRIGGER_LEVEL_RES      		
 *								AG3446X_ATTR_TRIGGER_LEVEL_FREQ     		
 *								AG3446X_ATTR_TRIGGER_LEVEL_PER      		
 *								AG3446X_ATTR_TRIGGER_LEVEL_TEMP     		
 *								AG3446X_ATTR_RESOLUTION             		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_VDC 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_VAC 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_CDC 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_CAC 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_FREQ 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_PER 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_RES 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_TEMP 		
 *								AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO 	
 *								AG3446X_ATTR_SECONDARY_FUNCTION_CAP 
 *
 *							Modified Attributes:
 *								AG3446X_ATTR_FUNCTION	
 *								AG3446X_ATTR_RANGE
 *								AG3446X_ATTR_RESOLUTION_ABSOLUTE
 *								AG3446X_ATTR_TRIGGER_SOURCE
 *								AG3446X_ATTR_TEMP_TRANSDUCER_TYPE
 *								AG3446X_ATTR_SAMPLE_COUNT
 *								AG3446X_ATTR_APERTURE_TIME
 *								AG3446X_ATTR_APERTURE_TIME_UNITS
 *								AG3446X_ATTR_NULL_AUTO_ENABLED
 *								AG3446X_ATTR_NULL_VALUE
 *								AG3446X_ATTR_NULL_ENABLED
 *								AG3446X_ATTR_CONF_MEAS
 *								AG3446X_ATTR_MODEL
 *							
 *							New Functions:
 *								ConfigureSecondaryMeasurement
 *								ConfigureFrequencyTimeout
 *								ConfigureRTDAdvanced
 *								ConfigureThermocouple
 *								ConfigureFixedRefJunction
 *								ConfigureThermocoupleCheckEnabled
 *								ConfigureRefJunctionOffsetAdjustment
 *								ConfigureThermistorPowerLimit
 *								ConfigureTriggerLevel
 *								ConfigurePretrigger
 *								ConfigureDataTransitionFormat
 *								ConfigureScaleAdvanced
 *								ConfigureScaleUnit
 *								ConfigureSmoothing
 *								ConfigureTrendChartEnabled
 *								ConfigureResistance
 *								ConfigureApertureTime
 *								ReadSecondaryMeasurement
 *		 05/16/2015 - [YL] Fix CAR 526339     
 *		 06/10/2015 - [YL] Fix CAR 530170
 *		 08/26/2021 - [Shashi Kumar BS] Instrument Driver Updated.
 *					  		Add support for new model EDU34450A.						   
 *					  		New Range Tables:
 *					      		attrCountEDU34450ARangeTable
 *					      		attrLimitEDU34450ARangeTable   
 *					      		attrConfMeasEDU34450ARangeTable
 *					      		attrEDU34450ADbReferenceRangeTable
 *					      		attrEDU34450ADbmReferenceRangeTable
 *					      		attrEDU34450AFunctionRangeTable
 *					      		attrRangeACVoltageEDU34450ARangeTable
 *					      		attrRangeDCVoltageEDU34450ARangeTable
 *					      		attrRangeCapacitanceEDU34450ARangeTable
 *					      		attrRangeResistanceEDU34450ARangeTable
 *					      		attrRangeCurrentEDU34450ARangeTable
 *					      		attrResolutionEDU34450ARangeTable
 *					      		attrTriggerSourceEDU344520ARangeTable
 *					      		attrFreqVoltageRangeEDU34450ARangeTable
 *					      		attrSampleIntervalEDU34450ARangeTable
 *					      		attrApertureTimeSecondsEDU34450AFreqRangeTable
 *
 *							New Range Table CallBacks:
 *						  		ag3446xAttrFreqVoltageRange_RangeTableCallback
 *						  		ag3446xAttrTriggerDelay_RangeTableCallback
 *								ag3446xAttrTriggerCount_RangeTableCallback
 *						  		ag3446xAttrConfMeas_RangeTableCallback
 *						  		ag3446xAttrScaleDbReference_RangeTableCallback
 *						  		ag3446xAttrSampleInterval_RangeTableCallback
 *								ag3446xAttrScaleDbmReference_RangeTableCallback
 *								ag3446xAttrTriggerSource_RangeTableCallback
 *
 *							New Range check callbacks
 *					  	   		ag3446xAttrFreqVoltageRange_CheckCallback
 * 								ag3446xAttrTriggerDelay_CheckCallback
 *								ag3446xAttrRange_CheckCallback
 *								ag3446xScaleFunction_RangeTableCallback
 *								ag3446xAttrApertureTimeSeconds_CheckCallback 
 *
 *							New Read/Write callbacks
 *								ag3446xAttrScaleDbReference_ReadCallback
 *								ag3446xAttrScaleDbReference_WriteCallback
 *								ag3446xAttrScaleFunction_ReadCallback
 *								ag3446xAttrScaleFunction_WriteCallback
 *								ag3446xAttrScaleDbmReference_ReadCallback
 *								ag3446xAttrScaleDbmReference_WriteCallback
 *
*****************************************************************************/

#include <ansi_c.h>
#include <visa.h>
#include <string.h>
#include <stdio.h>
#include <formatio.h>
#include <stdlib.h>
#include "ag3446x.h"

/*****************************************************************************
 *--------------------- Hidden Attribute Declarations -----------------------*
 *****************************************************************************/

#define AG3446X_ATTR_OPC_TIMEOUT    				(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 1L)             /* ViInt32   */
#define AG3446X_ATTR_SAMPLE_INTERVAL_MIN    		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 2L)			  /* ViReal64  */
#define AG3446X_ATTR_CALC_FUNC_ENABLED      		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 3L)			  /* ViBoolean */
#define AG3446X_ATTR_OPTION                 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 4L)			  /* ViInt32   */
#define AG3446X_ATTR_TRIGGER_LEVEL_DCV      		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 5L)			  /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_LEVEL_DCI      		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 6L)			  /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_LEVEL_ACV      		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 7L)			  /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_LEVEL_ACI      		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 8L)			  /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_LEVEL_RES      		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 9L)			  /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_LEVEL_FREQ     		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 10L)			  /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_LEVEL_PER      		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 11L)			  /* ViReal64  */
#define AG3446X_ATTR_TRIGGER_LEVEL_TEMP     		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 12L)			  /* ViReal64  */
#define AG3446X_ATTR_RESOLUTION             		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 13L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_VDC 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 14L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_VAC 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 15L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_CDC 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 16L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_CAC 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 17L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_FREQ 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 18L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_PER 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 19L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_RES 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 20L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_TEMP 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 21L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO 	(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 22L)			  /* ViReal64  */
#define AG3446X_ATTR_SECONDARY_FUNCTION_CAP 		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 23L)			  /* ViReal64  */
#define AG3446X_ATTR_APERTURE_TIME_NPLC     		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 24L)			  /* ViReal64  */
#define AG3446X_ATTR_APERTURE_TIME_SECONDS  		(IVI_SPECIFIC_PRIVATE_ATTR_BASE + 25L)			  /* ViReal64  */

/*****************************************************************************
 *---------------------------- Useful Macros --------------------------------*
 *****************************************************************************/

/*- I/O buffer size -----------------------------------------------------*/
#define SMALL_BUFFER_SIZE                        128L
#define BUFFER_SIZE                              512L
#define EXTENDED_BUFFER_SIZE                     8300L       /*  For Multi-Point Fetch function */

/*- 488.2 Event Status Register (ESR) Bits ------------------------------*/
#define IEEE_488_2_QUERY_ERROR_BIT               0x04
#define IEEE_488_2_DEVICE_DEPENDENT_ERROR_BIT    0x08
#define IEEE_488_2_EXECUTION_ERROR_BIT           0x10
#define IEEE_488_2_COMMAND_ERROR_BIT             0x20

/*- List of channels passed to the Ivi_BuildChannelTable function -------*/
#define CHANNEL_LIST                             "1"

/*- Macros for access to enum range table -----------------------------------*/
#define ag3446x_GetCmdFromIntValue(value, table, cmd) \
    Ivi_GetViInt32EntryFromValue (value, table, VI_NULL, VI_NULL, \
                                  VI_NULL, VI_NULL, cmd, VI_NULL)

#define ag3446x_GetValueFromCmd(buffer, table, value) \
    Ivi_GetViInt32EntryFromString (buffer, table, value, VI_NULL, \
                                   VI_NULL, VI_NULL, VI_NULL)

/*- Macros for model and options checking -----------------------------------*/

#define IS_34460A(modelType)	(modelType == AG3446X_VAL_MODEL_34460A) 
#define IS_34461A(modelType)	(modelType == AG3446X_VAL_MODEL_34461A)  
#define IS_34465A(modelType)	(modelType == AG3446X_VAL_MODEL_34465A)  
#define IS_34470A(modelType)	(modelType == AG3446X_VAL_MODEL_34470A) 
#define IS_EDU34450A(modelType)	(modelType == AG3446X_VAL_MODEL_EDU34450A)

enum
{
	AG3446X_VAL_OPT_GPB 	= 	(1 << 0),
	AG3446X_VAL_OPT_LAN		= 	(1 << 1),
	AG3446X_VAL_OPT_SEC		= 	(1 << 2), 
	AG3446X_VAL_OPT_DIG		= 	(1 << 3), 
	AG3446X_VAL_OPT_MEM		= 	(1 << 4) 
};

#define IS_DIG_INSTALLED(options)	((options & AG3446X_VAL_OPT_DIG) != 0)
#define IS_MEM_INSTALLED(options)	((options & AG3446X_VAL_OPT_MEM) != 0)

/*
 * Table, which associate numeric model identifier
 * with string interpretation in *IDN? query
 */
static IviStringValueTable ag3446x_ModelTable =
{
    { AG3446X_VAL_MODEL_34460A, "34460A" },
    { AG3446X_VAL_MODEL_34461A, "34461A" },
    { AG3446X_VAL_MODEL_34465A, "34465A" },
    { AG3446X_VAL_MODEL_34470A, "34470A" },
	{ AG3446X_VAL_MODEL_EDU34450A, "EDU34450A"},
    { VI_NULL,                  VI_NULL  }
};

/*
 * Table, which associate numeric option value
 * with string interpretation in *OPT? query
 */
static IviStringValueTable ag3446x_OptionTable =
{
    { AG3446X_VAL_OPT_GPB, "GPB"    },
    { AG3446X_VAL_OPT_LAN, "LAN"    },
    { AG3446X_VAL_OPT_SEC, "SEC"    },
    { AG3446X_VAL_OPT_DIG, "DIG"    },
	{ AG3446X_VAL_OPT_MEM, "MEM"    }, 
    { VI_NULL,             VI_NULL  }
};

/*****************************************************************************/
/*-------------- Typedefs for string-value-revision tables ------------------*/
/*****************************************************************************/
typedef struct { ViInt32       value;        /* Attribute ID */
                 ViConstString string;       /* Command */
                 ViConstString repCommand;   /* Extension for Repeated Command */
} ag3446xStringValueEntry;

typedef ag3446xStringValueEntry   ag3446xStringValueTable[];

/*- Macros for the wrapper of empty channel name */
#define VALID_CHANNELNAME(channelName) \
    (VI_NULL == channelName ? "" : channelName)

static ag3446xStringValueTable ag3446xEnum_commands =
{   /* Attribute ID,                  			SCPI command       */
    { AG3446X_ATTR_TRIGGER_SOURCE,       		"TRIG:SOUR",      			""      },
    { AG3446X_ATTR_TEMP_TRANSDUCER_TYPE, 		"TEMP:TRAN:TYPE", 			""      },
    { AG3446X_ATTR_TRIGGER_SLOPE,        		"TRIG:SLOP",      			""      },
 	{ AG3446X_ATTR_SMOOTHING_RESPONSE,   		"CALC:SMO:RESP",  			""	    },
	{ AG3446X_ATTR_MEM_FORM_READING_SEPARATOR,	"MMEM:FORM:READ:CSEP",		""		},
	{ AG3446X_ATTR_SAMPLE_TRIGGER, 				"SAMP:SOUR",				""		},
	{ AG3446X_ATTR_TEMP_TC_TYPE,				"TEMP:TRAN:TC:TYPE",		""		},
	{ AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE,		"TEMP:TRAN:TC:RJUN:TYPE",	""		},
    { AG3446X_ATTR_SECONDARY_FUNCTION_VDC,		"VOLT:SEC",	 				""		},		
    { AG3446X_ATTR_SECONDARY_FUNCTION_VAC, 		"VOLT:AC:SEC", 				""		},
    { AG3446X_ATTR_SECONDARY_FUNCTION_CDC,		"CURR:SEC", 				""		},
    { AG3446X_ATTR_SECONDARY_FUNCTION_CAC, 		"CURR:AC:SEC", 				""		},
    { AG3446X_ATTR_SECONDARY_FUNCTION_FREQ, 	"FREQ:SEC", 				""		},	
    { AG3446X_ATTR_SECONDARY_FUNCTION_PER, 		"PER:SEC", 					""		},
    { AG3446X_ATTR_SECONDARY_FUNCTION_RES, 		"RES:SEC", 					""		},
    { AG3446X_ATTR_SECONDARY_FUNCTION_TEMP, 	"TEMP:SEC", 				""		},	
    { AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO, "VOLT:RAT:SEC", 			""		},	
    { AG3446X_ATTR_SECONDARY_FUNCTION_CAP, 		"CAP:SEC", 					""		},
	{ AG3446X_ATTR_RANGE_CHANGE_MODE,           "CURR:SWIT:MODE",      		""		},
    { VI_NULL,                           		VI_NULL,          			VI_NULL }
};

static ag3446xStringValueTable ag3446xViString_commands =
{   /* Attribute ID,           SCPI command       */
    { AG3446X_ATTR_CAL_STRING, "CAL:STR", 				"" 	},
	{ AG3446X_ATTR_SCALE_UNIT, "CALC:SCAL:UNIT",    	"" 	},
    { VI_NULL,                 VI_NULL,   VI_NULL }
};

static ag3446xStringValueTable ag3446xViBoolean_commands =
{   /* Attribute ID,                  							SCPI command       */
    { AG3446X_ATTR_VOLT_AUTO_IMPEDANCE,  						"VOLT:IMP:AUTO",            ""      },
    { AG3446X_ATTR_AUTO_RECALL_ENABLE,   						"MMEM:STAT:REC:AUTO",       ""      },
    { AG3446X_ATTR_SECURITY_ENABLED,     						"CAL:SEC:STAT",             ""      },
    { AG3446X_ATTR_LIMIT_ENABLED,        						"CALC:LIM",                 ""      },
    { AG3446X_ATTR_HIST_ENABLED,         						"CALC:TRAN:HIST",           ""      },
    { AG3446X_ATTR_HIST_AUTO_RANGE,      						"CALC:TRAN:HIST:RANG:AUTO", ""      },
    { AG3446X_ATTR_SCALE_ENABLED,        						"CALC:SCAL",                ""      },
    { AG3446X_ATTR_SCALE_AUTO_REFERENCE, 						"CALC:SCAL:REF:AUTO",       ""      },
	{ AG3446X_ATTR_SCALE_UNIT_ENABLED,	 						"CALC:SCAL:UNIT:STAT", 	 	""		},
	{ AG3446X_ATTR_SMOOTHING_ENABLED,    						"CALC:SMO",      			""		},
	{ AG3446X_ATTR_TREND_CHART_ENABLED,  						"CALC:TCH",      			""		},
	{ AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED,   			"MMEM:FORM:READ:INF",      	""		},
	{ AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED,      			"MMEM:FORM:READ:RLIM",      ""		},
	{ AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED,					"RES:OCOM",					""		},
	{ AG3446X_ATTR_POWER_LIMIT_ENABLED, 						"RES:POW:LIM",				"" 		},
	{ AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED,	"TEMP:TRAN:RTD:OCOM",		""		},
	{ AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED,			"TEMP:TRAN:RTD:POW:LIM",	""		},
	{ AG3446X_ATTR_TEMP_TC_CHECK_ENABLED,						"TEMP:TRAN:TC:CHEC",		""		},
	{ AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED,			"TEMP:TRAN:THER:POW:LIM",	""		},
	{ AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED,					"FREQ:TIM:AUTO",			""		},
    { VI_NULL,                          		 				VI_NULL,                    VI_NULL }
};

static ag3446xStringValueTable ag3446xViReal64_commands =
{   /* Attribute ID,                  			SCPI command          */
    { AG3446X_ATTR_CAL_VALUE,           		"CAL:VAL",                 		""      },
    { AG3446X_ATTR_HIST_LOWER_RANGE,    		"CALC:TRAN:HIST:RANG:LOW", 		""      },
    { AG3446X_ATTR_HIST_UPPER_RANGE,    		"CALC:TRAN:HIST:RANG:UPP", 		""      },
    { AG3446X_ATTR_LOWER_LIMIT,         		"CALC:LIM:LOW",            		""      },
    { AG3446X_ATTR_UPPER_LIMIT,         		"CALC:LIM:UPP",            		""      },
	{ AG3446X_ATTR_TEMP_THERMISTOR_RES,      	"TEMP:TRAN:THER:TYPE",      	""      },
    { AG3446X_ATTR_TEMP_RTD_ALPHA,      		"TEMP:TRAN:RTD:TYPE",      		""      },
	{ AG3446X_ATTR_SCALE_GAIN,          		"CALC:SCAL:GAIN",      	   		""      },
	{ AG3446X_ATTR_SCALE_OFFSET,        		"CALC:SCAL:OFFS",          		""      },
	{ AG3446X_ATTR_SCALE_REFERENCE,     		"CALC:SCAL:REF",           		""      },
	{ AG3446X_ATTR_SAMPLE_INTERVAL, 			"SAMP:TIM", 			   		""	    },
	{ AG3446X_ATTR_TRIGGER_LEVEL,				"TRIG:LEV",				   		""	    },
	{ AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC, 		"TEMP:TRAN:TC:RJUN",	   		""	    },
	{ AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ, 	"TEMP:TRAN:TC:RJUN:OFFS:ADJ",	""		},
    { VI_NULL,                          		VI_NULL,                   		VI_NULL }
};

static ag3446xStringValueTable ag3446xViInt32_commands =
{   /* Attribute ID,                  			SCPI command          */
    { AG3446X_ATTR_DATA_POINT_COUNT, 			"DATA:POIN:EVEN:THR",  ""      },
    { AG3446X_ATTR_HIST_POINT,       			"CALC:TRAN:HIST:POIN", ""      },
    { AG3446X_ATTR_SAMPLE_COUNT,     			"SAMP:COUN",           ""      },
    { AG3446X_ATTR_TRIGGER_COUNT,    			"TRIG:COUN",           ""      },
	{ AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER, 	"SAMP:COUN:PRET",	   ""	   },
    { VI_NULL,                       			VI_NULL,               VI_NULL }
};

/*****************************************************************************
 *-------------- Utility Function Declarations (Non-Exported) ---------------*
 *****************************************************************************/
static ViStatus ag3446x_IviInit (ViRsrc resourceName, ViBoolean IDQuery, ViBoolean reset, ViSession vi);
static ViStatus ag3446x_IviClose (ViSession vi);
static ViStatus ag3446x_InitAttributes (ViSession vi, ViInt32 modelNum);
static ViStatus ag3446x_DefaultInstrSetup (ViSession openInstrSession);
static ViStatus ag3446x_CheckStatus (ViSession vi);
static ViStatus ag3446x_WaitForOPC (ViSession vi, ViInt32 maxTime);
static ViStatus ag3446x_GetActualRange (ViSession vi, ViSession io, ViReal64 *value);
static ViStatus ag3446x_GetDriverSetupOption (ViSession vi, ViConstString optionTag,
                                              ViInt32 optionValueSize, ViChar optionValue[]);

/*- File I/O Utility Functions -*/
static ViStatus ag3446x_GetStringFromTable (ag3446xStringValueTable table, ViInt32 value,
                                            ViConstString* string);

static ViInt32 *StringToNumeric (ViChar inputStr[], ViInt32 *outputNum);
static ViInt32 StringToReal64Array (ViChar dataStr[],
                                    ViInt32 resultDataSize,
                                    ViReal64 resultData[],
                                    ViChar delimiter);

static ViStatus ag3446x_QueryID (ViSession vi,
                                 ViSession io,
                                 ViInt32 bufferSize,
                                 ViChar buffer[]);

static ViStatus ag3446x_GetModelFromBuffer (ViSession vi,
                                             ViConstString buffer,
                                             ViInt32* pModelType);

static ViStatus ag3446x_QueryOptions (ViSession vi,
                                      ViSession io,
                                      ViInt32 bufferSize,
                                      ViChar buffer[]);

static ViStatus ag3446x_GetOptionsFromBuffer (ViSession vi,
                                              ViConstString buffer,
                                              ViInt32 *value);

static void ag3446x_RemoveSurroundingWhiteSpace (ViChar string[]);

static ViStatus ag3446x_GetValueFromTable(IviStringValueTable stringTable, ViChar string[ ], ViInt32* value);

static ViBoolean ag3446x_StrCmpWithoutTerminators(ViConstString string, ViConstString stringWithTerminators);

/*****************************************************************************
 *----------------- Callback Declarations (Non-Exported) --------------------*
 *****************************************************************************/

/*- Global Session Callbacks --------------------------------------------*/

static ViStatus _VI_FUNC ag3446x_CheckStatusCallback (ViSession vi, ViSession io);

static ViStatus _VI_FUNC ag3446x_WaitForOPCCallback (ViSession vi, ViSession io);

/*- Attribute callbacks -------------------------------------------------*/

static ViStatus _VI_FUNC ag3446xAttrDriverRevision_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 const ViConstString cacheValue);
static ViStatus _VI_FUNC ag3446xAttrInstrumentManufacturer_ReadCallback (ViSession vi,
                                                                         ViSession io,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         const ViConstString cacheValue);
static ViStatus _VI_FUNC ag3446xAttrInstrumentModel_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  const ViConstString cacheValue);

static ViStatus _VI_FUNC ag3446xAttrFirmwareRevision_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   const ViConstString cacheValue);
static ViStatus _VI_FUNC ag3446xAttrIdQueryResponse_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  const ViConstString cacheValue);
static ViStatus _VI_FUNC ag3446xAttrFunction_ReadCallback (ViSession vi,
                                                           ViSession io,
                                                           ViConstString channelName,
                                                           ViAttr attributeId,
                                                           ViInt32 *value);
static ViStatus _VI_FUNC ag3446xAttrFunction_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value);
static ViStatus _VI_FUNC ag3446xAttrRange_ReadCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrRange_WriteCallback (ViSession vi,
                                                         ViSession io,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrRange_RangeTableCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              IviRangeTablePtr *rangeTablePtr);
static ViStatus _VI_FUNC ag3446xAttrResolutionAbsolute_CheckCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrResolutionAbsolute_ReadCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrResolutionAbsolute_WriteCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrAcMinFreq_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrAcMinFreq_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrTempRtdRes_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrTempRtdRes_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrApertureTime_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrApertureTime_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrApertureTimeUnits_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViInt32 *value);
static ViStatus _VI_FUNC ag3446xAttrApertureTimeUnits_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViInt32 value);
static ViStatus _VI_FUNC ag3446xAttrAutoRangeValue_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrAutoZero_ReadCallback (ViSession vi,
                                                           ViSession io,
                                                           ViConstString channelName,
                                                           ViAttr attributeId,
                                                           ViInt32 *value);
static ViStatus _VI_FUNC ag3446xAttrAutoZero_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value);
static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrCurrTerminal_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViInt32 *value);
static ViStatus _VI_FUNC ag3446xAttrCurrTerminal_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViInt32 value);
static ViStatus _VI_FUNC ag3446xAttrNullAutoEnable_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViBoolean *value);
static ViStatus _VI_FUNC ag3446xAttrNullAutoEnable_WriteCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViBoolean value);
static ViStatus _VI_FUNC ag3446xAttrNullValue_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 *value);
static ViStatus _VI_FUNC ag3446xAttrNullValue_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrNullValue_RangeTableCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  IviRangeTablePtr *rangeTablePtr);
static ViStatus _VI_FUNC ag3446xAttrNullEnable_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value);
static ViStatus _VI_FUNC ag3446xAttrNullEnable_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value);
static ViStatus _VI_FUNC ag3446xAttrDataPointCount_RangeTableCallback (ViSession vi,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       IviRangeTablePtr *rangeTablePtr);
static ViStatus _VI_FUNC ag3446xAttrHistLowerRange_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrHistUpperRange_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrLowerLimit_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrUpperLimit_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value);
static ViStatus _VI_FUNC ag3446xAttrConfMeas_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value);

static ViStatus _VI_FUNC ag3446xEnum_ReadCallback (ViSession vi, ViSession io,
                                                   ViConstString channelName,
                                                   ViAttr attributeId,
                                                   ViInt32 *value);

static ViStatus _VI_FUNC ag3446xEnum_WriteCallback (ViSession vi, ViSession io,
                                                    ViConstString channelName,
                                                    ViAttr attributeId,
                                                    ViInt32 value);

static ViStatus _VI_FUNC ag3446xViBoolean_ReadCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViBoolean *value);

static ViStatus _VI_FUNC ag3446xViBoolean_WriteCallback (ViSession vi,
                                                         ViSession io,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViBoolean value);

static ViStatus _VI_FUNC ag3446xViInt32_ReadCallback (ViSession vi, ViSession io,
                                                      ViConstString channelName,
                                                      ViAttr attributeId,
                                                      ViInt32 *value);

static ViStatus _VI_FUNC ag3446xViInt32_WriteCallback (ViSession vi,
                                                       ViSession io,
                                                       ViConstString channelName,
                                                       ViAttr attributeId,
                                                       ViInt32 value);

static ViStatus _VI_FUNC ag3446xViReal64_ReadCallback (ViSession vi,
                                                       ViSession io,
                                                       ViConstString channelName,
                                                       ViAttr attributeId,
                                                       ViReal64 *value);

static ViStatus _VI_FUNC ag3446xViReal64_WriteCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViReal64 value);

static ViStatus _VI_FUNC ag3446xViString_ReadCallback (ViSession vi,
                                                       ViSession io,
                                                       ViConstString channelName,
                                                       ViAttr attributeId,
                                                       const ViConstString cacheValue);

static ViStatus _VI_FUNC ag3446xViString_WriteCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViConstString value);

static ViStatus _VI_FUNC ag3446xScaleFunction_RangeTableCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  IviRangeTablePtr *rangeTablePtr); 

static ViStatus _VI_FUNC ag3446xScaleUnit_CheckCallback (ViSession vi,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViConstString value);

static ViStatus _VI_FUNC ag3446xAttrConfMeas_CheckCallback (ViSession vi,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value);

static ViStatus _VI_FUNC ag3446xSampleInterval_CoerceCallback (ViSession vi,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 value,
                                                               ViReal64 *coercedValue);

static ViStatus _VI_FUNC ag3446xAttrSampleInterval_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrSampleIntervalMin_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrSampleCountPreTrigger_CheckCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         ViInt32 value);

static ViStatus _VI_FUNC ag3446xAttrCalcFuncEnabled_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViBoolean *value);

static ViStatus _VI_FUNC ag3446xAttrTriggerSource_RangeTableCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevel_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevel_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelDcv_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelAci_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelAcv_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelDci_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelRes_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelMeas_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelMeas_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerLevel_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);
																				   
static ViStatus _VI_FUNC ag3446xAttrResolution_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrResolution_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrResolution_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrApertureTimeNplc_RangeTableCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrApertureTimeNplc_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrApertureTimeNplc_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_CoerceCallback (ViSession vi,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value,
                                                                        ViReal64 *coercedValue);

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_RangeTableCallback (ViSession vi,
                                                                            ViConstString channelName,
                                                                            ViAttr attributeId,
                                                                            IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrOffsetCompensateEnabled_CheckCallback (ViSession vi,
                                                                           ViConstString channelName,
                                                                           ViAttr attributeId,
                                                                           ViBoolean value);

static ViStatus _VI_FUNC ag3446xAttrPowerLimitEnabled_CheckCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViBoolean value);

static ViStatus _VI_FUNC ag3446xAttrTempTransducerType_CheckCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 value);

static ViStatus _VI_FUNC ag3446xAttrSecondaryFunction_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViInt32 *value);

static ViStatus _VI_FUNC ag3446xAttrSecondaryFunction_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViInt32 value);

static ViStatus _VI_FUNC ag3446xAttrSampleCount_RangeTableCallback (ViSession vi,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrRangeChangeMode_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViInt32 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerCount_RangeTableCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrSampleInterval_RangeTableCallback (ViSession vi,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrFunction_RangeTableCallback (ViSession vi,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_RangeTableCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_RangeTableCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     IviRangeTablePtr *rangeTablePtr);



static ViStatus _VI_FUNC ag3446xAttrUpperLimit_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrLowerLimit_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrConfMeas_RangeTableCallback (ViSession vi,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 IviRangeTablePtr *rangeTablePtr);



static ViStatus _VI_FUNC ag3446xAttrRange_CheckCallback (ViSession vi,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViReal64 value);



static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_CheckCallback (ViSession vi,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);



static ViStatus _VI_FUNC ag3446xAttrScaleDbReference_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrScaleDbReference_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrScaleDbReference_RangeTableCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrScaleDbmReference_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 *value);

static ViStatus _VI_FUNC ag3446xAttrScaleDbmReference_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViReal64 value);

static ViStatus _VI_FUNC ag3446xAttrScaleDbmReference_RangeTableCallback (ViSession vi,
                                                                          ViConstString channelName,
                                                                          ViAttr attributeId,
                                                                          IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC ag3446xAttrScaleFunction_ReadCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViInt32 *value);

static ViStatus _VI_FUNC ag3446xAttrScaleFunction_WriteCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViInt32 value);


static ViStatus _VI_FUNC ag3446xAttrAverEnabled_WriteCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViBoolean value);

static ViStatus _VI_FUNC ag3446xAttrLimitEnabled_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViBoolean *value);

static ViStatus _VI_FUNC ag3446xAttrLimitEnabled_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value);


static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_CheckCallback (ViSession vi,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 value);

/*****************************************************************************
 *------------ User-Callable Functions (Exportable Functions) ---------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: ag3446x_init
 * Purpose:  VXIplug&play required function.  Calls the
 *           ag3446x_InitWithOptions function.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_init (ViRsrc resourceName, ViBoolean IDQuery,
                                ViBoolean resetDevice, ViSession *newVi)
{
    ViStatus error = VI_SUCCESS;

    if (newVi == VI_NULL)
    {
        Ivi_SetErrorInfo (VI_NULL, VI_FALSE, IVI_ERROR_INVALID_PARAMETER,
                          VI_ERROR_PARAMETER4, "Null address for Instrument Handle");
        checkErr (IVI_ERROR_INVALID_PARAMETER);
    }

    checkErr (ag3446x_InitWithOptions (resourceName, IDQuery, resetDevice,
                                       "", newVi));

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446x_InitWithOptions
 * Purpose:  This function creates a new IVI session and calls the
 *           IviInit function.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_InitWithOptions (ViRsrc resourceName, ViBoolean IDQuery,
                                           ViBoolean resetDevice, ViConstString optionString,
                                           ViSession *newVi)
{
    ViStatus  error = VI_SUCCESS;
    ViSession vi    = VI_NULL;
    ViChar    newResourceName[IVI_MAX_MESSAGE_BUF_SIZE];
    ViChar    newOptionString[IVI_MAX_MESSAGE_BUF_SIZE];
    ViBoolean isLogicalName;

    if (newVi == VI_NULL)
    {
        Ivi_SetErrorInfo (VI_NULL, VI_FALSE, IVI_ERROR_INVALID_PARAMETER,
                          VI_ERROR_PARAMETER5, "Null address for Instrument Handle");
        checkErr (IVI_ERROR_INVALID_PARAMETER);
    }

    *newVi = VI_NULL;

    checkErr (Ivi_GetInfoFromResourceName (resourceName, (ViString) optionString,
                                           newResourceName,
                                           newOptionString,
                                           &isLogicalName));

    /* create a new interchangeable driver */
    checkErr (Ivi_SpecificDriverNew ("ag3446x", newOptionString, &vi));
    if (!isLogicalName)
    {
        ViInt32 oldFlag = 0;

        checkErr (Ivi_GetAttributeFlags (vi, IVI_ATTR_IO_RESOURCE_DESCRIPTOR, &oldFlag));
        checkErr (Ivi_SetAttributeFlags (vi, IVI_ATTR_IO_RESOURCE_DESCRIPTOR, oldFlag & 0xfffb | 0x0010));
        checkErr (Ivi_SetAttributeViString (vi, "", IVI_ATTR_IO_RESOURCE_DESCRIPTOR, 0, newResourceName));
    }
    /* init the driver */
    checkErr (ag3446x_IviInit (newResourceName, IDQuery, resetDevice, vi));
    if (isLogicalName)
        checkErr (Ivi_ApplyDefaultSetup (vi));
    *newVi = vi;

Error:
    if (error < VI_SUCCESS)
        Ivi_Dispose (vi);

    return error;
}

/*****************************************************************************
 * Function: ag3446x_close
 * Purpose:  This function closes the instrument.
 *
 *           Note:  This function must unlock the session before calling
 *           Ivi_Dispose.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_close (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    checkErr (ag3446x_IviClose (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    Ivi_Dispose (vi);

    return error;
}

/*****************************************************************************
 * Function: ag3446x_reset
 * Purpose:  This function resets the instrument.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_reset (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (!Ivi_Simulating (vi))               /* call only when locked */
    {
        ViSession io = Ivi_IOSession (vi);  /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr (viPrintf (io, "*RST"));
    }

    checkErr (ag3446x_DefaultInstrSetup (vi));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ResetWithDefaults
 * Purpose:  This function resets the instrument and applies default settings
 *           from the IVI Configuration Store based on the logical name
 *           from which the session was created.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ResetWithDefaults (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));
    checkErr (ag3446x_reset (vi));
    checkErr (Ivi_ApplyDefaultSetup (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/****************************************************************************
 *  Function: ag3446x_Disable
 *  Purpose:  This function places the instrument in a quiescent state as
 *            quickly as possible.
 ****************************************************************************/
ViStatus _VI_FUNC ag3446x_Disable (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (!Ivi_Simulating (vi))
    {
        /* Place appropriate code here to disable the instrument. */
    }
Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_self_test
 * Purpose:  This function executes the instrument self-test and returns the
 *           result.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_self_test (ViSession vi, ViInt16 *testResult,
                                     ViChar testMessage[])
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (testResult == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Test Result");
    if (testMessage == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Test Message");

    if (!Ivi_Simulating (vi))               /* call only when locked */
    {
        ViSession io = Ivi_IOSession (vi);  /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr (viQueryf (io, "*TST?;", "%hd", testResult));

        strcpy (testMessage, *testResult ? "Failed self-test." : "Passed self-test.");
    }
    else
    {
        /* Simulate Self Test */
        *testResult = 0;
        strcpy (testMessage, "No error.");
    }

    checkErr (Ivi_InvalidateAllAttributes (vi));    /* Invalidate all attributes */

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_revision_query
 * Purpose:  This function returns the driver and instrument revisions.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_revision_query (ViSession vi, ViChar driverRev[],
                                          ViChar instrRev[])
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (driverRev == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Driver Revision");
    if (instrRev == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Instrument Revision");

    checkErr (Ivi_GetAttributeViString (vi, "", AG3446X_ATTR_SPECIFIC_DRIVER_REVISION,
                                        0, 256, driverRev));
    checkErr (Ivi_GetAttributeViString (vi, "", AG3446X_ATTR_INSTRUMENT_FIRMWARE_REVISION,
                                        0, 256, instrRev));
    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_error_query
 * Purpose:  This function queries the instrument error queue and returns
 *           the result.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_error_query (ViSession vi, ViInt32 *errCode,
                                       ViChar errMessage[])
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (errCode == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Error Code");
    if (errMessage == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Error Message");

    if (!Ivi_Simulating (vi))               /* call only when locked */
    {
        ViSession io = Ivi_IOSession (vi);  /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr (viPrintf (io, ":SYST:ERR?"));

        viCheckErr (viScanf (io, "%ld,\"%256[^\"]", errCode, errMessage));
    }
    else
    {
        /* Simulate Error Query */
        *errCode = 0;
        strcpy (errMessage, "No error.");
    }

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_error_message
 * Purpose:  This function translates the error codes returned by this
 *           instrument driver into user-readable strings.
 *
 *           Note:  The caller can pass VI_NULL for the vi parameter.  This
 *           is useful if one of the init functions fail.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_error_message (ViSession vi, ViStatus errorCode,
                                         ViChar errorMessage[256])
{
    ViStatus                   error = VI_SUCCESS;

    static IviStringValueTable errorTable =
    {
        IVIDMM_ERROR_CODES_AND_MSGS,
        { VI_NULL,                  VI_NULL}
    };

    if (vi)
        Ivi_LockSession (vi, VI_NULL);

    /* all VISA and IVI error codes are handled as well as codes in the table */
    if (errorMessage == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Error Message");

    checkErr (Ivi_GetSpecificDriverStatusDesc (vi, errorCode, errorMessage, errorTable));

Error:
    if (vi)
        Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_InvalidateAllAttributes
 * Purpose:  This function invalidates the cached value of all attributes.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_InvalidateAllAttributes (ViSession vi)
{
    return Ivi_InvalidateAllAttributes (vi);
}

/*****************************************************************************
 * Function: ag3446x_GetError and ag3446x_ClearError Functions
 * Purpose:  These functions enable the instrument driver user to
 *           get or clear the error information the driver associates with the
 *           IVI session.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_GetError (ViSession vi,
                                    ViStatus *errorCode,
                                    ViInt32 bufferSize,
                                    ViChar description[])
{
    ViStatus  error              = VI_SUCCESS;
    ViStatus  primary            = VI_SUCCESS,
              secondary          = VI_SUCCESS;
    ViChar    elaboration[256]   = "";
    ViChar    errorMessage[1024] = "";
    ViChar    *appendPoint       = errorMessage;
    ViInt32   actualSize         = 0;
    ViBoolean locked             = VI_FALSE;

    /* Lock Session */
    if (vi != 0)
    {
        checkErr (Ivi_LockSession (vi, &locked));
    }

    /* Test for nulls and acquire error data */
    if (bufferSize != 0)
    {
        if (errorCode == VI_NULL)
        {
            viCheckParm (IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Error");
        }
        if (description == VI_NULL)
        {
            viCheckParm (IVI_ERROR_INVALID_PARAMETER, 4, "Null address for Description");
        }
        checkErr (Ivi_GetErrorInfo (vi, &primary, &secondary, elaboration));
    }

    else
    {
        checkErr (Ivi_GetAttributeViString (vi, VI_NULL, IVI_ATTR_ERROR_ELABORATION, 0, 256, elaboration));
        checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, IVI_ATTR_SECONDARY_ERROR, 0, &secondary));
        checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, IVI_ATTR_PRIMARY_ERROR, 0, &primary));
    }

    /* Format data */
    if (primary != VI_SUCCESS)
    {
        ViChar msg[256] = "";
        checkErr (ag3446x_error_message (vi, primary, msg));
        appendPoint += sprintf (appendPoint, "Primary Error: (Hex 0x%08X) %s\n", primary, msg);
    }

    if (secondary != VI_SUCCESS)
    {
        ViChar msg[256] = "";
        checkErr (ag3446x_error_message (vi, secondary, msg));
        appendPoint += sprintf (appendPoint, "Secondary Error: (Hex 0x%08X) %s\n", secondary, msg);
    }

    if (elaboration[0])
    {
        sprintf (appendPoint, "Elaboration: %s", elaboration);
    }

    actualSize = (ViInt32) (strlen (errorMessage) + 1);

    /* Prepare return values */
    if (bufferSize == 0)
    {
        error = actualSize;
    }
    else
    {
        if (bufferSize > 0)
        {
            if (actualSize > bufferSize)
            {
                error      = actualSize;
                actualSize = bufferSize;
            }
        }
        memcpy (description, errorMessage, actualSize - 1);
        description[actualSize - 1] = '\0';
    }

    if (errorCode)
    {
        *errorCode = primary;
    }

Error:
    /* Unlock Session */
    Ivi_UnlockSession (vi, &locked);
    return error;
}

ViStatus _VI_FUNC ag3446x_ClearError (ViSession vi)
{
    return Ivi_ClearErrorInfo (vi);
}

/*****************************************************************************
 * Function: ag3446x_GetNextCoercionRecord
 * Purpose:  This function enables the instrument driver user to obtain
 *           the coercion information associated with the IVI session.
 *           This function retrieves and clears the oldest instance in which
 *           the instrument driver coerced a value the instrument driver user
 *           specified to another value.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_GetNextCoercionRecord (ViSession vi,
                                                 ViInt32 bufferSize,
                                                 ViChar record[])
{
    return Ivi_GetNextCoercionString (vi, bufferSize, record);
}

/****************************************************************************
 *  Function: ag3446x_GetNextInterchangeWarning,
 *            ag3446x_ResetInterchangeCheck, and
 *            ag3446x_ClearInterchangeWarnings
 *  Purpose:  These functions allow the user to retrieve interchangeability
 *            warnings, reset the driver's interchangeability checking
 *            state, and clear all previously logged interchangeability warnings.
 ****************************************************************************/
ViStatus _VI_FUNC ag3446x_GetNextInterchangeWarning (ViSession vi,
                                                     ViInt32 bufferSize,
                                                     ViChar warnString[])
{
    return Ivi_GetNextInterchangeCheckString (vi, bufferSize, warnString);
}

ViStatus _VI_FUNC ag3446x_ResetInterchangeCheck (ViSession vi)
{
    return Ivi_ResetInterchangeCheck (vi);
}

ViStatus _VI_FUNC ag3446x_ClearInterchangeWarnings (ViSession vi)
{
    return Ivi_ClearInterchangeWarnings (vi);
}

/*****************************************************************************
 * Function: ag3446x_LockSession and ag3446x_UnlockSession Functions
 * Purpose:  These functions enable the instrument driver user to lock the
 *           session around a sequence of driver calls during which other
 *           execution threads must not disturb the instrument state.
 *
 *           NOTE:  The callerHasLock parameter must be a local variable
 *           initialized to VI_FALSE and passed by reference, or you can pass
 *           VI_NULL.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_LockSession (ViSession vi, ViBoolean *callerHasLock)
{
    return Ivi_LockSession (vi, callerHasLock);
}
ViStatus _VI_FUNC ag3446x_UnlockSession (ViSession vi, ViBoolean *callerHasLock)
{
    return Ivi_UnlockSession (vi, callerHasLock);
}

/*****************************************************************************
 * Function: ag3446x_ConfigureMeasurement
 * Purpose:  Configures the common attributes of the DMM.  These attributes
 *           are AG3446X_ATTR_FUNCTION,
 *               AG3446X_ATTR_RANGE, and
 *               AG3446X_ATTR_RESOLUTION_ABSOLUTE
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureMeasurement (ViSession vi, ViInt32 measFunction,
                                                ViReal64 range, ViReal64 resolution)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    /* Set attributes: */
    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION,
                                          0, measFunction), 2, "Measurement Function");
    viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE,
                                           0, range), 3, "Range");
	if (range != AG3446X_VAL_AUTO_RANGE_ON) 
	   viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RESOLUTION_ABSOLUTE,
                                               0, resolution), 4, "Resolution");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureSecondaryMeasurement
 * Purpose:   This function selects the secondary measurement function 
 *			  for the current measurement. 
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and the 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureSecondaryMeasurement (ViSession vi, ViInt32 secondaryFunction)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SECONDARY_FUNCTION,
                 0, secondaryFunction), 2, "secondary Function");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureACBandwidth
 * Purpose:  Configures additional attributes for AC Voltage or AC current
 *           measurements.  These attributes are
 *           AG3446X_ATTR_AC_MIN_FREQ and
 *           AG3446X_ATTR_AC_MAX_FREQ
 *           Note: This function not supported for EDU34450A.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureACBandwidth (ViSession vi, ViReal64 minFreq,
                                                ViReal64 maxFreq)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    /* Set attributes: */
    viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_AC_MIN_FREQ,
                                           0, minFreq), 2, "AC Min Frequency");
    viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_AC_MAX_FREQ,
                                           0, maxFreq), 3, "AC Max Frequency");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureFrequencyVoltageRange
 * Purpose:  Configures additional attributes for frequency or period
 *           measurements.  This attribute is
 *           AG3446X_ATTR_FREQ_VOLTAGE_RANGE
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureFrequencyVoltageRange (ViSession vi,
                                                          ViReal64 freqVoltageRange)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));


    viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_FREQ_VOLTAGE_RANGE,
                                           0, freqVoltageRange), 2, "Frequency Voltage Range");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureFrequencyTimeout
 * Purpose:   This function configures the frequency timeout of the DMM for 
 *			  frequency and period measurements.
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and the 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureFrequencyTimeout (ViSession vi, ViBoolean enableAutoTimeout)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED,
                 0, enableAutoTimeout), 2, "enable Auto Timeout");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureTransducerType
 * Purpose:  Configures the transducer type for temperature measurements.
 *           measurements. Sets the
 *           AG3446X_ATTR_TEMP_TRANSDUCER_TYPE attribute.
 * 			 Note: This function is not supported by EDU34450A.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureTransducerType (ViSession vi, ViInt32 transducerType)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    /* Set attributes: */
    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TEMP_TRANSDUCER_TYPE,
                                          0, transducerType), 2, "Transducer Type");
	
    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureRTD
 * Purpose:  Configures the attributes for RTD temperature measurements.
 *           These attributes are AG3446X_ATTR_TEMP_RTD_ALPHA and
 *           AG3446X_ATTR_TEMP_RTD_RES.
 * 			 Note(s):
 *				(1)The driver assumes that you are using a Platinum Resistance
 *           	   Temperature Device.
 *				(2)This function not supported for EDU34450A.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureRTD (ViSession vi, ViReal64 alpha,
                                        ViReal64 resistance)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    /* Set attributes: */
    viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_TEMP_RTD_ALPHA,
                                           0, alpha), 2, "Alpha");
    viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_TEMP_RTD_RES,
                                           0, resistance), 3, "Resistance");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureRTDAdvanced
 * Purpose:   This function configures the offset compensation and power limit 
 *			  for a resistance temperature device.
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureRTDAdvanced (ViSession vi, ViBoolean enablePowerLimit, 
												ViBoolean enableOffsetCompensation)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED,
                 0, enablePowerLimit), 2, "enable Power Limit");     
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED,
                 0, enableOffsetCompensation), 3, "enable Offset Compensation");
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}	

/*****************************************************************************
 * Function: ag3446x_ConfigureThermistor
 * Purpose:  Configures the AG3446X_ATTR_TEMP_THERMISTOR_RES
 *           attribute for thermistor temperature measurements.
 * Note:     The driver assumes that you are using an interchangeable
 *           thermistor. Interchangeable thermistors are thermistors that
 *           exhibit similar behavior for a given resistance value.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureThermistor (ViSession vi, ViReal64 resistance)

{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

	viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_TEMP_THERMISTOR_RES,
                                           0, resistance), 2, "Resistance");
	
    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureThermocouple
 * Purpose:   This function configures the thermocouple type and the reference 
 *			  junction type of the thermocouple for DMMs that take temperature 
 *			  measurements using a thermocouple transducer type.
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureThermocouple (ViSession vi, ViInt32 thermocoupleType, 
												 ViInt32 RefJunctionType)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TEMP_TC_TYPE,
                 0, thermocoupleType), 2, "thermocouple Type");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE,
                 0, RefJunctionType), 3, "Ref Junction Type");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureFixedRefJunction
 * Purpose:   This function configures the fixed reference junction for a 
 *			  thermocouple with a fixed reference junction
 *            type. 
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureFixedRefJunction (ViSession vi, ViReal64 fixedRefJunction)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC,
                 0, fixedRefJunction), 2, "fixed reference junction");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureThermocoupleCheckEnabled
 * Purpose:   This function disables or enables the thermocouple check feature 
 *			  to verify that your thermocouples are properly connected for 
 *			  measurements. 
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureThermocoupleCheckEnabled (ViSession vi, ViBoolean enableTcCheck)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_TEMP_TC_CHECK_ENABLED,
                 0, enableTcCheck), 2, "enable Tc Check");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureRefJunctionOffsetAdjustment
 * Purpose:   This function allows you to make minor temperature adjustments to 
 *			  correct for the differences between the DMM internal temperature 
 *			  measurement of the front connection and the actual temperature 
 *			  of the measurement terminals.
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureRefJunctionOffsetAdjustment (ViSession vi, ViReal64 adjustment)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ,
                 0, adjustment), 2, "adjustment");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}	

/*******************************************************************************
 * Function:  ag3446x_ConfigureThermistorPowerLimit
 * Purpose:   This function enables or disables low-power thermistor 
 *			  measurements (either 2- or 4-wire).
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureThermistorPowerLimit (ViSession vi, ViBoolean enablePowerLimit)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED,
                 0, enablePowerLimit), 2, "enable Power Limit");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureTrigger
 * Purpose:  Configures the common DMM trigger attributes.  These attributes
 *           are AG3446X_ATTR_TRIGGER_SOURCE and
 *               AG3446X_ATTR_TRIGGER_DELAY.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureTrigger (ViSession vi, ViInt32 triggerSource,
                                            ViReal64 triggerDelay)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    /* Set attributes: */
    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_SOURCE,
                                          0, triggerSource), 2, "Trigger Source");
    viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_DELAY,
                                           0, triggerDelay), 3, "Trigger Delay");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureMultiPoint
 * Purpose:  Configures the attributes for multi-point measurements.  These
 *           attributes are AG3446X_ATTR_TRIGGER_COUNT,
 *                          AG3446X_ATTR_SAMPLE_COUNT,
 *                          AG3446X_ATTR_SAMPLE_TRIGGER,
 *							AG3446X_ATTR_SAMPLE_INTERVAL
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureMultiPoint (ViSession vi, ViInt32 triggerCount,
                                               ViInt32 sampleCount, ViInt32 sampleTrigger,
                                               ViReal64 sampleInterval)
{
    ViStatus error = VI_SUCCESS;
	ViInt32	 model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr (Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_COUNT,
                                          0, triggerCount), 2, "Trigger Count");
    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT,
                                          0, sampleCount), 3, "Sample Count");
    if((sampleCount > 1) && (!IS_EDU34450A(model)))
    {
        viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_TRIGGER,
                                              0, sampleTrigger), 4, "Sample Trigger Source");
    }
	if (IS_34465A(model) || IS_34470A(model) || IS_EDU34450A(model))
	{
		viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_INTERVAL,
                                               0, sampleInterval), 5, "Sample Interval");		
	}

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigurePretrigger
 * Purpose:   This function configures the number of pretrigger samples.
 *            
 *            Notes:
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigurePretrigger (ViSession vi, ViInt32 preTriggerCount)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER,
                 0, preTriggerCount), 2, "pre Trigger Count");
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureMeasCompleteDest
 * Purpose:  Configures the AG3446X_ATTR_MEAS_COMPLETE_DEST
 *           attribute.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureMeasCompleteDest (ViSession vi, ViInt32 measCompleteDest)

{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MEAS_COMPLETE_DEST,
                                          0, measCompleteDest), 2, "Measurement Complete Destination");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureCalibrationSecurity
 * Purpose:   This function configures the calibration security.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureCalibrationSecurity (ViSession vi, ViChar securityCode[], ViBoolean enableSecurity)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_SECURITY_ENABLED,
                                            0, enableSecurity), 3, "Enable Security");

    if (enableSecurity == 0)
    {
        checkErr (viPrintf (vi, "CAL:SEC:CODE %s;", securityCode));
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_Calibrate
 * Purpose:   Performs a calibration using the calibration value based on the function and range.
 *
 *            Notes:
 *
 *            (1) A short must be applied for the resistance and voltage measurement functions, and
 *                the inputs must be open for the current measurement functions.
 *            (2) You must unsecure the instrument to calibrate it or to change the calibration
 *                string or security code.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_Calibrate (ViSession vi, ViReal64 calibrationValue, ViChar calibrationMessage[],
                                     ViBoolean enableCalibrationStore, ViBoolean *calibrationResult)
{
    ViStatus  error      = VI_SUCCESS;
    ViInt32   oldTimeout = 0;
    ViInt32   newTimeout = 5000;
    ViInt32   flag       = 0;
    ViChar    bitStr[SMALL_BUFFER_SIZE];
    ViSession io = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckErr (viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));
    viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, newTimeout));

    if (enableCalibrationStore)
    {
        viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_CAL_VALUE,
                                               0, calibrationValue), 2, "Calibration Value");
        viCheckParm (Ivi_SetAttributeViString (vi, VI_NULL, AG3446X_ATTR_CAL_STRING,
                                               0, calibrationMessage), 3, "Calibration Message");
    }

    viCheckErr (viQueryf (io, "CAL?", "%s", bitStr));

    StringToNumeric (bitStr, &flag);
    if (flag == 0)
        *calibrationResult = VI_TRUE;
    else
        *calibrationResult = VI_FALSE;

    viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_CalibrateADC
 * Purpose:   Performs a low-level calibration of the ADC (analog-to-digital converter) circuitry.
			  Note: This function not supported for EDU34450A. 
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_CalibrateADC (ViSession vi, ViBoolean *calibrationResult)
{
    ViStatus  error      = VI_SUCCESS;
    ViInt32   oldTimeout = 0;
    ViInt32   newTimeout = 5000;
    ViInt32   flag       = 0;
    ViSession io         = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckErr (viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));
    viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, newTimeout));

    viCheckErr (viQueryf (io, "CAL:ADC?", "%d", &flag));

    if (flag == 0)
        *calibrationResult = VI_TRUE;
    else
        *calibrationResult = VI_FALSE;

    viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureTriggerSlope
 * Purpose:  Configures the AG3446X_ATTR_TRIGGER_SLOPE
 *           attribute.
 *           Note: This function is not supported for EDU34450A.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureTriggerSlope (ViSession vi, ViInt32 polarity)

{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));


    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_SLOPE,
                                          0, polarity), 2, "Polarity");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureTriggerLevel
 * Purpose:   This function configures the level on which a trigger occurs 
 *			  when level triggering is enabled. 
 *            Notes: This function applies only to the 34465A, 34470A and
 *				  	 requires the DIG option.
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureTriggerLevel (ViSession vi, ViReal64 triggerLevel)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_LEVEL,
                 0, triggerLevel), 2, "trigger Level");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_ConfigureAutoZeroMode
 * Purpose:  Configures the auto zero capability of the DMM.
 *           Note: This function not supported for EDU34450A.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureAutoZeroMode (ViSession vi, ViInt32 autoZeroMode)

{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));


    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_AUTO_ZERO,
                                          0, autoZeroMode), 2, "Auto Zero Mode");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureVoltageImpedance
 * Purpose:   This function disables or enables automatic input impedance mode for DC voltage and ratio measurements.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureVoltageImpedance (ViSession vi, ViBoolean enableAutoImpedance)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));


    viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_VOLT_AUTO_IMPEDANCE,
                                            0, enableAutoImpedance), 2, "Enable Auto Impedance");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigureCurrentTeminals
 * Purpose:   This function configures the AC or DC current measurement to measure the source on the 3 A or 10 A terminals.
 * 			  Note: This function not supported for EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureCurrentTerminals (ViSession vi, ViInt32 terminalValue)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));


    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL,
                                          0, terminalValue), 2, "Terminal Value");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigureNullOperation
 * Purpose:   This function configures the null operation.
 *			  Note: This function not supported for EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureNullOperation (ViSession vi, ViBoolean enableNullFunction, ViReal64 nullValue,
                                                  ViBoolean enableAutoValue)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));


    viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_NULL_ENABLED,
                                            0, enableNullFunction), 2, "Enable Null Function");
    if (enableNullFunction)
    {
        viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_NULL_AUTO_ENABLED,
                                                0, enableAutoValue), 4, "Enable Auto Value");
        if (enableAutoValue == 0)
        {
            viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_NULL_VALUE,
                                                   0, nullValue), 3, "Null Value");
        }
    }


    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigureMeasurementTriggerParameters
 * Purpose:   This function configures measurement and trigger parameters to their default value.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureMeasurementTriggerParameters (ViSession vi, ViInt32 type)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CONF_MEAS,
                                          0, type), 2, "Type");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureSmoothing
 * Purpose:   This function configures the smoothing settings.
 *            
 *            Notes:
 *            
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureSmoothing (ViSession vi, ViInt32 numberOfMeasurements, 
											  ViBoolean enableSmoothing)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SMOOTHING_RESPONSE,
                 0, numberOfMeasurements), 2, "number Of Measurements");
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_SMOOTHING_ENABLED,
                 0, enableSmoothing), 3, "enable Smoothing");
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureTrendChartEnabled
 * Purpose:   This function enables or disables the trend chart data.
 *            
 *            Notes:
 *            
 *            (1) This function applies only to the 34461A, 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureTrendChartEnabled (ViSession vi, ViBoolean enableTrendChart)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_TREND_CHART_ENABLED,
                 0, enableTrendChart), 2, "enable Trend Chart");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureResistance
 * Purpose:   This function configures the measurement settings for both 2-wire 
 *			  resistance and 4-wire resistance measurement.
 *            Notes: (1) This function applies only to the 34465A, 34470A and EDU34450A. 
 *                   (2) AG3446X_ATTR_POWER_LIMIT_ENABLED not supported for EDU34450A.
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureResistance (ViSession vi, ViBoolean enablePowerLimit,
											   ViBoolean enableOffsetCompensation)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

    checkErr( Ivi_LockSession (vi, VI_NULL));
    checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model)); 
	
    if(!IS_EDU34450A(model))
		viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_POWER_LIMIT_ENABLED,
                 	 0, enablePowerLimit), 2, "enable power limit");  
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED,
                 0, enableOffsetCompensation), 3, "enable offset compensation");
                            
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureRangeChangeMode
 * Purpose:   Configures the range change mode for AC and DC current measurements.
 *            
 *            Notes:
 *            (1) This function only applies to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureRangeChangeMode (ViSession vi, ViInt32 rangeChangeMode)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_RANGE_CHANGE_MODE,
                 0, rangeChangeMode), 2, "range Change Mode");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}	

/*******************************************************************************
 * Function:  ag3446x_ConfigureScale
 * Purpose:   This function configures the scaling settings.
 *            Notes: This function applies only to ACV and DCV measurements.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureScale (ViSession vi, ViReal64 relativeValue, ViReal64 referenceResistance,
                                          ViInt32 scalingFunction, ViBoolean autoReference, ViBoolean enableScaling)
{
    ViStatus error = VI_SUCCESS;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;
	
    checkErr (Ivi_LockSession (vi, VI_NULL));
	
	if(!IS_EDU34450A(model))
		viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_SCALE_ENABLED,
	                                            0, enableScaling), 6, "Enable Scaling");
	
    if (IS_EDU34450A(model) || enableScaling)
    {
		if(!IS_EDU34450A(model)) 
			viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_SCALE_AUTO_REFERENCE,
                                                0, autoReference), 5, "Auto Reference");
        if (IS_EDU34450A(model) || autoReference == 0)
        {
            viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_SCALE_DB_REFERENCE,
                                                   0, relativeValue), 2, "Relative Value");
        }
        viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_SCALE_DBM_REFERENCE,
                                               0, referenceResistance), 3, "Reference Resistance");
        viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SCALE_FUNCTION,
                                              0, scalingFunction), 4, "Scaling Function");
	}
	
    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureScaleAdvanced
 * Purpose:   This function configures the scaling settings for 34465A and 34470A, 
 *			  including gain value, offset value and reference value.
 *            
 *            Notes:
 *            
 *            (1) This function applies only to ACV and DCV measurements.
 *            (2) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureScaleAdvanced (ViSession vi, ViReal64 gainValue, 
												  ViReal64 offsetValue, ViReal64 referenceValue)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_SCALE_GAIN,
                 0, gainValue), 2, "gain Value");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_SCALE_OFFSET,
                 0, offsetValue), 3, "offset Value");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_SCALE_REFERENCE,
                 0, referenceValue), 4, "reference Value");
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureScaleUnit
 * Purpose:   This function configures the scale unit settings.
 *            
 *            Notes:
 *            
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureScaleUnit (ViSession vi, ViBoolean enableScaleUnit, 
											  ViChar scaleUnit[])
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_SCALE_UNIT_ENABLED,
                 0, enableScaleUnit), 2, "enable Scale Unit");
    viCheckParm( Ivi_SetAttributeViString (vi, VI_NULL, AG3446X_ATTR_SCALE_UNIT,
                 0, scaleUnit), 3, "scale Unit");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}				

/*******************************************************************************
 * Function:  ag3446x_ConfigureAverage
 * Purpose:   This function enables or disables statistics computation.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureAverage (ViSession vi, ViBoolean enableAverage)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));
	
	viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_AVER_ENABLED,
                                            0, enableAverage), 2, "Enable Average");
	
    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigureLimit
 * Purpose:   This function configures the settings of limit test.
 *            Note: For EDU34450A first set the limit math function (CALC:FUNC LIM) 
 *					and turn on math operations (CALC:STAT ON) before setting a limit value. 
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureLimit (ViSession vi, ViReal64 lowerLimit, ViReal64 upperLimit,
                                          ViBoolean enableLimit)
{
    ViStatus error            = VI_SUCCESS;
    ViReal64 actualUpperLimit = 0.0;
	ViInt32  model 			  = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr (Ivi_LockSession (vi, VI_NULL));
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_LIMIT_ENABLED,
                                            0, enableLimit), 4, "Enable Limit");
    
	if (IS_EDU34450A(model) || enableLimit)
    {
        if (lowerLimit > upperLimit)
        {
            viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The lower limit should be less than upper limit");
        }

        checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, &actualUpperLimit));

        /* determine the sequence of setting lower and upper limit */
        if (lowerLimit > actualUpperLimit)
        {
            viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT,
                                                   0, upperLimit), 3, "Upper Limit");
            viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_LOWER_LIMIT,
                                                   0, lowerLimit), 2, "Lower Limit");
        }
        else
        {
            viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_LOWER_LIMIT,
                                                   0, lowerLimit), 2, "Lower Limit");
            viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT,
                                                   0, upperLimit), 3, "Upper Limit");
        }
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureHistogram
 * Purpose:   This function configures the histogram settings.
 *    		  Note: This function not supported by EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureHistogram (ViSession vi, ViReal64 lowerRange, ViReal64 upperRange,
                                              ViBoolean enableHistogram, ViBoolean autoHistogramRange, ViInt32 binCounts)
{
    ViStatus error            = VI_SUCCESS;
    ViReal64 actualUpperRange = 0.0;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_ENABLED,
                                            0, enableHistogram), 4, "Enable Histogram");
    if (enableHistogram)
    {
        viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE,
                                                0, autoHistogramRange), 5, "Auto Histogram Range");
        if (autoHistogramRange == 0)
        {
            if (lowerRange > upperRange)
            {
                viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The lower range should be less than upper range");
            }

            checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_HIST_UPPER_RANGE, 0, &actualUpperRange));

            /* determine the sequence of setting lower and upper range */
            if (lowerRange > actualUpperRange)
            {
                viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_HIST_UPPER_RANGE,
                                                       0, upperRange), 3, "Upper Range");
                viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_HIST_LOWER_RANGE,
                                                       0, lowerRange), 2, "Lower Range");
            }
            else
            {
                viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_HIST_LOWER_RANGE,
                                                       0, lowerRange), 2, "Lower Range");
                viCheckParm (Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_HIST_UPPER_RANGE,
                                                       0, upperRange), 3, "Upper Range");
            }
        }
        viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_HIST_POINT,
                                              0, binCounts), 6, "Bin Counts");
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureReadingMemory
 * Purpose:   This function sets the number of measurements to store in reading
 *            memory before setting bit 9 in the Standard Operation Register
 *            group event register to 1.
 * 			  Note: This function not supported in EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureReadingMemory (ViSession vi, ViInt32 measurementCounts)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));


    viCheckParm (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_DATA_POINT_COUNT,
                                          0, measurementCounts), 2, "Measurement Counts");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_QueryFileList
 * Purpose:   This function returns a list of files in the specified folder.
 *			  Note: This function not supported for EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_QueryFileList (ViSession vi, ViInt32* memoryUsed, ViInt32* memoryFree,
                                         ViChar fileListing[512])
{
    ViStatus  error = VI_SUCCESS;
    ViChar    memUsedStr[SMALL_BUFFER_SIZE];
    ViChar    memFreeStr[SMALL_BUFFER_SIZE];
    ViSession io = Ivi_IOSession (vi);  /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    io = Ivi_IOSession (vi);

    viCheckErr (viQueryf (io, "MMEM:CAT?", "%[^,],%[^,],%[^\n]", memUsedStr, memFreeStr, fileListing));
    *memoryUsed = atoi (memUsedStr);
    *memoryFree = atoi (memFreeStr);

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigureFile
 * Purpose:   This function configures the files copy, delete and move actions.
 *            Note: This function not supported for EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureFile (ViSession vi, ViInt32 operation, ViChar sourceFile[],
                                         ViChar destinationFile[])
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));


    if (operation == AG3446X_VAL_MEM_FILE_OPER_COPY)
    {
        viCheckErr (viPrintf (io, "MMEM:COPY \"%s\",\"%s\";", sourceFile, destinationFile));
    }
    else if (operation == AG3446X_VAL_MEM_FILE_OPER_MOVE)
    {
        viCheckErr (viPrintf (io, "MMEM:MOVE \"%s\",\"%s\";", sourceFile, destinationFile));
    }
    else
    {
        viCheckErr (viPrintf (io, "MMEM:DEL \"%s\";", sourceFile));
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigureDirectory
 * Purpose:   This function configures folder settings.
 *			  Note: This function not supported in EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureDirectory (ViSession vi, ViInt32 operation, ViChar folder[])
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (operation == AG3446X_VAL_MEM_DIR_OPER_SELECT)
    {
        viCheckErr (viPrintf (io, "MMEM:CDIR \"%s\";", folder));
    }
    else if (operation == AG3446X_VAL_MEM_DIR_OPER_MAKE)
    {
        viCheckErr (viPrintf (io, "MMEM:MDIR \"%s\";", folder));
    }
    else
    {
        viCheckErr (viPrintf (io, "MMEM:RDIR \"%s\";", folder));
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ValidateStateFile
 * Purpose:   This function checks whether the specified state file exists and contains a valid state file.
 * 			  Note: This function not supported for EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ValidateStateFile (ViSession vi, ViChar stateFile[], ViBoolean* isValid)
{
    ViStatus  error = VI_SUCCESS;
    ViInt32   flag  = 0;
    ViSession io    = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckErr (viQueryf (io, "MMEM:STAT:VAL? \"%s\";", "%d", stateFile, &flag));

    if (flag == 1)
        *isValid = VI_TRUE;
    else
        *isValid = VI_FALSE;

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureDataTransitionFormat
 * Purpose:   This function configures the data transition format.
 *            
 *            Notes:
 *            
 *            (1) This function applies only to the 34465A and 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureDataTransitionFormat (ViSession vi, ViInt32 separator, 
														 ViBoolean enableReadingInfo, 
                  										 ViBoolean enableRowLimit)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MEM_FORM_READING_SEPARATOR,
                 0, separator), 2, "separator");
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED,
                 0, enableReadingInfo), 3, "enable Reading Info");
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED,
                 0, enableRowLimit), 4, "enable Row Limit");                              
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}				


/*******************************************************************************
 * Function:  ag3446x_ConfigureDataTransition
 * Purpose:   This function transfers files into and out of the instrument's mass memory.
 			  Note: This function not supported in EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureDataTransition (ViSession vi, ViInt32 operation, ViChar fileName[],
                                                   ViChar binaryBlock[])
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (operation == AG3446X_VAL_MEM_DATA_OPER_DOWNLOAD)
    {
        viCheckErr (viPrintf (io, "MMEM:DOWN:FNAM \"%s\";", fileName));
        viCheckErr (viPrintf (io, "MMEM:DOWN:DATA %s;", binaryBlock));
    }
    else if (operation == AG3446X_VAL_MEM_DATA_OPER_STORE)
    {
        viCheckErr (viPrintf (io, "MMEM:STOR:DATA RDG_STORE, \"%s\";", fileName));
    }
    else
    {
        viCheckErr (viPrintf (io, "MMEM:UPL? \"%s\";", fileName));
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigureStateFile
 * Purpose:   This function save and load instrument states (state files).
 *			  Note: This function not supported in EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigureStateFile (ViSession vi, ViInt32 operation, ViChar fileName[],
                                              ViBoolean enableAutoRecall)
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (operation == AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD)
    {
        viCheckErr (viPrintf (io, "MMEM:LOAD:STAT \"%s\";", fileName));
    }
    else if (operation == AG3446X_VAL_MEM_STATE_FILE_OPER_STORE)
    {
        viCheckErr (viPrintf (io, "MMEM:STOR:STAT \"%s\";", fileName));
    }
    else
    {
        viCheckParm (Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_AUTO_RECALL_ENABLE,
                                                0, enableAutoRecall), 4, "Enable Auto Recall");
        if (enableAutoRecall == 0)
        {
            viCheckErr (viPrintf (io, "MMEM:STAT:REC:SEL \"%s\";", fileName));
        }
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ConfigurePreferenceFile
 * Purpose:   This function save and load preferred settings for nonvolatile parameters (preference files).
			  Note: This function not supported in EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ConfigurePreferenceFile (ViSession vi, ViInt32 operation, ViChar fileName[])
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi); /* call only when locked */

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (operation == AG3446X_VAL_MEM_PREF_FILE_OPER_LOAD)
    {
        viCheckErr (viPrintf (io, "MMEM:LOAD:PREF \"%s\";", fileName));
    }
    else
    {
        viCheckErr (viPrintf (io, "MMEM:STOR:PREF \"%s\";", fileName));
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_GetApertureTimeInfo
 * Purpose:  Returns additional information about the state of the instrument.
 *           Returns the value of the AG3446X_ATTR_APERTURE_TIME and
 *           AG3446X_ATTR_APERTURE_TIME_UNITS attributes.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_GetApertureTimeInfo (ViSession vi, ViReal64 *apertureTime,
                                               ViInt32 *apertureTimeUnits)
{
    ViStatus error = VI_SUCCESS;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;

    checkErr (Ivi_LockSession (vi, VI_NULL));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
    /* Get attributes: */
    viCheckParm (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_APERTURE_TIME,
                                           0, apertureTime), 3, "Aperture Time");
	if(!IS_EDU34450A(model))	  
    	viCheckParm (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_APERTURE_TIME_UNITS,
                                          	  0, apertureTimeUnits), 2, "Aperture Time Units");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ConfigureApertureTime
 * Purpose:   This function configures additional information about the state 
 *			  of the instrument. Specifically, it configures the aperture time 
 *			  and whether the aperture is enabled or not.
 *            Note: AG3446X_ATTR_APERTURE_TIME_UNITS not supported for EDU34450A.
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ConfigureApertureTime (ViSession vi, ViInt32 apertureTimeUnit,
											     ViReal64 apertureTime)
{
    ViStatus    error = VI_SUCCESS;			    
	ViInt32     model = AG3446X_VAL_MODEL_UNKNOWN;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
    
	if(!IS_EDU34450A(model))
	{
		viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_APERTURE_TIME_UNITS,
	                 0, apertureTimeUnit), 2, "aperture time unit");   
    }
	viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_APERTURE_TIME,
                 0, apertureTime), 3, "aperture Time");  
											  
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_GetAutoRangeValue
 * Purpose:  Returns the actual range the DMM is currently using.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_GetAutoRangeValue (ViSession vi, ViReal64 *autoRangeValue)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    /* Get attributes: */
    viCheckParm (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_AUTO_RANGE_VALUE,
                                           0, autoRangeValue), 3, "Auto Range Value");

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_Read
 * Purpose:  Initiates a measurement and fetches the result.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_Read (ViSession vi, ViInt32 maxTime, ViReal64 *reading)
{
    ViStatus error     = VI_SUCCESS;
    ViStatus overRange = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    IviDmm_InterchangeCheck (vi, "ag3446x_Read");

    if (reading == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Reading");

    checkErr (ag3446x_Initiate (vi));

    error = ag3446x_WaitForOPC (vi, maxTime);

    if (VI_ERROR_TMO == error)
        viCheckErr (AG3446X_ERROR_MAX_TIME_EXCEEDED);

    checkWarn (overRange = ag3446x_Fetch (vi, maxTime, reading));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    if (error < VI_SUCCESS)
        return error;
    else
        return overRange;
}

/*****************************************************************************
 * Function: ag3446x_ReadMultiPoint
 * Purpose:  This reads multiple points from the instrument.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_ReadMultiPoint (ViSession vi, ViInt32 maxTime,
                                          ViInt32 arraySize, ViReal64 readingArray[],
                                          ViInt32 *actualPts)
{
    ViStatus  error      = VI_SUCCESS;
    ViStatus  overRange  = VI_SUCCESS;
    ViSession io         = VI_NULL;
    ViUInt32  oldTimeout = 0;       /* Initialize to zero */
    ViInt32   sampleCount, triggerCount, total;
    ViBoolean needToRestoreTimeout = VI_FALSE;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

    checkErr (Ivi_LockSession (vi, VI_NULL));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
    IviDmm_InterchangeCheck (vi, "ag3446x_ReadMultiPoint");

    if (readingArray == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 4, "Null address for Reading Array");
    if (actualPts == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 5,
                     "Null address for Actual Number of Points");

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_COUNT, 0,
                                       &triggerCount));
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT, 0,
                                       &sampleCount));

    total = triggerCount * sampleCount;

    if ((sampleCount * triggerCount) > 1000000)
        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Insufficient memory.");

    if (!Ivi_Simulating (vi))                /* call only when locked */
    {
        ViInt32 i;

        io = Ivi_IOSession (vi); /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        /* Store the old timeout so that it can be restored later */
        viCheckErr (viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));
        viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, maxTime));
        needToRestoreTimeout = VI_TRUE;

        *actualPts = arraySize;
        error      = viQueryf (io, ":READ?;", "%,#Lf", actualPts, readingArray);

        if (*actualPts > arraySize)
            *actualPts = arraySize;

        if (error == VI_ERROR_TMO)
            error = AG3446X_ERROR_MAX_TIME_EXCEEDED;
        viCheckErr (error);

        /* Check for over range */
        for (i = 0; i < *actualPts; i++)
        {
            if ((-9.9E37 >= readingArray[i]) || (readingArray[i] >= 9.9E37))
            {
                readingArray[i] = IVI_VAL_NAN;
                overRange       = VI_TRUE;
            }
        }
    }
    else
    {   /* Simulate measurement data */
        ViInt32  i, measFunc;
        ViReal64 range = 0;

        *actualPts = sampleCount * triggerCount;

        if (*actualPts > arraySize)
            *actualPts = arraySize;

        if (range <= 0.0)       /* If auto-ranging, use the max value. */
        {
            checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0,
                                               &measFunc));

            switch (measFunc)
            {
            case AG3446X_VAL_DC_CURRENT:
            case AG3446X_VAL_AC_CURRENT:
                range = 3.0;            /* 3.0 amps */
                break;

            case AG3446X_VAL_DC_VOLTS:
            case AG3446X_VAL_DC_VOLTS_RATIO:
                range = 1000.0;         /* 1000.0 volts */
                break;

			case AG3446X_VAL_AC_VOLTS:
				 if(IS_EDU34450A(model))
					 range = 750.0;
				 else
					 range = 1000.0;
            case AG3446X_VAL_2_WIRE_RES:
            case AG3446X_VAL_4_WIRE_RES:
                range = 1.0E8;          /* 1.0E8 ohms */
                break;

            case AG3446X_VAL_FREQ:
                range = 3.0E5;          /* 300 kHz */
                break;

            case AG3446X_VAL_PERIOD:
                range = 333.33E-3;      /* 333.33 ms */
                break;

            case AG3446X_VAL_TEMPERATURE:
                range = 85.0;           /* 85.0 celsius */
                break;

            case AG3446X_VAL_DIODE:
                range = 1.0;            /* 1.0 volts */
                break;

            case AG3446X_VAL_CONTINUITY:
                range = 1000.0;         /* 1000.0 ohms */
                break;
            }
        }

        for (i = 0; i < arraySize; i++)
            readingArray[i] = range * (rand () / RAND_MAX);
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    if (needToRestoreTimeout)
    {
        /* Restore the original timeout */
        viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout);
    }
    Ivi_UnlockSession (vi, VI_NULL);
    if (error < VI_SUCCESS)
        return error;
    else
        return overRange;
}

/*******************************************************************************
 * Function:  ag3446x_ReadHistogramMeasurement
 * Purpose:   This function returns the histogram measurement result.
 *            Note: This function is not supported for EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ReadHistogramMeasurement (ViSession vi, ViChar readings[1024])
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    checkErr (ag3446x_FetchHistogramMeasurement (vi, readings));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ReadStatisticsMeasurement
 * Purpose:   This function returns a specified statistics measurement.
 * 			  Note:(1) Must set "EnableAverage" control to true in
 *                 	   ag3446x_ConfigureAverage function.
 *            	   (2) For EDU34450A model, must run ag3446x_ConfigureAverage to 
 *					   set calculation function to average.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ReadStatisticsMeasurement (ViSession vi, ViReal64* standardDeviationValue, ViReal64* averageValue,
                                                     ViReal64* countValue, ViReal64* maximumValue, ViReal64* minimumValue,
                                                     ViReal64* peakToPeakValue)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    checkErr (ag3446x_FetchStatisticsMeasurement (vi, standardDeviationValue, averageValue,
                                                  countValue, maximumValue, minimumValue, peakToPeakValue));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_FetchStatisticsMeasurement
 * Purpose:   This function returns a specified statistics measurement.
 * 			  Note:(1) You must set "EnableAverage" control to true in
 *                 	   ag3446x_ConfigureAverage function.
 *            	   (2) For EDU34450A model, must run ag3446x_ConfigureAverage to 
 *					   set calculation function to average.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_FetchStatisticsMeasurement (ViSession vi, ViReal64* standardDeviationValue, ViReal64* averageValue,
                                                      ViReal64* countValue, ViReal64* maximumValue, ViReal64* minimumValue,
                                                      ViReal64* peakToPeakValue)
{
    ViStatus  error = VI_SUCCESS;
    ViBoolean mathEnable;
	ViInt32   model = AG3446X_VAL_MODEL_UNKNOWN;
	
    checkErr (Ivi_LockSession (vi, VI_NULL));
	
	checkErr (Ivi_GetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_AVER_ENABLED, 0, &mathEnable));

	if (!mathEnable)
		viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Cannot get correct statistics value when statistics is disabled.");
	
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession (vi);

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

		viCheckErr (viQueryf (io, "CALC:AVER:AVER?", "%lf", averageValue));
        viCheckErr (viQueryf (io, "CALC:AVER:COUN?", "%lf", countValue));
        viCheckErr (viQueryf (io, "CALC:AVER:MAX?", "%lf", maximumValue));
        viCheckErr (viQueryf (io, "CALC:AVER:MIN?", "%lf", minimumValue));
		
		if(!IS_EDU34450A(model))
	    {	   
			viCheckErr (viQueryf (io, "CALC:AVER:SDEV?", "%lf", standardDeviationValue));
			viCheckErr (viQueryf (io, "CALC:AVER:PTP?", "%lf", peakToPeakValue)); 
	    }
		else
		{
			standardDeviationValue = 0;
			peakToPeakValue = 0;
		}
	}
    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_FetchHistogramMeasurement
 * Purpose:   This function returns the histogram measurement result (bin data).
 * 			  Note: This function is not supported by EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_FetchHistogramMeasurement (ViSession vi, ViChar readings[1024])
{
    ViStatus  error = VI_SUCCESS;
    ViBoolean histEnable;
    ViInt32   oldrdBufSize = 0;
    ViInt32   newrdBufSize = 60000;
    ViSession io           = Ivi_IOSession (vi);

    checkErr (Ivi_LockSession (vi, VI_NULL));

    checkErr (viGetAttribute (io, VI_ATTR_RD_BUF_SIZE, &oldrdBufSize));
    checkErr (viSetBuf (io, VI_READ_BUF, newrdBufSize));

    checkErr (Ivi_GetAttributeViBoolean (vi, VI_NULL,
                                         AG3446X_ATTR_HIST_ENABLED, 0, &histEnable));

    if (!histEnable)
        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION,
                        "Cannot get correct histogram value when histogram computation is disabled.");

    if (!Ivi_Simulating (vi))
    {
        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        viCheckErr (viQueryf (io, "CALC:TRAN:HIST:DATA?", "%s", readings));
    }

    checkErr (viSetBuf (io, VI_READ_BUF, oldrdBufSize));
    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_Initiate
 * Purpose:  Initiate a measurement.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_Initiate (ViSession vi)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  triggerCount, sampleCount;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    IviDmm_InterchangeCheck (vi, "ag3446x_Initiate");

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT, 0,
                                       &sampleCount));
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_COUNT, 0,
                                       &triggerCount));

    if ((sampleCount * triggerCount) > 1000000)
        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION,
                        "Insufficient memory.");

    if (!Ivi_Simulating (vi))               /* call only when locked */
    {
        ViSession io = Ivi_IOSession (vi);  /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        viCheckErr (viWrite (io, "INIT;", 5, VI_NULL));
    }

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_Abort
 * Purpose:  Aborts a measurement.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_Abort (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (!Ivi_Simulating (vi))                /* call only when locked */
    {
        ViSession io = Ivi_IOSession (vi);   /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        viCheckErr (viClear (io));
    }

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_SendSoftwareTrigger
 * Purpose:  Sends a command to trigger the instrument.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_SendSoftwareTrigger (ViSession vi)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  triggerSource;
    ViInt32  sampleTrigger;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_SOURCE,
                                       0, &triggerSource));
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_TRIGGER,
                                       0, &sampleTrigger));

    if ((triggerSource != AG3446X_VAL_SOFTWARE_TRIG) &&
        (sampleTrigger != AG3446X_VAL_SOFTWARE_TRIG))
        viCheckErr (AG3446X_ERROR_TRIGGER_NOT_SOFTWARE);

    if (!Ivi_Simulating (vi))               /* call only when locked */
    {
        ViSession io = Ivi_IOSession (vi);  /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        viCheckErr (viWrite (io, "*TRG;", 5, VI_NULL));
    }

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: ag3446x_Fetch
 * Purpose:  This function returns the measured value from a previously
 *           initiated measurement.  This function does not trigger the
 *           instrument.
 *
 *           After this function executes, the value in *readingRef
 *           is an actual reading or a value indicating that an over-range
 *           condition occurred.  If an over-range condition occurs, the
 *           function sets *readingRef to IVI_VAL_NAN and returns
 *           AG3446X_WARN_OVER_RANGE.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_Fetch (ViSession vi, ViInt32 maxTime, ViReal64 *readingRef)
{
    ViStatus  error                = VI_SUCCESS;
    ViBoolean overRange            = VI_FALSE;
    ViSession io                   = VI_NULL;
    ViUInt32  oldTimeout           = 0;
    ViBoolean needToRestoreTimeout = VI_FALSE;
	ViInt32   model = AG3446X_VAL_MODEL_UNKNOWN;
	
    checkErr (Ivi_LockSession (vi, VI_NULL));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
    if (readingRef == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Reading");

    if (!Ivi_Simulating (vi))    /* call only when locked */
    {
        ViInt32 actualPts;
        ViInt32 size;
        ViChar  format[EXTENDED_BUFFER_SIZE];

        io = Ivi_IOSession (vi);    /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        /* Store the old timeout so that it can be restored later */
        viCheckErr (viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));
        viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, maxTime));
        needToRestoreTimeout = VI_TRUE;

        /* assumes there is at least one value in the instrument's memory to read */
		if(IS_EDU34450A(model))
        	viCheckErr (viQueryf (io, "DATA:POIN? NVMEM", "%d", &actualPts));
		else
			viCheckErr (viQueryf (io, "DATA:POIN?", "%d", &actualPts));

        size = actualPts - 1;
        if (size > 0)
        {
            viCheckErr (viSPrintf (io, format, "%%*,%dlf,%%lf", size));
            error = viQueryf (io, ":FETC?;", format, readingRef);
        }
        else
        {
            error = viQueryf (io, "FETC?", "%lf", readingRef);
        }

        if (error == VI_ERROR_TMO)
            error = AG3446X_ERROR_MAX_TIME_EXCEEDED;
        viCheckErr (error);

        /* Test for over range */
        if ((*readingRef >= 9.9E+37) || (*readingRef <= -9.9E+37))
        {
            *readingRef = IVI_VAL_NAN;
            overRange   = VI_TRUE;
        }
    }
    else
    {       /* Simulate measurement data */
        ViReal64 range;
        ViInt32  measFunc;

        checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE,
                                            0, &range));

        if (range <= 0.0)       /* If auto-ranging, use the max value. */
        {
            checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0,
                                               &measFunc));
            switch (measFunc)
            {
            case AG3446X_VAL_DC_CURRENT:
            case AG3446X_VAL_AC_CURRENT:
                range = 3.0;            /* 3.0 amps */
                break;

            case AG3446X_VAL_DC_VOLTS:
            case AG3446X_VAL_DC_VOLTS_RATIO:
                range = 1000.0;         /* 1000.0 volts */
                break;
			 case AG3446X_VAL_AC_VOLTS:
                 if(IS_EDU34450A(model))
				 	range = 750.0;         /* 750.0 volts */
				 else
				 	range = 1000.0;         /* 1000.0 volts */ 	 
				break;
            case AG3446X_VAL_2_WIRE_RES:
            case AG3446X_VAL_4_WIRE_RES:
                range = 1.0E8;          /* 1.0E8 ohms */
                break;

            case AG3446X_VAL_FREQ:
                range = 3.0E5;          /* 300 kHz */
                break;

            case AG3446X_VAL_PERIOD:
                range = 333.33E-3;      /* 333.33 ms */
                break;

            case AG3446X_VAL_TEMPERATURE:
                range = 85.0;           /* 85.0 celsius */
                break;

            case AG3446X_VAL_DIODE:
                range = 1.0;            /* 1.0 volts */
                break;

            case AG3446X_VAL_CONTINUITY:
                range = 1000.0;         /* 1000.0 ohms */
                break;
            }
        }

        *readingRef = range * ((ViReal64) rand () / (ViReal64) RAND_MAX);
    }

    /*
     *  Do not invoke ag3446x_CheckStatus here.
     *  ag3446x_Read invokes ag3446x_CheckStatus after it calls
     *  this function.  After the user calls this function, the
     *  user can check for errors by calling ag3446x_error_query.
     */

Error:
    if (needToRestoreTimeout)
    {
        /* Restore the original timeout */
        viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout);
    }

    Ivi_UnlockSession (vi, VI_NULL);

    if (overRange && (error >= VI_SUCCESS))
        return AG3446X_WARN_OVER_RANGE;
    else
        return error;
}


/*****************************************************************************
 * Function: ag3446x_FetchMultiPoint
 * Purpose:  Fetches multiple readings from a previously triggered measurement.
 *           The number of measurements the DMM will take is determined by
 *           the values of the triggerCount and sampleCount
 *           parameters to ag3446x_ConfigureMultiPoint.
 *           This function does not trigger the instrument.
 *
 *           After this function executes, each value in readingArray
 *           is an actual reading or a value indicating that an over-range
 *           condition occurred.  If an over-range condition occurs, the
 *           function sets the corresponding value in readingArray to
 *           IVI_VAL_NAN and returns AG3446X_WARN_OVER_RANGE.
 *****************************************************************************/
ViStatus _VI_FUNC   ag3446x_FetchMultiPoint (ViSession vi, ViInt32 maxTime,
                                             ViInt32 arraySize, ViReal64 readingArray[],
                                             ViInt32 *actualPts)
{
    ViStatus  error      = VI_SUCCESS;
    ViBoolean overRange  = VI_FALSE;
    ViSession io         = VI_NULL;
    ViUInt32  oldTimeout = 0;       /* Initialize to zero */
    ViInt32   sampleCount, triggerCount, total;
    ViBoolean needToRestoreTimeout = VI_FALSE;
	ViInt32   model      = AG3446X_VAL_MODEL_UNKNOWN;

    checkErr (Ivi_LockSession (vi, VI_NULL));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model)); 
	
    if (readingArray == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 4, "Null address for Reading Array");
    if (actualPts == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 5,
                     "Null address for Actual Number of Points");

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TRIGGER_COUNT, 0,
                                       &triggerCount));
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT, 0,
                                       &sampleCount));

    total = triggerCount * sampleCount;

    if ((sampleCount * triggerCount) > 1000000)
        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Insufficient memory.");

    if (!Ivi_Simulating (vi))                /* call only when locked */
    {
        ViInt32 i;

        io = Ivi_IOSession (vi);    /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        /* Store the old timeout so that it can be restored later */
        viCheckErr (viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));
        viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, maxTime));
        needToRestoreTimeout = VI_TRUE;

        *actualPts = arraySize;
        error      = viQueryf (io, ":FETC?;", "%,#Lf", actualPts, readingArray);

        if (*actualPts > arraySize)
            *actualPts = arraySize;

        if (error == VI_ERROR_TMO)
            error = AG3446X_ERROR_MAX_TIME_EXCEEDED;
        viCheckErr (error);

        /* Check for overrange */
        for (i = 0; i < *actualPts; i++)
        {
            if ((-9.9E37 >= readingArray[i]) || (readingArray[i] >= 9.9E37))
            {
                readingArray[i] = IVI_VAL_NAN;
                overRange       = VI_TRUE;
            }
        }
    }
    else
    {       /* Simulate measurement data */
        ViInt32  i, measFunc;
        ViReal64 range = 0;

        *actualPts = sampleCount * triggerCount;

        if (*actualPts > arraySize)
            *actualPts = arraySize;

        if (range <= 0.0)           /* If auto-ranging, use the max value. */
        {
            checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0,
                                               &measFunc));

            switch (measFunc)
            {
            case AG3446X_VAL_DC_CURRENT:
            case AG3446X_VAL_AC_CURRENT:
                range = 3.0;                /* 3.0 amps */
                break;

            case AG3446X_VAL_DC_VOLTS:
            case AG3446X_VAL_DC_VOLTS_RATIO:
                range = 1000.0;             /* 1000.0 volts */
                break;
				
	    	case AG3446X_VAL_AC_VOLTS:
                 if(IS_EDU34450A(model))
				 range = 750.0;         /* 750.0 volts */
				 else
				 range = 1000.0;         /* 1000.0 volts */ 	 
				break;

            case AG3446X_VAL_2_WIRE_RES:
            case AG3446X_VAL_4_WIRE_RES:
                range = 1.0E8;              /* 1.0E8 ohms */
                break;

            case AG3446X_VAL_FREQ:
                range = 3.0E5;              /* 300 kHz */
                break;

            case AG3446X_VAL_PERIOD:
                range = 333.33E-3;          /* 333.33 ms */
                break;

            case AG3446X_VAL_TEMPERATURE:
                range = 85.0;               /* 85.0 celsius */
                break;

            case AG3446X_VAL_DIODE:
                range = 1.0;                /* 1.0 volts */
                break;

            case AG3446X_VAL_CONTINUITY:
                range = 1000.0;             /* 1000.0 ohms */
                break;
            }
        }

        for (i = 0; i < arraySize; i++)
            readingArray[i] = range * (rand () / RAND_MAX);
    }

    /*
     *  Do not invoke ag3446x_CheckStatus here.
     *  ag3446x_ReadMultiPoint invokes ag3446x_CheckStatus after it
     *  calls this function.  After the user calls this function, the
     *  user can check for errors by calling ag3446x_error_query.
     */

Error:
    if (needToRestoreTimeout)
    {
        /* Restore the original timeout */
        viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout);
    }

    Ivi_UnlockSession (vi, VI_NULL);

    if (overRange && (error >= VI_SUCCESS))
        return AG3446X_WARN_OVER_RANGE;
    else
        return error;
}

/*****************************************************************************
 * Function: ag3446x_IsOverRange
 * Purpose:  This function takes a measurement value that you obtain from one
 *           of the Measure, Read, or Fetch functions and determines if the
 *           value is a valid measurement value or a value indicating an
 *           over-range condition occurred.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_IsOverRange (ViSession vi, ViReal64 measurementValue,
                                       ViBoolean *isOverRange)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  type;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (isOverRange == VI_NULL)
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for OverRange status.");

    viCheckErr (Ivi_GetViReal64Type (measurementValue, &type));

    if (type == IVI_VAL_TYPE_NAN)
        *isOverRange = VI_TRUE;
    else
        *isOverRange = VI_FALSE;

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*===========================================================================*
 *= IviDmm Data Group Functions =============================*
 *===========================================================================*/


/*******************************************************************************
 * Function:  ag3446x_ReadMeasurementMemory
 * Purpose:   This function reads the measurement memory.
 *			  Note: This function not supported for EDU34450A.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ReadMeasurementMemory (ViSession vi, ViInt32 readCount, ViBoolean enableWait,
                                                 ViReal64 result[])
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi);
    ViChar    rdBuf[EXTENDED_BUFFER_SIZE];
    ViInt32   oldrdBufSize = 0;
    ViInt32   newrdBufSize = 60000;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    checkErr (viGetAttribute (io, VI_ATTR_RD_BUF_SIZE, &oldrdBufSize));
    checkErr (viSetBuf (io, VI_READ_BUF, newrdBufSize));

    if (enableWait)
    {
        viCheckErr (viQueryf (io, "DATA:REM? %ld,WAIT;", "%s", readCount, rdBuf));
    }
    else
    {
        viCheckErr (viQueryf (io, "DATA:REM? %ld;", "%s", readCount, rdBuf));
    }

    StringToReal64Array (rdBuf, readCount, result, ',');

    checkErr (viSetBuf (io, VI_READ_BUF, oldrdBufSize));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ReadLastMeasument
 * Purpose:   Returns the last measurement taken.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ReadLastMeasurement (ViSession vi, ViReal64* lastResult)
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi);

    checkErr (Ivi_LockSession (vi, VI_NULL));

    viCheckErr (viQueryf (io, "DATA:LAST?", "%lf", lastResult));

    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*******************************************************************************
 * Function:  ag3446x_ReadMeasurementCount
 * Purpose:   Returns the total number of measurements currently in reading memory.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ReadMeasurementCount (ViSession vi, ViInt32* dataPoints)
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi);
	ViInt32   model = AG3446X_VAL_MODEL_UNKNOWN;

    checkErr (Ivi_LockSession (vi, VI_NULL));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
    	viCheckErr (viQueryf (io, "DATA:POIN? NVMEM", "%ld", dataPoints));	
	else
		viCheckErr (viQueryf (io, "DATA:POIN?", "%ld", dataPoints));
    
	checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ReadSecondaryMeasurement
 * Purpose:   This function initiates a measurement, waits until the DMM has 
 *			  returned to the idle state, and returns the secondary measured value.
 *
 *			  Notes:
 *            (1) This function applies only to the 34465A and the 34470A. 
*******************************************************************************/			
ViStatus _VI_FUNC ag3446x_ReadSecondaryMeasurement (ViSession vi,  ViInt32 numberOfReadings, ViReal64 reading[3])
{
    ViStatus    error = VI_SUCCESS;
    ViSession 	io = VI_NULL;
	ViChar		buffer[BUFFER_SIZE] = "";
	ViInt32		i = 0;
	ViPBuf		p = VI_NULL;
	
    checkErr( Ivi_LockSession (vi, VI_NULL));
	
	io = Ivi_IOSession (vi);
    viCheckErr (viQueryf (io, "DATA2?", "%s", buffer)); 
	
	p = strtok(buffer, ","); 
	while (p && i < numberOfReadings)
	{
		checkErr( viSScanf(io, p, "%lf", &reading[i++]));
		
		p = strtok(NULL, ",");
	}
	
	for (i; i < numberOfReadings; ++i)
	{
		reading[i] = 9.90000000E+37;
	}
                 
    checkErr( ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}


/*****************************************************************************
 * Function: ag3446x_GetAttribute<type> Functions
 * Purpose:  These functions enable the instrument driver user to get
 *           attribute values directly.  There are typesafe versions for
 *           ViInt32, ViInt64, ViReal64, ViString, ViBoolean, and ViSession
 *           attributes.
 *****************************************************************************/

ViStatus _VI_FUNC ag3446x_GetAttributeViInt32 (ViSession vi, ViConstString channelName,
                                               ViAttr attributeId, ViInt32 *value)
{
    return Ivi_GetAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                    value);
}
ViStatus _VI_FUNC ag3446x_GetAttributeViReal64 (ViSession vi, ViConstString channelName,
                                                ViAttr attributeId, ViReal64 *value)
{
    return Ivi_GetAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     value);
}
ViStatus _VI_FUNC ag3446x_GetAttributeViString (ViSession vi, ViConstString channelName,
                                                ViAttr attributeId, ViInt32 bufSize,
                                                ViChar value[])
{
    return Ivi_GetAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     bufSize, value);
}
ViStatus _VI_FUNC ag3446x_GetAttributeViBoolean (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViBoolean *value)
{
    return Ivi_GetAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}
ViStatus _VI_FUNC ag3446x_GetAttributeViSession (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViSession *value)
{
    return Ivi_GetAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}

/*****************************************************************************
 * Function: ag3446x_SetAttribute<type> Functions
 * Purpose:  These functions enable the instrument driver user to set
 *           attribute values directly.  There are typesafe versions for
 *           ViInt32, ViInt64, ViReal64, ViString, ViBoolean, and ViSession
 *           datatypes.
 *****************************************************************************/

ViStatus _VI_FUNC ag3446x_SetAttributeViInt32 (ViSession vi, ViConstString channelName,
                                               ViAttr attributeId, ViInt32 value)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                    value);
}
ViStatus _VI_FUNC ag3446x_SetAttributeViReal64 (ViSession vi, ViConstString channelName,
                                                ViAttr attributeId, ViReal64 value)
{
    return Ivi_SetAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     value);
}
ViStatus _VI_FUNC ag3446x_SetAttributeViString (ViSession vi, ViConstString channelName,
                                                ViAttr attributeId, ViConstString value)
{
    return Ivi_SetAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     value);
}
ViStatus _VI_FUNC ag3446x_SetAttributeViBoolean (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViBoolean value)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}
ViStatus _VI_FUNC ag3446x_SetAttributeViSession (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViSession value)
{
    return Ivi_SetAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}

/*****************************************************************************
 * Function: ag3446x_CheckAttribute<type> Functions
 * Purpose:  These functions enable the instrument driver user to check
 *           attribute values directly.  These functions check the value you
 *           specify even if you set the AG3446X_ATTR_RANGE_CHECK
 *           attribute to VI_FALSE.  There are typesafe versions for ViInt32,
 *           ViInt64, ViReal64, ViString, ViBoolean, and ViSession datatypes.
 *****************************************************************************/


ViStatus _VI_FUNC ag3446x_CheckAttributeViInt32 (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViInt32 value)
{
    return Ivi_CheckAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}
ViStatus _VI_FUNC ag3446x_CheckAttributeViReal64 (ViSession vi, ViConstString channelName,
                                                  ViAttr attributeId, ViReal64 value)
{
    return Ivi_CheckAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                       value);
}
ViStatus _VI_FUNC ag3446x_CheckAttributeViString (ViSession vi, ViConstString channelName,
                                                  ViAttr attributeId, ViConstString value)
{
    return Ivi_CheckAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                       value);
}
ViStatus _VI_FUNC ag3446x_CheckAttributeViBoolean (ViSession vi, ViConstString channelName,
                                                   ViAttr attributeId, ViBoolean value)
{
    return Ivi_CheckAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                        value);
}
ViStatus _VI_FUNC ag3446x_CheckAttributeViSession (ViSession vi, ViConstString channelName,
                                                   ViAttr attributeId, ViSession value)
{
    return Ivi_CheckAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                        value);
}

/*****************************************************************************
 * Function: viWrite and viRead Functions
 * Purpose:  These functions enable the instrument driver user to
 *           write and read commands directly to and from the instrument.
 *
 *           Notes: 1) These functions bypass the IVI attribute state caching.
 *                  viWrite invalidates the cached values for all
 *                  attributes.
 *                  2) These functions are supported with the IVI Compliance
 *                  Package (ICP) 4.6.1 and later. If you are using an
 *                  earlier version of ICP, you can still use the ag3446x_WriteInstrData
 *                  and ag3446x_ReadInstrData functions under the Obsolete folder.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_viWrite (ViSession vi, ViByte buffer[], ViInt64 count, ViInt64 *returnCount)
{
    return Ivi_viWrite (vi, buffer, count, returnCount);
}
ViStatus _VI_FUNC ag3446x_viRead (ViSession vi, ViInt64 bufferSize, ViByte buffer[], ViInt64 *returnCount)
{
    return Ivi_viRead (vi, bufferSize, buffer, returnCount);
}

/*****************************************************************************
 * Function: WriteInstrData and ReadInstrData Functions
 * Purpose:  These functions enable the instrument driver user to
 *           write and read commands directly to and from the instrument.
 *
 *           Notes: 1) These functions bypass the IVI attribute state caching.
 *                  WriteInstrData invalidates the cached values for all
 *                  attributes.
 *                  2) These functions are obsolete since IVI Compliance
 *                  Package (ICP) 4.6.1. You can use ag3446x_viWrite
 *                  and ag3446x_viRead instead.
 *****************************************************************************/
ViStatus _VI_FUNC ag3446x_WriteInstrData (ViSession vi, ViConstString writeBuffer)
{
    return Ivi_WriteInstrData (vi, writeBuffer);
}
ViStatus _VI_FUNC ag3446x_ReadInstrData (ViSession vi, ViInt32 numBytes,
                                         ViChar rdBuf[], ViInt32 *bytesRead)
{
    return Ivi_ReadInstrData (vi, numBytes, rdBuf, bytesRead);
}

/*****************************************************************************
 *-------------------- Utility Functions (Not Exported) ---------------------*
 *****************************************************************************/
static IviRangeTableEntry attrActualRangeTableEntries[] =
{
    { AG3446X_VAL_DC_VOLTS,       0, 0, "VOLT:DC:RANG", 0 },
    { AG3446X_VAL_AC_VOLTS,       0, 0, "VOLT:AC:RANG", 0 },
    { AG3446X_VAL_DC_VOLTS_RATIO, 0, 0, "VOLT:DC:RANG", 0 },
    { AG3446X_VAL_DC_CURRENT,     0, 0, "CURR:DC:RANG", 0 },
    { AG3446X_VAL_AC_CURRENT,     0, 0, "CURR:AC:RANG", 0 },
    { AG3446X_VAL_2_WIRE_RES,     0, 0, "RES:RANG",     0 },
    { AG3446X_VAL_4_WIRE_RES,     0, 0, "FRES:RANG",    0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrActualRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_FALSE,
    VI_FALSE,
    VI_NULL,
    attrActualRangeTableEntries,
};

static ViStatus ag3446x_GetActualRange (ViSession vi, ViSession io,
                                        ViReal64 *value)
{
    ViStatus error = VI_NULL;
    ViInt32  function;
    ViString cmd;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &function));

    switch (function)
    {
    case AG3446X_VAL_FREQ:
    case AG3446X_VAL_PERIOD:
    case AG3446X_VAL_TEMPERATURE:
    case AG3446X_VAL_CONTINUITY:
    case AG3446X_VAL_DIODE:
        *value = AG3446X_VAL_AUTO_RANGE_ON;
        break;

    default:
        viCheckErr (ag3446x_GetCmdFromIntValue (function, &attrActualRangeTable, &cmd));
        viCheckErr (viPrintf (io, "SENS:%s?", cmd));
        viCheckErr (viScanf (io, "%le", value));
        break;
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446x_IviInit
 * Purpose:  This function is called by ag3446x_InitWithOptions
 *           or by an IVI class driver.  This function initializes the I/O
 *           interface, optionally resets the device, optionally performs an
 *           ID query, and sends a default setup to the instrument.
 *****************************************************************************/
static ViStatus ag3446x_IviInit (ViRsrc resourceName, ViBoolean IDQuery,
                                 ViBoolean reset, ViSession vi)
{
    ViStatus  error        = VI_SUCCESS;
    ViSession io           = VI_NULL;
    ViUInt16  interface    = VI_INTF_GPIB;
    ViChar    modelStr[20] = "";
    ViInt32   modelNum     = AG3446X_VAL_MODEL_UNKNOWN;
	ViChar    rdBuffer[BUFFER_SIZE] = ""; 
	ViInt32	  optionValue  = 0;

    if (!Ivi_Simulating (vi))
    {
        ViSession rmSession = VI_NULL;

        /* Open instrument session */
        checkErr (Ivi_GetAttributeViSession (vi, VI_NULL, IVI_ATTR_VISA_RM_SESSION, 0,
                                             &rmSession));
        viCheckErr (viOpen (rmSession, resourceName, VI_NULL, VI_NULL, &io));
        /* io session owned by driver now */
        checkErr (Ivi_SetAttributeViSession (vi, VI_NULL, IVI_ATTR_IO_SESSION, 0, io));

        /* Configure VISA Formatted I/O */
        viCheckErr (viSetAttribute (io, VI_ATTR_TMO_VALUE, 10000));
        viCheckErr (viSetBuf (io, VI_READ_BUF | VI_WRITE_BUF, 4000));
        viCheckErr (viSetAttribute (io, VI_ATTR_WR_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS));
        viCheckErr (viSetAttribute (io, VI_ATTR_RD_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS));

        /* Configure VISA Serial I/O */
        viCheckErr (viGetAttribute (io, VI_ATTR_INTF_TYPE, &interface));
        if (interface == VI_INTF_ASRL)
        {
            viCheckErr (viSetAttribute (io, VI_ATTR_TERMCHAR, '\n'));
            viCheckErr (viSetAttribute (io, VI_ATTR_TERMCHAR_EN, VI_TRUE));
            viCheckErr (viSetAttribute (io, VI_ATTR_ASRL_END_IN, VI_ASRL_END_TERMCHAR));
            viCheckErr (viSetAttribute (io, VI_ATTR_ASRL_END_OUT, VI_ASRL_END_TERMCHAR));
        }
		
		if (IDQuery && modelNum == AG3446X_VAL_MODEL_UNKNOWN)
		{
		    checkErr (ag3446x_QueryID (vi, io, BUFFER_SIZE, rdBuffer));
		    checkErr (ag3446x_GetModelFromBuffer (vi, rdBuffer, &modelNum));
		}
    }
	
	checkErr (Ivi_BuildChannelTable (vi, CHANNEL_LIST, VI_FALSE, VI_NULL));
	
	if (modelNum == AG3446X_VAL_MODEL_UNKNOWN)
	{
		modelNum = AG3446X_VAL_MODEL_34460A;
	}
	
	/* Add attributes */
    checkErr (ag3446x_InitAttributes (vi, modelNum));
	
    /*- Reset instrument ----------------------------------------------------*/
    if (reset)
        checkErr (ag3446x_reset (vi));
    else  /*- Send Default Instrument Setup ---------------------------------*/
        checkErr (ag3446x_DefaultInstrSetup (vi));

    /*- Identification Query ------------------------------------------------*/
    if (IDQuery)
    {
		ViInt32 actModel = modelNum;
		
		if (!rdBuffer[0])
		{
	        checkErr (Ivi_GetAttributeViString (vi, VI_NULL, AG3446X_ATTR_ID_QUERY_RESPONSE,
	                                            0, BUFFER_SIZE, rdBuffer));
			checkErr (ag3446x_GetModelFromBuffer (vi, rdBuffer, &actModel));   
		}
        else
        {
            checkErr (Ivi_SetAttributeViString (vi, VI_NULL, AG3446X_ATTR_ID_QUERY_RESPONSE,
                                                IVI_VAL_DONT_MARK_AS_SET_BY_USER,
                                                rdBuffer));
			checkErr (Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MODEL, VI_NULL, modelNum)); 
			
			checkErr( ag3446x_QueryOptions(vi, io, BUFFER_SIZE, rdBuffer));
			checkErr( ag3446x_GetOptionsFromBuffer(vi, rdBuffer, &optionValue));
		
			checkErr( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_OPTION, 0, optionValue));
        }
        
		if (modelNum != actModel)
            viCheckErr (VI_ERROR_FAIL_ID_QUERY);
    }
    else
    {
        checkErr (ag3446x_GetDriverSetupOption (vi, "Model", 20, modelStr));

        
		if ((strncmp (modelStr, "EDU34450A", strlen ("EDU34450A")) == 0))
            modelNum = AG3446X_VAL_MODEL_EDU34450A;
		else if (strncmp (modelStr, "34460A", strlen ("34460A")) == 0)
            modelNum = AG3446X_VAL_MODEL_34460A;
        else if (strncmp (modelStr, "34461A", strlen ("34461A")) == 0)
            modelNum = AG3446X_VAL_MODEL_34461A;
        else if (strncmp (modelStr, "34465A", strlen ("34465A")) == 0)
            modelNum = AG3446X_VAL_MODEL_34465A;
        else if (strncmp (modelStr, "34470A", strlen ("34470A")) == 0)
            modelNum = AG3446X_VAL_MODEL_34470A;
        else
            viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The model specified is not valid");
		
		checkErr( Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_OPTION, 0, 0));
    }

    checkErr (ag3446x_CheckStatus (vi));

Error:
    if (error < VI_SUCCESS)
    {
        if (!Ivi_Simulating (vi) && io)
            viClose (io);
    }
    return error;
}

/*****************************************************************************
 * Function: ag3446x_IviClose
 * Purpose:  This function performs all of the drivers clean-up operations
 *           except for closing the IVI session.  This function is called by
 *           ag3446x_close or by an IVI class driver.
 *
 *           Note:  This function must close the I/O session and set
 *           IVI_ATTR_IO_SESSION to 0.
 *****************************************************************************/
static ViStatus ag3446x_IviClose (ViSession vi)
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = VI_NULL;

    /* Do not lock here.  The caller manages the lock. */

    checkErr (Ivi_GetAttributeViSession (vi, VI_NULL, IVI_ATTR_IO_SESSION, 0, &io));

Error:
    Ivi_SetAttributeViSession (vi, VI_NULL, IVI_ATTR_IO_SESSION, 0, VI_NULL);
    if (io)
    {
        viClose (io);
    }
    return error;
}

/*****************************************************************************
 * Function: ag3446x_CheckStatus
 * Purpose:  This function checks the status of the instrument to detect
 *           whether the instrument has encountered an error.  This function
 *           is called at the end of most exported driver functions.  If the
 *           instrument reports an error, this function returns
 *           IVI_ERROR_INSTRUMENT_SPECIFIC.  The user can set the
 *           AG3446X_ATTR_QUERY_INSTRUMENT_STATUS attribute to VI_FALSE to disable this
 *           check and increase execution speed.
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus ag3446x_CheckStatus (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    if (Ivi_QueryInstrStatus (vi) && Ivi_NeedToCheckStatus (vi) && !Ivi_Simulating (vi))
    {
        checkErr (ag3446x_CheckStatusCallback (vi, Ivi_IOSession (vi)));
        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_FALSE));
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446x_WaitForOPC
 * Purpose:  This function waits for the instrument to complete the
 *           execution of all pending operations.  This function is a
 *           wrapper for the WaitForOPCCallback.  It can be called from
 *           other instrument driver functions.
 *
 *           The maxTime parameter specifies the maximum time to wait for
 *           operation complete in milliseconds.
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus ag3446x_WaitForOPC (ViSession vi, ViInt32 maxTime)
{
    ViStatus error = VI_SUCCESS;

    if (!Ivi_Simulating (vi))
    {
        ViInt32 oldOPCTimeout;

        checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_OPC_TIMEOUT,
                                           0, &oldOPCTimeout));
        Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_OPC_TIMEOUT,
                                 0, maxTime);

        error = ag3446x_WaitForOPCCallback (vi, Ivi_IOSession (vi));

        Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_OPC_TIMEOUT,
                                 0, oldOPCTimeout);
        viCheckErr (error);
    }
Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446x_DefaultInstrSetup
 * Purpose:  This function sends a default setup to the instrument.  The
 *           ag3446x_reset function calls this function.  The
 *           ag3446x_IviInit function calls this function when the
 *           user passes VI_FALSE for the reset parameter.  This function is
 *           useful for configuring settings that other instrument driver
 *           functions require.
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus ag3446x_DefaultInstrSetup (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    /* Invalidate all attributes */
    checkErr (Ivi_InvalidateAllAttributes (vi));

    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession (vi);  /* call only when locked */

        checkErr (Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        viCheckErr (viPrintf (io, "*CLS;*ESE 1;*SRE 32"));
    }

    checkErr (Ivi_SetAttributeViInt32 (vi, "", AG3446X_ATTR_TRIGGER_COUNT,
                                       IVI_VAL_DONT_MARK_AS_SET_BY_USER, 1));
    checkErr (Ivi_SetAttributeViInt32 (vi, "", AG3446X_ATTR_SAMPLE_COUNT,
                                       IVI_VAL_DONT_MARK_AS_SET_BY_USER, 1));
    checkErr (Ivi_SetAttributeViInt32 (vi, "", AG3446X_ATTR_AUTO_ZERO,
                                       IVI_VAL_DONT_MARK_AS_SET_BY_USER,
                                       AG3446X_VAL_AUTO_ZERO_OFF));
    checkErr (ag3446x_CheckStatus (vi));

Error:
    return error;
}

/*******************************************************************************
 * Function:  ag3446x_ClearCalculateData
 * Purpose:   This function clears the calculation data.
 *******************************************************************************/
ViStatus _VI_FUNC ag3446x_ClearCalculateData (ViSession vi, ViInt32 clearOperation)
{
    ViStatus  error = VI_SUCCESS;
    ViSession io    = Ivi_IOSession (vi);

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if (clearOperation == AG3446X_VAL_CLEAR_ALL)
    {
        viCheckErr (viPrintf (io, "CALC:CLE;"));
    }
    else if (clearOperation == AG3446X_VAL_CLEAR_LIMIT)
    {
        viCheckErr (viPrintf (io, "CALC:LIM:CLE;"));
    }
    else if (clearOperation == AG3446X_VAL_CLEAR_HIST)
    {
        viCheckErr (viPrintf (io, "CALC:TRAN:HIST:CLE;"));
    }
    else if (clearOperation == AG3446X_VAL_CLEAR_AVER)
    {
        viCheckErr (viPrintf (io, "CALC:AVER:CLE;"));
    }
    else
        viCheckErrElab (IVI_ERROR_INVALID_VALUE, "This is a wrong value when setting the clear operation");


    checkErr (ag3446x_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 *  Function: ag3446x_GetStringFromTable
 *  Purpose:  Read the string command from range table
 *****************************************************************************/
static ViStatus ag3446x_GetStringFromTable (ag3446xStringValueTable table,
                                            ViInt32 value,
                                            ViConstString*        string)
{
    ViStatus  error = VI_SUCCESS;
    ViBoolean found = VI_FALSE;
    ViInt32   i;

    for (i = 0; table[i].string; i++)
    {
        if (table[i].value == value)
        {
            *string = table[i].string;
            found   = VI_TRUE;
            break;
        }
    }

    if (!found)
        error = IVI_ERROR_INVALID_VALUE;

    return error;
}

/*****************************************************************************
 *  Function: ag3446x_GetRepCommandFromTable
 *  Purpose:  Read the repeated command from range table to concat with the
 *            string command.
 *****************************************************************************/
static ViStatus ag3446x_GetRepCommandFromTable (ag3446xStringValueTable table,
                                                ViInt32 value,
                                                ViConstString*        repCommand)
{
    ViStatus  error = VI_SUCCESS;
    ViBoolean found = VI_FALSE;
    ViInt32   i;

    for (i = 0; table[i].repCommand; i++)
    {
        if (table[i].value == value)
        {
            *repCommand = table[i].repCommand;
            found       = VI_TRUE;
            break;
        }
    }

    if (!found)
        error = IVI_ERROR_INVALID_VALUE;

    return error;
}


/*****************************************************************************
 *------------------------ Global Session Callbacks -------------------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: ag3446x_CheckStatusCallback
 * Purpose:  This function queries the instrument to determine if it has
 *           encountered an error.  If the instrument has encountered an
 *           error, this function returns the IVI_ERROR_INSTRUMENT_SPECIFIC
 *           error code.  This function is called by the
 *           ag3446x_CheckStatus utility function.  The
 *           Ivi_SetAttribute and Ivi_GetAttribute functions invoke this
 *           function when the optionFlags parameter includes the
 *           IVI_VAL_DIRECT_USER_CALL flag.
 *
 *           The user can disable calls to this function by setting the
 *           AG3446X_QUERY_INSTRUMENT_STATUS attribute to VI_FALSE.  The driver can
 *           disable the check status callback for a particular attribute by
 *           setting the IVI_VAL_DONT_CHECK_STATUS flag.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446x_CheckStatusCallback (ViSession vi, ViSession io)
{
    ViStatus error = VI_SUCCESS;
    ViInt16  esr   = 0;
    ViString msg   = "";

    viCheckErr (viQueryf (io, "*ESR?", "%hd", &esr));

    /* Convert status information into a message */
    if ((esr & IEEE_488_2_QUERY_ERROR_BIT))
        msg = "Query Error";
    else if ((esr & IEEE_488_2_DEVICE_DEPENDENT_ERROR_BIT))
        msg = "Device Dependent Error";
    else if ((esr & IEEE_488_2_EXECUTION_ERROR_BIT))
        msg = "Execution Error";
    else if ((esr & IEEE_488_2_COMMAND_ERROR_BIT))
        msg = "Command Error";
    else
        esr = 0;

    if (esr != 0)
        viCheckErrElab (IVI_ERROR_INSTR_SPECIFIC, msg);

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446x_WaitForOPCCallback
 * Purpose:  This function waits until the instrument has finished processing
 *           all pending operations.  This function is called by the
 *           ag3446x_WaitForOPC utility function.  The IVI engine invokes
 *           this function in the following two cases:
 *           - Before invoking the read callback for attributes for which the
 *             IVI_VAL_WAIT_FOR_OPC_BEFORE_READS flag is set.
 *           - After invoking the write callback for attributes for which the
 *             IVI_VAL_WAIT_FOR_OPC_AFTER_WRITES flag is set.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446x_WaitForOPCCallback (ViSession vi, ViSession io)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  opcTimeout;
    ViUInt16 statusByte;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_OPC_TIMEOUT,
                                       0, &opcTimeout));

    viCheckErr (viEnableEvent (io, VI_EVENT_SERVICE_REQ, VI_QUEUE, VI_NULL));

    viCheckErr (viPrintf (io, "*OPC"));

    /* wait for SRQ */
    viCheckErr (viWaitOnEvent (io, VI_EVENT_SERVICE_REQ, opcTimeout, VI_NULL, VI_NULL));
    viCheckErr (viDisableEvent (io, VI_EVENT_SERVICE_REQ, VI_QUEUE));

    /* clean up after SRQ */
    viCheckErr (viBufWrite (io, "*CLS", 4, VI_NULL));
    viCheckErr (viReadSTB (io, &statusByte));

Error:
    viDiscardEvents (io, VI_EVENT_SERVICE_REQ, VI_QUEUE);

    return error;
}

/*****************************************************************************
 *----------------- Attribute Range Tables and Callbacks --------------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: ag3446xEnum_WriteCallback
 * Purpose:  This function sets the enum value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xEnum_WriteCallback (ViSession vi,
                                                    ViSession io,
                                                    ViConstString channelName,
                                                    ViAttr attributeId,
                                                    ViInt32 value)
{
    ViStatus         error = VI_SUCCESS;
    ViString         command,
                     commandValue;
    ViString         repCommand;
    IviRangeTablePtr table;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xEnum_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xEnum_commands, attributeId, &repCommand));

    checkErr (Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));
    viCheckErr (ag3446x_GetCmdFromIntValue (value, table, &commandValue));

    if (!Ivi_Simulating (vi))
    {
        viCheckErr (viPrintf (io, "%s%s%s %s", command, VALID_CHANNELNAME (channelName), repCommand, commandValue));
    }
Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xEnum_ReadCallback
 * Purpose:  This function reads the enum value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xEnum_ReadCallback (ViSession vi,
                                                   ViSession io,
                                                   ViConstString channelName,
                                                   ViAttr attributeId,
                                                   ViInt32*        value)										
{
    ViStatus         error = VI_SUCCESS;
    ViString         command;
    ViString         repCommand;
    IviRangeTablePtr table;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xEnum_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xEnum_commands, attributeId, &repCommand));

    checkErr (Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));

    if (!Ivi_Simulating (vi))
    {
        ViChar  rdBuffer[BUFFER_SIZE];
        ViInt32 rdBufferSize = (ViInt32) sizeof (rdBuffer);

        viCheckErr (viPrintf (io, "%s%s%s?", command, VALID_CHANNELNAME (channelName), repCommand));
        viCheckErr (viScanf (io, "%#s", &rdBufferSize, rdBuffer));
        viCheckErr (ag3446x_GetValueFromCmd (rdBuffer, table, value));
    }
Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xViBoolean_WriteCallback
 * Purpose:  This function sets the bool value of the ViBoolean attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViBoolean_WriteCallback (ViSession vi,
                                                         ViSession io,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViBoolean value)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViBoolean_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViBoolean_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
        viCheckErr (viPrintf (io, "%s%s%s %s", command, VALID_CHANNELNAME (channelName), repCommand, value ? "ON" : "OFF"));

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xViBoolean_ReadCallback
 * Purpose:  This function reads the bool value of the ViBoolean attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViBoolean_ReadCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViBoolean*      value)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViBoolean_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViBoolean_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
        viCheckErr (viQueryf (io, "%s%s%s?", "%hd", command, VALID_CHANNELNAME (channelName), repCommand, value));

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xViString_WriteCallback
 * Purpose:  This function sets the string value of the ViString attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViString_WriteCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViConstString value)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViString_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViString_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
        viCheckErr (viPrintf (io, "%s%s%s \"%s\"", command, VALID_CHANNELNAME (channelName), repCommand, value));

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xViString_ReadCallback
 * Purpose:  This function reads the string value of the ViString attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViString_ReadCallback (ViSession vi,
                                                       ViSession io,
                                                       ViConstString channelName,
                                                       ViAttr attributeId,
                                                       const ViConstString cacheValue)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;
    ViChar   * pdata = VI_NULL;
    ViChar   * pend  = VI_NULL;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViString_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViString_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
    {
        ViChar   buffer[BUFFER_SIZE];
        ViChar   * pbuffer       = VI_NULL;
        ViUInt32 allocated_count = 0;
        ViUInt32 count           = 0;
        ViUInt32 readed_count;

        viCheckErr (viPrintf (io, "%s%s%s?", command, VALID_CHANNELNAME (channelName), repCommand));

        while ((error = viRead (io, buffer, BUFFER_SIZE, &readed_count)) == VI_SUCCESS_MAX_CNT)
        {
            if (allocated_count)
            {
                if (allocated_count <= count + readed_count)
                {
                    allocated_count += (allocated_count - count) + BUFFER_SIZE;
                    pdata            = realloc (pdata, allocated_count);
                }

                pend = pdata + count;
            }
            else
            {
                allocated_count = 2 * BUFFER_SIZE;
                pdata           = malloc (allocated_count);
                pend            = pdata;
            }

            memcpy (pend, buffer, readed_count);
            count += readed_count;
        }

        if (readed_count > 0)
        {
            /*
             * Check if the last character is alnum.
             * if this character is not alnum we know that it's '\n'.
             * Remove it.
             */
            if (!isalnum (buffer[readed_count - 1]))
                readed_count--;
            buffer[readed_count] = '\0';
        }

        /*
         * If function is read more data as BUFFER_SIZE, we must
         * copy last data from static buffer to dynamic buffer
         */
        if (pdata)
        {
            /*
             * For sure, check if the  buffer has enough element.
             * This condition should be FALSE every time.
             */
            if (allocated_count <= count + readed_count)
            {
                allocated_count += (allocated_count - count) + BUFFER_SIZE;
                pdata            = realloc (pdata, allocated_count);
            }
            pend = pdata + count;
            memcpy (pend, buffer, readed_count + 1);
            pbuffer = pdata;
        }
        else
            pbuffer = buffer;

        viCheckErr (error);

        checkErr (Ivi_SetValInStringCallback (vi, attributeId, pbuffer));
    }

Error:
    if (pdata)
        free (pdata);
    return error;
}

/*****************************************************************************
 * Function: ag3446xViReal64_WriteCallback
 * Purpose:  This function sets the bool value of the ViReal64 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViReal64_WriteCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViReal64_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViReal64_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
    {											   
        if (abs (value) < 1.0)
        {
            viCheckErr (viPrintf (io, "%s%s%s %Le", command, VALID_CHANNELNAME (channelName), repCommand, value));
        }
        else
        {
            viCheckErr (viPrintf (io, "%s%s%s %Lf", command, VALID_CHANNELNAME (channelName), repCommand, value));
        }
    }
Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xViReal64_ReadCallback
 * Purpose:  This function reads the bool value of the ViReal64 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViReal64_ReadCallback (ViSession vi,
                                                       ViSession io,
                                                       ViConstString channelName,
                                                       ViAttr attributeId,
                                                       ViReal64*       value)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViReal64_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViReal64_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
        viCheckErr (viQueryf (io, "%s%s%s?", "%Le", command, VALID_CHANNELNAME (channelName), repCommand, value));

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xViInt32_WriteCallback
 * Purpose:  This function sets the bool value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViInt32_WriteCallback (ViSession vi,
                                                       ViSession io,
                                                       ViConstString channelName,
                                                       ViAttr attributeId,
                                                       ViInt32 value)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViInt32_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViInt32_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
        viCheckErr (viPrintf (io, "%s%s%s %ld", command, VALID_CHANNELNAME (channelName), repCommand, value));

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446xViInt32_ReadCallback
 * Purpose:  This function reads the bool value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC ag3446xViInt32_ReadCallback (ViSession vi,
                                                      ViSession io,
                                                      ViConstString channelName,
                                                      ViAttr attributeId,
                                                      ViInt32*        value)
{
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViInt32_commands, attributeId, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViInt32_commands, attributeId, &repCommand));

    if (!Ivi_Simulating (vi))
        viCheckErr (viQueryf (io, "%s%s%s?", "%ld", command, VALID_CHANNELNAME (channelName), repCommand, value));

Error:
    return error;
}



/*- AG3446X_ATTR_ID_QUERY_RESPONSE -*/

static ViStatus _VI_FUNC ag3446xAttrIdQueryResponse_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  const ViConstString cacheValue)
{
    ViStatus error = VI_SUCCESS;
    ViChar   rdBuffer[BUFFER_SIZE];
    ViUInt32 retCnt;

    viCheckErr (viPrintf (io, "*IDN?"));
    viCheckErr (viRead (io, rdBuffer, BUFFER_SIZE - 1, &retCnt));
    rdBuffer[retCnt] = 0;

    checkErr (Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}

/*- AG3446X_ATTR_SPECIFIC_DRIVER_REVISION -*/

static ViStatus _VI_FUNC ag3446xAttrDriverRevision_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 const ViConstString cacheValue)
{
    ViStatus error = VI_SUCCESS;
    ViChar   driverRevision[256];


    sprintf (driverRevision,
             "Driver: ag3446x %d.%d, Compiler: %s %3.2f, "
             "Components: IVIEngine %.2f, VISA-Spec %.2f",
             AG3446X_MAJOR_VERSION, AG3446X_MINOR_VERSION,
             IVI_COMPILER_NAME, IVI_COMPILER_VER_NUM,
             IVI_ENGINE_MAJOR_VERSION + IVI_ENGINE_MINOR_VERSION / 1000.0,
             Ivi_ConvertVISAVer (VI_SPEC_VERSION));

    checkErr (Ivi_SetValInStringCallback (vi, attributeId, driverRevision));
Error:
    return error;
}


/*- AG3446X_ATTR_INSTRUMENT_FIRMWARE_REVISION -*/

static ViStatus _VI_FUNC ag3446xAttrFirmwareRevision_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   const ViConstString cacheValue)
{
    ViStatus error = VI_SUCCESS;
    ViChar   idQ[BUFFER_SIZE], rdBuffer[BUFFER_SIZE];

    checkErr (Ivi_GetAttributeViString (vi, "", AG3446X_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));

    sscanf (idQ, "%*[^,],%*[^,],%*[^,],%256[^\n]", rdBuffer);

    checkErr (Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}

/*- AG3446X_ATTR_INSTRUMENT_MANUFACTURER -*/

static ViStatus _VI_FUNC ag3446xAttrInstrumentManufacturer_ReadCallback (ViSession vi,
                                                                         ViSession io,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         const ViConstString cacheValue)
{
    ViStatus error = VI_SUCCESS;
    ViChar   rdBuffer[BUFFER_SIZE];
    ViChar   idQ[BUFFER_SIZE];

    checkErr (Ivi_GetAttributeViString (vi, "", AG3446X_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));
    sscanf (idQ, "%256[^,]", rdBuffer);

    checkErr (Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}



/*- AG3446X_ATTR_INSTRUMENT_MODEL -*/

static ViStatus _VI_FUNC ag3446xAttrInstrumentModel_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  const ViConstString cacheValue)
{
    ViStatus error = VI_SUCCESS;
    ViChar   rdBuffer[BUFFER_SIZE];
    ViChar   idQ[BUFFER_SIZE];

    checkErr (Ivi_GetAttributeViString (vi, "", AG3446X_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));
    sscanf (idQ, "%*[^,],%256[^,]", rdBuffer);

    checkErr (Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}



/*- AG3446X_ATTR_FUNCTION -*/

static IviRangeTableEntry attrFunctionRangeTableEntries[] =
{
    { AG3446X_VAL_DC_VOLTS,       0, 0, "VOLT",     0 },
    { AG3446X_VAL_AC_VOLTS,       0, 0, "VOLT:AC",  0 },
    { AG3446X_VAL_DC_CURRENT,     0, 0, "CURR",     0 },
    { AG3446X_VAL_AC_CURRENT,     0, 0, "CURR:AC",  0 },
    { AG3446X_VAL_2_WIRE_RES,     0, 0, "RES",      0 },
    { AG3446X_VAL_4_WIRE_RES,     0, 0, "FRES",     0 },
    { AG3446X_VAL_FREQ,           0, 0, "FREQ",     0 },
    { AG3446X_VAL_PERIOD,         0, 0, "PER",      0 },
    { AG3446X_VAL_TEMPERATURE,    0, 0, "TEMP",     0 },
    { AG3446X_VAL_CONTINUITY,     0, 0, "CONT",     0 },
    { AG3446X_VAL_DIODE,          0, 0, "DIOD",     0 },
    { AG3446X_VAL_DC_VOLTS_RATIO, 0, 0, "VOLT:RAT", 0 },
	{ AG3446X_VAL_CAPACITANCE,    0, 0, "CAP",      0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};
static IviRangeTable      attrFunctionRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_FALSE,
    VI_FALSE,
    VI_NULL,
    attrFunctionRangeTableEntries,
};

static IviRangeTableEntry attrEDU34450AFunctionRangeTableEntries[] =
	{
		{AG3446X_VAL_DC_VOLTS, 	  0, 0, "VOLT",     0},
		{AG3446X_VAL_AC_VOLTS,    0, 0, "VOLT:AC",  0},
		{AG3446X_VAL_DC_CURRENT,  0, 0, "CURR",     0},
		{AG3446X_VAL_AC_CURRENT,  0, 0, "CURR:AC",  0},
		{AG3446X_VAL_2_WIRE_RES,  0, 0, "RES",      0},
		{AG3446X_VAL_4_WIRE_RES,  0, 0, "FRES",     0},
		{AG3446X_VAL_FREQ,        0, 0, "FREQ",     0},
		{AG3446X_VAL_TEMPERATURE, 0, 0, "TEMP",     0},
		{AG3446X_VAL_CONTINUITY,  0, 0, "CONT",     0},
		{AG3446X_VAL_DIODE,       0, 0, "DIOD",     0},
		{AG3446X_VAL_CAPACITANCE, 0, 0, "CAP",      0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrEDU34450AFunctionRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrEDU34450AFunctionRangeTableEntries,
	};

static ViStatus _VI_FUNC ag3446xAttrFunction_RangeTableCallback (ViSession vi,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr (Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

	if (IS_EDU34450A(model))
	{
		tblPtr=&attrEDU34450AFunctionRangeTable;
	}
	else
	{
		tblPtr=&attrFunctionRangeTable; 	
	}


Error:
	*rangeTablePtr = tblPtr;
	return error;
}


static ViStatus _VI_FUNC ag3446xAttrFunction_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value)
{
    ViStatus         error = VI_SUCCESS;
    ViString         cmd;
    IviRangeTablePtr RngTblPtr;
	ViInt32 		 model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
    checkErr (Ivi_GetAttrRangeTable (vi, "", AG3446X_ATTR_FUNCTION, &RngTblPtr));
	
	if(IS_EDU34450A(model))
	{
		checkErr (ag3446x_GetCmdFromIntValue (value, &attrEDU34450AFunctionRangeTable, &cmd)); 
	}
	else
	{
		checkErr (ag3446x_GetCmdFromIntValue (value, &attrFunctionRangeTable, &cmd));
	}
	 	
    viCheckErr (viPrintf (io, ":FUNC \"%s\";", cmd));

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrFunction_ReadCallback (ViSession vi,
                                                           ViSession io,
                                                           ViConstString channelName,
                                                           ViAttr attributeId,
                                                           ViInt32 *value)
{
    ViStatus         error = VI_SUCCESS;
    ViChar           rdBuffer[BUFFER_SIZE];
    IviRangeTablePtr RngTblPtr;

    viCheckErr (viPrintf (io, "FUNC?;"));
    viCheckErr (viScanf (io, "\"%[^\"]", rdBuffer));

    checkErr (Ivi_GetAttrRangeTable (vi, "", AG3446X_ATTR_FUNCTION, &RngTblPtr));
    viCheckErr (ag3446x_GetValueFromCmd (rdBuffer, RngTblPtr, value));

Error:
    return error;
}

/*- AG3446X_ATTR_RANGE -*/

static IviRangeTableEntry attrRangeVoltageRangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    { AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, "", 0 },
    {                         0.0,                         0.1,                         0.1, "", 0 },
    {                         0.1,                           1,                           1, "", 0 },
    {                         1.0,                        10.0,                        10.0, "", 0 },
    {                        10.0,                       100.0,                       100.0, "", 0 },
    {                       100.0,                      1000.0,                      1000.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeVoltageRangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeVoltageRangeTableEntries,
};

static IviRangeTableEntry attrRangeDCVoltageEDU34450ARangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    {                         0.1,                           1,                           1, "", 0 },
    {                         1.0,                        10.0,                        10.0, "", 0 },
    {                        10.0,                       100.0,                       100.0, "", 0 },
    {                       100.0,                      1000.0,                      1000.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeDCVoltageEDU34450ARangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeDCVoltageEDU34450ARangeTableEntries,
};

static IviRangeTableEntry attrRangeACVoltageEDU34450ARangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    {                         0.1,                           1,                           1, "", 0 },
    {                         1.0,                        10.0,                        10.0, "", 0 },
    {                        10.0,                       100.0,                       100.0, "", 0 },
    {                       100.0,                       750.0,                       750.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeACVoltageEDU34450ARangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeACVoltageEDU34450ARangeTableEntries,
};

static IviRangeTableEntry attrRangeResistanceRangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    { AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, "", 0 },
    {                         0.0,                       100.0,                       100.0, "", 0 },
    {                       100.0,                      1000.0,                      1000.0, "", 0 },
    {                      1000.0,                     10000.0,                     10000.0, "", 0 },
    {                     10000.0,                    100000.0,                    100000.0, "", 0 },
    {                    100000.0,                   1000000.0,                   1000000.0, "", 0 },
    {                   1000000.0,                  10000000.0,                  10000000.0, "", 0 },
    {                  10000000.0,                 100000000.0,                 100000000.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeResistanceRangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeResistanceRangeTableEntries,
};

static IviRangeTableEntry attrRangeResistanceEDU34450ARangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    {                       100.0,                      1000.0,                      1000.0, "", 0 },
    {                      1000.0,                     10000.0,                     10000.0, "", 0 },
    {                     10000.0,                    100000.0,                    100000.0, "", 0 },
    {                    100000.0,                   1000000.0,                   1000000.0, "", 0 },
    {                   1000000.0,                  10000000.0,                  10000000.0, "", 0 },
    {                  10000000.0,                 100000000.0,                 100000000.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeResistanceEDU34450ARangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeResistanceEDU34450ARangeTableEntries,
};

static IviRangeTableEntry attrRangeCurrentRangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    { AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, "", 0 },
    {                         0.0,                      0.0001,                      0.0001, "", 0 },
    {                      0.0001,                       0.001,                       0.001, "", 0 },
    {                       0.001,                        0.01,                        0.01, "", 0 },
    {                        0.01,                         0.1,                         0.1, "", 0 },
    {                         0.1,                         1.0,                         1.0, "", 0 },
    {                         1.0,                         3.0,                         3.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeCurrentRangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeCurrentRangeTableEntries,
};

static IviRangeTableEntry attrRangeCurrentEDU34450ARangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    {                        0.01,                         0.1,                         0.1, "", 0 },
    {                         0.1,                         1.0,                         1.0, "", 0 },
    {                         1.0,                         3.0,                         3.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeCurrentEDU34450ARangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeCurrentEDU34450ARangeTableEntries,
};

static IviRangeTableEntry attrRangeCapacitanceRangeTableEntries[] =
{
	{AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   """", 0},
	{AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  """", 0},
	{AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, """", 0},
	{0.0,                         1e-9,                        1e-9,                        """", 0},
	{1e-9,                        1e-8,                        1e-8,                        """", 0},
	{1e-8,                        1e-7,                        1e-7,                        """", 0},
	{1e-7,                        1e-6,                        1e-6,                        """", 0},
	{1e-6,                        1e-5,                        1e-5,                        """", 0},
	{1e-5,                        1e-4,                        1e-4,                        """", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrRangeCapacitanceRangeTable = 
{
	IVI_VAL_COERCED,
	VI_FALSE,
	VI_TRUE,
	VI_NULL,
	attrRangeCapacitanceRangeTableEntries,
};

static IviRangeTableEntry attrRangeCapacitanceEDU34450ARangeTableEntries[] =
{
	{AG3446X_VAL_AUTO_RANGE_ON,  AG3446X_VAL_AUTO_RANGE_ON, AG3446X_VAL_AUTO_RANGE_ON,   """", 0},
	{AG3446X_VAL_AUTO_RANGE_OFF, AG3446X_VAL_AUTO_RANGE_OFF, AG3446X_VAL_AUTO_RANGE_OFF, """", 0},
	{1e-9, 1e-8, 1e-8, """", 0},
	{1e-8, 1e-7, 1e-7, """", 0},
	{1e-7, 1e-6, 1e-6, """", 0},
	{1e-6, 1e-5, 1e-5, """", 0},
	{1e-5, 1e-4, 1e-4, """", 0},
	{1e-4, 1e-3, 1e-3, """", 0},
	{1e-3, 1e-2, 1e-2, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrRangeCapacitanceEDU34450ARangeTable =
	{
		IVI_VAL_COERCED,
        VI_FALSE,
        VI_TRUE,
        VI_NULL,
        attrRangeCapacitanceEDU34450ARangeTableEntries,
	};

static IviRangeTableEntry attrRangeDefaultRangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON, AG3446X_VAL_AUTO_RANGE_ON, AG3446X_VAL_AUTO_RANGE_ON, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrRangeDefaultRangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrRangeDefaultRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrRange_RangeTableCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              IviRangeTablePtr *rangeTablePtr)
{
    ViStatus         error  = VI_SUCCESS;
    IviRangeTablePtr tblPtr = VI_NULL;
    ViInt32          measFunc;
	ViInt32 	     model  = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));  
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	
	if(IS_EDU34450A(model))
	{
		switch (measFunc)
	    {
	    case AG3446X_VAL_DC_VOLTS:
			tblPtr = &attrRangeDCVoltageEDU34450ARangeTable;
	        break;
			
	    case AG3446X_VAL_AC_VOLTS:
	        tblPtr = &attrRangeACVoltageEDU34450ARangeTable;
	        break;

	    case AG3446X_VAL_DC_CURRENT:
		case AG3446X_VAL_AC_CURRENT:
	        tblPtr = &attrRangeCurrentEDU34450ARangeTable;
	        break;

	    case AG3446X_VAL_2_WIRE_RES:
	    case AG3446X_VAL_4_WIRE_RES:
	        tblPtr = &attrRangeResistanceEDU34450ARangeTable;
	        break;
		
		case AG3446X_VAL_CAPACITANCE:
			tblPtr = &attrRangeCapacitanceEDU34450ARangeTable;
			break;

	    case AG3446X_VAL_FREQ:
	    case AG3446X_VAL_TEMPERATURE:
	    case AG3446X_VAL_CONTINUITY:
	    case AG3446X_VAL_DIODE:
	        tblPtr = &attrRangeDefaultRangeTable;
	        break;

	    default:
	        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION,
	                        "Invalid measurement function.");
	        break;
	    }	
	}
	
	else
		{	
			switch (measFunc)
		    {
		    case AG3446X_VAL_DC_VOLTS:
		    case AG3446X_VAL_AC_VOLTS:
		    case AG3446X_VAL_DC_VOLTS_RATIO:
		        tblPtr = &attrRangeVoltageRangeTable;
		        break;
		    case AG3446X_VAL_DC_CURRENT:
		    case AG3446X_VAL_AC_CURRENT:
		        tblPtr = &attrRangeCurrentRangeTable;
		        break;
		    case AG3446X_VAL_2_WIRE_RES:
		    case AG3446X_VAL_4_WIRE_RES:
		        tblPtr = &attrRangeResistanceRangeTable;
		        break;
			case AG3446X_VAL_CAPACITANCE:
				tblPtr = &attrRangeCapacitanceRangeTable;
				break;
		    case AG3446X_VAL_FREQ:
		    case AG3446X_VAL_PERIOD:
		    case AG3446X_VAL_TEMPERATURE:
		    case AG3446X_VAL_CONTINUITY:
		    case AG3446X_VAL_DIODE:
		        tblPtr = &attrRangeDefaultRangeTable;
		        break;
		    default:
		        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION,
		                        "Invalid measurement function.");
		        break;
		    }
		}	

Error:
    *rangeTablePtr = tblPtr;
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrRange_WriteCallback (ViSession vi,
                                                         ViSession io,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "VOLT:DC:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "VOLT:DC:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "VOLT:DC:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
			viCheckErr (viPrintf (io, "VOLT:DC:RANG %lf;", value));
        break;

    case AG3446X_VAL_AC_VOLTS:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "VOLT:AC:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "VOLT:AC:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "VOLT:AC:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
			viCheckErr (viPrintf (io, "VOLT:AC:RANG %lf;", value));
        break;

    case AG3446X_VAL_DC_CURRENT:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "CURR:DC:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "CURR:DC:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "CURR:DC:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
            viCheckErr (viPrintf (io, "CURR:DC:RANG %lf;", value));
        break;

    case AG3446X_VAL_AC_CURRENT:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "CURR:AC:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "CURR:AC:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "CURR:AC:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
			viCheckErr (viPrintf (io, "CURR:AC:RANG %lf;", value));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "RES:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "RES:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "RES:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
			viCheckErr (viPrintf (io, "RES:RANG %lf;", value));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "FRES:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "FRES:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "FRES:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
			viCheckErr (viPrintf (io, "FRES:RANG %lf;", value));
        break;
	
	case AG3446X_VAL_CAPACITANCE:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "CAP:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "CAP:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "CAP:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
			viCheckErr (viPrintf (io, "CAP:RANG %lf;", value));
        break;

    case AG3446X_VAL_FREQ:
    case AG3446X_VAL_PERIOD:
    case AG3446X_VAL_TEMPERATURE:
    case AG3446X_VAL_CONTINUITY:
    case AG3446X_VAL_DIODE:
        break;      /*No explicit range for temperature measurements.*/
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrRange_ReadCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;
    ViInt32  autoRange;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viQueryf (io, "VOLT:DC:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "VOLT:DC:RANG?", "%lf", value));
        break;

    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viQueryf (io, "VOLT:AC:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "VOLT:AC:RANG?", "%lf", value));
        break;

    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:DC:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "CURR:DC:RANG?", "%lf", value));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:AC:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "CURR:AC:RANG?", "%lf", value));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viQueryf (io, "RES:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "RES:RANG?", "%lf", value));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viQueryf (io, "FRES:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "FRES:RANG?", "%lf", value));
        break;
		
    case AG3446X_VAL_CAPACITANCE:
        viCheckErr (viQueryf (io, "CAP:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "CAP:RANG?", "%lf", value));
        break;

    case AG3446X_VAL_FREQ:
    case AG3446X_VAL_PERIOD:
    case AG3446X_VAL_TEMPERATURE:
    case AG3446X_VAL_CONTINUITY:
    case AG3446X_VAL_DIODE:
        *value = AG3446X_VAL_AUTO_RANGE_ON;
        break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrRange_CheckCallback (ViSession vi,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model)); 

	if(IS_EDU34450A(model) && (value == AG3446X_VAL_AUTO_RANGE_ONCE))
	{
		viCheckErrElab (IVI_ERROR_FUNCTION_NOT_SUPPORTED, "This parameter not supported for EDU34450A.");
	}
	
Error:
	return error;
}

/*- AG3446X_ATTR_AUTO_RANGE_VALUE -*/

static ViStatus _VI_FUNC ag3446xAttrAutoRangeValue_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 *value)
{
    return ag3446x_GetActualRange (vi, io, value);
}

/*- AG3446X_ATTR_RESOLUTION_ABSOLUTE -*/

static ViStatus _VI_FUNC ag3446xAttrResolutionAbsolute_CheckCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 range;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
    checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, &range));

	if(IS_EDU34450A(model) && !(value == AG3446X_VAL_SLOW  || value == AG3446X_VAL_MEDIUM || value == AG3446X_VAL_FAST))
	    viCheckErrElab (IVI_ERROR_INVALID_VALUE, "EDU34450A supports only SLOW, MEDIUM, FAST parameters");
		
    if (range == AG3446X_VAL_AUTO_RANGE_ON)
        viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Cannot set resolution when the DMM is auto-ranging.");

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrResolutionAbsolute_WriteCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 range, resFactor;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, &range));
	
	if(IS_EDU34450A(model))
		resFactor = value;
	else
		resFactor = value / range;
	
	checkErr (Ivi_SetAttributeViReal64 (vi, channelName, AG3446X_ATTR_RESOLUTION, 0, resFactor));

Error:														
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrResolutionAbsolute_ReadCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViReal64 *value)
{
	ViStatus error = VI_SUCCESS;
    ViReal64 range, resFactor;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;

    checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, &range));
	checkErr (Ivi_GetAttributeViReal64 (vi, channelName, AG3446X_ATTR_RESOLUTION, 0, &resFactor));

	if(IS_EDU34450A(model))
		*value = resFactor;
	else
		*value = resFactor * range;  

Error:
    return error;
}

static IviRangeTableEntry attrResolutionEDU34450ARangeTableEntries[] =
	{
		{AG3446X_VAL_SLOW, 0, 0, "SLOW", 0},
		{AG3446X_VAL_MEDIUM, 0, 0, "MED", 0},
		{AG3446X_VAL_FAST, 0, 0, "FAST", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrResolutionEDU34450ARangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrResolutionEDU34450ARangeTableEntries,
	};

/*- AG3446X_ATTR_TRIGGER_SOURCE -*/

static IviRangeTableEntry attrTriggerSourceRangeTableEntries[] =
{
    { AG3446X_VAL_IMMEDIATE,     0, 0, "IMM", 0 },
    { AG3446X_VAL_EXTERNAL,      0, 0, "EXT", 0 },
    { AG3446X_VAL_SOFTWARE_TRIG, 0, 0, "BUS", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};
static IviRangeTable      attrTriggerSourceRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_FALSE,
    VI_FALSE,
    VI_NULL,
    attrTriggerSourceRangeTableEntries,
};

static IviRangeTableEntry attrTriggerSource34465RangeTableEntries[] =
{
	{AG3446X_VAL_IMMEDIATE, 0, 0, "IMM", 0},
	{AG3446X_VAL_EXTERNAL, 0, 0, "EXT", 0},
	{AG3446X_VAL_SOFTWARE_TRIG, 0, 0, "BUS", 0},
	{AG3446X_VAL_INTERNAL, 0, 0, "INT", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerSource34465RangeTable =
{
	IVI_VAL_DISCRETE,
    VI_FALSE,
    VI_FALSE,
    VI_NULL,
    attrTriggerSource34465RangeTableEntries,
};

static IviRangeTableEntry attrTriggerSourceEDU344520ARangeTableEntries[] =
{
	{AG3446X_VAL_IMMEDIATE, 0, 0, "IMM", 0},
	{AG3446X_VAL_SOFTWARE_TRIG, 0, 0, "BUS", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerSourceEDU344520ARangeTable =
{
	IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerSourceEDU344520ARangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrTriggerSource_RangeTableCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	ViInt32		option = 0;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_OPTION, 0, &option)); 
	
    if(IS_EDU34450A(model))
	{
		tblPtr = &attrTriggerSourceEDU344520ARangeTable; 
	}
	
	else if ((IS_34465A(model) || IS_34470A(model)) && IS_DIG_INSTALLED(option))
	{
		tblPtr = &attrTriggerSource34465RangeTable;
	}
	else
	{
		tblPtr = &attrTriggerSourceRangeTable;
	}

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

/*- AG3446X_ATTR_MODEL -*/

static IviRangeTableEntry attrModelEntries[] =
	{
		{AG3446X_VAL_MODEL_34460A, 0, 0, "", 0},
		{AG3446X_VAL_MODEL_34461A, 0, 0, "", 0},
		{AG3446X_VAL_MODEL_34465A, 0, 0, "", 0},
		{AG3446X_VAL_MODEL_34470A, 0, 0, "", 0},
		{AG3446X_VAL_MODEL_EDU34450A, 0, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrModel =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrModelEntries,
	};

/*- AG3446X_ATTR_AC_MIN_FREQ -*/

static IviRangeTableEntry attrAcMinFreqRangeTableEntries[] =
{
    { 200.0, 300000.0, 200.0, "", 0 },
    {  20.0,    200.0,  20.0, "", 0 },
    {   3.0,     20.0,   3.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrAcMinFreqRangeTable =
{
    IVI_VAL_COERCED,
    VI_TRUE,
    VI_FALSE,
    VI_NULL,
    attrAcMinFreqRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrAcMinFreq_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viPrintf (io, "VOLT:AC:BAND %lf;", value));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:AC:BAND %lf;", value));
        break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrAcMinFreq_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viQueryf (io, "VOLT:AC:BAND?", "%lf", value));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:AC:BAND?", "%lf", value));
        break;
    }

Error:
    return error;
}

/*- AG3446X_ATTR_AC_MAX_FREQ -*/

static IviRangeTableEntry attrAcMaxFreqRangeTableEntries[] =
{
    { 3.0, 300000.0, 300000.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrAcMaxFreqRangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrAcMaxFreqRangeTableEntries,
};

/*- AG3446X_ATTR_FREQ_VOLTAGE_RANGE -*/

static IviRangeTableEntry attrFreqVoltageRangeRangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   AG3446X_VAL_AUTO_RANGE_ON,   "", 0 },
    { AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  AG3446X_VAL_AUTO_RANGE_OFF,  "", 0 },
    { AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, AG3446X_VAL_AUTO_RANGE_ONCE, "", 0 },
    {                         0.0,                         0.1,                         0.1, "", 0 },
    {                         0.1,                         1.0,                         1.0, "", 0 },
    {                         1.0,                        10.0,                        10.0, "", 0 },
    {                        10.0,                       100.0,                       100.0, "", 0 },
    {                       100.0,                      1000.0,                      1000.0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrFreqVoltageRangeRangeTable =
{
    IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrFreqVoltageRangeRangeTableEntries,
};

static IviRangeTableEntry attrFreqVoltageRangeEDU34450ARangeTableEntries[] =
	{
		{AG3446X_VAL_AUTO_RANGE_ON, AG3446X_VAL_AUTO_RANGE_ON, AG3446X_VAL_AUTO_RANGE_ON, "", 0},
		{AG3446X_VAL_AUTO_RANGE_OFF, AG3446X_VAL_AUTO_RANGE_OFF, AG3446X_VAL_AUTO_RANGE_OFF, "", 0},
		{0.1, 1.0, 1.0, "", 0},
		{1.0, 10.0, 10.0, "", 0},
		{10.0, 100.0, 100.0, "", 0},
		{100.0, 750.0, 750.0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrFreqVoltageRangeEDU34450ARangeTable =
	{
		IVI_VAL_COERCED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrFreqVoltageRangeEDU34450ARangeTableEntries,
	};
	
static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_RangeTableCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = -1;
	
	checkErr (Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

	if(IS_EDU34450A(model))
	{
	   tblPtr=&attrFreqVoltageRangeEDU34450ARangeTable;
	}
	else
	{
	   tblPtr=&attrFreqVoltageRangeRangeTable;
	}
	
Error:
	*rangeTablePtr = tblPtr;
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_FREQ:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "FREQ:VOLT:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "FREQ:VOLT:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "FREQ:VOLT:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
            viCheckErr (viPrintf (io, "FREQ:VOLT:RANG %lf;", value));
        break;

    case AG3446X_VAL_PERIOD:
        if (value == AG3446X_VAL_AUTO_RANGE_ON)
            viCheckErr (viPrintf (io, "PER:VOLT:RANG:AUTO ON;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_OFF)
            viCheckErr (viPrintf (io, "PER:VOLT:RANG:AUTO OFF;"));
        else if (value == AG3446X_VAL_AUTO_RANGE_ONCE)
            viCheckErr (viPrintf (io, "PER:VOLT:RANG:AUTO ONCE;"));
        else      /* Writing an explicit range turns off auto ranging. */
            viCheckErr (viPrintf (io, "PER:VOLT:RANG %lf;", value));
        break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;
    ViInt32  autoRange;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_FREQ:
        viCheckErr (viQueryf (io, "FREQ:VOLT:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "FREQ:VOLT:RANG?", "%lf", value));
        break;

    case AG3446X_VAL_PERIOD:
        viCheckErr (viQueryf (io, "PER:VOLT:RANG:AUTO?", "%d", &autoRange));
        if (autoRange)
            *value = AG3446X_VAL_AUTO_RANGE_ON;
        else
            viCheckErr (viQueryf (io, "PER:VOLT:RANG?", "%lf", value));
        break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrFreqVoltageRange_CheckCallback (ViSession vi,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model) && value == AG3446X_VAL_AUTO_RANGE_ONCE)
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The instrument model is does not support Auto range ONCE");	

Error:
	return error;
}

/*- AG3446X_ATTR_TEMP_TRANSDUCER_TYPE -*/

static IviRangeTableEntry attrTempTransducerTypeRangeTableEntries[] =
{
	{AG3446X_VAL_THERMOCOUPLE, 0, 0, "TC", 0},
	{AG3446X_VAL_2_WIRE_RTD, 0, 0, "RTD", 0},
	{AG3446X_VAL_4_WIRE_RTD, 0, 0, "FRTD", 0},
	{AG3446X_VAL_2_WIRE_THER, 0, 0, "THER", 0},
	{AG3446X_VAL_4_WIRE_THER, 0, 0, "FTH", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTempTransducerTypeRangeTable =
{
	IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTempTransducerTypeRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrTempTransducerType_CheckCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 value)
{
	ViStatus	error = VI_SUCCESS;
	
	if (value == AG3446X_VAL_THERMOCOUPLE)
	{
		ViInt32 model = AG3446X_VAL_MODEL_UNKNOWN;
		
		checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
			
		if (!IS_34465A(model) && !IS_34470A(model))
		{
			viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument model is not supported");
		}
	}

Error:
	return error;
}

/* AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC */

static IviRangeTableEntry attrTempTcFixedRefJuncRangeTableEntries[] =
{
	{-20, 80, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTempTcFixedRefJuncRangeTable = 
{
	IVI_VAL_RANGED,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrTempTcFixedRefJuncRangeTableEntries,
};

/* AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE */  

static IviRangeTableEntry attrTempTcRefJuncTypeRangeTableEntries[] =
{
	{AG3446X_VAL_TEMP_REF_JUNC_INTERNAL, 0, 0, "INT", 0},
	{AG3446X_VAL_TEMP_REF_JUNC_FIXED, 0, 0, "FIX", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTempTcRefJuncTypeRangeTable = 
{
	IVI_VAL_DISCRETE,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrTempTcRefJuncTypeRangeTableEntries,
};

static IviRangeTableEntry attrTempTcRefJuncOffsAdjRangeTableEntries[] =
{
	{-20, 20, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

/* AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ */

static IviRangeTable attrTempTcRefJuncOffsAdjRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTempTcRefJuncOffsAdjRangeTableEntries,
};

/* AG3446X_ATTR_TEMP_TC_TYPE */ 

static IviRangeTableEntry attrTempTcTypeRangeTableEntries[] =
{
	{AG3446X_VAL_TEMP_TC_E, 0, 0, "E", 0},
	{AG3446X_VAL_TEMP_TC_J, 0, 0, "J", 0},
	{AG3446X_VAL_TEMP_TC_K, 0, 0, "K", 0},
	{AG3446X_VAL_TEMP_TC_N, 0, 0, "N", 0},
	{AG3446X_VAL_TEMP_TC_R, 0, 0, "R", 0},
	{AG3446X_VAL_TEMP_TC_T, 0, 0, "T", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTempTcTypeRangeTable = 
{
	IVI_VAL_DISCRETE,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrTempTcTypeRangeTableEntries,
};

/*- AG3446X_ATTR_TEMP_RTD_ALPHA -*/

static IviRangeTableEntry attrTempRtdAlphaRangeTableEntries[] =
{
    { 85, 85, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrTempRtdAlphaRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTempRtdAlphaRangeTableEntries,
};

/*- AG3446X_ATTR_TEMP_RTD_RES -*/

static IviRangeTableEntry attrTempRtdResRangeTableEntries[] =
{
    { 80.0, 120.0, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrTempRtdResRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTempRtdResRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrTempRtdRes_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  tempType;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TEMP_TRANSDUCER_TYPE, 0, &tempType));

    switch (tempType)
    {
    case AG3446X_VAL_2_WIRE_RTD:
        viCheckErr (viPrintf (io, "TEMP:TRAN:RTD:RES %le;", value));
        break;

    case AG3446X_VAL_4_WIRE_RTD:
        viCheckErr (viPrintf (io, "TEMP:TRAN:FRTD:RES %le;", value));
        break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrTempRtdRes_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  tempType;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_TEMP_TRANSDUCER_TYPE, 0, &tempType));

    switch (tempType)
    {
    case AG3446X_VAL_2_WIRE_RTD:
        viCheckErr (viQueryf (io, "TEMP:TRAN:RTD:RES?", "%le", value));
        break;

    case AG3446X_VAL_4_WIRE_RTD:
        viCheckErr (viPrintf (io, "TEMP:TRAN:FRTD:RES?", "%le", value));
        break;
    }

Error:
    return error;
}


/*- AG3446X_ATTR_TEMP_THERMISTOR_RES -*/

static IviRangeTableEntry attrTempThermistorResRangeTableEntries[] =
{
    { 5000, 5000, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrTempThermistorResRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTempThermistorResRangeTableEntries,
};



/*- AG3446X_ATTR_APERTURE_TIME -*/

static ViStatus _VI_FUNC ag3446xAttrApertureTime_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
 	ViInt32	apertureTimeUnit = AG3446X_VAL_POWER_LINE_CYCLES;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(!IS_EDU34450A(model))
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_APERTURE_TIME_UNITS, 0, &apertureTimeUnit));
	
	if (IS_EDU34450A(model) || apertureTimeUnit == AG3446X_VAL_SECONDS)
	{
		checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_APERTURE_TIME_SECONDS, 0, value));
	}
	else
	{
		checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_APERTURE_TIME_NPLC, 0, value));	
	}

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTime_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
 	ViInt32	 apertureTimeUnit = AG3446X_VAL_POWER_LINE_CYCLES;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(!IS_EDU34450A(model))
		checkErr( Ivi_GetAttributeViInt32 (vi, channelName, AG3446X_ATTR_APERTURE_TIME_UNITS, 0, &apertureTimeUnit));
	
	if (IS_EDU34450A(model) || apertureTimeUnit == AG3446X_VAL_SECONDS)
	{
		checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_APERTURE_TIME_SECONDS, 0, value));
	}
	else
	{
		checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_APERTURE_TIME_NPLC, 0, value));	
	}

Error:
    return error;
}

/*- AG3446X_ATTR_APERTURE_TIME_UNITS -*/

static IviRangeTableEntry attrApertureTimeUnitsRangeTableEntries[] =
{
    { AG3446X_VAL_SECONDS,           0, 0, "", 0 },
    { AG3446X_VAL_POWER_LINE_CYCLES, 0, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrApertureTimeUnitsRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeUnitsRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrApertureTimeUnits_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViInt32 *value)
{
	ViStatus	error = VI_SUCCESS;
    ViInt32  	measFunc;
	ViBoolean   apertureEnabled = VI_FALSE;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));	
	
	switch(measFunc)
	{
		case AG3446X_VAL_DC_VOLTS:
			viCheckErr (viQueryf (io, "VOLT:APER:ENAB?", "%d", &apertureEnabled));
			break;
		case AG3446X_VAL_DC_CURRENT:
			viCheckErr (viQueryf (io, "CURR:APER:ENAB?", "%d", &apertureEnabled));   
			break;
		case AG3446X_VAL_TEMPERATURE:
			viCheckErr (viQueryf (io, "TEMP:APER:ENAB?", "%d", &apertureEnabled));  
			break;	
		case AG3446X_VAL_2_WIRE_RES:
			viCheckErr (viQueryf (io, "RES:APER:ENAB?", "%d", &apertureEnabled));  
			break;
		case AG3446X_VAL_4_WIRE_RES:
			viCheckErr (viQueryf (io, "FRES:APER:ENAB?", "%d", &apertureEnabled));  
			break;	
		default:
			viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Measurement function is not set to 2-wire or 4-wire resistance measurement."); 
			break;
	}

Error:
	*value = apertureEnabled ? AG3446X_VAL_SECONDS : AG3446X_VAL_POWER_LINE_CYCLES;  
	
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTimeUnits_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViInt32 value)
{
	ViStatus	error = VI_SUCCESS;
    ViInt32  	measFunc;
	ViBoolean 	apertureEnabled;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	
	apertureEnabled = (value == AG3446X_VAL_SECONDS);
	
	switch(measFunc)
	{
		case AG3446X_VAL_DC_VOLTS:
			viCheckErr (viPrintf (io, "VOLT:APER:ENAB %d;", apertureEnabled));
			break;
		case AG3446X_VAL_DC_CURRENT:
			viCheckErr (viPrintf (io, "CURR:APER:ENAB %d;", apertureEnabled));  
			break;
		case AG3446X_VAL_TEMPERATURE:
			viCheckErr (viPrintf (io, "TEMP:APER:ENAB %d;", apertureEnabled));  
			break;	
		case AG3446X_VAL_2_WIRE_RES:
			viCheckErr (viPrintf (io, "RES:APER:ENAB %d;", apertureEnabled));  
			break;
		case AG3446X_VAL_4_WIRE_RES:
			viCheckErr (viPrintf (io, "FRES:APER:ENAB %d;", apertureEnabled));  
			break;	
		default:
			viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Measurement function is not set to 2-wire or 4-wire resistance measurement."); 
			break;
	}

Error:
	return error;
}

/*- AG3446X_ATTR_AUTO_ZERO -*/

static IviRangeTableEntry attrAutoZeroRangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_ZERO_OFF,  0, 0, "OFF",  0 },
    { AG3446X_VAL_AUTO_ZERO_ON,   0, 0, "ON",   0 },
    { AG3446X_VAL_AUTO_ZERO_ONCE, 0, 0, "ONCE", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrAutoZeroRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrAutoZeroRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrAutoZero_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measType;
    ViString cmd;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measType));
    ag3446x_GetCmdFromIntValue (value, &attrAutoZeroRangeTable, &cmd);

    switch (measType)
    {
    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viPrintf (io, "VOLT:ZERO:AUTO %s;", cmd));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viPrintf (io, "TEMP:ZERO:AUTO %s;", cmd));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viPrintf (io, "RES:ZERO:AUTO %s;", cmd));
        break;

    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:ZERO:AUTO %s;", cmd));
        break;
		
	default:
		viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Auto zero is not valid for the current measurement function.");
		break;
    }


Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrAutoZero_ReadCallback (ViSession vi,
                                                           ViSession io,
                                                           ViConstString channelName,
                                                           ViAttr attributeId,
                                                           ViInt32 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measType;
    ViInt32  result = 0;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measType));

    switch (measType)
    {
    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viQueryf (io, "VOLT:ZERO:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viPrintf (io, "TEMP:ZERO:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viPrintf (io, "RES:ZERO:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:ZERO:AUTO?", "%ld", &result));
        break;
		
	default:
		viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Auto zero is not valid for the current measurement function.");
		break;
    }
																				  
    if (result)
        *value = AG3446X_VAL_AUTO_ZERO_ON;
    else
        *value = AG3446X_VAL_AUTO_ZERO_OFF;

Error:
    return error;
}

/*- AG3446X_ATTR_AVER_ENABLED -*/ 

static ViStatus _VI_FUNC ag3446xAttrAverEnabled_WriteCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
	{	
		viCheckErr (viPrintf (io, "CALC:FUNC AVER"));
		viCheckErr (viPrintf (io, "CALC:STAT %d", value));
	}
	else
		viCheckErr (viPrintf (io, "CALC:AVER %d", value));

Error:
	return error;
}

/*- AG3446X_ATTR_SAMPLE_COUNT -*/

static IviRangeTableEntry attrSampleCountRangeTableEntries[] =
{
    { 1, 1000000, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrSampleCountRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrSampleCountRangeTableEntries,
};

static IviRangeTableEntry attrSampleCount34465RangeTableEntries[] =
{
	{1, 1000000000, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrSampleCount34465RangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrSampleCount34465RangeTableEntries,
};


static IviRangeTableEntry attrCountEDU34450ARangeTableEntries[] =
{
	{1, 5000, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}									   
};

static IviRangeTable attrCountEDU34450ARangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrCountEDU34450ARangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrSampleCount_RangeTableCallback (ViSession vi,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32		model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
    if(IS_EDU34450A(model))
	{
		tblPtr = &attrCountEDU34450ARangeTable;  	
	}
	
	else if (IS_34465A(model) || IS_34470A(model))
	{
		tblPtr = &attrSampleCount34465RangeTable;
	}

	else
	{
		tblPtr = &attrSampleCountRangeTable;
	}
Error:
	*rangeTablePtr = tblPtr;
	return error;
}

/* AG3446X_ATTR_SAMPLE_TRIGGER */
/* use common read callback ag3446xEnum_ReadCallback */				      
		
/* use common write callback ag3446xEnum_WriteCallback */
static IviRangeTableEntry attrSampleTriggerRangeTableEntries[] =
{
	{AG3446X_VAL_IMMEDIATE, 0, 0, "IMM", 0},
	{AG3446X_VAL_TIMER, 0, 0, "TIM", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrSampleTriggerRangeTable =
{
	IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrSampleTriggerRangeTableEntries,
};


/*- AG3446X_ATTR_SAMPLE_INTERVAL -*/

static IviRangeTableEntry attrSampleIntervalRangeTableEntries[] =
{
	{0, 3600, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrSampleIntervalRangeTable =
{
	IVI_VAL_RANGED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrSampleIntervalRangeTableEntries,
};

static IviRangeTableEntry attrSampleIntervalEDU34450ARangeTableEntries[] =
{
	{0.01, 3600, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrSampleIntervalEDU34450ARangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrSampleIntervalEDU34450ARangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrSampleInterval_RangeTableCallback (ViSession vi,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32	 model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr (Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
	{
		tblPtr=&attrSampleIntervalEDU34450ARangeTable;
	}
	else
	{
		tblPtr=&attrSampleIntervalRangeTable;
	}
   
Error:
	*rangeTablePtr = tblPtr;
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrSampleInterval_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViReal64	minValue = 0;
	
	checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_SAMPLE_INTERVAL_MIN, 0, &minValue));
																				
	if (value < minValue)
	{
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The value should be greater than or equal to the lower range.");   	
	}
	
	checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));  

Error:
	return error;
}
          
static ViStatus _VI_FUNC ag3446xSampleInterval_CoerceCallback (ViSession vi,
                                                               ViConstString channelName,
                                                               ViAttr attributeId, 
                                                               ViReal64 value, ViReal64* coercedValue)
{
	/* In 1us steps and coerced to upper. */
	*coercedValue = ceil(value * 1000000) / 1000000; 

    return VI_SUCCESS;
}

/*- AG3446X_ATTR_TRIGGER_COUNT -*/

static IviRangeTableEntry attrTriggerCountRangeTableEntries[] =
{
    { 1, 1000000, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrTriggerCountRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerCountRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrTriggerCount_RangeTableCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
	{	
		tblPtr=&attrCountEDU34450ARangeTable;
	}	
	else
	{
	 	tblPtr=&attrTriggerCountRangeTable;    
	}

Error:
	*rangeTablePtr = tblPtr;
	return error;
}


/*- AG3446X_ATTR_TRIGGER_DELAY -*/

static IviRangeTableEntry attrTriggerDelayRangeTableEntries[] =
{
    { AG3446X_VAL_AUTO_DELAY_OFF, AG3446X_VAL_AUTO_DELAY_OFF, 0, "OFF", 0 },
    { AG3446X_VAL_AUTO_DELAY_ON,  AG3446X_VAL_AUTO_DELAY_ON,  0, "ON",  0 },
    {                        0.0,                     3600.0, 0, "",    0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrTriggerDelayRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerDelayRangeTableEntries,
};

static IviRangeTableEntry attrTriggerDelayEDU34450ARangeTableEntries[] =
{
	{0.0, 3600.0, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerDelayEDU34450ARangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerDelayEDU34450ARangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_RangeTableCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	if(IS_EDU34450A(model))
	{
		tblPtr=&attrTriggerDelayEDU34450ARangeTable;
	}
	else
	{
		tblPtr=&attrTriggerDelayRangeTable;
	}
	
Error:
	*rangeTablePtr = tblPtr;
	return error;
}


static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    if (value == AG3446X_VAL_AUTO_DELAY_ON)
        viCheckErr (viPrintf (io, "TRIG:DEL:AUTO ON;"));
    else if (value == AG3446X_VAL_AUTO_DELAY_OFF)
        viCheckErr (viPrintf (io, "TRIG:DEL:AUTO OFF;"));
    else
        viCheckErr (viPrintf (io, "TRIG:DEL %lf;", value));

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  autodel;
	ViInt32 model  = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

    if(IS_EDU34450A(model)) 
		viCheckErr (viQueryf (io, "TRIG:DEL?", "%lf", value));  
	else
	{
		viCheckErr (viQueryf (io, "TRIG:DEL:AUTO?", "%ld", &autodel));
    	if (autodel)
        	*value = AG3446X_VAL_AUTO_DELAY_ON;
		else
			viCheckErr (viQueryf (io, "TRIG:DEL?", "%lf", value));	
    }


Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerDelay_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model)); 
	
	if(IS_EDU34450A(model) && (value == AG3446X_VAL_AUTO_DELAY_ON || value == AG3446X_VAL_AUTO_DELAY_OFF))
	{
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Auto Trigger Delay parameter not supported for the current model");
	}
Error:
	return error;
}

/*- AG3446X_ATTR_TRIGGER_SLOPE -*/

static IviRangeTableEntry attrTriggerSlopeRangeTableEntries[] =
{
    { AG3446X_VAL_POSITIVE, 0, 0, "POS", 0 },
    { AG3446X_VAL_NEGATIVE, 0, 0, "NEG", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};
static IviRangeTable      attrTriggerSlopeRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_FALSE,
    VI_FALSE,
    VI_NULL,
    attrTriggerSlopeRangeTableEntries,
};

/* AG3446X_ATTR_VOLT_AUTO_IMPEDANCE */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

static IviRangeTableEntry attrCurrentTerminalRangeTableEntries[] =
{
    { AG3446X_VAL_CURR_TERM_3,  0, 0, "", 0 },
    { AG3446X_VAL_CURR_TERM_10, 0, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrCurrentTerminalRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrCurrentTerminalRangeTableEntries,
};

/* AG3446X_ATTR_CURR_TERMINAL */
static ViStatus _VI_FUNC ag3446xAttrCurrTerminal_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViInt32 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:DC:TERM?", "%ld", value));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:AC:TERM?", "%ld", value));
        break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrCurrTerminal_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViInt32 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;
    ViInt32  model;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        if (IS_34461A(model) || IS_34465A(model) || IS_34470A(model))
            viCheckErr (viPrintf (io, "CURR:DC:TERM %ld;", value));
        else if (IS_34460A(model))
            viCheckErr (viPrintf (io, "CURR:DC:TERM 3;"));
        else
            viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument model is not supported");
        break;

    case AG3446X_VAL_AC_CURRENT:
        if (IS_34461A(model) || IS_34465A(model) || IS_34470A(model)) 
            viCheckErr (viPrintf (io, "CURR:AC:TERM %ld;", value));
        else if (IS_34460A(model))
            viCheckErr (viPrintf (io, "CURR:AC:TERM 3;"));
        else
            viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument model is not supported");
        break;
    }

Error:
    return error;
}

/* AG3446X_ATTR_NULL_AUTO_ENABLED */
static ViStatus _VI_FUNC ag3446xAttrNullAutoEnable_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViBoolean *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;
    ViInt32  result = 0;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:DC:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:AC:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_FREQ:
        viCheckErr (viQueryf (io, "FREQ:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_PERIOD:
        viCheckErr (viQueryf (io, "PER:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viQueryf (io, "RES:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viQueryf (io, "FRES:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viQueryf (io, "TEMP:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viQueryf (io, "VOLT:DC:NULL:VALUE:AUTO?", "%ld", &result));
        break;

    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viQueryf (io, "VOLT:AC:NULL:VALUE:AUTO?", "%ld", &result));
        break;
	case AG3446X_VAL_CAPACITANCE:
		viCheckErr (viQueryf (io, "CAP:NULL:VALUE:AUTO?", "%ld", &result));
        break;
    }

    if (result)
        *value = VI_TRUE;
    else
        *value = VI_FALSE;

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrNullAutoEnable_WriteCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViBoolean value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:DC:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:AC:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_FREQ:
        viCheckErr (viPrintf (io, "FREQ:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_PERIOD:
        viCheckErr (viPrintf (io, "PER:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viPrintf (io, "RES:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viPrintf (io, "FRES:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viPrintf (io, "TEMP:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viPrintf (io, "VOLT:DC:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viPrintf (io, "VOLT:AC:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
        break;
	case AG3446X_VAL_CAPACITANCE:
		viCheckErr (viPrintf (io, "CAP:NULL:VALUE:AUTO %s;", value ? "ON" : "OFF"));
		break;
    }

Error:
    return error;
}

/* AG3446X_ATTR_NULL_VALUE */   

static IviRangeTableEntry attrNullCurrentValueRangeTableEntries[] =
{
    { -12, 12, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrNullCurrentValueRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrNullCurrentValueRangeTableEntries,
};

static IviRangeTableEntry attrNullFrequencyValueRangeTableEntries[] =
{
    { -1.2E6, 1.2E6, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrNullFrequencyValueRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrNullFrequencyValueRangeTableEntries,
};

static IviRangeTableEntry attrNullResistanceValueRangeTableEntries[] =
{
    { -1.2E8, 1.2E8, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrNullResistanceValueRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrNullResistanceValueRangeTableEntries,
};

static IviRangeTableEntry attrNullTemperatureValueRangeTableEntries[] =
{
    { -1.0E15, 1.0E15, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrNullTemperatureValueRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrNullTemperatureValueRangeTableEntries,
};

static IviRangeTableEntry attrNullVoltageValueRangeTableEntries[] =
{
    { -1200, 1200, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrNullVoltageValueRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrNullVoltageValueRangeTableEntries,
};

static IviRangeTableEntry attrNullCapacitanceValueRangeTableEntries[] =
{
	{-120, 120, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrNullCapacitanceValueRangeTable = 
{
	IVI_VAL_RANGED,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrNullCapacitanceValueRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrNullValue_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:DC:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:AC:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_FREQ:
        viCheckErr (viQueryf (io, "FREQ:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_PERIOD:
        viCheckErr (viQueryf (io, "PER:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viQueryf (io, "RES:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viQueryf (io, "FRES:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viQueryf (io, "TEMP:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viQueryf (io, "VOLT:DC:NULL:VALUE?", "%lf", value));
        break;

    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viQueryf (io, "VOLT:AC:NULL:VALUE?", "%lf", value));
        break;
	case AG3446X_VAL_CAPACITANCE:
		viCheckErr (viQueryf (io, "CAP:NULL:VALUE?", "%lf", value));
		break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrNullValue_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:DC:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:AC:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_FREQ:
        viCheckErr (viPrintf (io, "FREQ:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_PERIOD:
        viCheckErr (viPrintf (io, "PER:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viPrintf (io, "RES:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viPrintf (io, "FRES:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viPrintf (io, "TEMP:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viPrintf (io, "VOLT:DC:NULL:VALUE %lf", value));
        break;

    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viPrintf (io, "VOLT:AC:NULL:VALUE %lf", value));
        break;
	case AG3446X_VAL_CAPACITANCE: 
		viCheckErr (viPrintf (io, "CAP:NULL:VALUE %lf", value));   
		break; 
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrNullValue_RangeTableCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  IviRangeTablePtr *rangeTablePtr)
{
    ViStatus         error = VI_SUCCESS;
    ViInt32          measFunc;
    IviRangeTablePtr tblPtr = VI_NULL;


    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
    case AG3446X_VAL_AC_CURRENT:
        tblPtr = &attrNullCurrentValueRangeTable;
        break;

    case AG3446X_VAL_FREQ:
    case AG3446X_VAL_PERIOD:
        tblPtr = &attrNullFrequencyValueRangeTable;
        break;

    case AG3446X_VAL_2_WIRE_RES:
    case AG3446X_VAL_4_WIRE_RES:
        tblPtr = &attrNullResistanceValueRangeTable;
        break;

    case AG3446X_VAL_TEMPERATURE:
        tblPtr = &attrNullTemperatureValueRangeTable;
        break;

    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
    case AG3446X_VAL_AC_VOLTS:
        tblPtr = &attrNullVoltageValueRangeTable;
        break;
	case AG3446X_VAL_CAPACITANCE:
		tblPtr = &attrNullCapacitanceValueRangeTable;
		break;
    }

Error:
    *rangeTablePtr = tblPtr;
    return error;
}


/* AG3446X_ATTR_NULL_ENABLED */
static ViStatus _VI_FUNC ag3446xAttrNullEnable_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;
    ViInt32  result = 0;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:DC:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:AC:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_FREQ:
        viCheckErr (viQueryf (io, "FREQ:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_PERIOD:
        viCheckErr (viQueryf (io, "PER:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viQueryf (io, "RES:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viQueryf (io, "FRES:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viQueryf (io, "TEMP:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viQueryf (io, "VOLT:DC:NULL?", "%ld", &result));
        break;

    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viQueryf (io, "VOLT:AC:NULL?", "%ld", &result));
        break;
	case AG3446X_VAL_CAPACITANCE:
		viCheckErr (viQueryf (io, "CAP:NULL?;", "%ld", &result)); 
		break;
    }

    if (result)
        *value = VI_TRUE;
    else
        *value = VI_FALSE;

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrNullEnable_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:DC:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_AC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:AC:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_FREQ:
        viCheckErr (viPrintf (io, "FREQ:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_PERIOD:
        viCheckErr (viPrintf (io, "PER:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viPrintf (io, "RES:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viPrintf (io, "FRES:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viPrintf (io, "TEMP:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viPrintf (io, "VOLT:DC:NULL %s;", value ? "ON" : "OFF"));
        break;

    case AG3446X_VAL_AC_VOLTS:
        viCheckErr (viPrintf (io, "VOLT:AC:NULL %s;", value ? "ON" : "OFF"));
        break;
	case AG3446X_VAL_CAPACITANCE:
		viCheckErr (viPrintf (io, "CAP:NULL %s;", value ? "ON" : "OFF")); 
		break;
    }

Error:
    return error;
}

static IviRangeTableEntry attrDataPointCount34460RangeTableEntries[] =
{
    { 1, 1000, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrDataPointCount34460RangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrDataPointCount34460RangeTableEntries,
};

static IviRangeTableEntry attrDataPointCount34461RangeTableEntries[] =
{
    { 1, 10000, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrDataPointCount34461RangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrDataPointCount34461RangeTableEntries,
};

static IviRangeTableEntry attrDataPointCount34465MemRangeTableEntries[] =
{
	{1, 2000000, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrDataPointCount34465MemRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrDataPointCount34465MemRangeTableEntries,
};

static IviRangeTableEntry attrDataPointCount34465RangeTableEntries[] =
{
	{1, 50000, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrDataPointCount34465RangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrDataPointCount34465RangeTableEntries,
};

/* AG3446X_ATTR_DATA_POINT_COUNT */
/* use common read callback ag3446xViInt32_ReadCallback */

/* use common write callback ag3446xViInt32_WriteCallback */

static ViStatus _VI_FUNC ag3446xAttrDataPointCount_RangeTableCallback (ViSession vi,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       IviRangeTablePtr *rangeTablePtr)
{
    ViStatus         error = VI_SUCCESS;
    ViInt32          model, options;
    IviRangeTablePtr tblPtr = VI_NULL;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

    if (IS_34460A(model))
    {
        tblPtr = &attrDataPointCount34460RangeTable;
    }
    else if (IS_34461A(model))
    {
        tblPtr = &attrDataPointCount34461RangeTable;
    }
	else if (IS_34465A(model) || IS_34470A(model))
	{
		checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_OPTION, 0, &options)); 
		
		if (IS_MEM_INSTALLED(options))
		{
			tblPtr = &attrDataPointCount34465MemRangeTable;
		}
		else
		{
			tblPtr = &attrDataPointCount34465RangeTable;
		}
	}
    else
    {
        viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument model is not supported.");
    }

Error:
    *rangeTablePtr = tblPtr;
    return error;
}


/* AG3446X_ATTR_AUTO_RECALL_ENABLE */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

/* AG3446X_ATTR_SECURITY_ENABLED */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

/* AG3446X_ATTR_CAL_VALUE */
/* use common read callback ag3446xViReal64_ReadCallback */

/* use common write callback ag3446xViReal64_WriteCallback */

/* AG3446X_ATTR_CAL_STRING */
/* use common read callback ag3446xViString_ReadCallback */

/* use common write callback ag3446xViString_WriteCallback */

/* AG3446X_ATTR_LIMIT_ENABLED */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

static IviRangeTableEntry attrHistRangeRangeTableEntries[] =
{
    { -1.0E+15, -1.0E-15, 0, "", 0 },
    {      0.0,      0.0, 0, "", 0 },
    {  1.0E-15,  1.0E+15, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrHistRangeRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrHistRangeRangeTableEntries,
};

/* AG3446X_ATTR_HIST_LOWER_RANGE */
/* use common read callback ag3446xViReal64_ReadCallback */

/* use common write callback ag3446xViReal64_WriteCallback */

static ViStatus _VI_FUNC ag3446xAttrHistLowerRange_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 upperRange;

    checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_HIST_UPPER_RANGE, 0, &upperRange));

    if (value > upperRange)
    {
        viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The lower range should be less than upper range");
    }

    checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));
Error:
    return error;
}


/* AG3446X_ATTR_HIST_UPPER_RANGE */
/* use common read callback ag3446xViReal64_ReadCallback */

/* use common write callback ag3446xViReal64_WriteCallback */

static ViStatus _VI_FUNC ag3446xAttrHistUpperRange_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 lowerRange;

    checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_HIST_LOWER_RANGE, 0, &lowerRange));

    if (value < lowerRange)
    {
        viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The upper range should be greater than lower range");
    }

    checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));
Error:
    return error;
}


/* AG3446X_ATTR_HIST_ENABLED */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

/* AG3446X_ATTR_HIST_AUTO_RANGE */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

static IviRangeTableEntry attrHistPointRangeTableEntries[] =
{
    { AG3446X_VAL_10,  0, 0, "", 0 },
    { AG3446X_VAL_20,  0, 0, "", 0 },
    { AG3446X_VAL_40,  0, 0, "", 0 },
    { AG3446X_VAL_100, 0, 0, "", 0 },
    { AG3446X_VAL_200, 0, 0, "", 0 },
    { AG3446X_VAL_400, 0, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrHistPointRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrHistPointRangeTableEntries,
};

/* AG3446X_ATTR_HIST_POINT */
/* use common read callback ag3446xViInt32_ReadCallback */

/* use common write callback ag3446xViInt32_WriteCallback */

static IviRangeTableEntry attrLimitRangeTableEntries[] =
{
    { -1.0E+15, -1.0E-15, 0, "", 0 },
    {      0.0,      0.0, 0, "", 0 },
    {  1.0E-15, +1.0E+15, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrLimitRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrLimitRangeTableEntries,
};

static IviRangeTableEntry attrLimitEDU34450ARangeTableEntries[] =
{
    {  -120, +120, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrLimitEDU34450ARangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrLimitEDU34450ARangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrUpperLimit_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	if(IS_EDU34450A(model))
	{
		tblPtr = &attrLimitEDU34450ARangeTable;
	}
	else
	{
		tblPtr = &attrLimitRangeTable;
	}
	  
Error:
	*rangeTablePtr = tblPtr;
	return error;
}


static ViStatus _VI_FUNC ag3446xAttrLowerLimit_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	if(IS_EDU34450A(model))
	{
		tblPtr = &attrLimitEDU34450ARangeTable;
	}
	else
	{
		tblPtr = &attrLimitRangeTable;
	}
	  
Error:
	*rangeTablePtr = tblPtr;
	return error;
}

/* AG3446X_ATTR_LIMIT_ENABLED */

static ViStatus _VI_FUNC ag3446xAttrLimitEnabled_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViBoolean *value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
		viCheckErr (viQueryf (io, "CALC:FUNC?", "%lf", value)); 
	else
		viCheckErr (viQueryf (io, "CALC:LIM?", "%d", value));
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrLimitEnabled_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
	{	
		viCheckErr (viPrintf (io, "CALC:FUNC LIM"));
	    viCheckErr (viPrintf (io, "CALC:STAT %d",value));   
	}
		else
		viCheckErr (viPrintf (io, "CALC:LIM %d", value));
	
Error:													  
	return error;
}


/* AG3446X_ATTR_LOWER_LIMIT */
/* use common read callback ag3446xViReal64_ReadCallback */

/* use common write callback ag3446xViReal64_WriteCallback */

static ViStatus _VI_FUNC ag3446xAttrLowerLimit_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 upperLimit;

    checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, &upperLimit));

    if (value > upperLimit)
    {
        viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The lower limit should be less than upper limit");
    }

    checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));
Error:
    return error;
}


/* AG3446X_ATTR_UPPER_LIMIT */
/* use common read callback ag3446xViReal64_ReadCallback */

/* use common write callback ag3446xViReal64_WriteCallback */

static ViStatus _VI_FUNC ag3446xAttrUpperLimit_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 lowerLimit;

    checkErr (Ivi_GetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_LOWER_LIMIT, 0, &lowerLimit));

    if (value < lowerLimit)
    {
        viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The upper limit should be greater than lower limit");
    }

    checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));
Error:
    return error;
}


/* AG3446X_ATTR_SCALE_ENABLED */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

/* AG3446X_ATTR_AVER_ENABLED */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

/* AG3446X_ATTR_SCALE_AUTO_REFERENCE */
/* use common read callback ag3446xViBoolean_ReadCallback */

/* use common write callback ag3446xViBoolean_WriteCallback */

/* AG3446X_ATTR_SCALE_FUNCTION */


static ViStatus _VI_FUNC ag3446xAttrScaleFunction_ReadCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViInt32 *value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
		viCheckErr (viQueryf (io, "CALC:FUNC?", "%lf", value)); 
	else
		viCheckErr (viQueryf (io, "CALC:SCAL:FUNC?", "%lf", value));
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrScaleFunction_WriteCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViInt32 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
		viCheckErr (viPrintf (io, "CALC:FUNC %s", value));
	else
		viCheckErr (viPrintf (io, "CALC:SCAL:FUNC %s", value));
	
	
Error:
	return error;
}

static IviRangeTableEntry attrScaleFunctionRangeTableEntries[] =
{
    { AG3446X_VAL_SCALE_FUNC_DB,  0, 0, "DB",  0 },
    { AG3446X_VAL_SCALE_FUNC_DBM, 0, 0, "DBM", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrScaleFunctionRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrScaleFunctionRangeTableEntries,
};

static IviRangeTableEntry attrScaleFunction34465RangeTableEntries[] =
	{
		{AG3446X_VAL_SCALE_FUNC_DB, 0, 0, "DB", 0},
		{AG3446X_VAL_SCALE_FUNC_DBM, 0, 0, "DBM", 0},
		{AG3446X_VAL_SCALE_FUNC_PCT, 0, 0, "PCT", 0},
		{AG3446X_VAL_SCALE_FUNC_SCAL, 0, 0, "SCAL", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrScaleFunction34465RangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrScaleFunction34465RangeTableEntries,
	};

static ViStatus _VI_FUNC ag3446xScaleFunction_RangeTableCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId, 
                                                                  IviRangeTablePtr *rangeTablePtr)
{
    ViStatus    error = VI_SUCCESS;
	IviRangeTablePtr tblPtr = VI_NULL; 
	ViInt32  model;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if (IS_EDU34450A(model) || IS_34460A(model) || IS_34461A(model))
	{
		tblPtr = &attrScaleFunctionRangeTable;
	}
	else if(IS_34465A(model) || IS_34470A(model))
	{
		tblPtr = &attrScaleFunction34465RangeTable;
	}
  	else
    {
        viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument model is not supported");
    }

Error:
	*rangeTablePtr = tblPtr;
    return error;
}

static IviRangeTableEntry attrScaleDbmReferenceRangeTableEntries[] =
	{
		{AG3446X_VAL_50, 0, 0, "", 0},
		{AG3446X_VAL_75, 0, 0, "", 0},
		{AG3446X_VAL_93, 0, 0, "", 0},
		{AG3446X_VAL_110, 0, 0, "", 0},
		{AG3446X_VAL_124, 0, 0, "", 0},
		{AG3446X_VAL_125, 0, 0, "", 0},
		{AG3446X_VAL_135, 0, 0, "", 0},
		{AG3446X_VAL_150, 0, 0, "", 0},
		{AG3446X_VAL_250, 0, 0, "", 0},
		{AG3446X_VAL_300, 0, 0, "", 0},
		{AG3446X_VAL_500, 0, 0, "", 0},
		{AG3446X_VAL_600, 0, 0, "", 0},
		{AG3446X_VAL_800, 0, 0, "", 0},
		{AG3446X_VAL_900, 0, 0, "", 0},
		{AG3446X_VAL_1000, 0, 0, "", 0},
		{AG3446X_VAL_1200, 0, 0, "", 0},
		{AG3446X_VAL_8000, 0, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrScaleDbmReferenceRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrScaleDbmReferenceRangeTableEntries,
	};

static IviRangeTableEntry attrEDU34450ADbmReferenceRangeTableEntries[] =
	{
		{AG3446X_VAL_2, 0, 0, "", 0},
		{AG3446X_VAL_4, 0, 0, "", 0},
		{AG3446X_VAL_8, 0, 0, "", 0},
		{AG3446X_VAL_16, 0, 0, "", 0},
		{AG3446X_VAL_50, 0, 0, "", 0},
		{AG3446X_VAL_75, 0, 0, "", 0},
		{AG3446X_VAL_93, 0, 0, "", 0},
		{AG3446X_VAL_110, 0, 0, "", 0},
		{AG3446X_VAL_124, 0, 0, "", 0},
		{AG3446X_VAL_125, 0, 0, "", 0},
		{AG3446X_VAL_135, 0, 0, "", 0},
		{AG3446X_VAL_150, 0, 0, "", 0},
		{AG3446X_VAL_250, 0, 0, "", 0},
		{AG3446X_VAL_300, 0, 0, "", 0},
		{AG3446X_VAL_500, 0, 0, "", 0},
		{AG3446X_VAL_600, 0, 0, "", 0},
		{AG3446X_VAL_800, 0, 0, "", 0},
		{AG3446X_VAL_900, 0, 0, "", 0},
		{AG3446X_VAL_1000, 0, 0, "", 0},
		{AG3446X_VAL_1200, 0, 0, "", 0},
		{AG3446X_VAL_8000, 0, 0, "", 0}, 
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrEDU34450ADbmReferenceRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrEDU34450ADbmReferenceRangeTableEntries,
	};

static ViStatus _VI_FUNC ag3446xAttrScaleDbmReference_RangeTableCallback (ViSession vi,
                                                                          ViConstString channelName,
                                                                          ViAttr attributeId,
                                                                          IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
		tblPtr=&attrEDU34450ADbmReferenceRangeTable;
	else
		tblPtr=&attrScaleDbmReferenceRangeTable;

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

/* AG3446X_ATTR_SCALE_DBM_REFERENCE */


static ViStatus _VI_FUNC ag3446xAttrScaleDbmReference_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 *value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

	if(IS_EDU34450A(model))
		viCheckErr (viQueryf (io, "CALC:DBM:REF?", "%lf", value));
	else
		viCheckErr (viQueryf (io, "CALC:SCAL:DBM:REF?", "%lf", value));
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrScaleDbmReference_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));   
	
	if(IS_EDU34450A(model))
		viCheckErr (viPrintf (io, "CALC:DBM:REF %lf", value));
	else
		viCheckErr (viPrintf (io, "CALC:SCAL:DBM:REF %lf", value)); 
	
Error:
	return error;
}

static IviRangeTableEntry attrScaleDbReferenceRangeTableEntries[] =
{
    { -200.0, 200.0, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrScaleDbReferenceRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrScaleDbReferenceRangeTableEntries,
};

static IviRangeTableEntry attrEDU34450ADbReferenceRangeTableEntries[] =
{
    { -120.0, 120.0, 0, "", 0 },
    { IVI_RANGE_TABLE_LAST_ENTRY }
};

static IviRangeTable attrEDU34450ADbReferenceRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrEDU34450ADbReferenceRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrScaleDbReference_RangeTableCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
		tblPtr=&attrEDU34450ADbReferenceRangeTable;
	else
		tblPtr=&attrScaleDbReferenceRangeTable;
	
Error:
	*rangeTablePtr = tblPtr;
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrScaleDbReference_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
		viCheckErr (viQueryf (io, "CALC:DB REF?", "%lf", &value));
	else	
		viCheckErr (viQueryf (io, "CALC:SCAL:DB:REF?", "%lf", &value));
	        	 
Error:											
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrScaleDbReference_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if(IS_EDU34450A(model))
	{
		viCheckErr (viPrintf (io, "CALC:STAT ON")); 
		viCheckErr (viPrintf (io, "CALC:DB:REF %lf", value));
	}    
	else	
	    viCheckErr (viPrintf (io, "CALC:SCAL:DB:REF %lf", value));    	 

Error:
	return error;
}


static IviRangeTableEntry attrConfMeasRangeTableEntries[] =
	{
		{AG3446X_VAL_CONF_MEAS_CONT, 0, 0, "CONT", 0},
		{AG3446X_VAL_CONF_MEAS_AC_CURRENT, 0, 0, "CURR:AC", 0},
		{AG3446X_VAL_CONF_MEAS_DC_CURRENT, 0, 0, "CURR:DC", 0},
		{AG3446X_VAL_CONF_MEAS_DIODE, 0, 0, "DIOD", 0},
		{AG3446X_VAL_CONF_MEAS_FREQ, 0, 0, "FREQ", 0},
		{AG3446X_VAL_CONF_MEAS_PER, 0, 0, "PER", 0},
		{AG3446X_VAL_CONF_MEAS_RES, 0, 0, "RES", 0},
		{AG3446X_VAL_CONF_MEAS_FRES, 0, 0, "FRES", 0},
		{AG3446X_VAL_CONF_MEAS_TEMP, 0, 0, "TEMP", 0},
		{AG3446X_VAL_CONF_MEAS_AC_VOLTAGE, 0, 0, "AC", 0},
		{AG3446X_VAL_CONF_MEAS_DC_VOLTAGE, 0, 0, "DC", 0},
		{AG3446X_VAL_CONF_MEAS_DC_VOLTAGE_RATIO, 0, 0, "RAT", 0},
		{AG3446X_VAL_CONF_MEAS_CAP, 0, 0, "CAP", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrConfMeasRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrConfMeasRangeTableEntries,
	};
static IviRangeTableEntry attrConfMeasEDU34450ARangeTableEntries[] =
	{
		{AG3446X_VAL_CONF_MEAS_CONT, 0, 0, "CONT", 0},
		{AG3446X_VAL_CONF_MEAS_AC_CURRENT, 0, 0, "CURR:AC", 0},
		{AG3446X_VAL_CONF_MEAS_DC_CURRENT, 0, 0, "CURR:DC", 0},
		{AG3446X_VAL_CONF_MEAS_DIODE, 0, 0, "DIOD", 0},
		{AG3446X_VAL_CONF_MEAS_FREQ, 0, 0, "FREQ", 0},
		{AG3446X_VAL_CONF_MEAS_RES, 0, 0, "RES", 0},
		{AG3446X_VAL_CONF_MEAS_FRES, 0, 0, "FRES", 0},
		{AG3446X_VAL_CONF_MEAS_TEMP, 0, 0, "TEMP", 0},
		{AG3446X_VAL_CONF_MEAS_AC_VOLTAGE, 0, 0, "AC", 0},
		{AG3446X_VAL_CONF_MEAS_DC_VOLTAGE, 0, 0, "DC", 0},
		{AG3446X_VAL_CONF_MEAS_CAP, 0, 0, "CAP", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrConfMeasEDU34450ARangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrConfMeasEDU34450ARangeTableEntries,
	};

/* AG3446X_ATTR_CONF_MEAS */
static ViStatus _VI_FUNC ag3446xAttrConfMeas_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value)
{
    ViStatus error = VI_SUCCESS;
    ViString cmd;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;
	
	if(IS_EDU34450A(model))
		checkErr (ag3446x_GetCmdFromIntValue (value, &attrConfMeasEDU34450ARangeTable, &cmd));	
    
	else
		checkErr (ag3446x_GetCmdFromIntValue (value, &attrConfMeasRangeTable, &cmd));

    viCheckErr (viPrintf (io, "CONF:%s;", cmd));

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrConfMeas_CheckCallback (ViSession vi,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if (value == AG3446X_VAL_CONF_MEAS_CAP)
	{   /* AG3446X_VAL_CONF_MEAS_CAP applies only to 34465A, 34470A and EDU34450A */ 
		if (!IS_34465A(model) && !IS_34470A(model) && !IS_EDU34450A(model))
		{
			viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Measurement parameter not supported for the current model"); 		
		}
	}
	
	checkErr (Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value)); 
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrConfMeas_RangeTableCallback (ViSession vi,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));  

	if(IS_EDU34450A(model))
	{
		tblPtr=&attrConfMeasEDU34450ARangeTable;
	}
	else
	{
		tblPtr=&attrConfMeasRangeTable;
	}

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

/* AG3446X_ATTR_SCALE_GAIN */
/* use common read callback ag3446xViReal64_ReadCallback */				      
		
/* use common write callback ag3446xViReal64_WriteCallback */

static IviRangeTableEntry attrScaleGainRangeTableEntries[] =
{
	{-1.0E+15, -1.0E-15, 0, "", 0},
	{0.0, 0.0, 0, "", 0},
	{+1.0E-15 , 1.0E+15, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrScaleGainRangeTable = 
{
	IVI_VAL_RANGED,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrScaleGainRangeTableEntries,
};

/* AG3446X_ATTR_SCALE_OFFSET */
/* use common read callback ag3446xViReal64_ReadCallback */				      
		
/* use common write callback ag3446xViReal64_WriteCallback */

static IviRangeTableEntry attrScaleOffsetRangeTableEntries[] =
{
	{-1.0E+15, -1.0E-15, 0, "", 0},
	{0.0, 0.0, 0, "", 0},
	{+1.0E-15 , 1.0E+15, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrScaleOffsetRangeTable = 
{
	IVI_VAL_RANGED,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrScaleOffsetRangeTableEntries,
};

/* AG3446X_ATTR_SCALE_REFERENCE */
/* use common read callback ag3446xViReal64_ReadCallback */				      
		
/* use common write callback ag3446xViReal64_WriteCallback */

static IviRangeTableEntry attrScaleReferenceRangeTableEntries[] =
{
	{-1.0E+15, -1.0E-15, 0, "", 0},
	{0.0, 0.0, 0, "", 0},
	{+1.0E-15 , 1.0E+15, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrScaleReferenceRangeTable = 
{
	IVI_VAL_RANGED,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrScaleReferenceRangeTableEntries,
};

/* AG3446X_ATTR_SCALE_UNIT */
/* use common read callback ag3446xViString_ReadCallback */				      
		
/* use common write callback ag3446xViString_WriteCallback */				      
		          
static ViStatus _VI_FUNC ag3446xScaleUnit_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId, 
                                                                  ViConstString value)
{
    ViStatus    error = VI_SUCCESS;

    if (strlen(value) > 4)
    {
        viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The scale unit should be a string of up to four characters");
    }

Error:
    return error;
}

/* AG3446X_ATTR_SMOOTHING_RESPONSE */
/* use common read callback ag3446xEnum_ReadCallback */				      
		
/* use common write callback ag3446xEnum_WriteCallback */	

static IviRangeTableEntry attrSmoothingResponseRangeTableEntries[] =
{
	{AG3446X_VAL_SMOOTHING_RESPONSE_SLOW, 0, 0, "SLOW", 0},
	{AG3446X_VAL_SMOOTHING_RESPONSE_MEDIUM, 0, 0, "MED", 0},
	{AG3446X_VAL_SMOOTHING_RESPONSE_FAST, 0, 0, "FAST", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrSmoothingResponseRangeTable = 
{
	IVI_VAL_DISCRETE,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrSmoothingResponseRangeTableEntries,
};

/* AG3446X_ATTR_MEM_FORM_READING_SEPARATOR */
/* use common read callback ag3446xEnum_ReadCallback */				      
		
/* use common write callback ag3446xEnum_WriteCallback */

static IviRangeTableEntry attrMemFormReadingSeparatorRangeTableEntries[] =
{
	{AG3446X_VAL_SEPARATOR_COM, 0, 0, "COMM", 0},
	{AG3446X_VAL_SEPARATOR_SEM, 0, 0, "SEM", 0},
	{AG3446X_VAL_SEPARATOR_TAB, 0, 0, "TAB", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrMemFormReadingSeparatorRangeTable = 
{
	IVI_VAL_DISCRETE,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrMemFormReadingSeparatorRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrSampleIntervalMin_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 *value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32	 model = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr (Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	
	if (!Ivi_Simulating(vi))
	{
		checkErr( viQueryf(io, "SAMP:TIM? MIN", "%lf", value));
	}
	else if(IS_EDU34450A(model))
	{
		*value = 0.01;
	}
    else
	{
		*value = 0.00002;
	}

Error:
	return error;
}

/* AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER */
/* use common read callback ag3446xViInt32_ReadCallback */				      
		
/* use common write callback ag3446xViInt32_WriteCallback */

static IviRangeTableEntry attrSampleCountPreTriggerRangeTableEntries[] =
{
	{0, 1999999, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrSampleCountPreTriggerRangeTable = 
{
	IVI_VAL_RANGED,
	VI_TRUE,
	VI_TRUE,
	VI_NULL,
	attrSampleCountPreTriggerRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrSampleCountPreTrigger_CheckCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         ViInt32 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		function;
	ViInt32		sampleCount;
	ViBoolean	calcState = VI_FALSE;
	
	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_FUNCTION, 0, &function));
	if (function == AG3446X_VAL_CONTINUITY || function == AG3446X_VAL_DIODE)
	{
		viCheckErrElab( IVI_ERROR_INVALID_CONFIGURATION, "Pretrigger applies to all measurement functions except Continuity and Diode test");	
	}
	
	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SAMPLE_COUNT, 0, &sampleCount));
	if (value >= sampleCount)
	{
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "The pretrigger sample count must be less than the sample count");	
	}
	checkErr( Ivi_GetAttributeViBoolean(vi, channelName, AG3446X_ATTR_CALC_FUNC_ENABLED, 0, &calcState));
	
	if (calcState == VI_TRUE)
	{
		if (value > 10000)
		{
			viCheckErrElab (IVI_ERROR_INVALID_VALUE, "If any of the calculation functions are on, the pretrigger count is limited to 10000 samples.");	
		}
	}
	
	checkErr (Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value));
	
Error:
	return error;
}

/* AG3446X_ATTR_CALC_FUNC_ENABLED */

static ViStatus _VI_FUNC ag3446xAttrCalcFuncEnabled_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViBoolean *value)
{
	ViStatus	error = VI_SUCCESS;
	ViBoolean	calcState = VI_FALSE;
	ViAttr		calcStateAttrs[] = { AG3446X_ATTR_SMOOTHING_ENABLED,
									 AG3446X_ATTR_SCALE_ENABLED,
									 AG3446X_ATTR_AVER_ENABLED,
									 AG3446X_ATTR_LIMIT_ENABLED,
									 AG3446X_ATTR_HIST_ENABLED };
	ViInt32 	calcStateNums = (ViInt32)(sizeof(calcStateAttrs) / sizeof(ViAttr));
	ViInt32		i = 0;
	
	for (i = 0, calcState = VI_FALSE; i < calcStateNums; ++i)
	{
		checkErr( Ivi_GetAttributeViBoolean(vi, channelName, calcStateAttrs[i], 0, &calcState));
		
		if (calcState == VI_TRUE)
			break;
	}

Error:
	*value = calcState; 
	
	return error;
}

/* AG3446X_ATTR_OPTION */   

static IviRangeTableEntry optionRangeTableEntries[] =
{
	{0, 31, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable optionRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    optionRangeTableEntries,
};

/* AG3446X_ATTR_TRIGGER_LEVEL */

static IviRangeTableEntry attrTriggerLevelDcvRangeTableEntries[] =
{
	{-1000, 1000, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerLevelDcvRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerLevelDcvRangeTableEntries,
};

static IviRangeTableEntry attrTriggerLevelDciRangeTableEntries[] =
{
	{-3.6, 3.6, 0, "", AG3446X_VAL_CURR_TERM_3},
	{-12, 12, 0, "", AG3446X_VAL_CURR_TERM_10},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerLevelDciRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerLevelDciRangeTableEntries,
};

static IviRangeTableEntry attrTriggerLevelAcvRangeTableEntries[] =
{
	{0, 1000, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerLevelAcvRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerLevelAcvRangeTableEntries,
};

static IviRangeTableEntry attrTriggerLevelAciRangeTableEntries[] =
{
	{0, 3.6, 0, "", AG3446X_VAL_CURR_TERM_3},
	{0, 12, 0, "", AG3446X_VAL_CURR_TERM_10},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerLevelAciRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerLevelAciRangeTableEntries,
};

static IviRangeTableEntry attrTriggerLevelResRangeTableEntries[] =
{
	{0, 1.2e+9, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerLevelResRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerLevelResRangeTableEntries,
};

static IviRangeTableEntry attrTriggerLevelFreqRangeTableEntries[] =
{
	{3, 300000, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerLevelFreqRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerLevelFreqRangeTableEntries,
};

static IviRangeTableEntry attrTriggerLevelPerRangeTableEntries[] =
{
	{3.33333333e-6, 0.333333333, 0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrTriggerLevelPerRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrTriggerLevelPerRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrTriggerLevel_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		function;

	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_FUNCTION, 0, &function));
	
	switch(function)
	{
		case AG3446X_VAL_DC_VOLTS:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_DCV, 0, value));
			break;
		case AG3446X_VAL_DC_CURRENT:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_DCI, 0, value));  
			break;
		case AG3446X_VAL_AC_VOLTS:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_ACV, 0, value));  
			break;
		case AG3446X_VAL_AC_CURRENT:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_ACI, 0, value));  
			break;
		case AG3446X_VAL_2_WIRE_RES:
		case AG3446X_VAL_4_WIRE_RES:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_RES, 0, value));  
			break;
		case AG3446X_VAL_FREQ:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_FREQ, 0, value));
			break;
		case AG3446X_VAL_PERIOD:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_PER, 0, value));
			break;
		case AG3446X_VAL_TEMPERATURE:
			checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_TEMP, 0, value));
			break;
		default:
			break;
	}
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevel_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		function;
	
	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_FUNCTION, 0, &function));
	
	switch(function)
	{
		case AG3446X_VAL_DC_VOLTS:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_DCV, 0, value));
			break;
		case AG3446X_VAL_DC_CURRENT:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_DCI, 0, value));  
			break;
		case AG3446X_VAL_AC_VOLTS:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_ACV, 0, value));  
			break;
		case AG3446X_VAL_AC_CURRENT:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_ACI, 0, value));  
			break;
		case AG3446X_VAL_2_WIRE_RES:
		case AG3446X_VAL_4_WIRE_RES:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_RES, 0, value));  
			break;
		case AG3446X_VAL_FREQ:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_FREQ, 0, value));
			break;
		case AG3446X_VAL_PERIOD:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_PER, 0, value));
			break;
		case AG3446X_VAL_TEMPERATURE:
			checkErr( Ivi_SetAttributeViReal64(vi, channelName, AG3446X_ATTR_TRIGGER_LEVEL_TEMP, 0, value));
			break;
		default:
			break;
	}

Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelDcv_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value){
	ViStatus	error = VI_SUCCESS;
	ViReal64	range;

	checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_RANGE, 0, &range));
	if (range >= 0.1 && range <=100)
	{
		if (value < -1.2 * range || value > 1.2 * range)
			viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Trigger level out of range."); 	
	}

	checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));  	

Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelAci_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value){
	ViStatus	error = VI_SUCCESS;
	ViReal64	range, upper = 0, lower = 0;
	ViInt32		currTerminal;
	IviRangeTablePtr tblPtr = VI_NULL;

	checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_RANGE, 0, &range));
	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_CURR_TERMINAL, 0, &currTerminal));
	
	if (currTerminal == AG3446X_VAL_CURR_TERM_3 && range != AG3446X_VAL_AUTO_RANGE_ON)
	{
		upper = 1.2 * range;
		lower = 0;
	}
	else
	{
		checkErr( Ivi_GetAttrRangeTable(vi, channelName, attributeId, &tblPtr));
		checkErr (Ivi_GetViReal64EntryFromCmdValue (currTerminal, tblPtr, &lower, &upper,
                                                    VI_NULL, VI_NULL, VI_NULL));
	}

	if (value < lower || value > upper)
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Trigger level out of range."); 
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelAcv_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value){
	ViStatus	error = VI_SUCCESS;
	ViReal64	range;

	checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_RANGE, 0, &range));
	
	if (range >= 0.1 && range <=100)
	{
		if (value < 0 || value > 1.2 * range)
			viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Trigger level out of range."); 	
	}

	checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));  	

Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelDci_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value){
	ViStatus	error = VI_SUCCESS;
	ViReal64	range, upper = 0, lower = 0;
	ViInt32		currTerminal;
	IviRangeTablePtr tblPtr = VI_NULL;

	checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_RANGE, 0, &range));
	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_CURR_TERMINAL, 0, &currTerminal));
	
	if (currTerminal == AG3446X_VAL_CURR_TERM_3 && range != AG3446X_VAL_AUTO_RANGE_ON)
	{
		upper = 1.2 * range;
		lower = -upper;
	}
	else
	{
		checkErr( Ivi_GetAttrRangeTable(vi, channelName, attributeId, &tblPtr));
		checkErr (Ivi_GetViReal64EntryFromCmdValue (currTerminal, tblPtr, &lower, &upper,
                                                    VI_NULL, VI_NULL, VI_NULL));
	}

	if (value < lower || value > upper)
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Trigger level out of range."); 
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelRes_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value){
	ViStatus	error = VI_SUCCESS;
	ViReal64	range;

	checkErr( Ivi_GetAttributeViReal64(vi, channelName, AG3446X_ATTR_RANGE, 0, &range));
	
	if (range != AG3446X_VAL_AUTO_RANGE_ON)
	{
		if (value < 0 || value > 1.2 * range)
			viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Trigger level out of range."); 	
	}

	checkErr (Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));  	

Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelMeas_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value){
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViReal64_commands, AG3446X_ATTR_TRIGGER_LEVEL, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViReal64_commands, AG3446X_ATTR_TRIGGER_LEVEL, &repCommand));

    if (!Ivi_Simulating (vi))
        viCheckErr (viQueryf (io, "%s%s%s?", "%Le", command, VALID_CHANNELNAME (channelName), repCommand, value));

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevelMeas_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value){
    ViStatus error = VI_SUCCESS;
    ViString command;
    ViString repCommand;

    viCheckErr (ag3446x_GetStringFromTable (ag3446xViReal64_commands, AG3446X_ATTR_TRIGGER_LEVEL, &command));
    viCheckErr (ag3446x_GetRepCommandFromTable (ag3446xViReal64_commands, AG3446X_ATTR_TRIGGER_LEVEL, &repCommand));

    if (!Ivi_Simulating (vi))
    {
        if (abs (value) < 1.0)
        {
            viCheckErr (viPrintf (io, "%s%s%s %Le", command, VALID_CHANNELNAME (channelName), repCommand, value));
        }
        else
        {
            viCheckErr (viPrintf (io, "%s%s%s %Lf", command, VALID_CHANNELNAME (channelName), repCommand, value));
        }
    }
Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrTriggerLevel_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		model = AG3446X_VAL_MODEL_UNKNOWN;
	ViInt32		options = 0;
	ViInt32		function;
	ViBoolean	offsetCompensateEnabled = VI_FALSE;
	ViBoolean   powerLimitEnabled = VI_FALSE;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_OPTION, 0, &options));
	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_FUNCTION, 0, &function));
	
	if (!IS_34465A(model) && !IS_34470A(model) && !IS_EDU34450A(model) || !IS_DIG_INSTALLED(options))
	{
		viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument model is not supported or required option is not installed.");		
	}
	switch(function)
	{
		case AG3446X_VAL_DC_VOLTS:
		case AG3446X_VAL_DC_CURRENT:
		case AG3446X_VAL_AC_VOLTS:
		case AG3446X_VAL_AC_CURRENT:
		case AG3446X_VAL_FREQ:
		case AG3446X_VAL_PERIOD:
			break;
		case AG3446X_VAL_2_WIRE_RES:
		case AG3446X_VAL_4_WIRE_RES:
			checkErr( Ivi_GetAttributeViBoolean(vi, VI_NULL, AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED, 0, &offsetCompensateEnabled));
			checkErr( Ivi_GetAttributeViBoolean(vi, VI_NULL, AG3446X_ATTR_POWER_LIMIT_ENABLED, 0, &powerLimitEnabled)); 
			if (offsetCompensateEnabled || powerLimitEnabled)
			{
				viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Resistance measurement must have offset compensation and low power disabled.");
			}
			break;
		case AG3446X_VAL_TEMPERATURE: 
			checkErr( Ivi_GetAttributeViBoolean(vi, VI_NULL, AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED, 0, &offsetCompensateEnabled));
			checkErr( Ivi_GetAttributeViBoolean(vi, VI_NULL, AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED, 0, &powerLimitEnabled)); 
			if (offsetCompensateEnabled || powerLimitEnabled)
			{
				viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Resistance measurement must have offset compensation and low power disabled.");
			}
			break;
		default:
			viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Measurement function is not supported for trigger level setting.");
			break;
	}

Error:
	return error;
}

/* AG3446X_ATTR_RESOLUTION */

/*This order of the entries make the max value coerced to the right value.*/

static IviRangeTableEntry attrResolution34460RangeTableEntries[] =
{
	{.0001, .0003, .0001, "", 0},
	{.00003, .0001, .00003, "", 0},
	{.00001, .00003, .00001, "", 0},
	{.000003, .00001, .000003, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrResolution34460RangeTable =
{
	IVI_VAL_COERCED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrResolution34460RangeTableEntries,
};

/*This order of the entries make the max value coerced to the right value.*/
static IviRangeTableEntry attrResolution34461RangeTableEntries[] =
{
	{.00001, .0001, .00001, "", 0},
	{.000003, .00001, .000003, "", 0},
	{.000001, .000003, .000001, "", 0},
	{.0000003, .000001, .0000003, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrResolution34461RangeTable =
{
	IVI_VAL_COERCED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrResolution34461RangeTableEntries,
};

/*This order of the entries make the max value coerced to the right value.*/  
static IviRangeTableEntry attrResolution34465RangeTableEntries[] =
{
	{0.000015, 0.00003, 0.000015, "", 0},
	{0.000006, 0.000015, 0.000006, "", 0},
	{0.000003, 0.000006, 0.000003, "", 0},
	{0.0000015, 0.000003, 0.0000015, "", 0},
	{0.0000007, 0.0000015, 0.0000007, "", 0},
	{0.0000003, 0.0000007, 0.0000003, "", 0},
	{0.0000001, 0.0000003, 0.0000001, "", 0},
	{0.00000003, 0.0000001, 0.00000003, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrResolution34465RangeTable =
{
	IVI_VAL_COERCED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrResolution34465RangeTableEntries,
};

/*This order of the entries make the max value coerced to the right value.*/  
static IviRangeTableEntry attrResolution34470RangeTableEntries[] =
{
	{0.00001, 0.00003, 0.00001, "", 0},
	{0.000003, 0.00001, 0.000003, "", 0},
	{0.000001, 0.000003, 0.000001, "", 0},
	{0.0000005, 0.000001, 0.0000005, "", 0},
	{0.0000003, 0.0000005, 0.0000003, "", 0},
	{0.0000001, 0.0000003, 0.0000001, "", 0},
	{0.00000003, 0.0000001, 0.00000003, "", 0},
	{0.00000001, 0.00000003, 0.00000001, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrResolution34470RangeTable =
{
	IVI_VAL_COERCED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrResolution34470RangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrResolution_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  model;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));

    if(IS_EDU34450A(model))
	{
		*rangeTablePtr = &attrResolutionEDU34450ARangeTable;
	}
	else if (IS_34460A(model))
    {
        *rangeTablePtr = &attrResolution34460RangeTable;
    }
    else if (IS_34461A(model))
    {
        *rangeTablePtr = &attrResolution34461RangeTable;
    }
	else if (IS_34465A(model))
	{
		*rangeTablePtr = &attrResolution34465RangeTable; 	
	}
	else if (IS_34470A(model))
	{
		*rangeTablePtr = &attrResolution34470RangeTable; 	
	}
    else
    {
        viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument is not supported");
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrResolution_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;
	ViReal64 range, absoluteValue = 0;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;
	ViString cmdValue;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model)); 
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	checkErr (Ivi_GetAttributeViReal64 (vi, channelName, AG3446X_ATTR_RANGE, 0, &range));

	if (IS_EDU34450A(model))
	{
		switch (measFunc)
		{
		case AG3446X_VAL_DC_CURRENT:
			viCheckErr (viPrintf (io, "CURR:RES?","%s", &cmdValue));
			 break;
		case AG3446X_VAL_AC_CURRENT:
		    viCheckErr (viPrintf (io, "CURR:AC:RES?","%s", &cmdValue));          
		     break;
		case AG3446X_VAL_DC_VOLTS:
			viCheckErr (viPrintf (io, "VOLT:RES?","%s", &cmdValue)); 
			 break;
		case AG3446X_VAL_AC_VOLTS:
		    viCheckErr (viPrintf (io, "VOLT:AC:RES?","%s", &cmdValue));   
		     break;
		case AG3446X_VAL_2_WIRE_RES:
			viCheckErr (viPrintf (io, "RES:RES?","%s", &cmdValue)); 
			 break;
		case AG3446X_VAL_4_WIRE_RES:
		    viCheckErr (viPrintf (io, "FRES:RES?","%s", &cmdValue));    
		     break;
		default:
	        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION,
							"Invalid measurement function.");
		     break;
		}
		
		if (cmdValue == AG3446X_VAL_SLOW)
		{
			*value =  1;
		}
		else if (cmdValue == AG3446X_VAL_MEDIUM)
		{
			*value =  2;
		}
		else if (cmdValue == AG3446X_VAL_FAST) 
		{ 
			*value =  3;		
		}
		else
		{
			viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Resolution not supported for current model.");	
		}
	 }
	
     else
	 {
		 switch (measFunc)
		{
		case AG3446X_VAL_DC_VOLTS:
		case AG3446X_VAL_DC_VOLTS_RATIO:
		    viCheckErr (viQueryf (io, "VOLT:RES?", "%lf", &absoluteValue));
		    break;

		case AG3446X_VAL_DC_CURRENT:
		    viCheckErr (viQueryf (io, "CURR:RES?", "%lf", &absoluteValue));
		    break;

		case AG3446X_VAL_2_WIRE_RES:
		    viCheckErr (viQueryf (io, "RES:RES?", "%lf", &absoluteValue));
		    break;

		case AG3446X_VAL_4_WIRE_RES:
		    viCheckErr (viQueryf (io, "FRES:RES?", "%lf", &absoluteValue));
		    break;
		}
	 *value = absoluteValue / range;
	 }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrResolution_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;
	ViReal64 range, absoluteValue;
	ViString cmd;
	ViInt32  model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));  
    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	checkErr (Ivi_GetAttributeViReal64 (vi, channelName, AG3446X_ATTR_RANGE, 0, &range));
	
	if(IS_EDU34450A(model))
	{
		checkErr (ag3446x_GetCmdFromIntValue (value, &attrResolutionEDU34450ARangeTable, &cmd)); 
		switch (measFunc)
		{
		case AG3446X_VAL_DC_CURRENT:
			viCheckErr (viPrintf (io, "CURR:RES %s",cmd));
			 break;
		case AG3446X_VAL_AC_CURRENT:
		    viCheckErr (viPrintf (io, "CURR:AC:RES %s",cmd));               
		     break;
		case AG3446X_VAL_DC_VOLTS:
			viCheckErr (viPrintf (io, "VOLT:RES %s",cmd));
			 break;
		case AG3446X_VAL_AC_VOLTS:
		    viCheckErr (viPrintf (io, "VOLT:AC:RES %s",cmd));             
		     break;
		case AG3446X_VAL_2_WIRE_RES:
			viCheckErr (viPrintf (io, "RES:RES %s",cmd));
			 break;
		case AG3446X_VAL_4_WIRE_RES:
		    viCheckErr (viPrintf (io, "FRES:RES %s",cmd));           
		     break;
		default:
	        viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION,
							"Invalid measurement function.");
		     break;
		}	
	 }
	 else
	 {
		absoluteValue = range * value;
	    switch (measFunc)
	    {
	    case AG3446X_VAL_DC_VOLTS:
	    case AG3446X_VAL_DC_VOLTS_RATIO:
	        viCheckErr (viPrintf (io, "VOLT:RES %.10lf;", absoluteValue));
	        break;

	    case AG3446X_VAL_DC_CURRENT:
	        viCheckErr (viPrintf (io, "CURR:RES %.10lf;", absoluteValue));
	        break;

	    case AG3446X_VAL_2_WIRE_RES:
	        viCheckErr (viPrintf (io, "RES:RES %.10lf;", absoluteValue));
	        break;

	    case AG3446X_VAL_4_WIRE_RES:
	        viCheckErr (viPrintf (io, "FRES:RES %.10lf;", absoluteValue));
	        break;
	    }
	 }	

Error:
    return error;
}

/* AG3446X_APERTURE_TIME_NPLC */  

static IviRangeTableEntry attrApertureTimeNplcRangeTableEntries[] =
{
	{0.0, 0.02, 0.02, "", 0},
	{0.02, 0.2, 0.2, "", 0},
	{0.2, 1.0, 1.0, "", 0},
	{1.0, 10.0, 10.0, "", 0},
	{10.0, 100.0, 100.0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrApertureTimeNplcRangeTable =
{
	IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeNplcRangeTableEntries,
};

static IviRangeTableEntry attrApertureTimeNplc34465DigRangeTableEntries[] =
{
	{0.0, 0.001, 0.001, "", 0},
	{0.001, 0.002, 0.002, "", 0},
	{0.002, 0.006, 0.006, "", 0},
	{0.006, 0.02, 0.02, "", 0},
	{0.02, 0.06, 0.06, "", 0},
	{0.06, 0.2, 0.2, "", 0},
	{0.2, 1.0, 1.0, "", 0},
	{1.0, 10.0, 10.0, "", 0},
	{10.0, 100.0, 100.0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrApertureTimeNplc34465DigRangeTable =
{
	IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeNplc34465DigRangeTableEntries,
};

static IviRangeTableEntry attrApertureTimeNplc34465RangeTableEntries[] =
{
	{0.0, 0.02, 0.02, "", 0},
	{0.02, 0.06, 0.06, "", 0},
	{0.06, 0.2, 0.2, "", 0},
	{0.2, 1.0, 1.0, "", 0},
	{1.0, 10.0, 10.0, "", 0},
	{10.0, 100.0, 100.0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrApertureTimeNplc34465RangeTable =
{
	IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeNplc34465RangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrApertureTimeNplc_RangeTableCallback (ViSession vi,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;
	ViInt32		options = 0;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_OPTION, 0, &options));

	if (IS_34460A(model) || IS_34461A(model))
	{
		tblPtr = &attrApertureTimeNplcRangeTable;
	}
	else
	{
		if (IS_DIG_INSTALLED(options))
		{
			tblPtr = &attrApertureTimeNplc34465DigRangeTable;
		}
		else
		{
			tblPtr = &attrApertureTimeNplc34465RangeTable;
		}
	}

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTimeNplc_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viQueryf (io, "VOLT:NPLC?", "%lf", value));
        break;

    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:NPLC?", "%lf", value));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viQueryf (io, "RES:NPLC?", "%lf", value));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viQueryf (io, "FRES:NPLC?", "%lf", value));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viQueryf (io, "TEMP:NPLC?", "%lf", value));
        break;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTimeNplc_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viPrintf (io, "VOLT:NPLC %lf", value));
        break;

    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viPrintf (io, "CURR:NPLC %lf", value));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viPrintf (io, "RES:NPLC %lf", value));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viPrintf (io, "FRES:NPLC %lf", value));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viPrintf (io, "TEMP:NPLC %lf", value));
        break;
    }

Error:
    return error;
}

/* AG3446X_APERTURE_TIME_SECONDS */

static IviRangeTableEntry attrApertureTimeSeconds34465DigRangeTableEntries[] =
{
	{20e-6, 1, 100.0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrApertureTimeSeconds34465DigRangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeSeconds34465DigRangeTableEntries,
};

static IviRangeTableEntry attrApertureTimeSecondsFreqRangeTableEntries[] =
{
	{0, 0.01, 0.01, "", 0},
	{0.01, 0.1, 0.1, "", 0},
	{0.1, 1, 1, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrApertureTimeSecondsFreqRangeTable =
{
	IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeSecondsFreqRangeTableEntries,
};

static IviRangeTableEntry attrApertureTimeSecondsEDU34450AFreqRangeTableEntries[] =
	{
		{0.1, 1, 1, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrApertureTimeSecondsEDU34450AFreqRangeTable =
	{
		IVI_VAL_COERCED,
        VI_FALSE,
        VI_TRUE,
        VI_NULL,
        attrApertureTimeSecondsEDU34450AFreqRangeTableEntries,
	};

static IviRangeTableEntry attrApertureTimeSeconds34465FreqRangeTableEntries[] =
{
	{0.0, 0.001, 0.001, "", 0},
	{0.001, 0.01, 0.01, "", 0},
	{0.01, 0.1, 0.1, "", 0},
	{0.1, 1, 1, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrApertureTimeSeconds34465FreqRangeTable =
{
	IVI_VAL_COERCED,
    VI_FALSE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeSeconds34465FreqRangeTableEntries,
};

static IviRangeTableEntry attrApertureTimeSeconds34465RangeTableEntries[] =
{
	{200e-6, 1, 100.0, "", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrApertureTimeSeconds34465RangeTable =
{
	IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrApertureTimeSeconds34465RangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_CoerceCallback (ViSession vi,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value,
                                                                        ViReal64 *coercedValue)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		measFunc;
	ViInt32     model = AG3446X_VAL_MODEL_UNKNOWN;
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	
	if (!IS_EDU34450A(model) && (measFunc == AG3446X_VAL_DC_VOLTS || measFunc == AG3446X_VAL_DC_CURRENT
																  || measFunc == AG3446X_VAL_2_WIRE_RES
																  || measFunc == AG3446X_VAL_4_WIRE_RES
																  || measFunc == AG3446X_VAL_TEMPERATURE))
	{
		*coercedValue = (ViInt32)(value / 2.0e-6) * 2.0e-6;  	
	}
	else if (measFunc == AG3446X_VAL_FREQ || measFunc == AG3446X_VAL_PERIOD)
	{
		checkErr( Ivi_DefaultCoerceCallbackViReal64(vi, channelName, attributeId, value, coercedValue));
	}
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

	switch (measFunc)
    {
    case AG3446X_VAL_DC_VOLTS:
    case AG3446X_VAL_DC_VOLTS_RATIO:
        viCheckErr (viQueryf (io, "VOLT:APER?", "%lf", value));
        break;

    case AG3446X_VAL_DC_CURRENT:
        viCheckErr (viQueryf (io, "CURR:APER?", "%lf", value));
        break;

    case AG3446X_VAL_2_WIRE_RES:
        viCheckErr (viQueryf (io, "RES:APER?", "%lf", value));
        break;

    case AG3446X_VAL_4_WIRE_RES:
        viCheckErr (viQueryf (io, "FRES:APER?", "%lf", value));
        break;

    case AG3446X_VAL_TEMPERATURE:
        viCheckErr (viQueryf (io, "TEMP:APER?", "%lf", value));
        break;
	case AG3446X_VAL_FREQ:
		viCheckErr (viQueryf (io, "FREQ:APER?", "%lf", value));
        break;	
	case AG3446X_VAL_PERIOD:
		viCheckErr (viQueryf (io, "PER:APER?", "%lf", value));
        break;	
    }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

	switch (measFunc)
    {
	    case AG3446X_VAL_DC_VOLTS:
	    case AG3446X_VAL_DC_VOLTS_RATIO:
	        viCheckErr (viPrintf (io, "VOLT:APER %lf", value));
	        break;

	    case AG3446X_VAL_DC_CURRENT:
	        viCheckErr (viPrintf (io, "CURR:APER %lf", value));
	        break;

	    case AG3446X_VAL_2_WIRE_RES:
	        viCheckErr (viPrintf (io, "RES:APER %lf", value));
	        break;

	    case AG3446X_VAL_4_WIRE_RES:
	        viCheckErr (viPrintf (io, "FRES:APER %lf", value));
	        break;

	    case AG3446X_VAL_TEMPERATURE:
	        viCheckErr (viPrintf (io, "TEMP:APER %lf", value));
	        break;
		case AG3446X_VAL_FREQ:
			viCheckErr (viPrintf (io, "FREQ:APER %lf", value));
	        break;	
		case AG3446X_VAL_PERIOD:
			viCheckErr (viPrintf (io, "PER:APER %lf", value));
	        break;	
  	 }

Error:
    return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_RangeTableCallback (ViSession vi,
                                                                            ViConstString channelName,
                                                                            ViAttr attributeId,
                                                                            IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	ViInt32     model, options, measFunc;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_OPTION, 0, &options));
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	
	if (measFunc == AG3446X_VAL_FREQ || measFunc == AG3446X_VAL_PERIOD)
	{
		if(IS_EDU34450A(model))
		{
			tblPtr=&attrApertureTimeSecondsEDU34450AFreqRangeTable;
		}
		else if (IS_34465A(model) || IS_34470A(model))
		{
			tblPtr = &attrApertureTimeSeconds34465FreqRangeTable;
		}
		else
		{
			tblPtr = &attrApertureTimeSecondsFreqRangeTable;	
		}
	}
	else if (measFunc == AG3446X_VAL_DC_VOLTS || measFunc == AG3446X_VAL_DC_CURRENT
											  || measFunc == AG3446X_VAL_2_WIRE_RES
											  || measFunc == AG3446X_VAL_4_WIRE_RES
											  || measFunc == AG3446X_VAL_TEMPERATURE)
	{
		if (IS_34465A(model) || IS_34470A(model))
		{
			if (IS_DIG_INSTALLED(options))
			{
				tblPtr = &attrApertureTimeSeconds34465DigRangeTable;
			}
			else
			{
				tblPtr = &attrApertureTimeSeconds34465RangeTable; 	
			}
		}
		else
		{
			viCheckErrElab (AG3446X_ERROR_INVALID_MODEL_TYPE, "The instrument model is not supported.");
		}		
	}
	else
	{
		viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Measurement function not supported for aperture time.");	
	}

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrApertureTimeSeconds_CheckCallback (ViSession vi,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 value)
{
	ViStatus	error    = VI_SUCCESS;
	ViInt32		measFunc = 0;
	ViInt32     model	 = AG3446X_VAL_MODEL_UNKNOWN;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model));
	checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	
	
	if(IS_EDU34450A(model) && measFunc != AG3446X_VAL_FREQ)
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Measurement parameter not supported for the current model");
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrOffsetCompensateEnabled_CheckCallback (ViSession vi,
                                                                           ViConstString channelName,
                                                                           ViAttr attributeId,
                                                                           ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		measFunc;
	ViReal64	range;
	ViInt32 	model = AG3446X_VAL_MODEL_UNKNOWN;

	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_MODEL, 0, &model)); 
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc)); 
	checkErr( Ivi_GetAttributeViReal64(vi, VI_NULL, AG3446X_ATTR_RANGE, 0, &range));
	
	if (measFunc != AG3446X_VAL_2_WIRE_RES && measFunc != AG3446X_VAL_2_WIRE_RES)
	{
		viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Measurement function is not set to 2-wire or 4-wire resistance measurement.");
	}										  
	else if(IS_EDU34450A(model) && (range < 100 || range > 10000))
	{
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Offset compensation applies only to resistance measurements on the 100ohm, 1 kohm, 10 kohm ranges."); 	
	}
	else if(range < 100 || range > 100000)
	{
		viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Offset compensation applies only to resistance measurements on the 100ohm, 1 kohm, 10 kohm and 100 kohm ranges."); 	
	}
	
Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrPowerLimitEnabled_CheckCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		measFunc;
	ViReal64	range;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc)); 
	checkErr( Ivi_GetAttributeViReal64(vi, VI_NULL, AG3446X_ATTR_RANGE, 0, &range));
	
	if (measFunc != AG3446X_VAL_2_WIRE_RES && measFunc != AG3446X_VAL_2_WIRE_RES)
	{
		viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Measurement function is not set to 2-wire or 4-wire resistance measurement.");
	}
	else if (range < 100 || range > 100000)
	{
			viCheckErrElab (IVI_ERROR_INVALID_VALUE, "Low-power resistance measurements apply to the 100ohm through 100kohm ranges only.");
	}

Error:
	return error;
}

/* AG3446X_ATTR_SECONDARY_FUNCTION */

static ViStatus _VI_FUNC ag3446xAttrSecondaryFunction_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViInt32 *value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_VOLTS:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_VDC, 0, value));
		break;
    case AG3446X_VAL_DC_VOLTS_RATIO:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO, 0, value));
		break;
    case AG3446X_VAL_AC_VOLTS:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_VAC, 0, value));
		break;
    case AG3446X_VAL_DC_CURRENT:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_CDC, 0, value));
		break;
    case AG3446X_VAL_AC_CURRENT:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_CAC, 0, value));
		break;
    case AG3446X_VAL_2_WIRE_RES:
	case AG3446X_VAL_4_WIRE_RES: 
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_RES, 0, value));
		break;
    case AG3446X_VAL_CAPACITANCE:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_CAP, 0, value));
		break;
    case AG3446X_VAL_FREQ:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_FREQ, 0, value));
		break;
    case AG3446X_VAL_PERIOD:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_PER, 0, value));
		break;
    case AG3446X_VAL_TEMPERATURE:
		checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_TEMP, 0, value));
		break;
    }

Error:
	return error;
}

static ViStatus _VI_FUNC ag3446xAttrSecondaryFunction_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViInt32 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32  measFunc;

    checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));

    switch (measFunc)
    {
    case AG3446X_VAL_DC_VOLTS:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_VDC, 0, value));
		break;
    case AG3446X_VAL_DC_VOLTS_RATIO:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO, 0, value));
		break;
    case AG3446X_VAL_AC_VOLTS:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_VAC, 0, value));
		break;
    case AG3446X_VAL_DC_CURRENT:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_CDC, 0, value));
		break;
    case AG3446X_VAL_AC_CURRENT:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_CAC, 0, value));
		break;
    case AG3446X_VAL_2_WIRE_RES:
	case AG3446X_VAL_4_WIRE_RES: 
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_RES, 0, value));
		break;
    case AG3446X_VAL_CAPACITANCE:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_CAP, 0, value));
		break;
    case AG3446X_VAL_FREQ:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_FREQ, 0, value));
		break;
    case AG3446X_VAL_PERIOD:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_PER, 0, value));
		break;
    case AG3446X_VAL_TEMPERATURE:
		checkErr( Ivi_SetAttributeViInt32(vi, channelName, AG3446X_ATTR_SECONDARY_FUNCTION_TEMP, 0, value));
		break;
    }

Error:
	return error;
}

/* AG3446X_ATTR_SECONDARY_FUNCTION_VDC */ 

static IviRangeTableEntry attrSecFuncVdcRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_VAC, 0, 0, "\"VOLT:AC\"", 0},
		{AG3446X_VAL_SEC_FUNC_PTP, 0, 0, "\"PTP\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncVdcRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncVdcRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_CAC */

static IviRangeTableEntry attrSecFuncCacRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_FREQ, 0, 0, "\"FREQ\"", 0},
		{AG3446X_VAL_SEC_FUNC_CDC, 0, 0, "\"CURR\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncCacRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncCacRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_CAP */

static IviRangeTableEntry attrSecFuncCapacitanceRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncCapacitanceRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncCapacitanceRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_CDC */

static IviRangeTableEntry attrSecFuncCdcRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_CAC, 0, 0, "\"CURR:AC\"", 0},
		{AG3446X_VAL_SEC_FUNC_PTP, 0, 0, "\"PTP\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncCdcRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncCdcRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO */

static IviRangeTableEntry attrSecFuncDcRatioRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_SENS, 0, 0, "\"SENS:DATA\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncDcRatioRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncDcRatioRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_FREQ */

static IviRangeTableEntry attrSecFuncFreqRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_PER, 0, 0, "\"PER\"", 0},
		{AG3446X_VAL_SEC_FUNC_VAC, 0, 0, "\"VOLT:AC\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncFreqRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncFreqRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_PER */

static IviRangeTableEntry attrSecFuncPerRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_FREQ, 0, 0, "\"FREQ\"", 0},
		{AG3446X_VAL_SEC_FUNC_VAC, 0, 0, "\"VOLT:AC\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncPerRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncPerRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_RES */

static IviRangeTableEntry attrSecFuncResRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncResRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncResRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_TEMP */

static IviRangeTableEntry attrSecFuncTempRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_SENS, 0, 0, "\"SENS:DATA\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncTempRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncTempRangeTableEntries,
	};

/* AG3446X_ATTR_SECONDARY_FUNCTION_VAC */

static IviRangeTableEntry attrSecFuncVacRangeTableEntries[] =
	{
		{AG3446X_VAL_SEC_FUNC_OFF, 0, 0, "\"OFF\"", 0},
		{AG3446X_VAL_SEC_FUNC_CALC, 0, 0, "\"CALC:DATA\"", 0},
		{AG3446X_VAL_SEC_FUNC_VDC, 0, 0, "\"VOLT\"", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrSecFuncVacRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSecFuncVacRangeTableEntries,
	};

/* AG3446X_ATTR_RANGE_CHANGE_MODE */
/* use common read callback ag3446xViEnum_ReadCallback */

/* use common write callback ag3446xViEnum_WriteCallback */

static IviRangeTableEntry attrRangeChangeModeRangeTableEntries[] =
{
	{AG3446X_VAL_RANGE_CHANGE_FAST, 0, 0, "FAST", 0},
	{AG3446X_VAL_RANGE_CHANGE_CONT, 0, 0, "CONT", 0},
	{IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrRangeChangeModeRangeTable =
{
	IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrRangeChangeModeRangeTableEntries,
};

static ViStatus _VI_FUNC ag3446xAttrRangeChangeMode_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViInt32 value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32		measFunc = 0;
	ViInt32		currTerminal = 0;
	
	checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, &measFunc));
	checkErr( Ivi_GetAttributeViInt32(vi, channelName, AG3446X_ATTR_CURR_TERMINAL, 0, &currTerminal));  
	
	if ((measFunc != AG3446X_VAL_DC_CURRENT && measFunc != AG3446X_VAL_DC_CURRENT) || currTerminal != AG3446X_VAL_CURR_TERM_3)
	{
		viCheckErrElab (IVI_ERROR_INVALID_CONFIGURATION, "Range change mode support DC/AC current measurement in 3A current terminals only."); 
	}
	
	checkErr (Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value));  

Error:
	return error;
}


/*****************************************************************************
 * Function: ag3446x_InitAttributes
 * Purpose:  This function adds attributes to the IVI session, initializes
 *           instrument attributes, and sets attribute invalidation
 *           dependencies.
 *****************************************************************************/
static ViStatus ag3446x_InitAttributes (ViSession vi, ViInt32 modelNum)
{
    ViStatus         error = VI_SUCCESS;
    ViInt32          flags = 0;
    IviRangeTablePtr resDynamicRangeTablePtr;

    /*- Initialize instrument attributes --------------------------------*/

    checkErr (Ivi_SetAttrReadCallbackViString (vi, AG3446X_ATTR_SPECIFIC_DRIVER_REVISION,
                                               ag3446xAttrDriverRevision_ReadCallback));
    checkErr (Ivi_SetAttributeViInt32 (vi, "", AG3446X_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION,
                                       0, AG3446X_CLASS_SPEC_MAJOR_VERSION));
    checkErr (Ivi_SetAttributeViInt32 (vi, "", AG3446X_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION,
                                       0, AG3446X_CLASS_SPEC_MINOR_VERSION));
    checkErr (Ivi_SetAttributeViString (vi, "", AG3446X_ATTR_SUPPORTED_INSTRUMENT_MODELS,
                                        0, AG3446X_SUPPORTED_INSTRUMENT_MODELS));
    checkErr (Ivi_SetAttributeViString (vi, "", AG3446X_ATTR_IO_SESSION_TYPE,
                                        0, AG3446X_IO_SESSION_TYPE));

    checkErr (Ivi_GetAttributeFlags (vi, AG3446X_ATTR_INSTRUMENT_FIRMWARE_REVISION, &flags));
    checkErr (Ivi_SetAttributeFlags (vi, AG3446X_ATTR_INSTRUMENT_FIRMWARE_REVISION,
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr (Ivi_SetAttrReadCallbackViString (vi, AG3446X_ATTR_INSTRUMENT_FIRMWARE_REVISION,
                                               ag3446xAttrFirmwareRevision_ReadCallback));

    checkErr (Ivi_GetAttributeFlags (vi, AG3446X_ATTR_INSTRUMENT_MANUFACTURER, &flags));
    checkErr (Ivi_SetAttributeFlags (vi, AG3446X_ATTR_INSTRUMENT_MANUFACTURER,
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr (Ivi_SetAttrReadCallbackViString (vi, AG3446X_ATTR_INSTRUMENT_MANUFACTURER,
                                               ag3446xAttrInstrumentManufacturer_ReadCallback));

    checkErr (Ivi_GetAttributeFlags (vi, AG3446X_ATTR_INSTRUMENT_MODEL, &flags));
    checkErr (Ivi_SetAttributeFlags (vi, AG3446X_ATTR_INSTRUMENT_MODEL,
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr (Ivi_SetAttrReadCallbackViString (vi, AG3446X_ATTR_INSTRUMENT_MODEL,
                                               ag3446xAttrInstrumentModel_ReadCallback));

    checkErr (Ivi_SetAttributeViString (vi, "", AG3446X_ATTR_SPECIFIC_DRIVER_VENDOR,
                                        0, AG3446X_DRIVER_VENDOR));
    checkErr (Ivi_SetAttributeViString (vi, "", AG3446X_ATTR_SPECIFIC_DRIVER_DESCRIPTION,
                                        0, AG3446X_DRIVER_DESCRIPTION));
    checkErr (Ivi_SetAttributeViAddr (vi, VI_NULL, IVI_ATTR_OPC_CALLBACK, 0,
                                      ag3446x_WaitForOPCCallback));
    checkErr (Ivi_SetAttributeViAddr (vi, VI_NULL, IVI_ATTR_CHECK_STATUS_CALLBACK, 0,
                                      ag3446x_CheckStatusCallback));

    checkErr (Ivi_SetAttributeViString (vi, "", AG3446X_ATTR_GROUP_CAPABILITIES, 0,
                                        "IviDmmBase,"
                                        "IviDmmACMeasurement,"
                                        "IviDmmFrequencyMeasurement,"
                                        "IviDmmTemperatureMeasurement,"
                                        "IviDmmThermocouple,"
                                        "IviDmmResistanceTemperatureDevice,"
                                        "IviDmmThermistor,"
                                        "IviDmmMultiPoint,"
                                        "IviDmmTriggerSlope,"
                                        "IviDmmSoftwareTrigger,"
                                        "IviDmmDeviceInfo,"
                                        "IviDmmAutoRangeValue,"
                                        "IviDmmAutoZero,"));

    /*- Add instrument-specific attributes ------------------------------*/
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_FUNCTION,
	                                   "AG3446X_ATTR_FUNCTION", AG3446X_VAL_DC_VOLTS,
	                                   0, ag3446xAttrFunction_ReadCallback,
	                                   ag3446xAttrFunction_WriteCallback,
	                                   &attrFunctionRangeTable));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_FUNCTION,
	                                         ag3446xAttrFunction_RangeTableCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_RANGE, "AG3446X_ATTR_RANGE",
	                                    AG3446X_VAL_AUTO_RANGE_ON,
	                                    IVI_VAL_NEVER_CACHE,
	                                    ag3446xAttrRange_ReadCallback,
	                                    ag3446xAttrRange_WriteCallback, VI_NULL, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_RANGE,
	                                            ag3446xAttrRange_CheckCallback));
    checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_RANGE,
                                             ag3446xAttrRange_RangeTableCallback));

    checkErr (Ivi_RangeTableNew (vi, 10, 2, VI_TRUE, VI_TRUE, &resDynamicRangeTablePtr));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_RESOLUTION_ABSOLUTE,
	                                    "AG3446X_ATTR_RESOLUTION_ABSOLUTE", .000001,
	                                    0,
	                                    ag3446xAttrResolutionAbsolute_ReadCallback,
	                                    ag3446xAttrResolutionAbsolute_WriteCallback,
	                                    VI_NULL, 0));
    checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_RESOLUTION_ABSOLUTE,
                                                ag3446xAttrResolutionAbsolute_CheckCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_TRIGGER_SOURCE,
	                                   "AG3446X_ATTR_TRIGGER_SOURCE",
	                                   AG3446X_VAL_IMMEDIATE, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback, VI_NULL));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_TRIGGER_SOURCE,
	                                         ag3446xAttrTriggerSource_RangeTableCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_MODEL, "AG3446X_ATTR_MODEL",
	                                   AG3446X_VAL_MODEL_34460A, 0, VI_NULL, VI_NULL,
	                                   &attrModel));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_AC_MIN_FREQ,
                                        "AG3446X_ATTR_AC_MIN_FREQ", 20.0, 0,
                                        ag3446xAttrAcMinFreq_ReadCallback,
                                        ag3446xAttrAcMinFreq_WriteCallback,
                                        &attrAcMinFreqRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_AC_MAX_FREQ,
                                        "AG3446X_ATTR_AC_MAX_FREQ", 300000.0, 0,
                                        VI_NULL, VI_NULL, &attrAcMaxFreqRangeTable,
                                        0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_APERTURE_TIME,
	                                    "AG3446X_ATTR_APERTURE_TIME", 10, 0,
	                                    ag3446xAttrApertureTime_ReadCallback,
	                                    ag3446xAttrApertureTime_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_APERTURE_TIME_UNITS,
	                                   "AG3446X_ATTR_APERTURE_TIME_UNITS",
	                                   AG3446X_VAL_POWER_LINE_CYCLES,
	                                   IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
	                                   ag3446xAttrApertureTimeUnits_ReadCallback,
	                                   ag3446xAttrApertureTimeUnits_WriteCallback,
	                                   &attrApertureTimeUnitsRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_AUTO_RANGE_VALUE,
                                        "AG3446X_ATTR_AUTO_RANGE_VALUE", 10.0,
                                        IVI_VAL_NOT_USER_WRITABLE | IVI_VAL_NEVER_CACHE,
                                        ag3446xAttrAutoRangeValue_ReadCallback,
                                        VI_NULL, VI_NULL, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_AUTO_ZERO,
                                       "AG3446X_ATTR_AUTO_ZERO",
                                       AG3446X_VAL_AUTO_ZERO_ON, 0,
                                       ag3446xAttrAutoZero_ReadCallback,
                                       ag3446xAttrAutoZero_WriteCallback,
                                       &attrAutoZeroRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SAMPLE_COUNT,
	                                   "AG3446X_ATTR_SAMPLE_COUNT", 1, 0,
	                                   ag3446xViInt32_ReadCallback,
	                                   ag3446xViInt32_WriteCallback, VI_NULL));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_SAMPLE_COUNT,
	                                         ag3446xAttrSampleCount_RangeTableCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SAMPLE_TRIGGER,
	                                   "AG3446X_ATTR_SAMPLE_TRIGGER",
	                                   AG3446X_VAL_IMMEDIATE, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSampleTriggerRangeTable));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_SAMPLE_INTERVAL,
	                                    "AG3446X_ATTR_SAMPLE_INTERVAL", 1, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrSampleIntervalRangeTable, 0));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_SAMPLE_INTERVAL,
	                                         ag3446xAttrSampleInterval_RangeTableCallback));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_SAMPLE_INTERVAL,
	                                            ag3446xAttrSampleInterval_CheckCallback));
	checkErr (Ivi_SetAttrCoerceCallbackViReal64 (vi, AG3446X_ATTR_SAMPLE_INTERVAL,
												 ag3446xSampleInterval_CoerceCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER,
	                                   "AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER", 0, 0,
	                                   ag3446xViInt32_ReadCallback,
	                                   ag3446xViInt32_WriteCallback,
	                                   &attrSampleCountPreTriggerRangeTable));
	checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi,
	                                           AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER,
	                                           ag3446xAttrSampleCountPreTrigger_CheckCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_TRIGGER_COUNT,
	                                   "AG3446X_ATTR_TRIGGER_COUNT", 1, 0,
	                                   ag3446xViInt32_ReadCallback,
	                                   ag3446xViInt32_WriteCallback,
	                                   &attrTriggerCountRangeTable));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_TRIGGER_COUNT,
	                                         ag3446xAttrTriggerCount_RangeTableCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_DELAY,
	                                    "AG3446X_ATTR_TRIGGER_DELAY", 0.0, 0,
	                                    ag3446xAttrTriggerDelay_ReadCallback,
	                                    ag3446xAttrTriggerDelay_WriteCallback,
	                                    &attrTriggerDelayRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_TRIGGER_DELAY,
	                                            ag3446xAttrTriggerDelay_CheckCallback));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_TRIGGER_DELAY,
	                                         ag3446xAttrTriggerDelay_RangeTableCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_TRIGGER_SLOPE,
                                       "AG3446X_ATTR_TRIGGER_SLOPE",
                                       AG3446X_VAL_NEGATIVE, 0,
                                       ag3446xEnum_ReadCallback,
                                       ag3446xEnum_WriteCallback,
                                       &attrTriggerSlopeRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_MEAS_COMPLETE_DEST,
	                                   "AG3446X_ATTR_MEAS_COMPLETE_DEST", 0, 0,
	                                   VI_NULL, VI_NULL, VI_NULL));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_FREQ_VOLTAGE_RANGE,
	                                    "AG3446X_ATTR_FREQ_VOLTAGE_RANGE", 10.0, 0,
	                                    ag3446xAttrFreqVoltageRange_ReadCallback,
	                                    ag3446xAttrFreqVoltageRange_WriteCallback,
	                                    &attrFreqVoltageRangeRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_FREQ_VOLTAGE_RANGE,
	                                            ag3446xAttrFreqVoltageRange_CheckCallback));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_FREQ_VOLTAGE_RANGE,
	                                         ag3446xAttrFreqVoltageRange_RangeTableCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_TEMP_TRANSDUCER_TYPE,
	                                   "AG3446X_ATTR_TEMP_TRANSDUCER_TYPE",
	                                   AG3446X_VAL_4_WIRE_RTD, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrTempTransducerTypeRangeTable));
	checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi, AG3446X_ATTR_TEMP_TRANSDUCER_TYPE,
	                                           ag3446xAttrTempTransducerType_CheckCallback));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TEMP_RTD_ALPHA,
                                        "AG3446X_ATTR_TEMP_RTD_ALPHA", 85, 0,
                                        ag3446xViReal64_ReadCallback,
                                        ag3446xViReal64_WriteCallback,
                                        &attrTempRtdAlphaRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TEMP_RTD_RES,
                                        "AG3446X_ATTR_TEMP_RTD_RES", 100.0, 0,
                                        ag3446xAttrTempRtdRes_ReadCallback,
                                        ag3446xAttrTempRtdRes_WriteCallback,
                                        &attrTempRtdResRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TEMP_THERMISTOR_RES,
	                                    "AG3446X_ATTR_TEMP_THERMISTOR_RES", 5000, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrTempThermistorResRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_CAL_VALUE,
                                        "AG3446X_ATTR_CAL_VALUE", 0.0, 0,
                                        ag3446xViReal64_ReadCallback,
                                        ag3446xViReal64_WriteCallback, VI_NULL, 0));
    checkErr (Ivi_AddAttributeViString (vi, AG3446X_ATTR_CAL_STRING,
                                        "AG3446X_ATTR_CAL_STRING", "", 0,
                                        ag3446xViString_ReadCallback,
                                        ag3446xViString_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_SECURITY_ENABLED,
                                         "AG3446X_ATTR_SECURITY_ENABLED", VI_TRUE, 0,
                                         ag3446xViBoolean_ReadCallback,
                                         ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_DATA_POINT_COUNT,
	                                   "AG3446X_ATTR_DATA_POINT_COUNT", 1, 0,
	                                   ag3446xViInt32_ReadCallback,
	                                   ag3446xViInt32_WriteCallback, VI_NULL));
    checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_DATA_POINT_COUNT,
                                             ag3446xAttrDataPointCount_RangeTableCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_AUTO_RECALL_ENABLE,
                                         "AG3446X_ATTR_AUTO_RECALL_ENABLE", VI_TRUE,
                                         0, ag3446xViBoolean_ReadCallback,
                                         ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_AVER_ENABLED,
	                                     "AG3446X_ATTR_AVER_ENABLED", VI_FALSE, 0,
	                                     VI_NULL,
	                                     ag3446xAttrAverEnabled_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_LIMIT_ENABLED,
	                                     "AG3446X_ATTR_LIMIT_ENABLED", VI_FALSE, 0,
	                                     ag3446xAttrLimitEnabled_ReadCallback,
	                                     ag3446xAttrLimitEnabled_WriteCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_LOWER_LIMIT,
	                                    "AG3446X_ATTR_LOWER_LIMIT", 0.0, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrLimitRangeTable, 0));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_LOWER_LIMIT,
	                                         ag3446xAttrLowerLimit_RangeTableCallback));
    checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_LOWER_LIMIT,
                                                ag3446xAttrLowerLimit_CheckCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_UPPER_LIMIT,
	                                    "AG3446X_ATTR_UPPER_LIMIT", 0.0, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrLimitRangeTable, 0));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_UPPER_LIMIT,
	                                         ag3446xAttrUpperLimit_RangeTableCallback));
    checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_UPPER_LIMIT,
                                                ag3446xAttrUpperLimit_CheckCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_SCALE_ENABLED,
	                                     "AG3446X_ATTR_SCALE_ENABLED", VI_FALSE, 0,
	                                     ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_SCALE_AUTO_REFERENCE,
                                         "AG3446X_ATTR_SCALE_AUTO_REFERENCE",
                                         VI_TRUE, 0, ag3446xViBoolean_ReadCallback,
                                         ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_SCALE_DB_REFERENCE,
	                                    "AG3446X_ATTR_SCALE_DB_REFERENCE", 0, 0,
	                                    ag3446xAttrScaleDbReference_ReadCallback,
	                                    ag3446xAttrScaleDbReference_WriteCallback,
	                                    &attrScaleDbReferenceRangeTable, 0));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_SCALE_DB_REFERENCE,
	                                         ag3446xAttrScaleDbReference_RangeTableCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_SCALE_DBM_REFERENCE,
	                                    "AG3446X_ATTR_SCALE_DBM_REFERENCE",
	                                    AG3446X_VAL_600, 0,
	                                    ag3446xAttrScaleDbmReference_ReadCallback,
	                                    ag3446xAttrScaleDbmReference_WriteCallback,
	                                    &attrScaleDbmReferenceRangeTable, 0));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_SCALE_DBM_REFERENCE,
	                                         ag3446xAttrScaleDbmReference_RangeTableCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SCALE_FUNCTION,
	                                   "AG3446X_ATTR_SCALE_FUNCTION",
	                                   AG3446X_VAL_SCALE_FUNC_DB, 0,
	                                   ag3446xAttrScaleFunction_ReadCallback,
	                                   ag3446xAttrScaleFunction_WriteCallback,
	                                   VI_NULL));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_SCALE_FUNCTION,
											 ag3446xScaleFunction_RangeTableCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_HIST_ENABLED,
	                                     "AG3446X_ATTR_HIST_ENABLED", VI_FALSE, 0,
	                                     ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_HIST_AUTO_RANGE,
                                         "AG3446X_ATTR_HIST_AUTO_RANGE", VI_TRUE, 0,
                                         ag3446xViBoolean_ReadCallback,
                                         ag3446xViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_HIST_LOWER_RANGE,
                                        "AG3446X_ATTR_HIST_LOWER_RANGE", 0.0, 0,
                                        ag3446xViReal64_ReadCallback,
                                        ag3446xViReal64_WriteCallback,
                                        &attrHistRangeRangeTable, 0));
    checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_HIST_LOWER_RANGE,
                                                ag3446xAttrHistLowerRange_CheckCallback));
    checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_HIST_UPPER_RANGE,
                                        "AG3446X_ATTR_HIST_UPPER_RANGE", 0.0, 0,
                                        ag3446xViReal64_ReadCallback,
                                        ag3446xViReal64_WriteCallback,
                                        &attrHistRangeRangeTable, 0));
    checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_HIST_UPPER_RANGE,
                                                ag3446xAttrHistUpperRange_CheckCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_HIST_POINT,
                                       "AG3446X_ATTR_HIST_POINT", AG3446X_VAL_100, 0,
                                       ag3446xViInt32_ReadCallback,
                                       ag3446xViInt32_WriteCallback,
                                       &attrHistPointRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_CURR_TERMINAL,
	                                   "AG3446X_ATTR_CURR_TERMINAL",
	                                   AG3446X_VAL_CURR_TERM_3, 0,
	                                   ag3446xAttrCurrTerminal_ReadCallback,
	                                   ag3446xAttrCurrTerminal_WriteCallback,
	                                   &attrCurrentTerminalRangeTable));
    checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_VOLT_AUTO_IMPEDANCE,
                                         "AG3446X_ATTR_VOLT_AUTO_IMPEDANCE",
                                         VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
                                         ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_CONF_MEAS,
	                                   "AG3446X_ATTR_CONF_MEAS",
	                                   AG3446X_VAL_CONF_MEAS_CONT, 0, VI_NULL,
	                                   ag3446xAttrConfMeas_WriteCallback,
	                                   &attrConfMeasRangeTable));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_CONF_MEAS,
	                                         ag3446xAttrConfMeas_RangeTableCallback));
	checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi, AG3446X_ATTR_CONF_MEAS,
	                                           ag3446xAttrConfMeas_CheckCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_NULL_ENABLED,
	                                     "AG3446X_ATTR_NULL_ENABLED", VI_FALSE, 0,
	                                     ag3446xAttrNullEnable_ReadCallback,
	                                     ag3446xAttrNullEnable_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_NULL_AUTO_ENABLED,
	                                     "AG3446X_ATTR_NULL_AUTO_ENABLED", VI_FALSE,
	                                     0, ag3446xAttrNullAutoEnable_ReadCallback,
	                                     ag3446xAttrNullAutoEnable_WriteCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_NULL_VALUE,
	                                    "AG3446X_ATTR_NULL_VALUE", 0, 0,
	                                    ag3446xAttrNullValue_ReadCallback,
	                                    ag3446xAttrNullValue_WriteCallback,
	                                    &attrNullCurrentValueRangeTable, 0));
    checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_NULL_VALUE,
                                             ag3446xAttrNullValue_RangeTableCallback));

	checkErr (Ivi_AddAttributeViString (vi, AG3446X_ATTR_ID_QUERY_RESPONSE,
	                                    "AG3446X_ATTR_ID_QUERY_RESPONSE",
	                                    "Agilent/Keysight Technologies,34460A",
	                                    IVI_VAL_NOT_USER_WRITABLE,
	                                    ag3446xAttrIdQueryResponse_ReadCallback,
	                                    VI_NULL));
    checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_OPC_TIMEOUT,
                                       "AG3446X_ATTR_OPC_TIMEOUT",
                                       5000, IVI_VAL_HIDDEN | IVI_VAL_DONT_CHECK_STATUS,
                                       VI_NULL, VI_NULL, VI_NULL));
	
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_SCALE_GAIN,
	                                    "AG3446X_ATTR_SCALE_GAIN", 1.0, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrScaleGainRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_SCALE_OFFSET,
	                                    "AG3446X_ATTR_SCALE_OFFSET", 0.0, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrScaleOffsetRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_SCALE_REFERENCE,
	                                    "AG3446X_ATTR_SCALE_REFERENCE", 0.0, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrScaleReferenceRangeTable, 0));
	checkErr (Ivi_AddAttributeViString (vi, AG3446X_ATTR_SCALE_UNIT,
	                                    "AG3446X_ATTR_SCALE_UNIT", VI_NULL, 0,
	                                    ag3446xViString_ReadCallback,
	                                    ag3446xViString_WriteCallback));
	checkErr (Ivi_SetAttrCheckCallbackViString (vi, AG3446X_ATTR_SCALE_UNIT,
											    ag3446xScaleUnit_CheckCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_SCALE_UNIT_ENABLED,
	                                     "AG3446X_ATTR_SCALE_UNIT_ENABLED", VI_FALSE,
	                                     0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SMOOTHING_RESPONSE,
	                                   "AG3446X_ATTR_SMOOTHING_RESPONSE",
	                                   AG3446X_VAL_SMOOTHING_RESPONSE_FAST, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSmoothingResponseRangeTable));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_SMOOTHING_ENABLED,
	                                     "AG3446X_ATTR_SMOOTHING_ENABLED", VI_TRUE,
	                                     0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_TREND_CHART_ENABLED,
	                                     "AG3446X_ATTR_TREND_CHART_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_MEM_FORM_READING_SEPARATOR,
	                                   "AG3446X_ATTR_MEM_FORM_READING_SEPARATOR",
	                                   AG3446X_VAL_SEPARATOR_COM, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrMemFormReadingSeparatorRangeTable));
	checkErr (Ivi_AddAttributeViBoolean (vi,
	                                     AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED,
	                                     "AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED,
	                                     "AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED",
	                                     VI_TRUE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_SAMPLE_INTERVAL_MIN,
	                                    "AG3446X_ATTR_SAMPLE_INTERVAL_MIN", 1.0,
	                                    IVI_VAL_NEVER_CACHE | IVI_VAL_HIDDEN,
	                                    ag3446xAttrSampleIntervalMin_ReadCallback,
	                                    VI_NULL, VI_NULL, 0));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_CALC_FUNC_ENABLED,
	                                     "AG3446X_ATTR_CALC_FUNC_ENABLED", VI_FALSE,
	                                     IVI_VAL_HIDDEN,
	                                     ag3446xAttrCalcFuncEnabled_ReadCallback,
	                                     VI_NULL));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_OPTION,
	                                   "AG3446X_ATTR_OPTION", 0, IVI_VAL_HIDDEN,
	                                   VI_NULL, VI_NULL, &optionRangeTable));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL", 0,
	                                    IVI_VAL_NEVER_CACHE,
	                                    ag3446xAttrTriggerLevel_ReadCallback,
	                                    ag3446xAttrTriggerLevel_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL,
	                                            ag3446xAttrTriggerLevel_CheckCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_DCV,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_DCV", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    &attrTriggerLevelDcvRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_DCV,
	                                            ag3446xAttrTriggerLevelDcv_CheckCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_DCI,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_DCI", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    &attrTriggerLevelDciRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_DCI,
	                                            ag3446xAttrTriggerLevelDci_CheckCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_ACV,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_ACV", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    &attrTriggerLevelAcvRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_ACV,
	                                            ag3446xAttrTriggerLevelAcv_CheckCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_ACI,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_ACI", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    &attrTriggerLevelAciRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_ACI,
	                                            ag3446xAttrTriggerLevelAci_CheckCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_RES,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_RES", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    &attrTriggerLevelResRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_RES,
	                                            ag3446xAttrTriggerLevelRes_CheckCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_FREQ,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_FREQ", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    &attrTriggerLevelFreqRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_PER,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_PER", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    &attrTriggerLevelPerRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TRIGGER_LEVEL_TEMP,
	                                    "AG3446X_ATTR_TRIGGER_LEVEL_TEMP", 0,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrTriggerLevelMeas_ReadCallback,
	                                    ag3446xAttrTriggerLevelMeas_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_RESOLUTION,
	                                    "AG3446X_ATTR_RESOLUTION", .000001,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrResolution_ReadCallback,
	                                    ag3446xAttrResolution_WriteCallback,
	                                    resDynamicRangeTablePtr, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_APERTURE_TIME_NPLC,
	                                    "AG3446X_ATTR_APERTURE_TIME_NPLC", 10,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrApertureTimeNplc_ReadCallback,
	                                    ag3446xAttrApertureTimeNplc_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_APERTURE_TIME_SECONDS,
	                                    "AG3446X_ATTR_APERTURE_TIME_SECONDS", 0.1,
	                                    IVI_VAL_HIDDEN,
	                                    ag3446xAttrApertureTimeSeconds_ReadCallback,
	                                    ag3446xAttrApertureTimeSeconds_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi,
	                                            AG3446X_ATTR_APERTURE_TIME_SECONDS,
	                                            ag3446xAttrApertureTimeSeconds_CheckCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED,
	                                     "AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_POWER_LIMIT_ENABLED,
	                                     "AG3446X_ATTR_POWER_LIMIT_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi,
	                                     AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED,
	                                     "AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi,
	                                     AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED,
	                                     "AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC,
	                                    "AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC", 0, 0,
	                                    ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrTempTcFixedRefJuncRangeTable, 0));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE,
	                                   "AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE",
	                                   AG3446X_VAL_TEMP_REF_JUNC_INTERNAL, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrTempTcRefJuncTypeRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_TEMP_TC_TYPE,
	                                   "AG3446X_ATTR_TEMP_TC_TYPE",
	                                   AG3446X_VAL_TEMP_TC_E, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrTempTcTypeRangeTable));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_TEMP_TC_CHECK_ENABLED,
	                                     "AG3446X_ATTR_TEMP_TC_CHECK_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ,
	                                    "AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ", 0,
	                                    0, ag3446xViReal64_ReadCallback,
	                                    ag3446xViReal64_WriteCallback,
	                                    &attrTempTcRefJuncOffsAdjRangeTable, 0));
	checkErr (Ivi_AddAttributeViBoolean (vi,
	                                     AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED,
	                                     "AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_NEVER_CACHE,
	                                   ag3446xAttrSecondaryFunction_ReadCallback,
	                                   ag3446xAttrSecondaryFunction_WriteCallback,
	                                   VI_NULL));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_VDC,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_VDC",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncVdcRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_VAC,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_VAC",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncVacRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_CDC,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_CDC",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncCdcRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_CAC,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_CAC",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncCacRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_FREQ,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_FREQ",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncFreqRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_PER,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_PER",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncPerRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_RES,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_RES",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncResRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_TEMP,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_TEMP",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncTempRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_DC_RATIO",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncDcRatioRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_SECONDARY_FUNCTION_CAP,
	                                   "AG3446X_ATTR_SECONDARY_FUNCTION_CAP",
	                                   AG3446X_VAL_SEC_FUNC_OFF, IVI_VAL_HIDDEN,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrSecFuncCapacitanceRangeTable));
	checkErr (Ivi_AddAttributeViBoolean (vi, AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED,
	                                     "AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED",
	                                     VI_FALSE, 0, ag3446xViBoolean_ReadCallback,
	                                     ag3446xViBoolean_WriteCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, AG3446X_ATTR_RANGE_CHANGE_MODE,
	                                   "AG3446X_ATTR_RANGE_CHANGE_MODE",
	                                   AG3446X_VAL_RANGE_CHANGE_CONT, 0,
	                                   ag3446xEnum_ReadCallback,
	                                   ag3446xEnum_WriteCallback,
	                                   &attrRangeChangeModeRangeTable));
	checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi, AG3446X_ATTR_RANGE_CHANGE_MODE,
	                                           ag3446xAttrRangeChangeMode_CheckCallback));
	checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi,
	                                             AG3446X_ATTR_POWER_LIMIT_ENABLED,
	                                             ag3446xAttrPowerLimitEnabled_CheckCallback));
	checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi,
	                                             AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED,
	                                             ag3446xAttrOffsetCompensateEnabled_CheckCallback));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_APERTURE_TIME_SECONDS,
	                                         ag3446xAttrApertureTimeSeconds_RangeTableCallback));
	checkErr (Ivi_SetAttrCoerceCallbackViReal64 (vi,
	                                             AG3446X_ATTR_APERTURE_TIME_SECONDS,
	                                             ag3446xAttrApertureTimeSeconds_CoerceCallback));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_APERTURE_TIME_NPLC,
	                                         ag3446xAttrApertureTimeNplc_RangeTableCallback));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, AG3446X_ATTR_RESOLUTION,
	                                         ag3446xAttrResolution_RangeTableCallback));
	
	if (!IS_34465A(modelNum) && !IS_34470A(modelNum) && !IS_EDU34450A(modelNum))
	{
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER)); 	
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_TRIGGER_LEVEL));			  	
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED)); 	
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_POWER_LIMIT_ENABLED));    	
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED)); 		
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED)); 			
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_TEMP_TC_CHECK_ENABLED));  	
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ)); 	
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED)); 			
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SECONDARY_FUNCTION));     	
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED)); 	 
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_MEM_FORM_READING_SEPARATOR)); 		
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED));		
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED));			
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SCALE_GAIN));				     
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SCALE_OFFSET));			     
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SCALE_REFERENCE));		     
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SCALE_UNIT));		  		      
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SCALE_UNIT_ENABLED));		   
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SMOOTHING_RESPONSE));		  
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_SMOOTHING_ENABLED));		  
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_TREND_CHART_ENABLED));
		checkErr (Ivi_DeleteAttribute(vi, AG3446X_ATTR_RANGE_CHANGE_MODE));
	}
	else 
	{
		checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_FUNCTION,
										AG3446X_ATTR_SMOOTHING_RESPONSE, VI_TRUE));
		checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_SMOOTHING_ENABLED,
	                                    AG3446X_ATTR_CALC_FUNC_ENABLED, VI_TRUE));
	}

    /*- Setup attribute invalidations -----------------------------------*/
    checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_FUNCTION,
                                            AG3446X_ATTR_RANGE, VI_TRUE));
    checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_FUNCTION,
                                            AG3446X_ATTR_RESOLUTION_ABSOLUTE, VI_TRUE));
    checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_RANGE,
                                            AG3446X_ATTR_RESOLUTION_ABSOLUTE, VI_TRUE));
    checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_FUNCTION,
                                            AG3446X_ATTR_APERTURE_TIME, VI_TRUE));
    checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_FUNCTION,
                                            AG3446X_ATTR_AUTO_ZERO, VI_TRUE));
	checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_AVER_ENABLED,
	                                        AG3446X_ATTR_CALC_FUNC_ENABLED, VI_TRUE));
	checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_LIMIT_ENABLED,
	                                        AG3446X_ATTR_CALC_FUNC_ENABLED, VI_TRUE));
	checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_SCALE_ENABLED,
	                                        AG3446X_ATTR_CALC_FUNC_ENABLED, VI_TRUE));
	checkErr (Ivi_AddAttributeInvalidation (vi, AG3446X_ATTR_HIST_ENABLED,
	                                        AG3446X_ATTR_CALC_FUNC_ENABLED, VI_TRUE));


Error:
    return error;
}

/*****************************************************************************
 *  Function: ag3446x_GetDriverSetupOption
 *  Purpose:  Get the value of a DriverSetup option.  The driver setup string
 *            is part of the option string the user passes to the
 *            tkds30xx_InitWithOptions function.  Specifically it is the part
 *            that follows "DriverSetup=".  This function assumes the
 *            DriverSetup string has the following format:
 *              "OptionTag1 : OptionValue1; OptionTag2 : OptionValue2"
 *            Leading and trailing white space is removed from the option
 *            value and both the option tag and option value may contain
 *            white space.  The option tag is case sensitive.
 *
 *            Example:
 *
 *              "DriverSetup= Model : InstrX ; Special Option:Feature Y "
 *
 *              optionTag "Model"          returns optionValue "InstrX"
 *
 *              optionTag "Special Option" returns optionValue "Feature Y"
 *****************************************************************************/
static ViStatus ag3446x_GetDriverSetupOption (ViSession vi,
                                              ViConstString optionTag,
                                              ViInt32 optionValueSize,
                                              ViChar optionValue[])
{
    ViStatus error = VI_SUCCESS;
    ViChar   setup[BUFFER_SIZE];
    ViChar   * searchOrigin;
    ViChar   * start;
    ViChar   * end;
    ViInt32  n;

    checkErr (Ivi_LockSession (vi, VI_NULL));

    if ((optionValue != VI_NULL) && (optionValueSize > 0))
        optionValue[0] = 0;

    if ((optionTag != VI_NULL) && (optionValue != VI_NULL) && (optionValueSize > 1))
    {
        checkErr (Ivi_GetAttributeViString (vi, "", IVI_ATTR_DRIVER_SETUP,
                                            0, BUFFER_SIZE, setup));
        searchOrigin = setup;
        while (searchOrigin != VI_NULL)
        {
            searchOrigin = strstr (searchOrigin, optionTag);
            if (searchOrigin)
            {
                searchOrigin += strlen (optionTag);
                start         = searchOrigin;
                while (isspace (*start))
                    start++;
                if (*start == ':')
                {
                    start++;
                    while (isspace (*start))
                        start++;
                    if (*start)
                    {
                        end = strchr (start, ';');
                        if (start != end)
                        {
                            end = (end) ? --end : &setup[strlen (setup) - 1];
                            while (isspace (*end))
                                end--;
                            n = (ViInt32) (end - start) + 1;
                            if (n > optionValueSize - 1)
                                n = optionValueSize - 1;
                            strncpy (optionValue, start, n);
                            optionValue[n] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: StringToNumeric
 *
 * Purpose:  This function transfers the string with symbol to numeric.
 *****************************************************************************/
static ViInt32 *StringToNumeric (ViChar inputStr[],
                                 ViInt32 *outputNum)
{
    ViInt32 strLength = (ViInt32) strlen (inputStr);
    ViChar  *newStr   = 0;

    newStr = (ViChar *) malloc (strLength);
    strncpy (newStr, inputStr + 1, strLength - 1);
    newStr[strLength - 1] = 0;
    *outputNum            = atoi (newStr);
    free (newStr);

    return outputNum;
}

/*****************************************************************************
 * Function:    StringToReal64Array
 * Description: Convert the delimiter separated data string into ViReal64 array.
 *              The return value will be the count of data element converted.
 *****************************************************************************/
static ViInt32 StringToReal64Array (ViChar dataStr[],
                                    ViInt32 resultDataSize,
                                    ViReal64 resultData[],
                                    ViChar delimiter)
{
    ViInt32 i, iArrayIdx, iNumLen, iLoopCnt = (ViInt32) strlen (dataStr);

    for (i = 0, iArrayIdx = 0, iNumLen = 0; iArrayIdx < resultDataSize && i < iLoopCnt; ++i)
    {
        if (dataStr[i] == delimiter || i == iLoopCnt - 1)
        {
            sscanf (dataStr + i - iNumLen, "%Le", &resultData[iArrayIdx++]);
            iNumLen = 0;
        }
        else if (dataStr[i] != delimiter)
        {
            ++iNumLen;
        }
    }

    return iArrayIdx;
}

/*****************************************************************************
 *  Function: ag3446x_QueryID
 *  Purpose:  Query the instrument for its id string.
 *****************************************************************************/
static ViStatus ag3446x_QueryID (ViSession vi,
                                  ViSession io,
                                  ViInt32 bufferSize,
                                  ViChar buffer[])
{
    ViStatus error = VI_SUCCESS;
    ViUInt32 readCount;

    viCheckErr (viWrite (io, "*IDN?", 5, VI_NULL));
    viCheckErr (viRead (io, buffer, bufferSize - 1, &readCount));
    buffer[readCount] = '\0';

Error:
    return error;
}

/*****************************************************************************
 *  Function: ag3446x_QueryOptions
 *  Purpose:  Query the instrument for its option string.
 *****************************************************************************/
static ViStatus ag3446x_QueryOptions (ViSession vi,
                                      ViSession io,
                                      ViInt32 bufferSize,
                                      ViChar buffer[])
{								   
    ViStatus error = VI_SUCCESS;
    ViUInt32 readCount;

    viCheckErr (viWrite (io, "*OPT?", 5, VI_NULL));
    viCheckErr (viRead (io, buffer, bufferSize - 1, &readCount));
    buffer[readCount] = '\0';

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446x_GetModelFromBuffer
 * Purpose:  This function returns model number from buffer. If table
 *           hp33120a_ModelTable does not contains this model, function
 *           returns VI_ERROR_FAIL_ID_QUERY;
 *****************************************************************************/
static ViStatus ag3446x_GetModelFromBuffer (ViSession vi,
                                             ViConstString buffer,
                                             ViInt32* pModelType)
{
    ViStatus error = VI_SUCCESS;
    ViChar   tmp_buffer[BUFFER_SIZE];

    sscanf (buffer, "%*[^,],%[^,]", tmp_buffer);
    ag3446x_RemoveSurroundingWhiteSpace (tmp_buffer);
    if (Ivi_GetValueFromTable (ag3446x_ModelTable, tmp_buffer, pModelType) < VI_SUCCESS)
        viCheckErr (VI_ERROR_FAIL_ID_QUERY);

Error:
    return error;
}

/*****************************************************************************
 * Function: ag3446x_GetOptionsFromBuffer
 * Purpose:  This function returns option number from buffer.
 *****************************************************************************/
static ViStatus ag3446x_GetOptionsFromBuffer (ViSession vi,
                                          	  ViConstString buffer,
                                              ViInt32 *value)
{
	ViStatus 	error = VI_SUCCESS;
    ViPBuf	 	p = VI_NULL;
	ViChar		optionStr[BUFFER_SIZE] = "";
	ViChar   	tmp_buffer[BUFFER_SIZE] = ""; 
	ViInt32	 	option = 0;

	if (value == VI_NULL)
	{
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Value");
	}
	
	*value = 0;
	if (buffer != VI_NULL)
	{
		strncpy(optionStr, buffer, BUFFER_SIZE);
		p = strtok(optionStr, ",");
		while(p)
		{
			strncpy(tmp_buffer, p, BUFFER_SIZE);
			ag3446x_RemoveSurroundingWhiteSpace (tmp_buffer);
		
	    	if (!(ag3446x_GetValueFromTable (ag3446x_OptionTable, tmp_buffer, &option) < VI_SUCCESS))
			{
				*value |= option;
			}
												 
			p = strtok(NULL, ",");
		}
	}
	
Error:
	return error;
}

/*****************************************************************************
 * Function: ag3446x_RemoveSurroundingWhiteSpace
 * Purpose:  This function removes surrounding white space around a string
 *****************************************************************************/
static void ag3446x_RemoveSurroundingWhiteSpace (ViChar string[])
{
    ViChar  *start = string,
    *end;
    ViInt32 lengthWithoutLeadingWS;

    if (start)
    {
        while (*start && isspace ((unsigned char) *start))
            start++;

        lengthWithoutLeadingWS = (ViInt32) strlen (start);
        memmove (string, start, lengthWithoutLeadingWS);
        end = string + lengthWithoutLeadingWS;
        while (end > string && isspace ((unsigned char) *(end - 1)))
            end--;

        *end = '\0';
    }
}

/*****************************************************************************
 * Function: ag3446x_GetValueFromTable
 * Purpose:  This function get the value for the given string in the specified
 *			 table
 *****************************************************************************/
static ViStatus ag3446x_GetValueFromTable (IviStringValueTable stringTable, 
										   ViChar string[ ], 
										   ViInt32* value)
{
   IviStringValueEntry *entry;    

   for (entry=&stringTable[0]; entry->string; entry++)
   {
      if (ag3446x_StrCmpWithoutTerminators(entry->string, string))
      {
         if (value != VI_NULL)
		 {
            *value = entry->value;
		 }
		 
         return VI_SUCCESS;
      }
   }

   return IVI_ERROR_INVALID_VALUE;
}


/*****************************************************************************
 * Function: ag3446x_StrCmpWithoutTerminators
 * Purpose:  This function will compare a string with one returned from an 
 *			 instrument that may contain I/O terminators.  It will return 
 *			 VI_TRUE if the strings match, VI_FALSE otherwise 
 *****************************************************************************/
static ViBoolean ag3446x_StrCmpWithoutTerminators(ViConstString string, ViConstString stringWithTerminators)
{
   ViConstString ptr;     

   if (string == 0 || stringWithTerminators == 0)
      {
      return(string == stringWithTerminators);
      }
   if (strncmp(string, stringWithTerminators, strlen(string)) == 0)
      {
      ptr = stringWithTerminators + strlen(string);

      if (*ptr == '\0' || *ptr == '\r' || *ptr == '\n')
         return VI_TRUE;
      else
         return VI_FALSE;
      }

   return VI_FALSE;
}

/*****************************************************************************
 *------------------- End Instrument Driver Source Code ---------------------*
 *****************************************************************************/
