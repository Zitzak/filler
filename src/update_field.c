/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_field.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 12:05:21 by mgross         #+#    #+#                */
/*   Updated: 2019/08/22 12:10:03 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		find_first_piece(t_info *filler)
{
	int		i;

	i = 0;
	while (filler->line[i] != '\0')
	{
		if (filler->line[i] == 'X' || filler->line[i] == 'O')
		{
			if (filler->line[i] == filler->me)
				filler->start = 1;
			else
			{
				filler->start = 0;
			}
			break;
		}
		i++;
	}
}

void		update_field(t_info *filler)
{
	int		x;

	x = 0;
	ft_get_next_line(0, &filler->line);
	while (x < filler->field_x)
	{
		ft_get_next_line(0, &filler->line);
		if (filler->start == -1)
			find_first_piece(filler);
		filler->field[x] = (ft_strchr(filler->line, ' ') + 1);
		x++;
		//zit hier nog de \n bij?
	}
	filler->field[x] = NULL;
}
