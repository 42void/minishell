/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 23:10:24 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 20:19:34 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*final_setenv(char **ret_gnl)
{
	char	*str;

	str = ft_strjoin(ret_gnl[1], "=");
	str = ft_strjoin(str, ret_gnl[2]);
	return (str);
}

char	*final_setenv2(char **ret_gnl)
{
	char	*str;

	str = ft_strjoin(ret_gnl[1], "=");
	return (str);
}
