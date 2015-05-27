/******************************************************************************/
/** @file       example.c
 *******************************************************************************
 *
 *  @brief      Brief example for using the notification mechanism
 *              <p>
 *              Mechanism would be more usefull in an event driven application.
 *              In a multithreading application some saftey mechanism (semaphore,
 *              mutex) has to be added if a thread fires a notification for
 *              an other running thread.
 *
 *  @author     wht4
 *
 *  @remark     Last modifications
 *                 \li V1.0, May 2014, wht4, initial release
 *
 ******************************************************************************/
/*
 *  functions  global:
 *              main
 *  functions  local:
 *              .
 *
 ******************************************************************************/

/****** Header-Files **********************************************************/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "notify.h"

/****** Macros ****************************************************************/

/****** Data types ************************************************************/

/****** Fuction prototypes ****************************************************/
static void
exampleHandler(void  * pvReceiver,
               void  * pvSender,
               int32_t s32Info,
               void  * pvData,
               int32_t s32DataSize);

/****** Data ******************************************************************/
static char *  SENDER = "main";
static char *  RECEIVER = "notifyHandler";

/****** Implementation ********************************************************/

/*******************************************************************************
 *  function :    main
 ******************************************************************************/
int
main(int argc, char **argv) {

    int          i = 0;
    NotifyData_t notifyData;
    char         cText[100];

    /* Prevent compiler warnings */
    (void) argc;
    (void) argv;

    notify_init(&notifyData, exampleHandler, (void *) RECEIVER, 0);

    for (i = 0; i < 12; i++) {

        sprintf(cText, "We sleept for %d seconds", i);
        notify_fire(&notifyData, SENDER, (void *) cText, strlen(cText));
        sleep(1);
    }

    return (EXIT_SUCCESS);
}


/*******************************************************************************
 *  function :    notifyHandler
 ******************************************************************************/
static void
exampleHandler(void  * pvReceiver,
               void  * pvSender,
               int32_t s32Info,
               void  * pvData,
               int32_t s32DataSize) {

    printf("%s: Sender %s fired callback with: Info = %d, Data = %s, Data size = %d \r\n",
           (char *) pvReceiver,
           (char *) pvSender,
           s32Info,
           (char *) pvData,
           s32DataSize);
}
