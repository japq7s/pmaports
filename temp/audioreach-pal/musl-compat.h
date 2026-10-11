/* musl compatibility for AudioReach sources written against glibc/bionic */
#ifndef MUSL_COMPAT_H
#define MUSL_COMPAT_H
/* musl's struct stat has a member named __unused: include it before the macro */
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#ifndef __unused
#define __unused __attribute__((__unused__))
#endif
#ifndef TEMP_FAILURE_RETRY
#define TEMP_FAILURE_RETRY(e) ({ long _r; do _r = (long)(e); while (_r == -1L && errno == EINTR); _r; })
#endif
#endif
