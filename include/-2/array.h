#ifndef G_2_ARRAY_H
#define G_2_ARRAY_H

#ifdef __cplusplus
#include <cstddef.h>
#else
#include <stddef.h>
#endif

#include "-0_common.h"

#include "array_types.h"

#ifdef __cplusplus
extern "C" {
#endif

g_2_array_t *g_2_array(size_t length, size_t element_size,
                       g_err_t (*initialize)(void *context, size_t i,
                                             void *out),
                       void *context);

g_err_t g_2_array_set(g_2_array_t *self, size_t index, const void *data);

g_err_t g_2_array_get(g_2_array_t *self, size_t index, void *data);

g_err_t g_2_array_get_addr(g_2_array_t *self, size_t index, void **out);

#ifdef __cplusplus
}
#endif

#endif
