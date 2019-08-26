/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:44 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 17:03:48 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		initializing_var_struct(t_info *filler, t_hmap *heatmap)
{
	filler->first_star = 0;
	filler->last_star = 0;
	filler->lines_piece = 0;
	heatmap->last_piece_x = -1;
	heatmap->current_piece_x = -1;
}

void		update_game(t_info *filler, t_hmap *heatmap)
{
	initializing_var_struct(filler, heatmap);
	update_field(filler);
	update_enemy(filler, heatmap);
	update_heatmap(filler, heatmap);
	update_piece(filler, heatmap);
	print_test(filler, heatmap);// <-----
}
