/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:34:54 by mkami             #+#    #+#             */
/*   Updated: 2019/04/09 17:13:44 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	indexten(int len, int n)
{
	int i;
	int index;

	i = 1;
	index = 1;
	while (i < len)
	{
		index = index * 10;
		i++;
	}
	if (n < 0)
		index = index / 10;
	return (index);
}

static char	*writestr(char *s, int index, int n, int i)
{
	while (index > 0)
	{
		s[i] = n / index + 48;
		n = n % index;
		index = index / 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		index;

	i = 0;
	if ((s = (char *)malloc(sizeof(*s) * charlen(n) + 1)) == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		s[i] = '-';
		s[1] = '2';
		n = 147483648;
		i = i + 2;
	}
	index = indexten(charlen(n), n);
	if (n < 0)
	{
		s[i] = '-';
		n = n * (-1);
		i++;
	}
	s = writestr(s, index, n, i);
	return (s);
}
