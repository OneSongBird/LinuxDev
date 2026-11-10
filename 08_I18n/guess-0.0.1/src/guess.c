#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#define _(STRING) gettext(STRING)

int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	bindtextdomain ("guess", "/usr/share/locale");
	textdomain ("guess");
	printf(_("Guess the number from 1 to 100\n"));
	int begin = 1, end = 100, is_eof = 0;
	while (begin != end) {
		int guess = begin + (end - begin + 1) / 2;
		printf(_("\nIs this number less than %d? Write YES or NO\n"), guess);
		char str[4];
		scanf("%s", str);
		if (strcmp(str, "") == 0) {
			is_eof = 1;
			break;
		}
		if (strcmp(str, "YES") == 0) 
			end = guess - 1;
		else if (strcmp(str, "NO") == 0) 
			begin = guess;
		else
			printf(_("Wrong answer!\n"));
		str[0] = '\0';
	}
	if (is_eof) {
		printf(_("Empty line!\n"));
		return 2;
	}
	printf(_("You guessed %d!\n"), begin);
	return 0;
}
