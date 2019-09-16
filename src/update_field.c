/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_field.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 12:05:21 by mgross         #+#    #+#                */
/*   Updated: 2019/09/16 16:38:56 by mgross        ########   odam.nl         */
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
				filler->start = 1;
				heatmap->start = 1;
			}
			else
			{
				filler->start = 0;
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
		if (filler->start == -1)
			find_first_piece(filler, heatmap);
		filler->field[x] = ft_strcpy(filler->field[x], (filler->line + 4));
		ft_strdel(&filler->line);
		x++;
	}
}
