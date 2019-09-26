/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_or_three_elements.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:05:15 by mkami             #+#    #+#             */
/*   Updated: 2019/08/16 21:05:17 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sort_two_elements_a(t_stack *stack)
{
	if (stack->a[stack->min_a] > stack->a[stack->min_a + 1])
		ft_sa(stack, 1);
}

void	ft_sort_two_elements_b(t_stack *stack)
{
	if (stack->b[stack->min_b] < stack->b[stack->min_b + 1])
		ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
	stack->sorted = stack->sorted + 2;
}

void	ft_sort_three_b_and_pa(int a, int b, int c, t_stack *stack)
{
	if (a > b && a > c && b < c)
		ft_201(stack);
	else if (a > b && a < c && c > b)
		ft_102(stack);
	else if (a < b && a < c && c < b)
		ft_021(stack);
	else if (a < b && a < c && c > b)
		ft_012(stack);
	else if (a < b && a > c && c < b)
		ft_120(stack);
	else
	{
		ft_pa(stack, 1);
		ft_pa(stack, 1);
		ft_pa(stack, 1);
	}
	stack->sorted = stack->sorted + 3;
}

void	ft_sort_two_or_three_elements_b_and_pa(t_stack *stack)
{
	int i;
	int a;
	int b;
	int c;

	i = stack->min_b;
	a = stack->b[i];
	b = stack->b[i + 1];
	if (stack->max_b - stack->min_b == 1 || stack->wide_b[stack->ind_b] == 2)
	{
		ft_sort_two_elements_b(stack);
		return ;
	}
	c = stack->b[i + 2];
	ft_sort_three_b_and_pa(a, b, c, stack);
}

void	ft_sort_two_or_three_elements_a(t_stack *stack)
{
	int i;
	int a;
	int b;
	int c;

	i = stack->min_a;
	a = stack->a[i];
	b = stack->a[i + 1];
	if (stack->max_a - stack->min_a == 1)
	{
		ft_sort_two_elements_a(stack);
		return ;
	}
	c = stack->a[i + 2];
	if (a > b && a < c && b < c)
		ft_sa(stack, 1);
	else if (a > b && a > c && c > b)
		ft_a_201(stack);
	else if (a < b && a > c && c < b)
		ft_a_120(stack);
	else if (a > b && a > c && c < b)
		ft_a_210(stack);
	else if (a < b && a < c && c < b)
		ft_a_021(stack);
}
