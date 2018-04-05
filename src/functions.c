#include "functions.h"

void printData(void * data)
{
    printf("%s\n", (char *)data);
}

int compareFunction(const void *first,const void *second)
{
	

	if(*(int *)first > *(int *)second || *(int *)first == *(int *)second)
	{
		return *(int *)first;
	}
	else
	{
		int tempVal = 0;
		tempVal = *(int *)first;
		*(int *)first = *(int *)second;
		*(int *)second = tempVal;
		return *(int *)first;
	}
}

void clearTextLine(int x, int y)
{
    move(x,y);
    clrtoeol();
}

void makeMainMenu(int maxX, int maxY)
{
    for(int i = 0; i <= ((maxX - 1)); i++)
    {
        mvaddch(0,i,'=');
        mvaddch(((maxY/3)*2),i,'=');
        if(i > 1)
        {
            mvaddch(1, i , '=');
            mvaddch((((maxY/3)*2) - 1), i - 1, '=');
        }
    }

    for(int i = 0; i <= ((maxY/3)*2); i++)
    {
        mvaddch(i,0,'|');
        mvaddch(i,(maxX - 1),'|');
        if(i > 1)
        {
            mvaddch(i - 1, 1, '#');
            mvaddch(i - 1, (maxX - 2), '#');
            mvaddch(i - 1, 2,'|');
            mvaddch(i - 1, (maxX - 3),'|');
        }

    }

    mvprintw(1, (maxX / 2) - 12, " <~ Health Records ~> ");
    move(1, ((maxX/3)) - 3);
}

void clearMainMenu(int maxX, int maxY)
{
    for(int i = 4; i <= ((maxY/3)*2); i++)
    {
        for(int k = 3; k <= (maxX - 4 ); k++)
        {
            mvaddch(i - 2, k  , ' ');
        }
    }
}

void makeMainMenuOptions(int maxX, int maxY, int i, char * menuOptions)
{
    mvprintw(((maxY/8) * i), 4, "[");
    move((maxY/8) * i, 4);

    mvprintw(((maxY/8) * i), 6, "]");
    move((maxY/8) * i, 6);

    mvprintw((((maxY/8) * i)), 8, menuOptions);
    move((((maxY/8) * i)), 8);
}


void getPos(int * y, int * x)
{
    * y = getcury(stdscr);
    * x = getcurx(stdscr);

    return;
}
