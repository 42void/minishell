/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 23:09:49 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 21:45:17 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	read_cmd(void)
{
	char *cmd;
	char *ret_trim;

	while (get_next_line(0, &cmd) > 0)
	{
		ret_trim = ft_strtrim(cmd);
		tab_to_sp(ret_trim);
		if (!(ret_trim && ft_strlen(ret_trim) == 0))
			ft_exec_cmd(ret_trim);
		ft_putstr("mon_prompt > ");
	}
}

void	ft_exec_cmd(char *ret_trim)
{
	char	**path;
	char	**ret_gnl;
	char	*tmp;

	path = ft_get_path();
	ret_gnl = ft_str_to_wordtab(ret_trim);
	if (ft_strcmp(ret_gnl[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(ret_gnl[0], "env") == 0 && ret_gnl[1] == NULL)
		ft_env();
	else if (ft_strcmp(ret_gnl[0], "cd") == 0)
		ft_cd(ret_gnl);
	else if (ft_strcmp(ret_gnl[0], "setenv") == 0)
		g_env = ft_setenv(ret_gnl);
	else if (ft_strcmp(ret_gnl[0], "unsetenv") == 0)
		g_env = ft_unsetenv(ret_gnl[1]);
	else if ((tmp = ft_concat_cmd_path(path, ret_gnl)) != NULL)
		ft_fork(ret_gnl, tmp);
	else
	{
		ft_putstr("ft_minishell1: command not found: ");
		ft_putendl(ret_gnl[0]);
	}
}

void	ft_fork(char **ret_gnl, char *tmp)
{
	pid_t	father;

	father = fork();
	if (father == 0)
		execve(tmp, ret_gnl, g_env);
	else
		wait(NULL);
}
