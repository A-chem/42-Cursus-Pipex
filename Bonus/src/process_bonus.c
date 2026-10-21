/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:27:45 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/14 03:10:02 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	ft_handle_input_redirection(t_data *data)
{
	data->fd_in = open(data->av[1], O_RDONLY);
	if (data->fd_in == -1)
	{
		perror(data->av[1]);
		ft_close(data->fd[1]);
		ft_close (data->fd_out);
		exit(1);
	}
	ft_dup2(data->fd_in, 0);
	ft_close(data->fd_in);
}

static void	ft_handle_output_redirection(t_data *data)
{
	ft_dup2(data->fd_out, 1);
	ft_close(data->fd_out);
	close(data->fd[1]);
}

void	ft_process(char *cmd, char **env, bool cdt, t_data *data)
{
	int	child;

	ft_pipe(&data);
	child = ft_fork();
	if (child == 0)
	{
		ft_close(data->fd[0]);
		ft_close (data->fd_save);
		if (data->i == 2)
			ft_handle_input_redirection(data);
		if (cdt)
			ft_handle_output_redirection(data);
		else
		{
			ft_dup2(data->fd[1], 1);
			ft_close(data->fd[1]);
		}
		check_exec_cmd(cmd, env);
	}
	else
	{
		ft_close(data->fd[1]);
		ft_dup2(data->fd[0], 0);
		ft_close(data->fd[0]);
	}
}
