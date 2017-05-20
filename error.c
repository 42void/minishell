/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 23:09:22 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/20 23:09:29 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_error(char **ret_gnl)
{
	struct stat	check_stat;

	if (stat(ret_gnl[1], &check_stat) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(ret_gnl[1]);
	}
	else if (access(ret_gnl[1], R_OK) == -1)
	{
		ft_putstr("cd: permisson denied: ");
		ft_putendl(ret_gnl[1]);
	}
	else if (S_ISDIR(check_stat.st_mode) == 0)
	{
		ft_putstr("cd: not a directory: ");
		ft_putendl(ret_gnl[1]);
	}
	else
		ft_putendl("unknown error");
}
