/**********************************************************************************************
 * Filename:       adcService.h
 *
 * Description:    This file contains the adcService service definitions and
 *                 prototypes.
 *
 * Copyright (c) 2015-2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *************************************************************************************************/


#ifndef _ADCSERVICE_H_
#define _ADCSERVICE_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
* CONSTANTS
*/
// Service UUID
#define ADCSERVICE_SERV_UUID 0xAA00

//  Characteristic defines
#define ADCSERVICE_ADCDATACHAR_ID   0
#define ADCSERVICE_ADCDATACHAR_UUID 0xAA01
#define ADCSERVICE_ADCDATACHAR_LEN  16

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * Profile Callbacks
 */

// Callback when a characteristic value has changed
typedef void (*adcServiceChange_t)(uint16_t connHandle, uint16_t svcUuid, uint8_t paramID, uint16_t len, uint8_t *pValue);

typedef struct
{
  adcServiceChange_t        pfnChangeCb;  // Called when characteristic value changes
  adcServiceChange_t        pfnCfgChangeCb;
} adcServiceCBs_t;



/*********************************************************************
 * API FUNCTIONS
 */


/*
 * AdcService_AddService- Initializes the AdcService service by registering
 *          GATT attributes with the GATT server.
 *
 */
extern bStatus_t AdcService_AddService( uint8_t rspTaskId);

/*
 * AdcService_RegisterAppCBs - Registers the application callback function.
 *                    Only call this function once.
 *
 *    appCallbacks - pointer to application callbacks.
 */
extern bStatus_t AdcService_RegisterAppCBs( adcServiceCBs_t *appCallbacks );

/*
 * AdcService_SetParameter - Set a AdcService parameter.
 *
 *    param - Profile parameter ID
 *    len - length of data to right
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate
 *          data type (example: data type of uint16 will be cast to
 *          uint16 pointer).
 */
extern bStatus_t AdcService_SetParameter(uint8_t param, uint16_t len, void *value);

/*
 * AdcService_GetParameter - Get a AdcService parameter.
 *
 *    param - Profile parameter ID
 *    value - pointer to data to write.  This is dependent on
 *          the parameter ID and WILL be cast to the appropriate
 *          data type (example: data type of uint16 will be cast to
 *          uint16 pointer).
 */
extern bStatus_t AdcService_GetParameter(uint8_t param, uint16_t *len, void *value);

extern uint16_t adcService_AdcDataCharVal[ADCSERVICE_ADCDATACHAR_LEN];

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _ADCSERVICE_H_ */
