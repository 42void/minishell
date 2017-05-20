/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 19:02:51 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/12/22 18:39:02 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	str = (!str) ? ft_strnew(1) : str;
	while (1)
	{
		if (ft_strchr(str, '\n'))
		{
			*line = ft_strsub(str, 0, ft_len_line(str));
			str = ft_strdup(str + ft_len_line(str) + 1);
			return (1);
		}
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		str = (ret > 0) ? ft_strjoin(str, buf) : str;
		if (ret <= 0)
		{
			*line = ft_strdup(str);
			str = NULL;
			return ((ret > 0) ? 1 : ret);
		}
	}
}
