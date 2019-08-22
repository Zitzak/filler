/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:57 by mgross         #+#    #+#                */
/*   Updated: 2019/08/22 11:37:10 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	print_test(t_info *filler, t_hmap *heatmap)
{
	int		i;
	int		y;

	i = 0;
	ft_dprintf(filler->fd, "me:    %c\nother: %c\n", filler->me, filler->other);// <------
	ft_dprintf(filler->fd, "\nField: %d - %d\n", filler->field_x, filler->field_y);
	while (filler->field[i] != NULL)
	{
		ft_dprintf(filler->fd, "[%s]\n", filler->field[i]);
		i++;
	}
	i = 0;
	ft_dprintf(filler->fd, "\n[first_star: %d]\n[last_star: %d]\n[num lines: %d]\n[num collums: %d]\n[start: %d]\n",
		filler->first_star, filler->last_star, filler->lines_piece, filler->collums_piece, filler->start);
	ft_dprintf(filler->fd, "\ntemp_piece: %d - %d\n", filler->piece_x, filler->piece_y);
	while (filler->temp_piece[i] != NULL)//
	{
		ft_dprintf(filler->fd, "[%s]\n", filler->temp_piece[i]);//
		i++;
	}
	i = 0;
	ft_dprintf(filler->fd, "\nPiece cut\n");
	while (filler->piece[i] != NULL)
	{
		ft_dprintf(filler->fd, "[%s]\n", filler->piece[i]);
		i++;
	}
	i = 0;
	// free(heatmap);
	ft_dprintf(filler->fd, "enemy_num: %i\ncurrent_piecer[%i][%i]\nlast_piece[%i][%i]\n", heatmap->enemy_num,
		heatmap->current_piece_x, heatmap->current_piece_y, heatmap->last_piece_x, heatmap->last_piece_y);
	ft_dprintf(filler->fd, "heatmap\n");
	while(i < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			ft_dprintf(filler->fd, "%i", heatmap->map[i][y]);
			y++;
		}
		ft_dprintf(filler->fd, "\n");
		i++;
	}
}

void		error(t_info *filler, t_hmap *heatmap)
{
	//deze moet nog aangepast worden om alles te freeen
	free(heatmap);
	free(filler);
	exit (-1);
}

int		main(void)//moet errors handelen van malloc
{
	t_info			*filler;
	t_hmap			*heatmap;

	filler = malloc(sizeof(t_info));
	heatmap = malloc(sizeof(t_hmap));
	filler->fd = open("../input.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);// <-----
	first_call(filler, heatmap);
	main_control(filler, heatmap);
	return (0);
}