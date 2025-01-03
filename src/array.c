#define G_EXPORT
#include "-2/array.h"
#undef G_EXPORT

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "-0/common_export.h"

static inline void *addr_unchecked(g_2_array_t *self, size_t index) {
  return (void *)(((unsigned char *)self->opaque) + index * self->element_size);
}

G_API g_2_array_t *g_2_array(size_t length, size_t element_size,
                             g_err_t (*initialize)(void *context, size_t i,
                                                   void *out),
                             void *context) {
  g_2_array_t *const result =
      (g_2_array_t *)malloc(sizeof(g_2_array_t) + element_size * length);
  if (!result) {
    return NULL;
  }
  result->length = length;
  result->element_size = element_size;
  if (initialize) {
    for (size_t i = 0; i < length; i++) {
      if (initialize(context, i, addr_unchecked(result, i))) {
        free(result);
        return NULL;
      }
    }
  }
  return result;
}

G_API g_err_t g_2_array_set(g_2_array_t *self, size_t index, const void *data) {
  if (index >= self->length) {
    return true;
  }
  memcpy(addr_unchecked(self, index), data, self->element_size);
  return false;
}

G_API g_err_t g_2_array_get(g_2_array_t *self, size_t index, void *data) {
  if (index >= self->length) {
    return true;
  }
  memcpy(data, addr_unchecked(self, index), self->element_size);
  return false;
}

G_API g_err_t g_2_array_get_addr(g_2_array_t *self, size_t index, void **out) {
  if (index >= self->length) {
    return true;
  }
  *out = addr_unchecked(self, index);
  return false;
}
