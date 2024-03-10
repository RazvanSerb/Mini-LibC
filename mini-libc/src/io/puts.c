// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <internal/syscall.h>
#include <errno.h>

int puts(const char* str) {
    while (*str) {
        int ret = syscall(__NR_write, 1, str, 1);
        if (ret < 0) {
		    errno = -ret;
		    return -1;
	    }
        str++;
    }
    int ret = syscall(__NR_write, 1, "\n", 1);
    if (ret < 0) {
		errno = -ret;
		return -1;
	}
    return ret;
}
