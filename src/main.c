/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:57 by mgross         #+#    #+#                */
/*   Updated: 2019/09/13 18:00:50 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	print_test(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece)
{
	int		i;


	
	// <<<<<<<<<<<<<<<<<<<<<<<< FREE NOT NEEDED STRUCT >>>>>>>>>>>>>>>>>>>>>
	// free(strategy);
	// free(filler);
	// free(heatmap);
	// free(piece);
	filler->nks = 5;
	piece->nks = 5;
	heatmap->nks = 5;
	strategy->nks = 5;


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
	i = 0;
	ft_dprintf(filler->fd, "\ntemp_piece: %d - %d\n", piece->piece_x, piece->piece_y);
	while (i < piece->piece_x)//
	{
		ft_dprintf(filler->fd, "[%s]\n", piece->temp_piece[i]);//
		i++;
	}


	//<<<<<<<<<<<<<<<<<<<<<<< VAR FOR CUT PIECE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// ft_dprintf(filler->fd, "\n[first_star: %d]\n[last_star: %d]\n[num lines: %d]\n[num collums: %d]\n[first_line: %d]\n[start: %d]\n",
		// piece->first_star, piece->last_star, piece->lines_piece, piece->collums_piece, piece->first_line, filler->start);


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
	// ft_dprintf(filler->fd, "cordinate_placement_piece: [%i][%i]\nsum_heatmap: %i\n", heatmap->x, heatmap->y, heatmap->sum);
	// if (piece->first_line != 1)
	// 	heatmap->x = heatmap->x - (piece->first_line - 1);
	// if (piece->first_star != 1)
	// 	heatmap->y = heatmap->y - (piece->first_star - 1);
	// ft_dprintf(filler->fd, "final x: %i - final y: %i\n", heatmap->x, heatmap->y);
}

void		error(t_fie *filler, t_hmap *heatmap)
{
	//deze moet nog aangepast worden om alles te freeen
	//piece moet ook nog gefreed worden

	free(heatmap);
	free(filler);
	exit (-1);
}

int			init_struct(t_fie **filler, t_hmap **heatmap, t_str **strategy, t_pie **piece)
{
	*filler = (t_fie*)ft_memalloc(sizeof(t_fie));
	if (filler == NULL)
		return (-1);
	*heatmap = (t_hmap*)ft_memalloc(sizeof(t_hmap));
	if (heatmap == NULL)
	{
		free(filler);
		return (-1);
	}
	*piece = (t_pie*)ft_memalloc(sizeof(t_pie));
	if (piece == NULL)
	{
		free(filler);
		free(heatmap);
		return (-1);
	}
	*strategy = (t_str*)ft_memalloc(sizeof(t_str));
	if (strategy == NULL)
	{
		free(filler);
		free(heatmap);
		free(piece);		
		return (-1);
	}
	return (0);
}

int			main(void)//moet errors handelen van malloc
{
	t_fie			*filler;
	t_hmap			*heatmap;
	t_str			*strategy;
	t_pie			*piece;


	if (init_struct(&filler, &heatmap, &strategy, &piece) == -1)
		return (-1);
	filler->fd = open("../input.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);// <-----
	if (first_input(filler, heatmap, strategy) == -1)
		return (-1); // <<<<<<<<free management
	if (main_control(filler, heatmap, strategy, piece) == -1)
		return (-1);
	// else
	// {
	// 	free structs
	// }
	return (0);
}