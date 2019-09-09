/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:44 by mgross         #+#    #+#                */
/*   Updated: 2019/09/09 16:16:20 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		init_var_update(t_str *strategy, t_pie *piece, t_hmap *heatmap)
{
	piece->first_star = 0;
	piece->last_star = 0;
	piece->lines_piece = 0;
	piece->first_line = -1;
	strategy->enemy_last_x = -1;
	strategy->enemy_curr_x = -1;
	heatmap->sum = 0;
}

void		update_game(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece)
{
	filler->nks = 5;//§
	// write(filler->fd, "n4:", 3);ft_putnbr_fd(heatmap->map[0][0], filler->fd);write(filler->fd, "\n", 1);
	init_var_update(strategy, piece, heatmap);
		write(filler->fd, "n3a:", 4);
	// write(filler->fd, "n5:", 3);ft_putnbr_fd(heatmap->map[0][0], filler->fd);write(filler->fd, "\n", 1);
	update_field(filler);
		write(filler->fd, "n3b:", 4);

	// write(filler->fd, "test2\n", 6);write(filler->fd, "n6:", 3);ft_putnbr_fd(heatmap->map[0][0], filler->fd);write(filler->fd, "\n", 1);
	update_enemy(filler, heatmap, strategy);//<<<<<<<<<<<<< Seg errror
		write(filler->fd, "n3c:", 4);
	
	update_strategy(filler, strategy);
		write(filler->fd, "n3d:", 4);
	// write(filler->fd, "test9\n", 6);
	update_heatmap(filler, heatmap, strategy);// segfault :(
		write(filler->fd, "n3e:", 4);	
	// write(filler->fd, "test10\n", 7);
	update_piece(filler, heatmap, piece);
		write(filler->fd, "n3f:", 4);
	// write(filler->fd, "test11\n", 7);

}
