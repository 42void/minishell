/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:12:11 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 18:36:14 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		ft_putstr("mon_prompt > ");
	}
}

int		main(int argc, char **argv, char *envp[])
{
	int		i;

	(void)argc;
	(void)argv;
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putstr("\ncan't catch SIGINT\n");
	if (signal(SIGTSTP, sig_handler) == SIG_ERR)
		ft_putstr("\ncan't catch SIGTSTP\n");
	if (signal(SIGQUIT, sig_handler) == SIG_ERR)
		ft_putstr("\ncan't catch SIGQUIT\n");
	i = 0;
	while (envp[i])
		i++;
	g_env = malloc(sizeof(*envp) * i + 1);
	i = 0;
	while (envp[i])
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_env[i] = NULL;
	ft_putstr("mon_prompt > ");
	read_cmd();
	return (0);
}
