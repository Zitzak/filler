/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_control.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 10:08:24 by mgross         #+#    #+#                */
/*   Updated: 2019/09/09 16:14:19 by mgross        ########   odam.nl         */
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

void		write_coordinates(t_hmap *heatmap, t_pie *piece)
{
	if (piece->first_line != 1)
		heatmap->x = heatmap->x - (piece->first_line - 1);
	if (piece->first_star != 1)
		heatmap->y = heatmap->y - (piece->first_star - 1);
	ft_printf("%i %i\n", heatmap->x, heatmap->y);
}

void		main_control(t_fie *filler, t_hmap *heatmap)
{
	t_str			*strategy;
	t_pie			*piece;
	int				ret;

	ret = 1;
	piece = (t_pie*)malloc(sizeof(t_pie));
	if (piece == NULL)
		exit (-1); //<<<< error
	strategy = (t_str*)malloc(sizeof(t_str));
	if (strategy == NULL)
		exit (-1);
	//hier komt de while loop <<<<<<<<<<<<
	// write(filler->fd, "n2:", 3);ft_putnbr_fd(heatmap->map[0][0], filler->fd);write(filler->fd, "\n", 1);
	init_var_strategy(filler, strategy, heatmap);
	while (1)
	{
		write(filler->fd, "n3:", 3);
		update_game(filler, heatmap, strategy, piece);
		write(filler->fd, "n4:", 3);		
		ret = check_placement(heatmap, piece, filler);
		write(filler->fd, "n5:\n", 4);
		if (ret == 0)
			break ;
		write_coordinates(heatmap, piece);
		// ft_dprintf(filler->fd, "sum_heatmap!!!! %i\n", heatmap->sum);
		// print_test(filler, heatmap, strategy, piece);// <-----
	}
	ft_printf("0 0\n");
}