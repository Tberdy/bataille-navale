/* 
 * File:   XPlatform.c
 * Author: Tberdy
 *
 * Created on 30 septembre 2016, 00:09
 */

#include "XPlatform.h"

#ifdef WINDOWS

char xplt_getch() {
    return getch();
}

void xplt_clrscr() {
    system("cls");
}

#else

char xplt_getch() {
    char c = 0;
    system("/bin/stty raw");
    while (c == 0) {
        c = getchar();
    }
    system("/bin/stty cooked");
    return c;
}

void xplt_clrscr() {
    system("clear");
}

#endif