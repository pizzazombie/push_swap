/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:16:13 by mkami             #+#    #+#             */
/*   Updated: 2019/08/16 21:16:14 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_push_small_nums_to_b(t_stack *stack, int mid)
{
	int ra;
	int i;

	ra = 0;
	if (stack->ind_a != -1)
		i = stack->wide_a[stack->ind_a];
	else
		i = stack->max_a - stack->min_a + 1;
	while (i > 0)
	{
		if (stack->a[stack->min_a] < mid)
		{
			ft_pb(stack, 1);
			stack->wide_b[stack->ind_b]++;
		}
		else
		{
			ft_ra(stack, 1);
			ra++;
		}
		i--;
	}
	return (ra);
}

int		ft_push_small_nums_to_a(t_stack *stack, int mid)
{
	int i;
	int rb;

	rb = 0;
	i = stack->wide_b[stack->ind_b];
	while (i > 0)
	{
		if (stack->b[stack->min_b] >= mid)
		{
			ft_pa(stack, 1);
			stack->wide_a[stack->ind_a]++;
		}
		else
		{
			ft_rb(stack, 1);
			rb++;
		}
		i--;
	}
	return (rb);
}

void	ft_cut_a(t_stack *stack)
{
	int mid;
	int ra;

	mid = ft_median_a(stack);
	stack->ind_b++;
	stack->wide_b[stack->ind_b] = 0;
	ra = ft_push_small_nums_to_b(stack, mid);
	stack->wide_a[stack->ind_a] = ra;
	while (ra > 0)
	{
		ft_rra(stack, 1);
		ra--;
	}
}

void	ft_cut_b(t_stack *stack)
{
	int mid;
	int rb;

	rb = 0;
	if (stack->wide_b[stack->ind_b] > stack->max_b - stack->min_b + 1)
		stack->wide_b[stack->ind_b] = stack->max_b - stack->min_b + 1;
	mid = ft_median_b(stack);
	stack->ind_a++;
	stack->wide_a[stack->ind_a] = 0;
	rb = ft_push_small_nums_to_a(stack, mid);
	stack->wide_b[stack->ind_b] = rb;
	while (rb > 0)
	{
		ft_rrb(stack, 1);
		rb--;
	}
}
