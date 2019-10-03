/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_pos.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 13:14:51 by mgross         #+#    #+#                */
/*   Updated: 2019/10/03 15:23:41 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

int		getPosMap(t_test *result)
{
	int i;

	if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) != FLAG_A)
		i = 2;
	else if ((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) != FLAG_A)			
		i = 3;
	else if (((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) != FLAG_A) ||
			((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) == FLAG_A))
		i = 4;
	else if (((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) != FLAG_A) ||
			((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) == FLAG_A))
		i = 5;
	else if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) == FLAG_A)
		i = 6;
	else
		i = 7;
	return (i);
}

int		getPosPlayers(t_test *result)
{
	int		i;

	if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) != FLAG_N)
		i = 2;
	else if ((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) != FLAG_N)
		i = 3;
	else if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) == FLAG_N)
		i = 4;
	else
		i = 5;
	return (i);
}

int		getPosNum(t_test *result)
{
	int		i;

	if ((result->flags & FLAG_O) == FLAG_O)
		i = 3;
	else
		i = 2;
	return (i);
}

int		getPosP1(t_test *result)
{
	int i;

	if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) != FLAG_A)
		i = 4;
	else if ((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) != FLAG_A)
		i = 5;
	else if (((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) != FLAG_A) ||
			((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) == FLAG_A))
		i = 6;
	else if (((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) != FLAG_A) ||
			((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) == FLAG_A))
		i = 7;
	else if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) == FLAG_A)
		i = 8;
	else
		i = 9;
	return (i);	
}

int		getPosP2(t_test *result)
{
	int i;

	if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) != FLAG_A)
		i = 6;
	else if ((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) != FLAG_A)			
		i = 7;
	else if (((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) != FLAG_A) ||
			((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) == FLAG_A))
		i = 8;
	else if (((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) != FLAG_A) ||
			((result->flags & FLAG_O) == FLAG_O && (result->flags & FLAG_N) != FLAG_N && (result->flags & FLAG_A) == FLAG_A))
		i = 9;
	else if ((result->flags & FLAG_O) != FLAG_O && (result->flags & FLAG_N) == FLAG_N && (result->flags & FLAG_A) == FLAG_A)
		i = 10;
	else
		i = 11;
	return (i);	
}