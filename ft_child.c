/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:14:24 by arrlamber         #+#    #+#             */
/*   Updated: 2023/04/08 17:05:29 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(char **av, char **all_path, int *fd, char **envp)
{
	char	**cmd;
	char	*path;
	int		infile;

	close (fd[0]);
	cmd = ft_split(av[2], ' ');
	ft_cmd(all_path, cmd, fd);
	path = ft_command(all_path, cmd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		write (1, "no such file or directory1:\n", 28);
		close(fd[1]);
		ft_free_path(all_path);
		ft_free_path(cmd);
		free(path);
		exit(1);
	}
	dup2(infile, 0);
	dup2(fd[1], 1);
	ft_exec_chemin(cmd[0], cmd, envp);
	ft_truc(fd, path, all_path, cmd);
	execve(path, cmd, envp);
}

void	ft_child2(char **av, char **all_path, int *fd, char **envp)
{
	char	**cmd;
	char	*path;
	int		outfile;

	close(fd[1]);
	cmd = ft_split(av[3], ' ');
	ft_cmd2(all_path, cmd, fd);
	path = ft_command(all_path, cmd[0]);
	outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (outfile < 0)
	{
		write (1, "no such file or directory2:\n", 28);
		close(fd[0]);
		ft_free_path(all_path);
		ft_free_path(cmd);
		free(path);
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(outfile, 1);
	ft_exec_chemin(cmd[0], cmd, envp);
	ft_truc(fd, path, all_path, cmd);
	execve(path, cmd, envp);
}

void	ft_truc(int *fd, char *path, char **all_path, char **cmd)
{
	if (path == NULL)
	{
		write(2, "zsh: command not fou1nd1:\n", 26);
		close (fd[1]);
		close (fd[0]);
		ft_free_path(all_path);
		ft_free_path(cmd);
		exit(1);
	}
}
