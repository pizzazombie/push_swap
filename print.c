/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:39:01 by mkami             #+#    #+#             */
/*   Updated: 2019/07/22 13:39:02 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_stacks(t_stack *stack, int max)
{
	int i;

	i = 0;
	ft_putstr("\na :");
	while (i <= max)
	{
		if (i <= stack->max_a && i >= stack->min_a && stack->min_a >= 0)
			ft_putnbr(stack->a[i]);
		else
			ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
	i = 0;
	ft_putstr("\nb :");
	while (i <= max)
	{
		if (i <= stack->max_b && i >= stack->min_b && stack->min_b >= 0)
			ft_putnbr(stack->b[i]);
		else
			ft_putchar('.');
		ft_putchar(' ');
		i++;
	}
}
