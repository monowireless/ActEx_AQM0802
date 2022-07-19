// -*- coding:utf-8-unix -*-
/**
 * @file   ActEx_AQM0802.cpp
 * @author alnasl
 * @date   Thu Jun 16 14:45:57 2022
 *
 * @brief  Act sample for using AQM0802 LCD modules built with the Sitronix ST7032 LCD controller
 *
 * Copyright (C) 2022 Mono Wireless Inc. All Rights Reserved.
 * Released under MW-OSSLA-*J,*E (MONO WIRELESS OPEN SOURCE SOFTWARE LICENSE AGREEMENT).
 */

// Include Files //////////////////////////////////////////////////////////////

#include <TWELITE>
#include "AQM0802/AQM0802.hpp"    // AQM0802 local library for TWELITE


// Macro Definitions //////////////////////////////////////////////////////////


// Function Prototypes ////////////////////////////////////////////////////////


// Global Objects /////////////////////////////////////////////////////////////

AQM0802 display;                // AQM0802 Display object
uint16_t count;                 // Count number (Maximum: 5 digits)
bool use_mwx_stream;            // Using mwx::stream or not

// Setup and Loop Procedure ///////////////////////////////////////////////////

/**
 * @fn      setup
 * @brief   the setup procedure (called on boot)
 *
 * @param   none
 * @return  none
 */
void setup() {
    // Setup the display
    display.begin();

    // Select printing style
    use_mwx_stream = false;
    if (use_mwx_stream) {
        Serial << "ActEx_AQM0802: Using mwx::stream" << mwx::crlf;
    } else {
        Serial.printfmt("ActEx_AQM0802: Using printf\n");
    }

    // Print initial messages
    if (use_mwx_stream) {
        display << "ActExtra AQM0802" << mwx::crlf;     // Cpp-style
    } else {
        display.printf("ActExtra AQM0802\n");           // C-style
    }
    delay(2000);
    if (use_mwx_stream) {
        display << "-Start!-" << mwx::crlf;     // Cpp-style
    } else {
        display.printf("-Start!-\n");           // C-style
    }

    // Initialize the count number
    count = 0;

    // Begin the Timer0 with 1Hz
    Timer0.begin(1);
}

/**
 * @fn      loop
 * @brief   the loop procedure (called every event)
 *
 * @param   none
 * @return  none
 */
void loop() {
    if (Timer0.available()) {
        // Increment the count number and print it
        if (use_mwx_stream) {
            display << format("%05d[s]", ++count) << mwx::crlf; // Cpp-style
        } else {
            display.printf("%05d[s]\n", ++count);               // C-style
        }
    }
}
