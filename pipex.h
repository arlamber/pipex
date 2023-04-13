/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:42:41 by arlamber          #+#    #+#             */
/*   Updated: 2023/04/08 16:07:39 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>

////////////////////LIBFT
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);

////////////////////PIPEX
char	**ft_path(char **envp);
char	*ft_command(char **path, char *cmd);
void	ft_child1(char **av, char **all_path, int *fd, char **envp);
void	ft_child2(char **av, char **all_path, int *fd, char **envp);
void	ft_free_path(char **str);
int		ft_strchrsl(char *str, char c);
void	ft_truc(int *fd, char *path, char **all_path, char **cmd);
void	ft_truc2(char **av, char *path, char **all_path, char **cmd);
void	ft_cmd(char **all_path, char **cmd, int *fd);
void	ft_cmd2(char **all_path, char **cmd, int *fd);
void	ft_exec_chemin(char *av, char **cmd, char **envp);
int		ft_parent_process(int pid, int pid2);

#endif
