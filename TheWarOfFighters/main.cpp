//
//  main.cpp
//  TheWarOfFighters
//
//  Created by Chenxi Yuan on 2016/4/5.
//  Copyright © 2016年 Chenxi Yuan. All rights reserved.
//

#include <iostream>
#include <ncurses.h>
void main_game(char fighter_char, int row, int col, int ch);
int main(int argc, const char * argv[]) {    int row = 10;
    int col = 10;

    char bullet_char = '-';
    char enemy_char='*';
    // Initialize ncurses status
    clear();
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    printw ("Welcome to the War of Figher game!\n Press any key to start.\npress q or Q to quit.\n");
    int ch = getch();
    clear();
    main_game(figher_char, row, col, ch);
    endwin();
    return 0;
}



void main_game(char fighter_char, int row, int col, int ch) {
    if(ch =='q'|| ch=='Q') return;
    mvaddch(row, col, fighter_char);
    refresh();
    // todo: sample ncurses code
    while(true) {
        ch = getch();
        switch (ch) {
            case KEY_LEFT:
                mvaddch(row, col, ' ');
                col = col-1;
                mvaddch(row, col, fighter_char);
                break;
                
            case KEY_RIGHT:
                mvaddch(row, col, ' ');
                col = col+1;
                mvaddch(row, col, fighter_char);
                break;
                
            case KEY_UP:
                mvaddch(row, col, ' ');
                row = row+1;
                mvaddch(row, col, fighter_char);
                break;
            case KEY_DOWN:
                mvaddch(row, col, ' ');
                row = row-1;
                mvaddch(row, col, fighter_char);
                break;
                break;
            default:
                break;
        }
    }
    
}
