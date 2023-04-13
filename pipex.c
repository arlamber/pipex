/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:54:41 by arrlamber         #+#    #+#             */
/*   Updated: 2023/04/08 16:09:06 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parent_process(int pid, int pid2)
{
	int	wstatus;
	int	exitcode;

	waitpid(pid, NULL, 0);
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		exitcode = WEXITSTATUS(wstatus);
	}
	return (exitcode);
}

int	main(int ac, char **av, char *envp[])
{
	char	**all_path;
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];
	int		statuscode;

	if (ac != 5)
		return (write (2, "wrong numbers of argument\n", 27), 1);
	all_path = ft_path(envp);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
		ft_child1(av, all_path, fd, envp);
	pid2 = fork();
	if (pid2 == 0)
		ft_child2(av, all_path, fd, envp);
	close(fd[0]);
	close(fd[1]);
	statuscode = ft_parent_process(pid, pid2);
	ft_free_path(all_path);
	return (statuscode);
}

char	**ft_path(char **envp)
{
	int		i;
	int		j;
	char	**path;

	path = NULL;
	i = 0;
	if (envp)
	{
		while (envp[i])
		{
			j = 0;
			if (envp[i][j] == 'P' && envp[i][j + 1] == 'A' &&
					envp[i][j + 2] == 'T' && envp[i][j + 3] == 'H'
						&& envp[i][j + 4] == '=')
			{
				envp[i] += 5;
				path = ft_split (envp[i], ':');
				break ;
			}
			i++;
		}
	}
	return (path);
}

char	*ft_command(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	if (path)
	{
		while (path[i])
		{
			tmp = ft_strjoin(path[i], "/");
			command = ft_strjoin(tmp, cmd);
			if ((access(command, F_OK)) == 0)
			{
				free(tmp);
				return (command);
			}
			free(command);
			free(tmp);
			i++;
		}
	}
	return (NULL);
}
