/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:32:27 by mkami             #+#    #+#             */
/*   Updated: 2019/08/16 15:32:28 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_a_201(t_stack *stack)
{
	ft_sa(stack, 1);
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
}

void	ft_a_120(t_stack *stack)
{
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
	ft_sa(stack, 1);
}

void	ft_a_210(t_stack *stack)
{
	ft_sa(stack, 1);
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
	ft_sa(stack, 1);
}

void	ft_a_021(t_stack *stack)
{
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
}
