/*
 * \file ds3231_events.h
 * \brief Ds3231 Events
 *
 * This file defines event IDs for Ds3231,
 * specifically the DS3231. These ID represent various status changes
 * or general events from the device.
 *
 * Software License Agreement:
 * 
 * This code is proprietary to Embedd Limited and may not be distributed
 * or copied without the express permission of Embedd Limited. This code
 * is provided "as is" without warranty of any kind, either expressed or
 * implied, including but not limited to the implied warranties of
 * merchantability and fitness for a particular purpose. This code is intended
 * for use only by the employees and authorized agents of Embedd Limited
 * and its affiliates, and may not be disclosed or used for any other purpose
 * without prior written consent from Embedd Limited.
 * 
 * Unauthorized distribution or use of this code, or any portion of it, may
 * result in severe civil and criminal penalties, and will be prosecuted to
 * the maximum extent possible under the law.
 * 
 * © 2024 Embedd Limited. All Rights Reserved.
 */
#ifndef _SRC_DS3231_EVENTS_H
#define _SRC_DS3231_EVENTS_H

#include <stdint.h>
#include "embedd_driver.h"

enum {
/* -------------------------------------------------------------------------- 
 * Event name: Alarm 1 Match
 * Event description: Triggered by a match between the timekeeping registers and Alarm 1 registers.
 * -------------------------------------------------------------------------- */
  DS3231_ALARM_1_MATCH_EVENT_ID = 0x98d83c6e,
/* -------------------------------------------------------------------------- 
 * Event name: Alarm 2 Match
 * Event description: Triggered by a match between the timekeeping registers and Alarm 2 registers.
 * -------------------------------------------------------------------------- */
  DS3231_ALARM_2_MATCH_EVENT_ID = 0xb110889c,
};

#endif//_SRC_DS3231_EVENTS_H
