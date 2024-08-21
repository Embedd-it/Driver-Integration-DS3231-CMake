/******************************************************************************
* Company: Embedd Limited
*
* File: event_manager.c
*
* Description: Provides an event manager's implementation
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

#include    <string.h>
#include    <stdbool.h>

#include    "event_manager_cfg.h"
#include    "embedd_event_types.h"

// ------------------------------------------------------------------------- //
// event manager data

/*!
 *  \struct   cb_item_t
 *  \brief    callback entry in table
 *
 *  \param    one_shot    one-shot option, null - regular, 1 - one shot
 *  \param    cb          callback
 */
typedef struct {
    int                 one_shot;
    embedd_callback_t   cb;
}   cb_item_t;

/*!
 *  \struct   id_item_t
 *  \brief    structure for id, includes id and table of potential callbacks
 *
 *  \param    id                id of event
 *  \param    cb_item_t table   table for single id
 */
typedef struct {
    int id;
    cb_item_t table[EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT];
}   id_item_t;

/*!
 *  \brief    table of processed is with its own tables
 */
static id_item_t event_manager_data[EMBEDD_EVENT_MGR_MAX_ACTIVE_ID_COUNT];  // <! table for all active ids
// ------------------------------------------------------------------------- //
// event queue data
static struct   EventSource queue[EMBEDD_EVENT_MGR_MAX_QUEUE_ITEMS_COUNT];  // queue cycle buffer
static struct   EventSource *queue_wr_ptr =(struct EventSource *)NULL;      // buffer write pointer
static struct   EventSource *queue_rd_ptr =(struct EventSource *)NULL;      // buffer read pointer
static size_t   queue_data_size           =0;                               // queue data current size
static int      process_enable            =false;                           // process enable flag, true - processing enabled, false - disabled

static void queue_rd_inc();
static void queue_wr_inc();

static id_item_t* get_id_ptr(int event_id);
static EMBEDD_RESULT register_cb(  int event_id, embedd_callback_t cb, int one_shot );
// ------------------------------------------------------------------------- //
__attribute__((weak)) void engage_guard() {}
__attribute__((weak)) void disengage_guard() {}
__attribute__((weak)) void engage_init() {}
__attribute__((weak)) void engage_deinit() {}
// ------------------------------------------------------------------------- //
// event manager functions
EMBEDD_RESULT embedd_event_manager_init() {
    queue_wr_ptr    = queue;
    queue_rd_ptr    = queue;
    queue_data_size = 0;
    process_enable  = true;
    memset ( event_manager_data, 0, sizeof(event_manager_data) );
    engage_init();
    return EMBEDD_RESULT_OK;
}

EMBEDD_RESULT embedd_event_manager_deinit() {
    queue_wr_ptr    = (struct EventSource *)NULL;
    queue_rd_ptr    = (struct EventSource *)NULL;
    queue_data_size = 0;
    process_enable  = false;
    engage_deinit();
    return EMBEDD_RESULT_OK;
}

EMBEDD_RESULT embedd_event_manager_register_oneshot( int event_id, embedd_callback_t cb ) { 
    EMBEDD_RESULT res = EMBEDD_RESULT_OK;
    engage_guard();
    res = register_cb( event_id, cb, true );
    disengage_guard();
    return res;
}

EMBEDD_RESULT embedd_event_manager_register_callback(  int event_id, embedd_callback_t cb ) {
    EMBEDD_RESULT res = EMBEDD_RESULT_OK;
    engage_guard();
    res = register_cb( event_id, cb, false );
    disengage_guard();
    return res;
}

EMBEDD_RESULT embedd_event_manager_unregister_callback( int event_id, embedd_callback_t cb ) { 
    EMBEDD_RESULT res = EMBEDD_RESULT_OK;
    if (event_id == VOID_EVENT_ID) {
        res = EMBEDD_RESULT_ERR;
    } else {
        engage_guard();
        id_item_t* pId = get_id_ptr(event_id);
        if( pId == NULL ) {
            res = EMBEDD_RESULT_ERR;
        } else {
            cb_item_t *pCb = pId->table;
            for( ; (pCb < pId->table + EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT) && (pCb->cb != cb); ++pCb );
            if( pCb == pId->table + EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT ) {
                res = EMBEDD_RESULT_ERR;
            } else {
                pCb->cb       =0;
                pCb->one_shot =false;
                
                for( ; (pCb < pId->table + EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT) && (pCb->cb == NULL); ++pCb );
                if( pCb == pId->table + EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT ) {
                    pId->id = 0;
                }
            }
        }
        disengage_guard();
    }
    return res; 
}

EMBEDD_RESULT embedd_event_manager_trigger(int event_id, void *device) {
    EMBEDD_RESULT res = EMBEDD_RESULT_OK;
    if( event_id != VOID_EVENT_ID ) {
        if( get_id_ptr(event_id) != NULL ) {
            if( queue_data_size == EMBEDD_EVENT_MGR_MAX_QUEUE_ITEMS_COUNT ) {
                queue_rd_inc();
            }      

            struct   EventSource ev = { .device = (embedd_device_t*)device, .event_id = event_id };
        
            engage_guard();
            memcpy( queue_wr_ptr, &ev, sizeof(struct EventSource) );
            disengage_guard(); 

            queue_wr_inc();
            res = EMBEDD_RESULT_OK; 
        } else {
            res = EMBEDD_RESULT_ERR;
        }
    } else {
        res = EMBEDD_RESULT_ERR;
    }
    return res;
}

EMBEDD_RESULT embedd_event_manager_process_events_enable() { 
    process_enable  =true;
    return EMBEDD_RESULT_OK; 
}

EMBEDD_RESULT embedd_event_manager_process_events_disable() { 
    process_enable  =false;
    return EMBEDD_RESULT_OK; 
}

EMBEDD_RESULT embedd_event_manager_process() {
    if( process_enable ) {
        
        for( ; queue_data_size; ) {
            // check if if is in list
            engage_guard();    
            struct   EventSource ev = *queue_rd_ptr;
            disengage_guard();    
            id_item_t* pId = get_id_ptr(ev.event_id);
            if( pId != NULL ) {
                // check if exists registered callback
                for( cb_item_t *pCb = pId->table ; pCb < pId->table + EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT; ++pCb ) {
                    if( pCb->cb ) {
                        (*pCb->cb)( &ev );
                        if( pCb->one_shot ) {
                            // removed callback if one shot option
                            pCb->cb =(embedd_callback_t)NULL;
                            pCb->one_shot =0;
                        }
                    }
                }
            }
            queue_rd_inc();
#if EMBEDD_EVENT_MGR_PROCESS_ONE_ITEM == 1 
            break;
#endif
        }
    }
    return EMBEDD_RESULT_OK; 
}

// ------------------------------------------------------------------------- //
static void queue_rd_inc() {
    engage_guard();
    -- queue_data_size;
    ++ queue_rd_ptr;
    if( queue_rd_ptr >= queue + EMBEDD_EVENT_MGR_MAX_QUEUE_ITEMS_COUNT ) {
        queue_rd_ptr = queue;
    }
    disengage_guard();
}

static void queue_wr_inc() {
    engage_guard();
    ++ queue_data_size;
    ++ queue_wr_ptr;
    if( queue_wr_ptr >= queue + EMBEDD_EVENT_MGR_MAX_QUEUE_ITEMS_COUNT ) {
        queue_wr_ptr = queue;
    }
    disengage_guard();
}

static id_item_t* get_id_ptr(int event_id) {
    for( id_item_t* p = event_manager_data; p < event_manager_data + EMBEDD_EVENT_MGR_MAX_ACTIVE_ID_COUNT; ++p ) {
        if( p->id == event_id ) {
            return p;
        }
    }
    return (id_item_t*)NULL;
}

static EMBEDD_RESULT register_cb(  int event_id, embedd_callback_t cb, int one_shot ) {
    if( cb == NULL || event_id == VOID_EVENT_ID ) {
        return EMBEDD_RESULT_ERR;
    }
    
    id_item_t* pId = get_id_ptr(event_id);
    if( pId != NULL ) {
        for( cb_item_t *pCb = pId->table ; pCb < pId->table + EMBEDD_EVENT_MGR_MAX_CB_FOR_ID_COUNT; ++pCb ) {
            if( pCb->cb == cb ) {
              // try to regsiter existing callback
              return EMBEDD_RESULT_ERR;
            }
            if( pCb->cb == NULL ) {
                pCb->cb = cb;
                pCb->one_shot =one_shot ? 1 : 0;
                return EMBEDD_RESULT_OK;
            }
        }
        // no free space for callback
        return EMBEDD_RESULT_ERR;
    }
        
    // no id, look for free space        
    pId = get_id_ptr(VOID_EVENT_ID);
    if( pId != NULL ) {
        pId->id = event_id;
        pId->table[0].cb = cb;
        pId->table[0].one_shot =one_shot;
        return EMBEDD_RESULT_OK;
    } 
    
    // no free space for new id
    return EMBEDD_RESULT_ERR;
}
