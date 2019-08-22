/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 08:22:23 by mgross         #+#    #+#                */
/*   Updated: 2019/07/16 12:38:24 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnchar(char const *c, size_t len)
{
	write(1, c, len);
}
