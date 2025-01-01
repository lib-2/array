#define G_THIS
#include "-2/array_nd_internal.h"
#undef G_THIS

#include <stdbool.h>
#include <stdlib.h>

#include "-0_types.h"

#define G_THIS
#include "-0_common.h"
#undef G_THIS

G_EXPORT void *g_2_array_nd_internal_alloc(size_t element_size,
                                           const size_t *length,
                                           size_t dimension,
                                           size_t struct_size) {
  size_t size = element_size;
  for (size_t i = 0; i < dimension; i++) {
    size *= length[i];
  }
  return malloc(struct_size + size);
}

G_EXPORT g_0_err_t g_2_array_nd_internal_index(const size_t *length,
                                               const size_t *index,
                                               size_t dimension, size_t *out) {
  size_t result = 0;
  for (size_t i = 0; i < dimension; i++) {
    if (index[i] >= length[i]) {
      return true;
    }
    result = result * length[i] + index[i];
  }
  *out = result;
  return false;
}
