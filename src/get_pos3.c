/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_quater.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marvin <Marvin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 16:54:10 by Marvin         #+#    #+#                */
/*   Updated: 2019/09/19 17:45:24 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		get_quater(t_fie *filler, t_str *strategy, int x, int y)
{
	int		size_x;
	int		size_y;

	
	size_x = filler->field_x / 4;
	size_y = filler->field_y / 4;
	if (x < size_x)
		strategy->enemy_quater |= QUATER_1_X;
	else if (x < (size_x * 2))
		strategy->enemy_quater |= QUATER_2_X;
	else if (x < (size_x * 3 ))
		strategy->enemy_quater |= QUATER_3_X;
	else
		strategy->enemy_quater |= QUATER_4_X;
	if (y < size_y)
		strategy->enemy_quater |= QUATER_1_Y;
	else if (y < (size_y * 2))
		strategy->enemy_quater |= QUATER_2_Y;
	else if (y < (size_y * 3 ))
		strategy->enemy_quater |= QUATER_3_Y;		
	else
		strategy->enemy_quater |= QUATER_4_Y;
}