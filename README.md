# Generic notification mechanism

## Brief

Throughout application programming there are always events 
that occur and you like to register a notification / callback
function to this event. This module will support you in that.

The module provides function to initialize a notification,
assign a notification and finally notify the notification.

## Reference

### Initialize a notification

Initialize the notification structure
```C 
static inline void
notify_init(NotifyData_t * ptCtx,
            pfNotifyHdlr * pfHdlr,
            void * pvReceiver,
            int32_t s32Info);
```

### Clear a notification

Clear the notification structure
```C 
static inline void
notify_clear(NotifyData_t * ptCtx);
```


### Assign a notification

Assign a notification to an event
```C 
static inline void
notify_assign(NotifyData_t * ptSignal, NotifyData_t * ptSlot);
```


### Fire a notification

Fire a notification
```C 
static inline void
notify_fire(NotifyData_t * ptCtx,
            void * pvSender,
            void * pvData,
            int32_t s32DataSize);
```
