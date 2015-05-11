/******************************************************************************/
/** \file       notify.h
 *******************************************************************************
 *
 *  \brief      Generic notification mechanism
 *              <p>
 *              Throughout application programming there are always events
 *              that occur and you like to register a notification / callback
 *              function to this event. This module will support you in that.
 *              <p>
 *              The module provides function to initialize a notification,
 *              assign a notification and finally notify the notification.
 *
 *  \author     wht4
 *
 ******************************************************************************/
/*
 *  function    .
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****** Header-Files **********************************************************/
#include <stdint.h>

/****** Macros ****************************************************************/

/****** Data types ************************************************************/
/*
 * \brief Notification callback function prototype
 * \param pvReceiver  Receiver instance
 * \param pvSender    Sender instance, provided by sender
 * \param s32Info     Notification info
 * \param pvData      Notification data, provided by sender
 * \param s32DataSize Size of notification data, provided by sender
 */
typedef void (*pfNotifyHdlr)(void  * pvReceiver, 
                             void  * pvSender, 
                             int32_t s32Info, 
                             void  * pvData, 
                             int32_t s32DataSize);


typedef struct _NotifyData_t{
    /** Callback function called if the event occurs */
    pfNotifyHdlr     pfHdlr;
    /** Receiver of the callback function */
    void           * pvReceiver;
    /** Notification info */
    int32_t          s32Info;

}NotifyData_t;

/****** Fuction prototypes ****************************************************/

/****** Data ******************************************************************/

/****** Implementation ********************************************************/

/*******************************************************************************
 *  function :    notify_init
 ******************************************************************************/
/** @brief        Initialize the notification structure
 *
 *  @type         global
 *
 *  @param[in]    psCtx       Pointer to the notification structure
 *  @param[in]    pfHdlr      Notification / callback function
 *  @param[in]    pvReceiver  Receiver of the callback
 *  @param[in]    s32Info     Info value passed on calling callback
 *
 *  @return       void
 *
 ******************************************************************************/
static inline void
notify_init(NotifyData_t * ptCtx, pfNotifyHdlr * pfHdlr, void * pvReceiver, int32_t s32Info) {
	
	ptCtx->pfHdlr = pfHdlr;
	ptCtx->pvReceiver = pvReceiver;
	ptCtx->s32Info = s32Info;
}


/*******************************************************************************
 *  function :    notify_clear
 ******************************************************************************/
/** @brief        Clear the notification structure
 *
 *  @type         global
 *
 *  @param[in]    psCtx       Pointer to the notification structure
 *
 *  @return       void
 *
 ******************************************************************************/
static inline void 
notify_clear(NotifyData_t * ptCtx) {
	
	ptCtx->pfHdlr = NULL;
	ptCtx->pvReceiver = NULL;
	ptCtx->s32Info = 0;   
}

 
/*******************************************************************************
 *  function :    notify_assign
 ******************************************************************************/
/** @brief        Assign a notification to an event
 *
 *  @type         global
 *
 *  @param[in]    ptSignal   Pointer to the notification structure of the event
 *  @param[in]    ptSlot     Notification structure which is assigned
 *
 *  @return       void
 *
 ******************************************************************************/
static inline void 
notify_assign(NotifyData_t * ptSignal, NotifyData_t * ptSlot) {
	 
	ptSignal->pfHdlr = ptSlot->pfHdlr;
	ptSignal->pvReceiver = ptSlot->pvReceiver;
	ptSignal->s32Info = ptSlot->s32Info; 
}


/*******************************************************************************
 *  function :    NOTIFICATION_NOTIFY
 ******************************************************************************/
/**
 * Notify the notification
 * \param[in]   psNotificationData  Pointer to the notification structure
 * \param[in]   pvSender            Sender of the notification
 * \param[in]   pvData              Data passed to the receiver of the
 *                                  notification
 * \param[in]   s32DataSize         Data size passed
 * \return      void
 */
/*******************************************************************************
 *  function :    notify_fire
 ******************************************************************************/
/** @brief        Fire a notification
 *
 *  @type         global
 *
 *  @param[in]    ptCtx        Pointer to the notification structure
 *  @param[in]    pvSender     Notification structure which is assigned
 *  @param[in]    pvData       Data passed to the receiver of the notification
 *  \param[in]    s32DataSize  Size of data passed
 *
 *  @return       void
 *
 ******************************************************************************/
static inline void
notify_fire(NotifyData_t * ptCtx, void * pvSender, void * pvData, int32_t s32DataSize) {
	
	if(ptCtx->pfHndlr != NULL) {
		
		ptCtx->pfHdlr(ptCtx->pvReceiver, 
		              pvSender,
		              ptCtx->s32Info,
		              pvData,
		              s32DataSize);
	}
}


#ifdef __cplusplus
}
#endif /* __cplusplus */
