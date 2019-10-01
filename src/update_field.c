/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_field.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 12:05:21 by mgross         #+#    #+#                */
/*   Updated: 2019/09/30 15:58:28 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		find_first_piece(t_fie *filler, t_hmap *heatmap)
{
	int		i;

	i = 0;
	while (filler->line[i] != '\0')
	{
		if (filler->line[i] == 'X' || filler->line[i] == 'O')
		{
			if (filler->line[i] == filler->me)
			{
				filler->start |= START_TOP;
				heatmap->start = 1; // deze moet nog define
			}
			else
			{
				filler->start |= START_BOTT;
				heatmap->start = 0;
			}
			break ;
		}
		i++;
	}
}

void		update_field(t_fie *filler, t_hmap *heatmap)
{
	int		x;

	x = 0;
	ft_get_next_line(0, &filler->line);
	if (*filler->line != ' ')
		ft_get_next_line(0, &filler->line);
	while (x < filler->field_x)
	{
		ft_get_next_line(0, &filler->line);
		if ((filler->start & START_BOTT) != START_BOTT && (filler->start & START_TOP) != START_TOP)
			find_first_piece(filler, heatmap);
		filler->field[x] = ft_strcpy(filler->field[x], (filler->line + 4));
		ft_strdel(&filler->line);
		x++;
	}
}
