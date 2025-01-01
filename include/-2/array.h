#ifndef G_2_ARRAY_H
#define G_2_ARRAY_H

#include <stddef.h>

#include "-0/debug_types.h"
#include "-0_common.h"
#include "-0_types.h"

#include "array_types.h"

G_EXPORT g_2_array_t *g_2_array(
    G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE size_t length, size_t element_size,
    g_0_err_t (*initialize)(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE void *context,
                            size_t i, void *out),
    void *context);

G_EXPORT g_0_err_t
g_2_array_set(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_2_array_t *self,
              size_t index, const void *data);

G_EXPORT g_0_err_t
g_2_array_get(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_2_array_t *self,
              size_t index, void *data);

G_EXPORT g_0_err_t
g_2_array_get_addr(G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE g_2_array_t *self,
                   size_t index, void **out);

#endif
