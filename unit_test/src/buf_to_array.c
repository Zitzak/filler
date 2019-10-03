/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buf_to_array.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 20:19:24 by mgross         #+#    #+#                */
/*   Updated: 2019/10/03 17:05:01 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

int		strlen_newline(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\n')
	{
		i++;
	}
	return (i);
}

int		bufToArray(t_test *result, int type, int size, char *path)
{
	int		i;
	int		len;
	int		path_len;
	int		max_len;
	char	**array;

	i = 0;
	max_len = 0;
	path_len = strlen(path);
	array = (char**)malloc(sizeof(char*) * size);
	if (!array)
		return (ERROR);
	while (i < size)
	{
		len = (strlen_newline(&result->buf[max_len]));
		array[i] = (char*)malloc(sizeof(char) * (len + path_len));
		if (!array[i])
			return (ERROR);
		strcpy(array[i], path);
		strncat(array[i], (&result->buf[max_len]), len);
		max_len = max_len + len + 1;
		i++;
	}
	if (type == PLAYERS)
		result->players = array;
	else
		result->maps = array;
	return (SUCCES);
}

int		getNumLines(t_test *result, char *str)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	readFileToBuf(result);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			num++;
		}
		i++;
	}
	return (num);
}
