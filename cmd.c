/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:56:39 by arlamber          #+#    #+#             */
/*   Updated: 2023/04/08 16:04:08 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd(char **all_path, char **cmd, int *fd)
{
	if (cmd == NULL || !cmd[0])
	{
		write(2, "zsh: command not found:\n", 24);
		close (fd[1]);
		ft_free_path(all_path);
		if (cmd)
			free(cmd);
		exit(1);
	}
}

void	ft_cmd2(char **all_path, char **cmd, int *fd)
{
	if (cmd == NULL || !cmd[0])
	{
		write(2, "zsh: command not found:\n", 24);
		close (fd[0]);
		ft_free_path(all_path);
		if (cmd)
			free(cmd);
		exit(1);
	}
}
