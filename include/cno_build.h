#ifndef CNO_BUILD_H
#define CNO_BUILD_H

#define CNO_BUILD_NAME "DreamPuff"
#define CNO_BUILD_DATE __DATE__
#define CNO_BUILD_TIME __TIME__
#define CNO_BUILD_VERSION_MAJOR 1
#define CNO_BUILD_VERSION_MINOR 0

#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 199901L
#define CNO_IS_C99 1
#else
#define CNO_IS_C99 0
#error "Not C99"
#endif //__STDC_VERSION__ >= 199901L
#endif //__STDC_VERSION__

#ifdef __clang__
#define CNO_COMPILER "clang"
#define CNO_COMPILER_VERSION __clang_version__
#elif __GNUC__
#define CNO_COMPILER "gcc"
#endif

#define CNO_BYTE_SIZE __CHAR_BIT__
#define CNO_ENDIAN __BYTE_ORDER__

#if __x86_64__ || __amd64__
#define CNO_ARCHITECTURE "x86_64"
#define CNO_CPU_BIT_TYPE 64
#elif __i386__
#define CNO_ARCHITECTURE "i386"
#define CNO_CPU_BIT_TYPE 32
#elif __powerpc__
#define CNO_ARCHITECTURE "PowerPC"
#elif __mips__
#define CNO_ARCHITECTURE "Mips"
#elif __m68k__
#define CNO_ARCHITECTURE "Motorola68k"
#elif __arm__
#define CNO_ARCHITECTURE "ARM"
#define CNO_CPU_BIT_TYPE 32
#endif

#define CNO_BUILD_FOR_BINARY 1
#define CNO_BUILD_FOR_LIBRARY 0

#ifdef __unix__
#define CNO_IS_UNIX __unix__
#endif //__unix__
#ifdef __POSIX_VERSION
#define CNO_IS_POSIX __POSIX_VERSION
#endif //__POSIX_VERSION
#define CNO_C_VERSION __STDC_VERSION__
#ifdef BSD
#define CNO_IS_BSD BSD
#endif //BSD
#ifdef __GNU__
#define CNO_IS_GNU __GNU__
#endif //__GNU__

//OS
#ifdef __APPLE__
#define CNO_OS_NAME "MacOSX"
#define CNO_OS 2
#elif __gnu_linux__
#define CNO_OS_NAME "Linux"
#define CNO_OS 3
#elif __CYGWIN__ || __WIN32
#define CNO_OS_NAME "Windows"
#define CNO_OS 1
#else
#define CNO_OS_NAME "Unknown"
#define CNO_OS 4
#endif

//Static Dependencies
#define CNO_HAVE_STDIO 1
#define CNO_HAVE_STDLIB 1
#define CNO_HAVE_STRING 1
#define CNO_HAVE_MATH 1
#define CNO_HAVE_TIME 1
#define CNO_HAVE_STDARG 1
#define CNO_HAVE_UNISTD 1
#define CNO_HAVE_ERRNO 1
#define CNO_HAVE_GETOPT 1
#define CNO_HAVE_INIH 1
#define CNO_HAVE_WHEREAMI 1
#define CNO_HAVE_STRETCHYBUFFER 1
#define CNO_HAVE_TINYDIR 1
#define CNO_HAVE_TINYFILEDIALOGS 1
#define CNO_HAVE_PARSON 1
#define CNO_HAVE_SDL2 1

#if CNO_HAVE_STDIO
#define CNO_ALLOW_PRINTF 1
#endif //CNO_HAVE_STDIO

#if CNO_HAVE_STDLIB
#define CNO_ALLOW_EXIT 1
#endif //CNO_HAVE_STDLIB

#if CNO_HAVE_SDL2
#include <SDL2/SDL_version.h>
#endif //CNO_HAVE_SDL2

#define CNO_ALLOW_WINDOW 1
#define CNO_ALLOW_AUDIO 1
#define CNO_ALLOW_THREADS 1
#define CNO_ALLOW_OBJECTS 1

#define DESKTOP_BUILD 1
#define MOBILE_BUILD 0

#if DESKTOP_BUILD && !MOBILE_BUILD
#define CNO_DEVICE_TYPE 1
#elif MOBILE_BUILD && !DESKTOP_BUILD
#define CNO_DEVICE_TYPE 2
#endif //DESKTOP_BUILD && MOBILE_BUILD

typedef unsigned char cno_u8_type;
typedef signed char cno_s8_type;
typedef unsigned short cno_u16_type;
typedef signed short cno_s16_type;
typedef unsigned long cno_u32_type;
typedef signed long cno_s32_type;
typedef unsigned long long cno_u64_type;
typedef signed long long cno_s64_type;
typedef float cno_f32_type;
typedef double cno_f64_type;
typedef unsigned char* cno_cstring_type;

#ifndef CNO_noop
#define CNO_noop ((void)0)
#endif //CNO_noop

//CNO_Functions
#ifndef CNO_printf
#if CNO_HAVE_STDIO && CNO_ALLOW_PRINTF
#define CNO_printf(...) printf(__VA_ARGS__);
#else
#define CNO_printf(...) CNO_noop
#endif //CNO_HAVE_STDIO && CNO_ALLOW_PRINTF
#endif //CNO_printf
#ifndef CNO_sprintf
#if CNO_HAVE_STDIO
#define CNO_sprintf(...) sprintf(__VA_ARGS__);
#else
#define CNO_sprintf(...) CNO_noop
#endif //CNO_HAVE_STDIO
#endif //CNO_sprintf
#ifndef cno_file_type
#define cno_file_type FILE* //cno_file_type is a macro not a typedef
#endif //cno_file_type
#ifndef CNO_fopen
#if CNO_HAVE_STDIO
#define CNO_fopen(...) fopen(__VA_ARGS__)
#else
#define CNO_fopen(...) CNO_Noop
#endif //CNO_HAVE_STDIO
#endif //CNO_fopen
#ifndef CNO_fclose
#if CNO_HAVE_STDIO
#define CNO_fclose(...) fclose(__VA_ARGS__)
#else
#define CNO_fclose(...) CNO_noop
#endif //CNO_HAVE_STDIO
#endif //CNO_fclose
#ifndef CNO_fputs
#if CNO_HAVE_STDIO
#define CNO_fputs(...) fputs(__VA_ARGS__)
#else
#define CNO_fputs(...) CNO_noop
#endif //CNO_HAVE_STDIO
#endif //CNO_fputs

#ifndef CNO_exit
#if CNO_HAVE_STDLIB && CNO_ALLOW_EXIT
#define CNO_exit(...) exit(__VA_ARGS__)
#else
#define CNO_exit CNO_noop
#endif //CNO_HAVE_STDLIB && CNO_ALLOW_EXIT
#endif //CNO_exit
#ifndef CNO_atoi
#if CNO_HAVE_STDLIB
#define CNO_atoi(...) atoi(__VA_ARGS__)
#else
#define CNO_atoi(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_atoi
#ifndef CNO_getenv
#if CNO_HAVE_STDLIB
#define CNO_getenv(...) getenv(__VA_ARGS__)
#else
#define CNO_getenv(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_getenv
#ifndef CNO_malloc
#if CNO_HAVE_STDLIB
#define CNO_malloc(...) malloc(__VA_ARGS__)
#else
#define CNO_malloc(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_malloc
#ifndef CNO_calloc
#if CNO_HAVE_STDLIB
#define CNO_calloc(...) calloc(__VA_ARGS__)
#else
#define CNO_calloc(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_calloc
#ifndef CNO_realloc
#if CNO_HAVE_STDLIB
#define CNO_realloc(...) realloc(__VA_ARGS__)
#else
#define CNO_realloc(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_realloc
#ifndef CNO_free
#if CNO_HAVE_STDLIB
#define CNO_free(...) free(__VA_ARGS__)
#else
#define CNO_free(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_free

#ifndef CNO_strcpy
#if CNO_HAVE_STRING
#define CNO_strcpy(...) strcpy(__VA_ARGS__)
#else
#define CNO_strcpy(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strcpy
#ifndef CNO_strcat
#if CNO_HAVE_STRING
#define CNO_strcat(...) strcat(__VA_ARGS__)
#else
#define CNO_strcat(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strcat
#ifndef CNO_strlen
#if CNO_HAVE_STRING
#define CNO_strlen(...) strlen(__VA_ARGS__)
#else
#define CNO_strlen(...) CNO_noop
#endif //CNO_HAVE_STRING
#ifndef CNO_strncat
#if CNO_HAVE_STRING
#define CNO_strncat(...) strncat(__VA_ARGS__)
#else
#define CNO_strncat(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strncat
#endif //CNO_strlen
#ifndef CNO_strcmp
#if CNO_HAVE_STRING
#define CNO_strcmp(...) strcmp(__VA_ARGS__)
#else
#define CNO_strcmp(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strcmp

#ifndef CNO_abs
#if CNO_HAVE_MATH
#define CNO_abs(...) abs(__VA_ARGS__)
#else
#define CNO_abs(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_abs
#ifndef CNO_pow
#if CNO_HAVE_MATH
#define CNO_pow(...) pow(__VA_ARGS__)
#else
#define CNO_pow(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_pow
#ifndef CNO_sqrt
#if CNO_HAVE_MATH
#define CNO_sqrt(...) sqrt(__VA_ARGS__)
#else
#define CNO_sqrt(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_sqrt
#ifndef CNO_sin
#if CNO_HAVE_MATH
#define CNO_sin(...) sin(__VA_ARGS__)
#else
#define CNO_sin(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_sin
#ifndef CNO_cos
#if CNO_HAVE_MATH
#define CNO_cos(...) cos(__VA_ARGS__)
#else
#define CNO_cos(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_cos
#ifndef CNO_tan
#if CNO_HAVE_MATH
#define CNO_tan(...) tan(__VA_ARGS__)
#else
#define CNO_tan(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_tan
#ifndef CNO_asin
#if CNO_HAVE_MATH
#define CNO_asin(...) asin(__VA_ARGS__)
#else
#define CNO_asin(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_asin
#ifndef CNO_acos
#if CNO_HAVE_MATH
#define CNO_acos(...) acos(__VA_ARGS__)
#else
#define CNO_acos(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_acos
#ifndef CNO_atan
#if CNO_HAVE_MATH
#define CNO_atan(...) atan(__VA_ARGS__)
#else
#define CNO_atan(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_atan
#ifndef CNO_ceil
#if CNO_HAVE_MATH
#define CNO_ceil(...) ceil(__VA_ARGS__)
#else
#define CNO_ceil(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_ceil
#ifndef CNO_floor
#if CNO_HAVE_MATH
#define CNO_floor(...) floor(__VA_ARGS__)
#else
#define CNO_floor(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_floor
#ifndef CNO_round
#if CNO_HAVE_MATH
#define CNO_round(...) round(__VA_ARGS__)
#else
#define CNO_round(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_round

#ifndef CNO_time
#if CNO_HAVE_TIME
#define CNO_time(...) time(__VA_ARGS__)
#else
#define CNO_time(...) CNO_noop
#endif //CNO_HAVE_TIME
#endif //CNO_time
#ifndef CNO_gmtime
#if CNO_HAVE_TIME
#define CNO_gmtime(...) gmtime(__VA_ARGS__)
#else
#define CNO_gmtime(...) CNO_noop
#endif //CNO_HAVE_TIME
#endif //CNO_gmtime
#ifndef CNO_strftime
#if CNO_HAVE_TIME
#define CNO_strftime(...) strftime(__VA_ARGS__)
#else
#define CNO_strftime(...) CNO_noop
#endif //CNO_HAVE_TIME
#endif //CNO_strftime

#ifndef CNO_va_start
#if CNO_HAVE_STDARG
#define CNO_va_start(...) va_start(__VA_ARGS__)
#else
#define CNO_va_start(...) CNO_noop
#endif //CNO_HAVE_STDARG
#endif //CNO_va_start
#ifndef CNO_va_arg
#if CNO_HAVE_STDARG
#define CNO_va_arg(...) va_arg(__VA_ARGS__)
#else
#define CNO_va_arg(...) CNO_noop
#endif //CNO_HAVE_STDARG
#endif //CNO_va_arg
#ifndef CNO_va_end
#if CNO_HAVE_STDARG
#define CNO_va_end(...) va_end(__VA_ARGS__)
#else
#define CNO_va_end(...) CNO_noop
#endif //CNO_HAVE_STDARG
#endif //CNO_va_end

//Shortcuts

/*#if CNO_ALLOW_PRINTF
#define cno_printf(...) CNO_printf(__VA_ARGS__)
#else
#define cno_printf(...) CNO_noop
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
#define cno_exit(...) CNO_exit(__VA_ARGS__)
#else
#define cno_exit(...) CNO_noop
#endif //CNO_ALLOW_EXIT*/

#endif //CNO_BUILD_H
