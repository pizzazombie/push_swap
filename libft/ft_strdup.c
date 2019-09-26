/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:29:50 by mkami             #+#    #+#             */
/*   Updated: 2019/04/23 15:36:00 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	str = (char*)malloc(i + 1);
	if (!(str))
		return (0);
	while (j <= i)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
