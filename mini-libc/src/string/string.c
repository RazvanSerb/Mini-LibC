// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdlib.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *ptr_dest = destination;
	while (*source) {
		*ptr_dest = *source;
		source++;
		ptr_dest++;
	}
	*ptr_dest = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *ptr_dest = destination;
	size_t i = 0;
	while (i < len) {
		*ptr_dest = *source;
		source++;
		ptr_dest++;
		i++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *ptr_dest = destination;
	while (*ptr_dest)
		ptr_dest++;
	while (*source) {
		*ptr_dest = *source;
		source++;
		ptr_dest++;
	}
	*ptr_dest = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *ptr_dest = destination;
	size_t i = 0;
	while (*ptr_dest)
		ptr_dest++;
	while (i < len) {
		*ptr_dest = *source;
		source++;
		ptr_dest++;
		i++;
	}
	*ptr_dest = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while ((*str1) && (*str2)) {
		if ((*str1) < (*str2))
			return -1;
		if ((*str1) > (*str2))
			return 1;
		str1++;
		str2++;
	}
	if (!(*str1) && (*str2))
		return -1;
	if ((*str1) && !(*str2))
		return 1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i = 0;
	while (i < len) {
		if ((*str1) < (*str2))
			return -1;
		if ((*str1) > (*str2))
			return 1;
		str1++;
		str2++;
		i++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str) {
		if ((*str) == c)
			return (char *) str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *position = NULL;
	while (*str) {
		if ((*str) == c)
			position = str;
		str++;
	}
	return (char *) position;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	const char *ptr_haystack = NULL;
	const char *ptr_needle = NULL;
	while (*haystack) {
		ptr_haystack = haystack;
		ptr_needle = needle;
		while ((*ptr_needle) == (*ptr_haystack)) {
			ptr_needle++;
			ptr_haystack++;
			if (!(*ptr_needle))
				break;
		}
		if (!(*ptr_needle))
			return (char *) haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *position = NULL;
	const char *ptr_haystack = NULL;
	const char *ptr_needle = NULL;
	while (*haystack) {
		ptr_haystack = haystack;
		ptr_needle = needle;
		while ((*ptr_needle) == (*ptr_haystack)) {
			ptr_needle++;
			ptr_haystack++;
			if (!(*ptr_needle))
				break;
		}
		if (!(*ptr_needle))
			position = haystack;
		haystack++;
	}
	return (char *) position;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *ptr_dest = (char *) destination;
	const char *ptr_src = (const char *) source;
	size_t i = 0;
	while (i < num) {
		*ptr_dest = *ptr_src;
		ptr_src++;
		ptr_dest++;
		i++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *ptr_dest = (char *) destination;
	const char *ptr_src = (const char *) source;
	char *temp = (char *) malloc(num * sizeof(char));
	size_t i = 0;
	while (i < num) {
		temp[i] = *ptr_src;
		ptr_src++;
		i++;
	}
	i = 0;
	while (i < num) {
		*ptr_dest = temp[i];
		ptr_dest++;
		i++;
	}
	free(temp);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *str1 = (const char *) ptr1;
	const char *str2 = (const char *) ptr2;
	size_t i = 0;
	while (i < num) {
		if ((*str1) < (*str2))
			return -1;
		if ((*str1) > (*str2))
			return 1;
		str1++;
		str2++;
		i++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *ptr_src = (char *) source;
	size_t i = 0;
	while (i < num) {
		*ptr_src = value;
		ptr_src++;
		i++;
	}
	return source;
}
