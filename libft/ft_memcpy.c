/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:57:48 by mkami             #+#    #+#             */
/*   Updated: 2019/04/18 14:44:00 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*u;
	char	*u2;

	i = 0;
	if (n == 0)
		return (dest);
	u = dest;
	u2 = (char *)src;
	while (i < n)
	{
		u[i] = u2[i];
		i++;
	}
	return (u);
}
