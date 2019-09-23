/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pos.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:43:24 by mgross         #+#    #+#                */
/*   Updated: 2019/09/19 19:55:09 by Marvin        ########   odam.nl         */
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
				if (strategy->my_far_x == -1)
				{
					assign_pos_me_x(strategy, x, y);
				}
				if (y < (strategy->my_far_y - 1) ||
					strategy->my_far_y == -1)
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
					strategy->border |= D_BORDER;
				if (((filler->field_y - 1) - y) < 2)
					strategy->border |= R_BORDER;
				if (x == 0)
					strategy->border |= T_BORDER;
				if (y == 0)
					strategy->border |= L_BORDER;
				if (strategy->my_far_x == -1)
					assign_pos_me_x(strategy, x, y);
				if (y > (strategy->my_far_y - 1) ||
					strategy->my_far_y == -1)
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
				get_quater(filler, strategy, x, y);
				if (strategy->enemy_far_x == -1)
				{
					assign_pos_enemy_x(strategy, x, y);
				}
				if (y < (strategy->enemy_far_y - 1) ||
					strategy->enemy_far_y == -1)
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
				if (strategy->enemy_far_x == -1)
					assign_pos_enemy_x(strategy, x, y);
				if (y > (strategy->enemy_far_y - 1) ||
					strategy->enemy_far_y == -1)
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
