/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_placement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 17:24:04 by mgross         #+#    #+#                */
/*   Updated: 2019/09/09 15:02:05 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** Test placement of piece to up and left
*/

int		get_sum_placement(t_hmap *heatmap, t_pie *piece, int x, int y, t_fie *filler)
{
	int		sum;
	int		temp_y;
	
	sum = 0; filler->nks = 0;//
	while (piece->x < piece->lines_piece)
	{	
		piece->y = 0;
		temp_y = y;
		//dit is eebn testststslhja
		while (piece->y < piece->collums_piece || temp_y == heatmap->size_y)
		{
			if (heatmap->map[x][temp_y] == 0 && piece->piece[piece->x][piece->y] == '*')
				piece->star++;
			if (heatmap->map[x][temp_y] < -1 && piece->piece[piece->x][piece->y] == '*')
				return (0);
			sum = sum + heatmap->map[x][temp_y];
			piece->y++;
			temp_y++;
		}
		piece->x++;
		x++;
		if (temp_y == heatmap->size_y || x == heatmap->size_x)
			return (0);
	}
	if (piece->star != 1)
		sum = 0;
	return (sum);
}

void		init_var_test_placement(t_pie *piece)
{
	piece->star = 0;
	piece->x = 0;
}

int		check_placement(t_hmap *heatmap, t_pie *piece, t_fie *filler)
{
	int		x;
	int		y;
	int		sum;
	int		ret;

	ret = 0;
	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			init_var_test_placement(piece);
			sum = get_sum_placement(heatmap, piece, x, y, filler);
			if (sum > 0)
			{
				// ft_dprintf(filler->fd, "1 - sum: %i - x: %i - y: %i\n", sum, x, y);
				if ((sum < heatmap->sum || heatmap->sum == 0))
				{
					// ft_dprintf(filler->fd, "2 - sum: %i - x: %i - y: %i\n", sum, x, y);
					if (ret == 0)
						ret = 1;
					heatmap->x = x;
					heatmap->sum = sum;
					heatmap->y = y;
				}
			}
			y++;				
		}
		x++;
	}
	return (ret);
}



// void		place_piece(t_hmap *heatmap, t_pie *piece, t_fie *filler)
// {
// 	check_placement(heatmap, piece, filler);
	// write_coordinates(heatmap, piece);
// }