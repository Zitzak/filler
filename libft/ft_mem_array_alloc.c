/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mem_array_alloc.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 15:41:35 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 21:20:33 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function takes the address of a 2D array plus the size of the layers it
** has to malloc and sets the last array pointer to NULL
*/

int		ft_mem_array_alloc(char ***array, size_t size)
{
	*array = (char**)malloc(sizeof(char*) * size);
	if (*array == NULL)
		return (-1);
	return (0);
}
