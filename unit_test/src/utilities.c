/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 10:05:12 by mgross         #+#    #+#                */
/*   Updated: 2019/10/03 17:25:55 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/test_filler.h"

void	printTest(char **array, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%s", array[i]);
		i++;
	}
}

void	pathToFile(t_test *result, int i)
{
	lsPathToFile(result->array[i]);
	readFileToBuf(result);
}

int		validateInput(char **array, char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if(!strstr(array[i], str))
			return (ERROR);
		i++;
	}
	return (SUCCES);
}


void	readFileToBuf(t_test *result)
{
	int		fd;
	int		ret;

	bzero(result->buf, (BUFFSIZE_TEST + 1));
	ret = 1;
	fd = open (READ, O_RDWR);
	ret = read (fd, result->buf, BUFFSIZE_TEST);
	result->buf[ret] = '\0';
}

void	lsPathToFile(char *str)
{
	char	cmd[BUFFSIZE_TEST];

	strcpy(cmd, "ls ");
	strcat(cmd, str);
	strcat(cmd, WRITE);
	system(cmd);
}

int		init_var(t_test *result)
{
	result->buf = (char*)malloc(sizeof(char) * (BUFFSIZE_TEST + 1));
	if (result->buf == NULL)
		return (ERROR);
	result->cmd = (char*)malloc(sizeof(char) * BUFFSIZE_TEST);
	if (!result->cmd)
		return (ERROR);
	result->fd1 = open("./test_results.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	result->me = 0;
	result->score_o = 0;
	result->score_x = 0;
	result->flags = 0;
	result->numRounds = 5;
	return (SUCCES);
}

int		get_flags(t_test *result, char *str)
{
	if (strstr(str, "-a") != NULL)
		result->flags |= FLAG_A;
	else if (strstr(str, "-n") != NULL)
		result->flags |= FLAG_N;
	else if (strstr(str, "-o") != NULL)
		result->flags |= FLAG_O;
	else if (strstr(str, "-f") != NULL)
		result->flags |= FLAG_LF;
	else if (strstr(str, "-F") != NULL)
		result->flags |= FLAG_F;
	else if (strstr(str, "-p1") != NULL)
		result->flags |= FLAG_P1;
	else if (strstr(str, "-p2") != NULL)
		result->flags |= FLAG_P2;
	if ((result->flags & FLAG_A) == FLAG_A && (result->flags & FLAG_P2) == FLAG_P2 && (result->flags & FLAG_P1) == FLAG_P1)
	{
		printf("Error: Invald flags: -a together with -p1 and -p2\n");
		return (ERROR);
	}
	if ((result->flags & FLAG_F) == FLAG_F && (result->flags & FLAG_LF) == FLAG_LF)
	{
		printf("Error: Invalid flags: -f with -F\n");		
		return (ERROR);
	}
	else
		return (SUCCES);
}

void	systemCall(t_test *result)
{
	system(result->cmd);
}
