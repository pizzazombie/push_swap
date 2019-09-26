/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:47:12 by mkami             #+#    #+#             */
/*   Updated: 2019/04/11 19:48:58 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordlen(char const *s, char c, int word)
{
	int i;
	int w;
	int len;

	i = 0;
	w = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (w == word)
				len++;
		}
		if (w == word)
			return (len);
		w++;
	}
	return (0);
}
