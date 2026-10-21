/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:25:37 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/12 12:53:12 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	handle_errors(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_dup2(int fd_src, int fd_dest, int fd_close)
{
	if (dup2(fd_src, fd_dest) == -1)
	{
		ft_close(fd_src);
		ft_close (fd_close);
		handle_errors ("Dup2 Failed\n");
	}
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		handle_errors("Error closing file descriptor\n");
}

pid_t	ft_fork(t_data *data)
{
	pid_t	child;

	child = fork();
	if (child == -1)
	{
		ft_close(data->fd[0]);
		ft_close(data->fd[1]);
		handle_errors("Fork  Failed\n");
	}
	return (child);
}
