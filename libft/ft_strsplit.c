/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:04:00 by mkami             #+#    #+#             */
/*   Updated: 2019/04/17 17:10:19 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		k;

	if (s == NULL
			|| (p = (char **)malloc((sizeof(*p) * (words(s, c) + 1)))) == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < words(s, c))
	{
		j = -1;
		if (refresh(p, wordlen(s, c, i), i) == 0)
			return (NULL);
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k] != '\0')
			p[i][++j] = s[k++];
		p[i][++j] = '\0';
		i++;
	}
	p[i] = 0;
	return (p);
}
