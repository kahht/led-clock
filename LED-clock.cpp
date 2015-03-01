// - LED Clock -
// This code works with an even common anode wired to a 4 digit, 7 segment display
//
// Written by Kat Dornian
//
// Copyright 2015 Phidgets Inc.  All rights reserved.
// This work is licensed under the Creative Commons Attribution 2.5 Canada License.
// view a copy of this license, visit http://creativecommons.org/licenses/by/2.5/ca/


#include <stdio.h>
#include <phidget21.h>
#include <time.h>
#include <unistd.h> // for sleep

int CCONV ErrorHandler(CPhidgetHandle LED, void *userptr, int ErrorCode, const char *unknown)
{
    printf("Error handled. %d - %s\n", ErrorCode, unknown);
    return 0;
}

// Digit: 1-4
// Value: 0-9
// Brightness: 0(off) - 100(full brightness)
int SetDigit(CPhidgetLEDHandle phid, int digit, int value, int brightness)
{
    int DIGindex = digit*2 + 14;
    
    // Check the values
    if (digit < 1 || digit > 4 || value < 0 || value > 9 || brightness < 0 || brightness > 100)
        return 1; // user error
    
    switch (value)
    {
    case 0:
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
        CPhidgetLED_setBrightness (phid, 8, brightness);
            CPhidgetLED_setBrightness (phid, 10, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    case 1:
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 4, brightness);
        break;
    case 2:
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
        CPhidgetLED_setBrightness (phid, 8, brightness);
            CPhidgetLED_setBrightness (phid, 12, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    case 3:
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
            CPhidgetLED_setBrightness (phid, 12, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    case 4:
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 10, brightness);
        CPhidgetLED_setBrightness (phid, 12, brightness);
        break;
    case 5:
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
        CPhidgetLED_setBrightness (phid, 10, brightness);
            CPhidgetLED_setBrightness (phid, 12, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    case 6:
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
        CPhidgetLED_setBrightness (phid, 8, brightness);
        CPhidgetLED_setBrightness (phid, 10, brightness);
            CPhidgetLED_setBrightness (phid, 12, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    case 7:
        CPhidgetLED_setBrightness (phid, 2, brightness);
            CPhidgetLED_setBrightness (phid, 4, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    case 8:
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
        CPhidgetLED_setBrightness (phid, 8, brightness);
        CPhidgetLED_setBrightness (phid, 10, brightness);
            CPhidgetLED_setBrightness (phid, 12, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    case 9:
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
        CPhidgetLED_setBrightness (phid, 10, brightness);
            CPhidgetLED_setBrightness (phid, 12, brightness);
            CPhidgetLED_setBrightness (phid, 0, brightness);
        break;
    default:
        CPhidgetLED_setBrightness (phid, 0, brightness);
        CPhidgetLED_setBrightness (phid, 2, brightness);
        CPhidgetLED_setBrightness (phid, 4, brightness);
        CPhidgetLED_setBrightness (phid, 6, brightness);
        CPhidgetLED_setBrightness (phid, 8, brightness);
        CPhidgetLED_setBrightness (phid, 10, brightness);
        CPhidgetLED_setBrightness (phid, 12, brightness);
        
        
    }
    
    CPhidgetLED_setBrightness (phid, DIGindex, brightness);
    
    return 0;
    
}

// Turns a digit on or off
// Digit: 1-4
// onoff: turn number on or off
int SetDigit(CPhidgetLEDHandle phid, int digit, bool onoff)
{
    int index = digit*2 + 14;
    int brightness;
    
    // Check the value for digit
    if (digit < 1 || digit > 4)
        return 1; // user error
    
    if (onoff)
        brightness = 100;
    if (!onoff)
        brightness = 0;
    
    CPhidgetLED_setBrightness (phid, 0, brightness);
    CPhidgetLED_setBrightness (phid, 2, brightness);
    CPhidgetLED_setBrightness (phid, 4, brightness);
    CPhidgetLED_setBrightness (phid, 6, brightness);
    CPhidgetLED_setBrightness (phid, 8, brightness);
    CPhidgetLED_setBrightness (phid, 10, brightness);
    CPhidgetLED_setBrightness (phid, 12, brightness);
    
    CPhidgetLED_setBrightness (phid, index, brightness);
    
    return 0;
    
}

//Display the properties of the attached phidget to the screen.  We will be displaying the name, serial number and version of the attached device.
//We will also display the total number of available LEDs
int display_properties(CPhidgetLEDHandle phid)
{
    int serialNo, version, numLED;
    const char* ptr;
    
    CPhidget_getDeviceType((CPhidgetHandle)phid, &ptr);
    CPhidget_getSerialNumber((CPhidgetHandle)phid, &serialNo);
    CPhidget_getDeviceVersion((CPhidgetHandle)phid, &version);
    CPhidgetLED_getLEDCount(phid, &numLED);
    
    printf("%s\n", ptr);
    printf("Serial Number: %10d\nVersion: %8d\n", serialNo, version);
    printf("# LEDs: %d\n", numLED);
    
    return 0;
}

int run_clock()
{
    int result, i;
    const char *err;
    time_t rawtime;
    struct tm * currtime;
    int hour, minute;
    
    //Declare an LED handle
    CPhidgetLEDHandle led = 0;
    
    //create the LED object
    CPhidgetLED_create(&led);
    
    //Set the handlers to be run when the device generates an error.
    CPhidget_set_OnError_Handler((CPhidgetHandle)led, ErrorHandler, NULL);
    
    //open the LED for device connections
    CPhidget_open((CPhidgetHandle)led, -1);
    
    //get the program to wait for an LED device to be attached
    printf("Waiting for Phidget LED 64 to be attached...");
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)led, 10000)))
    {
        CPhidget_getErrorDescription(result, &err);
        printf("Problem waiting for attachment: %s\n", err);
        return 0;
    }
    
    printf(" Attached\n");
    
    // A - 0, B - 2, C - 4, D - 6, E - 8, F - 10, G - 12, DP - 14
    // Through Transistors: DIG1 - 16, DIG2 - 18, DIG3 - 20, DIG4 - 22
    for(i = 0; i < 6000; i++)
    {
        time(&rawtime);
        currtime = localtime(&rawtime);
        
        hour = currtime->tm_hour;
        minute = currtime->tm_min;
        
        
        SetDigit(led, 1, hour/10, 100);
        SetDigit(led, 1, false);
        usleep(25);
        SetDigit(led, 2, hour%10, 100);
        SetDigit(led, 2, false);
        usleep(25);
        SetDigit(led, 3, minute/10, 100);
        SetDigit(led, 3, false);
        usleep(25);
        SetDigit(led, 4, minute%10, 100);
        SetDigit(led, 4, false);
        usleep(25);
    }
    
    CPhidget_close((CPhidgetHandle)led);
    CPhidget_delete((CPhidgetHandle)led);
    
    //all done, exit
    return 0;
}

int main(int argc, char* argv[])
{
    run_clock();
    return 0;
}

