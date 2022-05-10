/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkansoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:07:54 by zkansoun          #+#    #+#             */
/*   Updated: 2022/05/10 09:51:03 by zkansoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	add_list(t_seg **seg)
{
	t_seg	*temp;
	t_seg	*new;

	temp = *seg;
	while (temp->next != NULL)
		temp = temp->next;
	new = malloc(sizeof(t_seg));
	new->next = NULL;
	temp->next = new;
}

t_seg	**take_tokens(char **segments)
{
	t_seg	**seg;
	t_seg	*temp;
	int		i;

	i = 0;
	seg = malloc(sizeof(t_seg *));
	*seg = malloc(sizeof(t_seg));
	(*seg)->next = NULL;
	temp = *seg;
	while (segments[i])
	{
		temp->tokens = ft_split(segments[i], ' ');
		if (segments[i + 1])
			add_list(seg);
		temp = temp->next;
		i++;
	}
	return (seg);
}

void	fill_cmd(t_seg **seg, char **path)
{
	t_seg	*temp;
	int		i;
	int		res;
	int		j;

	temp = *seg;
	while (temp)
	{
		i = 0;
		while (temp->tokens[i])
		{
			j = 0;
			res = 0;
			while (path[j])
			{
				if (access(ft_strjoin(path[j], temp->tokens[i]), F_OK) == 0)
				{
					temp->cmd = temp->tokens[i];
					res = 1;
					break ;
				}
				j++;
			}
			if (res == 1)
				break ;
			i++;
		}
		temp = temp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**path;
	t_seg	**seg;
	t_seg	*temp;
	char	**segments;
	int		i;

	i = -1;
	line = readline("<$");
	path = ft_split(getenv("PATH"), ':');
	while (path[++i])
			path[i] = ft_strjoin(path[i], "/");
	while (line)
	{
		segments = ft_split(line, '|');
		seg =  take_tokens(segments);
		fill_cmd(seg, path);
		i = 0;
		temp = *seg;
		while (temp)
		{
			printf("%s\n", temp->cmd);
			temp = temp->next;
		}
		free (line);
		line = readline("<$");
	}
}
