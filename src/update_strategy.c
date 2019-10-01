/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_strategy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marvin <Marvin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 18:59:07 by Marvin         #+#    #+#                */
/*   Updated: 2019/09/30 15:56:40 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		calc_distance_redirect(t_fie *filler, t_str *strategy, t_pie *piece)
{
	if ((filler->start & START_BOTT) == START_BOTT)
	{

	}
	if ((filler->start & START_TOP) == START_TOP)
	{
		if ((strategy->map & SIZE_S) == SIZE_S)
		{

		}
		if ((strategy->map & SIZE_M) == SIZE_M)
		{
			// if (((strategy->enemy_far_x - strategy->my_far_x) <= 4 && (strategy->enemy_far_xy - strategy->my_far_xy) <= 12) || ((strategy->enemy_far_x - strategy->my_far_x) <= 0))
			// {
				if ((strategy->border & R_BORDER) != R_BORDER)
				{
					ft_dprintf(filler->fd, "test1<<<<<<<<<<<<<<<\n");
					// if ((strategy->my_far_x > (filler->field_x / 2) && (strategy->enemy_far_x - strategy->my_far_x) < 4 && (strategy->enemy_far_xy - strategy->my_far_xy) <= 12 && piece->lines_piece <= piece->collums_piece) || ((strategy->enemy_far_x - strategy->my_far_x) <= 0 && (strategy->enemy_far_xy - strategy->my_far_xy) < 12) || ((strategy->enemy_far_x - strategy->my_far_x) <= 0 && (strategy->enemy_far_y - strategy->my_far_y) < 12))
					if (strategy->enemy_far_x - strategy->my_far_x < 6)
					{
						ft_dprintf(filler->fd, "test2<<<<<<<<<<<<<<<\n");
						strategy->up = 0;
						strategy->map = 'r';
					}
					else
						strategy->map = 's';
				}
				// else if (((strategy->left >= 2 || strategy->dl_corner >= 2) && strategy->me_ry_border != 1) || (strategy->map = 'r' && strategy->me_ry_border == 1))
				else if ((strategy->border & D_BORDER) != D_BORDER)
				{
					ft_dprintf(filler->fd, "test3<<<<<<<<<<<<<<<\n");
					if ((((strategy->enemy_far_y - strategy->my_far_y) <= 12 && (strategy->enemy_far_yx - strategy->my_far_xy) < 4) && piece->collums_piece <= piece->lines_piece) || ((strategy->enemy_far_y - strategy->my_far_y) <= 0 && (strategy->enemy_far_yx - strategy->my_far_yx) < 4))
					{
						ft_dprintf(filler->fd, "test4<<<<<<<<<<<<<<<\n");
						strategy->left = 0;
						strategy->map = 'd';
					}
					else
					{
						strategy->map = 's';
					}
					
				}
				else
					strategy->map = 's';
// 
			// }

		}
		// else
		// {
			
		// }
		
	}

}

void		update_strategy(t_fie *filler, t_str *strategy, t_pie *piece)
{
	filler->nks = 5;//
	(void)piece;
	get_furthest_pos(filler, strategy);
	calc_distance_redirect(filler, strategy, piece);
}