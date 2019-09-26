/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:13:44 by mkami             #+#    #+#             */
/*   Updated: 2019/04/08 13:57:22 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int j;
	int k;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < (int)len)
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
			if (k == 0 && i + j < (int)len + 1)
				return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}
