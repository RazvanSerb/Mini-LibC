/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/io.h>
#include <internal/types.h>

typedef struct timespec {
    unsigned long long int seconds;
    unsigned long long int nanoseconds;
} timespec;

unsigned long long int sleep(unsigned long long int seconds);
int nanosleep(const timespec *t1, const timespec *t2);

#ifdef __cplusplus
}
#endif

#endif
