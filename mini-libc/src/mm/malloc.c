// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ptr) {
		mem_list_add(ptr, size);
		return ptr;
	} else {
		return NULL;
	}
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ptr) {
		memset(ptr, 0, nmemb * size);
		mem_list_add(ptr, nmemb * size);
		return ptr;
	} else {
		return NULL;
	}
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (!ptr) {
		return;
	} else {
		struct mem_list *elem = mem_list_find(ptr);
		munmap(ptr, elem->len);
		mem_list_del(ptr);
		return;
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *new_ptr = NULL;
	if (ptr) {
		new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	} else {
		struct mem_list *elem = mem_list_find(ptr);
		new_ptr = mremap(ptr, elem->len, size, MREMAP_MAYMOVE);
	}
	if (new_ptr) {
		mem_list_del(ptr);
		mem_list_add(ptr, size);
		return new_ptr;
	} else {
		return NULL;
	}
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *new_ptr = NULL;
	if (ptr) {
		new_ptr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	} else {
		struct mem_list *elem = mem_list_find(ptr);
		new_ptr = mremap(ptr, elem->len, nmemb * size, MREMAP_MAYMOVE);
	}
	if (new_ptr) {
		mem_list_del(ptr);
		mem_list_add(ptr, nmemb * size);
		return new_ptr;
	} else {
		return NULL;
	}
}
