/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_control.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 10:08:24 by mgross         #+#    #+#                */
/*   Updated: 2019/09/27 16:13:50 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		write_coordinates(t_fie *filler, t_hmap *heatmap, t_pie *piece)
{
	filler->nks = 5;// <-------
	if (piece->first_line != 1)
		heatmap->x = heatmap->x - (piece->first_line - 1);
	if (piece->first_star != 1)
		heatmap->y = heatmap->y - (piece->first_star - 1);
	ft_dprintf(filler->fd, "x: %i, y: %i\n", heatmap->x, heatmap->y);
	ft_printf("%i %i\n", heatmap->x, heatmap->y);
}

int			main_control(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece)
{
	int i;//

	i = 0;//
	while (1)// hier moet weer 1
	{
		if (update_game(filler, heatmap, strategy, piece) == -1)
			return (-1);
		if (!check_placement(heatmap, piece, strategy))
		{
			ft_printf("0 0\n");
			return (1);
		}
		write_coordinates(filler, heatmap, piece);
		print_test(filler, heatmap, strategy, piece);// <-----
		free_piece(piece);
		i++;//
	}
	return (1);//
}
