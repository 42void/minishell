/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 23:09:09 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 20:20:57 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_env(void)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		ft_putendl(g_env[i]);
		i++;
	}
}

int		nb_lines(char **ret_gnl)
{
	int		i;

	i = 0;
	while (ret_gnl[i])
		i++;
	return (i);
}

char	**ft_setenv(char **ret_gnl)
{
	int		j;
	int		k;
	char	*final_str;

	j = 0;
	k = 0;
	final_str = NULL;
	while (ret_gnl[j])
		j++;
	if (j > 1)
		g_env = ft_unsetenv(ret_gnl[1]);
	if (j == 3)
		final_str = final_setenv(ret_gnl);
	else if (j == 2)
		final_str = final_setenv2(ret_gnl);
	else if (j < 2)
	{
		while (g_env[k])
			ft_putendl(g_env[k++]);
		return (g_env);
	}
	else
		ft_putendl("Too many arguments.");
	return (ft_malloc_env_end(final_str));
}

char	**ft_malloc_env_end(char *final_str)
{
	char	**env_end;
	int		i;

	i = 0;
	env_end = malloc((nb_lines(g_env) + 2) * sizeof(*env_end));
	while (g_env[i])
	{
		env_end[i] = ft_strdup(g_env[i]);
		i++;
	}
	env_end[i] = ft_strdup(final_str);
	env_end[++i] = NULL;
	return (env_end);
}

char	**ft_unsetenv(char *name)
{
	char	*var;
	int		i;
	int		j;
	char	**env_end;

	i = 0;
	j = 0;
	if ((var = ft_get_var(name)) != NULL)
	{
		env_end = malloc((nb_lines(g_env) - 1) * sizeof(char *) + 1);
		while (g_env[i])
		{
			if (ft_strcmp(g_env[i], name) == '=')
			{
				free(g_env[i]);
				++i;
			}
			else
				env_end[j++] = ft_strdup(g_env[i++]);
		}
		env_end[j] = NULL;
		return (env_end);
	}
	else
		return (g_env);
}
