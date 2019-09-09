/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_heatmap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:23 by mgross         #+#    #+#                */
/*   Updated: 2019/09/09 13:31:37 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		heatmap_from_left(t_hmap *heatmap)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		n = 1;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] < 0)
			{
				n++;
			}
			else
			{
				heatmap->map[x][y] = n;
				n++;
			}
			y++;
		}
		x++;
	}
}

void		heatmap_from_right(t_hmap *heatmap, t_fie *filler)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	filler->nks = 5;//
	// write(filler->fd, "test16\n", 7);
	while (x < heatmap->size_x)
	{
		y = heatmap->size_y -1;
		n = 1;
		while (y >= 0)
		{
			if (heatmap->map[x][y] < -1)
			{
				n++;
			}
			else
			{
				heatmap->map[x][y] = n;
				n++;
			}
			y--;
		}
		x++;
	}
}

void		heatmap_from_up(t_hmap *heatmap)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	n = 1;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] >= 0)
			{
				heatmap->map[x][y] = n;
			}
			y++;
		}
		x++;
		n++;
	}
}

void		heatmap_from_down(t_hmap *heatmap)
{
	int		x;
	int		y;
	int		n;

	x = heatmap->size_x -1;
	n = 1;
	while (x >= 0)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] >= 0)
			{
				heatmap->map[x][y] = n;
			}
			y++;
		}
		x--;
		n++;
	}
}

void		heatmap_to_enemy(t_fie *filler, t_hmap *heatmap)
{
	int		n;

	n = 1;
	while (redirect_heatmap_to_enemy(filler, heatmap, n))
	{
		n++;
	}
}
