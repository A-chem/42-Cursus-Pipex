/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:20:51 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/12 14:40:24 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_data
{
	int	fd[2];
	int	fd_in;
	int	fd_out;
	int	fd_save[2];
}		t_data;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *s, char c);
void	ft_putstr(const char *str);
void	ft_dup2(int fd_src, int fd_dest, int fd_close);
void	ft_close(int fd);
void	ft_pipe(t_data **data);
pid_t	ft_fork(t_data *data);
void	ft_wait(pid_t pid);
int		check_exec_cmd(char *cmd, char **env);
int		ft_check_path_cmd(char *cmd);
char	*ft_found_cmd(char *cmd, char **path);
char	*fet_path(char **env);
int		pars_cmd_1(char *cmd);
int		pars_cmd_2(char **cmd_split, char **env);
int		pars_cmd_3(char **cmd_split, char **env);
void	ft_double_free(char **str);
void	handle_errors(char *str);

#endif
