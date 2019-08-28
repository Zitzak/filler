/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_control.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 10:08:24 by mgross         #+#    #+#                */
/*   Updated: 2019/08/28 15:56:56 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		init_var_strategy(t_fie *filler, t_str *strategy, t_hmap *heatmap)
{
	if (filler->field_x == 15)
		strategy->size_field = 's';
	else if (filler->field_x == 24)
		strategy->size_field = 'm';
	else
		strategy->size_field = 'l';
	strategy->down = 0;
	strategy->up = 0;
	strategy->left = 0;
	strategy->right = 0;
	strategy->ul_corner = 0;
	strategy->ur_corner = 0;
	strategy->dl_corner = 0;
	strategy->dr_corner = 0;
	heatmap->sum = 0;
}

void		main_control(t_fie *filler, t_hmap *heatmap)
{
	t_str			*strategy;
	t_pie			*piece;

	piece = (t_pie*)malloc(sizeof(t_pie));
	if (piece == NULL)
		exit (-1); //<<<< error
	strategy = (t_str*)malloc(sizeof(t_str));
	if (strategy == NULL)
		exit (-1);
	//hier komt de while loop <<<<<<<<<<<<
	init_var_strategy(filler, strategy, heatmap);
	update_game(filler, heatmap, strategy, piece);
	check_placement(heatmap, piece, filler);
	ft_dprintf(filler->fd, "sum_heatmap!!!! %i\n", heatmap->sum);
	print_test(filler, heatmap, strategy, piece);// <-----

}