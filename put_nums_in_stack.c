/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nums_in_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:21:11 by mkami             #+#    #+#             */
/*   Updated: 2019/07/26 14:21:12 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_put_nums(t_stack *stack, int argc, char **argv)
{
	int				i;
	long long int	temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi2(argv[i]);
		if (ft_valid(temp) < 0)
		{
			ft_puterror2(stack, 0);
			return (-1);
		}
		stack->a[i - 1] = temp;
		i++;
	}
	stack->max_a = argc - 2;
	stack->min_a = 0;
	stack->max_b = argc - 2;
	stack->min_b = -1;
	stack->nums = argc - 2;
	if (ft_double_num(stack) < 0)
		return (-1);
	return (1);
}

void	ft_stack_init(t_stack *stack)
{
	stack->max_a = 0;
	stack->max_b = 0;
	stack->min_a = 0;
	stack->min_b = 0;
	stack->nums = 0;
	stack->ind_b = -1;
	stack->ind_a = -1;
	stack->sorted = 0;
}
