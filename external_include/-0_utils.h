#ifndef G_0_UTILS_H
#define G_0_UTILS_H

#ifdef __cplusplus
#include <cstddef>
#else
#include <stdbool.h>
#include <stddef.h>
#endif

#include "-0_common.h"

#ifdef __cplusplus
extern "C" {
#endif

G_API void g_0_bzero(void *ptr, size_t size);
G_API void *g_0_memdup(void *ptr, size_t size);
G_API void *g_0_nonnull(void *ptr);
G_API void g_0_assert(bool condition);

#ifdef __cplusplus
}
#endif

#endif
