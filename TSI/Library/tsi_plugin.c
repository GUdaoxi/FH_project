#include "tsi_plugin.h"
#include "tsi_object.h"

/* TSI library plugin list indexing helper macros ---------------------------*/
/** Plugin list head element (NULL). */
TSI_USED static const TSI_LibCallbacksTypeDef *const TSI_PLUGINS_BEGIN
TSI_SECTION(TSI_PLUGINS_BEGIN_SECTION) = NULL;

/** Plugin list tail element (NULL). */
TSI_USED static const TSI_LibCallbacksTypeDef *const TSI_PLUGINS_END
TSI_SECTION(TSI_PLUGINS_END_SECTION) = NULL;

/* TSI library callback dispatcher definition helper macros -----------------*/
/* Callback dispatcher with 0 or 1 param. */
#define TSI_PLUGIN_DISPATCHER(CBNAME, PARAM)                                \
    void TSI_Plugin_##CBNAME##_Callback(PARAM)                              \
    {                                                                       \
        const TSI_LibCallbacksTypeDef* const* cb;                           \
        for(cb = &TSI_PLUGINS_BEGIN; cb < &TSI_PLUGINS_END; cb++) {         \
            if((*cb) != NULL && (*cb)->CBNAME != NULL) {                    \

/* Callback dispatcher with 2 params. */
#define TSI_PLUGIN_DISPATCHER_2(CBNAME, PARAM1, PARAM2)                     \
    void TSI_Plugin_##CBNAME##_Callback(PARAM1, PARAM2)                     \
    {                                                                       \
        const TSI_LibCallbacksTypeDef* const* cb;                           \
        for(cb = &TSI_PLUGINS_BEGIN; cb < &TSI_PLUGINS_END; cb++) {         \
            if((*cb) != NULL && (*cb)->CBNAME != NULL) {                    \

#define TSI_PLUGIN_DISPATCHER_END()                                         \
            }                                                               \
        }                                                                   \
    }

/** Setup dispatcher which dispachs callback to each plugin. */
#define TSI_PLUGIN_SET_CB_DISPATCHER(CB, CBNAME)                            \
    ((CB).CBNAME = TSI_Plugin_##CBNAME##_Callback)

/** Setup callback to the plugin with valid callback and highest priority. */
#define TSI_PLUGIN_SET_CB_DIRECT(CB, CBNAME)                                \
    {                                                                       \
        const TSI_LibCallbacksTypeDef* const* cb;                           \
        for(cb = &TSI_PLUGINS_BEGIN; cb < &TSI_PLUGINS_END; cb++) {         \
            if((*cb) != NULL && (*cb)->CBNAME != NULL) {                    \
                (CB).CBNAME = (*cb)->CBNAME;                                \
                break;                                                      \
            }                                                               \
        }                                                                   \
    }

/* Dispatcher definitions ---------------------------------------------------*/
/*  Library Init completed callback */
TSI_PLUGIN_DISPATCHER(initCompleted, TSI_LibHandleTypeDef *handle)
{
    (*cb)->initCompleted(handle);
}
TSI_PLUGIN_DISPATCHER_END()

/* Library DeInit completed callback */
TSI_PLUGIN_DISPATCHER(deInitCompleted, TSI_LibHandleTypeDef *handle)
{
    (*cb)->deInitCompleted(handle);
}
TSI_PLUGIN_DISPATCHER_END()

/* Library started callback */
TSI_PLUGIN_DISPATCHER(started, TSI_LibHandleTypeDef *handle)
{
    (*cb)->started(handle);
}
TSI_PLUGIN_DISPATCHER_END()

/* Library stopped callback */
TSI_PLUGIN_DISPATCHER(stopped, TSI_LibHandleTypeDef *handle)
{
    (*cb)->stopped(handle);
}
TSI_PLUGIN_DISPATCHER_END()

/* Widget initialized callback */
TSI_PLUGIN_DISPATCHER_2(widgetInitCompleted, TSI_LibHandleTypeDef *handle,
                        TSI_WidgetTypeDef *widget)
{
    (*cb)->widgetInitCompleted(handle, widget);
}
TSI_PLUGIN_DISPATCHER_END()

/* Widget scan completed callback */
TSI_PLUGIN_DISPATCHER(widgetScanCompleted, TSI_LibHandleTypeDef *handle)
{
    (*cb)->widgetScanCompleted(handle);
}
TSI_PLUGIN_DISPATCHER_END()

/* Widget data updated callback */
TSI_PLUGIN_DISPATCHER(widgetValueUpdated, TSI_LibHandleTypeDef *handle)
{
    (*cb)->widgetValueUpdated(handle);
}
TSI_PLUGIN_DISPATCHER_END()

/* Widget status updated callback */
TSI_PLUGIN_DISPATCHER(widgetStatusUpdated, TSI_LibHandleTypeDef *handle)
{
    (*cb)->widgetStatusUpdated(handle);
}
TSI_PLUGIN_DISPATCHER_END()

/* API implementations ------------------------------------------------------*/
void TSI_Plugin_Init(TSI_LibHandleTypeDef *handle)
{
    /* Setup callback dispatcher */
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, initCompleted);
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, deInitCompleted);
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, started);
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, stopped);
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, widgetInitCompleted);
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, widgetScanCompleted);
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, widgetValueUpdated);
    TSI_PLUGIN_SET_CB_DISPATCHER(handle->cb, widgetStatusUpdated);

    /* Setup callback */
    TSI_PLUGIN_SET_CB_DIRECT(handle->cb, getInitScanBufferAndCount);
    TSI_PLUGIN_SET_CB_DIRECT(handle->cb, processInitScanValue);
}
