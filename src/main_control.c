/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_control.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 10:08:24 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 20:43:16 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		init_var_strategy(t_str *strategy)
{
	strategy->down = 0;
	strategy->up = 0;
	strategy->left = 0;
	strategy->right = 0;
	strategy->ul_corner = 0;
	strategy->ur_corner = 0;
	strategy->dl_corner = 0;
	strategy->dr_corner = 0;
}

void		main_control(t_fie *filler, t_hmap *heatmap)
{
	t_str			*strategy;
	t_pie			*piece;

	piece = malloc(sizeof(piece));
	strategy = malloc(sizeof(t_str));
	init_var_strategy(strategy);
	update_game(filler, heatmap, strategy, piece);
}