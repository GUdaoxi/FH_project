#ifndef TSI_PLUGIN_H
#define TSI_PLUGIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Exported macros ----------------------------------------------------------*/
/** Plugin register helper. */
#define TSI_PLUGIN(NAME, PRIORITY)                                                  \
    TSI_STATIC const TSI_LibCallbacksTypeDef TSI_Plugin_##NAME##_Callback;          \
    TSI_USED TSI_STATIC const TSI_LibCallbacksTypeDef* const TSI_Plugin             \
    TSI_SECTION(TSI_PLUGINS_SECTION PRIORITY) = &TSI_Plugin_##NAME##_Callback;      \
    TSI_STATIC const TSI_LibCallbacksTypeDef TSI_Plugin_##NAME##_Callback =

/* Foward declarations ------------------------------------------------------*/
struct _TSI_LibHandle;

/* Plugin APIs declaration --------------------------------------------------*/
void TSI_Plugin_Init(struct _TSI_LibHandle *handle);

#ifdef __cplusplus
}
#endif

#endif  /* TSI_PLUGIN_H */
