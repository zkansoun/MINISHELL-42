/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkansoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:07:38 by zkansoun          #+#    #+#             */
/*   Updated: 2022/05/10 12:31:49 by zkansoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(void)
{
	char *c;
	int fd[2];
	int id;

	pipe(fd);
	id = fork();
	if (id == 0)
	{
		char **argh;

		argh = malloc(3);
		argh[0] = "/bin/echo";
		argh[1] = "bonjour\n";
		argh[2] = NULL;
		dup2(fd[1], 1);
		execve("/bin/echo", argh, NULL);
	}
	else
	{
		char *s;

		s = malloc (7);
		dup2(fd[0],0);
		char **argj;
		argj = malloc (3);
		argj[0] = "/bin/cat";
		argj[1] = "-e";
		argj[2] = NULL;
		execve("/bin/cat", argj, NULL);

	}
}
