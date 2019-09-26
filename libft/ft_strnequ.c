/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:03:54 by mkami             #+#    #+#             */
/*   Updated: 2019/04/08 15:41:08 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (!(s1 == NULL || s2 == NULL))
	{
		while (s1[i] != '\0' && s2[i] != '\0' && i < (int)n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s1[i] != s2[i] && i < (int)n)
			return (0);
		return (1);
	}
	return (0);
}
