/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:37 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 15:47:48 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		create_field(t_info *filler, t_hmap *heatmap)
{
	int		i;

	i = 0;
	ft_get_next_line(0, &filler->line);
	while (ft_isdigit(*filler->line) != 1)
		filler->line++;
	filler->field_x = ft_atoi(&(*filler->line));
	heatmap->size_x = filler->field_x;
	while (ft_isdigit(*filler->line) == 1)
		filler->line++;
	filler->line++;
	filler->field_y = ft_atoi(&(*filler->line));
	heatmap->size_y = filler->field_y;
	if (ft_mem_array_alloc(&filler->field, filler->field_x) == -1)
		return (-1);
	filler->field[filler->field_x] = NULL;
	return (0);
}

int		create_heatmap(t_hmap *heatmap)
{
	int		x;
	int		y;

	x = 0;
	heatmap->map = (int**)malloc(sizeof(int*) * heatmap->size_x);
	if (heatmap->map == NULL)
		return (-1);
	while (x < heatmap->size_x)
	{
		y = 0;
		heatmap->map[x] = (int*)malloc(sizeof(int) * heatmap->size_y);
		if (heatmap->map[x] == NULL)
			return (-1);
		while(y < heatmap->size_y)
		{
			heatmap->map[x][y] = 0;
			y++;
		}
		x++;
	}
	return (0);
}

void		get_token(t_info *filler)
{
	ft_get_next_line(0, &filler->line);
	filler->line = ft_strstr((const char*)filler->line, (const char*)"p1");
	if (filler->line == NULL)
	{
		filler->me = 'X';
		filler->other = 'O';
	}
	else
	{
		filler->me = 'O';
		filler->other = 'X';
	}
}

void		first_input(t_info *filler, t_hmap *heatmap)
{
	filler->start = -1;// deze moet nog ergens anders
	heatmap->enemy_num = 0;// moet nog weg hier
	get_token(filler);
	if (create_field(filler, heatmap) == -1)
		error (filler, heatmap);
	if (create_heatmap(heatmap) == -1)
		error (filler, heatmap);
}
