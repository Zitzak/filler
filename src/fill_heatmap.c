/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_heatmap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:23 by mgross         #+#    #+#                */
/*   Updated: 2019/08/22 17:15:02 by mgross        ########   odam.nl         */
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

void		heatmap_from_right(t_hmap *heatmap)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = heatmap->size_y -1;
		n = 1;
		while (y >= 0)
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

void		change_heatmap(t_hmap *heatmap, int n, int x, int y)
{
	if (heatmap->map[x - 1][y - 1] == 0 && x != 0 && y != 0)
		heatmap->map[x - 1][y - 1] = n;
	if (heatmap->map[x][y - 1] == 0 && y != 0)
		heatmap->map[x][y - 1] = n;
	if (heatmap->map[x + 1][y - 1] == 0 && x != (heatmap->size_x - 1) && y != 0)
		heatmap->map[x + 1][y - 1] = n;
	if (heatmap->map[x + 1][y] == 0 && x != (heatmap->size_x - 1))
		heatmap->map[x + 1][y] = n;
	if (heatmap->map[x + 1][y + 1] == 0 && x != (heatmap->size_x - 1) && y != 
		(heatmap->size_y - 1))
		heatmap->map[x + 1][y + 1] = n;
	if (heatmap->map[x][y + 1] == 0 && y != (heatmap->size_y - 1))
		heatmap->map[x][y + 1] = n;
	if (heatmap->map[x - 1][y + 1] == 0 && x != 0 && y != (heatmap->size_y - 1))
		heatmap->map[x - 1][y + 1] = n;
	if (heatmap->map[x - 1][y] == 0 && x != 0)
		heatmap->map[x - 1][y] = n;
}

void		heatmap_to_enemy(t_hmap *heatmap)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] < 0)
			{
				change_heatmap(heatmap, n, x, y);
			}
			y++;
		}
	}

}
