/******************************************************************************** 
 *  Copyright 2013 - 2021 National Instruments Corporation.  All Rights Reserved.   * 
 ********************************************************************************/

/*****************************************************************************
 *  ag3446x Instrument Driver Sample Program                              
 *  Developed with LabWindows/CVI 2012                                     
 *  Original Release: 07/12/2013                                  
 *
 *  Purpose:  This sample program reads multiple point measurements from the 
 *            instrument based on multiple triggers and multiple measurements
 *            per trigger. It initializes the DMM, configures it for a 
 *            basic measurement, acquires a measurement, and displays the 
 *            measured value in a message pop-up.
 *
 *            To run this sample program, do the following:
 *            1) Create a new project in LabWindows/CVI.
 *            2) Add this file to the project.  To add files to the project,
 *               select the Add Files To Project from the Edit menu of the 
 *               Project window.
 *            3) Add one of the following files to the project:
 *               ag3446x.fp, ag3446x.c, or ag3446x.lib.
 *            4) Check that the resource name used in ag3446x_InitWithOptions()
 *               is correct. If simulating, change flag to simulate.
 *            5) Run the project.
 *
 *            VCC or Borland Users:
 *            This example uses CVI's MessagePopup() to display the
 *            measured value.  You will need to replace this function with a 
 *            printf() or similar display function.  You will then need to 
 *            remove the #include <userint.h> statement.  You can then follow 
 *            the above directions for CVI users.
 *****************************************************************************/

#include <stdio.h>
#include <userint.h>
#include "ag3446x.h"

main ()

{
    ViSession ag3446x;
    ViStatus  error = VI_SUCCESS;
    ViReal64  readingArray[256];
	ViInt32   actualPoints;
	ViInt32   sampleCount = 1;
	ViInt32   triggerCount = 1;
    ViChar    msgStr[256];  


        /* 
            If you want to run this sample program and the instrument is not
            present, set the Simulate flag to 1.  (Example:  "Simulate = 1")
        */
    checkErr( ag3446x_InitWithOptions ("34470A", VI_TRUE, VI_TRUE,
                                    "Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1",
                                    &ag3446x));
    checkErr( ag3446x_ConfigureMeasurement (ag3446x, AG3446X_VAL_DC_VOLTS, 10,
											 0.00002));

    checkErr( ag3446x_ConfigureTrigger (ag3446x, AG3446X_VAL_IMMEDIATE, 0.001));

    checkErr( ag3446x_ConfigureMultiPoint (ag3446x, triggerCount, sampleCount, AG3446X_VAL_IMMEDIATE, 1.0));
	
	checkErr( ag3446x_ReadMultiPoint (ag3446x, 5000, 256, readingArray, &actualPoints));
    
    sprintf (msgStr, "Reading = %f", readingArray[0]);
    MessagePopup ("Measurement", msgStr);
    
Error:
    if (error != VI_SUCCESS)
        {
            ViChar   errStr[2048];

            ag3446x_GetError (ag3446x, &error, 2048, errStr);
            MessagePopup ("Error!", errStr);
        }
    
    if (ag3446x)
        ag3446x_close (ag3446x);
}
