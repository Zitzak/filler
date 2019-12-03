/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maps_to_stdout.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 15:58:36 by mgross         #+#    #+#                */
/*   Updated: 2019/10/17 13:55:48 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"



void			read_function(t_test *result)
{
	int		fd;
	char	buff[BUFFSIZE_TEST + 1];
	int		ret;
	char	*score;

	bzero(result->buf, BUFFSIZE_TEST);
	ret = 1;
	fd = open (READ, O_RDWR);
	while (ret != 0)
	{
		ret = read (fd, buff, BUFFSIZE_TEST);
		buff[ret] = '\0';
		score = strstr(buff, "==");
		if (score != NULL)
		{
			printf("%s", buff);
			break ;
		}
		else
			printf("%s", buff);
	}
	ret = strlen(score);
	strncpy(result->buf, score, ret);
	countScore(result, result->buf);
	close(fd);
}

void	allPlayersAllMaps(t_test *result)
{
	int		i;
	int		j;
	int		round;

	i = 0;
	while (i < result->numPlayers)
	{
		j = 0;
		printMatchUp(result, result->players[i]);
		while (j < result->numMaps)
		{
			round = 0;
			result->size_print = j;
			while (round < result->numRounds)
			{
				if (addStringsForCommand(result, result->maps[j], result->players[i], result->output))
				{
					systemCall(result);
					read_function(result);
					printRoundScore(result, result->maps[j], result->players[i], (round + 1));
				}
				round++;
			}
			printMapChange(result);
			j++;
		}
		i++;
	}
}

void	allPlayerOneMap(t_test *result)
{
	int		i;
	int		round;

	i = 0;
	while (i < result->numPlayers)
	{
		printMatchUp(result, result->players[i]);
		round = 0;
		while (round < result->numRounds)
		{
			if (addStringsForCommand(result, result->singleMap, result->players[i], result->output))
			{
				systemCall(result);
				read_function(result);
				printRoundScore(result, result->singleMap, result->players[i], (round + 1));
			}
			round++;
		}
		printMapChange(result);
		i++;
	}

}

void	testsToOutput(t_test *result)
{
	int		i;

	i = 0;
	result->output = strdup(STDOUT);
	if ((result->flags & FLAG_A) == FLAG_A && (result->flags & FLAG_F) == FLAG_F)
	{
		allPlayersAllMaps(result);
	}
	// else if ((result->flags & FLAG_A) == FLAG_A && (result->flags & FLAG_F) != FLAG_F)
	// {
	// 	allPlayerOneMap(result);
	// }
	// if ((result->flags & FLAG_A) != FLAG_A && (result->flags & FLAG_F) != FLAG_F)
	// {
	// 	p1P2OneMaps(result);
	// }
	// else if ((result->flags & FLAG_A) != FLAG_A && (result->flags & FLAG_F) == FLAG_F)
	// {
	// 	p1P2AllMaps(result);
	// }
	free(result->output);
}