/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 11:35:02 by mgross         #+#    #+#                */
/*   Updated: 2019/10/14 16:29:20 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

int		getPathFiller_vm(t_test *result)
{
	int		len;
	int		i;

	i = 0;
	if (!strstr(result->array[i], "filler_vm"))
	{
		printf("Error: Invalid filler_vm path\n");
		return (ERROR);
	}
	pathToFile(result, i);
	len = strlen(result->buf);
	result->filler_vm = strndup(result->buf, (len - 1));
	printf("%s\n", result->filler_vm);//<-----------------
	return (SUCCES);
}

int		getNumRounds(t_test *result)
{
	int i;

	i = getPosNum(result);
	result->numRounds = atoi(result->array[i]);
	if (!result->numRounds)
	{
		printf("Error: Invalid number of rounds\n");
		return (ERROR);
	}
	printf("numRounds:%i\n", result->numRounds);//<-----------------
	return (SUCCES);
}

int		getPathPlayers(t_test *result)
{
	int		i;

	i = getPosPlayers(result);
	pathToFile(result, i);
	result->numPlayers = getNumLines(result, result->buf);
	if (!bufToArray(result, PLAYERS, result->numPlayers, result->array[i]))
		return (ERROR);
	printTest(result->players, result->numPlayers);//<------------------
	if (!validateInput(result->players, ".filler", result->numPlayers))
	{
		printf("Error: Invalid player in folder\n");
		return (ERROR);
	}
	return (SUCCES);
}

int		getPathMaps(t_test *result)
{
	int		i;

	i = getPosMap(result);
	pathToFile(result, i);
	result->numMaps = getNumLines(result, result->buf);
	if (!bufToArray(result, MAPS, result->numMaps, result->array[i]))
	{
		printf("Error: Malloc Error\n");
		return (ERROR);
	}
	if (!validateInput(result->maps, "map0", result->numMaps))
	{
		printf("!!Error: Invalid map in folder\n");
		return (ERROR);
	}
	printTest(result->maps, result->numMaps);//<------------------
	return (SUCCES);
}

int		getPathSingleMap(t_test *result)
{
	int		i;

	i = getPosMap(result);
	if (!strstr(result->array[i], "map0"))
	{
		printf("Error: Invalid map\n");
		return (ERROR);
	}
	result->singleMap = strdup(result->array[i]);
	if (!result->singleMap)
	{
		printf("Error: Malloc Error\n");
		return (ERROR);
	}
	// printf("singlemap: %s\n", result->singleMap);// <<--------------
	return (SUCCES);

}

int		getPathP1(t_test *result)
{
	int		i;

	i = getPosP1(result);
	if (!strstr(result->array[i], ".filler"))
	{
		printf("Error: Invalid player 1\n");
		return (ERROR);
	}
	result->player1 = strdup(result->array[i]);
	if (!result->player1)
	{
		printf("Error: Malloc Error\n");
		return (ERROR);
	}
	printf("player 1: %s\n", result->player1);// <<--------------
	return (SUCCES);
}

int		getPathP2(t_test *result)
{
	int		i;

	// write(result->fd1, "test1\n", 6);
	i = getPosP2(result);
	// dprintf(result->fd1, "i: %i\n", i);
	// dprintf(result->fd1, "i: %i - pla: %s\n", i, result->array[i]);
	// write(result->fd1, "test2\n", 6);
	if (!strstr(result->array[i], ".filler"))
	{
		printf("Error: Invalid player 2\n");
		return (ERROR);
	}
	// write(result->fd1, "test3\n", 6);
	result->player2 = strdup(result->array[i]);
	// write(result->fd1, "test4\n", 6);
	if (!result->player2)
	{
		printf("Error: Malloc Error\n");
		return (ERROR);
	}
	// write(result->fd1, "test5\n", 6);
	printf("player 2: %s\n", result->player2);// <<--------------
	return (SUCCES);
}
