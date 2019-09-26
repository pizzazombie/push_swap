/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:38:19 by mkami             #+#    #+#             */
/*   Updated: 2019/07/22 13:38:21 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free(char **arr, char *str)
{
	int i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(str);
}

int		ft_if_one_arg(t_stack *stack, char **argv)
{
	char *str;
	char **arr;

	stack->nums = words(argv[1], ' ');
	stack->a = (int*)malloc(sizeof(*stack->a) * (stack->nums));
	stack->b = (int*)malloc(sizeof(*stack->b) * (stack->nums));
	str = ft_strjoin("0 ", argv[1]);
	arr = ft_strsplit(str, ' ');
	if (ft_validate(stack->nums + 1, arr, stack) < 0 ||
			ft_put_nums(stack, stack->nums + 1, arr) < 0)
	{
		ft_free(arr, str);
		return (-1);
	}
	ft_free(arr, str);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	stack;

	ft_stack_init(&stack);
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if (ft_if_one_arg(&stack, argv) == -1)
			return (0);
	}
	else
	{
		stack.a = (int*)malloc(sizeof(*stack.a) * (argc - 1));
		stack.b = (int*)malloc(sizeof(*stack.b) * (argc - 1));
		if (ft_validate(argc, argv, &stack) < 0 ||
				ft_put_nums(&stack, argc, argv) < 0)
			return (0);
	}
	ft_checker_init(&stack);
	return (0);
}
