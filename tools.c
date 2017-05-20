/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 23:11:09 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 21:50:02 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_get_content_var(char *var)
{
	char	*content;
	int		i;

	i = 0;
	content = NULL;
	while (g_env[i] != NULL && content == NULL)
	{
		content = ft_strnstr(g_env[i], var, ft_strlen(var));
		i++;
	}
	if (content != NULL)
	{
		i--;
		content = ft_strchr(g_env[i], '=') + 1;
	}
	return (content);
}

char	*ft_get_var(char *var)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (g_env[i] != NULL && tmp == NULL)
	{
		tmp = ft_strstr(g_env[i], var);
		i++;
	}
	return (tmp);
}

char	**ft_get_path(void)
{
	char	*all_paths;
	char	**path;

	all_paths = ft_get_content_var("PATH=");
	path = ft_strsplit(all_paths, ':');
	return (path);
}

char	**ft_str_to_wordtab(char *cmd)
{
	char	**ret_gnl;

	ret_gnl = ft_strsplit(cmd, ' ');
	return (ret_gnl);
}

char	*ft_concat_cmd_path(char **path, char **ret_gnl)
{
	int		i;
	char	*path_n_cmd;

	i = 0;
	if (access(ret_gnl[0], X_OK) != -1)
		return (ret_gnl[0]);
	while (path && path[i] != NULL)
	{
		path_n_cmd = ft_strnew(ft_strlen(path[i]) + ft_strlen(ret_gnl[0]) + 2);
		path_n_cmd = ft_strcat(path_n_cmd, path[i]);
		path_n_cmd = ft_strcat(path_n_cmd, "/");
		path_n_cmd = ft_strcat(path_n_cmd, ret_gnl[0]);
		if (access(path_n_cmd, X_OK) != -1)
			return (path_n_cmd);
		free (path_n_cmd);
		i++;
	}
	return (NULL);
}
