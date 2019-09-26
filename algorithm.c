/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:48:56 by mkami             #+#    #+#             */
/*   Updated: 2019/08/13 16:48:58 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pre_sort_a(t_stack *stack)
{
	int mid;
	int ra;

	while (stack->max_a - stack->min_a > 2)
	{
		mid = ft_median_a(stack);
		stack->ind_b++;
		stack->wide_b[stack->ind_b] = 0;
		ra = ft_push_small_nums_to_b(stack, mid);
	}
	ft_sort_two_or_three_elements_a(stack);
	stack->sorted = stack->max_a - stack->min_a + 1;
}

void	ft_sort_b_and_pa(t_stack *stack)
{
	if (stack->wide_b[stack->ind_b] <= 3)
	{
		ft_sort_two_or_three_elements_b_and_pa(stack);
		stack->ind_b--;
	}
}

void	ft_sort_3_a(t_stack *stack)
{
	if (stack->wide_a[stack->ind_a] <= 3)
	{
		ft_sort_two_or_three_elements_a(stack);
		if (stack->wide_a[stack->ind_a] == 3)
			stack->sorted = stack->sorted + 3;
		else
			stack->sorted = stack->sorted + 2;
		stack->ind_a--;
	}
}

void	ft_circle(t_stack *stack)
{
	if (stack->wide_b[stack->ind_b] <= 3)
	{
		ft_sort_3_a(stack);
		ft_sort_two_or_three_elements_b_and_pa(stack);
		stack->ind_b--;
	}
	else
	{
		ft_cut_b(stack);
		if (stack->wide_a[stack->ind_a] <= 3)
			ft_sort_3_a(stack);
		else
			while (stack->wide_a[stack->ind_a] > 3)
				ft_cut_a(stack);
	}
}

void	ft_alg2(t_stack *stack)
{
	int i;

	i = 0;
	stack->odd = stack->nums % 2;
	ft_pre_sort_a(stack);
	while (stack->min_a != 0)
		ft_circle(stack);
}
