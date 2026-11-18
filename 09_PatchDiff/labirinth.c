#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void replace(int *reachibility, int from, int to, int cur_row, int cur_col, int N) {
    for (int i = 0; i < cur_row * N + cur_col; ++i) {
        if (reachibility[i] == from)
            reachibility[i] = to;
    }
}

int new_group(int *labirinth, int N) {
	int number = 1;
	while (1) {
		int is_member = 0;
		for (int i = 0; i < N; ++i) {
			if (labirinth[i] == number) {
				is_member = 1;
				++number;
				break;
			}
		}
		if (!is_member)
			return number;
	}
}

int main() {
	srand(time(NULL));
	int N = 6;
	int *labirinth = (int *) malloc(sizeof(int) * 2 * N);
	int *reachibility = (int *) malloc(sizeof(int) * N * N);
	short *walls = (short *) malloc(sizeof(int) * N);
    char *printing = (char *) malloc(sizeof(char) * (2 * N + 1) * (2 * N + 1));
	for (int i = 0; i < N; ++i) {
		labirinth[i] = 0;
	}
	
	// First row-wall
	printing[0] = '#';
	for (int i = 0; i < N; ++i) {
        printing[2 * i + 1] = '#';
        printing[2 * (i + 1)] = '#';
    }
	
	for (int iter = 0; iter < N; ++iter) {
		// Fill in gaps(0)
		for (int i = 0; i < N; ++i) {
			if (labirinth[i] == 0) 
				labirinth[i] = iter * N + i + 1;
		}
		
		// Merge elements in the row
        int cur_pos = (2 * iter + 1) * (2 * N + 1);
		printing[cur_pos] = '#';
		for (int i = 0; i < N - 1; ++i) {
			printing[cur_pos + (2 * i) + 1] = '.';
			if (labirinth[i] == labirinth[i+1]) {
				printing[cur_pos + 2 * (i + 1)] = '#';
				labirinth[i] = new_group(labirinth, N);
				continue;
			}
			if (rand() % 2) {
				printing[cur_pos + 2 * (i + 1)] = '#';
			}
			else {
				printing[cur_pos + 2 * (i + 1)] = '.';
				labirinth[i+1] = labirinth[i];
			}
		}
        printing[cur_pos + 2 * N - 1] = '.';
        printing[cur_pos + 2 * N] = '#';
		
        for (int i = 0; i < N; ++i) {
            reachibility[iter * N + i] = labirinth[i];
        }

        if (iter > 0) {
            for (int i = 0; i < N; ++i) {
                if (!(walls[i]) && reachibility[(iter - 1) * N + i] != reachibility[iter * N + i])
                    replace(reachibility, reachibility[(iter - 1) * N + i], reachibility[iter * N + i], iter, i, N);
            }
        }
		
		// Fill next row
		int begin = 0, cnt = 0, value = 0;
		for (int i = 0; i < N; ++i) {
			if (value == 0) {
				value = labirinth[i];
			}
			else if (value != labirinth[i]) {
				if (cnt == 0) {
					int j = begin + rand() % (i - begin);
					labirinth[N + j] = labirinth[j];
				}
				cnt = 0;
				begin = i;
				value = labirinth[i];
			}
			if (rand() % 2) {
				labirinth[N + i] = labirinth[i];
				++cnt;
			}
			else 
				labirinth[N + i] = 0;
		}
		if (cnt == 0) {
			int j = begin + rand() % (N - begin);
			labirinth[N + j] = labirinth[j];
		}

		// Wall between
		if (iter != N - 1) {
            cur_pos = 2 * (iter + 1) * (2 * N + 1);
			printing[cur_pos] = '#';
			for (int i = 0; i < N; ++i) {
				if (labirinth[i] == labirinth[N + i]) {
					printing[cur_pos + 2 * i + 1] = '.';
					walls[i] = 0;
				}
				else {
					printing[cur_pos + 2 * i + 1] = '#';
					walls[i] = 1;
				}
				printing[cur_pos + 2 * (i + 1)] = '#';
			}
		}
		else {
			printing[2 * N * (2 * N + 1)] = '#';
			for (int i = 0; i < N; ++i) {
				printing[2 * N * (2 * N + 1) + 2 * i + 1] = '#';
                printing[2 * N * (2 * N + 1) + 2 * (i + 1)] = '#';
            }
		}
		
		// Switch to next row
		for (int i = 0; i < N; ++i) {
			labirinth[i] = labirinth[N + i];
		}
	}

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (reachibility[i * N + j] != reachibility[(i + 1) * N + j]) {
                printing[(2 * N + 1) * 2 * (i + 1) + 2 * j + 1] = '.';
                replace(reachibility, reachibility[(i + 1) * N + j], reachibility[i * N + j], N, 0, N);
            }
            if (reachibility[i * N + j] != reachibility[i * N + j + 1]) {
                printing[(2 * N + 1) * (2 * i + 1) + 2 * (j + 1)] = '.';
                replace(reachibility, reachibility[i * N + j + 1], reachibility[i * N + j], N, 0, N);
            }
        }
        if (reachibility[i * N + N - 1] != reachibility[(i + 1) * N +  N - 1]) {
            printing[(2 * N + 1) * 2 * (i + 1) + 2 * (N - 1) + 1] = '.';
            replace(reachibility, reachibility[(i + 1) * N +  N - 1], reachibility[i * N + N - 1], N, 0, N);
        }
    }

    for (int i = 0; i < 2 * N + 1; ++i) {
        for (int j = 0; j < 2 * N + 1; ++j) {
            printf("%c", printing[i * (2 * N + 1) + j]);
        }
        printf("\n");
    }

	free(labirinth);
	free(reachibility);
	free(walls);
    free(printing);
}
