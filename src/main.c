/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:57 by mgross         #+#    #+#                */
/*   Updated: 2019/08/28 15:47:25 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	print_test(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece)
{
	int		i;


	// <<<<<<<<<<<<<<<<<<<<<<<< FREE NOT NEEDED STRUCT >>>>>>>>>>>>>>>>>>>>>
	free(strategy);
	// free(heatmap);
	// free(piece);


	//<<<<<<<<<<<<<<<<<<<<<<< FIELD >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	i = 0;
	ft_dprintf(filler->fd, "me:    %c\nenemy: %c\n", filler->me, filler->enemy);// <------
	ft_dprintf(filler->fd, "\nField: %d - %d\n", filler->field_x, filler->field_y);
	while (i < filler->field_x)
	{
		ft_dprintf(filler->fd, "[%s]\n", filler->field[i]);
		i++;
	}


	//<<<<<<<<<<<<<<<<<<<<< HEATMAP >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	i = 0;
	ft_dprintf(filler->fd, "heatmap\n");
	int		y;
	while(i < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (heatmap->map[i][y] < 0)
				ft_dprintf(filler->fd, " %i", heatmap->map[i][y]);
			else if (heatmap->map[i][y] > -1 && heatmap->map[i][y] < 10)
			{
				ft_dprintf(filler->fd, "  %i", heatmap->map[i][y]);
			}
			else
			{
				ft_dprintf(filler->fd, " %i", heatmap->map[i][y]);
			}
			y++;
		}
		ft_dprintf(filler->fd, "\n");
		i++;
	}


	//<<<<<<<<<<<<<<<<<<<<<<< RAW PIECE  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// // i = 0;
	// ft_dprintf(filler->fd, "\ntemp_piece: %d - %d\n", piece->piece_x, piece->piece_y);
	// while (i < piece->piece_x)//
	// {
	// 	ft_dprintf(filler->fd, "[%s]\n", piece->temp_piece[i]);//
	// 	i++;
	// }


	//<<<<<<<<<<<<<<<<<<<<<<< VAR FOR CUT PIECE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// ft_dprintf(filler->fd, "\n[first_star: %d]\n[last_star: %d]\n[num lines: %d]\n[num collums: %d]\n[first_line: %d]\n[start: %d]\n",
	// 	piece->first_star, piece->last_star, piece->lines_piece, piece->collums_piece, piece->first_line, filler->start);


	//<<<<<<<<<<<<<<<<<<<<<<CUT PIECE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	i = 0;
	ft_dprintf(filler->fd, "\nPiece cut\n");
	while (i < piece->lines_piece)
	{
		ft_dprintf(filler->fd, "[%s]\n", piece->piece[i]);
		i++;
	}
	

	//<<<<<<<<<<<<<<<<<<<<<<<VAR STRATEGY STRUYCT >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// i = 0;
	// ft_dprintf(filler->fd, "enemy_num: %i\ncurrent_piece[%i][%i]\nlast_piece[%i][%i]\n", heatmap->enemy_num,
	// 	strategy->enemy_curr_x, strategy->enemy_curr_y, strategy->enemy_last_x, strategy->enemy_last_y);
	// ft_dprintf(filler->fd, "my_furthest_x: %i\nmy_curr_y: %i\nenemy_furthest_x: %i\nenemy_furthest_y: %i\n",
	//  strategy->my_furthest_x, strategy->my_furthest_y, strategy->enemy_furthest_x, strategy->enemy_furthest_y);
	
	
	//<<<<<<<<<<<<<<<<<<<<< VAR PLACEMEENT PIECE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	ft_dprintf(filler->fd, "cordinate_placement_piece: [%i][%i]\nsum_heatmap: %i\n", heatmap->x, heatmap->y, heatmap->sum);
	
}

void		error(t_fie *filler, t_hmap *heatmap)
{
	//deze moet nog aangepast worden om alles te freeen
	//piece moet ook nog gefreed worden
	free(heatmap);
	free(filler);
	exit (-1);
}

int		main(void)//moet errors handelen van malloc
{
	t_fie			*filler;
	t_hmap			*heatmap;

	filler = (t_fie*)malloc(sizeof(t_fie));// error if NULL
	heatmap = (t_hmap*)malloc(sizeof(t_hmap));// error if NULL
	filler->fd = open("../input.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);// <-----
	first_input(filler, heatmap);
	main_control(filler, heatmap);
	return (0);
}