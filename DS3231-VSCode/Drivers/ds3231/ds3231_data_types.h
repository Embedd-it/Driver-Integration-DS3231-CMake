/*!
 * \file ds3231_data_types.h
 * \brief Ds3231 data types
 *
 * This file contains all the information about Ds3231 specific data types.
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

#ifndef _SRC_DS3231_DATA_TYPES_H
#define _SRC_DS3231_DATA_TYPES_H

#include <stdint.h>
#include "embedd_driver.h"
#include "embedd_hal.h"

/* -------------------------------------------------------------------------- 
 * DATA types
 * -------------------------------------------------------------------------- */
#pragma pack(push, 1)


/*!
 * \struct ds3231_seconds_t
 * \brief This register contains the seconds value in BCD format.
 *
 * \var seconds Represents the seconds value in BCD format.
 * \var 10_seconds Stores the tens place of the seconds value.
 * \var reserved Reserved bit, should be set to 0.
 */
typedef struct {
  // Represents the seconds value in BCD format.
  uint8_t seconds:4;
  // Stores the tens place of the seconds value.
  uint8_t _10_seconds:3;
  // Reserved bit, should be set to 0.
  uint8_t reserved:1;
} ds3231_seconds_t;

/*!
 * \def DS3231_SECONDS_SECONDS_VALID_RANGE_FOR_SECONDS
 * \brief Represents the seconds value in BCD format.
*/
#define DS3231_SECONDS_SECONDS_VALID_RANGE_FOR_SECONDS 89


/*!
 * \macro DS3231_SECONDS_SECONDS_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_seconds_t_seconds type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_SECONDS_SECONDS_VALID(val) (\
  (val) == DS3231_SECONDS_SECONDS_VALID_RANGE_FOR_SECONDS ||\
  0)

/*!
 * \def DS3231_SECONDS_RESERVED_RESERVED
 * \brief Reserved bit, should be set to 0.
*/
#define DS3231_SECONDS_RESERVED_RESERVED 0


/*!
 * \macro DS3231_SECONDS_RESERVED_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_seconds_t_reserved type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_SECONDS_RESERVED_VALID(val) (\
  (val) == DS3231_SECONDS_RESERVED_RESERVED ||\
  0)

/*!
 * \struct ds3231_minutes_t
 * \brief Stores the minutes value of the current time.
 *
 * \var minutes Stores the units place of the minutes value.
 * \var 10_minutes Stores the tens place of the minutes value.
 * \var reserved Reserved field as space was unfilled
 */
typedef struct {
  // Stores the units place of the minutes value.
  uint8_t minutes:4;
  // Stores the tens place of the minutes value.
  uint8_t _10_minutes:3;
  // Reserved field as space was unfilled
  uint8_t reserved:1;
} ds3231_minutes_t;

/*!
 * \def DS3231_MINUTES_MINUTES_0
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_0 0

/*!
 * \def DS3231_MINUTES_MINUTES_1
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_1 1

/*!
 * \def DS3231_MINUTES_MINUTES_2
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_2 2

/*!
 * \def DS3231_MINUTES_MINUTES_3
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_3 3

/*!
 * \def DS3231_MINUTES_MINUTES_4
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_4 4

/*!
 * \def DS3231_MINUTES_MINUTES_5
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_5 5

/*!
 * \def DS3231_MINUTES_MINUTES_6
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_6 6

/*!
 * \def DS3231_MINUTES_MINUTES_7
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_7 7

/*!
 * \def DS3231_MINUTES_MINUTES_8
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_8 8

/*!
 * \def DS3231_MINUTES_MINUTES_9
 * \brief Stores the units place of the minutes value.
*/
#define DS3231_MINUTES_MINUTES_9 9


/*!
 * \macro DS3231_MINUTES_MINUTES_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_minutes_t_minutes type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_MINUTES_MINUTES_VALID(val) (\
  (val) == DS3231_MINUTES_MINUTES_0 ||\
  (val) == DS3231_MINUTES_MINUTES_1 ||\
  (val) == DS3231_MINUTES_MINUTES_2 ||\
  (val) == DS3231_MINUTES_MINUTES_3 ||\
  (val) == DS3231_MINUTES_MINUTES_4 ||\
  (val) == DS3231_MINUTES_MINUTES_5 ||\
  (val) == DS3231_MINUTES_MINUTES_6 ||\
  (val) == DS3231_MINUTES_MINUTES_7 ||\
  (val) == DS3231_MINUTES_MINUTES_8 ||\
  (val) == DS3231_MINUTES_MINUTES_9 ||\
  0)

/*!
 * \def DS3231_MINUTES_10_MINUTES_0
 * \brief Stores the tens place of the minutes value.
*/
#define DS3231_MINUTES_10_MINUTES_0 0

/*!
 * \def DS3231_MINUTES_10_MINUTES_1
 * \brief Stores the tens place of the minutes value.
*/
#define DS3231_MINUTES_10_MINUTES_1 1

/*!
 * \def DS3231_MINUTES_10_MINUTES_2
 * \brief Stores the tens place of the minutes value.
*/
#define DS3231_MINUTES_10_MINUTES_2 2

/*!
 * \def DS3231_MINUTES_10_MINUTES_3
 * \brief Stores the tens place of the minutes value.
*/
#define DS3231_MINUTES_10_MINUTES_3 3

/*!
 * \def DS3231_MINUTES_10_MINUTES_4
 * \brief Stores the tens place of the minutes value.
*/
#define DS3231_MINUTES_10_MINUTES_4 4

/*!
 * \def DS3231_MINUTES_10_MINUTES_5
 * \brief Stores the tens place of the minutes value.
*/
#define DS3231_MINUTES_10_MINUTES_5 5


/*!
 * \macro DS3231_MINUTES_10_MINUTES_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_minutes_t_10_minutes type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_MINUTES_10_MINUTES_VALID(val) (\
  (val) == DS3231_MINUTES_10_MINUTES_0 ||\
  (val) == DS3231_MINUTES_10_MINUTES_1 ||\
  (val) == DS3231_MINUTES_10_MINUTES_2 ||\
  (val) == DS3231_MINUTES_10_MINUTES_3 ||\
  (val) == DS3231_MINUTES_10_MINUTES_4 ||\
  (val) == DS3231_MINUTES_10_MINUTES_5 ||\
  0)

/*!
 * \struct ds3231_hour_t
 * \brief Hour register for timekeeping
 *
 * \var hour Hour digit of the hour
 * \var 10_hour 10-hour digit of the hour
 * \var ampm20hour AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
 * \var 1224 12-hour or 24-hour mode select bit
 * \var reserved Reserved field as space was unfilled
 */
typedef struct {
  // Hour digit of the hour
  uint8_t hour:4;
  // 10-hour digit of the hour
  uint8_t _10_hour:1;
  // AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
  uint8_t ampm20hour:1;
  // 12-hour or 24-hour mode select bit
  uint8_t _1224:1;
  // Reserved field as space was unfilled
  uint8_t reserved:1;
} ds3231_hour_t;

/*!
 * \def DS3231_HOUR_HOUR_0
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_0 0

/*!
 * \def DS3231_HOUR_HOUR_1
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_1 1

/*!
 * \def DS3231_HOUR_HOUR_2
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_2 10

/*!
 * \def DS3231_HOUR_HOUR_3
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_3 11

/*!
 * \def DS3231_HOUR_HOUR_4
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_4 4

/*!
 * \def DS3231_HOUR_HOUR_5
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_5 5

/*!
 * \def DS3231_HOUR_HOUR_6
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_6 6

/*!
 * \def DS3231_HOUR_HOUR_7
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_7 7

/*!
 * \def DS3231_HOUR_HOUR_8
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_8 8

/*!
 * \def DS3231_HOUR_HOUR_9
 * \brief Hour digit of the hour
*/
#define DS3231_HOUR_HOUR_9 9


/*!
 * \macro DS3231_HOUR_HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_hour_t_hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_HOUR_HOUR_VALID(val) (\
  (val) == DS3231_HOUR_HOUR_0 ||\
  (val) == DS3231_HOUR_HOUR_1 ||\
  (val) == DS3231_HOUR_HOUR_2 ||\
  (val) == DS3231_HOUR_HOUR_3 ||\
  (val) == DS3231_HOUR_HOUR_4 ||\
  (val) == DS3231_HOUR_HOUR_5 ||\
  (val) == DS3231_HOUR_HOUR_6 ||\
  (val) == DS3231_HOUR_HOUR_7 ||\
  (val) == DS3231_HOUR_HOUR_8 ||\
  (val) == DS3231_HOUR_HOUR_9 ||\
  0)

/*!
 * \def DS3231_HOUR_10_HOUR_09_HOURS
 * \brief 10-hour digit of the hour
*/
#define DS3231_HOUR_10_HOUR_09_HOURS 0

/*!
 * \def DS3231_HOUR_10_HOUR_1019_HOURS
 * \brief 10-hour digit of the hour
*/
#define DS3231_HOUR_10_HOUR_1019_HOURS 1


/*!
 * \macro DS3231_HOUR_10_HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_hour_t_10_hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_HOUR_10_HOUR_VALID(val) (\
  (val) == DS3231_HOUR_10_HOUR_09_HOURS ||\
  (val) == DS3231_HOUR_10_HOUR_1019_HOURS ||\
  0)

/*!
 * \def DS3231_HOUR_AMPM20HOUR_AM
 * \brief AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
*/
#define DS3231_HOUR_AMPM20HOUR_AM 0

/*!
 * \def DS3231_HOUR_AMPM20HOUR_PM
 * \brief AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
*/
#define DS3231_HOUR_AMPM20HOUR_PM 1


/*!
 * \macro DS3231_HOUR_AMPM20HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_hour_t_ampm20hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_HOUR_AMPM20HOUR_VALID(val) (\
  (val) == DS3231_HOUR_AMPM20HOUR_AM ||\
  (val) == DS3231_HOUR_AMPM20HOUR_PM ||\
  0)

/*!
 * \def DS3231_HOUR_1224_24HOUR_MODE
 * \brief 12-hour or 24-hour mode select bit
*/
#define DS3231_HOUR_1224_24HOUR_MODE 0

/*!
 * \def DS3231_HOUR_1224_12HOUR_MODE
 * \brief 12-hour or 24-hour mode select bit
*/
#define DS3231_HOUR_1224_12HOUR_MODE 1


/*!
 * \macro DS3231_HOUR_1224_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_hour_t_1224 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_HOUR_1224_VALID(val) (\
  (val) == DS3231_HOUR_1224_24HOUR_MODE ||\
  (val) == DS3231_HOUR_1224_12HOUR_MODE ||\
  0)

/*!
 * \struct ds3231_day_t
 * \brief Day register
 *
 * \var day Day of the week
 * \var reserved Reserved bits
 */
typedef struct {
  // Day of the week
  uint8_t day:3;
  // Reserved bits
  uint8_t reserved:5;
} ds3231_day_t;

/*!
 * \def DS3231_DAY_DAY_SUNDAY
 * \brief Day of the week
*/
#define DS3231_DAY_DAY_SUNDAY 0

/*!
 * \def DS3231_DAY_DAY_MONDAY
 * \brief Day of the week
*/
#define DS3231_DAY_DAY_MONDAY 1

/*!
 * \def DS3231_DAY_DAY_TUESDAY
 * \brief Day of the week
*/
#define DS3231_DAY_DAY_TUESDAY 2

/*!
 * \def DS3231_DAY_DAY_WEDNESDAY
 * \brief Day of the week
*/
#define DS3231_DAY_DAY_WEDNESDAY 3

/*!
 * \def DS3231_DAY_DAY_THURSDAY
 * \brief Day of the week
*/
#define DS3231_DAY_DAY_THURSDAY 4

/*!
 * \def DS3231_DAY_DAY_FRIDAY
 * \brief Day of the week
*/
#define DS3231_DAY_DAY_FRIDAY 5

/*!
 * \def DS3231_DAY_DAY_SATURDAY
 * \brief Day of the week
*/
#define DS3231_DAY_DAY_SATURDAY 6


/*!
 * \macro DS3231_DAY_DAY_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_day_t_day type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_DAY_DAY_VALID(val) (\
  (val) == DS3231_DAY_DAY_SUNDAY ||\
  (val) == DS3231_DAY_DAY_MONDAY ||\
  (val) == DS3231_DAY_DAY_TUESDAY ||\
  (val) == DS3231_DAY_DAY_WEDNESDAY ||\
  (val) == DS3231_DAY_DAY_THURSDAY ||\
  (val) == DS3231_DAY_DAY_FRIDAY ||\
  (val) == DS3231_DAY_DAY_SATURDAY ||\
  0)

/*!
 * \struct ds3231_date_t
 * \brief Holds the date of the month
 *
 * \var rsv_0 Reserved bit
 * \var date Units place of the date
 * \var 10_date Tens place of the date
 * \var rsv_1 Reserved bits
 */
typedef struct {
  // Reserved bit
  uint8_t rsv_0:1;
  // Units place of the date
  uint8_t date:4;
  // Tens place of the date
  uint8_t _10_date:1;
  // Reserved bits
  uint8_t rsv_1:2;
} ds3231_date_t;

/*!
 * \def DS3231_DATE_RSV_0_RESERVED
 * \brief Reserved bit
*/
#define DS3231_DATE_RSV_0_RESERVED 0


/*!
 * \macro DS3231_DATE_RSV_0_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_date_t_rsv_0 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_DATE_RSV_0_VALID(val) (\
  (val) == DS3231_DATE_RSV_0_RESERVED ||\
  0)

/*!
 * \def DS3231_DATE_DATE_0
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_0 0

/*!
 * \def DS3231_DATE_DATE_1
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_1 1

/*!
 * \def DS3231_DATE_DATE_2
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_2 2

/*!
 * \def DS3231_DATE_DATE_3
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_3 3

/*!
 * \def DS3231_DATE_DATE_4
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_4 4

/*!
 * \def DS3231_DATE_DATE_5
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_5 5

/*!
 * \def DS3231_DATE_DATE_6
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_6 6

/*!
 * \def DS3231_DATE_DATE_7
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_7 7

/*!
 * \def DS3231_DATE_DATE_8
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_8 8

/*!
 * \def DS3231_DATE_DATE_9
 * \brief Units place of the date
*/
#define DS3231_DATE_DATE_9 9


/*!
 * \macro DS3231_DATE_DATE_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_date_t_date type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_DATE_DATE_VALID(val) (\
  (val) == DS3231_DATE_DATE_0 ||\
  (val) == DS3231_DATE_DATE_1 ||\
  (val) == DS3231_DATE_DATE_2 ||\
  (val) == DS3231_DATE_DATE_3 ||\
  (val) == DS3231_DATE_DATE_4 ||\
  (val) == DS3231_DATE_DATE_5 ||\
  (val) == DS3231_DATE_DATE_6 ||\
  (val) == DS3231_DATE_DATE_7 ||\
  (val) == DS3231_DATE_DATE_8 ||\
  (val) == DS3231_DATE_DATE_9 ||\
  0)

/*!
 * \def DS3231_DATE_10_DATE_0
 * \brief Tens place of the date
*/
#define DS3231_DATE_10_DATE_0 0

/*!
 * \def DS3231_DATE_10_DATE_1
 * \brief Tens place of the date
*/
#define DS3231_DATE_10_DATE_1 1

/*!
 * \def DS3231_DATE_10_DATE_2
 * \brief Tens place of the date
*/
#define DS3231_DATE_10_DATE_2 2

/*!
 * \def DS3231_DATE_10_DATE_3
 * \brief Tens place of the date
*/
#define DS3231_DATE_10_DATE_3 3


/*!
 * \macro DS3231_DATE_10_DATE_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_date_t_10_date type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_DATE_10_DATE_VALID(val) (\
  (val) == DS3231_DATE_10_DATE_0 ||\
  (val) == DS3231_DATE_10_DATE_1 ||\
  (val) == DS3231_DATE_10_DATE_2 ||\
  (val) == DS3231_DATE_10_DATE_3 ||\
  0)

/*!
 * \def DS3231_DATE_RSV_1_RESERVED
 * \brief Reserved bits
*/
#define DS3231_DATE_RSV_1_RESERVED 0


/*!
 * \macro DS3231_DATE_RSV_1_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_date_t_rsv_1 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_DATE_RSV_1_VALID(val) (\
  (val) == DS3231_DATE_RSV_1_RESERVED ||\
  0)

/*!
 * \struct ds3231_monthcentury_t
 * \brief Month and century register
 *
 * \var month Month value
 * \var 10_month Tens place of the month
 * \var rsv Reserved bits
 * \var century Century bit
 */
typedef struct {
  // Month value
  uint8_t month:4;
  // Tens place of the month
  uint8_t _10_month:1;
  // Reserved bits
  uint8_t rsv:2;
  // Century bit
  uint8_t century:1;
} ds3231_monthcentury_t;

/*!
 * \def DS3231_MONTHCENTURY_MONTH_JANUARY
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_JANUARY 1

/*!
 * \def DS3231_MONTHCENTURY_MONTH_OCTOBER
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_OCTOBER 10

/*!
 * \def DS3231_MONTHCENTURY_MONTH_NOVEMBER
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_NOVEMBER 11

/*!
 * \def DS3231_MONTHCENTURY_MONTH_APRIL
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_APRIL 4

/*!
 * \def DS3231_MONTHCENTURY_MONTH_MAY
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_MAY 5

/*!
 * \def DS3231_MONTHCENTURY_MONTH_JUNE
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_JUNE 6

/*!
 * \def DS3231_MONTHCENTURY_MONTH_JULY
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_JULY 7

/*!
 * \def DS3231_MONTHCENTURY_MONTH_AUGUST
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_AUGUST 8

/*!
 * \def DS3231_MONTHCENTURY_MONTH_SEPTEMBER
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_SEPTEMBER 9

/*!
 * \def DS3231_MONTHCENTURY_MONTH_DECEMBER
 * \brief Month value
*/
#define DS3231_MONTHCENTURY_MONTH_DECEMBER 12


/*!
 * \macro DS3231_MONTHCENTURY_MONTH_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_monthcentury_t_month type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_MONTHCENTURY_MONTH_VALID(val) (\
  (val) == DS3231_MONTHCENTURY_MONTH_JANUARY ||\
  (val) == DS3231_MONTHCENTURY_MONTH_OCTOBER ||\
  (val) == DS3231_MONTHCENTURY_MONTH_NOVEMBER ||\
  (val) == DS3231_MONTHCENTURY_MONTH_APRIL ||\
  (val) == DS3231_MONTHCENTURY_MONTH_MAY ||\
  (val) == DS3231_MONTHCENTURY_MONTH_JUNE ||\
  (val) == DS3231_MONTHCENTURY_MONTH_JULY ||\
  (val) == DS3231_MONTHCENTURY_MONTH_AUGUST ||\
  (val) == DS3231_MONTHCENTURY_MONTH_SEPTEMBER ||\
  (val) == DS3231_MONTHCENTURY_MONTH_DECEMBER ||\
  0)

/*!
 * \def DS3231_MONTHCENTURY_10_MONTH_0
 * \brief Tens place of the month
*/
#define DS3231_MONTHCENTURY_10_MONTH_0 0

/*!
 * \def DS3231_MONTHCENTURY_10_MONTH_1
 * \brief Tens place of the month
*/
#define DS3231_MONTHCENTURY_10_MONTH_1 1


/*!
 * \macro DS3231_MONTHCENTURY_10_MONTH_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_monthcentury_t_10_month type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_MONTHCENTURY_10_MONTH_VALID(val) (\
  (val) == DS3231_MONTHCENTURY_10_MONTH_0 ||\
  (val) == DS3231_MONTHCENTURY_10_MONTH_1 ||\
  0)

/*!
 * \def DS3231_MONTHCENTURY_RSV_RESERVED
 * \brief Reserved bits
*/
#define DS3231_MONTHCENTURY_RSV_RESERVED 0


/*!
 * \macro DS3231_MONTHCENTURY_RSV_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_monthcentury_t_rsv type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_MONTHCENTURY_RSV_VALID(val) (\
  (val) == DS3231_MONTHCENTURY_RSV_RESERVED ||\
  0)

/*!
 * \def DS3231_MONTHCENTURY_CENTURY_20TH_CENTURY
 * \brief Century bit
*/
#define DS3231_MONTHCENTURY_CENTURY_20TH_CENTURY 0

/*!
 * \def DS3231_MONTHCENTURY_CENTURY_21ST_CENTURY
 * \brief Century bit
*/
#define DS3231_MONTHCENTURY_CENTURY_21ST_CENTURY 1


/*!
 * \macro DS3231_MONTHCENTURY_CENTURY_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_monthcentury_t_century type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_MONTHCENTURY_CENTURY_VALID(val) (\
  (val) == DS3231_MONTHCENTURY_CENTURY_20TH_CENTURY ||\
  (val) == DS3231_MONTHCENTURY_CENTURY_21ST_CENTURY ||\
  0)

/*!
 * \struct ds3231_year_t
 * \brief Year register stores the year value in BCD format.
 *
 * \var year Stores ones of the year BCD value
 * \var 10_year Stores 10s of the year BCD value
 */
typedef struct {
  // Stores ones of the year BCD value
  uint8_t year:4;
  // Stores 10s of the year BCD value
  uint8_t _10_year:4;
} ds3231_year_t;

/*!
 * \struct ds3231_alarm_1_seconds_t
 * \brief Alarm 1 seconds register
 *
 * \var seconds Seconds value
 * \var 10_seconds 10 seconds value
 * \var a1m1 Alarm 1 mask bit 1
 */
typedef struct {
  // Seconds value
  uint8_t seconds:4;
  // 10 seconds value
  uint8_t _10_seconds:3;
  // Alarm 1 mask bit 1
  uint8_t a1m1:1;
} ds3231_alarm_1_seconds_t;

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_0
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_0 0

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_1
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_1 1

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_2
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_2 10

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_3
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_3 11

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_4
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_4 4

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_5
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_5 5

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_6
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_6 6

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_7
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_7 7

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_8
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_8 8

/*!
 * \def DS3231_ALARM_1_SECONDS_SECONDS_9
 * \brief Seconds value
*/
#define DS3231_ALARM_1_SECONDS_SECONDS_9 9


/*!
 * \macro DS3231_ALARM_1_SECONDS_SECONDS_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_seconds_t_seconds type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_SECONDS_SECONDS_VALID(val) (\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_0 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_1 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_2 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_3 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_4 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_5 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_6 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_7 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_8 ||\
  (val) == DS3231_ALARM_1_SECONDS_SECONDS_9 ||\
  0)

/*!
 * \def DS3231_ALARM_1_SECONDS_10_SECONDS_0
 * \brief 10 seconds value
*/
#define DS3231_ALARM_1_SECONDS_10_SECONDS_0 0

/*!
 * \def DS3231_ALARM_1_SECONDS_10_SECONDS_10
 * \brief 10 seconds value
*/
#define DS3231_ALARM_1_SECONDS_10_SECONDS_10 1

/*!
 * \def DS3231_ALARM_1_SECONDS_10_SECONDS_20
 * \brief 10 seconds value
*/
#define DS3231_ALARM_1_SECONDS_10_SECONDS_20 10

/*!
 * \def DS3231_ALARM_1_SECONDS_10_SECONDS_30
 * \brief 10 seconds value
*/
#define DS3231_ALARM_1_SECONDS_10_SECONDS_30 11

/*!
 * \def DS3231_ALARM_1_SECONDS_10_SECONDS_40
 * \brief 10 seconds value
*/
#define DS3231_ALARM_1_SECONDS_10_SECONDS_40 4

/*!
 * \def DS3231_ALARM_1_SECONDS_10_SECONDS_50
 * \brief 10 seconds value
*/
#define DS3231_ALARM_1_SECONDS_10_SECONDS_50 5


/*!
 * \macro DS3231_ALARM_1_SECONDS_10_SECONDS_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_seconds_t_10_seconds type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_SECONDS_10_SECONDS_VALID(val) (\
  (val) == DS3231_ALARM_1_SECONDS_10_SECONDS_0 ||\
  (val) == DS3231_ALARM_1_SECONDS_10_SECONDS_10 ||\
  (val) == DS3231_ALARM_1_SECONDS_10_SECONDS_20 ||\
  (val) == DS3231_ALARM_1_SECONDS_10_SECONDS_30 ||\
  (val) == DS3231_ALARM_1_SECONDS_10_SECONDS_40 ||\
  (val) == DS3231_ALARM_1_SECONDS_10_SECONDS_50 ||\
  0)

/*!
 * \def DS3231_ALARM_1_SECONDS_A1M1_ALARM_WHEN_SECONDS_MATCH
 * \brief Alarm 1 mask bit 1
*/
#define DS3231_ALARM_1_SECONDS_A1M1_ALARM_WHEN_SECONDS_MATCH 0

/*!
 * \def DS3231_ALARM_1_SECONDS_A1M1_ALARM_ONCE_PER_SECOND
 * \brief Alarm 1 mask bit 1
*/
#define DS3231_ALARM_1_SECONDS_A1M1_ALARM_ONCE_PER_SECOND 1


/*!
 * \macro DS3231_ALARM_1_SECONDS_A1M1_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_seconds_t_a1m1 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_SECONDS_A1M1_VALID(val) (\
  (val) == DS3231_ALARM_1_SECONDS_A1M1_ALARM_WHEN_SECONDS_MATCH ||\
  (val) == DS3231_ALARM_1_SECONDS_A1M1_ALARM_ONCE_PER_SECOND ||\
  0)

/*!
 * \struct ds3231_alarm_1_minutes_t
 * \brief This register holds the minutes value for Alarm 1.
 *
 * \var minutes Units place of the minutes value for Alarm 1.
 * \var 10_minutes Tens place of the minutes value for Alarm 1.
 * \var a1m2 Alarm 1 mask bit for minutes. Controls whether the minutes value is used in the alarm match.
 */
typedef struct {
  // Units place of the minutes value for Alarm 1.
  uint8_t minutes:4;
  // Tens place of the minutes value for Alarm 1.
  uint8_t _10_minutes:3;
  // Alarm 1 mask bit for minutes. Controls whether the minutes value is used in the alarm match.
  uint8_t a1m2:1;
} ds3231_alarm_1_minutes_t;

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_0
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_0 0

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_1
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_1 1

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_2
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_2 10

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_3
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_3 11

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_4
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_4 4

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_5
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_5 5

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_6
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_6 6

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_7
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_7 7

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_8
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_8 8

/*!
 * \def DS3231_ALARM_1_MINUTES_MINUTES_9
 * \brief Units place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_MINUTES_9 9


/*!
 * \macro DS3231_ALARM_1_MINUTES_MINUTES_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_minutes_t_minutes type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_MINUTES_MINUTES_VALID(val) (\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_0 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_1 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_2 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_3 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_4 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_5 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_6 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_7 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_8 ||\
  (val) == DS3231_ALARM_1_MINUTES_MINUTES_9 ||\
  0)

/*!
 * \def DS3231_ALARM_1_MINUTES_10_MINUTES_0
 * \brief Tens place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_10_MINUTES_0 0

/*!
 * \def DS3231_ALARM_1_MINUTES_10_MINUTES_1
 * \brief Tens place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_10_MINUTES_1 1

/*!
 * \def DS3231_ALARM_1_MINUTES_10_MINUTES_2
 * \brief Tens place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_10_MINUTES_2 2

/*!
 * \def DS3231_ALARM_1_MINUTES_10_MINUTES_3
 * \brief Tens place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_10_MINUTES_3 3

/*!
 * \def DS3231_ALARM_1_MINUTES_10_MINUTES_4
 * \brief Tens place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_10_MINUTES_4 4

/*!
 * \def DS3231_ALARM_1_MINUTES_10_MINUTES_5
 * \brief Tens place of the minutes value for Alarm 1.
*/
#define DS3231_ALARM_1_MINUTES_10_MINUTES_5 5


/*!
 * \macro DS3231_ALARM_1_MINUTES_10_MINUTES_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_minutes_t_10_minutes type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_MINUTES_10_MINUTES_VALID(val) (\
  (val) == DS3231_ALARM_1_MINUTES_10_MINUTES_0 ||\
  (val) == DS3231_ALARM_1_MINUTES_10_MINUTES_1 ||\
  (val) == DS3231_ALARM_1_MINUTES_10_MINUTES_2 ||\
  (val) == DS3231_ALARM_1_MINUTES_10_MINUTES_3 ||\
  (val) == DS3231_ALARM_1_MINUTES_10_MINUTES_4 ||\
  (val) == DS3231_ALARM_1_MINUTES_10_MINUTES_5 ||\
  0)

/*!
 * \def DS3231_ALARM_1_MINUTES_A1M2_ALARM_WHEN_MINUTES_MATCH
 * \brief Alarm 1 mask bit for minutes. Controls whether the minutes value is used in the alarm match.
*/
#define DS3231_ALARM_1_MINUTES_A1M2_ALARM_WHEN_MINUTES_MATCH 0

/*!
 * \def DS3231_ALARM_1_MINUTES_A1M2_MINUTES_VALUE_IGNORED_IN_ALARM_MATCH
 * \brief Alarm 1 mask bit for minutes. Controls whether the minutes value is used in the alarm match.
*/
#define DS3231_ALARM_1_MINUTES_A1M2_MINUTES_VALUE_IGNORED_IN_ALARM_MATCH 1


/*!
 * \macro DS3231_ALARM_1_MINUTES_A1M2_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_minutes_t_a1m2 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_MINUTES_A1M2_VALID(val) (\
  (val) == DS3231_ALARM_1_MINUTES_A1M2_ALARM_WHEN_MINUTES_MATCH ||\
  (val) == DS3231_ALARM_1_MINUTES_A1M2_MINUTES_VALUE_IGNORED_IN_ALARM_MATCH ||\
  0)

/*!
 * \struct ds3231_alarm_1_hour_t
 * \brief Alarm 1 hour register
 *
 * \var hour Hour digit of the alarm time
 * \var 10_hour 10-hour digit of the alarm time
 * \var ampm20hour AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
 * \var 1224 12-hour or 24-hour mode select bit
 * \var a1m3 Alarm 1 mask bit 3
 */
typedef struct {
  // Hour digit of the alarm time
  uint8_t hour:4;
  // 10-hour digit of the alarm time
  uint8_t _10_hour:1;
  // AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
  uint8_t ampm20hour:1;
  // 12-hour or 24-hour mode select bit
  uint8_t _1224:1;
  // Alarm 1 mask bit 3
  uint8_t a1m3:1;
} ds3231_alarm_1_hour_t;

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_0
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_0 0

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_1
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_1 1

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_2
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_2 2

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_3
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_3 3

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_4
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_4 4

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_5
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_5 5

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_6
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_6 6

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_7
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_7 7

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_8
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_8 8

/*!
 * \def DS3231_ALARM_1_HOUR_HOUR_9
 * \brief Hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_HOUR_9 9


/*!
 * \macro DS3231_ALARM_1_HOUR_HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_hour_t_hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_HOUR_HOUR_VALID(val) (\
  (val) == DS3231_ALARM_1_HOUR_HOUR_0 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_1 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_2 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_3 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_4 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_5 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_6 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_7 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_8 ||\
  (val) == DS3231_ALARM_1_HOUR_HOUR_9 ||\
  0)

/*!
 * \def DS3231_ALARM_1_HOUR_10_HOUR_0
 * \brief 10-hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_10_HOUR_0 0

/*!
 * \def DS3231_ALARM_1_HOUR_10_HOUR_1
 * \brief 10-hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_10_HOUR_1 1

/*!
 * \def DS3231_ALARM_1_HOUR_10_HOUR_2
 * \brief 10-hour digit of the alarm time
*/
#define DS3231_ALARM_1_HOUR_10_HOUR_2 2


/*!
 * \macro DS3231_ALARM_1_HOUR_10_HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_hour_t_10_hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_HOUR_10_HOUR_VALID(val) (\
  (val) == DS3231_ALARM_1_HOUR_10_HOUR_0 ||\
  (val) == DS3231_ALARM_1_HOUR_10_HOUR_1 ||\
  (val) == DS3231_ALARM_1_HOUR_10_HOUR_2 ||\
  0)

/*!
 * \def DS3231_ALARM_1_HOUR_AMPM20HOUR_AM
 * \brief AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
*/
#define DS3231_ALARM_1_HOUR_AMPM20HOUR_AM 0

/*!
 * \def DS3231_ALARM_1_HOUR_AMPM20HOUR_PM
 * \brief AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
*/
#define DS3231_ALARM_1_HOUR_AMPM20HOUR_PM 1


/*!
 * \macro DS3231_ALARM_1_HOUR_AMPM20HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_hour_t_ampm20hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_HOUR_AMPM20HOUR_VALID(val) (\
  (val) == DS3231_ALARM_1_HOUR_AMPM20HOUR_AM ||\
  (val) == DS3231_ALARM_1_HOUR_AMPM20HOUR_PM ||\
  0)

/*!
 * \def DS3231_ALARM_1_HOUR_1224_24HOUR_MODE
 * \brief 12-hour or 24-hour mode select bit
*/
#define DS3231_ALARM_1_HOUR_1224_24HOUR_MODE 0

/*!
 * \def DS3231_ALARM_1_HOUR_1224_12HOUR_MODE
 * \brief 12-hour or 24-hour mode select bit
*/
#define DS3231_ALARM_1_HOUR_1224_12HOUR_MODE 1


/*!
 * \macro DS3231_ALARM_1_HOUR_1224_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_hour_t_1224 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_HOUR_1224_VALID(val) (\
  (val) == DS3231_ALARM_1_HOUR_1224_24HOUR_MODE ||\
  (val) == DS3231_ALARM_1_HOUR_1224_12HOUR_MODE ||\
  0)

/*!
 * \def DS3231_ALARM_1_HOUR_A1M3_ALARM_WHEN_HOURS_MATCH
 * \brief Alarm 1 mask bit 3
*/
#define DS3231_ALARM_1_HOUR_A1M3_ALARM_WHEN_HOURS_MATCH 0

/*!
 * \def DS3231_ALARM_1_HOUR_A1M3_ALARM_WHEN_HOURS_AND_MINUTES_MATCH
 * \brief Alarm 1 mask bit 3
*/
#define DS3231_ALARM_1_HOUR_A1M3_ALARM_WHEN_HOURS_AND_MINUTES_MATCH 1


/*!
 * \macro DS3231_ALARM_1_HOUR_A1M3_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_hour_t_a1m3 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_HOUR_A1M3_VALID(val) (\
  (val) == DS3231_ALARM_1_HOUR_A1M3_ALARM_WHEN_HOURS_MATCH ||\
  (val) == DS3231_ALARM_1_HOUR_A1M3_ALARM_WHEN_HOURS_AND_MINUTES_MATCH ||\
  0)

/*!
 * \struct ds3231_alarm_1_daydate_t
 * \brief Register for setting the day or date for Alarm 1
 *
 * \var daydate  Stores the day of the week or the date of the month depending on DY/DT bit.
 * \var 10_date Stores tens of the day value for Alarm 1.
 * \var dydt Controls whether the alarm value stored in bits 0 to 5 of the register reflects the day of the week or the date of the month.
 * \var reserved Reserved field as space was unfilled
 */
typedef struct {
  //  Stores the day of the week or the date of the month depending on DY/DT bit.
  uint8_t daydate:4;
  // Stores tens of the day value for Alarm 1.
  uint8_t _10_date:2;
  // Controls whether the alarm value stored in bits 0 to 5 of the register reflects the day of the week or the date of the month.
  uint8_t dydt:1;
  // Reserved field as space was unfilled
  uint8_t reserved:1;
} ds3231_alarm_1_daydate_t;

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_1
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_1 1

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_10
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_10 10

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_11
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_11 11

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_4
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_4 4

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_5
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_5 5

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_6
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_6 6

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_7
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_7 7

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_8
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_8 8

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_9
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_9 9

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_12
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_12 12

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_13
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_13 13

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_14
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_14 14

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_15
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_15 15

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_16
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_16 16

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_17
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_17 17

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_18
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_18 18

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_19
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_19 19

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_20
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_20 20

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_21
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_21 21

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_22
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_22 22

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_23
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_23 23

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_24
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_24 24

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_25
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_25 25

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_26
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_26 26

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_27
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_27 27

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_28
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_28 28

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_29
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_29 29

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_30
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_30 30

/*!
 * \def DS3231_ALARM_1_DAYDATE_10_DATE_31
 * \brief Stores tens of the day value for Alarm 1.
*/
#define DS3231_ALARM_1_DAYDATE_10_DATE_31 31


/*!
 * \macro DS3231_ALARM_1_DAYDATE_10_DATE_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_daydate_t_10_date type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_DAYDATE_10_DATE_VALID(val) (\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_1 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_10 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_11 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_4 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_5 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_6 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_7 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_8 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_9 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_12 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_13 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_14 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_15 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_16 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_17 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_18 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_19 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_20 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_21 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_22 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_23 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_24 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_25 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_26 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_27 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_28 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_29 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_30 ||\
  (val) == DS3231_ALARM_1_DAYDATE_10_DATE_31 ||\
  0)

/*!
 * \def DS3231_ALARM_1_DAYDATE_DYDT_ALARM_WHEN_DAYDATE_MATCH
 * \brief Controls whether the alarm value stored in bits 0 to 5 of the register reflects the day of the week or the date of the month.
*/
#define DS3231_ALARM_1_DAYDATE_DYDT_ALARM_WHEN_DAYDATE_MATCH 0

/*!
 * \def DS3231_ALARM_1_DAYDATE_DYDT_ALARM_WHEN_DAY_OF_THE_WEEK_MATCH
 * \brief Controls whether the alarm value stored in bits 0 to 5 of the register reflects the day of the week or the date of the month.
*/
#define DS3231_ALARM_1_DAYDATE_DYDT_ALARM_WHEN_DAY_OF_THE_WEEK_MATCH 1


/*!
 * \macro DS3231_ALARM_1_DAYDATE_DYDT_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_1_daydate_t_dydt type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_1_DAYDATE_DYDT_VALID(val) (\
  (val) == DS3231_ALARM_1_DAYDATE_DYDT_ALARM_WHEN_DAYDATE_MATCH ||\
  (val) == DS3231_ALARM_1_DAYDATE_DYDT_ALARM_WHEN_DAY_OF_THE_WEEK_MATCH ||\
  0)

/*!
 * \struct ds3231_alarm_2_minutes_t
 * \brief This register holds the minutes value for Alarm 2.
 *
 * \var minutes Minutes value for Alarm 2.
 * \var 10_minutes Tens place of the minutes value for Alarm 1.
 * \var a2m2 Alarm 2 mask bit for minutes. When set to logic 1, the minutes value is ignored in the alarm comparison.
 */
typedef struct {
  // Minutes value for Alarm 2.
  uint8_t minutes:4;
  // Tens place of the minutes value for Alarm 1.
  uint8_t _10_minutes:3;
  // Alarm 2 mask bit for minutes. When set to logic 1, the minutes value is ignored in the alarm comparison.
  uint8_t a2m2:1;
} ds3231_alarm_2_minutes_t;

/*!
 * \def DS3231_ALARM_2_MINUTES_MINUTES_VALID_MINUTES_RANGE
 * \brief Minutes value for Alarm 2.
*/
#define DS3231_ALARM_2_MINUTES_MINUTES_VALID_MINUTES_RANGE 89


/*!
 * \macro DS3231_ALARM_2_MINUTES_MINUTES_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_minutes_t_minutes type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_MINUTES_MINUTES_VALID(val) (\
  (val) == DS3231_ALARM_2_MINUTES_MINUTES_VALID_MINUTES_RANGE ||\
  0)

/*!
 * \def DS3231_ALARM_2_MINUTES_A2M2_ALARM_WHEN_MINUTES_MATCH
 * \brief Alarm 2 mask bit for minutes. When set to logic 1, the minutes value is ignored in the alarm comparison.
*/
#define DS3231_ALARM_2_MINUTES_A2M2_ALARM_WHEN_MINUTES_MATCH 0

/*!
 * \def DS3231_ALARM_2_MINUTES_A2M2_MINUTES_VALUE_IGNORED
 * \brief Alarm 2 mask bit for minutes. When set to logic 1, the minutes value is ignored in the alarm comparison.
*/
#define DS3231_ALARM_2_MINUTES_A2M2_MINUTES_VALUE_IGNORED 1


/*!
 * \macro DS3231_ALARM_2_MINUTES_A2M2_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_minutes_t_a2m2 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_MINUTES_A2M2_VALID(val) (\
  (val) == DS3231_ALARM_2_MINUTES_A2M2_ALARM_WHEN_MINUTES_MATCH ||\
  (val) == DS3231_ALARM_2_MINUTES_A2M2_MINUTES_VALUE_IGNORED ||\
  0)

/*!
 * \struct ds3231_alarm_2_hour_t
 * \brief Alarm 2 Hour register
 *
 * \var hour Hour bits
 * \var 10_hour 10 Hour bit
 * \var ampm20hour AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
 * \var 1224 12-hour or 24-hour mode select bit
 * \var a2m2 Alarm 2 Mask bit 2
 */
typedef struct {
  // Hour bits
  uint8_t hour:4;
  // 10 Hour bit
  uint8_t _10_hour:1;
  // AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
  uint8_t ampm20hour:1;
  // 12-hour or 24-hour mode select bit
  uint8_t _1224:1;
  // Alarm 2 Mask bit 2
  uint8_t a2m2:1;
} ds3231_alarm_2_hour_t;

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_0
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_0 0

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_1
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_1 1

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_2
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_2 10

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_3
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_3 11

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_4
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_4 4

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_5
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_5 5

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_6
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_6 6

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_7
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_7 7

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_8
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_8 8

/*!
 * \def DS3231_ALARM_2_HOUR_HOUR_9
 * \brief Hour bits
*/
#define DS3231_ALARM_2_HOUR_HOUR_9 9


/*!
 * \macro DS3231_ALARM_2_HOUR_HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_hour_t_hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_HOUR_HOUR_VALID(val) (\
  (val) == DS3231_ALARM_2_HOUR_HOUR_0 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_1 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_2 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_3 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_4 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_5 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_6 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_7 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_8 ||\
  (val) == DS3231_ALARM_2_HOUR_HOUR_9 ||\
  0)

/*!
 * \def DS3231_ALARM_2_HOUR_10_HOUR_0
 * \brief 10 Hour bit
*/
#define DS3231_ALARM_2_HOUR_10_HOUR_0 0

/*!
 * \def DS3231_ALARM_2_HOUR_10_HOUR_1
 * \brief 10 Hour bit
*/
#define DS3231_ALARM_2_HOUR_10_HOUR_1 1


/*!
 * \macro DS3231_ALARM_2_HOUR_10_HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_hour_t_10_hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_HOUR_10_HOUR_VALID(val) (\
  (val) == DS3231_ALARM_2_HOUR_10_HOUR_0 ||\
  (val) == DS3231_ALARM_2_HOUR_10_HOUR_1 ||\
  0)

/*!
 * \def DS3231_ALARM_2_HOUR_AMPM20HOUR_AM
 * \brief AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
*/
#define DS3231_ALARM_2_HOUR_AMPM20HOUR_AM 0

/*!
 * \def DS3231_ALARM_2_HOUR_AMPM20HOUR_PM
 * \brief AM/PM bit in 12-hour mode or the 2nd bit of 10s of hours in 24-hour mode
*/
#define DS3231_ALARM_2_HOUR_AMPM20HOUR_PM 1


/*!
 * \macro DS3231_ALARM_2_HOUR_AMPM20HOUR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_hour_t_ampm20hour type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_HOUR_AMPM20HOUR_VALID(val) (\
  (val) == DS3231_ALARM_2_HOUR_AMPM20HOUR_AM ||\
  (val) == DS3231_ALARM_2_HOUR_AMPM20HOUR_PM ||\
  0)

/*!
 * \def DS3231_ALARM_2_HOUR_1224_24HOUR_MODE
 * \brief 12-hour or 24-hour mode select bit
*/
#define DS3231_ALARM_2_HOUR_1224_24HOUR_MODE 0

/*!
 * \def DS3231_ALARM_2_HOUR_1224_12HOUR_MODE
 * \brief 12-hour or 24-hour mode select bit
*/
#define DS3231_ALARM_2_HOUR_1224_12HOUR_MODE 1


/*!
 * \macro DS3231_ALARM_2_HOUR_1224_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_hour_t_1224 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_HOUR_1224_VALID(val) (\
  (val) == DS3231_ALARM_2_HOUR_1224_24HOUR_MODE ||\
  (val) == DS3231_ALARM_2_HOUR_1224_12HOUR_MODE ||\
  0)

/*!
 * \def DS3231_ALARM_2_HOUR_A2M2_ALARM_WHEN_HOURS_MATCH
 * \brief Alarm 2 Mask bit 2
*/
#define DS3231_ALARM_2_HOUR_A2M2_ALARM_WHEN_HOURS_MATCH 0

/*!
 * \def DS3231_ALARM_2_HOUR_A2M2_ALARM_WHEN_HOURS_AND_MINUTES_MATCH
 * \brief Alarm 2 Mask bit 2
*/
#define DS3231_ALARM_2_HOUR_A2M2_ALARM_WHEN_HOURS_AND_MINUTES_MATCH 1


/*!
 * \macro DS3231_ALARM_2_HOUR_A2M2_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_hour_t_a2m2 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_HOUR_A2M2_VALID(val) (\
  (val) == DS3231_ALARM_2_HOUR_A2M2_ALARM_WHEN_HOURS_MATCH ||\
  (val) == DS3231_ALARM_2_HOUR_A2M2_ALARM_WHEN_HOURS_AND_MINUTES_MATCH ||\
  0)

/*!
 * \struct ds3231_alarm_2_daydate_t
 * \brief Alarm 2 Day/Date register
 *
 * \var daydate Day or Date value
 * \var 10_date Stores tens of the day value for Alarm 1.
 * \var dydt Day/Date select
 * \var a2m4 Alarm 2 Mask bit 4
 */
typedef struct {
  // Day or Date value
  uint8_t daydate:4;
  // Stores tens of the day value for Alarm 1.
  uint8_t _10_date:2;
  // Day/Date select
  uint8_t dydt:1;
  // Alarm 2 Mask bit 4
  uint8_t a2m4:1;
} ds3231_alarm_2_daydate_t;

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_1
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_1 1

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_10
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_10 10

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_11
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_11 11

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_4
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_4 4

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_5
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_5 5

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_6
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_6 6

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_7
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_7 7

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_8
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_8 8

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_9
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_9 9

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_12
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_12 12

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_13
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_13 13

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_14
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_14 14

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_15
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_15 15

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_16
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_16 16

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_17
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_17 17

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_18
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_18 18

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_19
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_19 19

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_20
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_20 20

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_21
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_21 21

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_22
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_22 22

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_23
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_23 23

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_24
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_24 24

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_25
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_25 25

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_26
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_26 26

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_27
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_27 27

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_28
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_28 28

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_29
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_29 29

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_30
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_30 30

/*!
 * \def DS3231_ALARM_2_DAYDATE_DAYDATE_31
 * \brief Day or Date value
*/
#define DS3231_ALARM_2_DAYDATE_DAYDATE_31 31


/*!
 * \macro DS3231_ALARM_2_DAYDATE_DAYDATE_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_daydate_t_daydate type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_DAYDATE_DAYDATE_VALID(val) (\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_1 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_10 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_11 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_4 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_5 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_6 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_7 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_8 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_9 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_12 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_13 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_14 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_15 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_16 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_17 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_18 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_19 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_20 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_21 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_22 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_23 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_24 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_25 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_26 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_27 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_28 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_29 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_30 ||\
  (val) == DS3231_ALARM_2_DAYDATE_DAYDATE_31 ||\
  0)

/*!
 * \def DS3231_ALARM_2_DAYDATE_DYDT_ALARM_WHEN_DAY_OF_THE_WEEK_MATCH
 * \brief Day/Date select
*/
#define DS3231_ALARM_2_DAYDATE_DYDT_ALARM_WHEN_DAY_OF_THE_WEEK_MATCH 0

/*!
 * \def DS3231_ALARM_2_DAYDATE_DYDT_ALARM_WHEN_DATE_OF_THE_MONTH_MATCH
 * \brief Day/Date select
*/
#define DS3231_ALARM_2_DAYDATE_DYDT_ALARM_WHEN_DATE_OF_THE_MONTH_MATCH 1


/*!
 * \macro DS3231_ALARM_2_DAYDATE_DYDT_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_daydate_t_dydt type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_DAYDATE_DYDT_VALID(val) (\
  (val) == DS3231_ALARM_2_DAYDATE_DYDT_ALARM_WHEN_DAY_OF_THE_WEEK_MATCH ||\
  (val) == DS3231_ALARM_2_DAYDATE_DYDT_ALARM_WHEN_DATE_OF_THE_MONTH_MATCH ||\
  0)

/*!
 * \def DS3231_ALARM_2_DAYDATE_A2M4_ALARM_WHEN_DAYDATE_MATCH
 * \brief Alarm 2 Mask bit 4
*/
#define DS3231_ALARM_2_DAYDATE_A2M4_ALARM_WHEN_DAYDATE_MATCH 0

/*!
 * \def DS3231_ALARM_2_DAYDATE_A2M4_ALARM_WHEN_DAYDATE_DONT_CARE
 * \brief Alarm 2 Mask bit 4
*/
#define DS3231_ALARM_2_DAYDATE_A2M4_ALARM_WHEN_DAYDATE_DONT_CARE 1


/*!
 * \macro DS3231_ALARM_2_DAYDATE_A2M4_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_alarm_2_daydate_t_a2m4 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_ALARM_2_DAYDATE_A2M4_VALID(val) (\
  (val) == DS3231_ALARM_2_DAYDATE_A2M4_ALARM_WHEN_DAYDATE_MATCH ||\
  (val) == DS3231_ALARM_2_DAYDATE_A2M4_ALARM_WHEN_DAYDATE_DONT_CARE ||\
  0)

/*!
 * \struct ds3231_control_t
 * \brief Control register for the DS3231 RTC, managing oscillator, square-wave output, and alarm interrupts.
 *
 * \var a1ie Alarm 1 Interrupt Enable. When set to logic 1, this bit permits the alarm 1 flag (A1F) bit in the status register to assert INT/SQW (when INTCN = 1).
 * \var a2ie Alarm 2 Interrupt Enable. When set to logic 1, this bit permits the alarm 2 flag (A2F) bit in the status register to assert INT/SQW (when INTCN = 1).
 * \var intcn Interrupt Control. This bit controls the INT/SQW signal.
 * \var rs1 Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
 * \var rs2 Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
 * \var conv Convert Temperature. Setting this bit to 1 forces the temperature sensor to convert the temperature into digital code and execute the TCXO algorithm to update the capacitance array for the oscillator.
 * \var bbsqw Battery-Backed Square-Wave Enable. When set to logic 1 with INTCN = 0 and VCC < VPF, this bit enables the square wave.
 * \var eosc Enable Oscillator. When set to logic 0, the oscillator is started. When set to logic 1, the oscillator is stopped when the DS3231 switches to VBAT.
 */
typedef struct {
  // Alarm 1 Interrupt Enable. When set to logic 1, this bit permits the alarm 1 flag (A1F) bit in the status register to assert INT/SQW (when INTCN = 1).
  uint8_t a1ie:1;
  // Alarm 2 Interrupt Enable. When set to logic 1, this bit permits the alarm 2 flag (A2F) bit in the status register to assert INT/SQW (when INTCN = 1).
  uint8_t a2ie:1;
  // Interrupt Control. This bit controls the INT/SQW signal.
  uint8_t intcn:1;
  // Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
  uint8_t rs1:1;
  // Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
  uint8_t rs2:1;
  // Convert Temperature. Setting this bit to 1 forces the temperature sensor to convert the temperature into digital code and execute the TCXO algorithm to update the capacitance array for the oscillator.
  uint8_t conv:1;
  // Battery-Backed Square-Wave Enable. When set to logic 1 with INTCN = 0 and VCC < VPF, this bit enables the square wave.
  uint8_t bbsqw:1;
  // Enable Oscillator. When set to logic 0, the oscillator is started. When set to logic 1, the oscillator is stopped when the DS3231 switches to VBAT.
  uint8_t eosc:1;
} ds3231_control_t;

/*!
 * \def DS3231_CONTROL_A1IE_ALARM_1_INTERRUPT_DISABLED
 * \brief Alarm 1 Interrupt Enable. When set to logic 1, this bit permits the alarm 1 flag (A1F) bit in the status register to assert INT/SQW (when INTCN = 1).
*/
#define DS3231_CONTROL_A1IE_ALARM_1_INTERRUPT_DISABLED 0

/*!
 * \def DS3231_CONTROL_A1IE_ALARM_1_INTERRUPT_ENABLED
 * \brief Alarm 1 Interrupt Enable. When set to logic 1, this bit permits the alarm 1 flag (A1F) bit in the status register to assert INT/SQW (when INTCN = 1).
*/
#define DS3231_CONTROL_A1IE_ALARM_1_INTERRUPT_ENABLED 1


/*!
 * \macro DS3231_CONTROL_A1IE_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_a1ie type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_A1IE_VALID(val) (\
  (val) == DS3231_CONTROL_A1IE_ALARM_1_INTERRUPT_DISABLED ||\
  (val) == DS3231_CONTROL_A1IE_ALARM_1_INTERRUPT_ENABLED ||\
  0)

/*!
 * \def DS3231_CONTROL_A2IE_ALARM_2_INTERRUPT_DISABLED
 * \brief Alarm 2 Interrupt Enable. When set to logic 1, this bit permits the alarm 2 flag (A2F) bit in the status register to assert INT/SQW (when INTCN = 1).
*/
#define DS3231_CONTROL_A2IE_ALARM_2_INTERRUPT_DISABLED 0

/*!
 * \def DS3231_CONTROL_A2IE_ALARM_2_INTERRUPT_ENABLED
 * \brief Alarm 2 Interrupt Enable. When set to logic 1, this bit permits the alarm 2 flag (A2F) bit in the status register to assert INT/SQW (when INTCN = 1).
*/
#define DS3231_CONTROL_A2IE_ALARM_2_INTERRUPT_ENABLED 1


/*!
 * \macro DS3231_CONTROL_A2IE_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_a2ie type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_A2IE_VALID(val) (\
  (val) == DS3231_CONTROL_A2IE_ALARM_2_INTERRUPT_DISABLED ||\
  (val) == DS3231_CONTROL_A2IE_ALARM_2_INTERRUPT_ENABLED ||\
  0)

/*!
 * \def DS3231_CONTROL_INTCN_SQUARE_WAVE_OUTPUT
 * \brief Interrupt Control. This bit controls the INT/SQW signal.
*/
#define DS3231_CONTROL_INTCN_SQUARE_WAVE_OUTPUT 0

/*!
 * \def DS3231_CONTROL_INTCN_INTERRUPT_OUTPUT
 * \brief Interrupt Control. This bit controls the INT/SQW signal.
*/
#define DS3231_CONTROL_INTCN_INTERRUPT_OUTPUT 1


/*!
 * \macro DS3231_CONTROL_INTCN_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_intcn type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_INTCN_VALID(val) (\
  (val) == DS3231_CONTROL_INTCN_SQUARE_WAVE_OUTPUT ||\
  (val) == DS3231_CONTROL_INTCN_INTERRUPT_OUTPUT ||\
  0)

/*!
 * \def DS3231_CONTROL_RS1_0
 * \brief Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
*/
#define DS3231_CONTROL_RS1_0 0

/*!
 * \def DS3231_CONTROL_RS1_1
 * \brief Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
*/
#define DS3231_CONTROL_RS1_1 1


/*!
 * \macro DS3231_CONTROL_RS1_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_rs1 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_RS1_VALID(val) (\
  (val) == DS3231_CONTROL_RS1_0 ||\
  (val) == DS3231_CONTROL_RS1_1 ||\
  0)

/*!
 * \def DS3231_CONTROL_RS2_0
 * \brief Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
*/
#define DS3231_CONTROL_RS2_0 0

/*!
 * \def DS3231_CONTROL_RS2_1
 * \brief Rate Select. These bits control the frequency of the square-wave output when the square wave has been enabled.
*/
#define DS3231_CONTROL_RS2_1 1


/*!
 * \macro DS3231_CONTROL_RS2_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_rs2 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_RS2_VALID(val) (\
  (val) == DS3231_CONTROL_RS2_0 ||\
  (val) == DS3231_CONTROL_RS2_1 ||\
  0)

/*!
 * \def DS3231_CONTROL_CONV_NO_CONVERSION
 * \brief Convert Temperature. Setting this bit to 1 forces the temperature sensor to convert the temperature into digital code and execute the TCXO algorithm to update the capacitance array for the oscillator.
*/
#define DS3231_CONTROL_CONV_NO_CONVERSION 0

/*!
 * \def DS3231_CONTROL_CONV_START_CONVERSION
 * \brief Convert Temperature. Setting this bit to 1 forces the temperature sensor to convert the temperature into digital code and execute the TCXO algorithm to update the capacitance array for the oscillator.
*/
#define DS3231_CONTROL_CONV_START_CONVERSION 1


/*!
 * \macro DS3231_CONTROL_CONV_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_conv type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_CONV_VALID(val) (\
  (val) == DS3231_CONTROL_CONV_NO_CONVERSION ||\
  (val) == DS3231_CONTROL_CONV_START_CONVERSION ||\
  0)

/*!
 * \def DS3231_CONTROL_BBSQW_SQUARE_WAVE_DISABLED
 * \brief Battery-Backed Square-Wave Enable. When set to logic 1 with INTCN = 0 and VCC < VPF, this bit enables the square wave.
*/
#define DS3231_CONTROL_BBSQW_SQUARE_WAVE_DISABLED 0

/*!
 * \def DS3231_CONTROL_BBSQW_SQUARE_WAVE_ENABLED
 * \brief Battery-Backed Square-Wave Enable. When set to logic 1 with INTCN = 0 and VCC < VPF, this bit enables the square wave.
*/
#define DS3231_CONTROL_BBSQW_SQUARE_WAVE_ENABLED 1


/*!
 * \macro DS3231_CONTROL_BBSQW_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_bbsqw type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_BBSQW_VALID(val) (\
  (val) == DS3231_CONTROL_BBSQW_SQUARE_WAVE_DISABLED ||\
  (val) == DS3231_CONTROL_BBSQW_SQUARE_WAVE_ENABLED ||\
  0)

/*!
 * \def DS3231_CONTROL_EOSC_OSCILLATOR_ENABLED
 * \brief Enable Oscillator. When set to logic 0, the oscillator is started. When set to logic 1, the oscillator is stopped when the DS3231 switches to VBAT.
*/
#define DS3231_CONTROL_EOSC_OSCILLATOR_ENABLED 0

/*!
 * \def DS3231_CONTROL_EOSC_OSCILLATOR_DISABLED
 * \brief Enable Oscillator. When set to logic 0, the oscillator is started. When set to logic 1, the oscillator is stopped when the DS3231 switches to VBAT.
*/
#define DS3231_CONTROL_EOSC_OSCILLATOR_DISABLED 1


/*!
 * \macro DS3231_CONTROL_EOSC_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_control_t_eosc type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROL_EOSC_VALID(val) (\
  (val) == DS3231_CONTROL_EOSC_OSCILLATOR_ENABLED ||\
  (val) == DS3231_CONTROL_EOSC_OSCILLATOR_DISABLED ||\
  0)

/*!
 * \struct ds3231_controlstatus_t
 * \brief Control and status register for the DS3231 RTC
 *
 * \var a1f A logic 1 in the alarm 1 flag bit indicates that the time matched the alarm 1 registers.
 * \var a2f A logic 1 in the alarm 2 flag bit indicates that the time matched the alarm 2 registers.
 * \var bsy This bit indicates the device is busy executing TCXO functions
 * \var en32khz This bit controls the status of the 32kHz pin. When set to logic 1, the 32kHz pin is enabled and outputs a 32.768kHz square- wave signal.
 * \var reserved Reserved bits
 * \var ocf A logic 1 in this bit indi- cates that the oscillator either is stopped or was stopped for some period and may be used to judge the validity of the timekeeping data
 */
typedef struct {
  // A logic 1 in the alarm 1 flag bit indicates that the time matched the alarm 1 registers.
  uint8_t a1f:1;
  // A logic 1 in the alarm 2 flag bit indicates that the time matched the alarm 2 registers.
  uint8_t a2f:1;
  // This bit indicates the device is busy executing TCXO functions
  uint8_t bsy:1;
  // This bit controls the status of the 32kHz pin. When set to logic 1, the 32kHz pin is enabled and outputs a 32.768kHz square- wave signal.
  uint8_t en32khz:1;
  // Reserved bits
  uint8_t reserved:3;
  // A logic 1 in this bit indi- cates that the oscillator either is stopped or was stopped for some period and may be used to judge the validity of the timekeeping data
  uint8_t ocf:1;
} ds3231_controlstatus_t;

/*!
 * \def DS3231_CONTROLSTATUS_BSY_SQUAREWAVE_OUTPUT
 * \brief This bit indicates the device is busy executing TCXO functions
*/
#define DS3231_CONTROLSTATUS_BSY_SQUAREWAVE_OUTPUT 0

/*!
 * \def DS3231_CONTROLSTATUS_BSY_INTERRUPT_OUTPUT
 * \brief This bit indicates the device is busy executing TCXO functions
*/
#define DS3231_CONTROLSTATUS_BSY_INTERRUPT_OUTPUT 1


/*!
 * \macro DS3231_CONTROLSTATUS_BSY_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_controlstatus_t_bsy type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROLSTATUS_BSY_VALID(val) (\
  (val) == DS3231_CONTROLSTATUS_BSY_SQUAREWAVE_OUTPUT ||\
  (val) == DS3231_CONTROLSTATUS_BSY_INTERRUPT_OUTPUT ||\
  0)

/*!
 * \def DS3231_CONTROLSTATUS_EN32KHZ_DISABLED
 * \brief This bit controls the status of the 32kHz pin. When set to logic 1, the 32kHz pin is enabled and outputs a 32.768kHz square- wave signal.
*/
#define DS3231_CONTROLSTATUS_EN32KHZ_DISABLED 0

/*!
 * \def DS3231_CONTROLSTATUS_EN32KHZ_ENABLED
 * \brief This bit controls the status of the 32kHz pin. When set to logic 1, the 32kHz pin is enabled and outputs a 32.768kHz square- wave signal.
*/
#define DS3231_CONTROLSTATUS_EN32KHZ_ENABLED 1


/*!
 * \macro DS3231_CONTROLSTATUS_EN32KHZ_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_controlstatus_t_en32khz type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROLSTATUS_EN32KHZ_VALID(val) (\
  (val) == DS3231_CONTROLSTATUS_EN32KHZ_DISABLED ||\
  (val) == DS3231_CONTROLSTATUS_EN32KHZ_ENABLED ||\
  0)

/*!
 * \def DS3231_CONTROLSTATUS_OCF_OSCILLATOR_ENABLED
 * \brief A logic 1 in this bit indi- cates that the oscillator either is stopped or was stopped for some period and may be used to judge the validity of the timekeeping data
*/
#define DS3231_CONTROLSTATUS_OCF_OSCILLATOR_ENABLED 0

/*!
 * \def DS3231_CONTROLSTATUS_OCF_OSCILLATOR_DISABLED
 * \brief A logic 1 in this bit indi- cates that the oscillator either is stopped or was stopped for some period and may be used to judge the validity of the timekeeping data
*/
#define DS3231_CONTROLSTATUS_OCF_OSCILLATOR_DISABLED 1


/*!
 * \macro DS3231_CONTROLSTATUS_OCF_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_controlstatus_t_ocf type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_CONTROLSTATUS_OCF_VALID(val) (\
  (val) == DS3231_CONTROLSTATUS_OCF_OSCILLATOR_ENABLED ||\
  (val) == DS3231_CONTROLSTATUS_OCF_OSCILLATOR_DISABLED ||\
  0)

/*!
 * \struct ds3231_aging_offset_t
 * \brief The aging offset register is used to add or subtract from the codes in the capacitance array registers.
 *
 * \var data These bits represent the magnitude of the aging offset value.
 * \var sign This bit represents the sign of the offset value.
 */
typedef struct {
  // These bits represent the magnitude of the aging offset value.
  uint8_t data:7;
  // This bit represents the sign of the offset value.
  uint8_t sign:1;
} ds3231_aging_offset_t;

/*!
 * \def DS3231_AGING_OFFSET_SIGN_POSITIVE_AGING_OFFSET
 * \brief This bit represents the sign of the offset value.
*/
#define DS3231_AGING_OFFSET_SIGN_POSITIVE_AGING_OFFSET 0

/*!
 * \def DS3231_AGING_OFFSET_SIGN_NEGATIVE_AGING_OFFSET
 * \brief This bit represents the sign of the offset value.
*/
#define DS3231_AGING_OFFSET_SIGN_NEGATIVE_AGING_OFFSET 1


/*!
 * \macro DS3231_AGING_OFFSET_SIGN_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_aging_offset_t_sign type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_AGING_OFFSET_SIGN_VALID(val) (\
  (val) == DS3231_AGING_OFFSET_SIGN_POSITIVE_AGING_OFFSET ||\
  (val) == DS3231_AGING_OFFSET_SIGN_NEGATIVE_AGING_OFFSET ||\
  0)

/*!
 * \struct ds3231_msb_of_temp_t
 * \brief Upper byte of the temperature register
 *
 * \var data Integer part of the temperature value
 * \var sign Sign bit of the temperature value
 */
typedef struct {
  // Integer part of the temperature value
  uint8_t data:7;
  // Sign bit of the temperature value
  uint8_t sign:1;
} ds3231_msb_of_temp_t;

/*!
 * \def DS3231_MSB_OF_TEMP_SIGN_POSITIVE_TEMPERATURE
 * \brief Sign bit of the temperature value
*/
#define DS3231_MSB_OF_TEMP_SIGN_POSITIVE_TEMPERATURE 0

/*!
 * \def DS3231_MSB_OF_TEMP_SIGN_NEGATIVE_TEMPERATURE
 * \brief Sign bit of the temperature value
*/
#define DS3231_MSB_OF_TEMP_SIGN_NEGATIVE_TEMPERATURE 1


/*!
 * \macro DS3231_MSB_OF_TEMP_SIGN_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ds3231_msb_of_temp_t_sign type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define DS3231_MSB_OF_TEMP_SIGN_VALID(val) (\
  (val) == DS3231_MSB_OF_TEMP_SIGN_POSITIVE_TEMPERATURE ||\
  (val) == DS3231_MSB_OF_TEMP_SIGN_NEGATIVE_TEMPERATURE ||\
  0)

/*!
 * \struct ds3231_lsb_of_temp_t
 * \brief Lower byte of the temperature register
 *
 * \var rsvd Reserved bits
 * \var tmplsb The 2 least significant bits of the temperature value
 */
typedef struct {
  // Reserved bits
  uint8_t rsvd:6;
  // The 2 least significant bits of the temperature value
  uint8_t tmplsb:2;
} ds3231_lsb_of_temp_t;

#pragma pack(pop)
/*!
 * \def ds3231_write_message_max_size
 * \brief Max buffer size required for write operations
 */
 #define ds3231_write_message_max_size 2

/*!
 * \def ds3231_read_message_max_size
 * \brief Max buffer size required for read operations
 */
#define ds3231_read_message_max_size 2

/*!
 * \struct ds3231_data_t
 * \brief Staticaly allocated data used by the device for read/write operations.
 *
 * \var in_buf    staticaly allocated buffer for input data
 * \var out_buf   staticaly allocated buffer for out data
 */
typedef struct {
  uint8_t out_buf[ds3231_write_message_max_size];
  uint8_t in_buf[ds3231_read_message_max_size];
} ds3231_data_t;

/*!
 * \struct ds3231_api_t
 * \brief The device's API structure containing pointers to all device's API functions
 *
 * \var ds3231_write_reg contains pointer to ds3231_write_reg API's function
 * \var ds3231_read_reg contains pointer to ds3231_read_reg API's function

 */
typedef struct {
  EMBEDD_RESULT (*ds3231_write_reg)(embedd_device_t *dev, uint32_t reg_addr, void *reg, uint32_t reg_size, uint32_t delay);
  EMBEDD_RESULT (*ds3231_read_reg)(embedd_device_t *dev, uint32_t reg_addr, void *reg, uint32_t reg_size, uint32_t delay);
} const ds3231_api_t;

#endif//_SRC_DS3231_DATA_TYPES_H
