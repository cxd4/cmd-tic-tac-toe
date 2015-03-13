/************************************************************/
/*                                                          */ 
/* Created by Ryan Collins 2012-2013, use at your own risk. */  
/*                                                          */  
/************************************************************/

#include <iostream>

using namespace std;

#define GRID_SIZE       3

enum {
    TOP,
    MID,
    LOW
};

enum {
    LFT,
    CNT,
    RGT
};

enum {
    BLANK,
    SET_X,
    SET_O
};

#define PLAYING     0
#define WIN_X       (SET_X)
#define WIN_O       (SET_O)
#define DRAW        3

extern unsigned short grid[GRID_SIZE][GRID_SIZE];

// This function draws the board and any X's or O's
void draw_board()
{
	if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == BLANK)
	{
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == BLANK)
	{
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == SET_X)
	{
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == BLANK)
	{
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == SET_X)
	{
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == SET_X)
	{
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == SET_X)
	{
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == BLANK)
	{
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == BLANK)
	{
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == SET_O)
	{
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == BLANK)
	{
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == SET_O)
	{
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == SET_O)
	{
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == SET_O)
	{
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == SET_O)
	{
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == BLANK)
	{
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == SET_O)
	{
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == SET_X)
	{
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == SET_O)
	{
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == BLANK && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == SET_X)
	{
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == SET_O)
	{
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == SET_O)
	{
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == BLANK && grid[TOP][RGT] == SET_X)
	{
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == SET_X)
	{
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == BLANK)
	{
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
	}
	else if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == SET_X)
	{
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "  O   O  |    X    |    X    " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
	}
	else
	{
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
	}

	if (grid[MID][LFT] == SET_X && grid[MID][CNT] == BLANK && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == SET_X && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == BLANK && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == SET_X && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == SET_X && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == BLANK && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == SET_X && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == BLANK && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == SET_O && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == BLANK && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == SET_O && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == SET_O && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == BLANK && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == SET_O && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == SET_O && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == SET_O && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == SET_X && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == SET_O && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == SET_X && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == BLANK && grid[MID][CNT] == SET_O && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_X && grid[MID][CNT] == BLANK && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == SET_X && grid[MID][RGT] == SET_O)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == BLANK && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == SET_O && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == SET_X && grid[MID][RGT] == BLANK)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else if (grid[MID][LFT] == SET_O && grid[MID][CNT] == SET_X && grid[MID][RGT] == SET_X)
	{
		cout << "---------+---------+---------" << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "  O   O  |    X    |    X    " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "---------+---------+---------" << endl;
	}
	else
	{
		cout << "---------+---------+---------" << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "---------+---------+---------" << endl;
	}

	if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == BLANK)
	{
		cout << "  X   X  |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "    X    |         |         " << endl;
		cout << "   X X   |         |         " << endl;
		cout << "  X   X  |         |         " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == BLANK)
	{
		cout << "         |  X   X  |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |    X    |         " << endl;
		cout << "         |   X X   |         " << endl;
		cout << "         |  X   X  |         " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == SET_X)
	{
		cout << "         |         |  X   X  " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |    X    " << endl;
		cout << "         |         |   X X   " << endl;
		cout << "         |         |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == BLANK)
	{
		cout << "  X   X  |  X   X  |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "    X    |    X    |         " << endl;
		cout << "   X X   |   X X   |         " << endl;
		cout << "  X   X  |  X   X  |         " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == SET_X)
	{
		cout << "         |  X   X  |  X   X  " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |    X    |    X    " << endl;
		cout << "         |   X X   |   X X   " << endl;
		cout << "         |  X   X  |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == SET_X)
	{
		cout << "  X   X  |         |  X   X  " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "    X    |         |    X    " << endl;
		cout << "   X X   |         |   X X   " << endl;
		cout << "  X   X  |         |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == SET_X)
	{
		cout << "  X   X  |  X   X  |  X   X  " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "    X    |    X    |    X    " << endl;
		cout << "   X X   |   X X   |   X X   " << endl;
		cout << "  X   X  |  X   X  |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == BLANK)
	{
		cout << "   OOO   |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "  O   O  |         |         " << endl;
		cout << "   OOO   |         |         " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == BLANK)
	{
		cout << "         |   OOO   |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |  O   O  |         " << endl;
		cout << "         |   OOO   |         " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == SET_O)
	{
		cout << "         |         |   OOO   " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |  O   O  " << endl;
		cout << "         |         |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == BLANK)
	{
		cout << "   OOO   |   OOO   |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "  O   O  |  O   O  |         " << endl;
		cout << "   OOO   |   OOO   |         " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == SET_O)
	{
		cout << "         |   OOO   |   OOO   " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |  O   O  |  O   O  " << endl;
		cout << "         |   OOO   |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == SET_O)
	{
		cout << "   OOO   |         |   OOO   " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "  O   O  |         |  O   O  " << endl;
		cout << "   OOO   |         |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == SET_O)
	{
		cout << "   OOO   |   OOO   |   OOO   " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "  O   O  |  O   O  |  O   O  " << endl;
		cout << "   OOO   |   OOO   |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == SET_O)
	{
		cout << "  X   X  |   OOO   |   OOO   " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "    X    |  O   O  |  O   O  " << endl;
		cout << "   X X   |  O   O  |  O   O  " << endl;
		cout << "  X   X  |   OOO   |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == BLANK)
	{
		cout << "  X   X  |   OOO   |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "    X    |  O   O  |         " << endl;
		cout << "   X X   |  O   O  |         " << endl;
		cout << "  X   X  |   OOO   |         " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == SET_O)
	{
		cout << "  X   X  |  X   X  |   OOO   " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "    X    |    X    |  O   O  " << endl;
		cout << "   X X   |   X X   |  O   O  " << endl;
		cout << "  X   X  |  X   X  |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == SET_X)
	{
		cout << "  X   X  |   OOO   |  X   X  " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "    X    |  O   O  |    X    " << endl;
		cout << "   X X   |  O   O  |   X X   " << endl;
		cout << "  X   X  |   OOO   |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == SET_O)
	{
		cout << "         |  X   X  |   OOO   " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |    X    |  O   O  " << endl;
		cout << "         |   X X   |  O   O  " << endl;
		cout << "         |  X   X  |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == BLANK && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == SET_X)
	{
		cout << "         |   OOO   |  X   X  " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |  O   O  |    X    " << endl;
		cout << "         |  O   O  |   X X   " << endl;
		cout << "         |   OOO   |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == SET_O)
	{
		cout << "  X   X  |         |   OOO   " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "    X    |         |  O   O  " << endl;
		cout << "   X X   |         |  O   O  " << endl;
		cout << "  X   X  |         |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == SET_O)
	{
		cout << "   OOO   |  X   X  |   OOO   " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "  O   O  |    X    |  O   O  " << endl;
		cout << "  O   O  |   X X   |  O   O  " << endl;
		cout << "   OOO   |  X   X  |   OOO   " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == BLANK && grid[LOW][RGT] == SET_X)
	{
		cout << "   OOO   |         |  X   X  " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "  O   O  |         |    X    " << endl;
		cout << "  O   O  |         |   X X   " << endl;
		cout << "   OOO   |         |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == SET_X)
	{
		cout << "   OOO   |   OOO   |  X   X  " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "  O   O  |  O   O  |    X    " << endl;
		cout << "  O   O  |  O   O  |   X X   " << endl;
		cout << "   OOO   |   OOO   |  X   X  " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == BLANK)
	{
		cout << "   OOO   |  X   X  |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "  O   O  |    X    |         " << endl;
		cout << "  O   O  |   X X   |         " << endl;
		cout << "   OOO   |  X   X  |         " << endl;
	}
	else if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == SET_X)
	{
		cout << "   OOO   |  X   X  |  X   X  " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "  O   O  |    X    |    X    " << endl;
		cout << "  O   O  |   X X   |   X X   " << endl;
		cout << "   OOO   |  X   X  |  X   X  " << endl;
	}
	else
	{
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
		cout << "         |         |         " << endl;
	}

	cout << endl;
}
