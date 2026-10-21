/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:40:35 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/14 03:04:26 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	handle_errors(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_pipe(t_data **data)
{
	if (pipe((*data)->fd) == -1)
		handle_errors("Pipe Failed\n");
}

pid_t	ft_fork(void)
{
	pid_t	child;

	child = fork();
	if (child == -1)
		handle_errors("Fork  Failed\n");
	return (child);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		handle_errors("Error closing file descriptor\n");
}

void	ft_dup2(int fd_src, int fd_dest)
{
	if (dup2(fd_src, fd_dest) == -1)
	{
		ft_close(fd_src);
		handle_errors ("Dup2 Failed\n");
	}
}
