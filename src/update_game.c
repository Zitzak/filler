/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:44 by mgross         #+#    #+#                */
/*   Updated: 2019/09/14 13:36:30 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		init_var_update(t_str *strategy, t_pie *piece, t_hmap *heatmap)
{
	piece->first_star = 0;
	piece->last_star = 0;
	piece->lines_piece = 0;
	piece->first_line = -1;
	strategy->enemy_last_x = -1;
	strategy->enemy_curr_x = -1;
	heatmap->sum = 0;
}

int		update_game(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece)
{
	init_var_update(strategy, piece, heatmap);
	update_field(filler);
	update_enemy(filler, heatmap, strategy);
	update_strategy(filler, strategy);
	update_heatmap(filler, heatmap, strategy);
	if (update_piece(filler, piece) ==  -1)
		return (-1);
	return (0);
}
