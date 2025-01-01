#ifndef G_2_ARRAY_TYPES_H
#define G_2_ARRAY_TYPES_H

#include <stddef.h>

typedef struct g_2_array {
  size_t length;
  size_t element_size;
  unsigned char opaque[];
} g_2_array_t;

#endif
