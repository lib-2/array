#ifndef G_0_DEBUG_TYPES_H
#define G_0_DEBUG_TYPES_H

#include <stddef.h>

#if defined(RELEASE) || defined(PRODUCTION)
#define NDEBUG
#endif

#if defined(DEBUG) || defined(DEVELOPMENT) || defined(TEST)
#undef NDEBUG
#endif

typedef struct g_0_debug_stacktrace_node {
  const struct g_0_debug_stacktrace_node *previous;
  const char *function_name;
  const char *file_name;
  unsigned long long int line;
} g_0_debug_stacktrace_node_t;

#ifdef NDEBUG

#define G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE0 void
#define G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE

#define G_0_DEBUG_ROOT_FUNCTION_BODY_PRELUDE                                   \
  do {                                                                         \
  } while (0)
#define G_0_DEBUG_FUNCTION_BODY_PRELUDE                                        \
  do {                                                                         \
  } while (0)

#define G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE0
#define G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE

#else

#define G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE0                                  \
  const g_0_debug_stacktrace_node_t                                            \
      *g_0_reserved_internal_previous_stacktrace_node
#define G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE                                   \
  G_0_DEBUG_FUNCTION_PARAMETER_PRELUDE0,

#define G_0_DEBUG_ROOT_FUNCTION_BODY_PRELUDE                                   \
  const g_0_debug_stacktrace_node_t                                            \
      *const g_0_reserved_internal_previous_stacktrace_node = NULL;
#define G_0_DEBUG_FUNCTION_BODY_PRELUDE                                        \
  (void)g_0_reserved_internal_previous_stacktrace_node;                        \
  const g_0_debug_stacktrace_node_t                                            \
      g_0_reserved_internal_current_stacktrace_node = {                        \
          .previous = g_0_reserved_internal_previous_stacktrace_node,          \
          .function_name = __func__,                                           \
          .file_name = __FILE__,                                               \
          .line = __LINE__,                                                    \
  };                                                                           \
  (void)g_0_reserved_internal_current_stacktrace_node

#define G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE0                                   \
  &g_0_reserved_internal_current_stacktrace_node
#define G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE                                    \
  G_0_DEBUG_FUNCTION_ARGUMENT_PRELUDE0,

#endif

#endif
