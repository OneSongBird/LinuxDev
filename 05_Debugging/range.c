#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("    Help:\nПараметры: N     Вывод: Числа от 0 до N-1\nПараметры: M N   Вывод: Числа от M до N-1\nПараметры: M N S Вывод: Числа от M до N-1 с шагом S\n");
    }
    else if (argc == 2) {
        int N = atoi(argv[1]);
        for (int i = 0; i < N; ++i) printf("%d\n", i);
    }
    else {
        int M = atoi(argv[1]);
        int N = atoi(argv[2]);
	int S = 1;
	if (argc >= 4) S = atoi(argv[3]);
        for (int i = M; i < N; i = i + S) {
		printf("%d\n", i);
	}
    }
}