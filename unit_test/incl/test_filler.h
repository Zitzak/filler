/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_filler.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 14:01:13 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 16:51:10 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FILLER_H
# define TEST_FILLER_H

// #include "../../incl/filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libc.h>
#include <ctype.h>
#include <unistd.h>


// # define MAP00_MGROSS_ABANLIN "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/abanlin.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_ABANLIN "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/abanlin.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_ABANLIN "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/abanlin.filler > ./test_runs/filler.txt"
// # define MAP00_ABANLIN_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/abanlin.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_ABANLIN_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/abanlin.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_ABANLIN_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/abanlin.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_CARLI "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/carli.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_CARLI "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/carli.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_CARLI "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/carli.filler > ./test_runs/filler.txt"
// # define MAP00_CARLI_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/carli.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_CARLI_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/carli.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_CARLI_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/carli.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_CHAMPELY "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/champely.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_CHAMPELY "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/champely.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_CHAMPELY "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/champely.filler > ./test_runs/filler.txt"
// # define MAP00_CHAMPELY_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/champely.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_CHAMPELY_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/champely.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_CHAMPELY_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/champely.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_GRATI "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/grati.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_GRATI "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/grati.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_GRATI "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/grati.filler > ./test_runs/filler.txt"
// # define MAP00_GRATI_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/grati.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_GRATI_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/grati.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_GRATI_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/grati.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_HCAO "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/hcao.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_HCAO "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/hcao.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_HCAO "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/hcao.filler > ./test_runs/filler.txt"
// # define MAP00_HCAO_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/hcao.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_HCAO_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/hcao.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_HCAO_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/hcao.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_SUPERJ "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/superjeannot.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_SUPERJ "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/superjeannot.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_SUPERJ "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/superjeannot.filler > ./test_runs/filler.txt"
// # define MAP00_SUPERJ_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/superjeannot.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_SUPERJ_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/superjeannot.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_SUPERJ_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/superjeannot.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_ANNA "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/ayundina.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_ANNA "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/ayundina.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_ANNA "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/ayundina.filler > ./test_runs/filler.txt"
// # define MAP00_ANNA_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/ayundina.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_ANNA_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/ayundina.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_ANNA_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/ayundina.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_JAMIE "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/wvan-ees.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_JAMIE "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/wvan-ees.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_JAMIE "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/wvan-ees.filler > ./test_runs/filler.txt"
// # define MAP00_JAMIE_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/wvan-ees.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_JAMIE_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/wvan-ees.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_JAMIE_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/wvan-ees.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP00_MGROSS_LAURIS "../filler_vm -f ../maps/map00 -p1 ../players/mgross.filler -p2 ../players/lskrauci.filler > ./test_runs/filler.txt"
// # define MAP01_MGROSS_LAURIS "../filler_vm -f ../maps/map01 -p1 ../players/mgross.filler -p2 ../players/lskrauci.filler > ./test_runs/filler.txt"
// # define MAP02_MGROSS_LAURIS "../filler_vm -f ../maps/map02 -p1 ../players/mgross.filler -p2 ../players/lskrauci.filler > ./test_runs/filler.txt"
// # define MAP00_LAURIS_MGROSS "../filler_vm -f ../maps/map00 -p1 ../players/lskrauci.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP01_LAURIS_MGROSS "../filler_vm -f ../maps/map01 -p1 ../players/lskrauci.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"
// # define MAP02_LAURIS_MGROSS "../filler_vm -f ../maps/map02 -p1 ../players/lskrauci.filler -p2 ../players/mgross.filler > ./test_runs/filler.txt"

# define SMALL			0
# define MEDIUM			1
# define LARGE			2
# define F				" -f "
# define P1				" -p1 "
# define P2				" -p2 "
# define STDOUT 		" > ./resources/read.txt"
# define WRITE			 " > ./resources/read.txt"
# define READ			"./resources/read.txt"
# define PLAYERS		1
# define MAPS			2
# define BUFFSIZE_TEST 	1024
# define ERROR			0
# define SUCCES			1
# define FLAG_A			(1 << 0)
# define FLAG_O			(1 << 1)
# define FLAG_LF		(1 << 2)
# define FLAG_F			(1 << 3)
# define FLAG_P1		(1 << 4)
# define FLAG_P2		(1 << 5)
# define FLAG_N			(1 << 6)
# define FLAG_P1W		(1 << 7)
# define FLAG_P2W		(1 << 8)

typedef struct	s_test
{
	char	*output;
	int		numPlayers;
	int		numRounds;
	int		numMaps;
	char	*filler_vm;
	char	**players;
	char	**maps;
	char	*singleMap;
	char	*path_players;
	char	*path_maps;
	char	*player1;
	char	*player2;
	int		flags;
	int		me;
	char	*buf;
	int		round;
	int		fd1;
	// int		fd;
	int		x;
	int		o;
	int		score_x;
	int		score_o;
	char	**array;
	char	*cmd;
	int		size_print;
}				t_test;

void	lsPathToFile(char *str);
int		init_var(t_test *result);
// void	run_tests(t_test *result);
// void	abanlin(t_test *result);
// void	carli(t_test *result);
// void	champely(t_test *result);
// void	grati(t_test *result);
// void	hcao(t_test *result);
// void	superjeannot(t_test *result);
// void	anna(t_test *result);
// void	jamie(t_test *result);
// void	lauris(t_test *result);
// void	test(char *str);
void	print_player_score(t_test *result);
int		get_args(t_test *result, int argc, char **argv);
void	print_test_scores(t_test *result, int n);
void	read_function(t_test *result);
void	countScore(t_test *result, char *str);
int		getPathPlayers(t_test *result);
int		get_all_maps(t_test *result);
void	printUsage();
int		getPaths(t_test *result);
int		get_flags(t_test *result, char *str);
void	readFileToBuf(t_test *result);
int		getPathFiller_vm(t_test *result);
int		getNumLines(t_test *result, char *str);
int		bufToArray(t_test *result, int type, int size, char *path);
int		strlen_newline(char *buf);
int		getNumRounds(t_test *result);
int		getPosMap(t_test *result);
int		getPathMaps(t_test *result);
void	printTest(char **array, int size);//
int		validateInput(char **array, char *str, int size);
int		getPosPlayers(t_test *result);
int		getPosNum(t_test *result);
int		getPosSingleMap(t_test *result);
void	pathToFile(t_test *result, int i);
int		getPathSingleMap(t_test *result);
int		getPosP1(t_test *result);
int		getPosP2(t_test *result);
int		getPathP1(t_test *result);
int		getPathP2(t_test *result);
int		getInput(t_test *result, int argc, char **argv);
int		runTests(t_test *result);
void	testsToOutput(t_test *result);
void	systemCall(t_test *result);
int		addStringsForCommand(t_test *result, char *map, char *enemy, char *output);
void	printP1W(t_test *result, char * map, char *enemy, int round);
void	printP2W(t_test *result, char * map, char *enemy, int round);
void	printRoundScore(t_test *result, char * map, char *enemy, int round);
void	printMatchUp(t_test *result, char *enemy);
void	printMapChange(t_test *result);
void	allPlayerOneMap(t_test *result);




#endif