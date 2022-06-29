#include  "ag3446x_testCppUnit.h"
#include "ag3446x.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "windows.h"

#define INVALID_ENUM_VALUE    -5000   /*Invalid enum parameter value*/

CPPUNIT_TEST_SUITE_REGISTRATION(DriverFunctionalityTest);
/****************************************************************************
 *------------------------------- Global Variable --------------------------*
 ****************************************************************************/
ViSession vi = VI_NULL;

ViStatus testInit()
{
	ViStatus error = VI_SUCCESS;
	
    checkErr(ag3446x_init ("34470A",VI_TRUE,VI_TRUE,&vi));
	
Error:
	return error;
}

void testClose()
{
	ag3446x_close(vi);
	vi = VI_NULL;
}

void DriverFunctionalityTest::setUp()
{
	testInit();
}

void DriverFunctionalityTest::tearDown()
{
	testClose();
	Sleep(500);
}

/****************************************************************************
 *------------------------- Attribute Test --------------------------------*
 ****************************************************************************/
/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_VOLT_AUTO_IMPEDANCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_VOLT_AUTO_IMPEDANCE ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_CURR_TERMINAL_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_CURR_TERMINAL ;
	ViInt32 defaultValue = 3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CURR_TERMINAL_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_CURR_TERMINAL ;
	ViInt32 discreteValue = AG3446X_VAL_CURR_TERM_3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CURR_TERMINAL_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_CURR_TERMINAL ;
	ViInt32 discreteValue = AG3446X_VAL_CURR_TERM_10 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_AUTO_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_NULL_AUTO_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_VALUE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_NULL_VALUE ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_VALUE_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_NULL_VALUE ;
	ViReal64 CloseminimumValue = -12 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_VALUE_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_NULL_VALUE ;
	ViReal64 ClosemaximumValue = 12 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_VALUE_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_NULL_VALUE ;
	 
	ViReal64 randomValue = 7.51 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_VALUE_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_NULL_VALUE;
	ViReal64 ViolationValue = -13 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_VALUE_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_NULL_VALUE;
	ViReal64 ViolationValue = 13 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_NULL_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_NULL_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
		
/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_OFFSET_COMPENSATE_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64(vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_POWER_LIMIT_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_POWER_LIMIT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64(vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_RANGE_CHANGE_MODE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_RANGE_CHANGE_MODE ;
	ViInt32 defaultValue = AG3446X_VAL_RANGE_CHANGE_FAST ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_RANGE_CHANGE_MODE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_RANGE_CHANGE_MODE ;
	ViInt32 discreteValue = AG3446X_VAL_RANGE_CHANGE_FAST ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_RANGE_CHANGE_MODE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_RANGE_CHANGE_MODE ;
	ViInt32 discreteValue = AG3446X_VAL_RANGE_CHANGE_CONT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_DATA_POINT_COUNT_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_DATA_POINT_COUNT ;
	ViInt32 defaultValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_DATA_POINT_COUNT_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_DATA_POINT_COUNT ;
	ViInt32 CloseminimumValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_DATA_POINT_COUNT_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_DATA_POINT_COUNT ;
	ViInt32 ClosemaximumValue = 2000000 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_DATA_POINT_COUNT_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_DATA_POINT_COUNT ;
	 
	ViInt32 randomValue = 6530 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_DATA_POINT_COUNT_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_DATA_POINT_COUNT;
	ViInt32 ViolationValue = 0 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_DATA_POINT_COUNT_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_DATA_POINT_COUNT;
	ViInt32 ViolationValue = 2000001 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_AUTO_RECALL_ENABLE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_AUTO_RECALL_ENABLE ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_MEM_FORM_READING_SEPARATOR_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_MEM_FORM_READING_SEPARATOR ;
	ViInt32 defaultValue = AG3446X_VAL_SEPARATOR_COM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_MEM_FORM_READING_SEPARATOR_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_MEM_FORM_READING_SEPARATOR ;
	ViInt32 discreteValue = AG3446X_VAL_SEPARATOR_COM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_MEM_FORM_READING_SEPARATOR_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_MEM_FORM_READING_SEPARATOR ;
	ViInt32 discreteValue = AG3446X_VAL_SEPARATOR_SEM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_MEM_FORM_READING_SEPARATOR_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_MEM_FORM_READING_SEPARATOR ;
	ViInt32 discreteValue = AG3446X_VAL_SEPARATOR_TAB ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SECURITY_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SECURITY_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	//CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	//CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	//CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	//
	//CPPUNIT_ASSERT( falseValue == returnValue );	/* Need to know the password of calibration*/	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_CAL_VALUE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_CAL_VALUE ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_LIMIT_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_LIMIT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;


	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE ;
	ViReal64 CloseminimumValue = -1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE ;
	ViReal64 ClosemaximumValue = -1.0E-15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE ;
	 
	ViReal64 randomValue = -320967893870173.62 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE;
	ViReal64 ViolationValue = -1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE ;
	ViReal64 ClosemaximumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE ;
	 
	ViReal64 randomValue = 0.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_ViolationMaxValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE;
	ViReal64 ViolationValue = -0.000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_LOWER_RANGE_ViolationMaxValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_LOWER_RANGE;
	ViReal64 ViolationValue = 1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
					
		
/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE;
	ViReal64 ViolationValue = -1.000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE ;
	ViReal64 ClosemaximumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE ;
	 
	ViReal64 randomValue = 0.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_CloseminimumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE ;
	ViReal64 CloseminimumValue = 1.0E-15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_ClosemaximumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE ;
	ViReal64 ClosemaximumValue = 1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_UPPER_RANGE_RandomValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_UPPER_RANGE ;
	 
	ViReal64 randomValue = 574418368776499.50 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, AG3446X_ATTR_HIST_AUTO_RANGE, 0, VI_FALSE));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_HIST_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_AUTO_RANGE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_HIST_AUTO_RANGE ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_POINT_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_HIST_POINT ;
	ViInt32 defaultValue = AG3446X_VAL_100 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_POINT_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_POINT ;
	ViInt32 discreteValue = AG3446X_VAL_10 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_POINT_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_POINT ;
	ViInt32 discreteValue = AG3446X_VAL_20 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_POINT_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_POINT ;
	ViInt32 discreteValue = AG3446X_VAL_40 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_POINT_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_POINT ;
	ViInt32 discreteValue = AG3446X_VAL_100 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_POINT_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_POINT ;
	ViInt32 discreteValue = AG3446X_VAL_200 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_HIST_POINT_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_HIST_POINT ;
	ViInt32 discreteValue = AG3446X_VAL_400 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
				

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT ;
	ViReal64 CloseminimumValue = -1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT ;
	ViReal64 ClosemaximumValue = -1.0E-15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT ;
	 
	ViReal64 randomValue = -151623297376833.50 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT;
	ViReal64 ViolationValue = 0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT ;
	ViReal64 ClosemaximumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT ;
	 
	ViReal64 randomValue = 0.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_ViolationMaxValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT;
	ViReal64 ViolationValue = 0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}	

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_LOWER_LIMIT_ViolationMaxValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_LOWER_LIMIT;
	ViReal64 ViolationValue = 1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_UPPER_LIMIT, 0, 1E15));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT;
	ViReal64 ViolationValue = -1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

	
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT ;
	ViReal64 ClosemaximumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT ;
	 
	ViReal64 randomValue = 0.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_CloseminimumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT ;
	ViReal64 CloseminimumValue = 1.0E-15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_ClosemaximumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT ;
	ViReal64 ClosemaximumValue = +1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_UPPER_LIMIT_RandomValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_UPPER_LIMIT ;
	 
	ViReal64 randomValue = 447539143315917.06 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}



/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

/*	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );*/	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_AVER_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_AVER_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_AUTO_REFERENCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_AUTO_REFERENCE ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_FUNCTION_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_SCALE_FUNC_DB ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_FUNCTION ;
	ViInt32 discreteValue = AG3446X_VAL_SCALE_FUNC_DB ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_FUNCTION ;
	ViInt32 discreteValue = AG3446X_VAL_SCALE_FUNC_DBM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViReal64 defaultValue = AG3446X_VAL_600 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_50 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_75 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_93 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_110 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_124 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_125 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_135 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_150 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index9()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_250 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index10()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_300 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index11()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_500 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index12()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_600 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index13()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_800 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index14()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_900 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index15()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_1000 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index16()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_1200 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DBM_REFERENCE_DiscreteValue_ReadWrite_NullChannel_Index17()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DBM_REFERENCE ;
	ViInt32 discreteValue = AG3446X_VAL_8000 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( discreteValue, returnValue, abs(discreteValue) / 10e7 );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DB_REFERENCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_DB_REFERENCE ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DB_REFERENCE_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DB_REFERENCE ;
	ViReal64 CloseminimumValue = -200.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DB_REFERENCE_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DB_REFERENCE ;
	ViReal64 ClosemaximumValue = 200.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DB_REFERENCE_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DB_REFERENCE ;
	 
	ViReal64 randomValue = 186.82 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DB_REFERENCE_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DB_REFERENCE;
	ViReal64 ViolationValue = -201 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_DB_REFERENCE_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_DB_REFERENCE;
	ViReal64 ViolationValue = 201 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 defaultValue = 1.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 CloseminimumValue = -1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 ClosemaximumValue = -1.0E-15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = -1.0E+15 + rand() % 100 * 1.0E15 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN;
	ViReal64 ViolationValue = -1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN;
	ViReal64 ViolationValue = -0.9999999E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 ClosemaximumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0.0 + rand() % 100 * 0 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ViolationMinValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN;
	ViReal64 ViolationValue = -0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ViolationMaxValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN;
	ViReal64 ViolationValue = 0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_CloseminimumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 CloseminimumValue = +1.0E-15  ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ClosemaximumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 ClosemaximumValue = 1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_RandomValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = +1.0E-15 + rand() % 100 * 1.0E15 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ViolationMinValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN;
	ViReal64 ViolationValue = 0.9999999E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_GAIN_ViolationMaxValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_GAIN;
	ViReal64 ViolationValue = 1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 CloseminimumValue = -1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 ClosemaximumValue = -1.0E-15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = -1.0E+15 + rand() % 100 * 1.0E15 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET;
	ViReal64 ViolationValue = -1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET;
	ViReal64 ViolationValue = -0.9999999E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 ClosemaximumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0.0 + rand() % 100 * 0 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ViolationMinValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET;
	ViReal64 ViolationValue = -0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ViolationMaxValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET;
	ViReal64 ViolationValue = 0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_CloseminimumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 CloseminimumValue = +1.0E-15  ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ClosemaximumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 ClosemaximumValue = 1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_RandomValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = +1.0E-15 + rand() % 100 * 1.0E15 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ViolationMinValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET;
	ViReal64 ViolationValue = 0.9999999E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_OFFSET_ViolationMaxValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_OFFSET;
	ViReal64 ViolationValue = 1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 CloseminimumValue = -1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 ClosemaximumValue = -1.0E-15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = -1.0E+15 + rand() % 100 * 1.0E15 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE;
	ViReal64 ViolationValue = -1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE;
	ViReal64 ViolationValue = -0.9999999E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 ClosemaximumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0.0 + rand() % 100 * 0 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ViolationMinValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE;
	ViReal64 ViolationValue = -0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ViolationMaxValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE;
	ViReal64 ViolationValue = 0.0000001E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_CloseminimumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 CloseminimumValue = +1.0E-15  ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ClosemaximumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 ClosemaximumValue = 1.0E+15 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_RandomValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = +1.0E-15 + rand() % 100 * 1.0E15 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ViolationMinValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE;
	ViReal64 ViolationValue = 0.9999999E-15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_REFERENCE_ViolationMaxValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SCALE_REFERENCE;
	ViReal64 ViolationValue = 1.0000001E15 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SCALE_UNIT_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SCALE_UNIT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SMOOTHING_RESPONSE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SMOOTHING_RESPONSE ;
	ViInt32 defaultValue = AG3446X_VAL_SMOOTHING_RESPONSE_FAST ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SMOOTHING_RESPONSE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SMOOTHING_RESPONSE ;
	ViInt32 discreteValue = AG3446X_VAL_SMOOTHING_RESPONSE_SLOW ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SMOOTHING_RESPONSE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SMOOTHING_RESPONSE ;
	ViInt32 discreteValue = AG3446X_VAL_SMOOTHING_RESPONSE_MEDIUM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SMOOTHING_RESPONSE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SMOOTHING_RESPONSE ;
	ViInt32 discreteValue = AG3446X_VAL_SMOOTHING_RESPONSE_FAST ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SMOOTHING_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SMOOTHING_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TREND_CHART_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TREND_CHART_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 defaultValue = AG3446X_VAL_CONF_MEAS_CONT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_CONT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_AC_CURRENT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_DC_CURRENT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_DIODE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_FREQ ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_PER ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_RES ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_FRES ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index9()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_TEMP ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index10()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_AC_VOLTAGE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index11()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_DC_VOLTAGE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index12()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_DC_VOLTAGE_RATIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	

/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_CONF_MEAS_DiscreteValue_ReadWrite_NullChannel_Index13()
{
	ViAttr attributeId = AG3446X_ATTR_CONF_MEAS ;
	ViInt32 discreteValue = AG3446X_VAL_CONF_MEAS_CAP ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}				

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_DC_VOLTS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_DC_VOLTS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_AC_VOLTS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_DC_CURRENT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_AC_CURRENT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_2_WIRE_RES ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_4_WIRE_RES ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index7()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_FREQ ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index8()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_PERIOD ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index9()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_TEMPERATURE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index10()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_CONTINUITY ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index11()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_DIODE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index12()
{
	
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_DC_VOLTS_RATIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index13()
{
	ViAttr attributeId = AG3446X_ATTR_FUNCTION ;
	ViInt32 discreteValue = AG3446X_VAL_CAPACITANCE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_AUTO_ZERO_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_AUTO_ZERO ;
	ViInt32 defaultValue = AG3446X_VAL_AUTO_ZERO_OFF ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0,  AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_AUTO_ZERO_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	
	ViAttr attributeId = AG3446X_ATTR_AUTO_ZERO ;
	ViInt32 defaultValue = AG3446X_VAL_AUTO_ZERO_OFF ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0,  AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_AUTO_ZERO_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	
	ViAttr attributeId = AG3446X_ATTR_AUTO_ZERO ;
	ViInt32 defaultValue = AG3446X_VAL_AUTO_ZERO_ON ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0,  AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_AUTO_ZERO_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	
	ViAttr attributeId = AG3446X_ATTR_AUTO_ZERO ;
	ViInt32 defaultValue = AG3446X_VAL_AUTO_ZERO_ONCE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0,  AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == (returnValue+2) );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC ;
	ViReal64 CloseminimumValue = -20 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC ;
	ViReal64 ClosemaximumValue = 80 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = -20 + rand() % 100 * 100 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC;
	ViReal64 ViolationValue = -21 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC;
	ViReal64 ViolationValue = 81 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE ;
	ViInt32 defaultValue = AG3446X_VAL_TEMP_REF_JUNC_INTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_REF_JUNC_INTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_REF_JUNC_FIXED ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_TYPE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_TYPE ;
	ViInt32 defaultValue = AG3446X_VAL_TEMP_TC_E ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_TC_E ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_TC_J ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_TC_K ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_TC_N ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_TC_R ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_TYPE_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_TEMP_TC_T ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_CHECK_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_CHECK_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ ;
	ViReal64 CloseminimumValue = -20 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ ;
	ViReal64 ClosemaximumValue = 20 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = -20 + rand() % 100 * 40 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ;
	ViReal64 ViolationValue = -21 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ;
	ViReal64 ViolationValue = 21 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SECONDARY_FUNCTION_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SECONDARY_FUNCTION ;
	ViInt32 defaultValue = AG3446X_VAL_SEC_FUNC_OFF ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SECONDARY_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SECONDARY_FUNCTION ;
	ViInt32 discreteValue = AG3446X_VAL_SEC_FUNC_OFF ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SECONDARY_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SECONDARY_FUNCTION ;
	ViInt32 discreteValue = AG3446X_VAL_SEC_FUNC_CALC ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SECONDARY_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_SECONDARY_FUNCTION ;
	ViInt32 discreteValue = AG3446X_VAL_SEC_FUNC_VAC ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SECONDARY_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_SECONDARY_FUNCTION ;
	ViInt32 discreteValue = AG3446X_VAL_SEC_FUNC_PTP ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SLOPE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SLOPE ;
	ViInt32 defaultValue = AG3446X_VAL_NEGATIVE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SLOPE ;
	ViInt32 defaultValue = AG3446X_VAL_POSITIVE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SLOPE ;
	ViInt32 defaultValue = AG3446X_VAL_NEGATIVE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_TYPE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_TYPE ;
	ViInt32 defaultValue = AG3446X_VAL_4_WIRE_RTD ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_TYPE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_TYPE ;
	ViInt32 defaultValue = AG3446X_VAL_2_WIRE_RTD ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_TYPE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_TYPE ;
	ViInt32 defaultValue = AG3446X_VAL_4_WIRE_RTD ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_TYPE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_TYPE ;
	ViInt32 defaultValue = AG3446X_VAL_2_WIRE_THER ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_TYPE_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_TYPE ;
	ViInt32 defaultValue = AG3446X_VAL_4_WIRE_THER ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_TYPE_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_TYPE ;
	ViInt32 discreteValue = AG3446X_VAL_THERMOCOUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_AC_MAX_FREQ_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_AC_MAX_FREQ ;
	ViReal64 defaultValue = 300000.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_RESOLUTION_ABSOLUTE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_RESOLUTION_ABSOLUTE ;
	ViReal64 defaultValue = 0.000001 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 0.1));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_RANGE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_RANGE ;
	ViReal64 defaultValue = AG3446X_VAL_AUTO_RANGE_ON ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_FREQ_VOLTAGE_RANGE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_FREQ_VOLTAGE_RANGE ;
	ViReal64 defaultValue = 10.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SOURCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SOURCE ;
	ViInt32 defaultValue = AG3446X_VAL_IMMEDIATE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SOURCE ;
	ViInt32 defaultValue = AG3446X_VAL_IMMEDIATE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SOURCE ;
	ViInt32 defaultValue = AG3446X_VAL_EXTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SOURCE ;
	ViInt32 defaultValue = AG3446X_VAL_SOFTWARE_TRIG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AG3446X_VAL_INTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_DELAY_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_DELAY ;
	ViReal64 defaultValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
		
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_DELAY_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_DELAY ;
	ViReal64 CloseminimumValue = 0.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_DELAY_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_DELAY ;
	ViReal64 ClosemaximumValue = 3600.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_DELAY_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_DELAY ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0.0 + rand() % 100 * 3600 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_DELAY_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_DELAY;
	ViReal64 ViolationValue = -3 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_DELAY_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_DELAY;
	ViReal64 ViolationValue = 3601 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1000));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 CloseminimumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1000));
	CloseminimumValue = -1000 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	CloseminimumValue = -120 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	CloseminimumValue = -1000 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 ClosemaximumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1000));
	ClosemaximumValue = 1000; 
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ClosemaximumValue = 120; 
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ClosemaximumValue = 1000; 
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 returnValue;
    ViReal64 randomValue;
          
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1000));
	randomValue = -1000 + rand() % 100 * 2000 / 100.00;
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	randomValue = -120 + rand() % 100 * 240 / 100.00;
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	randomValue = -1000 + rand() % 100 * 2000 / 100.00;
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1000));
	ViolationValue = -1001;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ViolationValue = -121;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = -1001;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1000));
	ViolationValue = 1001;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ViolationValue = 121;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = 1001;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_CloseminimumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 CloseminimumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	CloseminimumValue = -12 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	CloseminimumValue = -1.2 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	CloseminimumValue = -3.6 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 ClosemaximumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	ClosemaximumValue = 12 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	ClosemaximumValue = 1.2 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ClosemaximumValue = 3.6 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 returnValue;
    ViReal64 randomValue;
          
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	randomValue = -12 + rand() % 100 * 24 / 100.00;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	randomValue = -1.2 + rand() % 100 * 2.4 / 100.00 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	randomValue = -3.6 + rand() % 100 * 7.2 / 100.00 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMinValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 returnValue;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	ViolationValue = -12.1;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	ViolationValue = -1.21;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));		

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = -3.61;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMaxValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 returnValue;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	ViolationValue = 12.1;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	ViolationValue = 1.21;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));		

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = 3.61;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	
}

/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_CloseminimumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 CloseminimumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 750));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ClosemaximumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 ClosemaximumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 750));
	ClosemaximumValue = 1000; 
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ClosemaximumValue = 120; 
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ClosemaximumValue = 1000; 
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_RandomValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 returnValue;
    ViReal64 randomValue;
          
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 750));
	randomValue = rand() % 100 * 1000 / 100.00;
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	randomValue = rand() % 100 * 120 / 100.00;
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	randomValue = rand() % 100 * 1000 / 100.00;
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMinValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 750));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMaxValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_VOLTS));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 750));
	ViolationValue = 1001;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ViolationValue = 121;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = 1001;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_CloseminimumValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 CloseminimumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ClosemaximumValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 ClosemaximumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	ClosemaximumValue = 12 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	ClosemaximumValue = 1.2 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ClosemaximumValue = 3.6 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_RandomValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 returnValue;
    ViReal64 randomValue;
          
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	randomValue = 0 + rand() % 100 * 12 / 100.00;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	randomValue = 0 + rand() % 100 * 1.2 / 100.00 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	randomValue = 0+ rand() % 100 * 3.6 / 100.00 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );		
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMinValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 returnValue;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));		

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMaxValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 returnValue;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_AC_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_10 ));
	ViolationValue = 12.1;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_CURR_TERMINAL, 0, AG3446X_VAL_CURR_TERM_3 ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 1));
	ViolationValue = 1.21;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));		

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = 3.61;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	
}

/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_CloseminimumValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 CloseminimumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	CloseminimumValue = 0 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );	
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ClosemaximumValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 ClosemaximumValue;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ClosemaximumValue = 120 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ClosemaximumValue = 1.2E9 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );		
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_RandomValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 returnValue;
    ViReal64 randomValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	randomValue = rand() % 100 * 120 / 100.00 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	randomValue = rand() % 100 * 1.2E9 / 100.00 ;
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMinValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 returnValue;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));		

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = -1E-6;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMaxValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 returnValue;
	ViReal64 ViolationValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
	ViolationValue = 121;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));		

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, AG3446X_ATTR_RANGE, 0, AG3446X_VAL_AUTO_RANGE_ON));
	ViolationValue = 1.21E9;
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));	
}

/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_CloseminimumValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 CloseminimumValue = 3 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_FREQ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ClosemaximumValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 ClosemaximumValue = 300000 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_FREQ));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_RandomValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 3 + rand() % 100 * (300000-3) / 100.00;
          
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_FREQ));
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMinValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue = 2.99 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_FREQ));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMaxValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue = 300001 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_FREQ));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_CloseminimumValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 CloseminimumValue = 3.33333333e-6 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_PERIOD));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ClosemaximumValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 ClosemaximumValue = 0.333333333 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_PERIOD));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_RandomValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 3.33333333e-6 + rand() % 100 * (0.333333333-(3.33333333e-6)) / 100.00;
          
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_PERIOD));
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMinValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue = 3.33333332e-6 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_PERIOD));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_LEVEL_ViolationMaxValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_LEVEL;
	ViReal64 ViolationValue = 0.333333334 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_PERIOD));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_RTD_ALPHA_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_RTD_ALPHA ;
	ViReal64 defaultValue = 85 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_RTD_RES_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_RTD_RES ;
	ViReal64 defaultValue = 100.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_THERMISTOR_RES_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_THERMISTOR_RES ;
	ViReal64 defaultValue = 5000 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT ;
	ViInt32 defaultValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}

/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT ;
	ViInt32 CloseminimumValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT ;
	ViInt32 ClosemaximumValue = 1000000000 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT ;
	ViInt32 returnValue;
      
    ViInt32 randomValue = (int)(1 + rand() % 100 * 9.99999999E8 / 100.00);
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT;
	ViInt32 ViolationValue = 0 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT;
	ViInt32 ViolationValue = 1.000000001E9 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_TRIGGER_COUNT_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_TRIGGER_COUNT ;
	ViInt32 defaultValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}	

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_INTERVAL_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_INTERVAL ;
	ViReal64 defaultValue = 1 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}

/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_INTERVAL_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_INTERVAL ;
	ViReal64 ClosemaximumValue = 3600 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_INTERVAL_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_INTERVAL ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0 + rand() % 100 * 3600 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_INTERVAL_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_INTERVAL;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_INTERVAL_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_INTERVAL;
	ViReal64 ViolationValue = 3601 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER ;
	ViInt32 defaultValue = 0 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER ;
	ViInt32 CloseminimumValue = 0 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER ;
	ViInt32 ClosemaximumValue = 1999999 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT, 0, ClosemaximumValue+1));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER ;
	ViInt32 returnValue;
      
    ViInt32 randomValue = (int)(0 + rand() % 100 * 1.999999E6 / 100.00);
      
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT, 0, randomValue+1));
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER;
	ViInt32 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER;
	ViInt32 ViolationValue = 2.0E6 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_TRIGGER_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_TRIGGER ;
	ViInt32 defaultValue = AG3446X_VAL_IMMEDIATE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_TRIGGER_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_TRIGGER ;
	ViInt32 discreteValue = AG3446X_VAL_IMMEDIATE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_SAMPLE_TRIGGER_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_SAMPLE_TRIGGER ;
	ViInt32 discreteValue = AG3446X_VAL_TIMER ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 defaultValue = 10 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32( vi, VI_NULL, AG3446X_ATTR_APERTURE_TIME_UNITS, 0, AG3446X_VAL_POWER_LINE_CYCLES));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 0.001 ;	
	ViReal64 CoercedValue = 0.001 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 0.0 + rand() % 100 * 0.001 / 100.00;
      ViReal64 CoercedValue = 0.001 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 0.002 ;	
	ViReal64 CoercedValue = 0.002 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 0.001 + rand() % 100 * 0.001 / 100.00;
      ViReal64 CoercedValue = 0.002 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 0.006 ;	
	ViReal64 CoercedValue = 0.006 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 0.002 + rand() % 100 * 0.004 / 100.00;
      ViReal64 CoercedValue = 0.006 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 0.02 ;	
	ViReal64 CoercedValue = 0.02 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 0.006001 + rand() % 100 * 0.014 / 100.00;
    ViReal64 CoercedValue = 0.02 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 0.06 ;	
	ViReal64 CoercedValue = 0.06 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 0.02 + rand() % 100 * 0.039999999999999994 / 100.00;
      ViReal64 CoercedValue = 0.06 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 0.2 ;	
	ViReal64 CoercedValue = 0.2 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 0.06 + rand() % 100 * 0.14 / 100.00;
      ViReal64 CoercedValue = 0.2 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 1.0 ;	
	ViReal64 CoercedValue = 1.0 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 0.200001 + rand() % 100 * 0.8 / 100.00;
      ViReal64 CoercedValue = 1.0 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 10.0 ;	
	ViReal64 CoercedValue = 10.0 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 1.0 + rand() % 100 * 9 / 100.00;
      ViReal64 CoercedValue = 10.0 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			
/****************************************************************************
 * Coerced Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_ClosemaximumValue_ReadWrite_NullChannel_Index9()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 ClosemaximumValue = 100.0 ;	
	ViReal64 CoercedValue = 100.0 ;
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
					
/****************************************************************************
 * Coerced Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/							
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_Coerced_RandomValue_ReadWrite_NullChannel_Index9()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME ;
	ViReal64 returnValue;
        
	ViReal64 randomValue = 10.1 + rand() % 100 * 89.9 / 100.00;
      ViReal64 CoercedValue = 100.0 ;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CoercedValue, returnValue, abs(CoercedValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_UNITS_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME_UNITS ;
	ViInt32 defaultValue = AG3446X_VAL_POWER_LINE_CYCLES ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );		
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_UNITS_ReadWrite_NullChannel_Index0()
{

	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME_UNITS ;
	ViInt32 defaultValue = AG3446X_VAL_POWER_LINE_CYCLES ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );	
}

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/	
void DriverFunctionalityTest::testAG3446X_ATTR_APERTURE_TIME_UNITS_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AG3446X_ATTR_APERTURE_TIME_UNITS ;
	ViInt32 defaultValue = AG3446X_VAL_SECONDS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_DC_VOLTS));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );	
}


/****************************************************************************
 *------------------------- Function Test ---------------------------------*
 ****************************************************************************/
 
/****************************************************************************
 * ag3446x_ConfigureMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureMeasurement Ring Parameter "Function" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Function Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_AC_VOLTS, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index3()
{
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_CURRENT, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_AC_CURRENT, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_2_WIRE_RES, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_4_WIRE_RES, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_FREQ, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_PERIOD, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_TEMPERATURE, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_CONTINUITY, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DIODE, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Valid Item Test Index12
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index12()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS_RATIO, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}

/****************************************************************************
 * measurementFunction Valid Item Test Index13
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Valid_Item_Index13()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_CAPACITANCE, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}
                    
/****************************************************************************
 * Function Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Function_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMeasurement(vi, INVALID_ENUM_VALUE, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
}

/****************************************************************************
 * ag3446x_ConfigureMeasurement Coerced Parameter "Range" Test  
 ****************************************************************************/

/****************************************************************************
 * Range Coerced Minimum Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMinimumValue_Index4()
{
    ViReal64 minimumValue = 0.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, minimumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Maximum Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMaximumValue_Index4()
{
    ViReal64 maximumValue = 0.1;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, maximumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Random Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedRandomValue_Index4()
{
    ViReal64 randomValue = 0.0 + rand() % 100 * 0.1 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, randomValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Minimum Value Test Index5
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMinimumValue_Index5()
{
    ViReal64 minimumValue = 0.1;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, minimumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Maximum Value Test Index5
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMaximumValue_Index5()
{
    ViReal64 maximumValue = 1;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, maximumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Random Value Test Index5
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedRandomValue_Index5()
{
    ViReal64 randomValue = 0.1 + rand() % 100 * 0.9 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, randomValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Minimum Value Test Index6
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMinimumValue_Index6()
{
    ViReal64 minimumValue = 1.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, minimumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Maximum Value Test Index6
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMaximumValue_Index6()
{
    ViReal64 maximumValue = 10.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, maximumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Random Value Test Index6
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedRandomValue_Index6()
{
    ViReal64 randomValue = 1.0 + rand() % 100 * 9.0 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, randomValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Minimum Value Test Index7
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMinimumValue_Index7()
{
    ViReal64 minimumValue = 10.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, minimumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Maximum Value Test Index7
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMaximumValue_Index7()
{
    ViReal64 maximumValue = 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, maximumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Random Value Test Index7
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedRandomValue_Index7()
{
    ViReal64 randomValue = 10.0 + rand() % 100 * 90.0 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, randomValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Minimum Value Test Index8
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMinimumValue_Index8()
{
    ViReal64 minimumValue = 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, minimumValue, 1E-6));
}

/****************************************************************************
 * Range Coerced Maximum Value Test Index8
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedMaximumValue_Index8()
{
    ViReal64 maximumValue = 1000.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, maximumValue, 1E-5));
}

/****************************************************************************
 * Range Coerced Random Value Test Index8
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_CoercedRandomValue_Index8()
{
    ViReal64 randomValue = 100.1 + rand() % 100 * 900.0 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, randomValue, 1E-5));
}

/****************************************************************************
 * Range Coerced Invalid Value Test
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Range_Valid_InvalidValue()
{
    ViReal64 invalidValue = 2000.0;

    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, invalidValue, 1E-5));
}

/****************************************************************************
 * ag3446x_ConfigureMeasurement Coerced Parameter "Resolution" Test  
 ****************************************************************************/

/****************************************************************************
 * Resolution Coerced Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMinimumValue_Index1()
{
    ViReal64 minimumValue = 0.00001;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, minimumValue));
}

/****************************************************************************
 * Resolution Coerced Maximum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMaximumValue_Index1()
{
    ViReal64 maximumValue = 0.0001;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 10, maximumValue));
}

/****************************************************************************
 * Resolution Coerced Random Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedRandomValue_Index1()
{
    ViReal64 randomValue = 0.00001 + rand() % 100 * 0.00009 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 10, randomValue));
}

/****************************************************************************
 * Resolution Coerced Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMinimumValue_Index2()
{
    ViReal64 minimumValue = 0.000003;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, minimumValue));
}

/****************************************************************************
 * Resolution Coerced Maximum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMaximumValue_Index2()
{
    ViReal64 maximumValue = 0.00001;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, maximumValue));
}

/****************************************************************************
 * Resolution Coerced Random Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedRandomValue_Index2()
{
    ViReal64 randomValue = 0.000003 + rand() % 100 * 0.000007 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, randomValue));
}

/****************************************************************************
 * Resolution Coerced Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMinimumValue_Index3()
{
    ViReal64 minimumValue = 0.000001;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, minimumValue));
}

/****************************************************************************
 * Resolution Coerced Maximum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMaximumValue_Index3()
{
    ViReal64 maximumValue = 0.000003;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, maximumValue));
}

/****************************************************************************
 * Resolution Coerced Random Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedRandomValue_Index3()
{
    ViReal64 randomValue = 0.000001 + rand() % 100 * 0.000002 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, randomValue));
}

/****************************************************************************
 * Resolution Coerced Minimum Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMinimumValue_Index4()
{
    ViReal64 minimumValue = 0.0000003;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, minimumValue));
}

/****************************************************************************
 * Resolution Coerced Maximum Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedMaximumValue_Index4()
{
    ViReal64 maximumValue = 0.000001;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, maximumValue));
}

/****************************************************************************
 * Resolution Coerced Random Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_CoercedRandomValue_Index4()
{
    ViReal64 randomValue = 0.0000003 + rand() % 100 * 0.0000007 / 100.0;

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, randomValue));
}

/****************************************************************************
 * Resolution Coerced Invalid Value Test
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurement_Resolution_Valid_InvalidValue()
{
    ViReal64 invalidValue = 2000.0;

    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 1, invalidValue));
}

/****************************************************************************
 * ag3446x_ConfigureACBandwidth Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, 300000.0));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureACBandwidth Coerced Parameter "ACMininumFrequency" Test  
 ****************************************************************************/
                
/****************************************************************************
 * ACMininumFrequency Coerced Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedMinimumValue_Index1()                
{
    ViReal64 minimumValue = 3.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, minimumValue, 300000.0));
}
                
/*******************************************************************************
 * ACMininumFrequency Coerced Maximum Value Test Index1
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the maximum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedMaximumValue_Index1()                
{
    ViReal64 maximumValue = 20.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, maximumValue, 300000.0));
}
                
/****************************************************************************
 * ACMininumFrequency Coerced Random Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedRandomValue_Index1()                
{
	 
    ViReal64 randomValue = 3.0 + rand() % 100 * 17 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, randomValue, 300000.0));
}
                
/****************************************************************************
 * ACMininumFrequency Coerced Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedMinimumValue_Index2()                
{
    ViReal64 minimumValue = 20.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, minimumValue, 300000.0));
}
                
/*******************************************************************************
 * ACMininumFrequency Coerced Maximum Value Test Index2
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the maximum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedMaximumValue_Index2()                
{
    ViReal64 maximumValue = 200.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, maximumValue, 300000.0));
}
                
/****************************************************************************
 * ACMininumFrequency Coerced Random Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedRandomValue_Index2()                
{
	 
    ViReal64 randomValue = 20.0 + rand() % 100 * 180 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, randomValue, 300000.0));
}
                
/****************************************************************************
 * ACMininumFrequency Coerced Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedMinimumValue_Index3()                
{
    ViReal64 minimumValue = 200.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, minimumValue, 300000.0));
}
                
/*******************************************************************************
 * ACMininumFrequency Coerced Maximum Value Test Index3
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the maximum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedMaximumValue_Index3()                
{
    ViReal64 maximumValue = 300000.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, maximumValue, 300000.0));
}
                
/****************************************************************************
 * ACMininumFrequency Coerced Random Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMininumFrequency_CoercedRandomValue_Index3()                
{
	 
    ViReal64 randomValue = 200.0 + rand() % 100 * 299800 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, randomValue, 300000.0));
}

/****************************************************************************
 * ag3446x_ConfigureACBandwidth Coerced Parameter "ACMaximumFrequency" Test  
 ****************************************************************************/
                
/*******************************************************************************
 * ACMaximumFrequency Coerced Invalid Minimum Value Test Index1
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the minimum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedMinimumValue_Index1()                
{
    ViReal64 minimumValue = 3.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, minimumValue));
}
                
/****************************************************************************
 * ACMaximumFrequency Coerced Maximum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedMaximumValue_Index1()                
{
    ViReal64 maximumValue = 20.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, maximumValue));
}
                
/****************************************************************************
 * ACMaximumFrequency Coerced Random Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedRandomValue_Index1()                
{
	 
    ViReal64 randomValue = 3.0 + rand() % 100 * 17 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, randomValue));
}
                
/*******************************************************************************
 * ACMaximumFrequency Coerced Invalid Minimum Value Test Index2
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the minimum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedMinimumValue_Index2()                
{
    ViReal64 minimumValue = 20.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, minimumValue));
}
                
/****************************************************************************
 * ACMaximumFrequency Coerced Maximum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedMaximumValue_Index2()                
{
    ViReal64 maximumValue = 200.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, maximumValue));
}
                
/****************************************************************************
 * ACMaximumFrequency Coerced Random Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedRandomValue_Index2()                
{
	 
    ViReal64 randomValue = 20.0 + rand() % 100 * 180 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, randomValue));
}
                
/*******************************************************************************
 * ACMaximumFrequency Coerced Invalid Minimum Value Test Index3
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the minimum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedMinimumValue_Index3()                
{
    ViReal64 minimumValue = 200.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, minimumValue));
}
                
/****************************************************************************
 * ACMaximumFrequency Coerced Maximum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedMaximumValue_Index3()                
{
    ViReal64 maximumValue = 300000.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, maximumValue));
}
                
/****************************************************************************
 * ACMaximumFrequency Coerced Random Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedRandomValue_Index3()                
{
	 
    ViReal64 randomValue = 200.0 + rand() % 100 * 299800 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureACBandwidth(vi, 20.0, randomValue));
}

/****************************************************************************
 * ACMaximumFrequency Coerced Invalid Value Test
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureACBandwidth_ACMaximumFrequency_CoercedInvalidValue()                
{
	 
    ViReal64 invalidValue = 1;	
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureACBandwidth(vi, 20.0, invalidValue));
}

/****************************************************************************
 * ag3446x_ConfigureFrequencyVoltageRange Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, 10.0));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureFrequencyVoltageRange Coerced Parameter "FrequencyVoltageRange" Test  
 ****************************************************************************/
                
/*******************************************************************************
 * FrequencyVoltageRange Coerced Minimum Value Test Index1 
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum and Random Values for Index1 are the same as Minimum
 ****************************************************************************/	
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index2()                
{
    ViReal64 minimumValue = -2 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum and Random Values for Index2 are the same as Minimum
 ****************************************************************************/	
                
/*******************************************************************************
 * FrequencyVoltageRange Coerced Invalid Minimum Value Test Index3  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index3()                
{
    ViReal64 minimumValue = -3 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum and Random Values for Index3 are the same as Minimum
 ****************************************************************************/	
                
/*******************************************************************************
 * FrequencyVoltageRange Coerced Minimum Value Test Index4
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index4()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMaximumValue_Index4()                
{
    ViReal64 maximumValue = 0.1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, maximumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Random Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedRandomValue_Index4()                
{
	ViReal64 randomValue = 0.0 + rand() % 100 * 0.1 / 100.00;	

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, randomValue));
}
                
/*******************************************************************************
 * FrequencyVoltageRange Coerced Minimum Value Test Index3
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index5()                
{
    ViReal64 minimumValue = 0.1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}

/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum Value Test Index5
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMaximumValue_Index5()                
{
    ViReal64 maximumValue = 1.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, maximumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Random Value Test Index5
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedRandomValue_Index5()                
{
	ViReal64 randomValue = 0.1 + rand() % 100 * 0.9 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, randomValue));
}
                
/*******************************************************************************
 * FrequencyVoltageRange Coerced Minimum Value Test Index6
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the minimum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index6()                
{
    ViReal64 minimumValue = 1.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum Value Test Index6
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMaximumValue_Index6()                
{
    ViReal64 maximumValue = 10.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, maximumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Random Value Test Index6
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedRandomValue_Index6()                
{
	ViReal64 randomValue = 1.0 + rand() % 100 * 9.0 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, randomValue));
}
                
/*******************************************************************************
 * FrequencyVoltageRange Coerced Minimum Value Test Index7
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the minimum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index7()                
{
    ViReal64 minimumValue = 10.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum Value Test Index7
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMaximumValue_Index7()                
{
    ViReal64 maximumValue = 100.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, maximumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Random Value Test Index7
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedRandomValue_Index7()                
{
	ViReal64 randomValue = 10.0 + rand() % 100 * 90.0 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, randomValue));
}
                
/*******************************************************************************
 * FrequencyVoltageRange Coerced Minimum Value Test Index8
 * Should Fail! 
 * "Has Minimum" flag doesn't be checked, the minimum value should be invalid value.  
 *******************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMinimumValue_Index8()                
{
    ViReal64 minimumValue = 100.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, minimumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Maximum Value Test Index8
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedMaximumValue_Index8()                
{
    ViReal64 maximumValue = 1000.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, maximumValue));
}
                
/****************************************************************************
 * FrequencyVoltageRange Coerced Random Value Test Index8
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedRandomValue_Index8()                
{
	ViReal64 randomValue = 100.0 + rand() % 100 * 900.0 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyVoltageRange(vi, randomValue));
}

/****************************************************************************
 * FrequencyVoltageRange Coerced Invalid Value Test
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyVoltageRange_FrequencyVoltageRange_CoercedInvalidValue()                
{
	ViReal64 invalidValue = 2000;	
	
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureFrequencyVoltageRange(vi, invalidValue));
}


/****************************************************************************
 * ag3446x_ConfigureTransducerType Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTransducerType_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTransducerType(vi, AG3446X_VAL_4_WIRE_RTD));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureTransducerType Ring Parameter "TransducerType" Test  
 ****************************************************************************/
            
/****************************************************************************
 * TransducerType Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTransducerType_TransducerType_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTransducerType(vi, AG3446X_VAL_2_WIRE_THER));
}
                    
/****************************************************************************
 * TransducerType Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTransducerType_TransducerType_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTransducerType(vi, AG3446X_VAL_4_WIRE_THER));
}
                    
/****************************************************************************
 * TransducerType Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTransducerType_TransducerType_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTransducerType(vi, AG3446X_VAL_2_WIRE_RTD));
}
                    
/****************************************************************************
 * TransducerType Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTransducerType_TransducerType_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTransducerType(vi, AG3446X_VAL_4_WIRE_RTD));
}
                    
/****************************************************************************
 * transducerType Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTransducerType_transducerType_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTransducerType(vi, AG3446X_VAL_THERMOCOUPLE));
}
                                       
/****************************************************************************
 * TransducerType Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTransducerType_TransducerType_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureTransducerType(vi, INVALID_ENUM_VALUE));
}    

/****************************************************************************
 * ag3446x_ConfigureRTD Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTD(vi, 85, 100.0));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureRTD Ranged Parameter "Alpha" Test  
 ****************************************************************************/
                
/****************************************************************************
 * Alpha Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Alpha_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 85 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTD(vi, minimumValue, 100.0));
}

/****************************************************************************
 * Alpha Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Alpha_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = 84 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureRTD(vi, belowMinimumValue, 100.0));
}
                
/****************************************************************************
 * Alpha Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Alpha_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 85 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTD(vi, maximumValue, 100.0));
}

/****************************************************************************
 * Alpha Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Alpha_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 86 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureRTD(vi, aboveMaximumValue, 100.0));
}
                
/****************************************************************************
 * Alpha Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Alpha_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 85 + rand() % 100 * 0 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTD(vi, randomValue, 100.0));
}
                                
/****************************************************************************
 * ag3446x_ConfigureRTD Ranged Parameter "Resistance" Test  
 ****************************************************************************/
                
/****************************************************************************
 * Resistance Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Resistance_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 80.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTD(vi, 85, minimumValue));
}

/****************************************************************************
 * Resistance Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Resistance_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = 79 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureRTD(vi, 85, belowMinimumValue));
}
                
/****************************************************************************
 * Resistance Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Resistance_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 120.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTD(vi, 85, maximumValue));
}

/****************************************************************************
 * Resistance Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Resistance_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 121 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureRTD(vi, 85, aboveMaximumValue));
}
                
/****************************************************************************
 * Resistance Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRTD_Resistance_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 80.0 + rand() % 100 * 40 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTD(vi, 85, randomValue));
}

/****************************************************************************
 * ag3446x_ConfigureThermistor Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistor_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermistor(vi, 5000));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureThermistor Ranged Parameter "Resistance" Test  
 ****************************************************************************/
                
/****************************************************************************
 * Resistance Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistor_Resistance_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 5000 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermistor(vi, minimumValue));
}

/****************************************************************************
 * Resistance Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistor_Resistance_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = 4999 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureThermistor(vi, belowMinimumValue));
}
                
/****************************************************************************
 * Resistance Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistor_Resistance_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 5000 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermistor(vi, maximumValue));
}

/****************************************************************************
 * Resistance Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistor_Resistance_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 5001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureThermistor(vi, aboveMaximumValue));
}
                
/****************************************************************************
 * Resistance Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistor_Resistance_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 5000 + rand() % 100 * 0 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermistor(vi, randomValue));
}

/****************************************************************************
 * ag3446x_ConfigureTrigger Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, 0.0));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureTrigger Ring Parameter "TriggerSource" Test  
 ****************************************************************************/
            
/****************************************************************************
 * TriggerSource Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerSource_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, 0.0));
}
                    
/****************************************************************************
 * TriggerSource Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerSource_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_EXTERNAL, 0.0));
}
                    
/****************************************************************************
 * TriggerSource Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerSource_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, 0.0));
}

/****************************************************************************
 * triggerSource Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_triggerSource_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_INTERNAL, 0.0));
}
                    
/****************************************************************************
 * TriggerSource Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerSource_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureTrigger(vi, INVALID_ENUM_VALUE, 0.0));
}    
                                
/****************************************************************************
 * ag3446x_ConfigureTrigger Ranged Parameter "TriggerDelay" Test  
 ****************************************************************************/
                
/****************************************************************************
 * TriggerDelay Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -2 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, minimumValue));
}

/****************************************************************************
 * TriggerDelay Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -3 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, belowMinimumValue));
}
                
/****************************************************************************
 * TriggerDelay Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, minimumValue));
}

                
/****************************************************************************
 * TriggerDelay Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, minimumValue));
}

/****************************************************************************
 * TriggerDelay Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = -10 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, belowMinimumValue));
}
                
/****************************************************************************
 * TriggerDelay Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = 3600.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, maximumValue));
}

/****************************************************************************
 * TriggerDelay Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeAboveMaximumValue_Index3()                
{
    ViReal64 aboveMaximumValue = 3601 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, aboveMaximumValue));
}
                
/****************************************************************************
 * TriggerDelay Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTrigger_TriggerDelay_RangeRandomValue_Index3()                
{
	 
	ViReal64 randomValue = 0.0 + rand() % 100 * 3600 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_IMMEDIATE, randomValue));
}

/****************************************************************************
 * ag3446x_ConfigureTriggerSlope Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTriggerSlope_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTriggerSlope(vi, AG3446X_VAL_NEGATIVE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureTriggerSlope Ring Parameter "Polarity" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Polarity Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTriggerSlope_Polarity_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTriggerSlope(vi, AG3446X_VAL_POSITIVE));
}
                    
/****************************************************************************
 * Polarity Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTriggerSlope_Polarity_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTriggerSlope(vi, AG3446X_VAL_NEGATIVE));
}
                    
/****************************************************************************
 * Polarity Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTriggerSlope_Polarity_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureTriggerSlope(vi, INVALID_ENUM_VALUE));
}    


/****************************************************************************
 * ag3446x_ConfigureMultiPoint Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMultiPoint(vi, 1, 1, 1, 1.0));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureMultiPoint Ranged Parameter "TriggerCount" Test  
 ****************************************************************************/
                
/****************************************************************************
 * TriggerCount Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_TriggerCount_RangeMinimumValue_Index1()                
{
    ViInt32 minimumValue = 1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMultiPoint(vi, minimumValue, 1, 1, 1.0));
}

/****************************************************************************
 * TriggerCount Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_TriggerCount_RangeBelowMinimumValue_Index1()                
{
    ViInt32 belowMinimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMultiPoint(vi, belowMinimumValue, 1, 1, 1.0));
}
                
/****************************************************************************
 * TriggerCount Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_TriggerCount_RangeMaximumValue_Index1()                
{
    ViInt32 maximumValue = 1000000 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMultiPoint(vi, maximumValue, 1, 1, 1.0));
}

/****************************************************************************
 * TriggerCount Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_TriggerCount_RangeAboveMaximumValue_Index1()                
{
    ViInt32 aboveMaximumValue = 1.000001E6 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMultiPoint(vi, aboveMaximumValue, 1, 1, 1.0));
}
                
/****************************************************************************
 * TriggerCount Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_TriggerCount_RangeRandomValue_Index1()                
{
	 
	ViInt32 randomValue = (int)(1 + rand() % 100 * 999999 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMultiPoint(vi, randomValue, 1, 1, 1.0));
}
                                
/****************************************************************************
 * ag3446x_ConfigureMultiPoint Ranged Parameter "SampleCount" Test  
 ****************************************************************************/
                
/****************************************************************************
 * SampleCount Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_SampleCount_RangeMinimumValue_Index1()                
{
    ViInt32 minimumValue = 1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMultiPoint(vi, 1, minimumValue, 1, 1.0));
}

/****************************************************************************
 * SampleCount Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_SampleCount_RangeBelowMinimumValue_Index1()                
{
    ViInt32 belowMinimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMultiPoint(vi, 1, belowMinimumValue, 1, 1.0));
}
                
/****************************************************************************
 * SampleCount Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_SampleCount_RangeMaximumValue_Index1()                
{
    ViInt32 maximumValue = 1000000 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMultiPoint(vi, 1, maximumValue, 1, 1.0));
}

/****************************************************************************
 * SampleCount Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_SampleCount_RangeAboveMaximumValue_Index1()                
{
    ViInt32 aboveMaximumValue = 1.000001E9 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMultiPoint(vi, 1, aboveMaximumValue, 1, 1.0));
}
                
/****************************************************************************
 * SampleCount Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMultiPoint_SampleCount_RangeRandomValue_Index1()                
{
	 
	ViInt32 randomValue = (int)(1 + rand() % 100 * 999999 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMultiPoint(vi, 1, randomValue, 1, 1.0));
}

/****************************************************************************
 * ag3446x_Calibrate Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_Calibrate_DefaultParameter()
{
    ViBoolean CalibrationResult;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Calibrate(vi, 0.0, "", VI_FALSE, &CalibrationResult));
}
 
/****************************************************************************
 * ag3446x_Calibrate Boolean Parameter "EnableCalibrationStore" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableCalibrationStore Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_Calibrate_EnableCalibrationStore_TRUE()
{            
    ViBoolean CalibrationResult;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Calibrate(vi, 0.0, "", VI_TRUE, &CalibrationResult));
}

/****************************************************************************
 * EnableCalibrationStore Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_Calibrate_EnableCalibrationStore_FALSE()
{            
    ViBoolean CalibrationResult;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Calibrate(vi, 0.0, "", VI_FALSE, &CalibrationResult));
}


/****************************************************************************
 * ag3446x_CalibrateADC Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_CalibrateADC_DefaultParameter()
{
    ViBoolean CalibrationResult;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_CalibrateADC(vi, &CalibrationResult));
}

/****************************************************************************
 * ag3446x_ConfigureCalibrationSecurity Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureCalibrationSecurity_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCalibrationSecurity(vi, 0, VI_TRUE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureCalibrationSecurity Boolean Parameter "EnableSecurity" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableSecurity Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureCalibrationSecurity_EnableSecurity_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCalibrationSecurity(vi, 0, VI_TRUE));
}

/****************************************************************************
 * EnableSecurity Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureCalibrationSecurity_EnableSecurity_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCalibrationSecurity(vi, 0, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureDataTransition Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransition_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransition(vi, AG3446X_VAL_MEM_DATA_OPER_DOWNLOAD, "", ""));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureDataTransition Ring Parameter "Operation" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Operation Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransition_Operation_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransition(vi, AG3446X_VAL_MEM_DATA_OPER_DOWNLOAD, "", ""));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransition_Operation_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransition(vi, AG3446X_VAL_MEM_DATA_OPER_STORE, "", ""));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransition_Operation_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransition(vi, AG3446X_VAL_MEM_DATA_OPER_UPLOAD, "", ""));
}
                    
/****************************************************************************
 * Operation Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransition_Operation_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransition(vi, INVALID_ENUM_VALUE, "", ""));
}    

/****************************************************************************
 * ag3446x_ConfigureDirectory Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDirectory_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDirectory(vi, AG3446X_VAL_MEM_DIR_OPER_SELECT, ""));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureDirectory Ring Parameter "Operation" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Operation Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDirectory_Operation_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDirectory(vi, AG3446X_VAL_MEM_DIR_OPER_SELECT, ""));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDirectory_Operation_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDirectory(vi, AG3446X_VAL_MEM_DIR_OPER_MAKE, ""));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDirectory_Operation_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDirectory(vi, AG3446X_VAL_MEM_DIR_OPER_REMOVE, ""));
}
                    
/****************************************************************************
 * Operation Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDirectory_Operation_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDirectory(vi, INVALID_ENUM_VALUE, ""));
}    

/****************************************************************************
 * ag3446x_ConfigureFile Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFile_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFile(vi, AG3446X_VAL_MEM_FILE_OPER_COPY, "", ""));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureFile Ring Parameter "Operation" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Operation Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFile_Operation_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFile(vi, AG3446X_VAL_MEM_FILE_OPER_COPY, "", ""));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFile_Operation_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFile(vi, AG3446X_VAL_MEM_FILE_OPER_MOVE, "", ""));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFile_Operation_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFile(vi, AG3446X_VAL_MEM_FILE_OPER_DELETE, "", ""));
}
                    
/****************************************************************************
 * Operation Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFile_Operation_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFile(vi, INVALID_ENUM_VALUE, "", ""));
}    

/****************************************************************************
 * ag3446x_ConfigurePreferenceFile Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigurePreferenceFile_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePreferenceFile(vi, AG3446X_VAL_MEM_PREF_FILE_OPER_LOAD, ""));
}
 
    
/****************************************************************************
 * ag3446x_ConfigurePreferenceFile Ring Parameter "Operation" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Operation Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigurePreferenceFile_Operation_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePreferenceFile(vi, AG3446X_VAL_MEM_PREF_FILE_OPER_LOAD, ""));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigurePreferenceFile_Operation_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePreferenceFile(vi, AG3446X_VAL_MEM_PREF_FILE_OPER_STORE, ""));
}
                    
/****************************************************************************
 * Operation Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigurePreferenceFile_Operation_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePreferenceFile(vi, INVALID_ENUM_VALUE, ""));
}    

/****************************************************************************
 * ag3446x_ConfigureStateFile Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureStateFile_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureStateFile(vi, AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD, "", VI_TRUE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureStateFile Ring Parameter "Operation" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Operation Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureStateFile_Operation_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureStateFile(vi, AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD, "", VI_TRUE));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureStateFile_Operation_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureStateFile(vi, AG3446X_VAL_MEM_STATE_FILE_OPER_STORE, "", VI_TRUE));
}
                    
/****************************************************************************
 * Operation Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureStateFile_Operation_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureStateFile(vi, AG3446X_VAL_MEM_STATE_FILE_OPER_RECALL, "", VI_TRUE));
}
                    
/****************************************************************************
 * Operation Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureStateFile_Operation_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureStateFile(vi, INVALID_ENUM_VALUE, "", VI_TRUE));
}    
                
/****************************************************************************
 * ag3446x_ConfigureStateFile Boolean Parameter "EnableAutoRecall" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableAutoRecall Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureStateFile_EnableAutoRecall_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureStateFile(vi, AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD, "", VI_TRUE));
}

/****************************************************************************
 * EnableAutoRecall Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureStateFile_EnableAutoRecall_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureStateFile(vi, AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD, "", VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureReadingMemory Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureReadingMemory_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureReadingMemory(vi, 1));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureReadingMemory Ranged Parameter "MeasurementCounts" Test  
 ****************************************************************************/
                
/****************************************************************************
 * MeasurementCounts Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureReadingMemory_MeasurementCounts_RangeMinimumValue_Index1()                
{
    ViInt32 minimumValue = 1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureReadingMemory(vi, minimumValue));
}

/****************************************************************************
 * MeasurementCounts Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureReadingMemory_MeasurementCounts_RangeBelowMinimumValue_Index1()                
{
    ViInt32 belowMinimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureReadingMemory(vi, belowMinimumValue));
}
                
/****************************************************************************
 * MeasurementCounts Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureReadingMemory_MeasurementCounts_RangeMaximumValue_Index1()                
{
    ViInt32 maximumValue = 2000000 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureReadingMemory(vi, maximumValue));
}

/****************************************************************************
 * MeasurementCounts Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureReadingMemory_MeasurementCounts_RangeAboveMaximumValue_Index1()                
{
    ViInt32 aboveMaximumValue = 2000001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureReadingMemory(vi, aboveMaximumValue));
}
                
/****************************************************************************
 * MeasurementCounts Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureReadingMemory_MeasurementCounts_RangeRandomValue_Index1()                
{
	 
	ViInt32 randomValue = (int)(1 + rand() % 100 * 9999 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureReadingMemory(vi, randomValue));
}
                
 
/****************************************************************************
 * ag3446x_QueryFileList Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_QueryFileList_DefaultParameter()
{
    ViInt32 MemoryUsed;
    ViInt32 MemoryFree;
    ViChar FileListing[1024];
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_QueryFileList(vi, &MemoryUsed, &MemoryFree, FileListing));
}

/****************************************************************************
 * ag3446x_ValidateStateFile Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ValidateStateFile_DefaultParameter()
{
    ViBoolean IsValid;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ValidateStateFile(vi, "", &IsValid));
}

/****************************************************************************
 * ag3446x_ConfigureAutoZeroMode Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureAutoZeroMode_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAutoZeroMode(vi, AG3446X_VAL_AUTO_ZERO_ON));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureAutoZeroMode Ring Parameter "AutoZeroMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * AutoZeroMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureAutoZeroMode_AutoZeroMode_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAutoZeroMode(vi, AG3446X_VAL_AUTO_ZERO_OFF));
}
                    
/****************************************************************************
 * AutoZeroMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureAutoZeroMode_AutoZeroMode_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAutoZeroMode(vi, AG3446X_VAL_AUTO_ZERO_ON));
}
                    
/****************************************************************************
 * AutoZeroMode Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureAutoZeroMode_AutoZeroMode_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAutoZeroMode(vi, AG3446X_VAL_AUTO_ZERO_ONCE));
}
                    
/****************************************************************************
 * AutoZeroMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureAutoZeroMode_AutoZeroMode_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureAutoZeroMode(vi, INVALID_ENUM_VALUE));
}    
 
/****************************************************************************
 * ag3446x_ConfigureAverage Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureAverage_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAverage(vi, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureAverage Boolean Parameter "EnableAverage" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableAverage Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureAverage_EnableAverage_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAverage(vi, VI_TRUE));
}

/****************************************************************************
 * EnableAverage Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureAverage_EnableAverage_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAverage(vi, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureLimit Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, 0.0, 0.0, VI_FALSE));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureLimit Ranged Parameter "LowerLimit" Test  
 ****************************************************************************/
                
/****************************************************************************
 * LowerLimit Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, minimumValue, 0.0, VI_TRUE));
}

/****************************************************************************
 * LowerLimit Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1.0E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, belowMinimumValue, 0.0, VI_TRUE));
}
                
/****************************************************************************
 * LowerLimit Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = -1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, maximumValue, 0.0, VI_TRUE));
}

/****************************************************************************
 * LowerLimit Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = -1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, aboveMaximumValue, 0.0, VI_TRUE));
}
                
/****************************************************************************
 * LowerLimit Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeRandomValue_Index1()                
{
	ViReal64 randomValue = -1.0E+15 + rand() % 100 * (-1.0E-15 + 1.0E+15) / 100.00;	

	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, randomValue, 0.0, VI_TRUE));
}
                
/****************************************************************************
 * LowerLimit Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, minimumValue, 0.0, VI_TRUE));
}
                
/****************************************************************************
 * LowerLimit Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = 1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, minimumValue, 1.0E+15, VI_TRUE));
}

/****************************************************************************
 * LowerLimit Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = 1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, belowMinimumValue, 1.0E+15, VI_TRUE));
}
                
/****************************************************************************
 * LowerLimit Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = +1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, maximumValue, 1.0E+15, VI_TRUE));
}

/****************************************************************************
 * LowerLimit Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeAboveMaximumValue_Index3()                
{
    ViReal64 aboveMaximumValue = 1.000000000000001E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, aboveMaximumValue, 1.0E+15, VI_TRUE));
}
                
/****************************************************************************
 * LowerLimit Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_LowerLimit_RangeRandomValue_Index3()                
{
	ViReal64 randomValue = 1.0E-15 + rand() % 100 * (+1.0E+15 - 1.0E-15) / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, randomValue, 1.0E+15, VI_TRUE));
}
                                
/****************************************************************************
 * ag3446x_ConfigureLimit Ranged Parameter "UpperLimit" Test  
 ****************************************************************************/
                
/****************************************************************************
 * UpperLimit Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, -1.0E+15, minimumValue, VI_TRUE));
}

/****************************************************************************
 * UpperLimit Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1.000000000000001E+16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, -1.0E+15, belowMinimumValue, VI_TRUE));
}
                
/****************************************************************************
 * UpperLimit Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = -1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, -1.0E+15, maximumValue, VI_TRUE));
}

/****************************************************************************
 * UpperLimit Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = -1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, -1.0E+15, aboveMaximumValue, VI_TRUE));
}
                
/****************************************************************************
 * UpperLimit Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeRandomValue_Index1()                
{
	ViReal64 randomValue = -1.0E+15 + rand() % 100 * (-1.0E-15 + 1.0E+15) / 100.00;	

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, -1.0E+15, randomValue, VI_TRUE));
}
                
/****************************************************************************
 * UpperLimit Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, 0.0, minimumValue, VI_TRUE));
}
                
/****************************************************************************
 * UpperLimit Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = 1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, 0.0, minimumValue, VI_TRUE));
}

/****************************************************************************
 * UpperLimit Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = 1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, 0.0, belowMinimumValue, VI_TRUE));
}
                
/****************************************************************************
 * UpperLimit Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = +1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, 0.0, maximumValue, VI_TRUE));
}

/****************************************************************************
 * UpperLimit Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeAboveMaximumValue_Index3()                
{
    ViReal64 aboveMaximumValue = 1.000000000000001E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureLimit(vi, 0.0, aboveMaximumValue, VI_TRUE));
}
                
/****************************************************************************
 * UpperLimit Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_UpperLimit_RangeRandomValue_Index3()                
{
	ViReal64 randomValue = 1.0E-15 + rand() % 100 * (+1.0E+15 - 1.0E-15) / 100.00;	

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, 0.0, randomValue, VI_TRUE));
}
                
/****************************************************************************
 * ag3446x_ConfigureLimit Boolean Parameter "EnableLimit" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableLimit Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_EnableLimit_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, 0.0, 0.0, VI_TRUE));
}

/****************************************************************************
 * EnableLimit Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureLimit_EnableLimit_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureLimit(vi, 0.0, 0.0, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureScale Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_FALSE));
}

/****************************************************************************
 * RelativeValue Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_RelativeValue_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 200.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, maximumValue, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_TRUE));
}

/****************************************************************************
 * RelativeValue Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_RelativeValue_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 201 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScale(vi, aboveMaximumValue, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_FALSE, VI_TRUE));
}
                
/****************************************************************************
 * RelativeValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_RelativeValue_RangeRandomValue_Index1()                
{
	ViReal64 randomValue = 0 + rand() % 100 * 0 / 100.00;	

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, randomValue, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_TRUE));
}               
                
/****************************************************************************
 * ag3446x_ConfigureScale Ring Parameter "ScalingFunction" Test  
 ****************************************************************************/
            
/****************************************************************************
 * ScalingFunction Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_ScalingFunction_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_FALSE));
}
                    
/****************************************************************************
 * ScalingFunction Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_ScalingFunction_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DBM, VI_TRUE, VI_FALSE));
}
                    
/****************************************************************************
 * ScalingFunction Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_ScalingFunction_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, INVALID_ENUM_VALUE, VI_TRUE, VI_TRUE));
}    
                
/****************************************************************************
 * ag3446x_ConfigureScale Boolean Parameter "AutoReference" Test  
 ****************************************************************************/
/****************************************************************************
 * AutoReference Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_AutoReference_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_FALSE));
}

/****************************************************************************
 * AutoReference Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_AutoReference_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_FALSE, VI_FALSE));
}
            
/****************************************************************************
 * ag3446x_ConfigureScale Boolean Parameter "EnableScaling" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableScaling Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_EnableScaling_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_TRUE));
}

/****************************************************************************
 * EnableScaling Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_EnableScaling_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, 0, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureScale Ranged Parameter "RelativeValue" Test  
 ****************************************************************************/
                
/****************************************************************************
 * RelativeValue Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_RelativeValue_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -200.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScale(vi, minimumValue, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_TRUE, VI_TRUE));
}

/****************************************************************************
 * RelativeValue Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScale_RelativeValue_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -201 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScale(vi, belowMinimumValue, AG3446X_VAL_600, AG3446X_VAL_SCALE_FUNC_DB, VI_FALSE, VI_TRUE));
}

/****************************************************************************
 * ag3446x_ConfigureHistogram Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_FALSE, VI_TRUE, AG3446X_VAL_100));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureHistogram Ranged Parameter "LowerRange" Test  
 ****************************************************************************/
                
/****************************************************************************
 * LowerRange Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, minimumValue, 0.0, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * LowerRange Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1.0E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, belowMinimumValue, 0.0, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * LowerRange Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = -1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, maximumValue, 0.0, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * LowerRange Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = -1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, aboveMaximumValue, 0.0, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * LowerRange Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeRandomValue_Index1()                
{
	ViReal64 randomValue = -1.0E+15 + rand() % 100 * (-1.0E-15 + 1.0E+15) / 100.00;	

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, randomValue, 0.0, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * LowerRange Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, minimumValue, 0.0, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * LowerRange Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = 1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, minimumValue, 1.0E+15, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * LowerRange Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = 1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, belowMinimumValue, 1.0E+15, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * LowerRange Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = 1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, maximumValue, 1.0E+15, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * LowerRange Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeAboveMaximumValue_Index3()                
{
    ViReal64 aboveMaximumValue = 1.0E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, aboveMaximumValue, 1.0E+15, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * LowerRange Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_LowerRange_RangeRandomValue_Index3()                
{
	ViReal64 randomValue = 1.0E-15 + rand() % 100 * (1.0E+15 - 1.0E-15) / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, randomValue, 1.0E+15, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                                
/****************************************************************************
 * ag3446x_ConfigureHistogram Ranged Parameter "UpperRange" Test  
 ****************************************************************************/
                
/****************************************************************************
 * UpperRange Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, -1.0E+15, minimumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * UpperRange Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1.0E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, -1.0E+15, belowMinimumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * UpperRange Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = -1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, -1.0E+15, maximumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * UpperRange Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = -1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, -1.0E+15, aboveMaximumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * UpperRange Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeRandomValue_Index1()                
{
	ViReal64 randomValue = -1.0E+15 + rand() % 100 * (-1.0E-15 + 1.0E+15) / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, -1.0E+15, randomValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * UpperRange Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, -1.0E+15, minimumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * UpperRange Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = 1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, minimumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * UpperRange Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = 1.0E-16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, 0.0, belowMinimumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * UpperRange Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = 1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, maximumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}

/****************************************************************************
 * UpperRange Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeAboveMaximumValue_Index3()                
{
     ViReal64 aboveMaximumValue = 1.0E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, 0.0, aboveMaximumValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * UpperRange Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_UpperRange_RangeRandomValue_Index3()                
{
	ViReal64 randomValue = 1.0E-15 + rand() % 100 * (1.0E+15 - 1.0E-15) / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, randomValue, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
                
/****************************************************************************
 * ag3446x_ConfigureHistogram Boolean Parameter "EnableHistogram" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableHistogram Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_EnableHistogram_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_100));
}

/****************************************************************************
 * EnableHistogram Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_EnableHistogram_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_FALSE, VI_TRUE, AG3446X_VAL_100));
}
            
/****************************************************************************
 * ag3446x_ConfigureHistogram Boolean Parameter "AutoHistogramRange" Test  
 ****************************************************************************/
/****************************************************************************
 * AutoHistogramRange Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_AutoHistogramRange_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_100));
}

/****************************************************************************
 * AutoHistogramRange Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_AutoHistogramRange_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_FALSE, AG3446X_VAL_100));
}
            
/****************************************************************************
 * ag3446x_ConfigureHistogram Ring Parameter "BinCounts" Test  
 ****************************************************************************/
            
/****************************************************************************
 * BinCounts Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_BinCounts_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_10));
}
                    
/****************************************************************************
 * BinCounts Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_BinCounts_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_20));
}
                    
/****************************************************************************
 * BinCounts Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_BinCounts_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_40));
}
                    
/****************************************************************************
 * BinCounts Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_BinCounts_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_100));
}
                    
/****************************************************************************
 * BinCounts Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_BinCounts_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_200));
}
                    
/****************************************************************************
 * BinCounts Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_BinCounts_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_400));
}
                    
/****************************************************************************
 * BinCounts Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureHistogram_BinCounts_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, INVALID_ENUM_VALUE));
}    

/****************************************************************************
 * ag3446x_ConfigureCurrentTerminals Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureCurrentTerminals_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCurrentTerminals(vi, 3));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureCurrentTerminals Ring Parameter "TeminalValue" Test  
 ****************************************************************************/
            
/****************************************************************************
 * TeminalValue Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureCurrentTerminals_TeminalValue_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCurrentTerminals(vi, AG3446X_VAL_CURR_TERM_3));
}
                    
/****************************************************************************
 * TeminalValue Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureCurrentTerminals_TeminalValue_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCurrentTerminals(vi, AG3446X_VAL_CURR_TERM_10));
}
                    
/****************************************************************************
 * TeminalValue Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureCurrentTerminals_TeminalValue_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureCurrentTerminals(vi, INVALID_ENUM_VALUE));
}    

/****************************************************************************
 * ag3446x_ConfigureVoltageImpedance Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureVoltageImpedance_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureVoltageImpedance(vi, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureVoltageImpedance Boolean Parameter "EnableAutoImpedance" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableAutoImpedance Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureVoltageImpedance_EnableAutoImpedance_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureVoltageImpedance(vi, VI_TRUE));
}

/****************************************************************************
 * EnableAutoImpedance Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureVoltageImpedance_EnableAutoImpedance_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureVoltageImpedance(vi, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureNullOperation Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_FALSE, 0, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureNullOperation Boolean Parameter "EnableNullFunction" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableNullFunction Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_EnableNullFunction_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_TRUE, 0, VI_FALSE));
}

/****************************************************************************
 * EnableNullFunction Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_EnableNullFunction_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_FALSE, 0, VI_FALSE));
}
                            
/****************************************************************************
 * ag3446x_ConfigureNullOperation Ranged Parameter "NullValue" Test  
 ****************************************************************************/
                
/****************************************************************************
 * NullValue Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_NullValue_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -12 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_TRUE, minimumValue, VI_FALSE));
}

/****************************************************************************
 * NullValue Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_NullValue_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureNullOperation(vi, VI_TRUE, belowMinimumValue, VI_FALSE));
}
                
/****************************************************************************
 * NullValue Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_NullValue_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 12 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_TRUE, maximumValue, VI_FALSE));
}

/****************************************************************************
 * NullValue Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_NullValue_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 1E16 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureNullOperation(vi, VI_TRUE, aboveMaximumValue, VI_FALSE));
}
                
/****************************************************************************
 * NullValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_NullValue_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = -12 + rand() % 100 * 24 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_TRUE, randomValue, VI_FALSE));
}
                
/****************************************************************************
 * ag3446x_ConfigureNullOperation Boolean Parameter "EnableAutoValue" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableAutoValue Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_EnableAutoValue_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_TRUE, 0, VI_TRUE));
}

/****************************************************************************
 * EnableAutoValue Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureNullOperation_EnableAutoValue_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureNullOperation(vi, VI_TRUE, 0, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureMeasurementTriggerParameters Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_CONT));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureMeasurementTriggerParameters Ring Parameter "Type" Test  
 ****************************************************************************/
            
/****************************************************************************
 * Type Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_CONT));
}
                    
/****************************************************************************
 * Type Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_AC_CURRENT));
}
                    
/****************************************************************************
 * Type Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_DC_CURRENT));
}
                    
/****************************************************************************
 * Type Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_DIODE));
}
                    
/****************************************************************************
 * Type Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_FREQ));
}
                    
/****************************************************************************
 * Type Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_PER));
}
                    
/****************************************************************************
 * Type Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_RES));
}
                    
/****************************************************************************
 * Type Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_FRES));
}
                    
/****************************************************************************
 * Type Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_TEMP));
}
                    
/****************************************************************************
 * Type Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_AC_VOLTAGE));
}
                    
/****************************************************************************
 * Type Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_DC_VOLTAGE));
}
                    
/****************************************************************************
 * Type Valid Item Test Index12
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Valid_Item_Index12()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_DC_VOLTAGE_RATIO));
}
                   
/****************************************************************************
 * type Valid Item Test Index13
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_type_Valid_Item_Index13()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurementTriggerParameters(vi, AG3446X_VAL_CONF_MEAS_CAP));
}

/****************************************************************************
 * Type Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasurementTriggerParameters_Type_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureMeasurementTriggerParameters(vi, INVALID_ENUM_VALUE));
}    

/****************************************************************************
 * ag3446x_GetAutoRangeValue Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_GetAutoRangeValue_DefaultParameter()
{
    ViReal64 AutoRangeValue;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_GetAutoRangeValue(vi, &AutoRangeValue));
}

/****************************************************************************
 * ag3446x_GetApertureTimeInfo Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_GetApertureTimeInfo_DefaultParameter()
{
    ViReal64 ApertureTime;
    ViInt32 ApertureTimeUnits;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_GetApertureTimeInfo(vi, &ApertureTime, &ApertureTimeUnits));
}

/****************************************************************************
 * ag3446x_Read Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_Read_DefaultParameter()
{
    ViReal64 Reading;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Read(vi, 5000, &Reading));
}

/****************************************************************************
 * ag3446x_ReadMultiPoint Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ReadMultiPoint_DefaultParameter()
{
    ViInt32 ActualPts;
	ViReal64 ReadingArray[512];
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadMultiPoint(vi, 5000, 512, ReadingArray, &ActualPts));
}

/****************************************************************************
 * ag3446x_ReadHistogramMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ReadHistogramMeasurement_DefaultParameter()
{
    ViChar Readings[10240];

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_100));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadHistogramMeasurement(vi, Readings));
}

/****************************************************************************
 * ag3446x_ReadStatisticsMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ReadStatisticsMeasurement_DefaultParameter()
{
    ViReal64 standardDeviationValue;
	ViReal64 averageValue;
	ViReal64 countValue;
	ViReal64 maximumValue;
	ViReal64 minimumValue;
    ViReal64 peakToPeakValue;
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAverage(vi, VI_TRUE));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadStatisticsMeasurement(vi, &standardDeviationValue, 
																	   &averageValue,
																	   &countValue,
																	   &maximumValue,
																	   &minimumValue,
																	   &peakToPeakValue));
}

/****************************************************************************
 * ag3446x_ReadLastMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ReadLastMeasurement_DefaultParameter()
{
    ViReal64 LastResult;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadLastMeasurement(vi, &LastResult));
}

/****************************************************************************
 * ag3446x_ReadMeasurementCount Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ReadMeasurementCount_DefaultParameter()
{
    ViInt32 DataPoints;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadMeasurementCount(vi, &DataPoints));
}

/****************************************************************************
 * ag3446x_ReadMeasurementMemory Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ReadMeasurementMemory_DefaultParameter()
{
    ViReal64 Result;
	ViReal64  reading;

	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement (vi, AG3446X_VAL_DC_VOLTS, 10, 0.00002));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger (vi, AG3446X_VAL_IMMEDIATE, 0.001));
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Read (vi, 5000, &reading));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadMeasurementMemory(vi, 1, VI_FALSE, &Result));
}
 
    
                
/****************************************************************************
 * ag3446x_ReadMeasurementMemory Boolean Parameter "EnableWait" Test  
 ****************************************************************************/
/****************************************************************************
 * EnableWait Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ReadMeasurementMemory_EnableWait_TRUE()
{            
    ViReal64 Result;
	ViReal64  reading;

	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Read (vi, 5000, &reading));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadMeasurementMemory(vi, 1, VI_TRUE, &Result));
}

/****************************************************************************
 * EnableWait Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ReadMeasurementMemory_EnableWait_FALSE()
{            
    ViReal64 Result;
	ViReal64  reading;

	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Read (vi, 5000, &reading));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadMeasurementMemory(vi, 1, VI_FALSE, &Result));
}

/****************************************************************************
 * ag3446x_Initiate Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_Initiate_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Initiate(vi));
}

/****************************************************************************
 * ag3446x_SendSoftwareTrigger Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_SendSoftwareTrigger_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTrigger(vi, AG3446X_VAL_SOFTWARE_TRIG, 0.0));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_SendSoftwareTrigger(vi));
}

/****************************************************************************
 * ag3446x_Fetch Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_Fetch_DefaultParameter()
{
    ViReal64 Reading;
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Initiate(vi));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Fetch(vi, 5000, &Reading));
}

/****************************************************************************
 * ag3446x_FetchMultiPoint Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_FetchMultiPoint_DefaultParameter()
{
    ViInt32 ActualPts;
	ViReal64 ReadingArray[512];
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Initiate(vi));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_FetchMultiPoint(vi, 5000, 512, ReadingArray, &ActualPts));
}

/****************************************************************************
 * ag3446x_FetchHistogramMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_FetchHistogramMeasurement_DefaultParameter()
{
    ViChar Readings[10240];

    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureHistogram(vi, 0.0, 0.0, VI_TRUE, VI_TRUE, AG3446X_VAL_100));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_FetchHistogramMeasurement(vi, Readings));
}

/****************************************************************************
 * ag3446x_FetchStatisticsMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_FetchStatisticsMeasurement_DefaultParameter()
{
    ViReal64 standardDeviationValue;
	ViReal64 averageValue;
	ViReal64 countValue;
	ViReal64 maximumValue;
	ViReal64 minimumValue;
    ViReal64 peakToPeakValue;
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureAverage(vi, VI_TRUE));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_FetchStatisticsMeasurement(vi, &standardDeviationValue, 
																	   &averageValue,
																	   &countValue,
																	   &maximumValue,
																	   &minimumValue,
																	   &peakToPeakValue));
}
 
/****************************************************************************
 * ag3446x_Abort Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_Abort_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_Abort(vi));
}

/****************************************************************************
 * ag3446x_IsOverRange Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_IsOverRange_DefaultParameter()
{
    ViBoolean IsOverRange;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_IsOverRange(vi, 0, &IsOverRange));
}

/****************************************************************************
 * ag3446x_ClearCalculateData Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ClearCalculateData_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ClearCalculateData(vi, AG3446X_VAL_CLEAR_ALL));
}
 
    
/****************************************************************************
 * ag3446x_ClearCalculateData Ring Parameter "ClearOperation" Test  
 ****************************************************************************/
            
/****************************************************************************
 * ClearOperation Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ClearCalculateData_ClearOperation_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ClearCalculateData(vi, AG3446X_VAL_CLEAR_ALL));
}
                    
/****************************************************************************
 * ClearOperation Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ClearCalculateData_ClearOperation_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ClearCalculateData(vi, AG3446X_VAL_CLEAR_LIMIT));
}
                    
/****************************************************************************
 * ClearOperation Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ClearCalculateData_ClearOperation_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ClearCalculateData(vi, AG3446X_VAL_CLEAR_HIST));
}
                    
/****************************************************************************
 * ClearOperation Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ClearCalculateData_ClearOperation_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ClearCalculateData(vi, AG3446X_VAL_CLEAR_AVER));
}
                    
/****************************************************************************
 * ClearOperation Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ClearCalculateData_ClearOperation_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ClearCalculateData(vi, INVALID_ENUM_VALUE));
}    

/****************************************************************************
 * ag3446x_ConfigureMeasCompleteDest Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureMeasCompleteDest_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasCompleteDest(vi, 0));
}

/****************************************************************************
 * ag3446x_ConfigureSecondaryMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureSecondaryMeasurement_DefaultParameter()
{
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_VOLTS, 0.1, 1E-9));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSecondaryMeasurement(vi, AG3446X_VAL_SEC_FUNC_OFF));
}
                
 
/****************************************************************************
 * ag3446x_ConfigureFrequencyTimeout Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyTimeout_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyTimeout(vi, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureFrequencyTimeout Boolean Parameter "enableAutoTimeout" Test  
 ****************************************************************************/
/****************************************************************************
 * enableAutoTimeout Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyTimeout_enableAutoTimeout_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyTimeout(vi, VI_TRUE));
}

/****************************************************************************
 * enableAutoTimeout Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureFrequencyTimeout_enableAutoTimeout_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFrequencyTimeout(vi, VI_FALSE));
} 
                
 
/****************************************************************************
 * ag3446x_ConfigureThermocouple Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_E, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureThermocouple Ring Parameter "thermocoupleType" Test  
 ****************************************************************************/
            
/****************************************************************************
 * thermocoupleType Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_thermocoupleType_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_E, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
                    
/****************************************************************************
 * thermocoupleType Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_thermocoupleType_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_J, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
                    
/****************************************************************************
 * thermocoupleType Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_thermocoupleType_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_K, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
                    
/****************************************************************************
 * thermocoupleType Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_thermocoupleType_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_N, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
                    
/****************************************************************************
 * thermocoupleType Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_thermocoupleType_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_R, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
                    
/****************************************************************************
 * thermocoupleType Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_thermocoupleType_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_T, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
                    
/****************************************************************************
 * thermocoupleType Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_thermocoupleType_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureThermocouple(vi, INVALID_ENUM_VALUE, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}    
                
/****************************************************************************
 * ag3446x_ConfigureThermocouple Ring Parameter "RefJunctionType" Test  
 ****************************************************************************/
            
/****************************************************************************
 * RefJunctionType Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_RefJunctionType_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_E, AG3446X_VAL_TEMP_REF_JUNC_INTERNAL));
}
                    
/****************************************************************************
 * RefJunctionType Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_RefJunctionType_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_E, AG3446X_VAL_TEMP_REF_JUNC_FIXED));
}
                    
/****************************************************************************
 * RefJunctionType Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocouple_RefJunctionType_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureThermocouple(vi, AG3446X_VAL_TEMP_TC_E, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * ag3446x_ConfigureFixedRefJunction Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFixedRefJunction_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFixedRefJunction(vi, 0));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureFixedRefJunction Ranged Parameter "fixedRefJunction" Test  
 ****************************************************************************/
                
/****************************************************************************
 * fixedRefJunction Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFixedRefJunction_fixedRefJunction_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -20 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFixedRefJunction(vi, minimumValue));
}

/****************************************************************************
 * fixedRefJunction Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFixedRefJunction_fixedRefJunction_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -21 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureFixedRefJunction(vi, belowMinimumValue));
}
                
/****************************************************************************
 * fixedRefJunction Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFixedRefJunction_fixedRefJunction_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 80 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFixedRefJunction(vi, maximumValue));
}

/****************************************************************************
 * fixedRefJunction Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureFixedRefJunction_fixedRefJunction_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 81 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureFixedRefJunction(vi, aboveMaximumValue));
}
                
/****************************************************************************
 * fixedRefJunction Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureFixedRefJunction_fixedRefJunction_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = -20 + rand() % 100 * 100 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureFixedRefJunction(vi, randomValue));
}
                
 
/****************************************************************************
 * ag3446x_ConfigureThermocoupleCheckEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocoupleCheckEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocoupleCheckEnabled(vi, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureThermocoupleCheckEnabled Boolean Parameter "enableTcCheck" Test  
 ****************************************************************************/
/****************************************************************************
 * enableTcCheck Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocoupleCheckEnabled_enableTcCheck_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocoupleCheckEnabled(vi, VI_TRUE));
}

/****************************************************************************
 * enableTcCheck Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureThermocoupleCheckEnabled_enableTcCheck_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermocoupleCheckEnabled(vi, VI_FALSE));
}
            
 
/****************************************************************************
 * ag3446x_ConfigureRefJunctionOffsetAdjustment Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRefJunctionOffsetAdjustment_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRefJunctionOffsetAdjustment(vi, 0));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureRefJunctionOffsetAdjustment Ranged Parameter "adjustment" Test  
 ****************************************************************************/
                
/****************************************************************************
 * adjustment Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRefJunctionOffsetAdjustment_adjustment_RangeMinimumValue_Index1()                
{
    ViInt32 minimumValue = -20 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRefJunctionOffsetAdjustment(vi, minimumValue));
}

/****************************************************************************
 * adjustment Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRefJunctionOffsetAdjustment_adjustment_RangeBelowMinimumValue_Index1()                
{
    ViInt32 belowMinimumValue = -21 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureRefJunctionOffsetAdjustment(vi, belowMinimumValue));
}
                
/****************************************************************************
 * adjustment Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRefJunctionOffsetAdjustment_adjustment_RangeMaximumValue_Index1()                
{
    ViInt32 maximumValue = 20 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRefJunctionOffsetAdjustment(vi, maximumValue));
}

/****************************************************************************
 * adjustment Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureRefJunctionOffsetAdjustment_adjustment_RangeAboveMaximumValue_Index1()                
{
    ViInt32 aboveMaximumValue = 21 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureRefJunctionOffsetAdjustment(vi, aboveMaximumValue));
}
                
/****************************************************************************
 * adjustment Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRefJunctionOffsetAdjustment_adjustment_RangeRandomValue_Index1()                
{
	 
	ViInt32 randomValue = (int)(-20 + rand() % 100 * 40 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRefJunctionOffsetAdjustment(vi, randomValue));
}
                
 
/****************************************************************************
 * ag3446x_ConfigureThermistorPowerLimit Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistorPowerLimit_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermistorPowerLimit(vi, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureThermistorPowerLimit Boolean Parameter "enablePowerLimit" Test  
 ****************************************************************************/
/****************************************************************************
 * enablePowerLimit Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistorPowerLimit_enablePowerLimit_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermistorPowerLimit(vi, VI_TRUE));
}

/****************************************************************************
 * enablePowerLimit Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureThermistorPowerLimit_enablePowerLimit_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureThermistorPowerLimit(vi, VI_FALSE));
}
            
 
/****************************************************************************
 * ag3446x_ConfigureRTDAdvanced Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRTDAdvanced_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTDAdvanced(vi, VI_FALSE, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureRTDAdvanced Boolean Parameter "enablePowerLimit" Test  
 ****************************************************************************/
/****************************************************************************
 * enablePowerLimit Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureRTDAdvanced_enablePowerLimit_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTDAdvanced(vi, VI_FALSE, VI_TRUE));
}

/****************************************************************************
 * enablePowerLimit Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureRTDAdvanced_enablePowerLimit_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRTDAdvanced(vi, VI_FALSE, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureTriggerLevel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureTriggerLevel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureTriggerLevel(vi, 0.0));
}       
 
/****************************************************************************
 * ag3446x_ConfigurePretrigger Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigurePretrigger_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePretrigger(vi, 0));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigurePretrigger Ranged Parameter "preTriggerCount" Test  
 ****************************************************************************/
                
/****************************************************************************
 * preTriggerCount Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigurePretrigger_preTriggerCount_RangeMinimumValue_Index1()                
{
    ViInt32 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePretrigger(vi, minimumValue));
}

/****************************************************************************
 * preTriggerCount Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigurePretrigger_preTriggerCount_RangeBelowMinimumValue_Index1()                
{
    ViInt32 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigurePretrigger(vi, belowMinimumValue));
}
                
/****************************************************************************
 * preTriggerCount Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigurePretrigger_preTriggerCount_RangeMaximumValue_Index1()                
{
    ViInt32 maximumValue = 1999999 ;
    
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT, 0, maximumValue+1));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePretrigger(vi, maximumValue));
}

/****************************************************************************
 * preTriggerCount Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigurePretrigger_preTriggerCount_RangeAboveMaximumValue_Index1()                
{
    ViInt32 aboveMaximumValue = 2.0E6 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigurePretrigger(vi, aboveMaximumValue));
}
                
/****************************************************************************
 * preTriggerCount Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigurePretrigger_preTriggerCount_RangeRandomValue_Index1()                
{
	 
	ViInt32 randomValue = (int)(0 + rand() % 100 * 1.999999E6 / 100.00);
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_SAMPLE_COUNT, 0, randomValue+1));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigurePretrigger(vi, randomValue));
}
 
/****************************************************************************
 * ag3446x_ConfigureDataTransitionFormat Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_COM, VI_FALSE, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureDataTransitionFormat Ring Parameter "separator" Test  
 ****************************************************************************/
            
/****************************************************************************
 * separator Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_separator_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_COM, VI_FALSE, VI_FALSE));
}
                    
/****************************************************************************
 * separator Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_separator_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_SEM, VI_FALSE, VI_FALSE));
}
                    
/****************************************************************************
 * separator Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_separator_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_TAB, VI_FALSE, VI_FALSE));
}
                    
/****************************************************************************
 * separator Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_separator_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureDataTransitionFormat(vi, INVALID_ENUM_VALUE, VI_FALSE, VI_FALSE));
}    
                
/****************************************************************************
 * ag3446x_ConfigureDataTransitionFormat Boolean Parameter "enableReadingInfo" Test  
 ****************************************************************************/
/****************************************************************************
 * enableReadingInfo Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_enableReadingInfo_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_COM, VI_TRUE, VI_FALSE));
}

/****************************************************************************
 * enableReadingInfo Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_enableReadingInfo_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_COM, VI_FALSE, VI_FALSE));
}
            
/****************************************************************************
 * ag3446x_ConfigureDataTransitionFormat Boolean Parameter "enableRowLimit" Test  
 ****************************************************************************/
/****************************************************************************
 * enableRowLimit Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_enableRowLimit_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_COM, VI_FALSE, VI_TRUE));
}

/****************************************************************************
 * enableRowLimit Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureDataTransitionFormat_enableRowLimit_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureDataTransitionFormat(vi, AG3446X_VAL_SEPARATOR_COM, VI_FALSE, VI_FALSE));
}

/****************************************************************************
 * ag3446x_ConfigureScaleAdvanced Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, 0.0));
}
 
                    
/****************************************************************************
 * ag3446x_ConfigureScaleAdvanced Ranged Parameter "gainValue" Test  
 ****************************************************************************/
                
/****************************************************************************
 * gainValue Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, minimumValue, 0.0, 0.0));
}

/****************************************************************************
 * gainValue Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1.0000001E15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, belowMinimumValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = -1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, maximumValue, 0.0, 0.0));
}

/****************************************************************************
 * gainValue Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = -0.9999999E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, aboveMaximumValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = (int)(-1.0E+15 + rand() % 100 * 1.0E15 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, randomValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, minimumValue, 0.0, 0.0));
}

/****************************************************************************
 * gainValue Range Below Minimum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeBelowMinimumValue_Index2()                
{
    ViReal64 belowMinimumValue = -0.0000001E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, belowMinimumValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Maximum Value Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeMaximumValue_Index2()                
{
    ViReal64 maximumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, maximumValue, 0.0, 0.0));
}

/****************************************************************************
 * gainValue Range Above Maximum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeAboveMaximumValue_Index2()                
{
    ViReal64 aboveMaximumValue = 0.0000001E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, aboveMaximumValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeRandomValue_Index2()                
{
	 
	ViReal64 randomValue = (int)(0.0 + rand() % 100 * 0 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, randomValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = +1.0E-15  ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, minimumValue, 0.0, 0.0));
}

/****************************************************************************
 * gainValue Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = 0.9999999E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, belowMinimumValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = 1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, maximumValue, 0.0, 0.0));
}

/****************************************************************************
 * gainValue Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeAboveMaximumValue_Index3()                
{
    ViReal64 aboveMaximumValue = 1.0000001E15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, aboveMaximumValue, 0.0, 0.0));
}
                
/****************************************************************************
 * gainValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_gainValue_RangeRandomValue_Index3()                
{
	 
	ViReal64 randomValue = (int)(+1.0E-15 + rand() % 100 * 1.0E15 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, randomValue, 0.0, 0.0));
}
                                
/****************************************************************************
 * ag3446x_ConfigureScaleAdvanced Ranged Parameter "offsetValue" Test  
 ****************************************************************************/
                
/****************************************************************************
 * offsetValue Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, minimumValue, 0.0));
}

/****************************************************************************
 * offsetValue Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1.0000001E15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, belowMinimumValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = -1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, maximumValue, 0.0));
}

/****************************************************************************
 * offsetValue Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = -0.9999999E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, aboveMaximumValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = (int)(-1.0E+15 + rand() % 100 * 1.0E15 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, randomValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, minimumValue, 0.0));
}

/****************************************************************************
 * offsetValue Range Below Minimum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeBelowMinimumValue_Index2()                
{
    ViReal64 belowMinimumValue = -0.000001E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, belowMinimumValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Maximum Value Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeMaximumValue_Index2()                
{
    ViReal64 maximumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, maximumValue, 0.0));
}

/****************************************************************************
 * offsetValue Range Above Maximum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeAboveMaximumValue_Index2()                
{
    ViReal64 aboveMaximumValue = 0.000001E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, aboveMaximumValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeRandomValue_Index2()                
{
	 
	ViReal64 randomValue = (int)(0.0 + rand() % 100 * 0 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, randomValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = +1.0E-15  ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, minimumValue, 0.0));
}

/****************************************************************************
 * offsetValue Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = 0.9999999E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, belowMinimumValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = 1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, maximumValue, 0.0));
}

/****************************************************************************
 * offsetValue Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeAboveMaximumValue_Index3()                
{
    ViReal64 aboveMaximumValue = 1.0000001E15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, aboveMaximumValue, 0.0));
}
                
/****************************************************************************
 * offsetValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_offsetValue_RangeRandomValue_Index3()                
{
	 
	ViReal64 randomValue = (int)(+1.0E-15 + rand() % 100 * 1.0E15 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, randomValue, 0.0));
}
                                
/****************************************************************************
 * ag3446x_ConfigureScaleAdvanced Ranged Parameter "referenceValue" Test  
 ****************************************************************************/
                
/****************************************************************************
 * referenceValue Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, minimumValue));
}

/****************************************************************************
 * referenceValue Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1.0000001E15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, belowMinimumValue));
}
                
/****************************************************************************
 * referenceValue Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = -1.0E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, maximumValue));
}

/****************************************************************************
 * referenceValue Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = -0.9999999E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, aboveMaximumValue));
}
                
/****************************************************************************
 * referenceValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = (int)(-1.0E+15 + rand() % 100 * 1.0E15 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, randomValue));
}
                
/****************************************************************************
 * referenceValue Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, minimumValue));
}

/****************************************************************************
 * referenceValue Range Below Minimum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeBelowMinimumValue_Index2()                
{
    ViReal64 belowMinimumValue = -0.0000001E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, belowMinimumValue));
}
                
/****************************************************************************
 * referenceValue Range Maximum Value Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeMaximumValue_Index2()                
{
    ViReal64 maximumValue = 0.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, maximumValue));
}

/****************************************************************************
 * referenceValue Range Above Maximum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeAboveMaximumValue_Index2()                
{
    ViReal64 aboveMaximumValue = 0.0000001E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, aboveMaximumValue));
}
                
/****************************************************************************
 * referenceValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeRandomValue_Index2()                
{
	 
	ViReal64 randomValue = (int)(0.0 + rand() % 100 * 0 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, randomValue));
}
                
/****************************************************************************
 * referenceValue Range Minimum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeMinimumValue_Index3()                
{
    ViReal64 minimumValue = +1.0E-15  ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, minimumValue));
}

/****************************************************************************
 * referenceValue Range Below Minimum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeBelowMinimumValue_Index3()                
{
    ViReal64 belowMinimumValue = 0.9999999E-15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, belowMinimumValue));
}
                
/****************************************************************************
 * referenceValue Range Maximum Value Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeMaximumValue_Index3()                
{
    ViReal64 maximumValue = 1.0E+15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, maximumValue));
}

/****************************************************************************
 * referenceValue Range Above Maximum Value Test Index3
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeAboveMaximumValue_Index3()                
{
    ViReal64 aboveMaximumValue = 1.0000001E15 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, aboveMaximumValue));
}
                
/****************************************************************************
 * referenceValue Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_referenceValue_RangeRandomValue_Index3()                
{
	 
	ViReal64 randomValue = (int)(+1.0E-15 + rand() % 100 * 1.0E15 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, randomValue));
}
               
/****************************************************************************
 * enableScaling Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_enableScaling_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, 0.0));
}

/****************************************************************************
 * enableScaling Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleAdvanced_enableScaling_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleAdvanced(vi, 1.0, 0.0, 0.0));
}
            
 
/****************************************************************************
 * ag3446x_ConfigureScaleUnit Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleUnit_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleUnit(vi, VI_FALSE, ""));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureScaleUnit Boolean Parameter "enableScaleUnit" Test  
 ****************************************************************************/
/****************************************************************************
 * enableScaleUnit Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleUnit_enableScaleUnit_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleUnit(vi, VI_TRUE, ""));
}

/****************************************************************************
 * enableScaleUnit Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureScaleUnit_enableScaleUnit_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureScaleUnit(vi, VI_FALSE, ""));
}
            
 
/****************************************************************************
 * ag3446x_ConfigureSmoothing Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_FAST, VI_TRUE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureSmoothing Ring Parameter "numberOfMeasurements" Test  
 ****************************************************************************/
            
/****************************************************************************
 * numberOfMeasurements Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_numberOfMeasurements_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_SLOW, VI_TRUE));
}
                    
/****************************************************************************
 * numberOfMeasurements Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_numberOfMeasurements_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_MEDIUM, VI_TRUE));
}
                    
/****************************************************************************
 * numberOfMeasurements Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_numberOfMeasurements_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_FAST, VI_TRUE));
}
                    
/****************************************************************************
 * numberOfMeasurements Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_numberOfMeasurements_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureSmoothing(vi, INVALID_ENUM_VALUE, VI_TRUE));
}    
                
/****************************************************************************
 * ag3446x_ConfigureSmoothing Boolean Parameter "enableSmoothing" Test  
 ****************************************************************************/
/****************************************************************************
 * enableSmoothing Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_enableSmoothing_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_FAST, VI_TRUE));
}

/****************************************************************************
 * enableSmoothing Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_enableSmoothing_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_FAST, VI_FALSE));
}
            
/****************************************************************************
 * ag3446x_ConfigureSmoothing Boolean Parameter "enableTrendChart" Test  
 ****************************************************************************/
/****************************************************************************
 * enableTrendChart Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_enableTrendChart_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_FAST, VI_TRUE));
}

/****************************************************************************
 * enableTrendChart Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureSmoothing_enableTrendChart_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureSmoothing(vi, AG3446X_VAL_SMOOTHING_RESPONSE_FAST, VI_TRUE));
}

/****************************************************************************
 * ag3446x_ConfigureResistance Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureResistance_DefaultParameter()
{
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32(vi, VI_NULL, AG3446X_ATTR_FUNCTION, 0, AG3446X_VAL_2_WIRE_RES));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64(vi, VI_NULL, AG3446X_ATTR_RANGE, 0, 100));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureResistance(vi, VI_FALSE, VI_FALSE));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureResistance Boolean Parameter "enableOffsetCompensation" Test  
 ****************************************************************************/
/****************************************************************************
 * enableOffsetCompensation Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureResistance_enableOffsetCompensation_TRUE()
{            
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureResistance(vi, VI_TRUE, VI_FALSE));
}

/****************************************************************************
 * enableOffsetCompensation Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureResistance_enableOffsetCompensation_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureResistance(vi, VI_FALSE, VI_FALSE));
}
            
/****************************************************************************
 * ag3446x_ConfigureResistance Boolean Parameter "enablePowerLimit" Test  
 ****************************************************************************/
/****************************************************************************
 * enablePowerLimit Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_ag3446x_ConfigureResistance_enablePowerLimit_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureResistance(vi, VI_FALSE, VI_TRUE));
}

/****************************************************************************
 * enablePowerLimit Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_ag3446x_ConfigureResistance_enablePowerLimit_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureResistance(vi, VI_FALSE, VI_FALSE));
}
             
/****************************************************************************
 * ag3446x_ConfigureRangeChangeMode Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRangeChangeMode_DefaultParameter()
{
 	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_CURRENT, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCurrentTerminals(vi, AG3446X_VAL_CURR_TERM_3));   
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRangeChangeMode(vi, AG3446X_VAL_RANGE_CHANGE_FAST));
}
 
    
/****************************************************************************
 * ag3446x_ConfigureRangeChangeMode Ring Parameter "rangeChangeMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * rangeChangeMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRangeChangeMode_rangeChangeMode_Valid_Item_Index1()
{
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_CURRENT, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCurrentTerminals(vi, AG3446X_VAL_CURR_TERM_3));
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRangeChangeMode(vi, AG3446X_VAL_RANGE_CHANGE_FAST));
}
                    
/****************************************************************************
 * rangeChangeMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRangeChangeMode_rangeChangeMode_Valid_Item_Index2()
{
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_CURRENT, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCurrentTerminals(vi, AG3446X_VAL_CURR_TERM_3));    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureRangeChangeMode(vi, AG3446X_VAL_RANGE_CHANGE_CONT));
}
                    
/****************************************************************************
 * rangeChangeMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureRangeChangeMode_rangeChangeMode_Invalid()
{
 	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureMeasurement(vi, AG3446X_VAL_DC_CURRENT, AG3446X_VAL_AUTO_RANGE_ON, 1E-6));
	CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureCurrentTerminals(vi, AG3446X_VAL_CURR_TERM_3));   
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureRangeChangeMode(vi, INVALID_ENUM_VALUE));
}

/****************************************************************************
 * ag3446x_ConfigureApertureTime Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, 10.0));
}
    
/****************************************************************************
 * ag3446x_ConfigureApertureTime Ring Parameter "apertureTimeUnits" Test  
 ****************************************************************************/
            
/****************************************************************************
 * apertureTimeUnits Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTimeUnits_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_SECONDS, 0.1));
}
                    
/****************************************************************************
 * apertureTimeUnits Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTimeUnits_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, 10));
}
                    
/****************************************************************************
 * apertureTimeUnits Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTimeUnits_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != ag3446x_ConfigureApertureTime(vi, INVALID_ENUM_VALUE, 10));
}    
                
/****************************************************************************
 * _ConfigureApertureTime Coerced Parameter "apertureTime" Test  
 ****************************************************************************/          
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index1()                
{
    ViReal64 maximumValue = 0.001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index1()                
{
	 
    ViReal64 randomValue = 0.0 + rand() % 100 * 0.001 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}        
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index2()                
{
    ViReal64 maximumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index2()                
{
	 
    ViReal64 randomValue = 0.001 + rand() % 100 * 0.001 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index3()                
{
    ViReal64 maximumValue = 0.006 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index3
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index3()                
{
	 
    ViReal64 randomValue = 0.002 + rand() % 100 * 0.004 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index4()                
{
    ViReal64 maximumValue = 0.02 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index4
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index4()                
{
	 
    ViReal64 randomValue = 0.006 + rand() % 100 * 0.014 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index5
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index5()                
{
    ViReal64 maximumValue = 0.06 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index5
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index5()                
{
	 
    ViReal64 randomValue = 0.02 + rand() % 100 * 0.039999999999999994 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index6
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index6()                
{
    ViReal64 maximumValue = 0.2 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index6
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index6()                
{
	 
    ViReal64 randomValue = 0.06 + rand() % 100 * 0.14 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index7
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index7()                
{
    ViReal64 maximumValue = 1.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}

/****************************************************************************
 * apertureTime Coerced Random Value Test Index7
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index7()                
{
	 
    ViReal64 randomValue = 0.2 + rand() % 100 * 0.8 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index8
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index8()                
{
    ViReal64 maximumValue = 10.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index8
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index8()                
{
	 
    ViReal64 randomValue = 1.0 + rand() % 100 * 9 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
                
/****************************************************************************
 * apertureTime Coerced Maximum Value Test Index9
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedMaximumValue_Index9()                
{
    ViReal64 maximumValue = 100.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, maximumValue));
}
                
/****************************************************************************
 * apertureTime Coerced Random Value Test Index9
 ****************************************************************************/	
void DriverFunctionalityTest::test_ag3446x_ConfigureApertureTime_apertureTime_CoercedRandomValue_Index9()                
{
	 
    ViReal64 randomValue = 10.0 + rand() % 100 * 90 / 100.00;	
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ConfigureApertureTime(vi, AG3446X_VAL_POWER_LINE_CYCLES, randomValue));
}
 
/****************************************************************************
 * ag3446x_ReadSecondaryMeasurement Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_ag3446x_ReadSecondaryMeasurement_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == ag3446x_ReadSecondaryMeasurement(vi, VI_NULL, VI_NULL));
}
                    





