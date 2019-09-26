/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:15:06 by mkami             #+#    #+#             */
/*   Updated: 2019/04/04 14:26:55 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	int				i;
	unsigned char	*u;

	i = 0;
	if (len == 0)
		return (str);
	u = str;
	while (i <= (int)len - 1)
	{
		u[i] = (unsigned char)value;
		i++;
	}
	return (u);
}
