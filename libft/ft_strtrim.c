/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:32:54 by mkami             #+#    #+#             */
/*   Updated: 2019/04/08 20:44:58 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim1(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	trim2(char const *s)
{
	int i;
	int len;

	i = 0;
	while (s[i] != '\0')
		i++;
	len = i;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		b;

	if (s == NULL)
		return (NULL);
	i = trim1(s);
	b = trim2(s);
	j = 0;
	if (b < i)
		i = 0;
	str = (char *)malloc(sizeof(char) * (b - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < b)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
