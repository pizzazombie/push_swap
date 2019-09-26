/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:17:48 by mkami             #+#    #+#             */
/*   Updated: 2019/04/17 14:47:18 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned long long	spaces(char *str)
{
	unsigned long long j;

	j = 0;
	while (str[j] == '\t' || str[j] == '\v' || str[j] == '\n' ||
			str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
		j++;
	return (j);
}

int							ft_atoi(const char *str1)
{
	unsigned long long	i;
	unsigned long long	j;
	int					k;
	char				*str;

	str = (char *)str1;
	i = 0;
	k = 1;
	j = spaces(str);
	if (str[j] == '+')
		j++;
	else	if (str[j] == '-')
	{
		j++;
		k = -1;
	}
	while ((str[j++] <= 57) && (str[j - 1] >= 48))
	{
		i = i * 10 + (str[j - 1] - 48);
		if (k == -1 && i > 9223372036854775807)
			return (0);
		else if (k == 1 && i > 9223372036854775807)
			return (-1);
	}
	return (k * (int)i);
}
