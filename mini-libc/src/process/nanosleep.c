// SPDX-License-Identifier: BSD-3-Clause

#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const timespec *t1, const timespec *t2)
{
	int ret = syscall(__NR_nanosleep, t1, t2);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
