/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 18:13:46 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:38:52 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	free_line(t_fie *filler)
{
	ft_strdel(&filler->line);
}

void	free_filler(t_fie *filler)
{
	ft_strarrdel(&filler->field, (size_t)filler->field_x);
}

void	free_piece(t_pie *piece)
{
	ft_strarrdel(&piece->temp_piece, (size_t)piece->piece_x);
	ft_strarrdel(&piece->piece, (size_t)piece->lines_piece);
}
