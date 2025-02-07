/******************************************************************************

 Group: WCS, BTS
 Target Device: cc2640r2

 ******************************************************************************
 
 Copyright (c) 2009-2021, Texas Instruments Incorporated
 All rights reserved.

 IMPORTANT: Your use of this Software is limited to those specific rights
 granted under the terms of a software license agreement between the user
 who downloaded the software, his/her employer (which must be your employer)
 and Texas Instruments Incorporated (the "License"). You may not use this
 Software unless you agree to abide by the terms of the License. The License
 limits your use, and you acknowledge, that the Software may not be modified,
 copied or distributed unless embedded on a Texas Instruments microcontroller
 or used solely and exclusively in conjunction with a Texas Instruments radio
 frequency transceiver, which is integrated into your product. Other than for
 the foregoing purpose, you may not use, reproduce, copy, prepare derivative
 works of, modify, distribute, perform, display or sell this Software and/or
 its documentation for any purpose.

 YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
 PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
 NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
 TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
 NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
 LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
 INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
 OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
 OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
 (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

 Should you have any questions regarding your right to use this Software,
 contact Texas Instruments Incorporated at www.TI.com.

 ******************************************************************************
 
 
 *****************************************************************************/

/**
 *  @defgroup GAP GAP
 *  @brief This module implements the Generic Access Protocol (GAP)
 *  For a detailed usage section describing how to send these commands and receive events,
 *  see the <a href="../ble-stack/gap.html">GAP Section</a> of the
 *  User's Guide.
 *  @{
 *  @file  gap.h
 *  @brief      GAP layer interface
 */

#ifndef GAP_H
#define GAP_H

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------------------------
 * INCLUDES
 */
#include "bcomdef.h"
#include "osal.h"
#include "sm.h"

/*-------------------------------------------------------------------
 * MACROS
 */

/*-------------------------------------------------------------------
 * CONSTANTS
 */

/** @defgroup GAP_Constants GAP Constants
 * Other defines used in the GAP layer
 * @{
 */

/** @defgroup GAP_Event_IDs GAP Event IDs
 * @{
 */
/**
 * Sent resulting from @ref GAP_DeviceInit when the Device Initialization is
 * complete.  This event is sent as an OSAL message defined as
 * @ref gapDeviceInitDoneEvent_t.
 */
#define GAP_DEVICE_INIT_DONE_EVENT            0x00
/**
 * Sent when the Device Discovery Process is complete. This event is sent as an
 * OSAL message defined as @ref gapDevDiscEvent_t.
 */
#define GAP_DEVICE_DISCOVERY_EVENT            0x01
/**
 * Sent when the Advertising Data or SCAN_RSP Data has been updated. This event
 * is sent as an OSAL message defined as @ref gapAdvDataUpdateEvent_t.
 */
#define GAP_ADV_DATA_UPDATE_DONE_EVENT        0x02
/**
 * Sent when the Make Discoverable Request is complete. This event is sent as an
 * OSAL message defined as @ref gapMakeDiscoverableRspEvent_t.
 */
#define GAP_MAKE_DISCOVERABLE_DONE_EVENT      0x03
/**
 * Sent when the Advertising has ended. This event is sent as an OSAL message
 * defined as @ref gapEndDiscoverableRspEvent_t.
 */
#define GAP_END_DISCOVERABLE_DONE_EVENT       0x04
/**
 * Sent when the Establish Link Request is complete. This event is sent as an
 * OSAL message defined as @ref gapEstLinkReqEvent_t.
 */
#define GAP_LINK_ESTABLISHED_EVENT            0x05
/**
 * Sent when a connection was terminated. This event is sent as an OSAL message
 * defined as @ref gapTerminateLinkEvent_t.
 */
#define GAP_LINK_TERMINATED_EVENT             0x06
/**
 * Sent when a Parameter Update Event is received. This event is sent as an OSAL
 * message defined as @ref gapLinkUpdateEvent_t.
 */
#define GAP_LINK_PARAM_UPDATE_EVENT           0x07
/**
 * Sent when a random address was changed. This event is sent as an OSAL
 * message defined as @ref gapRandomAddrEvent_t.
 */
#define GAP_RANDOM_ADDR_CHANGED_EVENT         0x08
/**
 * Sent when the device's signature counter is updated. This event is sent as an
 * OSAL message defined as @ref gapSignUpdateEvent_t.
 */
#define GAP_SIGNATURE_UPDATED_EVENT           0x09
/**
 * Sent when the Authentication (pairing) process is complete. This event is
 * sent as an OSAL message defined as @ref gapAuthCompleteEvent_t.
 */
#define GAP_AUTHENTICATION_COMPLETE_EVENT     0x0A
/**
 * Sent when a Passkey is needed.  This is part of the pairing process. This
 * event is sent as an OSAL message defined as @ref gapPasskeyNeededEvent_t.
 */
#define GAP_PASSKEY_NEEDED_EVENT              0x0B
/**
 * Sent when a Slave Security Request is received. This event is sent as an OSAL
 * message defined as @ref gapSlaveSecurityReqEvent_t.
 */
#define GAP_SLAVE_REQUESTED_SECURITY_EVENT    0x0C
/**
 * Sent during the Device Discovery Process when a device is discovered. This
 * event is sent as an OSAL message defined as @ref gapDeviceInfoEvent_t.
 */
#define GAP_DEVICE_INFO_EVENT                 0x0D
/**
 * Sent when the bonding(bound) process is complete. This event is sent as an
 * OSAL message defined as @ref gapBondCompleteEvent_t.
 */
#define GAP_BOND_COMPLETE_EVENT               0x0E
/**
 * Sent when an unexpected Pairing Request is received. This event is sent as an
 * OSAL message defined as @ref gapPairingReqEvent_t.
 */
#define GAP_PAIRING_REQ_EVENT                 0x0F
/**
 * Sent when pairing fails, no @ref GAP_AUTHENTICATION_COMPLETE_EVENT is sent
 * and GBM_QUEUE_PAIRINGS is defined in the stack project.  This event is sent
 * as an OSAL message defined as @ref osal_event_hdr_t.
 */
#define GAP_AUTHENTICATION_FAILURE_EVT        0x10
/**
 * Sent when a Connection Parameter Update Request is received.  This event is
 * sent as an OSAL message defined as @ref gapUpdateLinkParamReqEvent_t. The
 * application should respond with @ref GAP_UpdateLinkParamReqReply
 */
#define GAP_UPDATE_LINK_PARAM_REQ_EVENT       0x11
/** @} End GAP_Event_IDs */

/** @defgroup GAP_Conn_Handle GAP Special Connection Handles
 * Used by GAP_TerminateLinkReq()
 * @{
 */
#define GAP_CONNHANDLE_INIT     0xFFFE  //!< terminates a link create
#define GAP_CONNHANDLE_ALL      0xFFFF  //!< terminates all links for the matching task ID.
/** @} End GAP_Conn_Handle */

/** @defgroup GAP_Profile_Roles GAP Profile Roles
 * Bit mask values
 * @{
 */
#define GAP_PROFILE_BROADCASTER   0x01 //!< A device that sends advertising events only.
#define GAP_PROFILE_OBSERVER      0x02 //!< A device that receives advertising events only.
#define GAP_PROFILE_PERIPHERAL    0x04 //!< A device that accepts the establishment of an LE physical link using the connection establishment procedure
#define GAP_PROFILE_CENTRAL       0x08 //!< A device that supports the Central role initiates the establishment of a physical connection
/** @} End GAP_Profile_Roles */

/**
 * @defgroup GAP_Params GAP Parameter IDs
 * Parameters set via @ref GAP_SetParamValue
 * @{
 */

/**
  * @brief Minimum time to remain advertising, when in general discoverable mode (ms)
  *
  * Setting this parameter to 0 turns off the timeout, thus allowing infinite advertising
  *
  * default: 0
  *
  * range: 0-65535
  */
#define TGAP_GEN_DISC_ADV_MIN          0

/**
  * @brief Time to remain advertising in limited discovery mode (sec)
  *
  * default: 180
  *
  * range: 1-65535
  */
#define TGAP_LIM_ADV_TIMEOUT           1

/**
  * @brief Time to perform scanning for general discovery (ms)
  *
  * default: 10240
  *
  * range: 1-65535
  */
#define TGAP_GEN_DISC_SCAN             2

/**
  * @brief Time to perform scanning for limited discovery (ms)
  *
  * default: 10240
  *
  * range: 1-65535
  */
#define TGAP_LIM_DISC_SCAN             3

/**
  * @brief Advertising timeout when performing connection establishment (ms)
  *
  * default: 10240
  *
  * range: 1-65535
  */
#define TGAP_CONN_EST_ADV_TIMEOUT      4

/**
  * @brief Timeout for link layer to wait to receive connection parameter
  * update response before giving up (ms)
  *
  * default: 30000
  *
  * range: 1-65535
  */
#define TGAP_CONN_PARAM_TIMEOUT        5

/**
  * @brief Minimum advertising interval in limited discovery mode (n × 0.625 ms)
  *
  * default: 160
  *
  * range: 32-16384
  *
  * range: 160-16384 For an advertising event type that is either a scannable
  *        undirected event type or a non-connectable undirected event
  *        type.
  */
#define TGAP_LIM_DISC_ADV_INT_MIN      6

/**
  * @brief Maximum advertising interval in limited discovery mode (n × 0.625 ms)
  *
  * default: 160
  *
  * range: 32-16384
  * 
  * range: 160-16384 For an advertising event type that is either a scannable
  *        undirected event type or a non-connectable undirected event
  *        type.
  */
#define TGAP_LIM_DISC_ADV_INT_MAX      7

/**
  * @brief Minimum advertising interval in general discovery mode (n × 0.625 ms)
  *
  * default: 160
  *
  * range: 32-16384
  * 
  * range: 160-16384 For an advertising event type that is either a scannable
  *        undirected event type or a non-connectable undirected event
  *        type.
  */
#define TGAP_GEN_DISC_ADV_INT_MIN      8

/**
  * @brief Maximum advertising interval in general discovery mode (n × 0.625 ms)
  *
  * default: 160
  *
  * range: 32-16384 
  * 
  * range: 160-16384 For an advertising event type that is either a scannable
  *        undirected event type or a non-connectable undirected event
  *        type.
  */
#define TGAP_GEN_DISC_ADV_INT_MAX      9

/**
  * @brief Minimum advertising interval, when in Connectable mode (n * 0.625 mSec)
  *
  * default: 2048
  *
  * range: 32-16384
  */
#define TGAP_CONN_ADV_INT_MIN         10

/**
  * @brief Maximum advertising interval, when in Connectable mode (n * 0.625 mSec)
  *
  * default: 2048
  *
  * range: 32-16384
  */
#define TGAP_CONN_ADV_INT_MAX         11

/**
  * @brief Scan interval used during connection establishment (n * 0.625 mSec)
  *
  * default: 480
  *
  * range: 4-16384
  */
#define TGAP_CONN_SCAN_INT            12

/**
  * @brief Scan window used during connection establishment (n * 0.625 mSec)
  *
  * default: 240
  *
  * range: 4-16384
  */
#define TGAP_CONN_SCAN_WIND           13

/**
  * @brief Scan interval used during connection establishment, high duty scan cycle scan parameters (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_CONN_HIGH_SCAN_INT       14

/**
  * @brief Scan window used during connection establishment, high duty scan cycle scan parameters (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_CONN_HIGH_SCAN_WIND      15

/**
  * @brief Scan interval used when in General Discovery proc (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_GEN_DISC_SCAN_INT        16

/**
  * @brief Scan window used when in General Discovery proc (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_GEN_DISC_SCAN_WIND       17

/**
  * @brief Scan interval used when in Limited Discovery proc (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_LIM_DISC_SCAN_INT        18

/**
  * @brief Scan window used when in Limited Discovery proc (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_LIM_DISC_SCAN_WIND       19

/// @cond NODOC
/**
  * @brief Advertising interval, when using Connection Establishment proc (n * 0.625 mSec)
  *
  * Obsolete - Do not use.
  */
#define TGAP_CONN_EST_ADV             20
/// @endcond // NODOC

/**
  * @brief Minimum connection interval for connection establishment (n * 1.25 mSec)
  *
  * default: 80
  *
  * range: 6-3200
  */
#define TGAP_CONN_EST_INT_MIN         21

/**
  * @brief Maximum connection interval for connection establishment (n * 1.25 mSec)
  *
  * default: 80
  *
  * range: 6-3200
  */
#define TGAP_CONN_EST_INT_MAX         22

/**
  * @brief Scan interval used during during connection establishment (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_CONN_EST_SCAN_INT        23

/**
  * @brief Scan window used during during connection establishment (n * 0.625 mSec)
  *
  * default: 16
  *
  * range: 4-16384
  */
#define TGAP_CONN_EST_SCAN_WIND       24

/**
  * @brief Connection supervision timeout for connection establishment (n * 10 mSec)
  *
  * default: 2000
  *
  * range: 10-3200
  */
#define TGAP_CONN_EST_SUPERV_TIMEOUT  25

/**
  * @brief Slave latency for connection establishment (in number of connection events)
  *
  * default: 0
  *
  * range: 0-499
  */
#define TGAP_CONN_EST_LATENCY         26

/**
  * @brief Local informational parameter about min len of connection needed, when using Connection Establishment proc (n * 0.625 mSec)
  *
  * default: 0
  *
  * range: < @ref TGAP_CONN_EST_MAX_CE_LEN
  */
#define TGAP_CONN_EST_MIN_CE_LEN      27

/**
  * @brief Local informational parameter about max len of connection needed, when using Connection Establishment proc (n * 0.625 mSec)
  *
  * default: 0
  *
  * range: > @ref TGAP_CONN_EST_MIN_CE_LEN
  */
#define TGAP_CONN_EST_MAX_CE_LEN      28

/**
  * @brief Minimum Time Interval between private (resolvable) address changes (minutes)
  *
  * default: 15
  *
  * range: 1-690
  */
#define TGAP_PRIVATE_ADDR_INT         29

/**
  * @brief Central idle timer (seconds)
  *
  * default: 1
  *
  * range: 1-65535
  */
#define TGAP_CONN_PAUSE_CENTRAL       30

/**
  * @brief Minimum time upon connection establishment before the peripheral starts a connection update procedure (seconds)
  *
  * default: 5
  *
  * range: 1-65535
  */
#define TGAP_CONN_PAUSE_PERIPHERAL    31

/**
  * @brief Time to wait for security manager response before returning bleTimeout (ms)
  *
  * default: 30000
  *
  * range: 1-65535
  */
#define TGAP_SM_TIMEOUT               32

/**
  * @brief SM Minimum Key Length supported
  *
  * default: 7
  *
  * range: 1-65535
  */
#define TGAP_SM_MIN_KEY_LEN           33

/**
  * @brief SM Maximum Key Length supported
  *
  * default: 16
  *
  * range: 1-65535
  */
#define TGAP_SM_MAX_KEY_LEN           34

/**
  * @brief Filter duplicate advertising reports
  *
  * default: TRUE
  *
  * range: 0-1
  */
#define TGAP_FILTER_ADV_REPORTS       35

/**
  * @brief Minimum RSSI required for scan responses to be reported to the app (dBm)
  *
  * default: -127
  *
  * range: -965535 - 0
  */
#define TGAP_SCAN_RSP_RSSI_MIN        36

/**
  * @brief Whether or not to reject Connection Parameter Update Request received on Central device
  *
  * default: FALSE
  *
  * range: 0-1
  */
#define TGAP_REJECT_CONN_PARAMS       37

/// @cond NODOC
#if !defined ( TESTMODES )
  #define TGAP_AUTH_TASK_ID           38  //!< Task ID override for Task Authentication control (for stack internal use only)
  #define TGAP_VERIFY_CAR             39  //!< Verify CAR is true before sending ADV DIR using RPA
/// @endcond // NODOC
  /**
  * @brief Minimum advertise interval during connection - for non connectable advertisement (n * 1.25 mSec)
  *
  * default: 100 ms
  *
  * comply :adv_fast_interval2 in the BLE standard
  */
  #define TGAP_FAST_INTERVAL_2_INT_MIN  40
  /**
  * @brief Minimum advertise interval during connection - for non connectable advertisement (n * 1.25 mSec)
  *
  * default: 150 ms
  *
  * comply :adv_fast_interval2 in the BLE standard
  */
  #define TGAP_FAST_INTERVAL_2_INT_MAX  41
  /**
  * @brief Stub 1 so Flash-ROM (!TESTMODES) and Flash Only(TESTMODES) would 
  *        have the same number of commands.
  *        ADD A NEW FLASH-ROM COMMAND HERE.
  *        
  */     
  #define TGAP_STUB_1                   42
  /**
  * @brief Stub 2 so Flash-ROM (!TESTMODES) and Flash Only(TESTMODES) would 
  *        have the same number of commands.
  *        ADD A NEW FLASH-ROM COMMAND HERE.
  *        
  */      
  #define TGAP_STUB_2                   43
  /**
  * @brief Set the scan channel parameters
  *
  * default: all channels GAP_ADV_CHAN_ALL
  *
  * values: GAP_ADV_CHAN_37, GAP_ADV_CHAN_38, GAP_ADV_CHAN_39, GAP_ADV_CHAN_37_38
  *         GAP_ADV_CHAN_37_39, GAP_ADV_CHAN_38_39, GAP_ADV_CHAN_ALL
  *
  *         @ref GAP_scanChannels_t. 
  */
  #define TGAP_SET_SCAN_CHAN            44

/// @cond NODOC
  #define TGAP_PARAMID_MAX            45  //!< ID MAX-valid Parameter ID
#else
  #define TGAP_GAP_TESTCODE           38  //!< GAP TestCodes - puts GAP into a test mode
  #define TGAP_SM_TESTCODE            39  //!< SM TestCodes - puts SM into a test mode
  #define TGAP_AUTH_TASK_ID           40  //!< Task ID override for Task Authentication control (for stack internal use only)
  #define TGAP_VERIFY_CAR             41  //!< Verify CAR is true before sending ADV DIR using RPA

  /**
  * @brief Minimum advertise interval during connection - for non connectable advertisement (n * 1.25 mSec)
  *
  * default: 100 ms
  *
  * comply :adv_fast_interval2 in the BLE standard
  */
  #define TGAP_FAST_INTERVAL_2_INT_MIN  42
  /**
  * @brief Minimum advertise interval during connection - for non connectable advertisement (n * 1.25 mSec)
  *
  * default: 150 ms
  *
  * comply :adv_fast_interval2 in the BLE standard
  */
  #define TGAP_FAST_INTERVAL_2_INT_MAX  43
  /**
  * @brief Set the scan channel parameters
  *
  * default: all channels GAP_ADV_CHAN_ALL
  *
  * values: GAP_ADV_CHAN_37, GAP_ADV_CHAN_38, GAP_ADV_CHAN_39, GAP_ADV_CHAN_37_38
  *         GAP_ADV_CHAN_37_39, GAP_ADV_CHAN_38_39, GAP_ADV_CHAN_ALL
  *
  *         @ref GAP_scanChannels_t. 
  */
  #define TGAP_SET_SCAN_CHAN            44
  #define TGAP_PARAMID_MAX            45  //!< ID MAX-valid Parameter ID

  #define TGAP_GATT_TESTCODE          100 //!< GATT TestCodes - puts GATT into a test mode (paramValue maintained by GATT)
  #define TGAP_ATT_TESTCODE           101 //!< ATT TestCodes - puts ATT into a test mode (paramValue maintained by ATT)
  #define TGAP_GGS_TESTCODE           102 //!< GGS TestCodes - puts GGS into a test mode (paramValue maintained by GGS)
  #define TGAP_L2CAP_TESTCODE         103 //!< L2CAP TestCodes - puts L2CAP into a test mode (paramValue maintained by L2CAP)
#endif
/// @endcond // NODOC
/** @} End GAP_Params */

/**
 * @defgroup GAP_Discovery GAP Device Discovery Modes
 * @{
 */
#define DEVDISC_MODE_NONDISCOVERABLE  0x00    //!< No discoverable setting
#define DEVDISC_MODE_GENERAL          0x01    //!< General Discoverable devices
#define DEVDISC_MODE_LIMITED          0x02    //!< Limited Discoverable devices
#define DEVDISC_MODE_ALL              0x03    //!< Not filtered
/** @} End GAP_Discovery */

/** @defgroup GAP_Addr_Types Address Types
 * @{
 */
#define ADDRTYPE_PUBLIC               0x00  //!< Public Device Address
#define ADDRTYPE_RANDOM               0x01  //!< Random Device Address
#define ADDRTYPE_PUBLIC_ID            0x02  //!< Public Identity Address (corresponds to peer's RPA)
#define ADDRTYPE_RANDOM_ID            0x03  //!< Random (static) Identity Address (corresponds to peer's RPA)
/** @} End GAP_Addr_Types */

/** @defgroup Address_IDs Masks for setting and getting ID type
 * @{
 */
#define SET_ADDRTYPE_ID               0x02  //!< OR with addrtype to change addr type to ID
#define MASK_ADDRTYPE_ID              0x01  //!< AND with addrtype to remove ID from type
/** @} End Address_IDs */

/** @defgroup Random_Addr_Subtypes Random Address Subtypes
 * @{
 */
#define RANDOM_ADDR_SUBTYPE_STATIC    0x00  //!< Random Static Address
#define RANDOM_ADDR_SUBTYPE_RPA       0x01  //!< Resolvable Private Address
#define RANDOM_ADDR_SUBTYPE_NRPA      0x02  //!< Non-Resolvable Private Address
/** @} End Random_Addr_Subtypes */

/** @defgroup Random_Addr_Bitfields Random Address bitfield mask and types
 * @{
 */
#define RANDOM_ADDR_HDR_MASK          0xC0  //!< Get top 2 bits of address
#define STATIC_ADDR_HDR               0xC0  //!< Random Static Address (b11)
#define PRIVATE_NON_RESOLVE_ADDR_HDR  0x80  //!< Random Private Non-Resolvable Address (b10)
#define PRIVATE_RESOLVE_ADDR_HDR      0x40  //!< Random Private Resolvable Address (b01)
  /** @} End Random_Addr_Bitfields */

/** @defgroup Gap_Addr_Modes GAP Addressing Modes
 * @{
 */
#define ADDRMODE_PUBLIC               0x00  //!< Use the BD_ADDR
#define ADDRMODE_STATIC               0x01  //!< Use provided Static Address
#define ADDRMODE_PRIVATE_NONRESOLVE   0x02  //!< Generate and Use Non-Resolvable Private Address
#define ADDRMODE_PRIVATE_RESOLVE      0x03  //!< Generate and Use Resolvable Private Address
/** @} End Gap_Addr_Modes */

/** @defgroup GAP_Adv_Types GAP Advertising Event Types
 * for eventType field in gapAdvertisingParams_t
 * @{
 */
#define GAP_ADTYPE_ADV_IND                0x00  //!< Connectable undirected advertisement
#define GAP_ADTYPE_ADV_HDC_DIRECT_IND     0x01  //!< Connectable high duty cycle directed advertisement
#define GAP_ADTYPE_ADV_SCAN_IND           0x02  //!< Scannable undirected advertisement
#define GAP_ADTYPE_ADV_NONCONN_IND        0x03  //!< Non-Connectable undirected advertisement
#define GAP_ADTYPE_ADV_LDC_DIRECT_IND     0x04  //!< Connectable low duty cycle directed advertisement
/** @} End GAP_Adv_Types */

/** @defgroup GAP_Adv_Report_Types GAP Advertising Report Event Types
 * for eventType field in gapDevRec_t and gapDeviceInfoEvent_t
 * @{
 */
#define GAP_ADRPT_ADV_IND                 0x00  //!< Connectable undirected advertisement
#define GAP_ADRPT_ADV_DIRECT_IND          0x01  //!< Connectable directed advertisement
#define GAP_ADRPT_ADV_SCAN_IND            0x02  //!< Scannable undirected advertisement
#define GAP_ADRPT_ADV_NONCONN_IND         0x03  //!< Non-Connectable undirected advertisement
#define GAP_ADRPT_SCAN_RSP                0x04  //!< Scan Response
/** @} End GAP_Adv_Report_Types */

/** @defgroup GAP_Adv_Filter_Policices GAP Advertiser Filter Scan Parameters
 * @{
 */
#define GAP_FILTER_POLICY_ALL             0x00 //!< Allow Scan Request from Any, Allow Connect Request from Any (default).
#define GAP_FILTER_POLICY_WHITE_SCAN      0x01 //!< Allow Scan Request from White List Only, Allow Connect from Any
#define GAP_FILTER_POLICY_WHITE_CON       0x02 //!< Allow Scan Request from Any, Connect from White List Only
#define GAP_FILTER_POLICY_WHITE           0x03 //!< Allow Scan Request and Connect from White List Only
/** @} End GAP_Adv_Filter_Policices */

/** @defgroup GAP_Disc_Filter_Policies GAP Discovery Filter Scan Parameters
 * @{
 */
 /**
 * @brief GAP Discovery Filter Scan Parameters
 *
 * Note: GAP_DISC_FILTER_POLICY_ALL_DIRECT & GAP_DISC_FILTER_POLICY_WHITE_DIRECT 
 *       are only applicable when PRIVACY is enabled
 * 
 */
#define GAP_DISC_FILTER_POLICY_ALL          0x00 //!< Accept all Adv Packets except
#define GAP_DISC_FILTER_POLICY_WHITE        0x01 //!< Accept only undirected Adv Packets from devices where AdvA is in WL
#define GAP_DISC_FILTER_POLICY_ALL_DIRECT   0x02 //!< Accept all Adv Packets and Direct Adv Packets where InitA is an RPA
#define GAP_DISC_FILTER_POLICY_WHITE_DIRECT 0x03 //!< Accept only undirected Adv Packets from devices where AdvA is in WL and Direct Adv Packets where InitA is an RPA
/** @} End GAP_Disc_Filter_Policies */

#define ADV_CHANMAP_SIZE                 5  //!< Advertiser Channel Map

#define GAP_PASSCODE_MAX                 999999 //!< Maximum Pairing Passcode/Passkey value.  Range of a passkey can be 0 - 999,999.

/**
 * @brief Sign Counter Initialized
 *
 * Sign counter hasn't been used yet.  Used when setting up
 *  a connection's signing information.
 */
#define GAP_INIT_SIGN_COUNTER            0xFFFFFFFF

/** @defgroup GAP_Adv_Chans GAP Advertisement Channel Map
 * @{
 */
#define GAP_ADVCHAN_37  0x01  //!< Advertisement Channel 37
#define GAP_ADVCHAN_38  0x02  //!< Advertisement Channel 38
#define GAP_ADVCHAN_39  0x04  //!< Advertisement Channel 39
#define GAP_ADVCHAN_ALL (GAP_ADVCHAN_37 | GAP_ADVCHAN_38 | GAP_ADVCHAN_39) //!< All Advertisement Channels Enabled
/** @} End GAP_Adv_Chans */

/** @defgroup GAP_Whitelist GAP White List Options
 * @{
 */
#define WL_NOTUSED    0x00    //!< White list not used but the advertiser's address in this command is used
#define WL_USED       0x01    //!< White list is used and the advertiser's address in this command is not used.
/** @} End GAP_Whitelist */

/** @defgroup GAP_ADTypes GAP Advertisement Data Types
 * These are the data type identifiers for the data tokens in the advertisement data field.
 * @{
 */
#define GAP_ADTYPE_FLAGS                        0x01 //!< @ref GAP_Discovery
#define GAP_ADTYPE_16BIT_MORE                   0x02 //!< Service: More 16-bit UUIDs available
#define GAP_ADTYPE_16BIT_COMPLETE               0x03 //!< Service: Complete list of 16-bit UUIDs
#define GAP_ADTYPE_32BIT_MORE                   0x04 //!< Service: More 32-bit UUIDs available
#define GAP_ADTYPE_32BIT_COMPLETE               0x05 //!< Service: Complete list of 32-bit UUIDs
#define GAP_ADTYPE_128BIT_MORE                  0x06 //!< Service: More 128-bit UUIDs available
#define GAP_ADTYPE_128BIT_COMPLETE              0x07 //!< Service: Complete list of 128-bit UUIDs
#define GAP_ADTYPE_LOCAL_NAME_SHORT             0x08 //!< Shortened local name
#define GAP_ADTYPE_LOCAL_NAME_COMPLETE          0x09 //!< Complete local name
#define GAP_ADTYPE_POWER_LEVEL                  0x0A //!< TX Power Level: 0xXX: -127 to +127 dBm
#define GAP_ADTYPE_OOB_CLASS_OF_DEVICE          0x0D //!< Simple Pairing OOB Tag: Class of device (3 octets)
#define GAP_ADTYPE_OOB_SIMPLE_PAIRING_HASHC     0x0E //!< Simple Pairing OOB Tag: Simple Pairing Hash C (16 octets)
#define GAP_ADTYPE_OOB_SIMPLE_PAIRING_RANDR     0x0F //!< Simple Pairing OOB Tag: Simple Pairing Randomizer R (16 octets)
#define GAP_ADTYPE_SM_TK                        0x10 //!< Security Manager TK Value
#define GAP_ADTYPE_SM_OOB_FLAG                  0x11 //!< Security Manager OOB Flags
#define GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE    0x12 //!< Min and Max values of the connection interval (2 octets Min, 2 octets Max) (0xFFFF indicates no conn interval min or max)
#define GAP_ADTYPE_SIGNED_DATA                  0x13 //!< Signed Data field
#define GAP_ADTYPE_SERVICES_LIST_16BIT          0x14 //!< Service Solicitation: list of 16-bit Service UUIDs
#define GAP_ADTYPE_SERVICES_LIST_128BIT         0x15 //!< Service Solicitation: list of 128-bit Service UUIDs
#define GAP_ADTYPE_SERVICE_DATA                 0x16 //!< Service Data - 16-bit UUID
#define GAP_ADTYPE_PUBLIC_TARGET_ADDR           0x17 //!< Public Target Address
#define GAP_ADTYPE_RANDOM_TARGET_ADDR           0x18 //!< Random Target Address
#define GAP_ADTYPE_APPEARANCE                   0x19 //!< Appearance
#define GAP_ADTYPE_ADV_INTERVAL                 0x1A //!< Advertising Interval
#define GAP_ADTYPE_LE_BD_ADDR                   0x1B //!< LE Bluetooth Device Address
#define GAP_ADTYPE_LE_ROLE                      0x1C //!< LE Role
#define GAP_ADTYPE_SIMPLE_PAIRING_HASHC_256     0x1D //!< Simple Pairing Hash C-256
#define GAP_ADTYPE_SIMPLE_PAIRING_RANDR_256     0x1E //!< Simple Pairing Randomizer R-256
#define GAP_ADTYPE_SERVICE_DATA_32BIT           0x20 //!< Service Data - 32-bit UUID
#define GAP_ADTYPE_SERVICE_DATA_128BIT          0x21 //!< Service Data - 128-bit UUID
#define GAP_ADTYPE_3D_INFO_DATA                 0x3D //!< 3D Information Data
#define GAP_ADTYPE_MANUFACTURER_SPECIFIC        0xFF //!< Manufacturer Specific Data: first 2 octets contain the Company Identifier Code followed by the additional manufacturer specific data
#define GAP_ADTYPE_FLAGS_LIMITED                0x01 //!< Discovery Mode: LE Limited Discoverable Mode
#define GAP_ADTYPE_FLAGS_GENERAL                0x02 //!< Discovery Mode: LE General Discoverable Mode
#define GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED    0x04 //!< Discovery Mode: BR/EDR Not Supported
/** @} End GAP_ADTypes */

/** @defgroup GAP_State_Flags GAP State Flags
 * @{
 */
#define GAP_STATE_IDLE                          0x00 //!< Device is idle
#define GAP_STATE_ADV                           0x01 //!< Device is advertising
#define GAP_STATE_SCAN                          0x02 //!< Device is scanning
#define GAP_STATE_INIT                          0x04 //!< Device is establishing a connection
/** @} End GAP_State_Flags */

/** @defgroup GAP_Appearance_Values GAP Appearance Values
 * @{
 */
#define GAP_APPEARE_UNKNOWN                     0x0000 //!< Unknown
#define GAP_APPEARE_GENERIC_PHONE               0x0040 //!< Generic Phone
#define GAP_APPEARE_GENERIC_COMPUTER            0x0080 //!< Generic Computer
#define GAP_APPEARE_GENERIC_WATCH               0x00C0 //!< Generic Watch
#define GAP_APPEARE_WATCH_SPORTS                0x00C1 //!< Watch: Sports Watch
#define GAP_APPEARE_GENERIC_CLOCK               0x0100 //!< Generic Clock
#define GAP_APPEARE_GENERIC_DISPLAY             0x0140 //!< Generic Display
#define GAP_APPEARE_GENERIC_RC                  0x0180 //!< Generic Remote Control
#define GAP_APPEARE_GENERIC_EYE_GALSSES         0x01C0 //!< Generic Eye-glasses
#define GAP_APPEARE_GENERIC_TAG                 0x0200 //!< Generic Tag
#define GAP_APPEARE_GENERIC_KEYRING             0x0240 //!< Generic Keyring
#define GAP_APPEARE_GENERIC_MEDIA_PLAYER        0x0280 //!< Generic Media Player
#define GAP_APPEARE_GENERIC_BARCODE_SCANNER     0x02C0 //!< Generic Barcode Scanner
#define GAP_APPEARE_GENERIC_THERMOMETER         0x0300 //!< Generic Thermometer
#define GAP_APPEARE_GENERIC_THERMO_EAR          0x0301 //!< Thermometer: Ear
#define GAP_APPEARE_GENERIC_HR_SENSOR           0x0340 //!< Generic Heart rate Sensor
#define GAP_APPEARE_GENERIC_HRS_BELT            0x0341 //!< Heart Rate Sensor: Heart Rate Belt
#define GAP_APPEARE_GENERIC_BLOOD_PRESSURE      0x0380 //!< Generic Blood Pressure
#define GAP_APPEARE_GENERIC_BP_ARM              0x0381 //!< Blood Pressure: Arm
#define GAP_APPEARE_GENERIC_BP_WRIST            0x0382 //!< Blood Pressure: Wrist
#define GAP_APPEARE_GENERIC_HID                 0x03C0 //!< Generic Human Interface Device (HID)
#define GAP_APPEARE_HID_KEYBOARD                0x03C1 //!< HID Keyboard
#define GAP_APPEARE_HID_MOUSE                   0x03C2 //!< HID Mouse
#define GAP_APPEARE_HID_JOYSTIC                 0x03C3 //!< HID Joystick
#define GAP_APPEARE_HID_GAMEPAD                 0x03C4 //!< HID Gamepad
#define GAP_APPEARE_HID_DIGITIZER_TYABLET       0x03C5 //!< HID Digitizer Tablet
#define GAP_APPEARE_HID_DIGITAL_CARDREADER      0x03C6 //!< HID Card Reader
#define GAP_APPEARE_HID_DIGITAL_PEN             0x03C7 //!< HID Digital Pen
#define GAP_APPEARE_HID_BARCODE_SCANNER         0x03C8 //!< HID Barcode Scanner
/** @} End GAP_Appearance_Values */

/** @defgroup LL_ERRORS Link Layer Error Values
 * @{
 */
#define GAP_LLERROR_COMMAND_DISALLOWED       0x0C   //!< Command is not allowed
#define GAP_LLERROR_INVALID_PARAMETERS       0x12   //!< One of the parameters were invalid
/** @} End LL_ERRORS */

/**
 * GAP Scanner Defines for Scan Channels
 */
typedef enum
{
  GAP_ADV_CHAN_37       = BV(0),               //!< Channel 37
  GAP_ADV_CHAN_38       = BV(1),               //!< Channel 38
  GAP_ADV_CHAN_39       = BV(2),               //!< Channel 39
  GAP_ADV_CHAN_37_38    = (GAP_ADV_CHAN_37 |
                           GAP_ADV_CHAN_38),   //!< Channels 37 & 38
  GAP_ADV_CHAN_37_39    = (GAP_ADV_CHAN_37 |
                           GAP_ADV_CHAN_39),   //!< Channels 37 & 39
  GAP_ADV_CHAN_38_39    = (GAP_ADV_CHAN_38 |
                           GAP_ADV_CHAN_39),   //!< Channels 38 & 39
  GAP_ADV_CHAN_ALL      = (GAP_ADV_CHAN_37 |
                           GAP_ADV_CHAN_38 |
                           GAP_ADV_CHAN_39)    //!< All Channels
} GAP_scanChannels_t;

/**
 * Status of connection events returned via @ref pfnGapConnEvtCB_t
 */
typedef enum
{
  /// Connection event occurred successfully
  GAP_CONN_EVT_STAT_SUCCESS   = LL_CONN_EVT_STAT_SUCCESS,
  /// Connection event failed because all packets had CRC errors
  GAP_CONN_EVT_STAT_CRC_ERROR = LL_CONN_EVT_STAT_CRC_ERROR,
  /// No data was received during connection event
  GAP_CONN_EVT_STAT_MISSED    = LL_CONN_EVT_STAT_MISSED
} GAP_ConnEvtStat_t;

/**
 * Task type for next scheduled BLE task
 */
typedef enum
{
  /// Advertiser
  GAP_CONN_EVT_TASK_TYPE_ADV    = LL_TASK_ID_ADVERTISER,
  /// Initiating a connection
  GAP_CONN_EVT_TASK_TYPE_INIT   = LL_TASK_ID_INITIATOR,
  /// Connection event in slave role
  GAP_CONN_EVT_TASK_TYPE_SLAVE  = LL_TASK_ID_SLAVE,
  /// Scanner
  GAP_CONN_EVT_TASK_TYPE_SCAN   = LL_TASK_ID_SCANNER,
  /// Connection event in master role
  GAP_CONN_EVT_TASK_TYPE_MASTER = LL_TASK_ID_MASTER,
  // No task
  GAP_CONN_EVT_TASK_TYPE_NONE   = LL_TASK_ID_NONE
} GAP_ConnEvtTaskType_t;

/**
 * Action to take for callback registration API's
 */
typedef enum
{
  GAP_CB_REGISTER, //!< Register a callback
  GAP_CB_UNREGISTER //!> Unregister a callback
} GAP_CB_Action_t;


/** @} End GAP_Constants */

/*-------------------------------------------------------------------
 * TYPEDEFS - Initialization and Configuration
 */

/** @defgroup GAP_Structs GAP Structures
 * @{
 */

/**
 * @brief GAP Parameters IDs
 *
 * @ref GAP_Params
 */
typedef uint16 gapParamIDs_t;

/// @brief GAP event header format.
typedef struct
{
  osal_event_hdr_t  hdr;           //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                    //!< GAP type of command. @ref GAP_Event_IDs
} gapEventHdr_t;

/** @defgroup GAP_Events GAP Events
 * @{
 */

/**
 * @brief @ref GAP_RANDOM_ADDR_CHANGED_EVENT message format.
 *
 * This message is sent to the
 * app when the random address changes.
 */
typedef struct
{
  osal_event_hdr_t  hdr;              //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                       //!< @ref GAP_RANDOM_ADDR_CHANGED_EVENT
  uint8 addrMode;                     //!< Address mode: @ref Gap_Addr_Modes
  uint8 newRandomAddr[B_ADDR_LEN];    //!< the new calculated private addr
} gapRandomAddrEvent_t;

/** @} End GAP_Events */

/**
 * @brief Connection parameters for the peripheral device.
 *
 * These numbers are used
 * to compare against connection events and request connection parameter
 * updates with the master.
 */
typedef struct
{
  /** Minimum value for the connection event (interval. 0x0006 - 0x0C80 * 1.25 ms) */
  uint16 intervalMin;
  /** Maximum value for the connection event (interval. 0x0006 - 0x0C80 * 1.25 ms) */
  uint16 intervalMax;
  /** Number of LL latency connection events (0x0000 - 0x03e8) */
  uint16 latency;
  /** Connection Timeout (0x000A - 0x0C80 * 10 ms) */
  uint16 timeout;
} gapPeriConnectParams_t;

/**
 *  @addtogroup GAP_Events
 *  @{
 */

/**
 * @brief @ref GAP_DEVICE_INIT_DONE_EVENT message format.
 *
 * This message is sent to the
 * app when the Device Initialization is done [initiated by calling
 * GAP_DeviceInit()].
 */
typedef struct
{
  osal_event_hdr_t  hdr;              //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                       //!< @ref GAP_DEVICE_INIT_DONE_EVENT
  uint8 devAddr[B_ADDR_LEN];          //!< Device's BD_ADDR
  uint16 dataPktLen;                  //!< HC_LE_Data_Packet_Length
  uint8 numDataPkts;                  //!< HC_Total_Num_LE_Data_Packets
} gapDeviceInitDoneEvent_t;

/**
 * @brief @ref GAP_SIGNATURE_UPDATED_EVENT message format.
 *
 * This message is sent to the
 * app when the signature counter has changed.  This message is to inform the
 * application in case it wants to save it to be restored on reboot or reconnect.
 * This message is sent to update a connection's signature counter and to update
 * this device's signature counter.  If devAddr == BD_ADDR, then this message pertains
 * to this device.
 */
typedef struct
{
  osal_event_hdr_t  hdr;              //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                       //!< @ref GAP_SIGNATURE_UPDATED_EVENT
  uint8 addrType;                     //!< Device's address type for devAddr
  uint8 devAddr[B_ADDR_LEN];          //!< Device's BD_ADDR, could be own address
  uint32 signCounter;                 //!< new Signed Counter
} gapSignUpdateEvent_t;

/**
 * @brief @ref GAP_DEVICE_INFO_EVENT message format.
 *
 * This message is sent to the
 * app during a Device Discovery Request, when a new advertisement or scan
 * response is received.
 */
typedef struct
{
  osal_event_hdr_t  hdr;    //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;             //!< @ref GAP_DEVICE_INFO_EVENT
  uint8 eventType;          //!< Advertisement Type: @ref GAP_Adv_Report_Types
  uint8 addrType;           //!< address type: @ref GAP_Addr_Types
  uint8 addr[B_ADDR_LEN];   //!< Address of the advertisement or SCAN_RSP
  int8 rssi;                //!< Advertisement or SCAN_RSP RSSI
  uint8 dataLen;            //!< Length (in bytes) of the data field (evtData)
  uint8 *pEvtData;          //!< Data field of advertisement or SCAN_RSP
} gapDeviceInfoEvent_t;

/** @} */ // end of GAP_Events

/*-------------------------------------------------------------------
 * TYPEDEFS - Device Discovery
 */

/// @brief Type of device discovery (Scan) to perform.
typedef struct
{
  uint8 taskID;              //!< Requesting App's Task ID, used to return results
  uint8 mode;                //!< Discovery Mode: @ref GAP_Discovery
  uint8 activeScan;          //!< TRUE for active scanning
  uint8 whiteList;           //!< Filer Policy: @ref GAP_Disc_Filter_Policies
} gapDevDiscReq_t;

/// @brief Type of device discovery (Scan) to perform.
typedef struct
{
  uint8 eventType;           //!< Indicates advertising event type used by the advertiser: @ref GAP_Adv_Report_Types
  uint8 addrType;            //!< Address Type: @ref GAP_Addr_Types
  uint8 addr[B_ADDR_LEN];    //!< Device's Address
} gapDevRec_t;

/**
 *  @addtogroup GAP_Events
 *  @{
 */

/**
 * @brief @ref GAP_DEVICE_DISCOVERY_EVENT message format.
 *
 * This message is sent to the
 * Application after a scan is performed.
 */
typedef struct
{
  osal_event_hdr_t  hdr;    //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;             //!< @ref GAP_DEVICE_DISCOVERY_EVENT
  uint8 numDevs;            //!< Number of devices found during scan
  gapDevRec_t *pDevList;    //!< array of device records
} gapDevDiscEvent_t;

/** @} */ // end of GAP_Events

/// @brief Advertising Parameters
typedef struct
{
  uint8 eventType;          //!< Advertise Event Type: @ref GAP_Adv_Types
  uint8 initiatorAddrType;  //!< Initiator's address type: @ref GAP_Addr_Types
  uint8 initiatorAddr[B_ADDR_LEN];  //!< Initiator's addr - used only with connectable directed eventType (ADV_EVTTYPE_CONNECTABLE_DIRECTED).
  uint8 channelMap;         //!< Channel Map: Bit mask @ref GAP_Adv_Chans
  uint8 filterPolicy;       //!< Filer Policy: @ref GAP_Adv_Filter_Policices. Ignored when directed advertising is used.
} gapAdvertisingParams_t;

/**
 *  @addtogroup GAP_Events
 *  @{
 */

/**
 * @brief @ref GAP_MAKE_DISCOVERABLE_DONE_EVENT message format.
 *
 * This message is sent to the
 * app when the Advertise config is complete.
 */
typedef struct
{
  osal_event_hdr_t  hdr; //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;          //!< @ref GAP_MAKE_DISCOVERABLE_DONE_EVENT
} gapMakeDiscoverableRspEvent_t;

/**
 * @brief @ref GAP_END_DISCOVERABLE_DONE_EVENT message format.
 *
 * This message is sent to the
 * app when the Advertising has stopped.
 */
typedef struct
{
  osal_event_hdr_t  hdr; //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;          //!< @ref GAP_END_DISCOVERABLE_DONE_EVENT
} gapEndDiscoverableRspEvent_t;

/**
 * @brief @ref GAP_ADV_DATA_UPDATE_DONE_EVENT message format.
 *
 * This message is sent to the
 * app when Advertising Data Update is complete.
 */
typedef struct
{
  osal_event_hdr_t  hdr; //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;          //!< @ref GAP_ADV_DATA_UPDATE_DONE_EVENT
  uint8 adType;          //!< TRUE if advertising data, FALSE if SCAN_RSP
} gapAdvDataUpdateEvent_t;

/** @} */ // end of GAP_Events

/*-------------------------------------------------------------------
 * TYPEDEFS - Link Establishment
 */

/// @brief Establish Link Request parameters
typedef struct
{
  uint8 taskID;               //!< Requesting App/Profile's Task ID
  uint8 highDutyCycle;        //!< TRUE to high duty cycle scan, FALSE if not.
  uint8 whiteList;            //!< Determines use of the white list: @ref GAP_Whitelist
  uint8 addrTypePeer;         //!< Address type of the advertiser: @ref GAP_Addr_Types
  uint8 peerAddr[B_ADDR_LEN]; //!< Advertiser's address
} gapEstLinkReq_t;

/// @brief Update Link Parameters Request parameters
typedef struct
{
  uint16 connectionHandle; //!< Connection handle of the update
  uint16 intervalMin;      //!< Minimum Connection Interval
  uint16 intervalMax;      //!< Maximum Connection Interval
  uint16 connLatency;      //!< Connection Latency
  uint16 connTimeout;      //!< Connection Timeout
} gapUpdateLinkParamReq_t;

/// @brief Update Link Parameters Request Reply parameters
typedef struct
{
  uint16 connectionHandle; //!< Connection handle of the update
  uint16 intervalMin;      //!< Minimum Connection Interval
  uint16 intervalMax;      //!< Maximum Connection Interval
  uint16 connLatency;      //!< Connection Latency
  uint16 connTimeout;      //!< Connection Timeout
  uint8  accepted;         //!< TRUE if host accepts parameter update, FALSE otherwise.
} gapUpdateLinkParamReqReply_t;

/**
 *  @addtogroup GAP_Events
 *  @{
 */

/**
 *  @brief @ref GAP_UPDATE_LINK_PARAM_REQ_EVENT message format.
 *
 *  Connection parameters desired by the remote device when a Connection
 *  Parameter Update Procedure is ongoing.
 */
typedef struct
{
  osal_event_hdr_t  hdr;              //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                       //!< @ref GAP_UPDATE_LINK_PARAM_REQ_EVENT
  gapUpdateLinkParamReq_t req;        //!< Remote device's requested parameters
} gapUpdateLinkParamReqEvent_t;

/**
 * @brief @ref GAP_LINK_ESTABLISHED_EVENT message format.
 *
 * This message is sent to the app
 * when the link request is complete.
 *
 * For an Observer, this message is sent to complete the Establish Link Request.<BR>
 * For a Peripheral, this message is sent to indicate that a link has been created.
 */
typedef struct
{
  osal_event_hdr_t  hdr;     //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;              //!< @ref GAP_LINK_ESTABLISHED_EVENT
  uint8 devAddrType;         //!< Device address type: @ref GAP_Addr_Types
  uint8 devAddr[B_ADDR_LEN]; //!< Device address of link
  uint16 connectionHandle;   //!< Connection Handle from controller used to ref the device
  uint8 connRole;            //!< Connection formed as Master or Slave
  uint16 connInterval;       //!< Connection Interval
  uint16 connLatency;        //!< Connection Latency
  uint16 connTimeout;        //!< Connection Timeout
  uint8 clockAccuracy;       //!< Clock Accuracy
} gapEstLinkReqEvent_t;

/**
 * @brief @ref GAP_LINK_PARAM_UPDATE_EVENT message format.
 *
 * This message is sent to the app
 * when the connection parameters update request is complete.
 */
typedef struct
{
  osal_event_hdr_t hdr;     //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;             //!< @ref GAP_LINK_PARAM_UPDATE_EVENT
  uint8 status;             //!< status from link layer, defined in ll.h
  uint16 connectionHandle;  //!< Connection handle of the update
  uint16 connInterval;      //!< Requested connection interval
  uint16 connLatency;       //!< Requested connection latency
  uint16 connTimeout;       //!< Requested connection timeout
} gapLinkUpdateEvent_t;

/**
 * @brief @ref GAP_LINK_TERMINATED_EVENT message format.
 *
 * This message is sent to the
 * app when a link to a device is terminated.
 */
typedef struct
{
  osal_event_hdr_t  hdr;   //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;            //!< @ref GAP_LINK_TERMINATED_EVENT
  uint16 connectionHandle; //!< connection Handle
  uint8 reason;            //!< termination reason from LL, defined in ll.h
} gapTerminateLinkEvent_t;

/*-------------------------------------------------------------------
 * TYPEDEFS - Authentication, Bounding and Pairing
 */

/**
 * @brief @ref GAP_PASSKEY_NEEDED_EVENT message format.
 *
 * This message is sent to the
 * app when a Passkey is needed from the app's user interface.
 */
typedef struct
{
  osal_event_hdr_t  hdr;        //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                 //!< @ref GAP_PASSKEY_NEEDED_EVENT
  uint8 deviceAddr[B_ADDR_LEN]; //!< address of device to pair with, and could be either public or random.
  uint16 connectionHandle;      //!< Connection handle
  uint8 uiInputs;               //!< Pairing User Interface Inputs - Ask user to input passcode
  uint8 uiOutputs;              //!< Pairing User Interface Outputs - Display passcode
  uint32 numComparison;         //!< Numeric Comparison value to be displayed.
} gapPasskeyNeededEvent_t;

/**
 * @brief @ref GAP_AUTHENTICATION_COMPLETE_EVENT message format.
 *
 * This message is sent to the app
 * when the authentication request is complete.
 */
typedef struct
{
  osal_event_hdr_t  hdr;           //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                    //!< @ref GAP_AUTHENTICATION_COMPLETE_EVENT
  uint16 connectionHandle;         //!< Connection Handle from controller used to ref the device
  uint8 authState;                 //!< TRUE if the pairing was authenticated (MITM)
  smSecurityInfo_t *pSecurityInfo; //!< BOUND - security information from this device
  smSigningInfo_t *pSigningInfo;   //!< Signing information
  smSecurityInfo_t *pDevSecInfo;   //!< BOUND - security information from connected device
  smIdentityInfo_t *pIdentityInfo; //!< BOUND - identity information
} gapAuthCompleteEvent_t;

/** @} */ // end of GAP_Events

/**
 * @brief Authentication Parameters
 *
 * securityInfo and identityInfo are only used if secReqs.bondable == BOUND, which means that
 * the device is already bound and we should use the security information and keys.
 */
typedef struct
{
  uint16 connectionHandle;      //!< Connection Handle from controller,
  smLinkSecurityReq_t  secReqs; //!< Pairing Control info
} gapAuthParams_t;

/**
 *  @addtogroup GAP_Events
 *  @{
 */

/**
 * @brief @ref GAP_SLAVE_REQUESTED_SECURITY_EVENT message format.
 *
 * This message is sent to the app
 * when a Slave Security Request is received.
 */
typedef struct
{
  osal_event_hdr_t  hdr;        //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;                 //!< @ref GAP_SLAVE_REQUESTED_SECURITY_EVENT
  uint16 connectionHandle;      //!< Connection Handle
  uint8 deviceAddr[B_ADDR_LEN]; //!< address of device requesting security
  uint8 authReq;                //!< Authentication Requirements: Bit 2: MITM, Bits 0-1: bonding (0 - no bonding, 1 - bonding)
} gapSlaveSecurityReqEvent_t;

/**
 * @brief @ref GAP_BOND_COMPLETE_EVENT message format.
 *
* This message is sent to the
 * app when a bonding is complete.  This means that a key is loaded and the link is encrypted.
 */
typedef struct
{
  osal_event_hdr_t  hdr;   //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;            //!< @ref GAP_BOND_COMPLETE_EVENT
  uint16 connectionHandle; //!< connection Handle
} gapBondCompleteEvent_t;

/** @} */ // end of GAP_Events

/// @brief Pairing Request fields - the parsed fields of the SMP Pairing Request command.
typedef struct
{
  uint8 ioCap;         //!< Pairing Request ioCap field
  uint8 oobDataFlag;   //!< Pairing Request OOB Data Flag field
  uint8 authReq;       //!< Pairing Request Auth Req field
  uint8 maxEncKeySize; //!< Pairing Request Maximum Encryption Key Size field
  keyDist_t keyDist;   //!< Pairing Request Key Distribution field
} gapPairingReq_t;

/**
 *  @addtogroup GAP_Events
 *  @{
 */

/**
 * @brief @ref GAP_PAIRING_REQ_EVENT message format.
 *
 * This message is sent to the
 * app when an unexpected Pairing Request is received.  The application is
 * expected to setup for a Security Manager pairing/bonding.
 *
 * To setup an SM Pairing, the application should call GAP_Authenticate() with these "pairReq" fields.<BR>
 *
 * NOTE: This message should only be sent to peripheral devices.
 */
typedef struct
{
  osal_event_hdr_t hdr;    //!< @ref GAP_MSG_EVENT and status
  uint8 opcode;            //!< @ref GAP_PAIRING_REQ_EVENT
  uint16 connectionHandle; //!< connection Handle
  gapPairingReq_t pairReq; //!< The Pairing Request fields received.
} gapPairingReqEvent_t;

/**
 * Report describing connection event Returned via a @ref pfnGapConnEvtCB_t.
 */
typedef struct
{
  GAP_ConnEvtStat_t     status;   //!< status of connection event
  uint16_t              handle;   //!< connection handle
  uint8_t               channel;  //!< BLE RF channel index (0-39)
  int8_t                lastRssi; //!< RSSI of last packet received
  /// Number of packets received for this connection event
  uint16_t              packets;
  /// Total number of CRC errors for the entire connection
  uint16_t              errors;
  /// Type of next BLE task
  GAP_ConnEvtTaskType_t nextTaskType;
  /// Time to next BLE task (in us). 0xFFFFFFFF if there is no next task.
  uint32_t              nextTaskTime;
} Gap_ConnEventRpt_t;

/** @} */ // end of GAP_Events

/**
 * @brief GAP Advertisement/Scan Response Data Token
 *
 * These data items are stored as low byte first (OTA
 * format).  The data space for these items are passed in and maintained by
 * the calling application
 */
typedef struct
{
  uint8 adType;     //!< ADTYPE value: @ref GAP_Addr_Types
  uint8 attrLen;    //!< Number of bytes in the attribute data
  uint8 *pAttrData; //!< pointer to Attribute data
} gapAdvDataToken_t;

/** @} End GAP_Structs */

/** @defgroup GAP_CBs GAP Callbacks
 * @{
 */

/// @brief Enhanced Privacy Check Callback Function
typedef uint8 (*pfnSuppEnhPrivCB_t)
(
  uint8  *deviceAddr                   //!< address of device to check for Enhanced Privacy
);

/// @brief GAP Idle Callback Function
typedef void (*pfnGapIdleCB_t)();

/// @brief Callback Registration Structure
typedef struct
{
  pfnSuppEnhPrivCB_t        supportEnhPrivCB;  //!< Supports Enhanced Privacy callback
  pfnGapIdleCB_t            gapIdleCB;         //!< GAP Idle callback
} gapBondMgrCBs_t;

/**
 * GAP Callback function pointer type for Connection Event notifications.
 *
 * When registered via @ref GAP_RegisterConnEventCb, this callback will return
 * a pointer to a @ref Gap_ConnEventRpt_t from the controller after each
 * connection event
 *
 * @warning The application owns the memory pointed to by pReport. That is, it
 * is responsible for freeing this memory.
 *
 * @warning This is called from the stack task context. Therefore, processing
 * in this callback should be minimized. Any excessive processing should be
 * done by posting an event to the application task context.
 */
typedef void (*pfnGapConnEvtCB_t)
(
  /// Pointer to report describing the connection event
  Gap_ConnEventRpt_t *pReport
);

/** @} End GAP_CBs */

/*-------------------------------------------------------------------
 * GLOBAL VARIABLES
 */

/*-------------------------------------------------------------------
 * FUNCTIONS - Initialization and Configuration
 */

  /**
   * @brief GAP Device Initialiation
   *
   * Setup the device.  Call just once on initialization.
   *
   * @par Corresponding Events:
   * @ref GAP_DEVICE_INIT_DONE_EVENT of type @ref gapDeviceInitDoneEvent_t
   *
   *
   * @param       taskID - task to receive event
   * @param       profileRole - GAP Profile Roles: @ref GAP_Profile_Roles
   * @param       maxScanResponses - maximum number to scan responses
   *                we can receive during a device discovery.
   *                If 0,
   *                  - there will be no limitation of scan responses to receive.
   *                  - payload duplicate filter will not be applied regardless
   *                    of @ref TGAP_FILTER_ADV_REPORTS although filter by address
   *                    can still be applied depending on @ref TGAP_FILTER_ADV_REPORTS.
   *                  - the numDevs parameter coming with GAP_DEVICE_DISCOVERY_EVENT
   *                    will be 0 regardless of how many devices have been actually
   *                    discovered.
   * @param       pIRK - pointer to Identity Root Key, NULLKEY (all zeroes) if the app
   *                wants the GAP to generate the key.
   * @param       pSRK - pointer to Sign Resolving Key, NULLKEY if the app
   *                wants the GAP to generate the key.
   * @param       pSignCounter - 32 bit value used in the SM Signing
   *                algorithm that shall be initialized to zero and incremented
   *                with every new signing. This variable must also be maintained
   *                by the application.
   *
   * @return      @ref SUCCESS - initialization started
   * @return      @ref INVALIDPARAMETER - for invalid profile role or role combination
   * @return      @ref bleIncorrectMode - trouble communicating with HCI
   */
  extern bStatus_t GAP_DeviceInit(  uint8 taskID,
                           uint8 profileRole,
                           uint8 maxScanResponses,
                           uint8 *pIRK,
                           uint8 *pSRK,
                           uint32 *pSignCounter );

  /**
   * @brief Update the resolving list
   *
   * Based on whether the bond manager is included, this will call
   * @ref HCI_LE_SetAddressResolutionEnableCmd directly or go through the bond manager.
   *
   * @param       pIRK - pointer to Identity Root Key, NULLKEY (all zeroes) if the app
   *                wants the GAP to generate the key.
   */
  extern void GAP_UpdateResolvingList( uint8 *pIRK );

  /**
   * @brief Set Advertising Token
   *
   * Called to setup a GAP Advertisement / Scan Response data token.
   *
   * @note
   *        The data in these items are stored as low byte first (OTA format).
   *              The passed in structure "token" should be allocated by the calling app/profile
   *              and not released until after calling @ref GAP_RemoveAdvToken
   *
   * @param       pToken - Advertisement/Scan response token to write.
   *
   * @return      @ref SUCCESS - advertisement token added to the GAP list
   * @return      @ref INVALIDPARAMETER - Invalid Advertisement Type or pAttrData is NULL
   * @return      @ref INVALID_MEM_SIZE - The tokens take up too much space and don't fit into Advertisement data and Scan Response Data
   * @return      @ref bleInvalidRange : token ID already exists.
   * @return      @ref bleIncorrectMode - not a peripheral device
   * @return      @ref bleMemAllocError - memory allocation failure,
   */
  extern bStatus_t GAP_SetAdvToken( gapAdvDataToken_t *pToken );

  /**
   * @brief Get Advertising Token
   *
   * Called to read a GAP Advertisement/Scan Response data token.
   *
   * @param       adType - Advertisement type to get
   *
   * @return      pointer to the advertisement data token structure, NULL if not found.
   */
  extern gapAdvDataToken_t *GAP_GetAdvToken( uint8 adType );

  /**
   * @brief Remove Advertising Token
   *
   * Called to remove a GAP Advertisement/Scan Response data token.
   *
   * @param       adType - Advertisement type to remove
   *
   * @return      pointer to the token structure removed from the GAP ADType list
   * @return      NULL if the requested adType wasn't found.
   */
  extern gapAdvDataToken_t *GAP_RemoveAdvToken( uint8 adType );

  /**
   * @brief Update Advertising Token
   *
   * Called to rebuild and load Advertisement and Scan Response data from existing
   *              GAP Advertisement Tokens.
   *
   * @return      @ref SUCCESS or bleIncorrectMode
   */
  extern bStatus_t GAP_UpdateAdvTokens( void );

 /**
   * @brief       Set a GAP Parameter value
   *
   * Use this function to change
   * the default GAP parameter values.
   *
   * @param       paramID - parameter ID: @ref GAP_Params
   * @param       paramValue - new param value
   *
   * @return      @ref SUCCESS
   * @return      @ref INVALIDPARAMETER
   */
  extern bStatus_t GAP_SetParamValue( gapParamIDs_t paramID, uint16 paramValue );

  /**
   * @brief       Get a GAP Parameter value.
   *
   * @param       paramID - parameter ID: @ref GAP_Params
   *
   * @return      GAP Parameter value
   * @return      0xFFFF if invalid
   */
  extern uint16 GAP_GetParamValue( gapParamIDs_t paramID );

  /**
   * @brief Configure Device Address
   *
   * Setup the device's address type.  If @ref ADDRMODE_PRIVATE_RESOLVE
   *              is selected, the address will change periodically.
   *
   * @note
   * If return value isn't SUCCESS, the address type remains
   * the same as before this call
   *
   * @par Corresponding Events:
   * If the device is correctly configured for @ref ADDRMODE_PRIVATE_NONRESOLVE ,
   * the calling task will receive in case PRIVACY_1_2_CFG Flag is Disabled
   * a @ref GAP_RANDOM_ADDR_CHANGED_EVENT of type
   * @ref gapRandomAddrEvent_t when the random address changes
   *
   * @param       addrMode - @ref Gap_Addr_Modes
   * @param       pStaticAddr - Only used with ADDRMODE_STATIC
   *                       or @ref ADDRMODE_PRIVATE_NONRESOLVE type.<BR>
   *                   NULL to auto generate otherwise the application
   *                   can specify the address value
   *
   * @return      @ref SUCCESS : address type updated
   * @return      @ref bleNotReady : Can't be called until @ref GAP_DeviceInit is called
   *                   and the init process is completed
   * @return       @ref bleIncorrectMode : can't change with an active connection
   * @return       or INVALIDPARAMETER
   */
  extern bStatus_t GAP_ConfigDeviceAddr( uint8 addrMode, uint8 *pStaticAddr );

  /**
   * @brief Register for GAP Messages
   *
   * Register a task ID to receive extra (unprocessed)
   *              HCI status and complete, and Host events.
   *
   * @param       taskID - Default task ID to send events.
   */
  extern void GAP_RegisterForMsgs( uint8 taskID );

  /**
   * @brief       Register bond manager call backs
   *
   * @param       pCBs - pointer to Bond Manager Callbacks.
   */
  extern void GAP_RegisterBondMgrCBs( gapBondMgrCBs_t *pCBs );

/*-------------------------------------------------------------------
 * FUNCTIONS - Device Discovery
 */

  /**
   * @brief       Start a device discovery scan.
   *
   * @param       pParams - Device Discovery parameters
   *
   * @par Corresponding Events:
   * As devices are discovered, the calling app will receive
   * @ref GAP_DEVICE_INFO_EVENT of type @ref gapDeviceInfoEvent_t <br>
   * When disovery is complete, the calling app will receive
   * a @ref GAP_DEVICE_DISCOVERY_EVENT of type @ref gapDevDiscEvent_t
   *
   * @return      @ref SUCCESS : scan request sent to stakc
   * @return      @ref bleIncorrectMode : invalid profile role
   * @return      @ref bleAlreadyInRequestedMode : not available
   */
  extern bStatus_t GAP_DeviceDiscoveryRequest( gapDevDiscReq_t *pParams );

  /**
   * @brief       Cancel an existing device discovery request.
   *
   * @par Corresponding Events:
   * When disovery is complete, the calling app will receive
   * a @ref GAP_DEVICE_DISCOVERY_EVENT of type @ref gapDevDiscEvent_t
   *
   * @param       taskID - task to receive event
   *
   * @return      @ref SUCCESS : cancel request sent to stack
   * @return      @ref bleInvalidTaskID : Not the task that started discovery
   * @return      @ref bleIncorrectMode : not in discovery mode
   */
  extern bStatus_t GAP_DeviceDiscoveryCancel( uint8 taskID );

  /**
   * @brief       Setup or change advertising.  Also starts advertising.
   *
   * @par Corresponding Events:
   * @ref GAP_MAKE_DISCOVERABLE_DONE_EVENT  of type @ref gapMakeDiscoverableRspEvent_t
   *
   * @param       taskID - task to receive event
   * @param       pParams - advertising parameters
   *
   * @return      @ref SUCCESS : advertising request sent to stack
   * @return      @ref bleIncorrectMode : invalid profile role
   * @return      @ref bleAlreadyInRequestedMode : already advertising
   * @return      @ref bleNotReady : advertising data isn't set up yet
   */
  extern bStatus_t GAP_MakeDiscoverable( uint8 taskID, gapAdvertisingParams_t *pParams );

  /**
   * @brief       Setup or change advertising and scan response data.
   *
   * @par Corresponding Events:
   * @ref GAP_ADV_DATA_UPDATE_DONE_EVENT of type @ref gapAdvDataUpdateEvent_t
   *
   * @param       taskID - task to receive event
   * @param       adType - TRUE - advertisement data, FALSE  - scan response data
   * @param       dataLen - Octet length of advertData
   * @param       pAdvertData - advertising or scan response data
   *
   * @return      @ref SUCCESS : advertising data sent to stack
   * @return      @ref bleIncorrectMode : invalid profile role
   */
  extern bStatus_t GAP_UpdateAdvertisingData( uint8 taskID, uint8 adType,
                                      uint8 dataLen, uint8 *pAdvertData );

  /**
   * @brief       Stops advertising.
   *
   * @par Corresponding Events:
   * @ref GAP_END_DISCOVERABLE_DONE_EVENT of type @ref gapEndDiscoverableRspEvent_t
   *
   * @param       taskID - task to receive event
   *
   * @return      @ref SUCCESS : discovery cancel sent to stack
   * @return      @ref bleIncorrectMode : not in discoverable mode
   * @return      @ref bleInvalidTaskID : not correct task
   */
  extern bStatus_t GAP_EndDiscoverable( uint8 taskID );

#if !defined (BLE_V42_FEATURES) || !(BLE_V42_FEATURES & PRIVACY_1_2_CFG)
  /**
   * @brief       Resolves a private address against an IRK.
   *
   * @param       pIRK - pointer to the IRK
   * @param       pAddr - pointer to the Resolvable Private address
   *
   * @return      @ref SUCCESS : match
   * @return      @ref FAILURE : don't match
   * @return      @ref INVALIDPARAMETER : parameters invalid
   */
  extern bStatus_t GAP_ResolvePrivateAddr( uint8 *pIRK, uint8 *pAddr );
#endif // ! BLE_V42_FEATURES | ! PRIVACY_1_2_CFG

/*-------------------------------------------------------------------
 * FUNCTIONS - Link Establishment
 */

  /**
   * @brief       Establish a link to a slave device.
   *
   * @par Corresponding Events:
   * @ref GAP_LINK_ESTABLISHED_EVENT of type @ref gapEstLinkReqEvent_t
   *
   * @param       pParams - link establishment parameters
   *
   * @return      @ref SUCCESS : connection request sent to stack
   * @return      @ref bleIncorrectMode : invalid profile role
   * @return      @ref bleNotReady : a scan is in progress
   * @return      @ref bleAlreadyInRequestedMode : can't process now
   * @return      @ref bleNoResources : Too many links
   */
  extern bStatus_t GAP_EstablishLinkReq( gapEstLinkReq_t *pParams );

  /**
   * @brief       Terminate a link connection.
   *
   * @par Corresponding Events:
   * @ref GAP_LINK_TERMINATED_EVENT of type @ref gapTerminateLinkEvent_t
   *
   * @param       taskID - requesting app's task id.
   * @param       connectionHandle - connection handle of link to terminate
   *                  or @ref GAP_Conn_Handle
   * @param       reason - terminate reason.
   *
   * @return      @ref SUCCESS : termination request sent to stack
   * @return      @ref bleIncorrectMode : No Link to terminate
   * @return      @ref bleInvalidTaskID : not app that established link
   */
  extern bStatus_t GAP_TerminateLinkReq( uint8 taskID, uint16 connectionHandle, uint8 reason );

  /**
   * @brief Update the link parameters to a Master or Slave device.
   *
   * @par Corresponding Events:
   * After the update procedure is complete, the calling task will receive a
   * @ref GAP_LINK_PARAM_UPDATE_EVENT of type @ref gapLinkUpdateEvent_t
   *
   * @param pParams link update parameters
   *
   * @return @ref SUCCESS : update request sent to stack
   * @return @ref INVALIDPARAMETER : one of the parameters were invalid
   * @return @ref bleIncorrectMode : invalid profile role
   * @return @ref bleAlreadyInRequestedMode : already updating link parameters
   * @return @ref bleNotConnected : not in a connection
   */
  extern bStatus_t GAP_UpdateLinkParamReq( gapUpdateLinkParamReq_t *pParams );

  /**
   * @brief Reply to a Connection Parameter Update Request sent from a peer
   * device.
   *
   * @par Corresponding Events:
   * The calling task should call this API in response to a
   * @ref GAP_UPDATE_LINK_PARAM_REQ_EVENT of type
   * @ref gapUpdateLinkParamReqEvent_t
   *
   * The host should fill in the connection parameters it desires as well as
   * whether or not this request was accepted. The controller will use the
   * connection parameters passed into this command to respond over-the-air to
   * the peer.
   *
   * After the update procedure is complete, the calling task will receive a
   * @ref GAP_LINK_PARAM_UPDATE_EVENT of type @ref gapLinkUpdateEvent_t
   *
   * @param       pParams - local device's desired connection parameters.
   *
   * @return      @ref SUCCESS : reply sent successfully
   * @return      @ref INVALIDPARAMETER : one of the parameters were invalid
   * @return      @ref bleIncorrectMode : invalid profile role
   * @return      @ref bleAlreadyInRequestedMode : already updating link parameters
   * @return      @ref bleNotConnected : not in a connection
   */
  extern bStatus_t GAP_UpdateLinkParamReqReply(gapUpdateLinkParamReqReply_t *pParams);

  /**
   * @brief       Returns the number of active connections.
   *
   * @return      Number of active connections.
   */
  extern uint8 GAP_NumActiveConnections( void );

 /**
* Register/Unregister a connection event callback
*
* It is only possible to register for one connection handle of for all
* connection handles. In the case of unregistering, it does not matter what
* connHandle or cb is passed in as whatever is currently registered will be
* unregistered.
*
* @warning The application owns the memory pointed to by pReport in
* @ref pfnGapConnEvtCB_t. That is, it is responsible for freeing this memory.
*
* @note The callback needs to be registered for each reconnection. It is not
* retained across a disconnect / reconnect.
*
* @param cb Function pointer to a callback.
* @param action Register or unregister the callback.
* @param connHandle if @ref LINKDB_CONNHANDLE_ALL, apply to all connections. <br>
*        else, apply only for a specific connection.
*
* @return @ref SUCCESS
* @return @ref bleGAPNotFound : connection handle not found
* @return @ref bleInvalidRange : the callback function was NULL or action is
*         invalid
* @return @ref bleMemAllocError : there is not enough memory to register the callback.
*/
extern bStatus_t GAP_RegisterConnEventCb(pfnGapConnEvtCB_t cb,
                                         GAP_CB_Action_t action,
                                         uint16_t connHandle);



/*-------------------------------------------------------------------
 * FUNCTIONS - Pairing
 */

  /**
   * @brief  Start Authentication
   *
   * Start the Authentication process with the requested device.
   *              This function is used to Initiate/Allow pairing.
   *              Called by both master and slave device (Central and Peripheral).
   *
   * @note
   *        This function must only be called after the link is established.
   *
   * @par Corresponding Events:
   * After pairing is completed succesfully, the calling task will receive a
   * @ref GAP_AUTHENTICATION_COMPLETE_EVENT of type @ref gapAuthCompleteEvent_t <br>
   * After a failed pairing, the calling task will receive a
   * @ref GAP_AUTHENTICATION_FAILURE_EVT
   *
   * @param       pParams - Authentication parameters
   * @param       pPairReq - Enter these parameters if the Pairing Request was already received.
   *              NULL, if waiting for Pairing Request or if initiating.
   *
   * @return      @ref SUCCESS - authentication request sent to stack
   * @return      @ref bleIncorrectMode : Not correct profile role
   * @return      @ref INVALIDPARAMETER
   * @return      @ref bleNotConnected
   * @return      @ref bleAlreadyInRequestedMode
   * @return      @ref FAILURE - not workable
   */
  extern bStatus_t GAP_Authenticate( gapAuthParams_t *pParams, gapPairingReq_t *pPairReq );

  /**
   * @brief       Check if GAP is currently pairing.
   *
   * @return      TRUE if pairing
   * @return      FALSE otherwise
   */
  extern uint8 GAP_isPairing(void);

  /**
   * @brief       Terminate Authnetication
   *
   * Send a Pairing Failed message and end any existing pairing.
   *
   * @par Corresponding Events:
   * @ref GAP_AUTHENTICATION_FAILURE_EVT
   *
   * @param       connectionHandle - connection handle.
   * @param       reason - Pairing Failed reason code.
   *
   * @return      @ref SUCCESS - function was successful
   * @return      @ref bleMemAllocError - memory allocation error
   * @return      @ref INVALIDPARAMETER - one of the parameters were invalid
   * @return      @ref bleNotConnected - link not found
   * @return      @ref bleInvalidRange : one of the parameters were not within range.
   */
  extern bStatus_t GAP_TerminateAuth( uint16 connectionHandle, uint8 reason );

  /**
   * @brief       Update the passkey in string format.
   *
   * @note
   * This function is the same as @ref GAP_PasscodeUpdate , except that
   *              the passkey is passed in as a string format.
   *
   * @note: Corresponding Events:
   * This API should be called in response to receiving a
   * @ref GAP_PASSKEY_NEEDED_EVENT of type gapPasskeyNeededEvent_t
   *
   * @param       pPasskey - new passkey - pointer to numeric string (ie. "019655" )
   *              This string's range is "000000" to "999999"
   * @param       connectionHandle - connection handle.
   *
   * @return      @ref SUCCESS : will start pairing with this entry
   * @return      @ref bleIncorrectMode : Link not found
   * @return      @ref INVALIDPARAMETER : passkey == NULL or passkey isn't formatted properly
   */
  extern bStatus_t GAP_PasskeyUpdate( uint8 *pPasskey, uint16 connectionHandle );

  /**
   * @brief       Update the passkey in a numeric value (not string).
   *
   * @note
   * This function is the same as GAP_PasskeyUpdate(), except that
   * the passkey is passed in as a non-string format.
   *
   * @note: Corresponding Events:
   * This API should be called in response to receiving a
   * @ref GAP_PASSKEY_NEEDED_EVENT of type gapPasskeyNeededEvent_t
   *
   * @param       passcode - not string - range: 0 - 999,999.
   * @param       connectionHandle - connection handle.
   *
   * @return      @ref SUCCESS : will start pairing with this entry
   * @return      @ref bleIncorrectMode : Link not found
   * @return      @ref INVALIDPARAMETER : passkey == NULL or passkey isn't formatted properly
   */
  extern bStatus_t GAP_PasscodeUpdate( uint32 passcode, uint16 connectionHandle );

  /**
   * @brief       Generate a Slave Requested Security message to the master.
   *
   * This API can be used to initiate security as a slave.
   *
   * @param       connectionHandle - connection handle.
   * @param       authReq - Authentication Requirements: Bit 2: MITM,
   *                        Bits 0-1: bonding (0 - no bonding, 1 - bonding)
   *                        Bit 3: Secure Connections
   *
   * @return      @ref SUCCESS : will send
   * @return      @ref bleNotConnected : Link not found
   * @return      @ref bleIncorrectMode : wrong GAP role, must be a Peripheral Role
   */
  extern bStatus_t GAP_SendSlaveSecurityRequest( uint16 connectionHandle, uint8 authReq );

  /**
   * @brief       Set up the connection to accept signed data.
   *
   * @note
   * This function is called after the link is established.
   *
   * @param       connectionHandle - connection handle of the signing information
   * @param       authenticated - TRUE if the signing information is authenticated, FALSE otherwise
   * @param       pParams - signing parameters
   *
   * @return      @ref SUCCESS
   * @return      @ref bleIncorrectMode : Not correct profile role
   * @return      @ref INVALIDPARAMETER
   * @return      @ref bleNotConnected
   * @return      @ref FAILURE : not workable.
   */
  extern bStatus_t GAP_Signable( uint16 connectionHandle, uint8 authenticated, smSigningInfo_t *pParams );

  /**
   * @brief       Set up the connection's bound paramaters.
   *
   * @note
   * This function must only called after the link is established.
   *
   * @par Corresponding Events:
   * @ref GAP_BOND_COMPLETE_EVENT of type @ref gapBondCompleteEvent_t
   *
   * @param       connectionHandle - connection handle of the signing information
   * @param       authenticated - TRUE if bond is authenticated.
   * @param       secureConnections - TRUE if bond has Secure Connections strength.
   * @param       pParams - the connected device's security parameters
   * @param       startEncryption - whether or not to start encryption
   *
   * @return      @ref SUCCESS, <BR>
   * @return      @ref bleIncorrectMode : Not correct profile role
   * @return      @ref INVALIDPARAMETER
   * @return      @ref bleNotConnected
   * @return      @ref FAILURE : not workable
   */
  extern bStatus_t GAP_Bond( uint16 connectionHandle, uint8 authenticated,
                             uint8 secureConnections, smSecurityInfo_t *pParams,
                             uint8 startEncryption );

/*-------------------------------------------------------------------
 * Internal API - These functions are only called from gap.c module.
 */

/// @cond NODOC

  /**
   * @internal
   *
   * @brief       Setup the device configuration parameters.
   *
   * @param       taskID - Default task ID to send events.
   * @param       profileRole - GAP Profile Roles
   *
   * @return      @ref SUCCESS or bleIncorrectMode
   */
  extern bStatus_t GAP_ParamsInit( uint8 taskID, uint8 profileRole );

  /**
   * @internal
   *
   * @brief       Setup the device privacy parameters.
   *
   * @param       pIRK - pointer to Identity Resolving Key
   */
  extern void GAP_PrivacyInit( uint8 *pIRK );

  /**
   * @internal
   *
   * @brief       Get the device's IRK
   *
   * @return      pointer to IRK
   */
  extern uint8 *GAP_GetIRK( void );

  /**
   * @internal
   *
   * @brief       Setup the device security configuration parameters.
   *
   * @param       pSRK - pointer to Sign Resolving Key, NULLKEY if the app
   *                wants the GAP to generate the key.
   * @param       pSignCounter - 32 bit value used in the SM Signing
   *                algorithm that shall be initialized to zero and incremented
   *                with every new signing. This variable must also be maintained
   *                by the application.
   */
  extern void GAP_SecParamsInit( uint8 *pSRK, uint32 *pSignCounter );

  /**
   * @internal
   *
   * @brief       Initialize the GAP Peripheral Dev Manager.
   *
   * @return      @ref SUCCESS or bleMemAllocError
   */
  extern bStatus_t GAP_PeriDevMgrInit( void );

 /**
   * @internal
   *
   * @brief       Register the GAP Peripheral Connection processing functions.
   *
   */
  extern void GAP_PeriConnRegister( void );

  /**
   * @internal
   *
   * @brief       Initialize the GAP Central Dev Manager.
   *
   * @param       maxScanResponses - maximum number to scan responses
   *                we can receive during a device discovery.
   *
   * @return      @ref SUCCESS
   * @return      @ref bleMemAllocError
   */
  extern bStatus_t GAP_CentDevMgrInit( uint8 maxScanResponses );

  /**
   * @internal
   *
   * @brief       Register the GAP Central Connection processing functions.
   *
   */
  extern void GAP_CentConnRegister( void );


/*-------------------------------------------------------------------
 * TASK API - These functions must only be called OSAL.
 */

  /**
   * @internal
   *
   * @brief       GAP Task initialization function.
   *
   * @param       taskID - GAP task ID.
   */
  extern void GAP_Init( uint8 task_id );

  /**
   * @internal
   *
   * @brief       GAP Task event processing function.
   *
   * @param       taskID - GAP task ID
   * @param       events - GAP events.
   *
   * @return      events not processed
   */
  extern uint16 GAP_ProcessEvent( uint8 task_id, uint16 events );

/// @endcond // NODOC

/*-------------------------------------------------------------------
-------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* GAP_H */

/** @} End GAP */
