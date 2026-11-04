#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rhash.h"
#include "config.h"

#ifdef READLINE
	#include <readline/readline.h>
#endif

int my_read(char **st) {
	#ifdef READLINE
		*st = readline("> ");
		if (*st == NULL)
			return -1;
		return 0;
	#else
		printf("> ");
		*st = NULL;
		size_t cnt = 0;
		return getline(st, &cnt, stdin);
	#endif
}

void str_toupper(char *s) {
    for (; *s; ++s)
        *s = (char)toupper((unsigned char)*s);
}

int main(int argc, char* argv[]) {
	char *line = NULL;
	while (my_read(&line) != -1) {
		if (line[0] == '\n' || line[0] == '\0') {
			free(line);
			continue;
		}
		char *hash = strtok(line, " ");
		char *token = strtok(NULL, " ");
		if (token == NULL) {
			fprintf(stderr, "Не хватает второго аргумента\n");
			free(line);
			continue;
		}
		int isHex = 0;
		if (hash[0] >= 'A' && hash[0] <= 'Z') isHex = 1;
		str_toupper(hash);
		unsigned algorithm;
		if (strcmp(hash, "SHA1") == 0) algorithm = RHASH_SHA1;
		else if (strcmp(hash, "MD5") == 0) algorithm = RHASH_MD5;
		else if (strcmp(hash, "TTH") == 0) algorithm = RHASH_TTH;
		else {
			fprintf(stderr, "Такого алгоритма не существует\n");
		}
		unsigned char digest[64];
		rhash_library_init();
		if (token[0] == '"') {
			++token;
			rhash_msg(algorithm, token, strlen(token), digest);
		}
		else {
			rhash_file(algorithm, token, digest);
		}
		char output[130];
		if (isHex) {
			rhash_print_bytes(output, digest, rhash_get_digest_size(algorithm), (RHPR_HEX | RHPR_UPPERCASE));
		}
		else {
			rhash_print_bytes(output, digest, rhash_get_digest_size(algorithm), (RHPR_BASE64 | RHPR_UPPERCASE));
		}
		printf("%s\n", output);
		free(line);
	}
	return 0;
}
