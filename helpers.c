/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:51:54 by mkami             #+#    #+#             */
/*   Updated: 2019/07/24 16:51:56 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static unsigned long long	spaces(char *str)
{
	unsigned long long j;

	j = 0;
	while (str[j] == '\t' || str[j] == '\v' || str[j] == '\n' ||
			str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
		j++;
	return (j);
}

long long int				ft_atoi2(const char *str1)
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
	}
	return (k * i);
}

void						ft_puterror2(t_stack *stack, int i)
{
	free(stack->a);
	free(stack->b);
	ft_puterror("Error\n");
	i = 0;
}

void						ft_puterror(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}
