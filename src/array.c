#define G_THIS
#include "-2/array.h"
#undef G_THIS

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "-0/debug_shortcut.h"
#include "-0_types.h"

#define G_THIS
#include "-0_common.h"
#undef G_THIS

static inline void *addr_unchecked(g_2_array_t *self, size_t index) {
  return (void *)(((unsigned char *)self->opaque) + index * self->element_size);
}

G_EXPORT g_2_array_t *g_2_array(G_P size_t length, size_t element_size,
                                g_0_err_t (*initialize)(G_P void *context,
                                                        size_t i, void *out),
                                void *context) {
  G_B;

  g_2_array_t *const result =
      (g_2_array_t *)malloc(sizeof(g_2_array_t) + element_size * length);
  if (!result) {
    return NULL;
  }
  result->length = length;
  result->element_size = element_size;
  if (initialize) {
    for (size_t i = 0; i < length; i++) {
      if (initialize(G_A context, i, addr_unchecked(result, i))) {
        free(result);
        return NULL;
      }
    }
  }
  return result;
}

G_EXPORT g_0_err_t g_2_array_set(G_P g_2_array_t *self, size_t index,
                                 const void *data) {
  G_B;

  if (index >= self->length) {
    return true;
  }
  memcpy(addr_unchecked(self, index), data, self->element_size);
  return false;
}

G_EXPORT g_0_err_t g_2_array_get(G_P g_2_array_t *self, size_t index,
                                 void *data) {
  G_B;

  if (index >= self->length) {
    return true;
  }
  memcpy(data, addr_unchecked(self, index), self->element_size);
  return false;
}

G_EXPORT g_0_err_t g_2_array_get_addr(G_P g_2_array_t *self, size_t index,
                                      void **out) {
  G_B;

  if (index >= self->length) {
    return true;
  }
  *out = addr_unchecked(self, index);
  return false;
}
