#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

typedef int (*remove_type)(const char*);

int remove(const char *file_name) {
	if (strstr(file_name, "PROTECT") == NULL) {
		return ((remove_type)(dlsym(RTLD_NEXT, "remove")))(file_name);
	}
	return 0;
}
