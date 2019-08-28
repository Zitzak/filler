/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_placement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 17:24:04 by mgross         #+#    #+#                */
/*   Updated: 2019/08/28 16:10:45 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** Test placement of piece to up and left
*/

int		test_placement(t_hmap *heatmap, t_pie *piece, int x, int y, t_fie *filler)
{
	int		temp;
	int		piece_x;
	int		piece_y;
	int		sum;
	int		temp_y;
	
	temp_y = y;
	temp = 0;
	piece_x = 0;
	sum = 0;filler->start = 1;
	while (piece_x < piece->lines_piece)
	{	
		if (x == heatmap->size_x)
		{
			// ft_dprintf(filler->fd, "\ntest3\n\n");		
			return (0);
		}
		piece_y = 0;
		temp_y = y;
		while (piece_y < piece->collums_piece)
		{
			if (temp_y == heatmap->size_y)
			{
				// ft_dprintf(filler->fd, "\ntest1\n\n");
				return (0);
			}
			if (heatmap->map[x][temp_y] == 0 && piece->piece[piece_x][piece_y] == '*')
				temp++;
			if ((heatmap->map[x][temp_y] < -1 && piece->piece[piece_x][piece_y] == '*') || (temp > 1))
			{
				return (0);
				// ft_dprintf(filler->fd, "\ntest2\n\n");					
			}
			// ft_dprintf(filler->fd, "heatmap_num: %i ", heatmap->map[x][temp_y]);
			sum = sum + heatmap->map[x][temp_y];
			// ft_dprintf(filler->fd, "sum after adding: %i\n", sum);
			piece_y++;
			temp_y++;
		}
		piece_x++;
		x++;
	}
	// ft_dprintf(filler->fd, "sum before check temp: %i\n", sum, temp);
	if (temp != 1)
		sum = 0;
	// ft_dprintf(filler->fd, "sum: %i - temp: %i\n", sum, temp);
	return (sum);
}

// void		redirect_test_placement(t_hmap *heatmap, t_pie *piece)
// {
	
// }


void		check_placement(t_hmap *heatmap, t_pie *piece, t_fie *filler)
{
	int		x;
	int		y;
	int		sum;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			sum = test_placement(heatmap, piece, x, y, filler);
			// ft_dprintf(filler->fd, "sum_chek_placement %i\n", sum);
			if (sum > 0)
			{
				ft_dprintf(filler->fd, "heatmap->sum1 %i\nx: %i\ny: %i\n\n", heatmap->sum, heatmap->x, heatmap->y);
				// ft_dprintf(filler->fd, "test5\n");
				if (heatmap->sum == 0)
				{
					// ft_dprintf(filler->fd, "test6\n");
					heatmap->x = x;
					heatmap->sum = sum;
					// ft_dprintf(filler->fd, "heatmap->sum2 %i\n\n", heatmap->sum);
					heatmap->y = y;
				}
				else if (sum < heatmap->sum)
				{
					// ft_dprintf(filler->fd, "test7\n");
					heatmap->x = x;
					heatmap->sum = sum;
					// ft_dprintf(filler->fd, "heatmap->sum3 %i\n\n", heatmap->sum);
					heatmap->y = y;
				}
			}
			y++;				
		}
		x++;
	}
}