/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:58:08 by mkami             #+#    #+#             */
/*   Updated: 2019/04/06 13:07:09 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		k = 0;
		if (str[i] == to_find[0])
		{
			while (to_find[j] != '\0' && k == 0)
			{
				if (to_find[j] != str[i + j])
					k = 1;
				j++;
			}
			if (k == 0)
				return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}
