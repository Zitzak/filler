/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:37 by mgross         #+#    #+#                */
/*   Updated: 2019/09/09 12:02:03 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		create_field(t_fie *filler, t_hmap *heatmap)
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
	// ft_putnbr_fd(filler->field_x, filler->fd);write(filler->fd, "- x\n", 4);ft_putnbr_fd(filler->field_y, filler->fd);write(filler->fd, "- y\n", 4);
	if (ft_mem_array_alloc(&filler->field, filler->field_x) == -1)
		return (-1);
	return (0);
}

int		create_heatmap(t_hmap *heatmap, t_fie *filler)
{
	int		x;
	int		y;

	x = 0;
	filler->nks = 5;//
	// write(filler->fd, "x:", 2);ft_putnbr_fd(heatmap->size_x, filler->fd);write(filler->fd, "\ny:", 3);ft_putnbr_fd(heatmap->size_y, filler->fd);write(filler->fd, "\n", 1);
	heatmap->map = (int**)malloc(sizeof(int*) * heatmap->size_x);
	if (heatmap->map == NULL)
	{
		// write(filler->fd, "test12\n", 7);
		return (-1);
	}
	while (x < heatmap->size_x)
	{
		y = 0;
		heatmap->map[x] = (int*)malloc(sizeof(int) * heatmap->size_y);
		if (heatmap->map[x] == NULL)
		{
			// write(filler->fd, "test12\n", 7);
			return (-1);
		}
		while(y < heatmap->size_y)
		{
			heatmap->map[x][y] = 0;
			y++;
		}
		x++;
	}
	// ft_putnbr_fd(heatmap->map[0][0], filler->fd);write(filler->fd, "\n", 1);
	return (0);
}

void		get_token(t_fie *filler)
{
	ft_get_next_line(0, &filler->line);
	filler->line = ft_strstr((const char*)filler->line, (const char*)"p1");
	if (filler->line == NULL)
	{
		filler->me = 'X';
		filler->enemy = 'O';
	}
	else
	{
		filler->me = 'O';
		filler->enemy = 'X';
	}
}

void		init_var_first_input(t_fie *filler, t_hmap *heatmap)
{
	filler->start = -1;
	heatmap->enemy_num = -1;
}

void		first_input(t_fie *filler, t_hmap *heatmap)
{
	init_var_first_input(filler, heatmap);
	get_token(filler);
	if (create_field(filler, heatmap) == -1)
		error (filler, heatmap);
	if (create_heatmap(heatmap, filler) == -1)
		error (filler, heatmap);
	// write(filler->fd, "n1:", 3);ft_putnbr_fd(heatmap->map[0][0], filler->fd);
}
