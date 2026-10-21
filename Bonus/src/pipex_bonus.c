/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:01:59 by achemlal          #+#    #+#             */
/*   Updated: 2025/03/14 14:48:34 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_open(int flag, int ac, t_data *data)
{
	if (ft_strncmp(data->av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			exit(1);
		ft_here_doc(data->av, data);
		data->fd_out = open(data->av[ac - 1], O_CREAT | O_WRONLY
				| O_APPEND, 0644);
		if (data->fd_out == -1)
			handle_errors("Error Opening File");
		flag++;
	}
	else
	{
		data->fd_out = open(data->av[ac - 1], O_CREAT | O_WRONLY
				| O_TRUNC, 0644);
		if (data->fd_out == -1)
			handle_errors("Error Opening File");
	}
	return (flag);
}

void	pipex(int ac, char **env, t_data *data)
{
	data->i = ft_open(1, ac, data);
	data->fd_save = dup(0);
	while (++data->i < ac - 1)
		ft_process(data->av[data->i], env, (data->i + 1 == ac - 1), data);
	ft_dup2(data->fd_save, 0);
	ft_close(data->fd_save);
	ft_close(data->fd_out);
	while (waitpid(-1, NULL, 0) != -1)
		;
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	data.av = av;
	if (ac < 5)
		handle_errors("Error: Invalid number of arguments\n");
	if (!*env || !env)
		handle_errors("Error: Invalid environment\n");
	pipex(ac, env, &data);
}
