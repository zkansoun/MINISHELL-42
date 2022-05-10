/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkansoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:48:56 by zkansoun          #+#    #+#             */
/*   Updated: 2022/05/10 11:56:36 by zkansoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int main(int argc, char ** argvv, char **envp)
{
	char **argv;

	argv = malloc (3 * sizeof(char *));
	argv[0] = "/bin/ls";
	argv[1] = " ./ > /Users/zkansoun/cursus_42/Dossier_INIT/minishell/aaa";
	argv[2] = NULL;

	execve(argv[0], argv, envp);
}
