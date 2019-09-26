/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ra_rb_rra_rrb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:42:33 by mkami             #+#    #+#             */
/*   Updated: 2019/08/16 21:42:34 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_stack *stack, int print)
{
	int first;
	int i;

	if (stack->min_a >= 0)
	{
		first = stack->a[stack->min_a];
		i = stack->min_a;
		while (i < stack->max_a)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = first;
	}
	if (print == 1)
		ft_putstr("ra\n");
}

void	ft_rb(t_stack *stack, int print)
{
	int first;
	int i;

	if (stack->min_b >= 0)
	{
		first = stack->b[stack->min_b];
		i = stack->min_b;
		while (i < stack->max_b)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = first;
	}
	if (print == 1)
		ft_putstr("rb\n");
}

void	ft_rra(t_stack *stack, int print)
{
	int first;
	int i;

	if (stack->min_a >= 0)
	{
		first = stack->a[stack->max_a];
		i = stack->max_a;
		while (i > stack->min_a)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[i] = first;
	}
	if (print == 1)
		ft_putstr("rra\n");
}

void	ft_rrb(t_stack *stack, int print)
{
	int first;
	int i;

	if (stack->min_b >= 0)
	{
		first = stack->b[stack->max_b];
		i = stack->max_b;
		while (i > stack->min_b)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[i] = first;
	}
	if (print == 1)
		ft_putstr("rrb\n");
}
