/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 15:31:33 by mgross         #+#    #+#                */
/*   Updated: 2019/10/03 16:17:49 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

int		get_args(t_test *result, int argc, char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 1;

	result->array = (char**)malloc(sizeof(char*) * (argc - 1));
	while (i < argc - 1)
	{
		len = strlen(argv[j]);
		result->array[i] = (char*)malloc(sizeof(char) * (len + 1));	
		if (!get_flags(result, argv[j]))
			return (ERROR);
		strcpy(result->array[i], argv[j]);
		i++;
		j++;
	}
	if ((result->flags & FLAG_P1) != FLAG_P1 && (result->flags & FLAG_P2) != FLAG_P2)
	{
		printf("Error: No -p1 or -p2 specifier\n");
		return (ERROR);
	}
	return (SUCCES);
}

int		getPaths(t_test *result)
{
	if (!getPathFiller_vm(result))
		return (ERROR);
	if ((result->flags & FLAG_N) == FLAG_N)
	{
		if(!getNumRounds(result))
			return (ERROR);
	}
	if ((result->flags & FLAG_A) == FLAG_A)
	{
		if(!getPathPlayers(result))
			return (ERROR);
	}
	if ((result->flags & FLAG_F) == FLAG_F)
	{
		if(!getPathMaps(result))
			return (ERROR);
	}
	else
	{
		if (!getPathSingleMap(result))
			return (ERROR);
	}
	if ((result->flags & FLAG_P1) == FLAG_P1)
	{
		if(!getPathP1(result))
			return (ERROR);
	}
	if ((result->flags & FLAG_P2) == FLAG_P2)
	{
		if(!getPathP2(result))
			return (ERROR);
	}
	return (SUCCES);
}

