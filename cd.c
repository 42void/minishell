/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 23:08:32 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/20 23:08:39 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_cd(char **ret_gnl)
{
	char		*dir;

	dir = NULL;
	if ((ft_strcmp(ret_gnl[0], "cd")) == 0)
	{
		if (ret_gnl[1] == NULL)
			dir = ft_get_content_var("HOME=");
		else if ((ft_strcmp(ret_gnl[1], "~")) == 0)
			dir = ft_get_content_var("HOME=");
		else if ((ft_strcmp(ret_gnl[1], "-")) == 0)
			dir = ft_get_content_var("OLDPWD=");
		else
			dir = ret_gnl[1];
	}
	if (chdir(dir) == 0)
		ft_chdir(dir);
	else
		ft_error(ret_gnl);
}
