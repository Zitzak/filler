/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pos.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:43:24 by mgross         #+#    #+#                */
/*   Updated: 2019/09/18 20:16:23 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		get_my_pos_down(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	x = 0;
	while (x < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (filler->field[x][y] == filler->me)
			{
				if (strategy->my_furthest_x == -1)
				{
					assign_pos_me_x(strategy, x, y);
				}
				if (y < (strategy->my_furthest_y - 1) ||
					strategy->my_furthest_y == -1)
				{
					assign_pos_me_y(strategy, x, y);
				}
			}
			y++;
		}
		x++;
	}
}

void		get_my_pos_up(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	x = filler->field_x - 1;
	while (x >= 0)
	{
		y = filler->field_y - 1;
		while (y >= 0)
		{
			if (filler->field[x][y] == filler->me)
			{
				if (((filler->field_x - 1) - x) < 2)
					strategy->dx_border = 1;
				if (((filler->field_y - 1) - y) < 2)
					strategy->ry_border = 1;
				if (strategy->my_furthest_x == -1)
					assign_pos_me_x(strategy, x, y);
				if (y > (strategy->my_furthest_y - 1) ||
					strategy->my_furthest_y == -1)
					assign_pos_me_y(strategy, x, y);
			}
			y--;
		}
		x--;
	}
}

void		get_enemy_pos_down(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	x = 0;
	while (x < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (filler->field[x][y] == filler->enemy)
			{
				if (strategy->enemy_furthest_x == -1)
				{
					assign_pos_enemy_x(strategy, x, y);
				}
				if (y < (strategy->enemy_furthest_y - 1) ||
					strategy->enemy_furthest_y == -1)
				{
					assign_pos_enemy_y(strategy, x, y);
				}
			}
			y++;
		}
		x++;
	}
}

void		get_enemy_pos_up(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	x = filler->field_x - 1;
	while (x >= 0)
	{
		y = filler->field_y - 1;
		while (y >= 0)
		{
			if (filler->field[x][y] == filler->enemy)
			{
				if (strategy->enemy_furthest_x == -1)
					assign_pos_enemy_x(strategy, x, y);
				if (y > (strategy->enemy_furthest_y - 1) ||
					strategy->enemy_furthest_y == -1)
					assign_pos_enemy_y(strategy, x, y);
			}
			y--;
		}
		x--;
	}
}

void		get_furthest_pos(t_fie *filler, t_str *strategy)
{
	init_var_get_pos(strategy);
	if (filler->start == 0)
	{
		get_my_pos_down(filler, strategy);
		get_enemy_pos_up(filler, strategy);
	}
	if (filler->start == 1)
	{
		get_my_pos_up(filler, strategy);
		get_enemy_pos_down(filler, strategy);
	}
}
