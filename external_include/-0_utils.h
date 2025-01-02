#ifndef G_0_UTILS_H
#define G_0_UTILS_H

#include <stdbool.h>
#include <stddef.h>

#include "-0_common.h"

G_EXPORT void g_0_bzero(void *ptr, size_t size);
G_EXPORT void *g_0_memdup(void *ptr, size_t size);
G_EXPORT void *g_0_nonnull(void *ptr);
G_EXPORT void g_0_assert(bool condition);

#endif
