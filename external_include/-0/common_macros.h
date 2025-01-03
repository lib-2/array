// NO INCLUDE GUARD INTENTIONALLY

#ifndef G_SHARED
#error G_SHARED must be specified
#elif G_SHARED == 0
#elif G_SHARED == 1
#else
#error G_SHARED must be specified as 0 or 1
#endif

#undef G_API

#ifdef G_EXPORT

#if defined(_WIN32) && G_SHARED == 1
#define G_API __declspec(dllexport)
#else
#define G_API
#endif

#else

#if defined(_WIN32) && G_SHARED == 1
#define G_API __declspec(dllimport)
#else
#define G_API
#endif

#endif
