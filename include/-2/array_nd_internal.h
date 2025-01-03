#ifndef G_2_ARRAY_ND_INTERNAL_H
#define G_2_ARRAY_ND_INTERNAL_H

#ifdef __cplusplus
#include <cstddef.h>
#else
#include <stddef.h>
#endif

#include "-0_common.h"

void *g_2_array_nd_internal_alloc(size_t element_size, const size_t *length,
                                  size_t dimension, size_t struct_size);

g_err_t g_2_array_nd_internal_index(const size_t *length, const size_t *index,
                                    size_t dimension, size_t *out);

static inline void *g_2_array_nd_internal_addr_unchecked(void *data,
                                                         size_t element_size,
                                                         size_t index) {
  return (void *)(((unsigned char *)data) + index * element_size);
}

#endif
