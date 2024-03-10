// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

unsigned long long int sleep(unsigned long long int seconds)
{
	timespec t1; // request_duration
	t1.seconds = seconds;
	t1.nanoseconds = 0;
	timespec t2; // remaining_duration
	t2.seconds = 0;
	t2.nanoseconds = 0;
	int ret = nanosleep(&t1, &t2);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return t2.seconds;
}
