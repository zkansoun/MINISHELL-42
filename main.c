/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkansoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:07:54 by zkansoun          #+#    #+#             */
/*   Updated: 2022/05/10 14:02:50 by zkansoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int		i[3];

	temp = *seg;
	while (temp)
	{
		i[0] = -1;
		while (temp->tokens[++i[0]])
		{
			i[1] = -1;
			i[2] = 0;
			while (path[++i[1]])
			{
				if (!access(ft_strjoin(path[i[1]], temp->tokens[i[0]]), F_OK))
				{
					temp->cmd = temp->tokens[i[0]];
					i[2] = 1;
					break ;
				}
			}
			if (i[2] == 1)
				break ;
		}
		temp = temp->next;
	}
}

void	fill_input(t_seg **seg)
{
	t_seg	*temp;
	int		i;

	temp = *seg;
	while (temp)
	{
		i = -1;
		while (temp->tokens[++i])
		{
			if (temp->tokens[i][0] == '<')
			{
				if (temp->tokens[i][1] == '\0'
					|| (temp->tokens[i][1] == '<' && temp->tokens[i][2] == '\0'))
				{
					temp->input = temp->tokens[i + 1];
					break ;
				}
				else
				{
					if(temp->tokens[i][1] != '<')
						temp->input = temp->tokens[i] + 1;
					else
						temp->input = temp->tokens[i] + 2;
				}
			}
	}
		temp = temp->next;
	}
}

void	fill_output(t_seg **seg)
{
	t_seg	*temp;
	int		i;

	temp = *seg;
	while (temp)
	{
		i = -1;
		while (temp->tokens[++i])
		{
			if (temp->tokens[i][0] == '>')
			{
				if (temp->tokens[i][1] == '\0'
					|| (temp->tokens[i][1] == '>' && temp->tokens[i][2] == '\0'))
				{
					temp->output = temp->tokens[i + 1];
					break ;
				}
				else
				{
					if(temp->tokens[i][1] != '>')
						temp->output = temp->tokens[i] + 1;
					else
						temp->output = temp->tokens[i] + 2;
				}
			}
	}
		temp = temp->next;
	}
}

void	fill_flags(t_seg **seg)
{
	t_seg	*temp;
	int		i;

	temp = *seg;
	while (temp)
	{
		i = -1;
		while (temp->tokens[++i])
		{
			if (temp->tokens[i][0] == '-')
			{
				if (temp->flags == NULL)
					temp->flags = temp->tokens[i];
				else
				{
					temp->flags = ft_strjoin(temp->flags, " ");
					temp->flags = ft_strjoin(temp->flags, temp->tokens[i]);
				}
			}
		}
		temp = temp->next;
	}
}

void	prompt(char **path)
{
	t_seg	**seg;
	t_seg	*temp;
	char	**segments;
	char	*line;
	
	line = readline("<$");
	while (line)
	{
		segments = ft_split(line, '|');
		seg = take_tokens(segments);
		fill_cmd(seg, path);
		fill_input(seg);	
		fill_output(seg);
		fill_flags(seg);	
		temp = *seg;
		while (temp)
		{
			printf("flags: %s", temp->flags);
			temp = temp->next;
		}
		free (line);
		line = readline("<$");
	}



}

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	int		i;

	i = -1;
	path = ft_split(getenv("PATH"), ':');
	while (path[++i])
			path[i] = ft_strjoin(path[i], "/");
	prompt(path);
	}
