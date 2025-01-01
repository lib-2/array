// NO INCLUDE GUARD INTENTIONALLY

/*

usage: set G_THIS for library currently building, like below

#define G_THIS
#include "my_library_currently_building.h"
#undef G_THIS
#include "other_libraries.h"
// ... other includes
#define G_THIS
#include "-0_common.h"
// implement your functions

*/

#ifndef G_SHARED
#error G_SHARED must be specified
#elif G_SHARED == 0
#elif G_SHARED == 1
#else
#error G_SHARED must be specified as 0 or 1
#endif

#undef G_EXPORT

#ifdef G_THIS

#if _WIN32 && G_SHARED == 1
#define G_EXPORT __declspec(dllexport)
#else
#define G_EXPORT
#endif

#else

#if _WIN32 && G_SHARED == 1
#define G_EXPORT __declspec(dllimport)
#else
#define G_EXPORT
#endif

#endif
