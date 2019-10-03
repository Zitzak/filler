/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_filler.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 11:50:26 by mgross         #+#    #+#                */
/*   Updated: 2019/10/03 17:05:17 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

int		runTests(t_test *result)
{
	if ((result->flags & FLAG_O) == FLAG_O)
	{
		// result->output = strdup(WRITE);
		testsToOutput(result);
	}
	// else
	// 	testsToFiles(result);
	return (SUCCES);
}

int		getInput(t_test *result, int argc, char **argv)
{
	if(!get_args(result, argc, argv))
		return (ERROR);
	if(!getPaths(result))
		return (ERROR);
	return (SUCCES);
}

int		main(int argc, char **argv)
{
	t_test	*result;

	if (argc == 1)
		printUsage();
	else
	{
		result = (t_test*)malloc(sizeof(t_test));
		if (result == NULL)
			return (ERROR);
		init_var(result);
		if (!getInput(result, argc, argv))
			return (-1);
		if (!runTests(result))
			return (-1);
		//free struct etc
	}
	return (0);

}
