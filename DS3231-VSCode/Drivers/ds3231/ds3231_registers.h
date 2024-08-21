/*!
 * \file ds3231_registers.h
 * \brief This header file defines register addresses, types, constants and functions prototypes for the
 * Ds3231 Ds3231 device.
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
#ifndef _SRC_DS3231_REGISTERS_H
#define _SRC_DS3231_REGISTERS_H

#include "ds3231_data_types.h"

/* --------------------------------------------------------------------------
 * Registers functions prototypes
 * -------------------------------------------------------------------------- */

/*!
 * \brief Writes data to registers of the DS3231 device.
 *
 * This function handles writing data to a specified register address within the
 * DS3231 device. It constructs the appropriate message format, including the
 * register address and data, and utilizes the underlying hardware abstraction layer
 * (HAL) to perform the bus write operation.
 *
 * \param dev Pointer to the embedd_device_t structure representing the device.
 * \param reg_addr The register address to write to.
 * \param data Pointer to the data to write.
 * \param data_size Size of the register data in bytes.
 * \param delay Delay in milliseconds after the write operation.
 *
 * \return EMBEDD_RESULT_OK on success, or an EMBEDD_RESULT_ERR error code.
 *
 */
EMBEDD_RESULT ds3231_write_reg(embedd_device_t *dev, uint32_t reg_addr, void *reg, uint32_t reg_size, uint32_t delay);

/*!
 * \brief Reads data from registers of the DS3231 device class.
 *
 * This function facilitates reading data from a specified register address within
 * the DS3231 device. It constructs the necessary message to initiate a bus read
 * operation via the hardware abstraction layer (HAL). After reading, it unpacks the
 * received data into the provided buffer.
 *
 * \param dev Pointer to the embedd_device_t structure representing the device.
 * \param reg_addr The register address to read from.
 * \param data Pointer to the buffer where the read data will be stored.
 * \param data_size Size of the register data in bytes.
 * \param delay Delay in milliseconds after the read operation.
 *
 * \return EMBEDD_RESULT_OK on success, or an EMBEDD_RESULT_ERR error code.
 *
 */
EMBEDD_RESULT ds3231_read_reg(embedd_device_t *dev, uint32_t reg_addr, void *reg, uint32_t reg_size, uint32_t delay);

/* --------------------------------------------------------------------------
 * Registers constants
 * -------------------------------------------------------------------------- */

#define DS3231_REGISTER_ADDR_SIZE (1)

/* --------------------------------------------------------------------------
 * Register name: Seconds
 * Register description: This register contains the seconds value in BCD format.
 * -------------------------------------------------------------------------- */
#define ds3231_seconds_read_reg_addr 0x00
#define ds3231_seconds_write_reg_addr 0x00
#define ds3231_seconds_delay 0
typedef ds3231_seconds_t ds3231_seconds;

/* --------------------------------------------------------------------------
 * Register name: Minutes
 * Register description: Stores the minutes value of the current time.
 * -------------------------------------------------------------------------- */
#define ds3231_minutes_read_reg_addr 0x01
#define ds3231_minutes_write_reg_addr 0x01
#define ds3231_minutes_delay 0
typedef ds3231_minutes_t ds3231_minutes;

/* --------------------------------------------------------------------------
 * Register name: Hour
 * Register description: Hour register for timekeeping
 * -------------------------------------------------------------------------- */
#define ds3231_hour_read_reg_addr 0x02
#define ds3231_hour_write_reg_addr 0x02
#define ds3231_hour_delay 0
typedef ds3231_hour_t ds3231_hour;

/* --------------------------------------------------------------------------
 * Register name: Day
 * Register description: Day register
 * -------------------------------------------------------------------------- */
#define ds3231_day_read_reg_addr 0x03
#define ds3231_day_write_reg_addr 0x03
#define ds3231_day_delay 0
typedef ds3231_day_t ds3231_day;

/* --------------------------------------------------------------------------
 * Register name: Date
 * Register description: Holds the date of the month
 * -------------------------------------------------------------------------- */
#define ds3231_date_read_reg_addr 0x04
#define ds3231_date_write_reg_addr 0x04
#define ds3231_date_delay 0
typedef ds3231_date_t ds3231_date;

/* --------------------------------------------------------------------------
 * Register name: Month/Century
 * Register description: Month and century register
 * -------------------------------------------------------------------------- */
#define ds3231_monthcentury_read_reg_addr 0x05
#define ds3231_monthcentury_write_reg_addr 0x05
#define ds3231_monthcentury_delay 0
typedef ds3231_monthcentury_t ds3231_monthcentury;

/* --------------------------------------------------------------------------
 * Register name: Year
 * Register description: Year register stores the year value in BCD format.
 * -------------------------------------------------------------------------- */
#define ds3231_year_read_reg_addr 0x06
#define ds3231_year_write_reg_addr 0x06
#define ds3231_year_delay 0
typedef ds3231_year_t ds3231_year;

/* --------------------------------------------------------------------------
 * Register name: Alarm 1 Seconds
 * Register description: Alarm 1 seconds register
 * -------------------------------------------------------------------------- */
#define ds3231_alarm_1_seconds_read_reg_addr 0x07
#define ds3231_alarm_1_seconds_write_reg_addr 0x07
#define ds3231_alarm_1_seconds_delay 0
typedef ds3231_alarm_1_seconds_t ds3231_alarm_1_seconds;

/* --------------------------------------------------------------------------
 * Register name: Alarm 1 Minutes
 * Register description: This register holds the minutes value for Alarm 1.
 * -------------------------------------------------------------------------- */
#define ds3231_alarm_1_minutes_read_reg_addr 0x08
#define ds3231_alarm_1_minutes_write_reg_addr 0x08
#define ds3231_alarm_1_minutes_delay 0
typedef ds3231_alarm_1_minutes_t ds3231_alarm_1_minutes;

/* --------------------------------------------------------------------------
 * Register name: Alarm 1 Hour
 * Register description: Alarm 1 hour register
 * -------------------------------------------------------------------------- */
#define ds3231_alarm_1_hour_read_reg_addr 0x09
#define ds3231_alarm_1_hour_write_reg_addr 0x09
#define ds3231_alarm_1_hour_delay 0
typedef ds3231_alarm_1_hour_t ds3231_alarm_1_hour;

/* --------------------------------------------------------------------------
 * Register name: Alarm 1 Day/Date
 * Register description: Register for setting the day or date for Alarm 1
 * -------------------------------------------------------------------------- */
#define ds3231_alarm_1_daydate_read_reg_addr 0x0a
#define ds3231_alarm_1_daydate_write_reg_addr 0x0a
#define ds3231_alarm_1_daydate_delay 0
typedef ds3231_alarm_1_daydate_t ds3231_alarm_1_daydate;

/* --------------------------------------------------------------------------
 * Register name: Alarm 2 Minutes
 * Register description: This register holds the minutes value for Alarm 2.
 * -------------------------------------------------------------------------- */
#define ds3231_alarm_2_minutes_read_reg_addr 0x0b
#define ds3231_alarm_2_minutes_write_reg_addr 0x0b
#define ds3231_alarm_2_minutes_delay 0
typedef ds3231_alarm_2_minutes_t ds3231_alarm_2_minutes;

/* --------------------------------------------------------------------------
 * Register name: Alarm 2 Hour
 * Register description: Alarm 2 Hour register
 * -------------------------------------------------------------------------- */
#define ds3231_alarm_2_hour_read_reg_addr 0x0c
#define ds3231_alarm_2_hour_write_reg_addr 0x0c
#define ds3231_alarm_2_hour_delay 0
typedef ds3231_alarm_2_hour_t ds3231_alarm_2_hour;

/* --------------------------------------------------------------------------
 * Register name: Alarm 2 Day/Date
 * Register description: Alarm 2 Day/Date register
 * -------------------------------------------------------------------------- */
#define ds3231_alarm_2_daydate_read_reg_addr 0x0d
#define ds3231_alarm_2_daydate_write_reg_addr 0x0d
#define ds3231_alarm_2_daydate_delay 0
typedef ds3231_alarm_2_daydate_t ds3231_alarm_2_daydate;

/* --------------------------------------------------------------------------
 * Register name: Control
 * Register description: Control register for the DS3231 RTC, managing oscillator, square-wave output, and alarm interrupts.
 * -------------------------------------------------------------------------- */
#define ds3231_control_read_reg_addr 0x0e
#define ds3231_control_write_reg_addr 0x0e
#define ds3231_control_delay 0
typedef ds3231_control_t ds3231_control;

/* --------------------------------------------------------------------------
 * Register name: Status
 * Register description: Control and status register for the DS3231 RTC
 * -------------------------------------------------------------------------- */
#define ds3231_status_read_reg_addr 0x0f
#define ds3231_status_write_reg_addr 0x0f
#define ds3231_status_delay 0
typedef ds3231_controlstatus_t ds3231_status;

/* --------------------------------------------------------------------------
 * Register name: Aging Offset
 * Register description: The aging offset register is used to add or subtract from the codes in the capacitance array registers.
 * -------------------------------------------------------------------------- */
#define ds3231_aging_offset_read_reg_addr 0x10
#define ds3231_aging_offset_write_reg_addr 0x10
#define ds3231_aging_offset_delay 0
typedef ds3231_aging_offset_t ds3231_aging_offset;

/* --------------------------------------------------------------------------
 * Register name: MSB of Temp
 * Register description: Upper byte of the temperature register
 * -------------------------------------------------------------------------- */
#define ds3231_msb_of_temp_read_reg_addr 0x11
#define ds3231_msb_of_temp_delay 0
typedef ds3231_msb_of_temp_t ds3231_msb_of_temp;

/* --------------------------------------------------------------------------
 * Register name: LSB of Temp
 * Register description: Lower byte of the temperature register
 * -------------------------------------------------------------------------- */
#define ds3231_lsb_of_temp_read_reg_addr 0x12
#define ds3231_lsb_of_temp_delay 0
typedef ds3231_lsb_of_temp_t ds3231_lsb_of_temp;


#endif//_SRC_DS3231_REGISTERS_H
