/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 14:42:18 by mgross         #+#    #+#                */
/*   Updated: 2019/07/17 10:15:23 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_printf_fd(1, format, ap));
}

int		ft_dprintf(const int fd, const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_printf_fd(fd, format, ap));
}
