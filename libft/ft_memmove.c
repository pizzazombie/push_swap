/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:43:06 by mkami             #+#    #+#             */
/*   Updated: 2019/04/12 17:53:54 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*u1;
	char	*u2;
	char	*p;
	int		i;

	u1 = (char *)dest;
	u2 = (char *)src;
	if (len == 0 || u1 == u2)
		return (dest);
	if (u1 < u2)
		p = ft_memcpy(dest, u2, len);
	else
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			u1[i] = u2[i];
			i--;
		}
	}
	return (u1);
}
