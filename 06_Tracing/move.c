#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Текущее кол-во аргументов - %d. Должно быть аргументов - 2\n", argc - 1);
		return 1;
	}
	FILE *f_in = fopen(argv[1], "r");
	if (f_in == NULL) {
		printf("Входной файл не открылся\n");
		return 2;
	}
	FILE *f_out = fopen(argv[2], "w");
	if (f_out == NULL) {
		printf("Выходной файл не открылся\n");
		return 3;
	}
	char *buffer = (char*) malloc(sizeof(char) * 1000);
	int count_in, count_out;
	do {
		count_in = fread(buffer, sizeof(char), 1000, f_in);
		if (!feof(f_in) && count_in != 1000) {
			printf("Ошибка чтения из файла\n");
			return 4;
		}
		count_out = fwrite(buffer, sizeof(char), count_in, f_out);
		if (count_in != count_out) {
			printf("Ошибка записи в файл\n");
			return 5;
		}
	} while (!feof(f_in));
	if (fclose(f_out)) {
		printf("Выходной файл не закрылся\n");
		return 6;
	}
	if (fclose(f_in)) {
		printf("Входной файл не закрылся\n");
		return 7;
	}
	if (remove(argv[1])) {
		printf("Входной файл не удалился\n");
		return 8;
	}
	free(buffer);
	return 0;
}
