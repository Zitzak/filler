/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 10:31:54 by mgross         #+#    #+#                */
/*   Updated: 2019/01/30 19:32:37 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	size_t	i;

	i = 0;
	if (ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}
