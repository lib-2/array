#ifndef G_2_ARRAY_ND_H
#define G_2_ARRAY_ND_H

#include <stddef.h>
#include <string.h>

#include "-0_common.h"

#include "array_nd_internal.h"

#define G_2_ARRAY_ND(dimension) g_2_array_nd__##dimension##__t
#define G_2_ARRAY_ND_NEW(dimension) g_2_array_nd__##dimension##__new
#define G_2_ARRAY_ND_SET(dimension) g_2_array_nd__##dimension##__set
#define G_2_ARRAY_ND_GET(dimension) g_2_array_nd__##dimension##__get
#define G_2_ARRAY_ND_GET_ADDR(dimension) g_2_array_nd__##dimension##__get_addr

#define G_2_ARRAY_ND_DEFINE_TYPE(dimension)                                    \
  typedef struct g_2_array_nd__##dimension {                                   \
    size_t length[dimension];                                                  \
    size_t element_size;                                                       \
    unsigned char opaque[];                                                    \
  } g_2_array_nd__##dimension##__t;                                            \
  static inline g_2_array_nd__##dimension##__t                                 \
      *g_2_array_nd__##dimension##__new(size_t element_size,                   \
                                        size_t length[dimension]) {            \
    g_2_array_nd__##dimension##__t *const result =                             \
        (g_2_array_nd__##dimension##__t *)g_2_array_nd_internal_alloc(         \
            element_size, length, dimension,                                   \
            sizeof(g_2_array_nd__##dimension##__t));                           \
    memcpy(result->length, length, sizeof(size_t) * dimension);                \
    result->element_size = element_size;                                       \
    return result;                                                             \
  }                                                                            \
  static inline g_0_err_t g_2_array_nd__##dimension##__set(                    \
      g_2_array_nd__##dimension##__t *self, size_t index[dimension],           \
      const void *data) {                                                      \
    size_t idx;                                                                \
    if (g_2_array_nd_internal_index(self->length, index, dimension, &idx)) {   \
      return 1;                                                                \
    }                                                                          \
    memcpy(g_2_array_nd_internal_addr_unchecked(self->opaque,                  \
                                                self->element_size, idx),      \
           data, self->element_size);                                          \
    return 0;                                                                  \
  }                                                                            \
  static inline g_0_err_t g_2_array_nd__##dimension##__get(                    \
      g_2_array_nd__##dimension##__t *self, size_t index[dimension],           \
      void *data) {                                                            \
    size_t idx;                                                                \
    if (g_2_array_nd_internal_index(self->length, index, dimension, &idx)) {   \
      return 1;                                                                \
    }                                                                          \
    memcpy(data,                                                               \
           g_2_array_nd_internal_addr_unchecked(self->opaque,                  \
                                                self->element_size, idx),      \
           self->element_size);                                                \
    return 0;                                                                  \
  }                                                                            \
  static inline g_0_err_t g_2_array_nd__##dimension##__get_addr(               \
      g_2_array_nd__##dimension##__t *self, size_t index[dimension],           \
      void **out) {                                                            \
    size_t idx;                                                                \
    if (g_2_array_nd_internal_index(self->length, index, dimension, &idx)) {   \
      return 1;                                                                \
    }                                                                          \
    *out = g_2_array_nd_internal_addr_unchecked(self->opaque,                  \
                                                self->element_size, idx);      \
    return 0;                                                                  \
  }

#endif
