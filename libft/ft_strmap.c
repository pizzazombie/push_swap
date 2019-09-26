/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:47:59 by mkami             #+#    #+#             */
/*   Updated: 2019/04/12 17:51:03 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*d;

	if (s == NULL || f == NULL)
		return (NULL);
	else
	{
		d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!(d == NULL))
		{
			i = 0;
			while (s[i] != '\0')
			{
				d[i] = f(s[i]);
				i++;
			}
			d[i] = '\0';
		}
	}
	return (d);
}
