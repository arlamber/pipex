/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:11:24 by arlamber          #+#    #+#             */
/*   Updated: 2023/04/08 16:08:46 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_chemin(char *av, char **cmd, char **envp)
{
	char	c;

	c = '/';
	if (ft_strchrsl(av, c) == 1)
	{
		if ((access(av, F_OK)) == 0)
		{
			execve(av, cmd, envp);
		}
	}
}

int	ft_strchrsl(char *str, char c)
{
	int	i;

	c = '/';
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
