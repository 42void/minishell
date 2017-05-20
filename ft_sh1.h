/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 17:32:07 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 21:46:34 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <unistd.h>
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>

char	*ft_get_content_var(char *var);
char	*ft_get_var(char *var);
char	**ft_get_path(void);
char	**ft_str_to_wordtab(char *cmd);
char	*ft_concat_cmd_path(char **path, char **ret_gnl);
void	ft_env(void);
char	**ft_setenv(char **ret_gnl);
int		get_next_line(int fd, char **line);
char	**g_env;
char	*final_setenv(char **ret_gnl);
char	*final_setenv2(char **ret_gnl);
char	**ft_unsetenv(char *name);
void	ft_cd(char **ret_gnl);
void	sig_handler(int signo);
void	ft_exec_cmd(char *ret_trim);
void	read_cmd();
void	ft_chdir(char *dir);
void	ft_error(char **ret_gnl);
void	ft_fork(char **ret_gnl, char *tmp);
char	**ft_malloc_env_end();
void	tab_to_sp(char *str);

#endif
