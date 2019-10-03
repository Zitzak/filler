void	lauris(t_test *result)
{
	int		i;

	i = 0;
	result->me |= P1;
	dprintf(result->fd1, "map00 -p1 mgross -p2 lauris\n----------------------------\n");
	while (i < 5)
	{
		test(MAP00_MGROSS_LAURIS);
		read_function(result);
		print_test_scores(result, i);
		i++;
	}
	print_player_score(result);

	i = 0;
	dprintf(result->fd1, "map01 -p1 mgross -p2 lauris\n----------------------------\n");
	while (i < 5)
	{
		test(MAP01_MGROSS_LAURIS);
		read_function(result);
		print_test_scores(result, i);
		i++;
	}
	print_player_score(result);

	i = 0;
	dprintf(result->fd1, "map02 -p1 mgross -p2 lauris\n----------------------------\n");
	while (i < 5)
	{
		test(MAP02_MGROSS_LAURIS);
		read_function(result);
		print_test_scores(result, i);
		i++;
	}
	print_player_score(result);

	result->me = P2;
	i = 0;
	dprintf(result->fd1, "map00 -p1 lauris -p2 mgross\n----------------------------\n");
	while (i < 5)
	{
		test(MAP00_LAURIS_MGROSS);
		read_function(result);
		print_test_scores(result, i);
		i++;
	}
	print_player_score(result);

	i = 0;
	dprintf(result->fd1, "map01 -p1 lauris -p2 mgross\n----------------------------\n");
	while (i < 5)
	{
		test(MAP01_LAURIS_MGROSS);
		read_function(result);
		print_test_scores(result, i);
		i++;
	}
	print_player_score(result);

	i = 0;
	dprintf(result->fd1, "map02 -p1 lauris -p2 mgross\n----------------------------\n");
	while (i < 5)
	{
		test(MAP02_LAURIS_MGROSS);
		read_function(result);
		print_test_scores(result, i);
		i++;
	}
	print_player_score(result);
}

# define MAP00_MGROSS_LAURIS "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/lskrauci.filler > ./test_runs/filler.txt"
# define MAP01_MGROSS_LAURIS "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/lskrauci.filler > ./test_runs/filler.txt"
# define MAP02_MGROSS_LAURIS "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/lskrauci.filler > ./test_runs/filler.txt"
# define MAP00_LAURIS_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/lskrauci.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
# define MAP01_LAURIS_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/lskrauci.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
# define MAP02_LAURIS_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/lskrauci.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"