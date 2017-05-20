/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:07:09 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/21 19:59:04 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
	int		n;
	int		i;
	char	*tab;

	if (!s1)
		return (NULL);
	i = 0;
	n = ft_strlen(s1);
	tab = malloc((n + 1) * sizeof(char));
	while (i < n)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
