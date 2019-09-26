/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medians.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:06:00 by mkami             #+#    #+#             */
/*   Updated: 2019/08/16 21:06:01 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sort_c(int i, int *c, int min)
{
	int j;
	int index;
	int tmp;

	while (i >= min)
	{
		index = 1;
		j = min;
		while (j < i)
		{
			if (c[j] > c[j + 1])
			{
				tmp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = tmp;
				index = 0;
			}
			j++;
		}
		if (index == 1)
			break ;
		i--;
	}
}

int		ft_median_a(t_stack *stack)
{
	int i;
	int *c;

	c = (int *)malloc(sizeof(c) * (stack->max_a));
	i = stack->min_a;
	while (i <= stack->max_a - stack->sorted)
	{
		c[i] = stack->a[i];
		i++;
	}
	i = stack->max_a - stack->sorted;
	ft_sort_c(i, c, stack->min_a);
	i = c[(stack->max_a - stack->sorted - stack->min_a + 1) / 2 + stack->min_a];
	free(c);
	return (i);
}

int		ft_median_b(t_stack *stack)
{
	int i;
	int *c;

	c = (int *)malloc(sizeof(c) * (stack->max_b));
	i = stack->min_b;
	while (i <= stack->min_b + stack->wide_b[stack->ind_b])
	{
		c[i] = stack->b[i];
		i++;
	}
	i = stack->min_b + stack->wide_b[stack->ind_b] - 1;
	ft_sort_c(i, c, stack->min_b);
	i = c[(stack->wide_b[stack->ind_b]) / 2 + stack->min_b];
	free(c);
	return (i);
}
