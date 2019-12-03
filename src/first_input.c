/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:37 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:47:42 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static int			create_field(t_fie *filler, t_hmap *heatmap)
{
	int		x;
	char	*temp;

	x = 0;
	ft_get_next_line(0, &filler->line);
	temp = filler->line;
	while (ft_isdigit(*temp) != 1)
		temp++;
	filler->field_x = ft_atoi(&(*temp));
	heatmap->size_x = filler->field_x;
	while (ft_isdigit(*temp) == 1)
		temp++;
	temp++;
	filler->field_y = ft_atoi(&(*temp));
	heatmap->size_y = filler->field_y;
	filler->field = (char**)ft_mem_array_alloc(filler->field_x,
	sizeof(char*) * filler->field_x, sizeof(char) * (filler->field_y + 1));
	free_line(filler);
	if (filler->field == NULL)
		return (-1);
	return (0);
}

static int			create_heatmap(t_hmap *heatmap)
{
	int		x;

	x = 0;
	heatmap->map = (int**)ft_mem_array_alloc(heatmap->size_x, (sizeof(int*)
	* heatmap->size_x), (sizeof(int) * heatmap->size_y));
	if (heatmap->map == NULL)
	{
		return (-1);
	}
	return (0);
}

static void			get_token(t_fie *filler)
{
	char	*temp;

	ft_get_next_line(0, &filler->line);
	temp = ft_strstr((const char*)filler->line, (const char*)"p1");
	if (temp == NULL)
	{
		filler->me = 'X';
		filler->enemy = 'O';
	}
	else
	{
		filler->me = 'O';
		filler->enemy = 'X';
	}
	free_line(filler);
}

static void			init_var_first_input(t_fie *filler, t_hmap *heatmap)
{
	filler->start = 0;
	heatmap->enemy_num = -1;
	heatmap->x = 0;
	heatmap->y = 0;
}

int					first_input(t_fie *filler, t_hmap *heatmap)
{
	get_token(filler);
	if (create_field(filler, heatmap) == -1)
		return (-1);
	if (create_heatmap(heatmap) == -1)
		return (-1);
	init_var_first_input(filler, heatmap);
	return (0);
}
