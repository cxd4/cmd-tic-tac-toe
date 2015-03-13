/************************************************************/
/*                                                          */ 
/* Created by Ryan Collins 2012-2013, use at your own risk. */  
/*                                                          */  
/************************************************************/

/*
To do list:
Fix cross platform compatibility (started)
Optimize horrible code
make CPU // No time D;
Try to make UI // Nooooooooooooooooooooooooooooo, it won't work D;
*/

#include <iostream>

#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#endif
#include "board.h"

using namespace std;

unsigned short grid[GRID_COMPLEXITY][GRID_COMPLEXITY];
unsigned short turn = 0, game = 0, x_win = 0, o_win = 0, tie = 0, playing = 1, place = 0, players = 0, error = 0;

// This function is CPU X's logic
void CPU_X()
{
	// Temp use of rand
	SYSTEMTIME time;
	GetLocalTime(&time);
	int ran = time.wMilliseconds;
	srand(ran);
	place = (rand() % GRID_SIZE) + 1;
}

// This function is CPU O's logic
void CPU_O()
{
	// Temp use of rand
	SYSTEMTIME time;
	GetLocalTime(&time);
	int ran = time.wMilliseconds;
	srand(ran);
	place = (rand() % GRID_SIZE) + 1;
}

// This function is used to determine whos turn it is
unsigned short player_turn()
{
	return (turn % NUM_PLAYERS) + 1;
}

// This function resets all of the places and clears the screen
void reset()
{
    int x, y;

    for (y = 0; y < GRID_COMPLEXITY; y++)
        for (x = 0; x < GRID_COMPLEXITY; x++)
            grid[y][x] = BLANK;
    turn = place = error = 0;
    system("cls"); /* <-- gay */
}

// This function checks to see if anyone has won or if there is a tie
unsigned short check_status()
{
    unsigned int test;
    int x, y;

/*
 * horizontal tests
 */
    if (grid[TOP][LFT] == SET_X && grid[TOP][CNT] == SET_X && grid[TOP][RGT] == SET_X)
        return WIN_X;
    if (grid[MID][LFT] == SET_X && grid[MID][CNT] == SET_X && grid[MID][RGT] == SET_X)
        return WIN_X;
    if (grid[LOW][LFT] == SET_X && grid[LOW][CNT] == SET_X && grid[LOW][RGT] == SET_X)
        return WIN_X;

/*
 * vertical tests
 */
    if (grid[TOP][LFT] == SET_X && grid[MID][LFT] == SET_X && grid[LOW][LFT] == SET_X)
        return WIN_X;
    if (grid[TOP][CNT] == SET_X && grid[MID][CNT] == SET_X && grid[LOW][CNT] == SET_X)
        return WIN_X;
    if (grid[TOP][RGT] == SET_X && grid[MID][RGT] == SET_X && grid[LOW][RGT] == SET_X)
        return WIN_X;

/*
 * diagonal tests
 */
    if (grid[TOP][LFT] == SET_X && grid[MID][CNT] == SET_X && grid[LOW][RGT] == SET_X)
        return WIN_X;
    if (grid[TOP][RGT] == SET_X && grid[MID][CNT] == SET_X && grid[LOW][LFT] == SET_X)
        return WIN_X;

/*
 * samefag (repeated for other player) (lrn2usefunctions u nub!)
 */
    if (grid[TOP][LFT] == SET_O && grid[TOP][CNT] == SET_O && grid[TOP][RGT] == SET_O)
        return WIN_O;
    if (grid[MID][LFT] == SET_O && grid[MID][CNT] == SET_O && grid[MID][RGT] == SET_O)
        return WIN_O;
    if (grid[LOW][LFT] == SET_O && grid[LOW][CNT] == SET_O && grid[LOW][RGT] == SET_O)
        return WIN_O;

    if (grid[TOP][LFT] == SET_O && grid[MID][LFT] == SET_O && grid[LOW][LFT] == SET_O)
        return WIN_O;
    if (grid[TOP][CNT] == SET_O && grid[MID][CNT] == SET_O && grid[LOW][CNT] == SET_O)
        return WIN_O;
    if (grid[TOP][RGT] == SET_O && grid[MID][RGT] == SET_O && grid[LOW][RGT] == SET_O)
        return WIN_O;

    if (grid[TOP][LFT] == SET_O && grid[MID][CNT] == SET_O && grid[LOW][RGT] == SET_O)
        return WIN_O;
    if (grid[TOP][RGT] == SET_O && grid[MID][CNT] == SET_O && grid[LOW][LFT] == SET_O)
        return WIN_O;

/*
 * tied game (meaning you both suck)
 */
    test  = 1;
    for (y = 0; y < GRID_COMPLEXITY; y++)
        for (x = 0; x < GRID_COMPLEXITY; x++)
            test &= (grid[y][x] == SET_X) || (grid[y][x] == SET_O);
    if (test != 0 || turn >= GRID_SIZE)
        return DRAW;

/*
 * game still on
 */
	return PLAYING;
}

// This function is used when 2 CPU's play against each other
void CPU2()
{
try_CPU2:
    switch (player_turn())
    {
    case SET_X:
        puts("X(CPU)'s turn");
        CPU_X();
        break;
    case SET_O:
        puts("O(CPU)'s turn");
        CPU_O();
        break;
    default:
        puts("Error, unknown turn");
        error++;
    }

/* to do:  wtf man lrn2switch */
	if (place == TOP_LEFT)
	{
		if (!grid[TOP][LFT])
			grid[TOP][LFT] = player_turn();
		else
		{
			// Don't worry about outputing an error if the CPU is moving as it it random and is bound to do so
			// puts("Error, cannot move there. Please try again\n");
			goto try_CPU2; // Return to begining of function to try again
		}
	}
	else if (place == TOP_CENTER)
	{
		if (!grid[TOP][CNT])
			grid[TOP][CNT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == TOP_RIGHT)
	{
		if (!grid[TOP][RGT])
			grid[TOP][RGT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == MID_LEFT)
	{
		if (!grid[MID][LFT])
			grid[MID][LFT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == MID_CENTER)
	{
		if (!grid[MID][CNT])
			grid[MID][CNT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == MID_RIGHT)
	{
		if (!grid[MID][RGT])
			grid[MID][RGT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == LOW_LEFT)
	{
		if (!grid[LOW][LFT])
			grid[LOW][LFT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == LOW_CENTER)
	{
		if (!grid[LOW][CNT])
			grid[LOW][CNT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else if (place == LOW_RIGHT)
	{
		if (!grid[LOW][RGT])
			grid[LOW][RGT] = player_turn();
		else
		{
			error++;
			goto try_CPU2;
		}
	}
	else
	{
		puts("Error, incorrect place. Please try again\n");
		error++;
		goto try_CPU2;
	}
	draw_board();
	turn++;
}

// This function is used when 1 player is against 1 CPU
void CPU()
{
try_CPU:
    switch (player_turn())
    {
    case SET_X:
        puts("X's turn");
        putchar('\n');
        fputs(
            "Please select where you would like to go, options include:\n"\
            "Nort West (1), North (2), North East (3), West (4), Center (5),\n"\
            "East (6), South West (7), South (8), South East (9):", stdout
        );
        putchar(' ');
        cin >> place;
        putchar('\n');
        break;
    case SET_O:
        puts("O(CPU)'s turn");
        CPU_O();
        break;
    default:
        puts("Error, unknown turn");
        error++;
    }

	if (place == TOP_LEFT)
	{
		if (!grid[TOP][LFT])
			grid[TOP][LFT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU; // Return to begining of function to try again
		}
	}
	else if (place == TOP_CENTER)
	{
		if (!grid[TOP][CNT])
			grid[TOP][CNT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else if (place == TOP_RIGHT)
	{
		if (!grid[TOP][RGT])
			grid[TOP][RGT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else if (place == MID_LEFT)
	{
		if (!grid[MID][LFT])
			grid[MID][LFT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else if (place == MID_CENTER)
	{
		if (!grid[MID][CNT])
			grid[MID][CNT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else if (place == MID_RIGHT)
	{
		if (!grid[MID][RGT])
			grid[MID][RGT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else if (place == LOW_LEFT)
	{
		if (!grid[LOW][LFT])
			grid[LOW][LFT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else if (place == LOW_CENTER)
	{
		if (!grid[LOW][CNT])
			grid[LOW][CNT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else if (place == LOW_RIGHT)
	{
		if (!grid[LOW][RGT])
			grid[LOW][RGT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_CPU;
		}
	}
	else
	{
		puts("Error, incorrect place. Please try again\n");
		error++;
		goto try_CPU;
	}
	draw_board();
	turn++;
}

// This function is used when 2 people play against each other
void person()
{
try_person:
    switch (player_turn())
    {
    case SET_X:
        puts("X's turn");
        break;
    case SET_O:
        puts("O's turn");
        break;
    default:
        puts("Error, unknown turn");
        error++;
    }

    putchar('\n');
    fputs(
        "Please select where you would like to go, options include:\n"\
        "Nort West (1), North (2), North East (3), West (4), Center (5),\n"
        "East (6), South West (7), South (8), South East (9):", stdout
    );
    putchar(' ');
	cin >> place;
    putchar('\n');

	if (place == TOP_LEFT)
	{
		if (!grid[TOP][LFT])
			grid[TOP][LFT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person; // Return to begining of function to try again
		}
	}
	else if (place == TOP_CENTER)
	{
		if (!grid[TOP][CNT])
			grid[TOP][CNT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else if (place == TOP_RIGHT)
	{
		if (!grid[TOP][RGT])
			grid[TOP][RGT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else if (place == MID_LEFT)
	{
		if (!grid[MID][LFT])
			grid[MID][LFT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else if (place == MID_CENTER)
	{
		if (!grid[MID][CNT])
			grid[MID][CNT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else if (place == MID_RIGHT)
	{
		if (!grid[MID][RGT])
			grid[MID][RGT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else if (place == LOW_LEFT)
	{
		if (!grid[LOW][LFT])
			grid[LOW][LFT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else if (place == LOW_CENTER)
	{
		if (!grid[LOW][CNT])
			grid[LOW][CNT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else if (place == LOW_RIGHT)
	{
		if (!grid[LOW][RGT])
			grid[LOW][RGT] = player_turn();
		else
		{
			puts("Error, cannot move there. Please try again\n");
			error++;
			goto try_person;
		}
	}
	else
	{
		puts("Error, incorrect place. Please try again\n");
		error++;
		goto try_person;
	}
	draw_board();
	turn++;
}

int main()
{
start:
	// Ask the user how many human players there are (if any)
    puts(
        "Would you like to play with 0 (2 CPUs), 1 (1 CPU), or 2 players? "\
        "(switching number of players mid-game requires a restart)"
    );
    puts("Note: All CPUs are very fast and you will likely not see them move.");
	cin >> players;
	system("cls");
	while (playing)
	{
		if (players == 0)
			CPU2();
		else if (players == 1)
			CPU();
		else if (players == 2)
			person();
		else
		{
			puts("Error, do not know how many people/CPU's are playing. Please try again.");
			error++;
			goto start;
		}
		place = 0;
		if (check_status())
		{
			system("cls");
			puts("SCOREBOARD:");
			putchar('\n');
			if (check_status() == WIN_X)
			{
				printf("X wins! It was done in %u turns.\n", turn);
				x_win++;
			}
			else if (check_status() == WIN_O)
			{
				printf("O wins! It was done in %u turns.\n", turn);
				o_win++;
			}
			else if (check_status() == DRAW)
			{
				printf("Tie, no one wins.\n");
				tie++;
			}
			else
			{
				puts("Error, unknown winner. Going back to start\n");
				error++;
				putchar('\n');
				goto start;
			}
			putchar('\n');

			game++;
			draw_board();

            putchar('\n');
            printf(
                "Out of %u game(s) played, "\
                "X has %u win(s), "\
                "O has %u win(s), "\
                "and there have been %u tie(s).\n",

                game, x_win, o_win, tie
            );

            putchar('\n');
            printf(
                "A total number of %u errors have occurred this turn "\
                "from moving in incorrect places or for some other reason.\n",

                error
            );

            fputs("Would you like to play again? (1 = yes, 0 = no): ", stdout);
			cin >> playing;
			reset();
		}
	}
}
