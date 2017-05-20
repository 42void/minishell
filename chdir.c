/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 23:08:49 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 18:36:35 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_chdir(char *dir)
{
	char		*charetoile;
	char		**split;
	char		**split2;
	char		*charetoile2;
	char		*tmpwd;

	dir = getcwd(NULL, 0);
	tmpwd = ft_get_content_var("PWD=");
	charetoile2 = ft_strjoin("setenv OLDPWD ", tmpwd);
	split2 = ft_strsplit(charetoile2, ' ');
	g_env = ft_setenv(split2);
	charetoile = ft_strjoin("setenv PWD ", dir);
	split = ft_strsplit(charetoile, ' ');
	g_env = ft_setenv(split);
}
