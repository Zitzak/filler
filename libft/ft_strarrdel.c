/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 19:02:13 by mgross         #+#    #+#                */
/*   Updated: 2019/04/03 12:17:30 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function frees all levels of an 2D array. This works only if the last
** level of the 2D array is pointed to NULL
*/

void	ft_strarrdel(char **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	while (i >= 0)
	{
		ft_strdel(&array[i]);
		i--;
	}
	free(array);
}
