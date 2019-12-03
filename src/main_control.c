/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_control.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 10:08:24 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:45:15 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void		write_coordinates(t_hmap *heatmap, t_pie *piece)
{
	if (piece->first_line != 1)
		heatmap->x = heatmap->x - (piece->first_line - 1);
	if (piece->first_star != 1)
		heatmap->y = heatmap->y - (piece->first_star - 1);
	ft_printf("%i %i\n", heatmap->x, heatmap->y);
}

int				main_control(t_fie *filler, t_hmap *heatmap, t_pie *piece)
{
	while (1)
	{
		if (update_game(filler, heatmap, piece) == -1)
			return (-1);
		if (!check_placement(heatmap, piece))
		{
			ft_printf("0 0\n");
			return (1);
		}
		write_coordinates(heatmap, piece);
		free_piece(piece);
	}
	return (1);
}
