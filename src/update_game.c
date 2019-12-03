/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:44 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:46:00 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void		init_var_update(t_pie *piece, t_hmap *heatmap)
{
	piece->first_star = 0;
	piece->last_star = 0;
	piece->lines_piece = 0;
	piece->first_line = -1;
	heatmap->sum = 0;
}

int				update_game(t_fie *filler, t_hmap *heatmap, t_pie *piece)
{
	init_var_update(piece, heatmap);
	if (!update_field(filler, heatmap))
		return (-1);
	update_enemy(filler, heatmap);
	update_heatmap(filler, heatmap);
	if (update_piece(filler, piece) == -1)
		return (-1);
	return (0);
}
