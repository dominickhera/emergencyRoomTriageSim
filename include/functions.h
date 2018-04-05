#ifndef _DHERA_FUNCTIONS_
#define _DHERA_FUNCTIONS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "heap.h"

void printData(void * data);
int compareFunction(const void *first,const void *second);
void clearTextLine(int x, int y);
void makeMainMenu(int maxX, int maxY);
void makeMainMenuOptions(int maxX, int maxY, int i, char * menuOptions);
void clearMainMenu(int maxX, int maxY);
void getPos(int *, int *);


#endif
