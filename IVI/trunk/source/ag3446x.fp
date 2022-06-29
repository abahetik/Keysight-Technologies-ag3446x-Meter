s��        kp   � �  Kx   �   ����                               ag3446x                         Agilent 3446X Series Multimeter                                                                       � � ��ViInt16  �  � ��ViInt32  � � ��ViReal64     � ��ViRsrc     	� 	��ViBoolean     	� 	��ViSession     � ��ViStatus     �  ViChar[]     � ��ViChar     � ��ViString     	�  ViInt16[]     	�  ViInt32[]     
�  	ViReal64[]     � 	 
ViBoolean[]     � ��ViConstString     � ��ViAttr     � ��ViAddr     �  ViByte[]     � ��ViInt64  �    This instrument driver provides programming support for the Agilent/Keysight 3446X Series.  The driver contains all the functions that IVI and VXIplug&play require.  In addition, the driver contains high-level functions that configure the DMM and take a measurement in a single operation.  The driver also contains lower level functions that configure, initiate a measurement, and retrieve the data in separate operations.   

Note:  This driver requires the VISA and IVI libraries.  

    �    This class contains functions and sub-classes that configure the DMM.  The class includes high-level functions that configure the basic measurement operation and subclasses that configure the trigger and the multi-point measurement capability.  It also contains sub-classes that configure additional parameters for some measurement types, that return information about the current state of the instrument, and that set, get, and check individual attribute values.
     �    This class contains functions and sub-classes that configure additional parameters for some measurement types. These are the AC Voltage, AC Current, frequency, period, and temperature measurements.      �    This class contains functions that configure additional parameters for temperature measurements. These parameters include the transducer type and settings specific to each transducer type.     �    This class contains functions that configure the triggering capabilities of the DMM. These include the trigger source, trigger delay, and trigger slope.     W    This class contains functions that configure the multi-point capabilities of the DMM.     W    This class contains functions that configure the calibration capabilities of the DMM.     R    This class contains functions that configure the memory capabilities of the DMM.     �    This class contains functions that configure the instrument for different measurement operations. These operations are the auto zero mode, average, limit, scale, histogram, current teminals, voltage impedance, null operation and trigger parameters.     �    This class contains functions that return information about the current state of the instrument. This information includes the actual range, aperture time, and the aperture time units.     T    This class contains sub-classes for the set, get, and check attribute functions.       �    This class contains functions that set an attribute to a new value.  There are typesafe functions for each attribute data type.     �    This class contains functions that obtain the current value of an attribute.  There are typesafe functions for each attribute data type.     �    This class contains functions that obtain the current value of an attribute.  There are typesafe functions for each attribute data type.    �    This class contains functions and sub-classes that initiate and retrieve measurements using the current configuration.  The class contains high-level read functions that initiate a measurement and fetch the data in one operation.  The class also contains low-level functions that initiate the measurement process, send a software trigger, and fetch measurement values in separate operations.
    L    The class contains functions that give low-level control over how the DMM takes measurements.  The functions perform the following operations:

- initiate the measurement process,
- send a software trigger, 
- fetch measurement values, and 
- abort the measurement process.  
- determine if an over-range condition has occurred.

     F    This class contains functions that send and receive instrument data.    _    This class contains functions and sub-classes that control common instrument operations.  These functions include many of functions that VXIplug&play require, such as reset, self-test, revision query, error query, and error message.  This class also contains functions that access IVI error infomation, lock the session, and perform instrument I/O.
     R    This class contains functions that retrieve and clear the IVI error information.     ?    This class contains functions that retrieve coercion records.     J    This class contains functions that retrieve interchangeability warnings.     k    This class contains functions that lock and unlock IVI instrument driver sessions for multithread safefy.     )    This class contains obsolete functions.     F    This class contains functions that send and receive instrument data.    C    This function performs the following initialization actions:

- Creates a new IVI instrument driver session.

- Opens a session to the specified device using the interface and address you specify for the Resource Name parameter.

- If the ID Query parameter is set to VI_TRUE, this function queries the instrument ID and checks that it is valid for this instrument driver.

- If the Reset parameter is set to VI_TRUE, this function resets the instrument to a known state.

- Sends initialization commands to set the instrument to the state necessary for the operation of the instrument driver.

- Returns a ViSession handle that you use to identify the instrument in all subsequent instrument driver function calls.

Note:  This function creates a new session each time you invoke it. Although you can open more than one IVI session for the same resource, it is best not to do so.  You can use the same session in multiple program threads.  You can use the ag3446x_LockSession and ag3446x_UnlockSession functions to protect sections of code that require exclusive access to the resource.

Content from the IVI specifications reproduced with permission from the IVI Foundation. 
 
The IVI Foundation and its member companies make no warranty of any kind with regard to this material, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose. The IVI Foundation and its member companies shall not be liable for errors contained herein or for incidental or consequential damages in connection with the furnishing, performance, or use of this material.    �    Pass the resource name of the device to initialize.

You can also pass the name of a virtual instrument or logical name that you configure with the IVI Configuration utility.  The virtual instrument identifies a specific device and specifies the initial settings for the session.  A logical Name identifies a particular virtual instrument.

Refer to the following table below for the exact grammar to use for this parameter.  Optional fields are shown in square brackets ([]).

Syntax
------------------------------------------------------
GPIB[board]::<primary address>[::secondary address]::INSTR
<LogicalName>

If you do not specify a value for an optional field, the following values are used:

 ------------------------------------
 |    Optional Field    |   Value   |
 ------------------------------------
 | Board                |     0     |
 | Secondary Address    | none (31) |
 -----------------------------------

The following table contains example valid values for this parameter.

 --------------------------------------------------------------
 |    Valid Value       |             Description             |
 --------------------------------------------------------------
 | GPIB::22::INSTR      | GPIB board 0, primary address 22    |
 |                      | no secondary address                |
 | GPIB::22::5::INSTR   | GPIB board 0, primary address 22    |
 |                      | secondary address 5                 |
 | GPIB1::22::5::INSTR  | GPIB board 1, primary address 22    |
 |                      | secondary address 5                 |
 | TCPIP::10.0.32.48::INSTR                | TCP/IP INSTR     |
 | TCPIP::10.0.32.45::3800::SOCKET         | TCP/IP Socket    |
 | USB0::0x0957::0x1A07::MY53200112::INSTR | USB interface    |
 | SampleDmm            | Logical name "SampleDmm"            |
 --------------------------------------------------------------
 
Default Value:  "GPIB::14::INSTR"        Specify whether you want the instrument driver to perform an ID Query.

Valid Range:
VI_TRUE  (1) - Perform ID Query (Default Value)
VI_FALSE (0) - Skip ID Query

When you set this parameter to VI_TRUE, the driver verifies that the instrument you initialize is a type that this driver supports.  

Circumstances can arise where it is undesirable to send an ID Query command string to the instrument.  When you set this parameter to VI_FALSE, the function initializes the instrument without performing an ID Query.

SCPI Command:
*IDN?     �    Specify whether you want the to reset the instrument during the initialization procedure.

Valid Range:
VI_TRUE  (1) - Reset Device (Default Value)
VI_FALSE (0) - Don't Reset

SCPI Command:
*IDN?

    �    Returns a ViSession handle that you use to identify the instrument in all subsequent instrument driver function calls.

Notes:

(1) This function creates a new session each time you invoke it.  This is useful if you have multiple physical instances of the same type of instrument.  

(2) Avoid creating multiple concurrent sessions to the same physical instrument.  Although you can create more than one IVI session for the same resource, it is best not to do so.  A better approach is to use the same IVI session in multiple execution threads.  You can use functions ag3446x_LockSession and ag3446x_UnlockSession to protect sections of code that require exclusive access to the resource.

    s    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors    � =   �  �    Resource Name                     !� : �       ID Query                          #� =� �       Reset Device                      $  �  �    Instrument Handle                 ';����  �    Status                          ����  ���                                            "GPIB::14::INSTR"   Yes VI_TRUE No VI_FALSE   Yes VI_TRUE No VI_FALSE    	           	           BCopyright 2013 - 2021 National Instruments.  All Rights Reserved.   I    This function performs the following initialization actions:

- Creates a new IVI instrument driver and optionally sets the initial state of the following session attributes:

    AG3446X_ATTR_RANGE_CHECK         
    AG3446X_ATTR_QUERY_INSTRUMENT_STATUS  
    AG3446X_ATTR_CACHE               
    AG3446X_ATTR_SIMULATE            
    AG3446X_ATTR_RECORD_COERCIONS    

- Opens a session to the specified device using the interface and address you specify for the Resource Name parameter.

- If the ID Query parameter is set to VI_TRUE, this function queries the instrument ID and checks that it is valid for this instrument driver.

- If the Reset parameter is set to VI_TRUE, this function resets the instrument to a known state.

- Sends initialization commands to set the instrument to the state necessary for the operation of the instrument driver.

- Returns a ViSession handle that you use to identify the instrument in all subsequent instrument driver function calls.

Note:  This function creates a new session each time you invoke it. Although you can open more than one IVI session for the same resource, it is best not to do so.  You can use the same session in multiple program threads.  You can use the ag3446x_LockSession and ag3446x_UnlockSession functions to protect sections of code that require exclusive access to the resource.

Content from the IVI specifications reproduced with permission from the IVI Foundation. 
 
The IVI Foundation and its member companies make no warranty of any kind with regard to this material, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose. The IVI Foundation and its member companies shall not be liable for errors contained herein or for incidental or consequential damages in connection with the furnishing, performance, or use of this material.    �    Pass the resource name of the device to initialize.

You can also pass the name of a virtual instrument or logical name that you configure with the IVI Configuration utility.  The virtual instrument identifies a specific device and specifies the initial settings for the session.  A logical Name identifies a particular virtual instrument.

Refer to the following table below for the exact grammar to use for this parameter.  Optional fields are shown in square brackets ([]).

Syntax
------------------------------------------------------
GPIB[board]::<primary address>[::secondary address]::INSTR
<LogicalName>

If you do not specify a value for an optional field, the following values are used:

 ------------------------------------
 |    Optional Field    |   Value   |
 ------------------------------------
 | Board                |     0     |
 | Secondary Address    | none (31) |
 -----------------------------------

The following table contains example valid values for this parameter.

 --------------------------------------------------------------
 |    Valid Value       |             Description             |
 --------------------------------------------------------------
 | GPIB::22::INSTR      | GPIB board 0, primary address 22    |
 |                      | no secondary address                |
 | GPIB::22::5::INSTR   | GPIB board 0, primary address 22    |
 |                      | secondary address 5                 |
 | GPIB1::22::5::INSTR  | GPIB board 1, primary address 22    |
 |                      | secondary address 5                 |
 | TCPIP::10.0.32.48::INSTR                | TCP/IP INSTR     |
 | TCPIP::10.0.32.45::3800::SOCKET         | TCP/IP Socket    |
 | USB0::0x0957::0x1A07::MY53200112::INSTR | USB interface    |
 | SampleDmm            | Logical name "SampleDmm"            |
 --------------------------------------------------------------
 
Default Value:  "GPIB::14::INSTR"        Specify whether you want the instrument driver to perform an ID Query.

Valid Range:
VI_TRUE  (1) - Perform ID Query (Default Value)
VI_FALSE (0) - Skip ID Query

When you set this parameter to VI_TRUE, the driver verifies that the instrument you initialize is a type that this driver supports.  

Circumstances can arise where it is undesirable to send an ID Query command string to the instrument.  When you set this parameter to VI_FALSE, the function initializes the instrument without performing an ID Query.

SCPI Command:
*IDN?     �    Specify whether you want the to reset the instrument during the initialization procedure.

Valid Range:
VI_TRUE  (1) - Reset Device (Default Value)
VI_FALSE (0) - Don't Reset

SCPI Command:
*IDN?

    �    Returns a ViSession handle that you use to identify the instrument in all subsequent instrument driver function calls.

Notes:

(1) This function creates a new session each time you invoke it.  This is useful if you have multiple physical instances of the same type of instrument.  

(2) Avoid creating multiple concurrent sessions to the same physical instrument.  Although you can create more than one IVI session for the same resource, it is best not to do so.  A better approach is to use the same IVI session in multiple execution threads.  You can use functions ag3446x_LockSession and ag3446x_UnlockSession to protect sections of code that require exclusive access to the resource.

    t    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors    �    You can use this control to set the initial value of certain attributes for the session.  The following table lists the attributes and the name you use in this parameter to identify the attribute.

Name              Attribute Defined Constant   
--------------------------------------------
RangeCheck        AG3446X_ATTR_RANGE_CHECK
QueryInstrStatus  AG3446X_ATTR_QUERY_INSTRUMENT_STATUS   
Cache             AG3446X_ATTR_CACHE   
Simulate          AG3446X_ATTR_SIMULATE  
RecordCoercions   AG3446X_ATTR_RECORD_COERCIONS

The format of this string is, "AttributeName=Value" where AttributeName is the name of the attribute and Value is the value to which the attribute will be set.  To set multiple attributes, separate their assignments with a comma.

If you pass NULL or an empty string for this parameter and a VISA resource descriptor for the Resource Name parameter, the session uses the default values for the attributes. The default values for the attributes are shown below:

    Attribute Name     Default Value
    ----------------   -------------
    RangeCheck         VI_TRUE
    QueryInstrStatus   VI_FALSE
    Cache              VI_TRUE
    Simulate           VI_FALSE
    RecordCoercions    VI_FALSE
    

If you pass NULL or an empty string for this parameter and a virtual instrument or logical name for the Resource Name parameter, the session uses the values that you configure for virtual instrument or logical name with the IVI Configuration utility.

You can override the values of the attributes by assigning a value explicitly in a string you pass for this parameter.  You do not have to specify all of the attributes and may leave any of them out.  If you do not specify one of the attributes, its default value or the value that you configure with the IVI Configuration utility will be used.

The following are the valid values for ViBoolean attributes:

    True:     1, TRUE, or VI_TRUE
    False:    0, False, or VI_FALSE


Default Value:
"Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1"
    6� =   �  �    Resource Name                     >� : �       ID Query                          @� =� �       Reset Device                      Ao �Y �  �    Instrument Handle                 D+#����  �    Status                            J� �  � �    Option String                   ���� 
 ���                                            "GPIB::14::INSTR"   Yes VI_TRUE No VI_FALSE   Yes VI_TRUE No VI_FALSE    	           	           5"Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1"    BCopyright 2013 - 2021 National Instruments.  All Rights Reserved.    �    This function configures the common attributes of the DMM.  These attributes include the measurement function, maximum range, and the absolute resolution.


    v    Pass the measurement range you want to use.  The driver sets the AG3446X_ATTR_RANGE attribute to this value.  

Use positive values to represent the absolute value of the maximum expected measurement.  The value must be in units appropriate for the Measurement Function.  For example, when you set the Measurement Function to AG3446X_VAL_DC_VOLTS, you must specify the Range in volts.  Setting this parameter to 10.0 configures the DMM to measure DC voltages from -10.0 to +10.0 volts.

The driver reserves special negative values for controlling the DMM's auto-ranging capability.

Defined Values:
AG3446X_VAL_AUTO_RANGE_ON  (-1.0) - Auto-range On
AG3446X_VAL_AUTO_RANGE_OFF (-2.0) - Auto-range Off
AG3446X_VAL_AUTO_RANGE_ONCE (-3.0) - Auto-range Once

Valid Manual Range:
The valid manual range depends on the measurement function.  The following table lists the valid manual ranges.

 ---------------------------------------------------------
 |    Function   |   Min Value   |   Max Value   | Unit  |  
 ---------------------------------------------------------
 | DC Volts      | 0.1           | 1000.0        | volts |
 | AC Volts      | 0.1           | 10000         | volts |
 | AC Volts      | 0.1           | 750           | volts | For EDU34450A
 | DC Current    | 0.0001        | 3.0           | amps  |
 | DC Current    | 0.01          | 3.0           | amps  | For EDU34450A
 | AC Current    | 0.0001        | 3.0           | amps  |
 | AC Current    | 0.01          | 3.0           | amps  | For EDU34450A
 | 2-Wire Res    | 100.0         | 100.0E6       | ohms  |
 | 4-Wire Res    | 100.0         | 100.0E6       | ohms  |
 | Frequency     | Auto-Range On | Auto-Range On | ----- |
 | Period        | Auto-Range On | Auto-Range On | ----- |
 | Temperature   | Auto-Range On | Auto-Range On | ----- | 
 | Diode         | Auto-Range On | Auto-Range On | ----- |
 | Continuity    | Auto-Range On | Auto-Range On | ----- |
 | DC Volts Ratio| 0.1           | 1000.0        | volts |
 | Capacitance   | 1e-9          | 1e-4          |  F    |
 | Capacitance   | 1e-9          | 1e-2          |  F    | For EDU34450A
 --------------------------------------------------------- 

Default Value:
AG3446X_VAL_AUTO_RANGE_ON (-1.0)

Notes:

(1) Setting this parameter to AG3446X_VAL_AUTO_RANGE_ONCE configures the DMM to auto-range once, turn auto-range off, and then remain at the current maximum range.

(2) AG3446X_VAL_AUTO_RANGE_ONCE not supported for EDU34450A.

(3) Setting this parameter AG3446X_VAL_AUTO_RANGE_OFF configures the DMM to stop auto-ranging and keep the range fixed at the current maximum range.

SCPI Command:
[SENSe:]CURRent:{AC|DC}:RANGe{<range>|MIN|MAX|DEF}
[SENSe:]CURRent:{AC|DC}:RANGe:AUTO {OFF|ON|ONCE}
[SENSe:]CURRent:{AC|DC}:RANGe:AUTO {OFF|ON} for EDU34450A.
[SENSe:]{RESistance|FRESistance}:RANGe {<range>|MIN|MAX|DEF}
[SENSe:]{RESistance|FRESistance}:RANGe:AUTO {OFF|ON|ONCE}
[SENSe:]{RESistance|FRESistance}:RANGe:AUTO {OFF|ON} for EDU34450A.
[SENSe:]VOLTage:{AC|DC}:RANGe {<range>|MIN|MAX|DEF}
[SENSe:]VOLTage:{AC|DC}:RANGe:AUTO {OFF|ON|ONCE}
[SENSe:]VOLTage:{AC|DC}:RANGe:AUTO {OFF|ON} for EDU34450A.
[SENSe:]CAPacitance:RANGe {<range>|MIN|MAX|DEF}    �    Pass your desired measurement resolution in absolute units. The driver sets the AG3446X_ATTR_RESOLUTION_ABSOLUTE attribute to this value.

Setting this parameter to lower values increases the measurement accuracy.  Setting this parameter to higher values increases the measurement speed.      

Valid Range:

The valid range depends on the current measurement function and the current measurement range that you select with the AG3446X_ATTR_FUNCTION and the AG3446X_ATTR_RANGE attributes. The table below shows the minimum and maximum resolution values for each measurement type. The minimum resolution values are based on the maximum possible range for that measurement function. The maximum resolution values are based on the minimum possible range. 

 ----------------------------------------------------------------------------------------------------------------------------------------------
 |                 Integration Time               |  Resolution (34460A)  |  Resolution (34461A)  | Resolution (34465A) | Resolution (34470A) |
 | power line     |    Aperture   |    Aperture   |                       |                       |                     |                     |
 | cycles         | (60 Hz Power) | (50 Hz Power) |                       |                       |                     |                     |
 ----------------------------------------------------------------------------------------------------------------------------------------------
 | 0.001 PLC      | 20 us         | 20 us         | N/A                   | N/A                   | 30 ppm x Range      | 30 ppm x Range      |
 | 0.002 PLC      | 40 us         | 40 us         | N/A                   | N/A                   | 15 ppm x Range      | 15 ppm x Range      |
 | 0.006 PLC      | 100 us        | 100 us        | N/A                   | N/A                   | 6 ppm x Range       | 3 ppm x Range       |
 | 0.02 PLC (MIN) | 0.3 ms        | 0.3 ms        | 300 ppm * Range (MAX) | 100 ppm * Range (MAX) | 3 ppm x Range       | 1 ppm x Range       |
 | 0.06 PLC       | 1 ms          | 1 ms          | N/A                   | N/A                   | 1.5 ppm x Range     | 0.5 ppm x Range     |
 | 0.2 PLC        | 3 ms          | 3 ms          | 100 ppm * Range       | 10 ppm * Range        | 0.7 ppm x Range     | 0.3 ppm x Range     |
 | 1 PLC          | 16.7 ms       | 20 ms         | 30 ppm * Range        | 3 ppm * Range         | 0.3 ppm x Range     | 0.1 ppm x Range     |
 | 10 PLC (DEF)   | 0.167 s       | 0.2 s         | 10 ppm * Range (DEF)  | 1 ppm * Range (DEF)   | 0.1 ppm x Range     | 0.03 ppm x Range    |
 | 100 PLC (MAX)  | 1.67 s        | 2 s           | 3 ppm * Range (MIN)   | 0.3 ppm * Range (MIN) | 0.03 ppm x Range    | 0.01 ppm x Range    |
 ----------------------------------------------------------------------------------------------------------------------------------------------
 
Valid values for EDU34450A:

AG3446X_VAL_SLOW   - SLOW 
AG3446X_VAL_MEDIUM - MEDIUM
AG3446X_VAL_FAST   - FAST

Default Value: 1E-6

Notes:

(1) This parameter is ignored if the 'Range' parameter is set to AG3446X_VAL_AUTO_RANGE_ON.
(2) EDU34450A supports SLOW,MEDIUM,FAST parameters only, to set resolution need to pass these parameters only.

SCPI Command:
[SENSe:]CURRent[:DC]:RESolution {<resolution>|MIN|MAX|DEF}
[SENSe:]{RESistance|FRESistance}:RESolution {<resolution>|MIN|MAX|DEF}
[SENSe:]VOLTage[:DC]:RESolution{<resolution>|MIN|MAX|DEF}

SCPI Commands supported for EDU34450A:
[SENSe:][PRIMary:]VOLTage:AC:RESolution <resolution>|MIN|MAX|DEF 
<resolution>: SLOW|MEDium|FAST
[SENSe:][PRIMary:]VOLTage[:DC]:RESolution <resolution>|MIN|MAX|DEF
<resolution>: SLOW|MEDium|FAST
[SENSe:][PRIMary:]CURRent:AC:RESolution <resolution>|MIN|MAX|DEF
<resolution>: SLOW|MEDium|FAST
[SENSe:][PRIMary:]CURRent[:DC]:RESolution <resolution>|MIN|MAX|DEF
<resolution>: SLOW|MEDium|FAST
[SENSe:][PRIMary:]RESistance:RESolution <resolution>|MIN|MAX|DEF
<resolution>: SLOW|MEDium|FAST
[SENSe:][PRIMary:]FRESistance:RESolution <resolution>|MIN|MAX|DEF
<resolution>: SLOW|MEDium|FAST


     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    t    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:        
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    4    Specifies the measurement function. The driver uses this value to set the AG3446X_ATTR_FUNCTION attribute.

Valid Values:
AG3446X_VAL_DC_VOLTS   -  DC Volts
AG3446X_VAL_AC_VOLTS   -  AC Volts
AG3446X_VAL_DC_CURRENT   -  DC Current
AG3446X_VAL_AC_CURRENT   -  AC Current
AG3446X_VAL_2_WIRE_RES   -  2 Wire Resistance
AG3446X_VAL_4_WIRE_RES   -  4 Wire Resistance
AG3446X_VAL_FREQ   -  Frequency
AG3446X_VAL_PERIOD   -  Period
AG3446X_VAL_TEMPERATURE   -  Temperature
AG3446X_VAL_CONTINUITY   -  Continuity
AG3446X_VAL_DIODE   -  Diode
AG3446X_VAL_DC_VOLTS_RATIO   -  DC Volts Ratio
AG3446X_VAL_CAPACITANCE - Capacitance

Default Value: AG3446X_VAL_DC_VOLTS

SCPI Command:
[SENSe:]FUNCtion[:ON] "<function>"

Note: 
AG3446X_VAL_DC_VOLTS_RATIO Not supported by EDU34450A.
AG3446X_VAL_PERIOD Not supported by EDU34450A.


    U� = �  �    Range                             b z W �  �    Resolution (absolute)             r-   �  �    Instrument Handle                 r�#����  �    Status                            yD > W � �    Measurement Function               AG3446X_VAL_AUTO_RANGE_ON    1E-6        	                     �DC Volts AG3446X_VAL_DC_VOLTS AC Volts AG3446X_VAL_AC_VOLTS DC Current AG3446X_VAL_DC_CURRENT AC Current AG3446X_VAL_AC_CURRENT 2 Wire Resistance AG3446X_VAL_2_WIRE_RES 4 Wire Resistance AG3446X_VAL_4_WIRE_RES Frequency AG3446X_VAL_FREQ Period AG3446X_VAL_PERIOD Temperature AG3446X_VAL_TEMPERATURE Continuity AG3446X_VAL_CONTINUITY Diode AG3446X_VAL_DIODE DC Volts Ratio AG3446X_VAL_DC_VOLTS_RATIO Capacitance AG3446X_VAL_CAPACITANCE    �    This function selects the secondary measurement function for the current measurement.

Notes:
(1) This function only applies to 34465A and 34470A.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    t    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:        
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Selects the secondary measurement function for the current selected measurement specified by the AG3446X_ATTR_FUNCTION attribute.

Valid Values:
For all measurement functions:
    AG3446X_VAL_SEC_FUNC_OFF - Off
    AG3446X_VAL_SEC_FUNC_CALC - Calculate data

When primary function is AG3446X_VAL_DC_VOLTS
    AG3446X_VAL_SEC_FUNC_VAC - AC voltage
    AG3446X_VAL_SEC_FUNC_PTP - Peak to Peak

When primary function is AG3446X_VAL_AC_VOLTS: 
    AG3446X_VAL_SEC_FUNC_VDC - DC voltage
    
When primary function is AG3446X_VAL_DC_CURRENT: 
    AG3446X_VAL_SEC_FUNC_CAC - AC current
    AG3446X_VAL_SEC_FUNC_PTP - Peak to Peak
   
When primary function is AG3446X_VAL_AC_CURRENT: 
    AG3446X_VAL_SEC_FUNC_CDC - DC current 
    AG3446X_VAL_SEC_FUNC_FREQ - Frequency
                  
When primary function is AG3446X_VAL_FREQ:       
    AG3446X_VAL_SEC_FUNC_VAC - AC voltage
    AG3446X_VAL_SEC_FUNC_PER - Period
             
When primary function is AG3446X_VAL_PERIOD:       
    AG3446X_VAL_SEC_FUNC_VAC - AC voltage
    AG3446X_VAL_SEC_FUNC_FREQ - Frequency
  
When primary function is AG3446X_VAL_TEMPERATURE or AG3446X_VAL_DC_VOLTS_RATIO:  
    AG3446X_VAL_SEC_FUNC_SENS - Sense data

Default Value: AG3446X_VAL_SEC_FUNC_OFF

SCPI Command:
[SENSe:]VOLTage[:DC]:SECondary {"OFF"|"CALCulate:DATA"|"VOLTage:AC"|"PTPeak"}
[SENSe:]VOLTage:AC:SECondary {"OFF"|"CALCulate:DATA"|"FREQuency"|"VOLTage[:DC]"}
[SENSe:]CURRent[:DC]:SECondary {"OFF"|"CALCulate:DATA"|"CURRent:AC"|"PTPeak"}
[SENSe:]CURRent:AC:SECondary {"OFF"|"CALCulate:DATA"|"FREQuency"|"CURRent[:DC]"}
[SENSe:]FREQuency:SECondary {"OFF"|"CALCulate:DATA"|"PERiod"|"VOLTage:AC"}
[SENSe:]PERiod:SECondary {"OFF"|"CALCulate:DATA"|"FREQuency"|"VOLTage:AC"}
[SENSe:]{FRESistance|RESistance}:SECondary {"OFF"|"CALCulate:DATA"}
[SENSe:]TEMPerature:SECondary {"OFF"|"CALCulate:DATA"|"SENSe:DATA"}
[SENSe:]VOLTage[:DC]:RATio:SECondary {"OFF"|"CALCulate:DATA"|"SENSe:DATA"}
[SENSe:]CAPacitance:SECondary {"OFF"|"CALCulate:DATA"}    �-   �  �    Instrument Handle                 ��#����  �    Status                            �Q = � � �    Secondary Function                     	                   
  aOff AG3446X_VAL_SEC_FUNC_OFF Calculate Data AG3446X_VAL_SEC_FUNC_CALC DC Volts AG3446X_VAL_SEC_FUNC_VDC AC Volts AG3446X_VAL_SEC_FUNC_VAC DC Current AG3446X_VAL_SEC_FUNC_CDC AC Current AG3446X_VAL_SEC_FUNC_CAC Period AG3446X_VAL_SEC_FUNC_PER Frequency AG3446X_VAL_SEC_FUNC_FREQ Peak to Peak AG3446X_VAL_SEC_FUNC_PTP Sense Data AG3446X_VAL_SEC_FUNC_SENS   ?    This function configures the AC minimum and maximum frequency for DMMs that take AC voltage or AC current measurements.

This function affects the behavior of the instrument only if the AG3446X_ATTR_FUNCTION attribute is set to an AC voltage or AC current measurement.

Note: This function not supported for EDU34450A    #    Pass the minimum expected frequency component of the input signal in Hertz. This parameter affects the instrument behavior only when you set the Measurement Function parameter to AC Measurement. The driver sets the AG3446X_ATTR_AC_MIN_FREQ attribute to this value. 

Units: hertz

Valid Range:
3.0   to  20.0   coerced to  3.0
20.0   to  200.0   coerced to  20.0
200.0   to  300000.0   coerced to  200.0

Default Value: 20.0 

SCPI Command:
[SENSe:]CURRent:AC:BANDwidth {<filter>|MIN|MAX|DEF}
[SENSe:]VOLTage:AC:BANDwidth {<filter>|MIN|MAX|DEF}
    �    Pass the maximum expected frequency component of the input signal in Hertz. This parameter affects instrument behavior only when you set the Measurement Function parameter to AC Measurement. The driver sets the AG3446X_ATTR_AC_MAX_FREQ attribute to this value. 

Units: hertz

Valid Range:
3.0   to  300000.0   coerced to  300000.0

Default Value: 300000.0 

SCPI Command:
[SENSe:]CURRent:AC:BANDwidth {<filter>|MIN|MAX|DEF}
[SENSe:]VOLTage:AC:BANDwidth {<filter>|MIN|MAX|DEF}
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    t    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:        
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �{ = X �  �    AC Minimum Frequency (Hz)         �� =3 �  �    AC Maximum Frequency (Hz)         ��-   �  �    Instrument Handle                 �E#����  �    Status                             20.0    	300000.0        	           �    This function configures the frequency voltage range of the DMM for frequency and period measurements.

This function affects the behavior of the instrument only if the AG3446X_ATTR_FUNCTION attribute is set to AG3446X_VAL_FREQ or AG3446X_VAL_PERIOD.      �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    s    Pass the expected maximum value of the input signal for frequency and period measurements in volts RMS. The driver sets the AG3446X_ATTR_FREQ_VOLTAGE_RANGE attribute to this value.  

The driver reserves special negative values for the auto-range mode.

Defined Values:
AG3446X_VAL_AUTO_RANGE_ON  (-1.0) - Auto-range On
AG3446X_VAL_AUTO_RANGE_OFF (-2.0) - Auto-range Off
AG3446X_VAL_AUTO_RANGE_ONCE(-3.0) - Auto-range once
0.0   to  0.1    coerced to  0.1
0.1   to  1.0    coerced to  1.0
1.0   to  10.0   coerced to  10.0
10.0  to  100.0  coerced to  100.0
100.0 to  1000.0 coerced to  1000.0

Defined values for EDU34450A:
AG3446X_VAL_AUTO_RANGE_ON  (-1.0) - Auto-range On
AG3446X_VAL_AUTO_RANGE_OFF (-2.0) - Auto-range Off
1.0   to  10.0   coerced to  10.0
10.0  to  100.0  coerced to  100.0
100.0 to  750.0  coerced to  750.0


Default Value: 10.0 volts RMS

SCPI Command:
[SENSe:]{FREQuency|PERiod}:VOLTage:RANGe{<range>|MIN|MAX|DEF}
[SENSe:]{FREQuency|PERiod}:VOLTage:RANGe:AUTO{OFF|ON|ONCE}
[SENSe:]{FREQuency|PERiod}:VOLTage:RANGe:AUTO{OFF|ON} for EDU34450A.

Note: AG3446X_VAL_AUTO_RANGE_ONCE(-3.0) not supported for EDU34450A.
    ��-   �  �    Instrument Handle                 �v#����  �    Status                            �� H � �  �    Voltage Range (RMS)                    	           10.0    �    This function configures the frequency timeout of the DMM for frequency and period measurements.

Notes:
(1) This function applies only to the 34465A and the 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    W    Controls how long the instrument waits before timing out on a frequency or period measurement when no signal is present. The driver uses this value to set the AG3446X_ATTR_FREQ_AUTO_TIMEOUT_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]FREQuency:TIMeout:AUTO {OFF | ON}    ��-   �  �    Instrument Handle                 ��#����  �    Status                            �	 H � �  �    Enable Auto Timeout                    	           True VI_TRUE False VI_FALSE       This function configures the DMM to take temperature measurements from a specified transducer type. 

Notes:

(1) This function affects the behavior of the instrument only when the  AG3446X_ATTR_FUNCTION is set to AG3446X_VAL_TEMPERATURE.
(2) This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        Specifies the transducer probe type to use for temperature measurements of the DMM.  The driver uses this value to set the AG3446X_ATTR_TEMP_TRANSDUCER_TYPE attribute.

Valid Values:
AG3446X_VAL_THERMOCOUPLE - Thermocouple
AG3446X_VAL_2_WIRE_THER  -  2 Wire Thermistor
AG3446X_VAL_4_WIRE_THER  -  4 Wire Thermistor
AG3446X_VAL_2_WIRE_RTD   -  2 Wire RTD
AG3446X_VAL_4_WIRE_RTD   -  4 Wire RTD

Default Value: AG3446X_VAL_4_WIRE_RTD

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:TYPE {TCouple | THERmistor | FTHermistor | FRTD | RTD}

    �]-   �  �    Instrument Handle                 �#����  �    Status                            �� U � � �    Transducer Type                        	                     �Thermocouple AG3446X_VAL_THERMOCOUPLE 2 Wire Thermistor AG3446X_VAL_2_WIRE_THER 4 Wire Thermistor AG3446X_VAL_4_WIRE_THER 2 Wire RTD AG3446X_VAL_2_WIRE_RTD 4 Wire RTD AG3446X_VAL_4_WIRE_RTD   �    This function configures the alpha and resistance parameters for a resistance temperature device.

This function affects the behavior of the instrument only when the AG3446X_ATTR_TEMP_TRANSDUCER_TYPE attribute is set to AG3446X_VAL_2_WIRE_RTD or AG3446X_VAL_4_WIRE_RTD.

Notes:

(1) The driver assumes that you are using a Platinum Resistance Temperature Device.
(2) This function not supporte for EDU34450A.       �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    x    Pass the alpha parameter for a resistance temperature device. The driver sets the AG3446X_ATTR_TEMP_RTD_ALPHA attribute to this value.

Valid Values: 
This parameter supports only Type 85 RTDs (alpha = 0.00385) for RTD temperature measurements.

Default Value: 85

Notes:

(1) This parameter affects both 2-wire and 4-wire RTD measurements.

SCPI Command:
TEMP:TRAN:RTD:TYPE    �    Specifies the R0 parameter (resistance) for a resistance temperature device. The RTD resistance is also known as the RTD reference value. The driver sets the AG3446X_ATTR_TEMP_RTD_RES attribute to this value.

Valid Range: 80.0 to 120.0 ohms

Default Value: 100.0 ohms

Notes: 

(1) This attribute affects both 2-wire and 4-wire RTD measurements. 

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:{RTD|FRTD}:RESistance[:REFerence]
{<reference>|MIN|MAX|DEF}    ��-   �  �    Instrument Handle                 ċ#����  �    Status                            � = X �  �    Alpha                             ̈ =3 �  �    Resistance                             	           85    100.0    �    This function configures the offset compensation and power limit for a resistance temperature device.

Notes:
(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    Y    Enables or disables offset compensation for 2-wire and 4-wire RTD measurements. The driver uses this value to set the AG3446X_ATTR_TEMP_TRANSDUCER_OFFSET_COMPENSATE_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:{FRTD|RTD}:OCOMpensated {ON|1|OFF|0}    L    Enables or disables low-power, 2-wire or 4-wire, RTD measurements. The driver uses this value to set the AG3446X_ATTR_TEMP_TRANSDUCER_POWER_LIMIT_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:{FRTD|RTD}:POWer:LIMit[:STATe] {ON|1|OFF|0}    ��-   �  �    Instrument Handle                 в#����  �    Status                            �/ >w �  �    Enable Offset Compensation        ؐ > } �  �    Enable Power Limit                     	           True VI_TRUE False VI_FALSE    True VI_TRUE False VI_FALSE   	    This function configures the resistance for a thermistor temperature measurement device.

This function affects the behavior of the instrument only when the AG3446X_ATTR_TEMP_TRANSDUCER_TYPE attribute is set to AG3446X_VAL_2_WIRE_THER or AG3446X_VAL_4_WIRE_THER.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    )    Pass the resistance of the thermistor in Ohms. The driver sets the AG3446X_ATTR_TEMP_THERMISTOR_RES attribute to this value. 

Valid Range: 5000.0 ohms (Only available choice)

Default Value: 5000 ohms

Notes:

(1) The driver assumes that you are using an interchangeable thermistor. Interchangeable thermistors are thermistors that exhibit similar behavior for a given resistance value.

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:{THERmistor|FTHermistor}:TYPE 5000

For EDU34450A:
SCPI Command:
[SENSe:]TEMPerature:TRANsducer:THERmistor:TYPE 5000
    �-   �  �    Instrument Handle                 ��#����  �    Status                            �M H � �  �    Resistance                             	           5000    �    This function configures the thermocouple type and the reference junction type of the thermocouple for
DMMs that take temperature measurements using a thermocouple transducer type.

Notes:
(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Selects the thermocouple type for thermocouple measurements. The driver uses this value to set the AG3446X_ATTR_TEMP_TC_TYPE attribute.

Valid Values:
AG3446X_VAL_TEMP_TC_E - Thermocouple E
AG3446X_VAL_TEMP_TC_J - Thermocouple J
AG3446X_VAL_TEMP_TC_K - Thermocouple K
AG3446X_VAL_TEMP_TC_N - Thermocouple N
AG3446X_VAL_TEMP_TC_R - Thermocouple R
AG3446X_VAL_TEMP_TC_T - Thermocouple T

Default Value: AG3446X_VAL_TEMP_TC_E

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:TCouple:TYPE {E|J|K|N|R|T}    <    Thermocouple measurements require a reference junction temperature. For the reference junction temperature, you can use an internal measurement, or a known fixed junction temperature.  The driver uses this value to set the AG3446X_ATTR_TEMP_TC_REF_JUNC_TYPE attribute.

Valid Values:
AG3446X_VAL_TEMP_REF_JUNC_INTERNAL - Thermocouple Reference Junction Internal
AG3446X_VAL_TEMP_REF_JUNC_FIXED - Thermocouple Reference Junction Fixed

Default Value: AG3446X_VAL_TEMP_REF_JUNC_INTERNAL

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:TCouple:RJUNction:TYPE {INTernal|FIXed}    �4-   �  �    Instrument Handle                 ��#����  �    Status                            �j >  � �    Thermocouple Type                 �c > � �    Reference Junction Type                	                      �Thermocouple E AG3446X_VAL_TEMP_TC_E Thermocouple J AG3446X_VAL_TEMP_TC_J Thermocouple K AG3446X_VAL_TEMP_TC_K Thermocouple N AG3446X_VAL_TEMP_TC_N Thermocouple R AG3446X_VAL_TEMP_TC_R Thermocouple T AG3446X_VAL_TEMP_TC_T               �Thermocouple Reference Junction Internal AG3446X_VAL_TEMP_REF_JUNC_INTERNAL Thermocouple Reference Junction Fixed AG3446X_VAL_TEMP_REF_JUNC_FIXED    �    This function configures the fixed reference junction for a thermocouple with a fixed reference junction type.

Notes:
(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    T    Sets the fixed reference junction temperature in degrees Celsius for thermocouple measurements. The driver uses this value to set the AG3446X_ATTR_TEMP_TC_FIXED_REF_JUNC attribute.

Valid Range:
-20 to 80 centigrade

Default Value:
0 centigrade

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:TCouple:RJUNction [{<temperature>|MIN|MAX|DEF}]    ��-   �  �    Instrument Handle                 ��#����  �    Status                            � > � �  �    Fixed Reference Junction               	           0    �    This function disables or enables the thermocouple check feature to verify that your thermocouples are properly connected for measurements. 

Notes:
(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    1    Disables or enables the thermocouple check feature to verify that your thermocouples are properly connected for measurements. When enabled, the instrument measures the resistance after each thermocouple measurement to ensure a proper connection. If an open connection is detected, the instrument reports an overload condition. The driver uses this value to set the AG3446X_ATTR_TEMP_TC_CHECK_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:TCouple:CHECk {ON|1|OFF|0}    ��-   �  �    Instrument Handle                 �#����  �    Status                           % > �  �    Enable Thermocouple Check              	           True VI_TRUE False VI_FALSE   "    This function allows you to make minor temperature adjustments to correct for the differences between the DMM internal temperature measurement of the front connection and the actual temperature of the measurement terminals.

Notes:
(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Allows you to make minor temperature adjustments to correct for the differences between the DMM internal temperature measurement of the front connection and the actual temperature of the measurement terminals. The driver uses this value to set the AG3446X_ATTR_TEMP_TC_REF_JUNC_OFFS_ADJ attribute.

Valid Range:
-20 to 20 centigrade

Default Value: 0 centigrade

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:TCouple:RJUNction:OFFSet:ADJust {<temperature>|MIN|MAX|DEF}   V-   �  �    Instrument Handle                #����  �    Status                           � > � �  �    Adjustment                             	           0    �    This function enables or disables low-power thermistor measurements (either 2-wire or 4-wire).

Notes:
(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    d    Enables or disables low-power thermistor measurements (either 2- or 4-wire). The driver uses this value to set the AG3446X_ATTR_TEMP_THERMISTOR_POWER_LIMIT_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]TEMPerature:TRANsducer:{FTHermistor|THERmistor}:POWer:LIMit[:STATe] {ON|1|OFF|0}   �-   �  �    Instrument Handle                ~#����  �    Status                           � > � �  �    Enable Power Limit                     	           True VI_TRUE False VI_FALSE    ~    This function configures the common DMM trigger attributes.  These attributes include the trigger source and trigger delay.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    l    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    ;    Specify the trigger source you want to use.  The driver sets the
AG3446X_ATTR_TRIGGER_SOURCE attribute to this value.

After you call either the ag3446x_Read or the ag3446x_Initiate function, the DMM waits for the trigger you specify in this parameter. After it receives the trigger, the DMM waits the length of time you specify in the Trigger Delay parameter.  The DMM then takes a measurement.

Valid Values:
AG3446X_VAL_IMMEDIATE     - Immediate. The DMM does not wait
for a trigger of any kind.
AG3446X_VAL_EXTERNAL      - External. The DMM waits for a
trigger on the external trigger input.
AG3446X_VAL_SOFTWARE_TRIG - BUS. The DMM waits until you call the ag3446x_SendSoftwareTrigger function.
AG3446X_VAL_INTERNAL      - Internal. Provides level triggering capability.

Default Value: AG3446X_VAL_IMMEDIATE

Notes:
(1) AG3446X_VAL_INTERNAL applies only to the 34465A and 34470A with DIG option.
(2) AG3446X_VAL_INTERNAL and AG3446X_VAL_EXTERNAL not supported for EDU34450A.

SCPI Command:
TRIGger:SOURce {IMMediate|EXTernal|BUS}
TRIGger:SOURce {IMMediate||BUS} for EDU34450A    {    Pass the value you want to use for the trigger delay.  Express this value in seconds.  The driver sets the AG3446X_ATTR_TRIGGER_DELAY attribute to this value. 

The trigger delay specifies the length of time the DMM waits after it receives the trigger and before it takes a measurement.

Use positive values to set the trigger delay in seconds.  The driver reserves negative values for configuring the DMM to calculate the trigger delay automatically.

Defined Constant Values:
AG3446X_VAL_AUTO_DELAY_OFF (-2.0)- Auto-delay off
AG3446X_VAL_AUTO_DELAY_ON (-1.0) - Auto-delay on

Valid Manual Range:  0.0 to 3600.0 (seconds)
 
Default Value: 0.0 (seconds)

Notes:

(1) Setting this parameter to AG3446X_VAL_AUTO_DELAY_ON (-1.0) configures the DMM to calculate the trigger delay before each measurement.

(2) Setting this parameter to AG3446X_VAL_AUTO_DELAY_OFF (-2.0) stops the DMM from calculating the trigger delay and sets the trigger delay to the last automatically calculated value.

(3) AG3446X_VAL_AUTO_DELAY_ON, AG3446X_VAL_AUTO_DELAY_OFF parameters not supported for EDU34450A model.

SCPI Command:
TRIGger:DELay {<seconds>|MIN|MAX|DEF}

   �-   �  �    Instrument Handle                 t#����  �    Status                           &� = l � �    Trigger Source                   ++ =. �  �    Trigger Delay (sec)                    	                      �Immediate AG3446X_VAL_IMMEDIATE External AG3446X_VAL_EXTERNAL Software Trigger Function AG3446X_VAL_SOFTWARE_TRIG Internal AG3446X_VAL_INTERNAL    0.0    R    This function configures the polarity of the external trigger source of the DMM.    z    Pass the polarity of the external trigger slope. The driver sets the AG3446X_ATTR_TRIGGER_SLOPE attribute to this value. The DMM triggers on either the rising or the falling edge of the external trigger source depending on the value of this attribute. The driver uses this value to set the AG3446X_ATTR_TRIGGER_SLOPE attribute.

Valid Values:
AG3446X_VAL_POSITIVE   -  Positive. The driver triggers on the rising edge of the external trigger.
AG3446X_VAL_NEGATIVE   -  Negative. The driver triggers on the falling edge of the external trigger.

Default Value: AG3446X_VAL_NEGATIVE

SCPI Command:
TRIGger:SLOPe {POSitive|NEGative}


     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

   1� N � � �    Trigger Slope                    4-   �  �    Instrument Handle                4�#����  �    Status                                       <Positive AG3446X_VAL_POSITIVE Negative AG3446X_VAL_NEGATIVE        	           �    This function configures the level on which a trigger occurs when level triggering is enabled. 

Notes:
(1) This function applies only to the 34465A, 34470A and requires the DIG option.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    l    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Sets the level on which a trigger occurs when level triggering is enabled.

Valid Range:
For different measurement function and range/input terminals:
DCV; 100 mV to 100 V ranges, fixed range: +/-120% of range
DCV; 1000 V range, fixed range: +/-1000 V
DCV; Auto range: +/-1000 V
DCI; 3 A terminals, fixed range: +/-120% of range
DCI; 3 A terminals, Autorange: +/-3.6 A
DCI, 10 A terminals: +/-12 A
RESistance/FRESistance; All ranges, fixed range: 0 to +120% of range
RESistance/FRESistance; Autorange: 0 to +1.2 GOhm
ACV; 100 mV to 100 V ranges, fixed range: 0 to +120% of range
ACV; 750 V range, fixed range: 0 to +1000 V
ACV; Autorange: 0 to +1000 V
ACI; 3 A terminals, fixed range: 0 to +120% of range
ACI; 3 A terminals, Autorange: 0 to +3.6 A
ACI; 10 A terminals: 0 to +12 A
Frequency: 3 Hz to 300 kHz
Period: 3.33333333 us to 0.333333333 s

Default Value: 0

SCPI Commands:
TRIGger:LEVel {<level>|MIN|MAX|DEF}
TRIGger:LEVel? [{MIN|MAX|DEF}]   =-   �  �    Instrument Handle                =�#����  �    Status                           D3 = � �  �    Trigger Level                          	           0.0    �    This function configures the attributes for multi-point measurements.  These attributes include the trigger count, sample count, sample trigger and sample interval.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    Q    Pass the number of triggers you want the DMM to receive before returning to the Idle state.  The driver sets the AG3446X_ATTR_TRIGGER_COUNT attribute to this value.

Valid Range(EDU34450A):
1 to 5000

Valid Range(34460A,34461A,34465A,34470A):
1 to 1000000


Default Value: 1

SCPI Command:
TRIGger:COUNt {<count>|MIN|MAX|DEF|INFinity}
    Y    Pass the number of measurements you want the DMM to take each time it receives a trigger.  The driver sets the AG3446X_ATTR_SAMPLE_COUNT attribute to this value. 

Valid Range:
1 to 1000000 for 34460A and 34461A
1 to 1000000000 for 34465A and 34470A
1 to 5000 for EDU34450A

Default Value: 1

SCPI Command: 
SAMPle:COUNt {<count>|MIN|MAX|DEF}
    �    Determines sample timing, when the sample count is greater than one. The driver uses this value to set the AG3446X_ATTR_SAMPLE_TRIGGER attribute.

Valid Values:
AG3446X_VAL_IMMEDIATE - Immediate, The first sample starts one trigger delay time after the trigger, and then the trigger delay time is inserted between the first and second samples, the second and third, and so on.
AG3446X_VAL_TIMER - Timer, The first sample starts one trigger delay time after the trigger. However, the second sample starts one sample interval after the start of the first sample, and so on.

Default Value: AG3446X_VAL_IMMEDIATE

Notes:
(1) This control is valid only when the instrument model is 34465A or 34470A.

SCPI Command:
SAMPle:SOURce {IMMediate|TIMer}    �    Sets a sample interval for timed sampling when the sample count is greater than one.

The first sample is taken one trigger delay time after the trigger. The second sample starts one sample interval after the start of the first sample, and so forth. Note that the sample timing is determinant because the start of each sample is determined by the sample interval. Integration and auto-ranging affect the sampling time for each sample, but not the sample interval as long as the sample interval is longer than the sampling time. Periodic sampling continues until the sample count is satisfied.

The driver uses this value to set the AG3446X_ATTR_SAMPLE_INTERVAL attribute.

Valid Values(34465A,34470A):
0 to 3600 seconds (1 us steps)

Valid values(EDU34450A):
0.01 to 3600 seconds (100 us steps)

Default Value: 1

Notes:
(1) This control is valid only when the instrument model is 34465A, 34470A and EDU34450A.

SCPI Command:
SAMPle:TIMer {<interval>|MIN|MAX|DEF}
   IS-   �  �    Instrument Handle                J#����  �    Status                           P� = l �  �    Trigger Count                    Q� =. �  �    Sample Count                     SB z l � �    Sample Trigger                   V2 z. �  �    Sample Interval                        	           1    1               8Immediate AG3446X_VAL_IMMEDIATE Timer AG3446X_VAL_TIMER    1.0    r    This instrument does not support the measurement-complete signal. This function exist only for class compliance.     �    Returns the ViSession handle that you obtain from the hp34401a_init or hp34401a_InitWithOptions functions. The handle identifies a particular instrument session.

Default Value:  None    �    Returns the status code of the operation. The status code either indicates success or describes an error or warning condition. Examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the hp34401a_error_message function.  To obtain additional information about the error condition, call the hp34401a_GetError function. To clear the error information from the driver, call the hp34401a_ClearError function.
          
The following table describes the general meaning of the status code:

 -------------------------------------
 |       Value         |   Meaning   |
 -------------------------------------
 |          0          |   Success   |
 |   Positive Values   |   Warnings  |
 |   Negative Values   |    Errors   |
 -------------------------------------


The instrument driver can return errors and warnings that other sources define. The following table defines the ranges of additional status codes that this driver can return. The table lists the different include files that contain the defined constants for the particular status codes:

 ---------------------------------------------------------------
 |  Numeric Range (in Hex)  |  Status Code  |      Types       |
 ---------------------------------------------------------------
 |   3FFA2000 to 3FFA3FFF   |    IviDmm     |     Warnings     |
 |   3FFA0000 to 3FFA1FFF   |     IVI       |     Warnings     |
 |   3FFF0000 to 3FFFFFFF   |     VISA      |     Warnings     |
 |   3FFC0000 to 3FFCFFFF   |    VXIPnP     |  Driver Warnings |
 |   BFFA2000 to BFFA3FFF   |    IviDmm     |      Errors      |
 |   BFFA0000 to BFFA1FFF   |     IVI       |      Errors      |
 |   BFFF0000 to BFFFFFFF   |     VISA      |      Errors      |
 |   BFFC0000 to BFFCFFFF   |    VXIPnP     |   Driver Errors  |
 ---------------------------------------------------------------     �    This instrument does not support the measurement-complete signal. This function exist only for class compliance.

Valid Values:
AG3446X_VAL_EXTERNAL

Default Value: AG3446X_VAL_EXTERNAL   \ -   �  �    Instrument Handle                \�#����  �    Status                           dz < � � �    Meas Complete Destination              	                      External AG3446X_VAL_EXTERNAL    }    This function configures the number of pretrigger samples.

Notes:
(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Allows collection of the data being digitized before the trigger. Reserves memory for pretrigger samples up to the specified number of pretrigger samples.

For example, with a sample count of 50,000, and a pretrigger sample count of 20,000, up to 20,000 samples are taken before the trigger, then 30,000 samples are taken after the trigger occurs.
The sample count and pretrigger count do not affect when the trigger occurs. If the memory allocated for pretrigger samples fills up, the oldest readings are discarded. In the example above, the 20,000 most recent pretrigger samples are saved, even if more than 20,000 samples occur before the trigger. If the trigger occurs before the pretrigger count is satisfied, only the actual pretrigger samples taken are saved.
In all cases, after the trigger is received, only sample count minus specified pretrigger count readings are taken. In this example, if the trigger occurs after 5 pretrigger samples have been taken (instead of the specified 20,000), only 30,000 post-trigger samples are taken. This is because memory was reserved for 20,000 pretrigger samples.

The driver uses this value to set the AG3446X_ATTR_SAMPLE_COUNT_PRE_TRIGGER attribute.

Valid Range:
0 to 1999999

Default Value: 0

Notes:
(1) Pretrigger applies to all measurement functions except Continuity and Diode test.
(2) After setting the sample count and pretrigger sample count, you must place the DMM in the "waitfor-trigger" state.
(3) The pretrigger sample count must be less than the sample count.
(4) If any of the calculation functions are on, the pretrigger count is limited to 10,000 samples.

SCPI Command:
SAMPle:COUNt:PRETrigger {<count>|MIN|MAX|DEF}   f�-   �  �    Instrument Handle                gV#����  �    Status                           m� = � �  �    Pretrigger Sample Count                	           0   ^    Performs a calibration using the calibration value based on the function and range.

Notes:

(1) A short must be applied for the resistance and voltage measurement functions, and the inputs must be open for the current measurement functions.
(2) You must unsecure the instrument to calibrate it or to change the calibration string or security code.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     �    Specifies the value of the applied calibration signal. The driver uses this value to set the AG3446X_ATTR_CAL_VALUE attribute.

Default Value: 0.0

SCPI Command:
CALibration:VALue<value>    �    Stores a message in calibration memory. Common messages include the last calibration date, calibration due date, or calibration department contact information. You can perform this query regardless of whether the instrument is secured. The driver uses this value to set the AG3446X_ATTR_CAL_STRING attribute.

Default Value:
"" 

Notes:

(1) You must unsecure the instrument to calibrate it or to change the calibration string or security code.
(2) This string may be stored only from the remote interface, but you can read the message from the front-panel or remote interface.
(3) Storing a calibration message overwrites the previous message, and this setting is non-volatile.

SCPI Command:
CALibration:STRing"<string>"     �    Enables or disables store calibration constants in volatile memory and places them in nonvolatile memory.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
CALibration:STORe     t    Returns the result of calibration.

Valid Range:
VI_TRUE  - Pass
VI_FALSE - Fail

SCPI Command:
CALibration[:ALL]?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   v�-   �  �    Instrument Handle                wB -  �  �    Calibration Value                x - � �  �    Calibration Message              z� -� �  �    Enable Calibration Store         {� �  �  �    Calibration Result               |?#����  �    Status                                 0.0    ""    True VI_TRUE False VI_FALSE    	            	            �    Performs a low-level calibration of the ADC (analog-to-digital converter) circuitry.

Notes:

(1) You must unsecure the instrument to calibrate it or to change the calibration string or security code.
(2) This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     �    Returns the calibration result of the ADC circuitry.

Valid Range:
VI_TRUE  - Successful
VI_FALSE - Unsuccessful

SCPI Command:
CALibration:ADC?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �8-   �  �    Instrument Handle                �� - � �  �    Calibration Result               ��#����  �    Status                                 	            	            6    This function configures the calibration security.

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    |    Sets the security code to prevent unauthorized calibrations.

Valid Range:
Unquoted string up to 12 characters, must start with letter (A-Z). May contain letters, numbers (0-9) and underscores.

Default Value: 
""

Notes:

(1) You must unsecure the instrument to calibrate it or to change the calibration string or security code.

SCPI Command:
CALibration:SECure:CODE<new_code>        Unsecures or secures the instrument for calibration. The driver uses this value to set the AG3446X_ATTR_SECURITY_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_TRUE

Notes:

(1) You must unsecure the instrument to calibrate it or to change the calibration string or security code.
(2) Front panel and remote interface calibration share the same code.
(3) This setting is non-volatile; it will not be changed by power cycling or reset.

SCPI Command:
CALibration:SECure:STATe{ON|1|OFF|0}[, <code>]    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ��-   �  �    Instrument Handle                �� -  �  �    Security Code                    �/ -� �  �    Enable Security                  �T#����  �    Status                                 ""   True VI_TRUE False VI_FALSE    	                This function transfers files into and out of the instrument's mass memory.

Note: This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Configures data transition settings. The driver uses this value to set the AG3446X_ATTR_MEM_DATA_OPER attribute.

Valid Values:
AG3446X_VAL_MEM_DATA_OPER_DOWNLOAD   -  Download Data
AG3446X_VAL_MEM_DATA_OPER_STORE   -  Store Data
AG3446X_VAL_MEM_DATA_OPER_UPLOAD   -  Upload Data

Default Value: AG3446X_VAL_MEM_DATA_OPER_DOWNLOAD

SCPI Command:
MMEMory:DOWNload:FNAMe <filename> 
MMEMory:STORe:DATA RDG_STORE, <file>     �    Specifies the file name to be configured.

Default Value:
""

SCPI Command:
MMEMory:DOWNload:FNAMe <filename> 
MMEMory:STORe:DATA RDG_STORE, <file>     i    Specifies the binary block data.

Default Value:
""

SCPI Command:
MMEMory:DOWNload:DATA <binary_block>    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �V-   �  �    Instrument Handle                � -  � �    Operation                        �� - � �  �    File Name                        �U -� �  �    Binary Block                     ��#����  �    Status                                            �Download Data AG3446X_VAL_MEM_DATA_OPER_DOWNLOAD Store Data AG3446X_VAL_MEM_DATA_OPER_STORE Upload Data AG3446X_VAL_MEM_DATA_OPER_UPLOAD    ""    ""    	            \    This function configures folder settings.

Note: This function not supported in EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Specifies the operation to perform to the folder settings. The driver uses this value to set the AG3446X_ATTR_MEM_DIR_OPER attribute.

Valid Values:
AG3446X_VAL_MEM_DIR_OPER_SELECT   -  Select Folder
AG3446X_VAL_MEM_DIR_OPER_MAKE   -  Make New Folder
AG3446X_VAL_MEM_DIR_OPER_REMOVE   -  Remove Folder

Default Value: AG3446X_VAL_MEM_DIR_OPER_SELECT

SCPI Command:
MMEMory:CDIRectory <folder> 
MMEMory:MDIRectory <folder> 
MMEMory:RDIRectory <folder>     �    Specifies the folder name to be configured.

Default Value:
""

SCPI Command:
MMEMory:CDIRectory <folder> 
MMEMory:MDIRectory <folder> 
MMEMory:RDIRectory <folder>    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �Y-   �  �    Instrument Handle                � -  � �    Operation                        �� -� �  �    Folder                           ��#����  �    Status                                            �Select Folder AG3446X_VAL_MEM_DIR_OPER_SELECT Make New Folder AG3446X_VAL_MEM_DIR_OPER_MAKE Remove Folder AG3446X_VAL_MEM_DIR_OPER_REMOVE    ""    	            t    This function configures the files copy, delete and move actions.

Note: This function not supported in EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    X    Specifies the operation to perform actions. The driver uses this value to set the AG3446X_ATTR_MEM_FILE_OPER attribute.

Valid Values:
AG3446X_VAL_MEM_FILE_OPER_COPY   -  Copy File. Copies <Source File> to <Destination File>. Each file name must include the file extension.
AG3446X_VAL_MEM_FILE_OPER_MOVE   -  Move File. Moves and/or renames <Source File> to <Destination File>. Each file name must include the file extension.
AG3446X_VAL_MEM_FILE_OPER_DELETE   -  Delete File. Deletes a file.

Default Value: AG3446X_VAL_MEM_FILE_OPER_COPY

SCPI Command:
MMEMory:COPY 
MMEMory:DELete 
MMEMory:MOVE     �    Specifies the source file to be configured. It also specifies the file name to be deleted.

Default Value:
""

Notes:

(1) The source file must exist and cannot be marked as hidden or system.

SCPI Command:
MMEMory:COPY 
MMEMory:DELete 
MMEMory:MOVE     �    Specifies the destination file to be configured.

Default Value:
""

Notes:

(1) The destination folder must exist and cannot be marked as hidden or system.

SCPI Command:
MMEMory:COPY 
MMEMory:MOVE    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ��-   �  �    Instrument Handle                �� -  � �    Operation                        � - � �  �    Source File                      � -� �  �    Destination File                 ��#����  �    Status                                            Copy File AG3446X_VAL_MEM_FILE_OPER_COPY Move File AG3446X_VAL_MEM_FILE_OPER_MOVE Delete File AG3446X_VAL_MEM_FILE_OPER_DELETE    ""    ""    	            �    This function save and load preferred settings for nonvolatile parameters (preference files).

Note: This function not supported in EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Specifies the operation to perform to the preference file. The driver uses this value to set the AG3446X_ATTR_MEM_PREF_FILE_OPER attribute.

Valid Values:
AG3446X_VAL_MEM_PREF_FILE_OPER_LOAD   -  Load Preference File
AG3446X_VAL_MEM_PREF_FILE_OPER_STORE   -  Store Preference File

Default Value: AG3446X_VAL_MEM_PREF_FILE_OPER_LOAD

Notes:

(1) When loading a preferences file that specifies a static IP address, be careful that this does not result in two instruments with the same IP address on your LAN. This could cause LAN configuration errors on both instruments.

SCPI Command:
MMEMory:LOAD:PREFerences <file>
MMEMory:STORe:PREFerences <file>     �    Specifies the file name to be configured.

Default Value:
""

SCPI Command:
MMEMory:LOAD:PREFerences <file>
MMEMory:STORe:PREFerences <file>    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ��-   �  �    Instrument Handle                �X -  � �    Operation                        �� -� �  �    File Name                        Â#����  �    Status                                            tLoad Preference File AG3446X_VAL_MEM_PREF_FILE_OPER_LOAD Store Preference File AG3446X_VAL_MEM_PREF_FILE_OPER_STORE    ""    	            >    This function save and load instrument states (state files).     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Specifies the operation to perform to the state file. The driver uses this value to set the AG3446X_ATTR_MEM_STATE_FILE_OPER attribute.

Valid Values:
AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD   -  Load State File
AG3446X_VAL_MEM_STATE_FILE_OPER_STORE   -  Store State File
AG3446X_VAL_MEM_STATE_FILE_OPER_RECALL   -  Recall State File

Default Value: AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD

SCPI Command:
MMEMory:LOAD:STATe <filename> 
MMEMory:STORe:STATe <filename> 
MMEMory:STATe:RECall:SELect <file>     �    Specifies the file name to be configured.

Default Value:
""

SCPI Command:
MMEMory:LOAD:STATe <filename> 
MMEMory:STORe:STATe <filename> 
MMEMory:STATe:RECall:SELect <file>    0    Disables or enables the automatic recall of a specific stored instrument state at power-on. The driver uses this value to set the AG3446X_ATTR_AUTO_RECALL_ENABLE attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_TRUE

SCPI Command:
MMEMory:STATe:RECall:AUTO {ON|1|OFF|0}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ˧-   �  �    Instrument Handle                �^ -  � �    Operation                        �X - � �  �    File Name                        � -� �  �    Enable Auto Recall               �G#����  �    Status                                            �Load State File AG3446X_VAL_MEM_STATE_FILE_OPER_LOAD Store State File AG3446X_VAL_MEM_STATE_FILE_OPER_STORE Recall State File AG3446X_VAL_MEM_STATE_FILE_OPER_RECALL    ""   True VI_TRUE False VI_FALSE    	            �    This function sets the number of measurements to store in reading memory before setting bit 9 in the Standard Operation Register group event register to 1.

Note: This function not supported in EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None        Sets the number of measurements to store in reading memory. The driver uses this value to set the AG3446X_ATTR_DATA_POINT_COUNT attribute.

Valid Range:
34460A: 1 to 1,000 readings
34461A: 1 to 10,000 readings 

Default Value: 1

SCPI Command:
DATA:POINts:EVENt:THReshold<count>    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ف-   �  �    Instrument Handle                �8 - � �  �    Measurement Counts               �X#����  �    Status                                 1    	            r    This function returns a list of files in the specified folder.

Note: This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     B    Specifies the used memory.

SCPI Command:
MMEMory:CATalog[:ALL]?     G    Specifies the free memory size.

SCPI Command:
MMEMory:CATalog[:ALL]?    �    Returns the file list in the format "<file_name>, <file_type>, <file_size>", (including the quotation marks), where <file_name> is the name of the file including file extension, if any; <file_type> is either STAT for STATe (.sta) files, ASC for DATA (.csv) files, PREF for PREFerence (.prf) files, FOLD for folders, or null for all other file extensions; <file_size> is the file size in bytes.

SCPI Command:
MMEMory:CATalog[:ALL]?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ��-   �  �    Instrument Handle                � -  �  �    Memory Used                      �� - � �  �    Memory Free                      �H -� �  �    File Listing                     �#����  �    Status                                 	            	            	            	            �    This function checks whether the specified state file exists and contains a valid state file.

Note: This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     Y    Specifies the state file.

Default Value:
""

SCPI Command:
MMEMory:STATe:VALid? <file>     �    Specifies whether the specified state file exists and contains a valid state file.

Valid Values:
VI_TRUE: If valid.
VI_FALSE: If not valid.

SCPI Command:
MMEMory:STATe:VALid? <file>    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �I-   �  �    Instrument Handle                �  -  �  �    State File                       �a -� �  �    Is Valid                         �"#����  �    Status                                 ""    	            	            x    This function configures the data transition format.

Notes:

(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Specifies the character used to separate the columns in stored data. The driver uses this value to set the AG3446X_ATTR_MEM_FORM_READING_SEPARATOR attribute.

Valid Values:
AG3446X_VAL_SEPARATOR_COM - Comma
AG3446X_VAL_SEPARATOR_SEM - Semicolon
AG3446X_VAL_SEPARATOR_TAB - Tab

Default Value: _VAL_SEPARATOR_COM

SCPI Command:
MMEMory:FORMat:READing:CSEParator  {COMMa|SEMicolon|TAB}    Z    When enabled, limits the maximum number rows per stored .csv data file to one million, including any header row, if enabled.
The driver uses this value to set the AG3446X_ATTR_MEM_FORM_ROW_LIMIT_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_TRUE

SCPI Command:
MMEMory:FORMat:READing:RLIMit {OFF | ON}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors    .    Disables/enables header information and reading numbers in stored data. The driver uses this value to set the AG3446X_ATTR_MEM_FORM_READING_INFO_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
MMEMory:FORMat:READing:INFormation {OFF | ON}   �
-   �  �    Instrument Handle                �� -  � �    Separator                        �J -� �  �    Enable Row Limit                 ��#����  �    Status                            -  �  �    Enable Reading Info                               bComma AG3446X_VAL_SEPARATOR_COM Semicolon AG3446X_VAL_SEPARATOR_SEM Tab AG3446X_VAL_SEPARATOR_TAB   True VI_TRUE False VI_FALSE    	            True VI_TRUE False VI_FALSE    k    This function configures the auto zero mode of the DMM.

Note: This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    &    Specify the auto-zero mode. The driver sets the AG3446X_ATTR_AUTO_ZERO attribute to this value.

When the auto-zero mode is enabled, the DMM internally disconnects the input signal and takes a Zero Reading. The DMM then subtracts the Zero Reading from the measurement. This prevents offset voltages present in the instrument's input circuitry from affecting measurement accuracy.

Valid Values:
AG3446X_VAL_AUTO_ZERO_ON   -  Auto Zero On. Configures the DMM to take a Zero Reading for each measurement. The DMM subtracts the Zero Reading from the value it measures.
AG3446X_VAL_AUTO_ZERO_OFF   -  Auto Zero Off. Disables the auto-zero feature.
AG3446X_VAL_AUTO_ZERO_ONCE   -  Auto Zero Once. Configures the DMM to take a Zero Reading immediately. The DMM then subtracts this Zero Reading from all subsequent values it measures.

Default Value: AG3446X_VAL_AUTO_ZERO_ON

SCPI Command:
[SENSe:]CURRent[:DC]:ZERO:AUTO {OFF|ON|ONCE}
[SENSe:]RESistance:ZERO:AUTO {OFF|ON|ONCE}
[SENSe:]TEMPerature:ZERO:AUTO {OFF|ON|ONCE}
[SENSe:]VOLTage[:DC]:ZERO:AUTO {OFF|ON|ONCE}   �-   �  �    Instrument Handle                G#����  �    Status                           � H � � �    Auto Zero Mode                         	                      ZOn AG3446X_VAL_AUTO_ZERO_ON Off AG3446X_VAL_AUTO_ZERO_OFF Once AG3446X_VAL_AUTO_ZERO_ONCE    =    This function enables or disables statistics computation.

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    n    Enables or disables statistics computation. The driver uses this value to set the AG3446X_ATTR_AVER_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
CALCulate:AVERage[:STATe]{ON|1|OFF|0}

SCPI Command supported for EDU34450A:
CALCulate[:STATe] <mode>
CALCulate:FUNCtion NULL|DB|DBM|LIMit|AVERage|HOLD

    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   O-   �  �    Instrument Handle                 - �  �    Enable Average                   |#����  �    Status                                 True VI_TRUE False VI_FALSE    	            �    This function configures the settings of limit test.

Note: For EDU34450A first set the limit math function (CALC:FUNC LIM) and turn on math operations (CALC:STAT ON) before setting a limit value.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    /    Sets the lower limit. The driver uses this value to set the AG3446X_ATTR_LOWER_LIMIT attribute.

Valid Range:
-1.0E+15   to  -1.0E-15
0
+1.0E-15   to  +1.0E+15
-120% to +120%

Default Value: 0.0

Notes:

(1) Do not set the lower limit above the upper limit, even if you are using only one limit.
(2) For EDU34450A first set the limit math function (CALC:FUNC LIM) and turn on math operations (CALC:STAT ON) before setting a limit value. 


SCPI Command:
CALCulate:LIMit:LOWer[:DATA]{<value>|MIN|MAX|DEF}
CALCulate:LIMit:LOWer <value>|MIN|MAX for EDU34450A.
    >    Sets the upper limit. The driver uses this value to set the AG3446X_ATTR_UPPER_LIMIT attribute.

Valid Range:
-1.0E+15   to  -1.0E-15
0
+1.0E-15   to  +1.0E+15

-120% to +120% for EDU34450A

Default Value: 0.0

Notes:

(1) Do not set the lower limit above the upper limit, even if you are using only one limit.
(2) For EDU34450A first set the limit math function (CALC:FUNC LIM) and turn on math operations (CALC:STAT ON) before setting a limit value. 


SCPI Command:
CALCulate:LIMit:UPPer[:DATA]{<value>|MIN|MAX|DEF}
CALCulate:LIMit:UPPer <value>|MIN|MAX for EDU34450A.
     �    Enables or disables limit testing. The driver uses this value to set the AG3446X_ATTR_LIMIT_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
CALCulate:LIMit[:STATe]{ON|1|OFF|0}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �-   �  �    Instrument Handle                A -  �  �    Lower Limit                      x - � �  �    Upper Limit                      !� -� �  �    Enable Limit                     "�#����  �    Status                                 0.0    0.0    True VI_TRUE False VI_FALSE    	            u    This function configures the scaling settings.

Notes:

(1) This function applies only to ACV and DCV measurements.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    N    Stores a relative value in the multimeter's dB Relative Register. When the dB function is enabled, this value will be subtracted from the each voltage measurement after the measurement is converted to dBm. The driver uses this value to set the AG3446X_ATTR_SCALE_DB_REFERENCE attribute.

Units: dBm

Valid Range:
-200.0   to  200.0
-120.0   to  120.0 for EDU34450A

Default Value: 0

Notes:

(1) Specifying a reference value disables automatic reference selection.

SCPI Command:
CALCulate:SCALe:DB:REFerence{<reference>|MIN|MAX|DEF}
CALCulate:DB:REFerence <value>|MIN|MAX (for EDU34450A)        Selects the reference resistance for converting voltage measurements to dBm. This reference value affects both the dBm and dB scaling functions. The driver uses this value to set the AG3446X_ATTR_SCALE_DBM_REFERENCE attribute.

Valid Values:
AG3446X_VAL_50   -  50
AG3446X_VAL_75   -  75
AG3446X_VAL_93   -  93
AG3446X_VAL_110   -  110
AG3446X_VAL_124   -  124
AG3446X_VAL_125   -  125
AG3446X_VAL_135   -  135
AG3446X_VAL_150   -  150
AG3446X_VAL_250   -  250
AG3446X_VAL_300   -  300
AG3446X_VAL_500   -  500
AG3446X_VAL_600   -  600
AG3446X_VAL_800   -  800
AG3446X_VAL_900   -  900
AG3446X_VAL_1000   -  1000
AG3446X_VAL_1200   -  1200
AG3446X_VAL_8000   -  8000

Default Value: AG3446X_VAL_600

SCPI Command:
CALCulate:SCALe:DBM:REFerence{<reference>|MIN|MAX|DEF}        Selects the operation that will be performed by the scaling function. The driver uses this value to set the AG3446X_ATTR_SCALE_FUNCTION attribute.

Valid Values:
AG3446X_VAL_SCALE_FUNC_DB   -  DB. Performs a relative dB computation. The result will be the difference between the input signal and the stored DB relative value, with both values converted to dBm (dB = measurement in dBm - relative value in dBm).
AG3446X_VAL_SCALE_FUNC_DBM   -  DBM. Performs a dBM computation. The result is logarithmic and is based on a calculation of power delivered to a reference resistance, relative to 1 milliwatt. (dBm = 10 * log10(measurement 2 / reference resistance / 1 mW)).
AG3446X_VAL_SCALE_FUNC_PCT - Percent. Performs a percent change operation. The result is the percent change of the measurement from the reference value: Result = ((Measurement �C Reference) / Reference) * 100. % scaling applies to all measurement functions except Ratio, Continuity, and
Diode.
AG3446X_VAL_SCALE_FUNC_SCAL - Scale. Performs an Mx-B operation. The result is the measurement multiplied by the gain value M minus the offset value B . Mx-B scaling applies to all measurement functions except Ratio, Continuity, and Diode.

Default Value: AG3446X_VAL_SCALE_FUNC_DB

SCPI Command:
CALCulate:SCALe:FUNCtion {DB | DBM | PCT | SCALe} 
CALCulate:FUNCtion NULL|DB|DBM|LIMit|AVERage|HOLD (for EDU34450A)

Notes:
(1) The Percent and Scale functions apply only to the 34465A and 34470A.
(2) EDU34450A supports only AG3446X_VAL_SCALE_FUNC_DBM, AG3446X_VAL_SCALE_FUNC_DB functions.    *    Enables or disables automatic reference selection for the dB scaling functions. The driver uses this value to set the AG3446X_ATTR_SCALE_AUTO_REFERENCE attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_TRUE

SCPI Command:
CALCulate:SCALe:REFerence:AUTO{ON|1|OFF|0}     �    Enables or disables the scaling function. The driver uses this value to set the AG3446X_ATTR_SCALE_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
CALCulate:SCALe[:STATe]{ON|1|OFF|0}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   *�-   �  �    Instrument Handle                +� -  �  �    Relative Value                   -� - � � �    Reference Resistance             1 -� � �    Scaling Function                 7 � P �  �    Auto Reference                   8K � �  �    Enable Scaling                   9J#����  �    Status                                 0             T50 AG3446X_VAL_50 75 AG3446X_VAL_75 93 AG3446X_VAL_93 110 AG3446X_VAL_110 124 AG3446X_VAL_124 125 AG3446X_VAL_125 135 AG3446X_VAL_135 150 AG3446X_VAL_150 250 AG3446X_VAL_250 300 AG3446X_VAL_300 500 AG3446X_VAL_500 600 AG3446X_VAL_600 800 AG3446X_VAL_800 900 AG3446X_VAL_900 1000 AG3446X_VAL_1000 1200 AG3446X_VAL_1200 8000 AG3446X_VAL_8000               �DB AG3446X_VAL_SCALE_FUNC_DB DBM AG3446X_VAL_SCALE_FUNC_DBM Percent AG3446X_VAL_SCALE_FUNC_PCT Scale AG3446X_VAL_SCALE_FUNC_SCAL   True VI_TRUE False VI_FALSE    True VI_TRUE False VI_FALSE    	            �    This function configures the scaling settings for 34465A and 34470A, including gain value, offset value and reference value.

Notes:

(1) This function applies only to ACV and DCV measurements.
(2) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    	    Sets a gain value M for the scaling function. The driver uses this value to set the AGX3446X_ATTR_SCALE_GAIN attribute.

Valid Range:
-1.0E+15 to -1.0E-15
0.0 to 0.0
+1.0E-15  to 1.0E+15

Default Value: 1.0

SCPI Command:
CALCulate:SCALe:GAIN {<gain>|MIN|MAX|DEF}        Sets the offset value B for the scaling function. The driver uses this value to set the AG3446X_ATTR_SCALE_OFFSET attribute.

Valid Range:
-1.0E+15 to -1.0E-15
0.0 to 0.0
+1.0E-15  to 1.0E+15

Default Value: 0.0

SCPI Command:
CALCulate:SCALe:OFFSet {<offset> | MIN | MAX | DEF}        Sets the reference value for the PCT function. The driver uses this value to set the AG3446X_ATTR_SCALE_REFERENCE attribute.

Valid Range:
-1.0E+15 to -1.0E-15
0.0 to 0.0
+1.0E-15  to 1.0E+15

Default Value: 0.0

SCPI Command:
CALCulate:SCALe:REFerence {<reference> | MIN | MAX | DEF}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   Dy-   �  �    Instrument Handle                E0 -  �  �    Gain Value                       FA - � �  �    Offset Value                     Ga -� �  �    Reference Value                  H�#����  �    Status                                 1.0    0.0    0.0    	            u    This function configures the scale unit settings.

Notes:

(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    M    Enables or disables displaying the unit string with measurements on the front panel when the scaling function is enabled. The driver uses this value to set the AG3446X_ATTR_SCALE_UNIT_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
CALCulate:SCALe:UNIT:STATe {OFF | ON}    !    Specifies the custom label of up to four characters (for example, RPM) for scaled measurements. The driver uses this value to set the AG3446X_ATTR_SCALE_UNIT attribute.

Valid Values:
ASCII string of up to four characters

Default Value: ""

SCPI Command:
CALCulate:SCALe:UNIT "<string>"    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   P�-   �  �    Instrument Handle                Q[ - U �  �    Enable Scale Unit                R� - � �  �    Scale Unit                       S�#����  �    Status                                 True VI_TRUE False VI_FALSE    ""    	            d    This function configures the histogram settings.

Note: This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Sets the lower range value for the histogram. The driver uses this value to set the AG3446X_ATTR_HIST_LOWER_RANGE attribute.

Valid Range:
-1.0E+15   to  -1.0E-15
0.0
1.0E-15   to  1.0E+15

Default Value: 0.0

Notes:

(1) Setting the lower or upper range value disables automatic selection of the lower and upper range.
(2) Do not set the lower range above the upper range, even if you are using only one range.

SCPI Command:
CALCulate:TRANsform:HISTogram:RANGe:LOWer {<value>|MIN|MAX|DEF}    �    Sets the upper range value for the histogram. The driver uses this value to set the AG3446X_ATTR_HIST_UPPER_RANGE attribute.

Valid Range:
-1.0E+15   to  -1.0E-15
0.0
1.0E-15   to  1.0E+15

Default Value: 0.0

Notes:

(1) Setting the lower or upper range value disables automatic selection of the lower and upper range.
(2) Do not set the upper range below the lower range, even if you are using only one range.

SCPI Command:
CALCulate:TRANsform:HISTogram:RANGe:UPPer {<value>|MIN|MAX|DEF}        Enables or disables histogram computation. The driver uses this value to set the AG3446X_ATTR_HIST_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
CALCulate:TRANsform:HISTogram[:STATe]{ON|1|OFF|0}    �    Enables or disables automatic selection of the histogram's lower and upper range values. The driver uses this value to set the AG3446X_ATTR_HIST_AUTO_RANGE attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_TRUE

Notes:

(1) Setting the lower or upper range value disables automatic selection of the lower and upper range values.

SCPI Command:
CALCulate:TRANsform:HISTogram:RANGe:AUTO{ON|1|OFF|0}    #    Sets the number of bins between the lower and upper range values for the histogram. Two additional bins always exist: one for measurements below the lower range and one for measurements above the upper range. The driver uses this value to set the AG3446X_ATTR_HIST_POINT attribute.

Valid Values:
AG3446X_VAL_10   -  10
AG3446X_VAL_20   -  20
AG3446X_VAL_40   -  40
AG3446X_VAL_100   -  100
AG3446X_VAL_200   -  200
AG3446X_VAL_400   -  400

Default Value: AG3446X_VAL_100

SCPI Command:
CALCulate:TRANsform:HISTogram:POINts{<value>|MIN|MAX|DEF}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   [�-   �  �    Instrument Handle                \w -  �  �    Lower Range                      ^k - � �  �    Upper Range                      `_ -� �  �    Enable Histogram                 al � P �  �    Auto Histogram Range             c" � � � �    Bin Counts                       eM#����  �    Status                                 0.0    0.0    True VI_TRUE False VI_FALSE   True VI_TRUE False VI_FALSE              r10 AG3446X_VAL_10 20 AG3446X_VAL_20 40 AG3446X_VAL_40 100 AG3446X_VAL_100 200 AG3446X_VAL_200 400 AG3446X_VAL_400    	            �    This function configures the AC or DC current measurement to measure the source on the 3 A or 10 A terminals.

Note: This function not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Configures the AC or DC current measurement to measure the source on the 3 A or 10 A terminals. The driver uses this value to set the AG3446X_ATTR_CURR_TERMINAL attribute. This function is only valid to AC and DC current measurement.

Valid Values:
AG3446X_VAL_CURR_TERM_3   -  3
AG3446X_VAL_CURR_TERM_10   -  10

Default Value: 3

Notes:

(1) 10 A terminal is not available on the 34460A.

SCPI Command:
[SENSe:]CURRent:{AC|DC}:TERMinals {3|10}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   n�-   �  �    Instrument Handle                oo - � � �    Terminal Value                   q6#����  �    Status                                            63 AG3446X_VAL_CURR_TERM_3 10 AG3446X_VAL_CURR_TERM_10    	            i    This function disables or enables automatic input impedance mode for DC voltage and ratio measurements.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Disables or enables automatic input impedance mode for DC voltage and ratio measurements. The driver uses this value to set the AG3446X_ATTR_VOLTAGE_AUTO_IMPEDANCE attribute.

Valid Values:
VI_TRUE  - Enable. The input impedance for DC voltage measurements varies by range
VI_FALSE - Disable. The input impedance for DC voltage measurements is fixed at 10M Ohm for all ranges to minimize noise pickup.

Default Value: VI_FALSE

SCPI Command:
[SENSe:]VOLTage[:DC]:IMPedance:AUTO {ON|1|OFF|0}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   y-   �  �    Instrument Handle                y� - �  �    Enable Auto Impedance            {�#����  �    Status                                 True VI_TRUE False VI_FALSE    	            a    This function configures the null operation.

Note: This function not supported for EDU34450A.      �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Enables or disables the null function for each measurements. The driver uses this value to set the AG3446X_ATTR_NULL_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]CURRent:{AC|DC}:NULL[:STATe]
[SENSe:]{FREQuency|PERiod}:NULL[:STATe]
[SENSe:]{RESistance|FRESistance}:NULL[:STATe]
[SENSe:]TEMPerature:NULL[:STATe]
[SENSe:]VOLTage:{AC|DC}:NULL[:STATe]
[SENSe:]CAPacitance:NULL[:STATe]    �    Stores a null value for each measurements. The driver uses this value to set the AG3446X_ATTR_NULL_VALUE attribute.

Valid Range:
-12A   to  12A  for current
-1.2E6  to 1.2E6 for frequency and period
-1.2E8  to 1.2E8 for resistance
-1.0E15  to  1.0E15 for temperature
-1200  to  1200 for voltage
-120  to  120 for capacitance

Default Value: 0

Notes:

(1) Specifying a null value disables automatic null value selection
(2) To use the null value, the null state must be on
(3) Capacitance applies to the 34465A and 34470A

SCPI Command:
[SENSe:]VOLTage:{AC|DC}:NULL:VALue
[SENSe:]CURRent:{AC|DC}:NULL:VALue
[SENSe:]{FREQuency|PERiod}:NULL:VALue
[SENSe:]{RESistance|FRESistance}:NULL:VALue
[SENSe:]TEMPerature:NULL:VALue
[SENSe:]CAPacitance:NULL:VALue    �    Enables or disables automatic null value selection for each measurement. The driver uses this value to set the AG3446X_ATTR_NULL_AUTO_ENABLED attribute.

Valid Values:
VI_TRUE  - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]CURRent:{AC|DC}:NULL:VALue:AUTO
[SENSe:]{FREQuency|PERiod}:NULL:VALue
[SENSe:]{RESistance|FRESistance}:NULL:VALue:AUTO
[SENSe:]TEMPerature:NULL:VALue:AUTO
[SENSe:]VOLTage:{AC|DC}:NULL:VALue:AUTO
[SENSe:]CAPacitance:NULL:VALue:AUTO    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �a-   �  �    Instrument Handle                � - P �  �    Enable Null Function             �� - � �  �    Null Value                       �� -� �  �    Enable Auto Value                ��#����  �    Status                                 True VI_TRUE False VI_FALSE    0    True VI_TRUE False VI_FALSE    	            U    This function configures measurement and trigger parameters to their default value.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    0    Specifies the measurement type to configure. The driver uses this value to set the AG3446X_ATTR_CONF_MEAS attribute.

Valid Values:
AG3446X_VAL_CONF_MEAS_CONT   -  Continuity
AG3446X_VAL_CONF_MEAS_AC_CURRENT   -  AC Current
AG3446X_VAL_CONF_MEAS_DC_CURRENT   -  DC Current
AG3446X_VAL_CONF_MEAS_DIODE   -  Diode
AG3446X_VAL_CONF_MEAS_FREQ   -  Frequency
AG3446X_VAL_CONF_MEAS_PER   -  Period
AG3446X_VAL_CONF_MEAS_RES   -  2 Wire Resistance
AG3446X_VAL_CONF_MEAS_FRES   -  4 Wire Resistance
AG3446X_VAL_CONF_MEAS_TEMP   -  Temperature
AG3446X_VAL_CONF_MEAS_AC_VOLTAGE   -  AC Voltage
AG3446X_VAL_CONF_MEAS_DC_VOLTAGE   -  DC Voltage
AG3446X_VAL_CONF_MEAS_DC_VOLTAGE_RATIO   -  DC Voltage Ratio
AG3446X_VAL_CONF_MEAS_CAP   -  Capacitance

Default Value: AG3446X_VAL_CONF_MEAS_CONT

Notes:
(1) AG3446X_VAL_CONF_MEAS_CAP applies only to the 34465A, 34470A and EDU34450A.
(2) AG3446X_VAL_CONF_MEAS_PER is not supported for EDU34450A.
    AG3446X_VAL_CONF_MEAS_DC_VOLTAGE_RATIO is not supported for EDU34450A.

SCPI Command:
CONFigure:CONTinuity
CONFigure:CURRent:{AC|DC}
CONFigure:DIODe
CONFigure:{FREQuency|PERiod} PERiod is not supported for EDU34450A.
CONFigure:{RESistance|FRESistance}
CONFigure:TEMPerature
CONFigure[:VOLTage]:{AC|DC}
CONFigure[:VOLTage][:DC]:RATio not supported for EDU34450A.
CONFigure:CAPacitance








    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ��-   �  �    Instrument Handle                �� - � � �    Type                             ��#����  �    Status                                           Continuity AG3446X_VAL_CONF_MEAS_CONT AC Current AG3446X_VAL_CONF_MEAS_AC_CURRENT DC Current AG3446X_VAL_CONF_MEAS_DC_CURRENT Diode AG3446X_VAL_CONF_MEAS_DIODE Frequency AG3446X_VAL_CONF_MEAS_FREQ Period AG3446X_VAL_CONF_MEAS_PER 2 Wire Resistance AG3446X_VAL_CONF_MEAS_RES 4 Wire Resistance AG3446X_VAL_CONF_MEAS_FRES Temperature AG3446X_VAL_CONF_MEAS_TEMP AC Voltage AG3446X_VAL_CONF_MEAS_AC_VOLTAGE DC Voltage AG3446X_VAL_CONF_MEAS_DC_VOLTAGE DC Voltage Ratio AG3446X_VAL_CONF_MEAS_DC_VOLTAGE_RATIO Capacitance AG3446X_VAL_CONF_MEAS_CAP    	            t    This function configures the smoothing settings.

Notes:

(1) This function applies only to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    �    Enables or disables a smoothing (moving average) filter on the measurements. Smoothing is intended to average out small variations in the measurements. Larger variations will cause the filter to reset. The driver uses this value to set the AG3446X_ATTR_SMOOTHING_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_TRUE

SCPI Command:
CALCulate:SMOothing[:STATe] {OFF | ON}    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors    �    Selects the number of measurements to be averaged by the moving average (boxcar) filter. The driver uses this value to set the AG3446X_ATTR_SMOOTHING_RESPONSE attribute.

Valid Values:
AG3446X_VAL_SMOOTHING_RESPONSE_SLOW - Slow, 100 measurements.
AG3446X_VAL_SMOOTHING_RESPONSE_MEDIUM - Medium, 50 measurements. 
AG3446X_VAL_SMOOTHING_RESPONSE_FAST - Fast, 10 measurements. 

Default Value: AG3446X_VAL_SMOOTHING_RESPONSE_FAST

SCPI Command:
CALCulate:SMOothing:RESPonse {SLOW | MEDium | FAST}   ��-   �  �    Instrument Handle                �f -� �  �    Enable Smoothing                 �
#����  �    Status                           �| -  � �    Number of Measurements                True VI_TRUE False VI_FALSE    	                      Slow AG3446X_VAL_SMOOTHING_RESPONSE_SLOW Medium AG3446X_VAL_SMOOTHING_RESPONSE_MEDIUM Fast AG3446X_VAL_SMOOTHING_RESPONSE_FAST    �    This function enables or disables the trend chart data.

Notes:

(1) This function applies only to the 34461A, 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors    w    Enables or disables trend chart data when controlling the instrument from remote. The driver uses this value to set the AG3446X_ATTR_TREND_CHART_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
CALCulate:TCHart[:STATe] {OFF | ON}

Notes:
(1) You must enable this (ON) before sending INIT or READ? to see trend chart data when controlling the instrument from remote. If it is disabled or enabled after INIT or READ?, viewing the trend chart results in a chart with no data.
(2) Trend chart data must be disabled (OFF) to make measurements at the highest speed (50 kHz).   ��-   �  �    Instrument Handle                �F#����  �    Status                           �� - �  �    Enable Trend Chart                     	            True VI_TRUE False VI_FALSE       This function configures the measurement settings for both 2-wire resistance and 4-wire resistance measurement.

Notes:

(1) This function applies only to the 34465A, 34470A and EDU34450A.
(2) AG3446X_ATTR_POWER_LIMIT_ENABLED not supported for EDU34450A.      �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors    r    Enables or disables offset compensation. Offset compensation removes the effects of small dc voltages in the circuit being measured. The technique involves taking the difference between two resistance measurements, one with the current source set to the normal value, and one with the current source set to a lower value. Enabling Offset Compensation approximately doubles the reading time. The driver uses this value to set the AG3446X_ATTR_OFFSET_COMPENSATE_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]{RESistance|FRESistance}:OCOMpensated {OFF|ON}    i    Enables or disables low-power resistance measurements (either 2- or 4-wire). The driver uses this value to set the AG3446X_ATTR_POWER_LIMIT_ENABLED attribute.

Valid Values:
VI_TRUE - Enable
VI_FALSE - Disable

Default Value: VI_FALSE

SCPI Command:
[SENSe:]{RESistance|FRESistance}:POWer:LIMit[:STATe] {OFF|ON}

Note: The command not supported for EDU34450A.   �-   �  �    Instrument Handle                ��#����  �    Status                           �7 -o �  �    Enable Offset Compensation       ı - � �  �    Enable Power Limit                     	            True VI_TRUE False VI_FALSE    True VI_TRUE False VI_FALSE    �    Configures the range change mode for AC and DC current measurements.

Notes:
(1) This function only applies to the 34465A and 34470A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors    �    Sets the range change mode for AC and DC current measurements. The driver uses this value to set the AG3446X_ATTR_RANGE_CHANGE_MODE attribute.

Valid Values:
AG3446X_VAL_RANGE_CHANGE_FAST - Fast
AG3446X_VAL_RANGE_CHANGE_CONT - Continuous

Default Value: AG3446X_VAL_RANGE_CHANGE_FAST

SCPI Command:
[SENSe:]CURRent:SWITch:MODE {FAST | CONTinuous}

Notes:
(1) This control is valid to the 3A current terminals only.    ��-   �  �    Instrument Handle                Ȋ#����  �    Status                           �� 7 � � �    Range Change Mode                      	                      LFast AG3446X_VAL_RANGE_CHANGE_FAST Continuous AG3446X_VAL_RANGE_CHANGE_CONT    c    This function returns the actual range the DMM is currently using, even while it is auto-ranging.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        Returns the actual range that the DMM is currently using, even while it is auto-ranging. The driver uses this value to set the AG3446X_ATTR_AUTO_RANGE_VALUE attribute.

The units of the returned value depend on the value of the AG3446X_ATTR_FUNCTION attribute.

   �-   �  �    Instrument Handle                ��#����  �    Status                           �P H � �  �    Actual Range                           	           	           �    This function returns additional information about the state of the instrument. Specifically, it returns the aperture time and the aperture time units.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    r    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:      
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    h    Returns the value of the Aperture Time attribute. The driver uses this value to set the AG3446X_ATTR_APERTURE_TIME attribute.
The units of this attribute depend on the value of the AG3446X_ATTR_APERTURE_TIME_UNITS attribute.

Valid Range:
34460A and 34461A when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_POWER_LINE_CYCLES
0.0  to  0.02  coerced to  0.02
0.02 to  0.2   coerced to  0.2
0.2  to  1.0   coerced to  1.0
1.0  to  10.0  coerced to  10.0
10.0 to  100.0 coerced to  100.0

34460A and 34461A when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS (Frequency and period measurement only)
0.0 to 0.01 coerced to 0.01
0.01 to 0.1 coerced to 0.1
0.1 to 1.0 coerced to 1.0

34465A and 34470A without option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_POWER_LINE_CYCLES
0.0  to  0.02  coerced to  0.02
0.02 to  0.2   coerced to  0.2
0.2  to  1.0   coerced to  1.0
1.0  to  10.0  coerced to  10.0
10.0 to  100.0 coerced to  100.0

34465A and 34470A with option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_POWER_LINE_CYCLES
0.0 to 0.001 coerced to 0.001
0.001 to 0.002 coerced to 0.002
0.002 to 0.006 coerced to 0.006
0.006  to  0.02  coerced to  0.02
0.02 to  0.2   coerced to  0.2
0.2  to  1.0   coerced to  1.0
1.0  to  10.0  coerced to  10.0
10.0 to  100.0 coerced to  100.0

34465A and 34470A without option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS
200 us to 1 s (2 us resolution)

34465A and 34470A with option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS
20 us to 1 s (2 us resolution)

34465A and 34470A when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS (Frequency and period measurement only)
0.0 to 0.001 coerced to 0.001
0.001 to 0.01 coerced to 0.01
0.01 to 0.1 coerced to 0.1
0.1 to 1.0 coerced to 1.0

Default Value: 0.0

SCPI Command:
[SENSe:]CURRent[:DC]:NPLC
[SENSe:]{RESistance|FRESistance}:NPLC
[SENSe:]TEMPerature:NPLC
[SENSe:]VOLTage[:DC]:NPLC
[SENSe:]CURRent[:DC]:APERture
[SENSe:]{FREQuency|PERiod}:APERture
[SENSe:]{RESistance|FRESistance}:APERture
[SENSe:]TEMPerature:APERture
[SENSe:]VOLTage[:DC]:APERture

Attribute Value: 1250321     �    Returns the value of the Aperture Time Units attribute. The driver uses this value to set the AG3446X_ATTR_APERTURE_TIME_UNITS attribute.

Valid Return Values:
AG3446X_VAL_SECONDS - Seconds
AG3446X_VAL_POWER_LINE_CYCLES - Powerline cycles
   ۼ-   �  �    Instrument Handle                �t#����  �    Status                           �� = X �  �    Aperture Time                    �^ =3 �  �    Aperture Time Units                    	           	           	            �    This function configures additional information about the state of the instrument. Specifically, it configures the aperture time and whether the aperture is enabled or not.

Note: AG3446X_ATTR_APERTURE_TIME_UNITS not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    r    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:      
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    	)    Specifies the value of the Aperture Time attribute. The driver uses this value to set the AG3446X_ATTR_APERTURE_TIME attribute.
The units of this attribute depend on the value of the AG3446X_ATTR_APERTURE_TIME_UNITS attribute.

Valid Range:
34460A and 34461A when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_POWER_LINE_CYCLES
0.0  to  0.02  coerced to  0.02
0.02 to  0.2   coerced to  0.2
0.2  to  1.0   coerced to  1.0
1.0  to  10.0  coerced to  10.0
10.0 to  100.0 coerced to  100.0

34460A and 34461A when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS (Frequency and period measurement only)
0.0 to 0.01 coerced to 0.01
0.01 to 0.1 coerced to 0.1
0.1 to 1.0 coerced to 1.0

34465A and 34470A without option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_POWER_LINE_CYCLES
0.0  to  0.02  coerced to  0.02
0.02 to  0.2   coerced to  0.2
0.2  to  1.0   coerced to  1.0
1.0  to  10.0  coerced to  10.0
10.0 to  100.0 coerced to  100.0

34465A and 34470A with option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_POWER_LINE_CYCLES
0.0 to 0.001 coerced to 0.001
0.001 to 0.002 coerced to 0.002
0.002 to 0.006 coerced to 0.006
0.006  to  0.02  coerced to  0.02
0.02 to  0.2   coerced to  0.2
0.2  to  1.0   coerced to  1.0
1.0  to  10.0  coerced to  10.0
10.0 to  100.0 coerced to  100.0

34465A and 34470A without option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS
200 us to 1 s (2 us resolution)

34465A and 34470A with option DIG when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS
20 us to 1 s (2 us resolution)

34465A and 34470A when AG3446X_ATTR_APERTURE_TIME_UNITS is AG3446X_VAL_SECONDS (Frequency and period measurement only)
0.0 to 0.001 coerced to 0.001
0.001 to 0.01 coerced to 0.01
0.01 to 0.1 coerced to 0.1
0.1 to 1.0 coerced to 1.0

EDU34450A supports only FREQuency:APERture measurement function
0.1 ro 1 coerced to 1

Default Value: 10.0

SCPI Command:
[SENSe:]CURRent[:DC]:NPLC
[SENSe:]{RESistance|FRESistance}:NPLC
[SENSe:]TEMPerature:NPLC
[SENSe:]VOLTage[:DC]:NPLC
[SENSe:]CURRent[:DC]:APERture
[SENSe:]{FREQuency|PERiod}:APERture
[SENSe:]{RESistance|FRESistance}:APERture
[SENSe:]TEMPerature:APERture
[SENSe:]VOLTage[:DC]:APERture

Only supported SCPI Command for EDU3450A:
[SENSe:][PRIMary:]FREQuency:APERture <seconds>|MIN|MAX|DEF


Attribute Value: 1250321    W    Specifies the value of the Aperture Time Units attribute. The driver uses this value to set the AG3446X_ATTR_APERTURE_TIME_UNITS attribute.

Valid Values:
AG3446X_VAL_SECONDS - Seconds
AG3446X_VAL_POWER_LINE_CYCLES - Powerline cycles

Default Value: AG3446X_VAL_POWER_LINE_CYCLES

Notes:
(1) This control is valid only for 34465A and 34470A.   �N-   �  �    Instrument Handle                �#����  �    Status                           �� >K �  �    Aperture Time                    �� > W � �    Aperture Time Units                    	           10.0              KSeconds AG3446X_VAL_SECONDS Powerline cycles AG3446X_VAL_POWER_LINE_CYCLES   �    This function sets the value of a ViInt32 attribute.

This is a low-level function that you can use to set the values of instrument-specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid or is different than the value you specify. 

This instrument driver contains high-level functions that set most of the instrument attributes.  It is best to use the high-level driver functions as much as possible.  They handle order dependencies and multithread locking for you.  In addition, they perform status checking only after setting all of the attributes.  In contrast, when you set multiple attributes using the SetAttribute functions, the functions check the instrument status after each call.

Also, when state caching is enabled, the high-level functions that configure multiple attributes perform instrument I/O only for the attributes whose value you change.  Thus, you can safely call the high-level functions without the penalty of redundant instrument I/O.


     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        Pass the value to which you want to set the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none    C    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViInt32 type. 
  If you choose to see all IVI attributes, the data types appear
  to the right of the attribute names in the list box.  The data
  types that are not consistent with this function are dim.
  If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
   )-   �  �    Instrument Handle                �#����  �    Status                           _ � � �  �    Attribute Value                 ���� � ���                                          z = � � �    Attribute ID                     � =  �  �    Channel Name                           	               .Press <ENTER> for a list of 
value constants.                0    ""   �    This function sets the value of a ViReal64 attribute.

This is a low-level function that you can use to set the values of instrument-specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid or is different than the value you specify. 

This instrument driver contains high-level functions that set most of the instrument attributes.  It is best to use the high-level driver functions as much as possible.  They handle order dependencies and multithread locking for you.  In addition, they perform status checking only after setting all of the attributes.  In contrast, when you set multiple attributes using the SetAttribute functions, the functions check the instrument status after each call.

Also, when state caching is enabled, the high-level functions that configure multiple attributes perform instrument I/O only for the attributes whose value you change.  Thus, you can safely call the high-level functions without the penalty of redundant instrument I/O.


     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        Pass the value to which you want to set the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none    E    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViReal64 
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
   �-   �  �    Instrument Handle                d#����  �    Status                           "� � � �  �    Attribute Value                 ���� � ���                                          $� = � � �    Attribute ID                     *I =  �  �    Channel Name                           	               .Press <ENTER> for a list of 
value constants.                0    ""   �    This function sets the value of a ViString attribute.

This is a low-level function that you can use to set the values of instrument-specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid or is different than the value you specify. 

This instrument driver contains high-level functions that set most of the instrument attributes.  It is best to use the high-level driver functions as much as possible.  They handle order dependencies and multithread locking for you.  In addition, they perform status checking only after setting all of the attributes.  In contrast, when you set multiple attributes using the SetAttribute functions, the functions check the instrument status after each call.

Also, when state caching is enabled, the high-level functions that configure multiple attributes perform instrument I/O only for the attributes whose value you change.  Thus, you can safely call the high-level functions without the penalty of redundant instrument I/O.


     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        Pass the value to which you want to set the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none    E    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViString 
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
   10-   �  �    Instrument Handle                1�#����  �    Status                           8f � � �  �    Attribute Value                 ���� � ���                                          :� = � � �    Attribute ID                     ?� =  �  �    Channel Name                           	               .Press <ENTER> for a list of 
value constants.                0    ""   �    This function sets the value of a ViBoolean attribute.

This is a low-level function that you can use to set the values of instrument-specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid or is different than the value you specify. 

This instrument driver contains high-level functions that set most of the instrument attributes.  It is best to use the high-level driver functions as much as possible.  They handle order dependencies and multithread locking for you.  In addition, they perform status checking only after setting all of the attributes.  In contrast, when you set multiple attributes using the SetAttribute functions, the functions check the instrument status after each call.

Also, when state caching is enabled, the high-level functions that configure multiple attributes perform instrument I/O only for the attributes whose value you change.  Thus, you can safely call the high-level functions without the penalty of redundant instrument I/O.


     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        Pass the value to which you want to set the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none    E    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViBoolean
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
   F�-   �  �    Instrument Handle                Gn#����  �    Status                           M� � � �  �    Attribute Value                 ���� � ���                                          P = � � �    Attribute ID                     UT =  �  �    Channel Name                           	               .Press <ENTER> for a list of 
value constants.                0    ""   �    This function sets the value of a ViSession attribute.

This is a low-level function that you can use to set the values of instrument-specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid or is different than the value you specify. 

This instrument driver contains high-level functions that set most of the instrument attributes.  It is best to use the high-level driver functions as much as possible.  They handle order dependencies and multithread locking for you.  In addition, they perform status checking only after setting all of the attributes.  In contrast, when you set multiple attributes using the SetAttribute functions, the functions check the instrument status after each call.

Also, when state caching is enabled, the high-level functions that configure multiple attributes perform instrument I/O only for the attributes whose value you change.  Thus, you can safely call the high-level functions without the penalty of redundant instrument I/O.


     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        Pass the value to which you want to set the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    E    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViSession
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   \<-   �  �    Instrument Handle                \�#����  �    Status                           cq � � �  �    Attribute Value                  e� =  �  �    Channel Name                     f = � � �    Attribute ID                    ���� � ���                                                	               ""                0    .Press <ENTER> for a list of 
value constants.   �    This function queries the value of a ViInt32 attribute.

You can use this function to get the values of instrument- specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid. 

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Returns the current value of the attribute.  Pass the address of a ViInt32 variable.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    �    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Help text is
  shown for each attribute.  Select an attribute by 
  double-clicking on it or by selecting it and then pressing
  <ENTER>.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViInt32 type. 
  If you choose to see all IVI attributes, the data types appear
  to the right of the attribute names in the list box.  The data
  types that are not consistent with this function are dim.
  If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   n�-   �  �    Instrument Handle                oa#����  �    Status                           u� � � �  �    Attribute Value                  w� =  �  �    Channel Name                     x = � � �    Attribute ID                           	           	            ""                0   �    This function queries the value of a ViReal64 attribute.

You can use this function to get the values of instrument- specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid. 

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Returns the current value of the attribute.  Pass the address of a ViReal64 variable.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    �    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Help text is
  shown for each attribute.  Select an attribute by 
  double-clicking on it or by selecting it and then pressing
  <ENTER>.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViReal64
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   �-   �  �    Instrument Handle                �b#����  �    Status                           �� � � �  �    Attribute Value                  �� =  �  �    Channel Name                     � = � � �    Attribute ID                           	           	           ""                0   +    This function queries the value of a ViString attribute.

You can use this function to get the values of instrument- specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid. 

You must provide a ViChar array to serve as a buffer for the value.  You pass the number of bytes in the buffer as the Buffer Size parameter.  If the current value of the attribute, including the terminating NUL byte, is larger than the size you indicate in the Buffer Size parameter, the function copies Buffer Size-1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the Buffer Size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you want to call this function just to get the required Buffer Size, you can pass 0 for the Buffer Size and VI_NULL for the Attribute Value buffer.  

If you want the function to fill in the buffer regardless of the number of bytes in the value, pass a negative number for the Buffer Size parameter.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    3    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

If the current value of the return buffer, including the terminating NUL byte, is larger than the size you indicate in the Buffer Size parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        The buffer in which the function returns the current value of the attribute.  The buffer must be of type ViChar and have at least as many bytes as indicated in the Buffer Size parameter.

If the current value of the attribute, including the terminating NUL byte, contains more bytes that you indicate in this parameter, the function copies Buffer Size-1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the Buffer Size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you specify 0 for the Buffer Size parameter, you can pass VI_NULL for this parameter.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    �    Pass the number of bytes in the ViChar array you specify for the Attribute Value parameter.  

If the current value of the attribute, including the terminating NUL byte, contains more bytes that you indicate in this parameter, the function copies Buffer Size-1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the Buffer Size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you pass a negative number, the function copies the value to the buffer regardless of the number of bytes in the value.

If you pass 0, you can pass VI_NULL for the Attribute Value buffer parameter.

Default Value: 512    �    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Help text is
  shown for each attribute.  Select an attribute by 
  double-clicking on it or by selecting it and then pressing
  <ENTER>.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViString
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   �"-   �  �    Instrument Handle                ��#����  �    Status or Required Size          � � L � �    Attribute Value                  �9 =  �  �    Channel Name                     �� =� �  �    Buffer Size                      �� = � � �    Attribute ID                           	           	            ""    512                0   �    This function queries the value of a ViBoolean attribute.

You can use this function to get the values of instrument- specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid. 

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Returns the current value of the attribute.  Pass the address of a ViBoolean variable.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    �    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Help text is
  shown for each attribute.  Select an attribute by 
  double-clicking on it or by selecting it and then pressing
  <ENTER>.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViBoolean
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   ��-   �  �    Instrument Handle                �8#����  �    Status                           �� � � �  �    Attribute Value                  �m =  �  �    Channel Name                     �� = � � �    Attribute ID                           	           	            ""                0   �    This function queries the value of a ViSession attribute.

You can use this function to get the values of instrument- specific attributes and inherent IVI attributes.  If the attribute represents an instrument state, this function performs instrument I/O in the following cases:

- State caching is disabled for the entire session or for the particular attribute.

- State caching is enabled and the currently cached value is invalid. 

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    �    Returns the current value of the attribute.  Pass the address of a ViSession variable.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  
     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    �    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Help text is
  shown for each attribute.  Select an attribute by 
  double-clicking on it or by selecting it and then pressing
  <ENTER>.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViSession
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   ��-   �  �    Instrument Handle                �=#����  �    Status                           ĺ � � �  �    Attribute Value                  �r =  �  �    Channel Name                     �� = � � �    Attribute ID                           	           	            ""                0    S    This function checks the validity of a value you specify for a ViInt32 attribute.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    (    Pass the value which you want to verify as a valid value for the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    B    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViInt32 type.
  If you choose to see all IVI attributes, the data types appear
  to the right of the attribute names in the list box.  The data
  types that are not consistent with this function are dim.
  If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   �&-   �  �    Instrument Handle                ��#����  �    Status                           �\ � � �  �    Attribute Value                  ֌ =  �  �    Channel Name                    ���� � ���                                          � = � � �    Attribute ID                           	               ""    .Press <ENTER> for a list of 
value constants.                0    T    This function checks the validity of a value you specify for a ViReal64 attribute.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    (    Pass the value which you want to verify as a valid value for the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    D    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViReal64
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   �E-   �  �    Instrument Handle                ��#����  �    Status                           �{ � � �  �    Attribute Value                  � =  �  �    Channel Name                    ���� � ���                                          �# = � � �    Attribute ID                           	               ""    .Press <ENTER> for a list of 
value constants.                0    T    This function checks the validity of a value you specify for a ViString attribute.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    (    Pass the value which you want to verify as a valid value for the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    D    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViString
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   �f-   �  �    Instrument Handle                �#����  �    Status                           �� � � �  �    Attribute Value                  �� =  �  �    Channel Name                    ���� � ���                                          �C = � � �    Attribute ID                           	               ""    .Press <ENTER> for a list of 
value constants.                0    U    This function checks the validity of a value you specify for a ViBoolean attribute.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    (    Pass the value which you want to verify as a valid value for the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    E    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViBoolean
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
    �-   �  �    Instrument Handle                ?#����  �    Status                           � � � �  �    Attribute Value                  	� =  �  �    Channel Name                    ���� � ���                                          
e = � � �    Attribute ID                           	               ""    .Press <ENTER> for a list of 
value constants.                0    U    This function checks the validity of a value you specify for a ViSession attribute.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

    (    Pass the value which you want to verify as a valid value for the attribute.

From the function panel window, you can use this control as follows.

- If the attribute currently showing in the Attribute ID ring
  control has constants as valid values, you can view a list of
  the constants by pressing <ENTER> on this control.  Select a
  value by double-clicking on it or by selecting it and then
  pressing <ENTER>.  

  Note:  Some of the values might not be valid depending on the
  current settings of the instrument session.

Default Value: none     p    DMM attributes are not channel-based. Pass VI_NULL or an empty string for this parameter.

Default Value:  ""
    E    Pass the ID of an attribute.

From the function panel window, you can use this control as follows.

- Click on the control or press <ENTER>, <spacebar>, or
  <ctrl-down arrow>, to display a dialog box containing a
  hierarchical list of the available attributes.  Attributes 
  whose value cannot be set are dim.  Help text is shown for 
  each attribute.  Select an attribute by double-clicking on it  
  or by selecting it and then pressing <ENTER>.

  Read-only attributes appear dim in the list box.  If you 
  select a read-only attribute, an error message appears.

  A ring control at the top of the dialog box allows you to see 
  all IVI attributes or only the attributes of the ViSession
  type.  If you choose to see all IVI attributes, the data types
  appear to the right of the attribute names in the list box. 
  The data types that are not consistent with this function are
  dim. If you select an attribute data type that is dim,
  LabWindows/CVI transfers you to the function panel for the
  corresponding function that is consistent with the data type.

- If you want to enter a variable name, press <CTRL-T> to change
  this ring control to a manual input box.

- If the attribute in this ring control has constants as valid
  values, you can view the constants by moving to the Attribute
  Value control and pressing <ENTER>.
   �-   �  �    Instrument Handle                b#����  �    Status                           � � � �  �    Attribute Value                   =  �  �    Channel Name                    ���� � ���                                          � = � � �    Attribute ID                           	               ""    .Press <ENTER> for a list of 
value constants.                0   &    This function initiates a measurement, waits until the DMM has returned to the idle state, and returns the measured value.

Notes:

(1) After this function executes, the Reading parameter contains  an actual reading or a value indicating that an over-range condition occurred.

(2) If an over-range condition occurs, the Reading parameter contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE (0x3FFA2001).  

(3) You can test the measurement value for over-range with the ag3446x_IsOverRange function.
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    N    Returns the measured value.  The value you specify for the Measurement Function parameter of the ag3446x_ConfigureMeasurement function determines the units of this parameter as shown in the following table.

  DC Volts           - volts
  AC Volts           - volts
  DC Current         - amperes
  AC Current         - amperes
  2-Wire Resistance  - ohms
  4-Wire Resistance  - ohms
  Temperature (C)    - celcius
  Temperature (F)    - Fahrenheit
  Frequency          - hertz
  Period             - seconds
  Diode              - none
  Continuity         - none

Notes:

(1) If an over-range condition occurs, the Reading parameter contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE (0x3FFA2001).  

(2) You can test the measurement value for over-range with the ag3446x_IsOverRange function.
    �    Pass the maximum length of time in which to allow the read operation to complete.  Express this value in milliseconds.  

If the operation does not complete within this time interval, the function returns the AG3446X_ERROR_MAX_TIME_EXCEEDED (0xBFFA2003) error code.  When this occurs, you can call ag3446x_Abort to cancel the read operation and return the instrument to the Idle state.  

Defined Values:
AG3446X_VAL_MAX_TIME_INFINITE (-1)            AG3446X_VAL_MAX_TIME_IMMEDIATE (0)          

Default Value: 5000 (ms)

Notes:

(1) The Maximum Time parameter affects only this function.  It has no effect on other timeout parameters or attributes.
   $�#����  �    Status                           +-   �  �    Instrument Handle                +� =0 �  �    Reading                          /( = l �  �    Maximum Time (ms)                  	               	           5000       This function initiates the measurement, waits for the DMM to return to the Idle state, and returns an array of measured values.  The number of measurements the DMM takes is determined by the values you specify for the Trigger Count and Sample Count parameters of the ag3446x_ConfigureMultiPoint function.

Notes:

(1) After this function executes, each element in the Reading Array parameter is an actual reading or a value indicating that an over-range condition occurred.

(2) If an over-range condition occurs, the corresponding Reading Array element contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE (0x3FFA2001). 

(3) You can test each element in the Reading Array parameter for over-range with the ag3446x_IsOverRange function.
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    �    Returns an array of the most recent measurement values.  The value you specify for the Measurement Function parameter of the ag3446x_ConfigureMeasurement function determines the units of this parameter as shown in the following table.

  DC Volts           - volts
  AC Volts           - volts
  DC Current         - amperes
  AC Current         - amperes
  2-Wire Resistance  - ohms
  4-Wire Resistance  - ohms
  Temperature (C)    - celcius
  Temperature (F)    - Fahrenheit
  Frequency          - hertz
  Period             - seconds
  Diode              - none
  Continuity         - none

Notes:

(1) The size of the Reading Array must be at least the size you specify for the Array Size parameter.

(2) If an over-range condition occurs, the corresponding Reading Array element contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE (0x3FFA2001). 

(3) You can test each element in the Reading Array parameter for over-range with the ag3446x_IsOverRange function.
     S    Pass the number of elements in the Reading Array parameter.

Default Value: None
     ]    Indicates the number of measured values the function places in the Reading Array parameter.    �    Pass the maximum length of time in which to allow the multi-point read operation to complete.  Express this value in milliseconds.  

If the operation does not complete within this time interval, the function returns the AG3446X_ERROR_MAX_TIME_EXCEEDED (0xBFFA2003) error code.  When this occurs, you can call ag3446x_Abort to cancel the multi-point read operation and return the instrument to the Idle state.  

Defined Values:
AG3446X_VAL_MAX_TIME_INFINITE (-1)             AG3446X_VAL_MAX_TIME_IMMEDIATE (0)           

Default Value: 5000 (ms)

Notes:

(1) The Maximum Time parameter affects only this function.  It has no effect on other timeout parameters or attributes.
   5�#����  �    Status                           <N-   �  �    Instrument Handle                = z0 �  �    Reading Array                    A =0 �  �    Array Size                       Aa �0 �  �    Actual Number of Points          A� = l �  �    Maximum Time (ms)                  	               	                	            5000    n    This function returns the histogram measurement result.

Note: This function is not supported for EDU34450A.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     �    Returns the histogram measurement result list of the bin data collected since the last time the histogram data was cleared.

SCPI Command:
CALCulate:TRANsform:HISTogram:DATA?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   F]-   �  �    Instrument Handle                G - � �  �    Readings                         G�#����  �    Status                                 	            	            �    This function returns a specified statistics measurement.

Notes:

(1) You must set "EnableAverage" control to true in ag3446x_ConfigureAverage function.
(2) For EDU34450A model, must run ag3446x_ConfigureAverage to set calculation function to average.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     Y    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:SDEViation?     V    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:AVERage?     T    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:COUNt?     V    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:MAXimum?     V    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:MINimum?     U    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:PTPeak?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   P -   �  �    Instrument Handle                P� -  �  �    Standard Deviation Value         Q - � �  �    Average Value                    Qv -� �  �    Count Value                      Q� �  �  �    Maximum Value                    R0 � � �  �    Minimum Value                    R� �� �  �    Peak-To-Peak Value               R�#����  �    Status                                 	            	            	            	            	            	           	            %    Returns the last measurement taken.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     T    Returns the last measurement result including the units.

SCPI Command:
DATA:LAST?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   [�-   �  �    Instrument Handle                \A - � �  �    Last Result                      \�#����  �    Status                                 	           	            G    Returns the total number of measurements currently in reading memory.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     c    Returns the total number of measurements currently in reading memory.

SCPI Command:
DATA:POINts?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   d-   �  �    Instrument Handle                d� - � �  �    Data Points                      e;#����  �    Status                                 	            	            -    This function reads the measurement memory.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     �    Specifies the number of measurements to read and erase from the reading memory.

Valid Range:
34460A: 1 to 1000
34461A: 1 to 10000

Default Value:
1

SCPI Command:
DATA:REMove?<num_readings> [,WAIT]        Specifies whether to wait when fewer than the count of measurements specified are available. The query will return an error unless Enable Wait is specified to true.

Valid Values:
VI_TRUE
VI_FALSE

Default Value:
VI_FALSE

SCPI Command:
DATA:REMove?<num_readings> [,WAIT]     L    Returns the read result.

SCPI Command:
DATA:REMove?<num_readings> [,WAIT]    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   l�-   �  �    Instrument Handle                mT -  �  �    Read Count                       n$ - �  �    Enable Wait                      o= -� �  �    Result                           o�#����  �    Status                                 1    True VI_TRUE False VI_FALSE    	            	            �    This function initiates a measurement, waits until the DMM has returned to the idle state, and returns the secondary measured value.

Notes:
(1) This function applies only to the 34465A and the 34470A.    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    +    Returns 1, 2, or 3 values depending on the active secondary measurement.

SCPI Command:
[SENSe:]DATA2?

Notes:
(1)  If there is currently no valid secondary measurement specified, the query returns "9.91000000E+37" (which is the IEEE488.2 definition of Not a Number - usually referred to as NaN).
     X    Specifies the number of readings to read.

Valid Values:
1, 2 or 3;

Default Value: 1
   x#����  �    Status                           ~�-   �  �    Instrument Handle                T =N �  �    Reading                          �� = > �  �    Number of Readings                 	               	            1   9    This function initiates a measurement.  After you call this function, the DMM leaves the Idle state and waits for a trigger.

Notes:

(1) This function does not check the instrument status.   Typically, you call this function only in a sequence of calls to other low-level driver functions.  The sequence performs one operation.  You use the low-level functions to optimize one or more aspects of interaction with the instrument.  If you want to check the instrument status, call the ag3446x_error_query function at the conclusion of the sequence.

SCPI Command:
INIT    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   �#����  �    Status                           ��-   �  �    Instrument Handle                  	              p    This function sends a command to trigger the DMM.  Call this function if you pass AG3446X_VAL_SOFTWARE_TRIG for the Trigger Source parameter of the ag3446x_ConfigureTrigger function or the Sample Trigger parameter of the ag3446x_ConfigureMultiPoint function.

Notes:

(1) If both the AG3446X_ATTR_TRIGGER_SOURCE and the  AG3446X_ATTR_SAMPLE_TRIGGER attributes are not set to the AG3446X_VAL_SOFTWARE_TRIG value, this function returns an error.

(2) This function does not check the instrument status.   Typically, you call this function only in a sequence of calls to other low-level driver functions.  The sequence performs one operation.  You use the low-level functions to optimize one or more aspects of interaction with the instrument.  If you want to check the instrument status, call the ag3446x_error_query function at the conclusion of the sequence.

SCPI Command:
*TRG    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   �E#����  �    Status                           ��-   �  �    Instrument Handle                  	                  This function returns the value from a previously initiated measurement.

You must first call the ag3446x_Initiate function to initiate a measurement before calling this function.

Notes:

(1) After this function executes, the Reading parameter contains  an actual reading or a value indicating that an over-range condition occurred.

(2) If an over-range condition occurs, the Reading parameter contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE (0x3FFA2001).  

(3) You can test the measurement value for over-range with the ag3446x_IsOverRange function.

(4) This function does not check the instrument status.   Typically, you call this function only in a sequence of calls to other low-level driver functions.  The sequence performs one operation.  You use the low-level functions to optimize one or more aspects of interaction with the instrument.  If you want to check the instrument status, call the ag3446x_error_query function at the conclusion of the sequence.

SCPI Command:
FETC?    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    A    Returns the measured value.  The value you specify for the Measurement Function parameter of the ag3446x_ConfigureMeasurement function determines the units of this parameter as shown in the following table.

  DC Volts           - volts
  AC Volts           - volts
  DC Current         - amperes
  AC Current         - amperes
  2-Wire Resistance  - ohms
  4-Wire Resistance  - ohms
  Temperature (C)    - celcius
  Temperature (F)    - Fahrenheit
  Frequency          - hertz
  Period             - seconds
  Diode              - none
  Continuity         - none

Notes:

(1) If an over-range condition occurs, the Reading parameter contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE.  

(2) You can test the measurement value for over-range with the ag3446x_IsOverRange function.
    �    Pass the maximum length of time in which to allow the fetch operation to complete.  Express this value in milliseconds.  

If the operation does not complete within this time interval, the function returns the AG3446X_ERROR_MAX_TIME_EXCEEDED (0xBFFA2003) error code.  When this occurs, you can call ag3446x_Abort to cancel the fetch operation and return the instrument to the Idle state.  

Defined Values:
AG3446X_VAL_MAX_TIME_INFINITE (-1)            AG3446X_VAL_MAX_TIME_IMMEDIATE (0)       

Default Value: 5000 (ms)

Notes:

(1) The Maximum Time parameter affects only this function.  It has no effect on other timeout parameters or attributes.
   �#����  �    Status                           ��-   �  �    Instrument Handle                �D =0 �  �    Reading                          �� = l �  �    Maximum Time (ms)                  	               	           5000   �    This function returns an array of values from a previously initiated multi-point measurement.  The number of measurements the DMM takes is determined by the values you specify for the Trigger Count and Sample Count parameters of the ag3446x_ConfigureMultiPoint function.

You must first call the ag3446x_Initiate function to initiate a measurement before calling this function.

Notes:

(1) After this function executes, each element in the Reading Array parameter is an actual reading or a value indicating that an over-range condition occurred.

(2) If an over-range condition occurs, the corresponding Reading Array element contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE (0x3FFA2001). 

(3) You can test each element in the Reading Array parameter for over-range with the ag3446x_IsOverRange function.

(4) This function does not check the instrument status.   Typically, you call this function only in a sequence of calls to other low-level driver functions.  The sequence performs one operation.  You use the low-level functions to optimize one or more aspects of interaction with the instrument.  If you want to check the instrument status, call the ag3446x_error_query function at the conclusion of the sequence.    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    �    Returns an array of the most recent measurement values.  The value you specify for the Measurement Function parameter of the ag3446x_ConfigureMeasurement function determines the units of this parameter as shown in the following table.

  DC Volts           - volts
  AC Volts           - volts
  DC Current         - amperes
  AC Current         - amperes
  2-Wire Resistance  - ohms
  4-Wire Resistance  - ohms
  Temperature (C)    - celcius
  Temperature (F)    - Fahrenheit
  Frequency          - hertz
  Period             - seconds
  Diode              - none
  Continuity         - none

Notes:

(1) The size of the Reading Array must be at least the size you specify for the Array Size parameter.

(2) If an over-range condition occurs, the corresponding Reading Array element contains an IEEE defined NaN (Not a Number) value and the function returns AG3446X_WARN_OVER_RANGE. 

(3) You can test each element in the Reading Array parameter for over-range with the ag3446x_IsOverRange function.
     S    Pass the number of elements in the Reading Array parameter.

Default Value: None
     ]    Indicates the number of measured values the function places in the Reading Array parameter.    �    Pass the maximum length of time in which to allow the multi-point fetch operation to complete.  Express this value in milliseconds.  

If the operation does not complete within this time interval, the function returns the AG3446X_ERROR_MAX_TIME_EXCEEDED (0xBFFA2003) error code.  When this occurs, you can call ag3446x_Abort to cancel the multi-point fetch operation and return the instrument to the Idle state.  

Defined Values:
AG3446X_VAL_MAX_TIME_INFINITE (-1)           AG3446X_VAL_MAX_TIME_IMMEDIATE (0)          

Default Value: 5000 (ms)

Notes:

(1) The Maximum Time parameter affects only this function.  It has no effect on other timeout parameters or attributes.
   �#����  �    Status                           ��-   �  �    Instrument Handle                �O z0 �  �    Reading Array                    �B =0 �  �    Array Size                       �� �0 �  �    Actual Number of Points          � = l �  �    Maximum Time (ms)                  	               	                	            5000    D    This function returns the histogram measurement result (bin data).     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     �    Returns the histogram measurement result list of the bin data collected since the last time the histogram data was cleared.

SCPI Command:
CALCulate:TRANsform:HISTogram:DATA?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �n-   �  �    Instrument Handle                �% - � �  �    Readings                         ��#����  �    Status                                 	            	            �    This function returns a specified statistics measurement.

Notes:

(1) You must set "EnableAverage" control to true in ag3446x_ConfigureAverage function.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None     Y    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:SDEViation?     V    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:AVERage?     T    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:COUNt?     V    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:MAXimum?     V    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:MINimum?     U    Returns the statistics measurement result.

SCPI Command:
CALCulate:AVERage:PTPeak?    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   ǭ-   �  �    Instrument Handle                �d -  �  �    Standard Deviation Value         �� - � �  �    Average Value                    �# -� �  �    Count Value                      � �  �  �    Maximum Value                    �� � � �  �    Minimum Value                    �; �� �  �    Peak-To-Peak Value               ʘ#����  �    Status                                 	            	            	            	            	            	           	               This function aborts a previously initiated measurement and returns the DMM to the Idle state.

Notes:

(1) This function does not check the instrument status.   Typically, you call this function only in a sequence of calls to other low-level driver functions.  The sequence performs one operation.  You use the low-level functions to optimize one or more aspects of interaction with the instrument.  If you want to check the instrument status, call the ag3446x_error_query function at the conclusion of the sequence.    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   �#����  �    Status                           ۗ-   �  �    Instrument Handle                  	              W    This function takes a measurement value that you obtain from one of the Measure, Read, or Fetch functions and determines if the value is a valid measurement value or a value indicating an over-range condition occurred.  

Notes:

(1) If an over-range condition occurs, the measurement value contains an IEEE defined NaN (Not a Number) value.    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    �    Returns whether the measurement value is a valid measurement or a value indicating an over-range condition.

Valid values:
VI_TRUE  (1) - The value indicates that an over-range condition   
               occurred.
VI_FALSE (0) - The value is a valid measurement.

Notes:

(1) If an over-range condition occurs, the measurement value contains an IEEE defined NaN (Not a Number) floating point value.
    �    Pass the measurement value that you obtain from one of the Measure, Read, or Fetch functions.  The driver tests this value to determine if the value is a valid measurement value or a value indicating an over-range condition occurred.  

Default Value: None

Notes:

(1) If an over-range condition occurs, the measurement value contains an IEEE defined NaN (Not a Number) value indicating that an over-range occurred.
   �(#����  �    Status                           �-   �  �    Instrument Handle                �^ =F �  �    Is Over Range                    �� = N �  �    Measurement Value                  	               	               �    This function writes a command string directly to an instrument using VISA I/O. The function bypasses the attribute state caching mechanism and therefore always invalidates all attribute cache values for the session.

The function assumes that the IVI_ATTR_SYSTEM_IO_SESSION attribute for the IVI session you specify holds a valid VISA session for the instrument.

The function calls Ivi_SetNeedToCheckStatus with VI_TRUE.

Note: This function is supported with the IVI Compliance Package (ICP) 4.6.1 and later. If you are using an earlier version of ICP, you can still use the WriteInstrData and ReadInstrData functions under the Obsolete folder.
     9    Specify the string you want to send to the instrument.
     0    Returns the number of bytes actually written.
     �    Specifies the number of bytes to write to the instrument. The value of this parameter must be less than or equal to the size of buffer.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function. The handle identifies a particular instrument session.

Default Value:  None    �    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �) -  �  �    Write Buffer                     �j -� �  �    Number of Bytes Written          � - � �  �    Number of Bytes to Write         �4   �  �    Instrument Handle                ������  �    Status                             ""    	                    	               This function reads data directly from an instrument using VISA I/O. The function bypasses the attribute state caching mechanism.

The function assumes that the IVI_ATTR_SYSTEM_IO_SESSION attribute for the IVI session you specify holds a valid VISA session for the instrument.

If data is not available at the instrument's output buffer when you call this function, the instrument might hang up. In that case, the function does not return until the VISA I/O call times out. If you have disabled the timeout, the function hangs indefinitely.

Note: This function is supported with the IVI Compliance Package (ICP) 4.6.1 and later. If you are using an earlier version of ICP, you can still use the WriteInstrData and ReadInstrData functions under the Obsolete folder.
    �    Specify the maximum number of bytes to read from the instrument. The Read Buffer parameter must be a ViChar buffer that contains at least the number of bytes you specify.

If the number of bytes you specify is less than the number of bytes in the instrument's output buffer, you must call this function again to empty the output buffer. If you do not empty the instrument's output buffer, the instrument might return invalid data in response to subsequent requests.

If data is not available at the instrument's output buffer when you call this function, the instrument might hang up. In that case, the function does not return until the VISA I/O call times out. If you have disabled the timeout, the function hangs indefinitely.
    j    A buffer in which the function places the data it receives from the instrument.

The buffer must be a ViChar array that has at least as many bytes as you specify in the Number Bytes To Read parameter.

This function does not write an ASCII NUL byte to terminate the data, nor does it clear the buffer beyond the bytes it actually receives from the instrument.
    �    This control returns the actual number of bytes the function received from the instrument. This is the value that the VISA viRead function returns.

If the actual number of bytes received is less than the number of bytes you specify in the Number Bytes To Read parameter, the instrument's output buffer has probably emptied.

If the number of bytes received is 0, the most probable cause is that no data was available at the instrument's output buffer.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function. The handle identifies a particular instrument session.

Default Value:  None    �    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   �� -  �  �    Number of Bytes to Read          �� - � �  �    Read Buffer                      � -� �  �    Number of Bytes Read             ��   �  �    Instrument Handle                ������  �    Status                                 	            	                	          &    This function resets the instrument to a known state and sends initialization commands to the instrument.  The initialization commands set instrument settings such as Headers Off, Short Command form, and Data Transfer Binary to the state necessary for the operation of the instrument driver.
    s    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   �#����  �    Status                           �-   �  �    Instrument Handle                  	                   This function resets the instrument and applies initial user specified settings from the Logical Name which was used to initialize the session.  If the session was created without a Logical Name, this function is equivalent to the ag3446x_reset function.    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   6#����  �    Status                           �-   �  �    Instrument Handle                  	               ,    This function clears the calculation data.     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None        Selects the operation to clear the measurement data. The driver uses this value to set the AG3446X_ATTR_CLEAR_OPER attribute.

Valid Values:
AG3446X_VAL_CLEAR_ALL   -  Clear All. Clears all limits, histogram data, statistics, and measurement data.
AG3446X_VAL_CLEAR_LIMIT   -  Clear Limit Data. Clears front panel indications of limits being exceeded and clears bit 11 ("Lower Limit Failed") and bit 12 ("Upper Limit Failed") in the Condition Register of the Questionable Data Register event register group. The corresponding event register bits are unaffected.
AG3446X_VAL_CLEAR_HIST   -  Clear Histogram Data. Clears the histogram data and restarts histogram ranging if it is enabled
AG3446X_VAL_CLEAR_AVER   -  Clear Average Data. Clears all computed statistics: minimum, maximum, average, peak-to-peak, count and standard deviation.

Default Value: AG3446X_VAL_CLEAR_ALL

SCPI Command:
CALCulate:CLEar[:IMMediate]
CALCulate:TRANsform:HISTogram:CLEar[:IMMediate]
CALCulate:AVERage:CLEar[:IMMediate]
CALCulate:LIMit:CLEar[:IMMediate]    j    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors   -   �  �    Instrument Handle                � - � � �    Clear Operation                  �#����  �    Status                                            �Clear All AG3446X_VAL_CLEAR_ALL Clear Limit Data AG3446X_VAL_CLEAR_LIMIT Clear Histogram Data AG3446X_VAL_CLEAR_HIST Clear Average Data AG3446X_VAL_CLEAR_AVER    	            �    This function places the instrument in a quiescent state where it has minimal or no impact on the system to which it is connected.    t    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   $A#����  �    Status                           *�-   �  �    Instrument Handle                  	               Z    This function runs the instrument's self test routine and returns the test result(s). 

    &    This control contains the value returned from the instrument self test.  Zero means success.  For any other code, see the device's operator's manual.

Self-Test Code    Description
---------------------------------------
   0              Passed self test
   1              Self test failed

     �    Returns the self-test response string from the instrument. See the device's operation manual for an explanation of the string's contents.

You must pass a ViChar array with at least 256 bytes.    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   ,Q =  �  �    Self Test Result                 - = � � ,    Self-Test Message                .I#����  �    Status                           4�-   �  �    Instrument Handle                  	           	            	               `    This function returns the revision numbers of the instrument driver and instrument firmware.

     �    Returns the instrument driver software revision numbers in the form of a string.

You must pass a ViChar array with at least 256 bytes.     �    Returns the instrument firmware revision numbers in the form of a string.

You must pass a ViChar array with at least 256 bytes.
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   6� = 3 �  �    Instrument Driver Revision       7t =6 �  �    Firmware Revision                7�#����  �    Status                           >|-   �  �    Instrument Handle                  	            	            	               V    This function reads an error code and a message from the instrument's error queue.

     B    Returns the error code read from the instrument's error queue.

     �    Returns the error message string read from the instrument's error message queue.

You must pass a ViChar array with at least 256 bytes.
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   @� =  �  �    Error Code                       @� = � � ,    Error Message                    Aj#����  �    Status                           G�-   �  �    Instrument Handle                  	           	            	               n    This function converts a status code returned by an instrument driver function into a user-readable string.     %w    Pass the Status parameter that is returned from any of the instrument driver functions.
          
Default Value:  0  (VI_SUCCESS)
          
ag3446x Status Codes:
Status    Description
-------------------------------------------------
No defined status codes: 

IviDmm Status Codes:
Status    Description
-------------------------------------------------
WARNINGS:
3FFA2001  Over range condition.
          
ERRORS:
BFFA1001  The trigger source is not software trigger.
BFFA2003  Maximum operation time was exceeded.

IVI Engine Status Codes:
Status    Description
-------------------------------------------------
ERRORS:
BFFA0001  Instrument error. Call ag3446x_error_query.
BFFA0002  Cannot open file.
BFFA0003  Error reading from file.
BFFA0004  Error writing to file.
BFFA0005  Driver module file not found.
BFFA0006  Cannot open driver module file for reading.
BFFA0007  Driver module has invalid file format or invalid data.
BFFA0008  Driver module contains undefined references.
BFFA0009  Cannot find function in driver module.
BFFA000A  Failure loading driver module.
BFFA000B  Invalid path name.
BFFA000C  Invalid attribute.
BFFA000D  IVI attribute is not writable.
BFFA000E  IVI attribute is not readable.
BFFA000F  Invalid parameter.
BFFA0010  Invalid value.
BFFA0011  Function not supported.
BFFA0012  Attribute not supported.
BFFA0013  Value not supported.
BFFA0014  Invalid type.
BFFA0015  Types do not match.
BFFA0016  Attribute already has a value waiting to be updated.
BFFA0017  Specified item already exists.
BFFA0018  Not a valid configuration.
BFFA0019  Requested item does not exist or value not available.
BFFA001A  Requested attribute value not known.
BFFA001B  No range table.
BFFA001C  Range table is invalid.
BFFA001D  Object or item is not initialized.
BFFA001E  Non-interchangeable behavior.
BFFA001F  No channel table has been built for the session.
BFFA0020  Channel name specified is not valid.
BFFA0021  Unable to allocate system resource.
BFFA0022  Permission to access file was denied.
BFFA0023  Too many files are already open.
BFFA0024  Unable to create temporary file in target directory.
BFFA0025  All temporary filenames already used.
BFFA0026  Disk is full.
BFFA0027  Cannot find configuration file on disk.
BFFA0028  Cannot open configuration file.
BFFA0029  Error reading configuration file.
BFFA002A  Invalid ViInt32 value in configuration file.
BFFA002B  Invalid ViReal64 value in configuration file.
BFFA002C  Invalid ViBoolean value in configuration file.
BFFA002D  Entry missing from configuration file.
BFFA002E  Initialization failed in driver DLL.
BFFA002F  Driver module has unresolved external reference.
BFFA0030  Cannot find CVI Run-Time Engine.
BFFA0031  Cannot open CVI Run-Time Engine.
BFFA0032  CVI Run-Time Engine has invalid format.
BFFA0033  CVI Run-Time Engine is missing required function(s).
BFFA0034  CVI Run-Time Engine initialization failed.
BFFA0035  CVI Run-Time Engine has unresolved external reference.
BFFA0036  Failure loading CVI Run-Time Engine.
BFFA0037  Cannot open DLL for read exports.
BFFA0038  DLL file is corrupt.
BFFA0039  No DLL export table in DLL.
BFFA003A  Unknown attribute name in default configuration file.
BFFA003B  Unknown attribute value in default configuration file.
BFFA003C  Memory pointer specified is not known.
BFFA003D  Unable to find any channel strings.
BFFA003E  Duplicate channel string.
BFFA003F  Duplicate virtual channel name.
BFFA0040  Missing virtual channel name.
BFFA0041  Bad virtual channel name.
BFFA0042  Unassigned virtual channel name.
BFFA0043  Bad virtual channel assignment.
BFFA0044  Channel name required.
BFFA0045  Channel name not allowed.
BFFA0046  Attribute not valid for channel.
BFFA0047  Attribute must be channel based.
BFFA0048  Channel already excluded.
BFFA0049  Missing option name (nothing before the '=').
BFFA004A  Missing option value (nothing after the '=').
BFFA004B  Bad option name.
BFFA004C  Bad option value.
BFFA004D  Operation only valid on a class driver session.
BFFA004E  "ivi.ini" filename is reserved.
BFFA004F  Duplicate run-time configuration entry.
BFFA0050  Index parameter is one-based.
BFFA0051  Index parameter is too high.
BFFA0052  Attribute is not cacheable.
BFFA0053  You cannot export a ViAddr attribute to the end-user.
BFFA0054  Bad channel string in channel string list.
BFFA0055  Bad prefix name in default configuration file.
         
VISA Status Codes:
Status    Description
-------------------------------------------------
WARNINGS:
3FFF0002 Event enabled for one or more specified mechanisms.
3FFF0003 Event disabled for one or more specified mechanisms.
3FFF0004 Successful, but queue already empty.
3FFF0005 Specified termination character was read.
3FFF0006 Number of bytes transferred equals input count.
3FFF0077 Configuration non-existant or could not be loaded.
3FFF007D Open successful, but the device not responding.
3FFF0080 Wait successful, but more event objects available.
3FFF0082 Specified object reference is uninitialized.
3FFF0084 Attribute value not supported.
3FFF0085 Status code could not be interpreted.
3FFF0088 Specified I/O buffer type not supported.
3FFF0098 Successful,  but invoke no handlers for this event.
3FFF0099 Successful but session has nested shared locks.
3FFF009A Successful but session has nested exclusive locks.
3FFF009B Successful but operation not asynchronous.
         
ERRORS:
BFFF0000 Unknown system error (miscellaneous error).
BFFF000E Session or object reference is invalid.
BFFF000F Resource is locked.
BFFF0010 Invalid expression specified for search.
BFFF0011 Resource is not present in the system.
BFFF0012 Invalid resource reference specified.  Parsing error.
BFFF0013 Invalid access mode.
BFFF0015 Timeout expired before operation completed.
BFFF0016 Unable to deallocate session data structures.
BFFF001B Specified degree is invalid.
BFFF001C Specified job identifier is invalid.
BFFF001D Attribute is not supported by the referenced object.
BFFF001E Attribute state not supported by the referenced object.
BFFF001F Specified attribute is read-only.
BFFF0020 Lock type lock not supported by this resource.
BFFF0021 Invalid access key.
BFFF0026 Specified event type not supported by the resource.
BFFF0027 Invalid mechanism specified.
BFFF0028 A handler was not installed.
BFFF0029 Handler reference either invalid or was not installed.
BFFF002A Specified event context invalid.
BFFF002D Event queue for specified type has overflowed.
BFFF002F Event type must be enabled in order to receive.
BFFF0030 User abort during transfer.
BFFF0034 Violation of raw write protocol during transfer.
BFFF0035 Violation of raw read protocol during transfer.
BFFF0036 Device reported output protocol error during transfer.
BFFF0037 Device reported input protocol error during transfer.
BFFF0038 Bus error during transfer.
BFFF0039 Unable to queue asynchronous operation.
BFFF003A Unable to start operation because setup is invalid.
BFFF003B Unable to queue the asynchronous operation.
BFFF003C Insufficient resources to perform memory allocation.
BFFF003D Invalid buffer mask specified.
BFFF003E I/O error.
BFFF003F Format specifier invalid.
BFFF0041 Format specifier not supported.
BFFF0042 Trigger line is currently in use.
BFFF004A Service request not received for the session.
BFFF004E Invalid address space specified.
BFFF0051 Invalid offset specified.
BFFF0052 Invalid access width specified.
BFFF0054 Offset not accessible from this hardware.
BFFF0055 Source and destination widths are different.
BFFF0057 Session not currently mapped.
BFFF0059 Previous response still pending.
BFFF005F No listeners condition detected.
BFFF0060 Interface not currently the controller in charge.
BFFF0061 Interface not the system controller.
BFFF0067 Session does not support this operation.
BFFF006A A parity error occurred during transfer.
BFFF006B A framing error occurred during transfer.
BFFF006C An overrun error occurred during transfer.
BFFF0070 Offset not properly aligned for operation access width.
BFFF0071 Specified user buffer not valid.
BFFF0072 Resource valid, but VISA cannot access it.
BFFF0076 Width not supported by this hardware.
BFFF0078 Invalid parameter value, parameter unknown.
BFFF0079 Invalid protocol.
BFFF007B Invalid window size.
BFFF0080 Session currently contains a mapped window.
BFFF0081 Operation not implemented.
BFFF0083 Invalid length.
BFFF0091 Invalid mode.
BFFF009C Session did not have a lock on the resource.
BFFF009D The device does not export any memory.
BFFF009E VISA-required code library not located or not loaded.
         
VXIPnP Driver Status Codes:
Status    Description
-------------------------------------------------
WARNINGS:
3FFC0101  Instrument does not have ID Query capability.
3FFC0102  Instrument does not have Reset capability.
3FFC0103  Instrument does not have Self-Test capability.
3FFC0104  Instrument does not have Error Query capability.
3FFC0105  Instrument does not have Revision Query capability.
          
ERRORS:
BFFC0001  Parameter 1 out of range, or error trying to set it.
BFFC0002  Parameter 2 out of range, or error trying to set it.
BFFC0003  Parameter 3 out of range, or error trying to set it.
BFFC0004  Parameter 4 out of range, or error trying to set it.
BFFC0005  Parameter 5 out of range, or error trying to set it.
BFFC0006  Parameter 6 out of range, or error trying to set it.
BFFC0007  Parameter 7 out of range, or error trying to set it.
BFFC0008  Parameter 8 out of range, or error trying to set it.
BFFC0011  Instrument failed the ID Query.
BFFC0012  Invalid response from instrument.     �    Returns the user-readable message string that corresponds to the status code you specify.

You must pass a ViChar array with at least 256 bytes.
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

        The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

You can pass VI_NULL for this parameter.  This is useful when one of the initialize functions fail.

Default Value:  VI_NULL
   J =  �  h    Error Code                       o� = � � �    Error Message                    p+#����  �    Status                           v�-   �  �    Instrument Handle                  0    	            	               P    This function invalidates the cached values of all attributes for the session.    t    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   y#����  �    Status                           �-   �  �    Instrument Handle                  	              �    This function retrieves and then clears the IVI error information for the session or the current execution thread. One exception exists: If the BufferSize parameter is 0, the function does not clear the error information. By passing 0 for the buffer size, the caller can ascertain the buffer size required to get the entire error description string and then call the function again with a sufficiently large buffer.

If the user specifies a valid IVI session for the InstrumentHandle parameter, Get Error retrieves and then clears the error information for the session.  If the user passes VI_NULL for the InstrumentHandle parameter, this function retrieves and then clears the error information for the current execution thread.  If the InstrumentHandle parameter is an invalid session, the function does nothing and returns an error. Normally, the error information describes the first error that occurred since the user last called ag3446x_GetError or ag3446x_ClearError.
    �    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

If the current value of the return buffer, including the terminating NUL byte, is larger than the size you indicate in the Buffer Size parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    �    Pass the number of bytes in the ViChar array you specify for the Description parameter.

If the error description, including the terminating NUL byte, contains more bytes than you indicate in this parameter, the function copies BufferSize - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you pass a negative number, the function copies the value to the buffer regardless of the number of bytes in the value.

If you pass 0, you can pass VI_NULL for the Description buffer parameter.

Default Value:  None     �    Returns the error code for the session or execution thread.

If you pass 0 for the Buffer Size, you can pass VI_NULL for this parameter.
    �    Returns the error description for the IVI session or execution thread.  If there is no description, the function returns an empty string.

The buffer must contain at least as many elements as the value you specify with the Buffer Size parameter.  If the error description, including the terminating NUL byte, contains more bytes than you indicate with the Buffer Size parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you pass 0 for the Buffer Size, you can pass VI_NULL for this parameter.   ��#����  �    Status                           ��-   �  �    Instrument Handle                �; 3< �  �    BufferSize                       � 3 P �  �    Code                             �� � Q � �    Description                        	                   	           	           a    This function clears the error code and error description for the IVI session. If the user specifies a valid IVI session for the InstrumentHandle parameter, this function clears the error information for the session. If the user passes VI_NULL for the Vi parameter, this function clears the error information for the current execution thread. If the Vi parameter is an invalid session, the function does nothing and returns an error.
The function clears the error code by setting it to VI_SUCCESS.  If the error description string is non-NULL, the function de-allocates the error description string and sets the address to VI_NULL.

Maintaining the error information separately for each thread is useful if the user does not have a session handle to pass to the ag3446x_GetError function, which occurs when a call to ag3446x_init or ag3446x_InitWithOptions fails.    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   �H#����  �    Status                           ��-   �  �    Instrument Handle                  	              �    This function returns the coercion information associated with the IVI session.  This function retrieves and clears the oldest instance in which the instrument driver coerced a value you specified to another value.

If you set the AG3446X_ATTR_RECORD_COERCIONS attribute to VI_TRUE, the instrument driver keeps a list of all coercions it makes on ViInt32 or ViReal64 values you pass to instrument driver functions.  You use this function to retrieve information from that list.

If the next coercion record string, including the terminating NUL byte, contains more bytes than you indicate in this parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you pass a negative number, the function copies the value to the buffer regardless of the number of bytes in the value.

If you pass 0, you can pass VI_NULL for the Coercion Record buffer parameter.

The function returns an empty string in the Coercion Record parameter if no coercion records remain for the session.

    4    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

If the current value of the return buffer, including the terminating NUL byte, is larger than the size you indicate in the Buffer Size parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init function.  The handle identifies a particular instrument session.

Default Value:  None    �    Returns the next coercion record for the IVI session.  If there are no coercion records, the function returns an empty string.

The buffer must contain at least as many elements as the value you specify with the Buffer Size parameter.  If the next coercion record string, including the terminating NUL byte, contains more bytes than you indicate with the Buffer Size parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

This parameter returns an empty string if no coercion records remain for the session.
    �    Pass the number of bytes in the ViChar array you specify for the Coercion Record parameter.

If the next coercion record string, including the terminating NUL byte, contains more bytes than you indicate in this parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you pass a negative number, the function copies the value to the buffer regardless of the number of bytes in the value.

If you pass 0, you can pass VI_NULL for the Coercion Record buffer parameter.

Default Value:  None

   ��#����  �    Status or Required Size          �
-   �  �    Instrument Handle                �� � Q � �    Coercion Record                  �� = � �  �    Buffer Size                        	               	               .    This function returns the interchangeability warnings associated with the IVI session. It retrieves and clears the oldest instance in which the class driver recorded an interchangeability warning.  Interchangeability warnings indicate that using your application with a different instrument might cause different behavior. You use this function to retrieve interchangeability warnings.

The driver performs interchangeability checking when the AG3446X_ATTR_INTERCHANGE_CHECK attribute is set to VI_TRUE.

The function returns an empty string in the Interchange Warning parameter if no interchangeability warnings remain for the session.

In general, the instrument driver generates interchangeability warnings when an attribute that affects the behavior of the instrument is in a state that you did not specify.
        Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

If the current value of the return buffer, including the terminating NUL byte, is larger than the size you indicate in the Buffer Size parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

To obtain a text description of the status code, or if the status code is not listed below, call the ag3446x_error_message function.  To obtain additional information about the error condition, use the ag3446x_GetError and ag3446x_ClearError functions.

The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    �    Pass the number of bytes in the ViChar array you specify for the Interchange Warning parameter.

If the next interchangeability warning string, including the terminating NUL byte, contains more bytes than you indicate in this parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value. For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

If you pass a negative number, the function copies the value to the buffer regardless of the number of bytes in the value.

If you pass 0, you can pass VI_NULL for the Interchange Warning buffer parameter.

Default Value:  None
        Returns the next interchange warning for the IVI session. If there are no interchange warnings, the function returns an empty  string.

The buffer must contain at least as many elements as the value you specify with the Buffer Size parameter. If the next interchangeability warning string, including the terminating NUL byte, contains more bytes than you indicate with the Buffer Size parameter, the function copies Buffer Size - 1 bytes into the buffer, places an ASCII NUL byte at the end of the buffer, and returns the buffer size you must pass to get the entire value.  For example, if the value is "123456" and the Buffer Size is 4, the function places "123" into the buffer and returns 7.

This parameter returns an empty string if no interchangeability
warnings remain for the session.

   ��#����  �    Status or Required Size          ��-   �  �    Instrument Handle                �� = � �  �    Buffer Size                      å � Q � �    Interchange Warning                	                   	            A    This function clears the list of current interchange warnings.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    t    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors
   �-   �  �    Instrument Handle                Ⱦ#����  �    Status                                 	          �    When developing a complex test system that consists of multiple test modules, it is generally a good idea to design the test modules so that they can run in any order.  To do so requires ensuring that each test module completely configures the state of each instrument it uses.  If a particular test module does not completely configure the state of an instrument, the state of the instrument depends on the configuration from a previously executed test module.  If you execute the test modules in a different order, the behavior of the instrument and therefore the entire test module is likely to change.  This change in behavior is generally instrument specific and represents an interchangeability problem.

You can use this function to test for such cases.  After you call this function, the interchangeability checking algorithms in the specific driver ignore all previous configuration operations.  By calling this function at the beginning of a test module, you can determine whether the test module has dependencies on the operation of previously executed test modules.

This function does not clear the interchangeability warnings from the list of previously recorded interchangeability warnings.  If you want to guarantee that the ag3446x_GetNextInterchangeWarning function only returns those interchangeability warnings that are generated after calling this function, you must clear the list of interchangeability warnings.  You can clear the interchangeability warnings list by repeatedly calling the ag3446x_GetNextInterchangeWarning function until no more interchangeability warnings are returned.  If you are not interested in the content of those warnings, you can call the ag3446x_ClearInterchangeWarnings function.
     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors
   փ-   �  �    Instrument Handle                �;#����  �    Status                                 	          .    This function obtains a multithread lock on the instrument session.  Before it does so, it waits until all other execution threads have released their locks on the instrument session.

Other threads might have obtained a lock on this session in the following ways:

- The user's application called ag3446x_LockSession.

- A call to the instrument driver locked the session.

- A call to the IVI engine locked the session.

After your call to ag3446x_LockSession returns successfully, no other threads can access the instrument session until you call ag3446x_UnlockSession.

Use ag3446x_LockSession and ag3446x_UnlockSession around a sequence of calls to instrument driver functions if you require that the instrument retain its settings through the end of the sequence.

You can safely make nested calls to ag3446x_LockSession within the same thread.  To completely unlock the session, you must balance each call to ag3446x_LockSession with a call to ag3446x_UnlockSession.  If, however, you use the Caller Has Lock parameter in all calls to ag3446x_LockSession and ag3446x_UnlockSession within a function, the IVI Library locks the session only once within the function regardless of the number of calls you make to ag3446x_LockSession.  This allows you to call ag3446x_UnlockSession just once at the end of the function. 
    v    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:          
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    �    This parameter serves as a convenience.  If you do not want to use this parameter, pass VI_NULL. 

Use this parameter in complex functions to keep track of whether you obtain a lock and therefore need to unlock the session.  Pass the address of a local ViBoolean variable.  In the declaration of the local variable, initialize it to VI_FALSE.  Pass the address of the same local variable to any other calls you make to ag3446x_LockSession or ag3446x_UnlockSession in the same function.

The parameter is an input/output parameter.  ag3446x_LockSession and ag3446x_UnlockSession each inspect the current value and take the following actions:

- If the value is VI_TRUE, ag3446x_LockSession does not lock the session again.  If the value is VI_FALSE, ag3446x_LockSession obtains the lock and sets the value of the parameter to VI_TRUE.

- If the value is VI_FALSE, ag3446x_UnlockSession does not attempt to unlock the session.  If the value is VI_TRUE, ag3446x_UnlockSession releases the lock and sets the value of the parameter to VI_FALSE.
 
Thus, you can, call ag3446x_UnlockSession at the end of your function without worrying about whether you actually have the lock.  

Example:

ViStatus TestFunc (ViSession vi, ViInt32 flags)
{
    ViStatus error = VI_SUCCESS;
    ViBoolean haveLock = VI_FALSE;

    if (flags & BIT_1)
        {
        viCheckErr( ag3446x_LockSession(vi, &haveLock));
        viCheckErr( TakeAction1(vi));
        if (flags & BIT_2)
            {
            viCheckErr( ag3446x_UnlockSession(vi, &haveLock));
            viCheckErr( TakeAction2(vi));
            viCheckErr( ag3446x_LockSession(vi, &haveLock);
            } 
        if (flags & BIT_3)
            viCheckErr( TakeAction3(vi));
        }

Error:
    /* 
       At this point, you cannot really be sure that 
       you have the lock.  Fortunately, the haveLock 
       variable takes care of that for you.          
    */
    ag3446x_UnlockSession(vi, &haveLock);
    return error;
}   �h#����  �    Status                           ��-   �  �    Instrument Handle                � H � �  �    Caller Has Lock                    	               	            �    This function releases a lock that you acquired on an instrument session using ag3446x_LockSession.  Refer to ag3446x_LockSession for additional information on session locks.
    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
    �    This parameter serves as a convenience.  If you do not want to use this parameter, pass VI_NULL. 

Use this parameter in complex functions to keep track of whether you obtain a lock and therefore need to unlock the session. 
Pass the address of a local ViBoolean variable.  In the declaration of the local variable, initialize it to VI_FALSE.  Pass the address of the same local variable to any other calls you make to ag3446x_LockSession or ag3446x_UnlockSession in the same function.

The parameter is an input/output parameter.  ag3446x_LockSession and ag3446x_UnlockSession each inspect the current value and take the following actions:

- If the value is VI_TRUE, ag3446x_LockSession does not lock the session again.  If the value is VI_FALSE, ag3446x_LockSession obtains the lock and sets the value of the parameter to VI_TRUE.

- If the value is VI_FALSE, ag3446x_UnlockSession does not attempt to unlock the session.  If the value is VI_TRUE, ag3446x_UnlockSession releases the lock and sets the value of the parameter to VI_FALSE.
 
Thus, you can, call ag3446x_UnlockSession at the end of your function without worrying about whether you actually have the lock.  

Example:

ViStatus TestFunc (ViSession vi, ViInt32 flags)
{
    ViStatus error = VI_SUCCESS;
    ViBoolean haveLock = VI_FALSE;

    if (flags & BIT_1)
        {
        viCheckErr( ag3446x_LockSession(vi, &haveLock));
        viCheckErr( TakeAction1(vi));
        if (flags & BIT_2)
            {
            viCheckErr( ag3446x_UnlockSession(vi, &haveLock));
            viCheckErr( TakeAction2(vi));
            viCheckErr( ag3446x_LockSession(vi, &haveLock);
            } 
        if (flags & BIT_3)
            viCheckErr( TakeAction3(vi));
        }

Error:
    /* 
       At this point, you cannot really be sure that 
       you have the lock.  Fortunately, the haveLock 
       variable takes care of that for you.          
    */
    ag3446x_UnlockSession(vi, &haveLock);
    return error;
}   ��#����  �    Status                           �R-   �  �    Instrument Handle                �
 H � �  �    Caller Has Lock                    	               	           �    This function performs the following operations:

- Closes the instrument I/O session.

- Destroys the instrument driver session and all of its attributes.

- Deallocates any memory resources the driver uses.

Notes:

(1) You must unlock the session before calling ag3446x_close.

(2) After calling ag3446x_close, you cannot use the instrument driver again until you call ag3446x_init or ag3446x_InitWithOptions.

    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   0#����  �    Status                           �-   �  �    Instrument Handle                  	               �    This function writes a user-specified string to the instrument.

Note:  This function bypasses IVI attribute state caching.  Therefore, when you call this function, the cached values for all attributes will be invalidated.     2    Pass the string to be written to the instrument.    s    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
   � = � �  �    Write Buffer                     #����  �    Status                           |-   �  �    Instrument Handle                      	               /    This function reads data from the instrument.     c    After this function executes, this parameter contains the data that was read from the instrument.    u    Returns the status code of this operation.  The status code  either indicates success or describes an error or warning condition.  You examine the status code from each call to an instrument driver function to determine if an error occurred.

To obtain a text description of the status code, call the ag3446x_error_message function.  To obtain additional information about the error condition, call the ag3446x_GetError function.  To clear the error information from the driver, call the ag3446x_ClearError function.
          
The general meaning of the status code is as follows:

Value                  Meaning
-------------------------------
0                      Success
Positive Values        Warnings
Negative Values        Errors

This driver defines the following status codes:
          
Status    Description
-------------------------------------------------
WARNINGS:         
This instrument driver also returns errors and warnings defined by other sources.  The following table defines the ranges of additional status codes that this driver can return.  The table lists the different include files that contain the defined constants for the particular status codes:
          
Numeric Range (in Hex)   Status Code Types    
-------------------------------------------------
3FFA2000 to 3FFA3FFF     IviDmm   Warnings
3FFA0000 to 3FFA1FFF     IVI      Warnings
3FFF0000 to 3FFFFFFF     VISA     Warnings
3FFC0000 to 3FFCFFFF     VXIPnP   Driver Warnings
          
BFFA2000 to BFFA3FFF     IviDmm   Errors
BFFA0000 to BFFA1FFF     IVI      Errors
BFFF0000 to BFFFFFFF     VISA     Errors
BFFC0000 to BFFCFFFF     VXIPnP   Driver Errors

     �    The ViSession handle that you obtain from the ag3446x_init or ag3446x_InitWithOptions function.  The handle identifies a particular instrument session.

Default Value:  None
     �    Pass the maximum number of bytes to read from the instruments.  

Valid Range:  0 to the number of elements in the Read Buffer.

Default Value:  0

     ^    Returns the number of bytes actually read from the instrument and stored in the Read Buffer.    = �  �    Read Buffer                      �#����  �    Status                           -   �  �    Instrument Handle                � = C �  �    Number of Bytes To Read          \ �' �  �    Num Bytes Read                     	            	               0    	         ����         �  -�             K.        init                                                                                                                                    ����         /�  R�             K.        InitWithOptions                                                                                                                         ����         T�  |�             K.        ConfigureMeasurement                                                                                                                    ����         �  �             K.        ConfigureSecondaryMeasurement                                                                                                           ����         �4  ��             K.        ConfigureACBandwidth                                                                                                                    ����         ��  �n             K.        ConfigureFrequencyVoltageRange                                                                                                          ����         �%  �h             K.        ConfigureFrequencyTimeout                                                                                                               ����         �6  ��             K.        ConfigureTransducerType                                                                                                                 ����         �/  �W             K.        ConfigureRTD                                                                                                                            ����         �J  ��             K.        ConfigureRTDAdvanced                                                                                                                    ����         �  �~             K.        ConfigureThermistor                                                                                                                     ����         �5  �             K.        ConfigureThermocouple                                                                                                                   ����         �  �d             K.        ConfigureFixedRefJunction                                                                                                               ����         � 	^             K.        ConfigureThermocoupleCheckEnabled                                                                                                       ����        
, i             K.        ConfigureRefJunctionOffsetAdjustment                                                                                                    ����         h             K.        ConfigureThermistorPowerLimit                                                                                                           ����        6 /�             K.        ConfigureTrigger                                                                                                                        ����        18 ;J             K.        ConfigureTriggerSlope                                                                                                                   ����        <D G�             K.        ConfigureTriggerLevel                                                                                                                   ����        H� Z              K.        ConfigureMultiPoint                                                                                                                     ����        [� e=             K.        ConfigureMeasCompleteDest                                                                                                               ����        f tq             K.        ConfigurePretrigger                                                                                                                     ����        u% ��             K.        Calibrate                                                                                                                               ����        �7 ��             K.        CalibrateADC                                                                                                                            ����        �� ��             K.        ConfigureCalibrationSecurity                                                                                                            ����        �� �8             K.        ConfigureDataTransition                                                                                                                 ����        �� ��             K.        ConfigureDirectory                                                                                                                      ����        �~ �V             K.        ConfigureFile                                                                                                                           ����        �	 ��             K.        ConfigurePreferenceFile                                                                                                                 ����        �a ֹ             K.        ConfigureStateFile                                                                                                                      ����        ث ��             K.        ConfigureReadingMemory                                                                                                                  ����        �~ �s             K.        QueryFileList                                                                                                                           ����        �� ��             K.        ValidateStateFile                                                                                                                       ����        �� T             K.        ConfigureDataTransitionFormat                                                                                                           ����         �             K.        ConfigureAutoZeroMode                                                                                                                   ����        
 �             K.        ConfigureAverage                                                                                                                        ����        � )(             K.        ConfigureLimit                                                                                                                          ����        *n ?�             K.        ConfigureScale                                                                                                                          ����        Cu N�             K.        ConfigureScaleAdvanced                                                                                                                  ����        P' ZK             K.        ConfigureScaleUnit                                                                                                                      ����        [T k�             K.        ConfigureHistogram                                                                                                                      ����        n w�             K.        ConfigureCurrentTerminals                                                                                                               ����        x� �*             K.        ConfigureVoltageImpedance                                                                                                               ����        �� �?             K.        ConfigureNullOperation                                                                                                                  ����        �� �Y             K.        ConfigureMeasurementTriggerParameters                                                                                                   ����        �3 �s             K.        ConfigureSmoothing                                                                                                                      ����        � �7             K.        ConfigureTrendChartEnabled                                                                                                              ����        � �"             K.        ConfigureResistance                                                                                                                     ����        �D Х             K.        ConfigureRangeChangeMode                                                                                                                ����        ѯ �`             K.        GetAutoRangeValue                                                                                                                       ����        � �W             K.        GetApertureTimeInfo                                                                                                                     ����        �S               K.        ConfigureApertureTime                                                                                                                   ����        V =             K.        SetAttributeViInt32                                                                                                                     ����        � *�             K.        SetAttributeViReal64                                                                                                                    ����        ,\ @F             K.        SetAttributeViString                                                                                                                    ����        A� U�             K.        SetAttributeViBoolean                                                                                                                   ����        Wg kQ             K.        SetAttributeViSession                                                                                                                   ����        l� |�             K.        GetAttributeViInt32                                                                                                                     ����        }� ��             K.        GetAttributeViReal64                                                                                                                    ����        �� �H             K.        GetAttributeViString                                                                                                                    ����        �� ��             K.        GetAttributeViBoolean                                                                                                                   ����        �� ˎ             K.        GetAttributeViSession                                                                                                                   ����        �� �N             K.        CheckAttributeViInt32                                                                                                                   ����        �� �o             K.        CheckAttributeViReal64                                                                                                                  ����        �
 ��             K.        CheckAttributeViString                                                                                                                  ����         * �             K.        CheckAttributeViBoolean                                                                                                                 ����        M  �             K.        CheckAttributeViSession                                                                                                                 ����        "o 1�             K.        Read                                                                                                                                    ����        2� Du             K.        ReadMultiPoint                                                                                                                          ����        E� N>             K.        ReadHistogramMeasurement                                                                                                                ����        N� Y]             K.        ReadStatisticsMeasurement                                                                                                               ����        [] c             K.        ReadLastMeasurement                                                                                                                     ����        c� k�             K.        ReadMeasurementCount                                                                                                                    ����        lh v             K.        ReadMeasurementMemory                                                                                                                   ����        wL ��             K.        ReadSecondaryMeasurement                                                                                                                ����        �� �S             K.        Initiate                                                                                                                                ����        �� �z             K.        SendSoftwareTrigger                                                                                                                     ����        �� �!             K.        Fetch                                                                                                                                   ����        � ��             K.        FetchMultiPoint                                                                                                                         ����        �" �O             K.        FetchHistogramMeasurement                                                                                                               ����        �
 �
             K.        FetchStatisticsMeasurement                                                                                                              ����        �
 �O             K.        Abort                                                                                                                                   ����        �� �             K.        IsOverRange                                                                                                                             ����        � �{             K.        viWrite                                                                                                                                 ����        ��              K.        viRead                                                                                                                                  ����        S �             K.        reset                                                                                                                                   ����        . l             K.        ResetWithDefaults                                                                                                                       ����        � "X             K.        ClearCalculateData                                                                                                                      ����        #� +u             K.        Disable                                                                                                                                 ����        +� 5             K.        self_test                                                                                                                               ����        6{ ?4             K.        revision_query                                                                                                                          ����        @0 H�             K.        error_query                                                                                                                             ����        I� w�             K.        error_message                                                                                                                           ����        x� �J             K.        InvalidateAllAttributes                                                                                                                 ����        �� ��             K.        GetError                                                                                                                                ����        �� �}             K.        ClearError                                                                                                                              ����        �� ��             K.        GetNextCoercionRecord                                                                                                                   ����        �� ��             K.        GetNextInterchangeWarning                                                                                                               ����        ǽ �:             K.        ClearInterchangeWarnings                                                                                                                ����        ϴ ݸ             K.        ResetInterchangeCheck                                                                                                                   ����        �2 �a             K.        LockSession                                                                                                                             ����        � �             K.        UnlockSession                                                                                                                           ����        � e             K.        close                                                                                                                                   ����        � 4             K.        WriteInstrData                                                                                                                          ����        � �             K.        ReadInstrData                                                                                                                                 K                                                                                     �Initialize                                                                           �Initialize With Options                                                             ;Configuration                                                                        �Configure Measurement                                                                �Configure Secondary Measurement                                                     Specific Measurements                                                                �Configure AC Bandwidth                                                               �Configure Freq Voltage Range                                                         �Configure Freq Timeout                                                              �Temperature                                                                          �Configure Transducer Type                                                            �Configure RTD                                                                        �Configure RTD Advanced                                                               �Configure Thermistor                                                                 �Configure Thermocouple                                                               �Configure Fixed Reference Junction                                                   �Configure Thermocouple Check Enabled                                                 �Configure Reference Junction Offset Adjustment                                       �Configure Thermistor Power Limit                                                    �Trigger                                                                              �Configure Trigger                                                                    �Configure Trigger Slope                                                              �Configure Trigger Level                                                             MMultiPoint                                                                           �Configure Multi-Point                                                                �Configure Meas Complete Dest                                                         �Configure Pretrigger                                                                �Calibrate                                                                            �Calibrate                                                                            �Calibrate ADC                                                                        �Configure Calibration Security                                                      	Memory                                                                               �Configure Data Transition                                                            �Configure Directory                                                                  �Configure File                                                                       �Configure Preference File                                                            �Configure State File                                                                 �Configure Reading Memory                                                             �Query File List                                                                      �Validate State File                                                                  �Configure Data Transition Format                                                    	eMeasurement Operation Options                                                        �Configure Auto Zero Mode                                                             �Configure Average                                                                    �Configure Limit                                                                      �Configure Scale                                                                      �Configure Scale Advanced                                                             �Configure Scale Unit                                                                 �Configure Histogram                                                                  �Configure Current Terminals                                                          �Configure Voltage Impedance                                                          �Configure Null Operation                                                             �Configure Measurement Trigger Parameters                                             �Configure Smoothing                                                                  �Configure Trend Chart Enabled                                                        �Configure Resistance                                                                 �Configure Range Change Mode                                                         
gConfiguration Information                                                            �Get Auto Range Value                                                                 �Get Aperture Time Info                                                               �Configure Aperture Time                                                             )Set/Get/Check Attribute                                                             �Set Attribute                                                                        �Set Attribute ViInt32                                                                �Set Attribute ViReal64                                                               �Set Attribute ViString                                                               �Set Attribute ViBoolean                                                              �Set Attribute ViSession                                                             Get Attribute                                                                        �Get Attribute ViInt32                                                                �Get Attribute ViReal64                                                               �Get Attribute ViString                                                               �Get Attribute ViBoolean                                                              �Get Attribute ViSession                                                             �Check Attribute                                                                      �Check Attribute ViInt32                                                              �Check Attribute ViReal64                                                             �Check Attribute ViString                                                             �Check Attribute ViBoolean                                                            �Check Attribute ViSession                                                           2Measurement                                                                          �Read                                                                                 �Read Multi-Point                                                                     �Read Histogram Measurement                                                           �Read Statistics Measurement                                                          �Read Last Measurement                                                                �Read Measurement Count                                                               �Read Measurement Memory                                                              �Read Secondary Measurement                                                          �Low-Level Measurement                                                                �Initiate                                                                             �Send Software Trigger                                                                �Fetch                                                                                �Fetch Multi-Point                                                                    �Fetch Histogram Measurement                                                          �Fetch Statistics Measurement                                                         �Abort                                                                                �Is Over Range                                                                       System                                                                               �Write Bytes                                                                          �Read Bytes                                                                          fUtility                                                                              �Reset                                                                                �Reset With Defaults                                                                  �Clear Calculate Data                                                                 �Disable                                                                              �Self-Test                                                                            �Revision Query                                                                       �Error-Query                                                                          �Error Message                                                                        �Invalidate All Attributes                                                           �Error Info                                                                           �Get Error                                                                            �Clear Error                                                                         'Coercion Info                                                                        �Get Next Coercion Record                                                            nInterchangeability Info                                                              �Get Next Interchange Warning                                                         �Clear Interchange Warnings                                                           �Reset Interchange Check                                                             �Locking                                                                              �Lock Session                                                                         �Unlock Session                                                                       �Close                                                                               3Obsolete                                                                            dInstrument I/O                                                                       �Write Instrument Data                                                                �Read Instrument Data                                                            