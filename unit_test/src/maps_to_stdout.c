/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maps_to_stdout.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 15:58:36 by mgross         #+#    #+#                */
/*   Updated: 2019/10/03 20:21:47 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

void		write_score(t_test *result, char *str)
{
	// dprintf(result->fd1, "str: %s\n", str);
	while (isdigit(*str) != 1)
		str++;
	result->o = atoi(str);
	str = str + 4;
	while (isdigit(*str) != 1)
		str++;
	result->x = atoi(str);
	if (result->x > result->o)
	{
		result->flags |= FLAG_P2W;
		result->score_x++;
	}
	else
	{
		result->flags |= FLAG_P1W;
		result->score_o++;
	}
	// write(result->fd1, "test2\n", 6);
	// dprintf(result->fd1, "game->o: %i - game-x: %i\n", result->o, result->x);
}

void			read_function(t_test *result)
{
	int		fd;
	char	buff[BUFFSIZE_TEST + 1];
	int		ret;
	char	*score;

	bzero(result->buf, BUFFSIZE_TEST);
	ret = 1;
	fd = open(READ, O_RDWR);	
	while (ret != 0)
	{
		ret = read(fd, buff, BUFFSIZE_TEST);
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
	write_score(result, result->buf);
	close(fd);
}

int		addStringsForCommand(t_test *result, char *map, char *enemy, char *output)
{
	if ((result->flags & FLAG_P1) == FLAG_P1)
	{
		if (strstr(enemy, result->player1))
			return (ERROR);
		else
		{
			strcpy(result->cmd, result->filler_vm);
			strcat(result->cmd, F);
			strcat(result->cmd, map);
			strcat(result->cmd, P1);
			strcat(result->cmd, result->player1);
			strcat(result->cmd, P2);
			strcat(result->cmd, enemy);
			strcat(result->cmd, output);
		}
	}
	else
	{
		if (strstr(enemy, result->player2))
			return(ERROR);
		else	
		{
			strcpy(result->cmd, result->filler_vm);
			strcat(result->cmd, F);
			strcat(result->cmd, map);
			strcat(result->cmd, P1);
			strcat(result->cmd, enemy);
			strcat(result->cmd, P2);
			strcat(result->cmd, result->player2);
			strcat(result->cmd, output);
		}
	}
	return (SUCCES);
}

void	allPlayersAllMaps(t_test *result)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	while (i < result->numPlayers)
	{
		j = 0;
		printMatchUp(result, result->players[i]);
		while (j < result->numMaps)
		{
			c = 0;
			result->size_print = j;
			while (c < result->numRounds)
			{
				if (addStringsForCommand(result, result->maps[j], result->players[i], result->output))
				{
					systemCall(result);
					read_function(result);
					printRoundScore(result, result->maps[j], result->players[i], (c + 1));
				}
				c++;
			}
			printMapChange(result);
			j++;
		}
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
		// dprintf(result->fd1, "score->o: %i - score-x: %i\n", result->score_o, result->score_x);
	}
	// if ((result->flags & FLAG_A) != FLAG_A && (result->flags & FLAG_F) != FLAG_F)
	// {
	// 	p1P2OneMaps(result);
	// }
	// else if ((result->flags & FLAG_A) != FLAG_A && (result->flags & FLAG_F) == FLAG_F)
	// {
	// 	p1P2AllMaps(result);
	// }
}