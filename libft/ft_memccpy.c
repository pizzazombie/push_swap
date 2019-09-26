/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:22:14 by mkami             #+#    #+#             */
/*   Updated: 2019/04/11 19:54:03 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*u;
	unsigned char	*u2;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	if ((!(dest) && !(src)))
		return (NULL);
	u = (unsigned char *)src;
	u2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		u2[i] = u[i];
		if (u[i] == cc)
			return (u2 + i + 1);
		i++;
	}
	return (NULL);
}
