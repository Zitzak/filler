// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   run_vm.c                                           :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: mgross <mgross@student.codam.nl>             +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2019/10/01 19:16:01 by mgross         #+#    #+#                */
// /*   Updated: 2019/10/02 17:33:45 by mgross        ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../incl/test_filler.h"

// int num = 10;

// void	abanlin(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 abanlin\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_ABANLIN);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 abanlin\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_ABANLIN);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 abanlin\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_ABANLIN);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 abanlin -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_ABANLIN_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 abanlin -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_ABANLIN_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 abanlin -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_ABANLIN_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	carli(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 carli\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_CARLI);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 carli\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_CARLI);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 carli\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_CARLI);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 carli -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_CARLI_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 carli -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_CARLI_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 carli -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_CARLI_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	champely(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 champley\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_CHAMPELY);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 champley\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_CHAMPELY);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 champley\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_CHAMPELY);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 champley -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_CHAMPELY_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 champley -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_CHAMPELY_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 champley -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_CHAMPELY_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	grati(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 grati\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_GRATI);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 grati\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_GRATI);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 grati\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_GRATI);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 grati -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_GRATI_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 grati -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_GRATI_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 grati -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_GRATI_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	hcao(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 hcao\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_HCAO);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 hcao\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_HCAO);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 hcao\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_HCAO);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 hcao -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_HCAO_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 hcao -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_HCAO_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 hcao -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_HCAO_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	superjeannot(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 superjeannot\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_SUPERJ);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 superjeannot\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_SUPERJ);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 superjeannot\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_SUPERJ);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 superjeannot -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_SUPERJ_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 superjeannot -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_SUPERJ_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 superjeannot -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_SUPERJ_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	anna(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 anna\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_ANNA);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 anna\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_ANNA);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 anna\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_ANNA);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 anna -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_ANNA_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 anna -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_ANNA_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 anna -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_ANNA_MGROSS);
		// read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	jamie(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 jamie\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_MGROSS_JAMIE);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 jamie\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_MGROSS_JAMIE);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 jamie\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_MGROSS_JAMIE);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 jamie -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP00_JAMIE_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 jamie -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP01_JAMIE_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 jamie -p2 mgross\n----------------------------\n");
// 	while (i < num)
// 	{
// 		test(MAP02_JAMIE_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }

// void	lauris(t_test *result)
// {
// 	int		i;

// 	i = 0;
// 	result->me |= P1;
// 	dprintf(result->fd1, "map00 -p1 mgross -p2 lauris\n----------------------------\n");
// 	while (i < 5)
// 	{
// 		test(MAP00_MGROSS_LAURIS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 mgross -p2 lauris\n----------------------------\n");
// 	while (i < 5)
// 	{
// 		test(MAP01_MGROSS_LAURIS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 mgross -p2 lauris\n----------------------------\n");
// 	while (i < 5)
// 	{
// 		test(MAP02_MGROSS_LAURIS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	result->me = P2;
// 	i = 0;
// 	dprintf(result->fd1, "map00 -p1 lauris -p2 mgross\n----------------------------\n");
// 	while (i < 5)
// 	{
// 		test(MAP00_LAURIS_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map01 -p1 lauris -p2 mgross\n----------------------------\n");
// 	while (i < 5)
// 	{
// 		test(MAP01_LAURIS_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);

// 	i = 0;
// 	dprintf(result->fd1, "map02 -p1 lauris -p2 mgross\n----------------------------\n");
// 	while (i < 5)
// 	{
// 		test(MAP02_LAURIS_MGROSS);
// 		read_function(result);
// 		print_test_scores(result, i);
// 		i++;
// 	}
// 	print_player_score(result);
// }
