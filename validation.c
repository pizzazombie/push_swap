/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:55:36 by mkami             #+#    #+#             */
/*   Updated: 2019/07/24 16:55:37 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_double_num(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (i <= stack->max_a)
	{
		j = i;
		while (j <= stack->max_a)
		{
			if (stack->a[i] == stack->a[j] && i != j)
			{
				ft_puterror2(stack, 0);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_valid(long long int a)
{
	if (a > 2147483647 || a < -2147483648)
		return (-1);
	return (1);
}

int	ft_valid_str(char *str)
{
	int i;
	int nums;

	nums = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			nums++;
			while (str[i] >= 48 && str[i] <= 57)
				i++;
		}
		else if (str[i] == ' ')
			i++;
		else if ((str[i] == '-' || str[i] == '+') &&
				(str[i + 1] >= 48 && str[i + 1] <= 57) && (i == 0))
			i++;
		else if ((str[i] == '-' || str[i] == '+') &&
				(str[i + 1] >= 48 && str[i + 1] <= 57) && (str[i - 1] == ' '))
			i++;
		else
			return (-1);
	}
	return (1);
}

int	ft_validate(int argc, char **argv, t_stack *stack)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_valid_str(argv[i]) < 0)
		{
			ft_puterror2(stack, 0);
			return (-1);
		}
		i++;
	}
	return (1);
}
