/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:44 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 21:05:30 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		init_var_update(t_str *strategy, t_pie *piece)
{
	piece->first_star = 0;
	piece->last_star = 0;
	piece->lines_piece = 0;
	strategy->last_piece_x = -1;
	strategy->current_piece_x = -1;
}

void		update_game(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece)
{
	init_var_update(strategy, piece);
	update_field(filler);
	update_enemy(filler, heatmap, strategy);
	// update_strategy(filler, strategy);
	update_heatmap(filler, heatmap);
	update_piece(filler, heatmap, piece);
	print_test(filler, heatmap, strategy, piece);// <-----
}
