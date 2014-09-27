/*******************************************************************************
 *
 * TNeoKernel: real-time kernel initially based on TNKernel
 *
 *    TNKernel:                  copyright © 2004, 2013 Yuri Tiomkin.
 *    PIC32-specific routines:   copyright © 2013, 2014 Anders Montonen.
 *    TNeoKernel:                copyright © 2014       Dmitry Frank.
 *
 *    TNeoKernel was born as a thorough review and re-implementation of
 *    TNKernel. The new kernel has well-formed code, inherited bugs are fixed
 *    as well as new features being added, and it is tested carefully with
 *    unit-tests.
 *
 *    API is changed somewhat, so it's not 100% compatible with TNKernel,
 *    hence the new name: TNeoKernel.
 *
 *    Permission to use, copy, modify, and distribute this software in source
 *    and binary forms and its documentation for any purpose and without fee
 *    is hereby granted, provided that the above copyright notice appear
 *    in all copies and that both that copyright notice and this permission
 *    notice appear in supporting documentation.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE DMITRY FRANK AND CONTRIBUTORS "AS IS"
 *    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DMITRY FRANK OR CONTRIBUTORS BE
 *    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *    THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

/**
 * \file
 *
 * Compatibility layer for old projects that use old TNKernel names;
 * usage of them in new projects is discouraged.
 *
 * If you're porting your existing application written for TNKernel, it 
 * might be useful though.
 *
 * Included automatially if the option `TN_OLD_TNKERNEL_NAMES` is set.
 *
 * @see `TN_OLD_TNKERNEL_NAMES`
 *
 */

#ifndef _TN_OLDSYMBOLS_H
#define _TN_OLDSYMBOLS_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "tn_common.h"



#ifndef TN_OLD_TNKERNEL_NAMES
#  error TN_OLD_TNKERNEL_NAMES is not defined
#endif

#if TN_OLD_TNKERNEL_NAMES


#ifdef __cplusplus
extern "C"  {     /*}*/
#endif

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

typedef struct TN_ListItem    CDLL_QUEUE;
typedef struct TN_Mutex       TN_MUTEX;
typedef struct TN_DQueue      TN_DQUE;
typedef struct TN_Task        TN_TCB;
typedef struct TN_FMem        TN_FMP;
typedef struct TN_Sem         TN_SEM;

//there's no compatibility with TNKernel's event object,
//so, this one is commented
//typedef struct TN_EventGrp    TN_EVENT;




/*******************************************************************************
 *    GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/

/*
 * compatibility with old struct names
 */
#define  _CDLL_QUEUE    TN_ListItem
#define  _TN_MUTEX      TN_Mutex
#define  _TN_DQUE       TN_DQueue
#define  _TN_TCB        TN_Task
#define  _TN_FMP        TN_FMem
#define  _TN_SEM        TN_Sem

//there's no compatibility with TNKernel's event object,
//so, this one is commented
//#define  _TN_EVENT      TN_EventGrp

#define  MAKE_ALIG      TN_MAKE_ALIG


#define  TSK_STATE_RUNNABLE            TN_TASK_STATE_RUNNABLE
#define  TSK_STATE_WAIT                TN_TASK_STATE_WAIT
#define  TSK_STATE_SUSPEND             TN_TASK_STATE_SUSPEND
#define  TSK_STATE_WAITSUSP            TN_TASK_STATE_WAITSUSP
#define  TSK_STATE_DORMANT             TN_TASK_STATE_DORMANT

#define  TN_TASK_START_ON_CREATION     TN_TASK_CREATE_OPT_START
#define  TN_EXIT_AND_DELETE_TASK       TN_TASK_EXIT_OPT_DELETE

#define  TN_EVENT_WCOND_AND            TN_EVENTGRP_WMODE_AND
#define  TN_EVENT_WCOND_OR             TN_EVENTGRP_WMODE_OR

#define  TSK_WAIT_REASON_NONE          TN_WAIT_REASON_NONE
#define  TSK_WAIT_REASON_SLEEP         TN_WAIT_REASON_SLEEP
#define  TSK_WAIT_REASON_SEM           TN_WAIT_REASON_SEM
#define  TSK_WAIT_REASON_EVENT         TN_WAIT_REASON_EVENT
#define  TSK_WAIT_REASON_DQUE_WSEND    TN_WAIT_REASON_DQUE_WSEND
#define  TSK_WAIT_REASON_DQUE_WRECEIVE TN_WAIT_REASON_DQUE_WRECEIVE
#define  TSK_WAIT_REASON_MUTEX_C       TN_WAIT_REASON_MUTEX_C
#define  TSK_WAIT_REASON_MUTEX_I       TN_WAIT_REASON_MUTEX_I
#define  TSK_WAIT_REASON_WFIXMEM       TN_WAIT_REASON_WFIXMEM


#define  TERR_NO_ERR                   TN_RC_OK
#define  TERR_OVERFLOW                 TN_RC_OVERFLOW
#define  TERR_WCONTEXT                 TN_RC_WCONTEXT
#define  TERR_WSTATE                   TN_RC_WSTATE
#define  TERR_TIMEOUT                  TN_RC_TIMEOUT
#define  TERR_WRONG_PARAM              TN_RC_WPARAM
#define  TERR_ILUSE                    TN_RC_ILLEGAL_USE
#define  TERR_NOEXS                    TN_RC_INVALID_OBJ
#define  TERR_DLT                      TN_RC_DELETED
#define  TERR_FORCED                   TN_RC_FORCED
#define  TERR_INTERNAL                 TN_RC_INTERNAL


#define  TN_MUTEX_ATTR_CEILING         TN_MUTEX_PROT_CEILING
#define  TN_MUTEX_ATTR_INHERIT         TN_MUTEX_PROT_INHERIT



#define  tn_sem_polling                tn_sem_acquire_polling
#define  tn_sem_ipolling               tn_sem_iacquire_polling

#define  tn_fmem_get_ipolling          tn_fmem_iget_polling

#define  tn_queue_ireceive             tn_queue_ireceive_polling



#define  align_attr_start              TN_ARCH_STK_ATTR_BEFORE
#define  align_attr_end                TN_ARCH_STK_ATTR_AFTER

#define  tn_cpu_int_disable            tn_arch_int_dis
#define  tn_cpu_int_enable             tn_arch_int_en

#define  tn_cpu_save_sr                tn_arch_sr_save_int_dis
#define  tn_cpu_restore_sr             tn_arch_sr_restore

#define  tn_disable_interrupt          TN_INT_DIS_SAVE
#define  tn_enable_interrupt           TN_INT_RESTORE

#define  tn_idisable_interrupt         TN_INT_IDIS_SAVE
#define  tn_ienable_interrupt          TN_INT_IRESTORE

#define  tn_chk_irq_disabled           TN_IS_INT_DISABLED
#define  TN_NUM_PRIORITY               TN_PRIORITIES_CNT
#define  _TN_BITS_IN_INT                TN_INT_WIDTH

#define  TN_ALIG                       TN_ALIGN

/*******************************************************************************
 *    PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/


#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif // TN_OLD_TNKERNEL_NAMES

#endif // _TN_OLDSYMBOLS_H


/*******************************************************************************
 *    end of file
 ******************************************************************************/

