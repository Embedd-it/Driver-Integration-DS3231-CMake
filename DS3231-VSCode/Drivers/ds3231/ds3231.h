/*!
 * \file ds3231.h
 * \brief Ds3231
 *
 * The main file that should be included in a project to use DS3231.
 * Includes all the device's functionality and provides macros to create the
 * device and interact with it.
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

#ifndef _SRC_DS3231_H
#define _SRC_DS3231_H

#include "embedd_driver.h"
#include "embedd_hal.h"
#include "embedd_i2c.h"
#include "embedd_event.h"
#include "embedd_event_types.h"
#include "event_manager_cfg.h"
#include "embedd_misc.h"
#include "ds3231_data_types.h"
#include "ds3231_events.h"
#include "ds3231_registers.h"

/*!
 * \var ds3231_api
 * \brief The device's API structure containing pointers to all device's API functions
 */
extern const ds3231_api_t ds3231_api;

/*!
 * \macro DS3231_WRITE_REG
 * \brief write register macro
 *
 * \param dev device object,
 * \param _typename typename for register
 * \param var variable for writing data
 */
#define DS3231_WRITE_REG(dev, _typename, var) \
  ((ds3231_api_t*)(dev).api)->ds3231_write_reg(&(dev), \
  _typename##_write_reg_addr, &(var), \
  sizeof(_typename), _typename##_delay)

/*!
 * \macro DS3231_READ_REG
 * \brief read register macro
 *
 * \param dev device object
 * \param _typename typename for register
 * \param var variable for read data
 */
#define DS3231_READ_REG(dev, _typename, var) \
  ((ds3231_api_t*)(dev).api)->ds3231_read_reg(&(dev), \
  _typename##_read_reg_addr, &(var), \
  sizeof(_typename), _typename##_delay)

/*!
* \macro DS3231_I2C_DEVICE_DEFINE
* \brief Macro to create the device's objects
*
* \param var name of device object's variable
* \param _name_of_device string name of the device (for debug purpose)
*/
#define DS3231_I2C_DEVICE_DEFINE(var, _name_of_device)\
  static ds3231_data_t var##_data;\
  static embedd_i2c_dev_cfg_t var##_i2c_cfg = {0};\
  static embedd_dev_cfg_t var##_cfg = {\
    .bus_cfg = { .bus_type = EMBEDD_BUS_TYPE_I2C, .configs = (void*)&var##_i2c_cfg },\
  };\
  EMBEDD_DEVICE_DEFINE_FULL(var, _name_of_device, &var##_cfg, &ds3231_api, NULL, &var##_data, NULL, NULL)

#endif//_SRC_DS3231_H
