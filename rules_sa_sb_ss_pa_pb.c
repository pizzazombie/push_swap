/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_sa_sb_ss_pa_pb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:42:03 by mkami             #+#    #+#             */
/*   Updated: 2019/08/16 21:42:05 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stack *stack, int print)
{
	int tmp;

	if (stack->max_a - stack->min_a > 0)
	{
		tmp = stack->a[stack->min_a];
		stack->a[stack->min_a] = stack->a[stack->min_a + 1];
		stack->a[stack->min_a + 1] = tmp;
	}
	if (print == 1)
		ft_putstr("sa\n");
}

void	ft_sb(t_stack *stack, int print)
{
	int tmp;

	if (stack->max_b - stack->min_b > 0)
	{
		tmp = stack->b[stack->min_b];
		stack->b[stack->min_b] = stack->b[stack->min_b + 1];
		stack->b[stack->min_b + 1] = tmp;
	}
	if (print == 1)
		ft_putstr("sb\n");
}

void	ft_ss(t_stack *stack, int print)
{
	ft_sa(stack, print);
	ft_sb(stack, print);
}

void	ft_pb(t_stack *stack, int print)
{
	if (stack->min_a >= 0)
	{
		if (stack->min_b >= 0)
		{
			stack->b[stack->min_b - 1] = stack->a[stack->min_a];
			if (stack->min_a == stack->nums)
				stack->min_a = -1;
			else
				stack->min_a++;
			stack->min_b--;
		}
		else
		{
			stack->b[stack->max_a] = stack->a[0];
			stack->min_b = stack->max_a;
			stack->max_b = stack->max_a;
			stack->min_a++;
		}
	}
	if (print == 1)
		ft_putstr("pb\n");
}

void	ft_pa(t_stack *stack, int print)
{
	if (stack->min_b >= 0)
	{
		if (stack->min_a >= 0)
		{
			stack->a[stack->min_a - 1] = stack->b[stack->min_b];
			if (stack->min_b == stack->nums)
				stack->min_b = -1;
			else
				stack->min_b++;
			stack->min_a--;
		}
		else
		{
			stack->a[stack->max_b] = stack->b[0];
			stack->min_a = stack->max_b;
			stack->max_a = stack->max_b;
			stack->min_b++;
		}
	}
	if (print == 1)
		ft_putstr("pa\n");
}
