/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkansoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:07:38 by zkansoun          #+#    #+#             */
/*   Updated: 2022/05/10 12:18:48 by zkansoun         ###   ########.fr       */
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
		//close (fd[0]);
		c = "zahraa";
		dup2(fd[1], 1);
		printf("%s\n", c);
		//close (fd[1]);
	}
	else
	{
		char *s;

		//close(fd[1]);
		s = malloc (7);
		read (fd[0], s, 7);
		printf("iii%s", s);
		//close (fd[0]);

	}
}
