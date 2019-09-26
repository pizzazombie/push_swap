/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:38:44 by mkami             #+#    #+#             */
/*   Updated: 2019/07/25 20:38:47 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_stack_sorted(t_stack *stack)
{
	int i;

	i = stack->min_a;
	if (stack->max_a - stack->min_a == 0)
		return (1);
	else
	{
		while (i < stack->max_a)
		{
			if (stack->a[i] >= stack->a[i + 1])
				return (-1);
			i++;
		}
		return (1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	ft_stack_init(&stack);
	i = 1;
	if (argc < 2)
		return (0);
	else
	{
		stack.a = (int*)malloc(sizeof(*stack.a) * (argc - 1));
		stack.b = (int*)malloc(sizeof(*stack.b) * (argc - 1));
		if (ft_validate(argc, argv, &stack) < 0 ||
				ft_put_nums(&stack, argc, argv) < 0)
		{
			free(stack.a);
			free(stack.b);
			return (0);
		}
	}
	if (ft_is_stack_sorted(&stack) == -1)
		ft_alg2(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
