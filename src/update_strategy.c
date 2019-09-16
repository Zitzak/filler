/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_strategy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marvin <Marvin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 18:59:07 by Marvin         #+#    #+#                */
/*   Updated: 2019/09/16 20:24:04 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		calc_distance_redirect(t_fie *filler, t_str *strategy, t_pie *piece)
{
	if (filler->start == 0)
	{

	}
	if (filler->start == 1)
	{
		if (strategy->size_field == 's')
		{

		}
		if (strategy->size_field == 'm')
		{
			// if (((strategy->enemy_furthest_x - strategy->my_furthest_x) <= 4 && (strategy->enemy_furthest_xy - strategy->my_furthest_xy) <= 12) || ((strategy->enemy_furthest_x - strategy->my_furthest_x) <= 0))
			// {
				if (((strategy->enemy_furthest_x - strategy->my_furthest_x) < 4 && (strategy->enemy_furthest_xy - strategy->my_furthest_xy) <= 12) || ((strategy->enemy_furthest_x - strategy->my_furthest_x) <= 0 && (strategy->enemy_furthest_xy - strategy->my_furthest_xy) < 12))
				{
					ft_dprintf(filler->fd, "test1<<<<<<<<<<<<<<<\n");
					if (piece->lines_piece <= piece->collums_piece && strategy->ry_border != 1)
					{
						ft_dprintf(filler->fd, "test2<<<<<<<<<<<<<<<\n");
						strategy->up = 0;
						strategy->map = 'r';
					}
					else
					{
						strategy->map = 'd';
					}
				}
				// else if (((strategy->left >= 2 || strategy->dl_corner >= 2) && strategy->ry_border != 1) || (strategy->map = 'r' && strategy->ry_border == 1))
				else if ((((strategy->enemy_furthest_y - strategy->my_furthest_y) <= 12 && (strategy->enemy_furthest_yx - strategy->my_furthest_yx) < 4) && (strategy->dx_border != 1)) || ((strategy->enemy_furthest_y - strategy->my_furthest_y) <= 0 && (strategy->enemy_furthest_yx - strategy->my_furthest_yx) < 4))
				{
					ft_dprintf(filler->fd, "test3<<<<<<<<<<<<<<<\n");
					if (piece->collums_piece <= piece->lines_piece  && strategy->dx_border != 1)
					{
						ft_dprintf(filler->fd, "test4<<<<<<<<<<<<<<<\n");
						strategy->left = 0;
						strategy->map = 'd';
					}
					else
					{
						strategy->map = 'r';
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