#ifndef G_2_ARRAY_H
#define G_2_ARRAY_H

#include <stddef.h>

#include "-0_common.h"
#include "-0_types.h"

#include "array_types.h"

G_EXPORT g_2_array_t *g_2_array(size_t length, size_t element_size,
                                g_0_err_t (*initialize)(void *context, size_t i,
                                                        void *out),
                                void *context);

G_EXPORT g_0_err_t g_2_array_set(g_2_array_t *self, size_t index,
                                 const void *data);

G_EXPORT g_0_err_t g_2_array_get(g_2_array_t *self, size_t index, void *data);

G_EXPORT g_0_err_t g_2_array_get_addr(g_2_array_t *self, size_t index,
                                      void **out);

#endif
