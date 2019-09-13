/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 18:06:32 by mgross         #+#    #+#                */
/*   Updated: 2019/09/13 16:44:22 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		get_offset(t_fie *filler, t_pie *piece)
{
	int		x;
	int		ret;

	x = 0;
	while (x < piece->piece_x)
	{
		ret = 0;
		ft_get_next_line(0, &filler->line);
		ret = ft_nchar(filler->line, '*');
		if (ret > 0)
		{
			piece->lines_piece = piece->lines_piece + 1;
			if (ret < piece->first_star || piece->first_star == 0)
				piece->first_star = ret;
			ret = ft_strlen(filler->line);
			while (filler->line[ret - 1] != '*')
				ret--;
			if (ret > piece->last_star)
				piece->last_star = ret;
		}
		piece->temp_piece[x] = ft_strcpy(piece->temp_piece[x], filler->line);
		ft_strdel(&filler->line);
		x++;
	}
	piece->collums_piece = piece->last_star - piece->first_star + 1;
}

void		copy_piece(t_pie *piece, int x, int first_star, int i)
{
	int		y;
	int		temp;

	y = 0;
	temp = first_star;
	while (temp > piece->first_star)
	{
		piece->piece[x][y] = '.';
		y++;
		temp--;
	}
	while (first_star <= piece->last_star)
	{
		piece->piece[x][y] = piece->temp_piece[i][first_star - 1];
		y++;
		first_star++;
	}
	piece->piece[x][y] = '\0';
}

int			create_piece(t_pie *piece)
{
	int		x;
	int		i;
	int		first_star;

	i = 0;
	x = 0;
	piece->piece = (char**)ft_mem_array_alloc(piece->lines_piece, sizeof(char*)
	* piece->lines_piece, sizeof(char) * (piece->collums_piece + 1));
	if (piece->piece == NULL)
		return (-1);
	while (x < piece->lines_piece)
	{
		first_star = ft_nchar(piece->temp_piece[i], '*');
		if (first_star != 0)
		{
			if (piece->first_line == -1)
				piece->first_line = i + 1;
			copy_piece(piece, x, first_star, i);
			x++;
		}
		i++;
	}
	return (0);
}

int			get_size_piece(t_fie *filler, t_pie *piece)
{
	char	*temp;
	int		x;

	x = 0;
	ft_get_next_line(0, &filler->line);
	temp = filler->line;
	while (ft_isdigit(*temp) != 1)
		temp++;
	piece->piece_x = ft_atoi(&(*temp));
	while (ft_isdigit(*temp) == 1)
		temp++;
	temp++;
	piece->piece_y = ft_atoi(&(*temp));
	free(filler->line);
	piece->temp_piece = (char**)ft_mem_array_alloc(piece->piece_x, sizeof(char*)
	* piece->piece_x, sizeof(char) * (piece->piece_y + 1));
	if (piece->temp_piece == NULL)
		return (-1);
	return (0);
}

int			update_piece(t_fie *filler, t_pie *piece)
{
	if (get_size_piece(filler, piece) == -1)
		return (-1);
	get_offset(filler, piece);
	if (create_piece(piece) == -1)
		return (-1);
	return (0);
}
