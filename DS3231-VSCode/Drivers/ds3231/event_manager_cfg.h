/******************************************************************************
* Company: Embedd Limited
*
* File: event_manager_cfg.h
*
* Description: Contains event manager configuration
*
* Software License Agreement:
*
* This code is proprietary to Embedd Limited and may not be distributed
* or copied without the express permission of Embedd Limited. This code
* is provided "as is" without warranty of any kind, either expressed or
* implied, including but not limited to the implied warranties of
* merchantability and fitness for a particular purpose. This code is intended
* for use only within the user's organization by its employees and authorized
* agents, and may not be disclosed or used for any other purpose without
* prior written consent from Embedd Limited.
*
* Unauthorized distribution or use of this code, or any portion of it,
* including but not limited to publishing online or making it open source,
* may result in severe civil and criminal penalties, and will be prosecuted to
* the maximum extent possible under the law.
*
* ©️ 2024 Embedd Limited. All Rights Reserved.
******************************************************************************/

#ifndef _SRC_EMBEDD_EVENT_MGR_CFG_H
#define _SRC_EMBEDD_EVENT_MGR_CFG_H
  
/*!
 *          Maximum count of events id processed by event manager
 */
#define     EMBEDD_EVENT_MGR_MAX_ACTIVE_ID_COUNT    (2U)

/*!
 *          Maximum count of items in callback table for each event id
 */
#define     EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT    (2U)

/*!
 *          Maximum count of items in queue
 */
#define     EMBEDD_EVENT_MGR_MAX_QUEUE_ITEMS_COUNT  (4U)

/*!
 *          If this parameter is 1 events manager will process 
 *          queue by one item in queue
 *          If this parameter is 0 events manager will process
 *          all items in queue
 */
#define     EMBEDD_EVENT_MGR_PROCESS_ONE_ITEM       (1U)

 
#endif //_SRC_EMBEDD_EVENT_MGR_CFG_H
