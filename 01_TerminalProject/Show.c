#include <stdio.h>
#include <curses.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define DX 3
#define DY 3

int main(int argc, char *argv[]) {
    WINDOW *frame, *win;
    FILE *file = fopen(argv[1], "r");
    int c = 0;

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    printw("Окно:");
    refresh();

    frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
    box(frame, 0, 0);
    mvwaddstr(frame, 0, (int)((COLS - 2*DX - 5) / 2), argv[1]);
    wrefresh(frame);

    win = newwin(LINES - 2*DY - 2, COLS - 2*DX-2, DY+1, DX+1);
    keypad(win, TRUE);
    scrollok (win, TRUE);
    char **str = malloc(1024 * sizeof(char *));
    str[0] = malloc(300 * sizeof(char));
    int size_file = 0;
    int line = 1;
    while (fgets(str[size_file], 1024, file)) {
        if (strlen(str[size_file]) > COLS - 2*DX-8) {
                    str[size_file][COLS - 2*DX-8] = '\0';
                    str[size_file][COLS - 2*DX-9] = '\n';
                }
        if (size_file < LINES - 2*DY - 3) {
            wprintw(win, "%4d: %s", line, str[size_file]);
            ++line;
        }
        ++size_file;
        str[size_file] = malloc(300 * sizeof(char));
    }
    
    
    while((c = wgetch(win)) != 27) {
        if (c == KEY_DOWN || c == 32) {
            if (line <= size_file) {
                wprintw(win, "%4d: %s", line, str[line-1]);
                ++line;
            }
        }
        else if (c == KEY_UP) {
            if (line > LINES - 2*DY - 2) {
                for (int i = line - (LINES - 2*DY - 2); i < line-1; ++ i) {
                    wprintw(win, "%4d: %s", i, str[i-1]);
                }
                --line;
            }
        }
    }
    delwin(win);
    delwin(frame);
    endwin();
    for (int i = 0; i < size_file; ++i) free(str[i]);
    free(str);
    fclose(file);
    return 0;
}