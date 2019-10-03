/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 09:28:46 by mgross         #+#    #+#                */
/*   Updated: 2019/10/03 20:43:34 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

void	printP1W(t_test *result, char * map, char *enemy, int round)
{
	if ((result->flags & FLAG_P1) == FLAG_P1)
	{
		if (result->size_print == SMALL)
			dprintf(result->fd1, "%s		 %i		[WIN]		   %s		 %i		  -		 %i			   %s				[LOSE]\n", strstr(map, "0"), round, (strrchr(result->player1, '/') + 1), result->o, result->x, (strrchr(enemy, '/') + 1));
		if (result->size_print == MEDIUM)
			dprintf(result->fd1, "%s		 %i		[WIN]		   %s		 %i		  -		 %i			   %s				[LOSE]\n", strstr(map, "0"), round, (strrchr(result->player1, '/') + 1), result->o, result->x, (strrchr(enemy, '/') + 1));
		if (result->size_print == LARGE)
			dprintf(result->fd1, "%s		 %i		[WIN]		   %s		 %i	  -		 %i				 %s				[LOSE]\n", strstr(map, "0"), round, (strrchr(result->player1, '/') + 1), result->o, result->x, (strrchr(enemy, '/') + 1));
	}
	else if ((result->flags & FLAG_P2) == FLAG_P2)
	{
		if (result->size_print == SMALL)
			dprintf(result->fd1, "%s		 %i		[WIN]		   %s				%i		 -		%i			%s			[LOSE]\n", strstr(map, "0"), round, (strrchr(enemy, '/') + 1), result->o, result->x, strstr(result->player2, "player"));
		if (result->size_print == MEDIUM)
			dprintf(result->fd1, "%s		 %i		[WIN]		   %s				%i		 -		%i			%s			[LOSE]\n", strstr(map, "0"), round, (strrchr(enemy, '/') + 1), result->o, result->x, strstr(result->player2, "player"));
		if (result->size_print == LARGE)
			dprintf(result->fd1, "%s		 %i		[WIN]		   %s				%i	 -		%i			%s			[LOSE]\n", strstr(map, "0"), round, (strrchr(enemy, '/') + 1), result->o, result->x, strstr(result->player2, "player"));	
	}
}

void	printP2W(t_test *result, char * map, char *enemy, int round)
{
	if ((result->flags & FLAG_P1) == FLAG_P1)
	{
		if (result->size_print == SMALL)
			dprintf(result->fd1, "%s		 %i		[LOSE]		  %s			%i		-		%i			%s			[WIN]\n", strstr(map, "0"), round, (strrchr(result->player1, '/') + 1), result->o, result->x, (strrchr(enemy, '/') + 1));
		if (result->size_print == MEDIUM)
			dprintf(result->fd1, "%s		 %i		[LOSE]		  %s			%i		-		%i			%s			[WIN]\n", strstr(map, "0"), round, (strrchr(result->player1, '/') + 1), result->o, result->x, (strrchr(enemy, '/') + 1));
		if (result->size_print == LARGE)
			dprintf(result->fd1, "%s		 %i		[LOSE]		  %s			%i		-	%i			%s			[WIN]\n", strstr(map, "0"), round, (strrchr(result->player1, '/') + 1), result->o, result->x, (strrchr(enemy, '/') + 1));
	}
	else if ((result->flags & FLAG_P2) == FLAG_P2)
	{
		if (result->size_print == SMALL)
			dprintf(result->fd1, "%s		 %i		[LOSE]		  %s				%i		-		%i			%s			[WIN]\n", strstr(map, "0"), round, (strrchr(enemy, '/') + 1), result->o, result->x, strstr(result->player2, "player"));
		if (result->size_print == MEDIUM)
			dprintf(result->fd1, "%s		 %i		[LOSE]		  %s				%i		-		%i			%s			[WIN]\n", strstr(map, "0"), round, (strrchr(enemy, '/') + 1), result->o, result->x, strstr(result->player2, "player"));
		if (result->size_print == LARGE)
			dprintf(result->fd1, "%s 		 %i		[LOSE]		  %s				%i		-	%i			%s			[WIN]\n", strstr(map, "0"), round, (strrchr(enemy, '/') + 1), result->o, result->x, strstr(result->player2, "player"));
	}
}

void	printRoundScore(t_test *result, char * map, char *enemy, int round)
{
	if ((result->flags & FLAG_P1W) == FLAG_P1W)
	{
		printP1W(result, map, enemy, round);
		result->flags ^= FLAG_P1W;
	}
	else
	{
		printP2W(result, map, enemy, round);
		result->flags ^= FLAG_P2W;
	}
}

void	printMatchUp(t_test *result, char *enemy)
{
	dprintf(result->fd1, "Map	   Round   WIN/LOSE			PLAYER 1			SCORE		    SCORE			PLAYER 2					WIN/LOSE\n----------------------------------------------------------------------------------------------------------------------------------------\n");
	if ((result->flags & FLAG_P1) == FLAG_P1)
	{
		dprintf(result->fd1, "							  [%s]					VS				  [%s]\n\n", (strrchr(result->player1, '/') + 1), (strrchr(enemy, '/') + 1));
	}
	else if ((result->flags & FLAG_P2) == FLAG_P2)
	{
		dprintf(result->fd1, "							  [%s]					VS				  [%s]\n\n", (strrchr(result->player1, '/') + 1), (strrchr(enemy, '/') + 1));
	}
}
void	printMapChange(t_test *result)
{
	dprintf(result->fd1, "\n");
}

// void	
// void	print_player_score(t_test *result)
// {
// 	if ((result->me & P1) == P1)
// 	{
// 		if (result->score_o > result->score_x)
// 			dprintf(result->fd1, "Score\n-----\nme: %i  -  enemy: %i\nWON :)\n\n", result->score_o, result->score_x);
// 		else
// 			dprintf(result->fd1, "Score\n-----\nme: %i  -  enemy: %i\nLOST :(\n\n", result->score_o, result->score_x);
// 	}
// 	else
// 	{
// 		if (result->score_o > result->score_x)
// 			dprintf(result->fd1, "Score\n-----\nme: %i  -  enemy: %i\nLOST :(\n\n", result->score_x, result->score_o);
// 		else
// 			dprintf(result->fd1, "Score\n-----\nme: %i  -  enemy: %i\nWON :)\n\n", result->score_x, result->score_o);
// 	}
// 	result->score_x = 0;
// 	result->score_o = 0;
// }

void		printUsage()
{
	printf("usage: filler_tester [path to filler_vm] [-onafFp1p2] [-o write maps to STDOUT] \
[-n number of rounds] [[-a all player][path to folder with players]]\n       [-F all maps[path to folder with maps]] \
[-f path to map] [-p1 player1] [-p2 path to player2]\n\n       filler_tester -n 10 -a [path to folder with player] -F [path to folder with \
all maps] -p1 [path to player to compete]\n       \
filler_tester -o -f [path to map] -p1 [path to player1] -p2 [path to player 2]\n");
}