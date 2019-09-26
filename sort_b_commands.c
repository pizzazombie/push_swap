/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:13:29 by mkami             #+#    #+#             */
/*   Updated: 2019/08/16 15:13:30 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_201(t_stack *stack)
{
	ft_pa(stack, 1);
	ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
}

void	ft_102(t_stack *stack)
{
	ft_rb(stack, 1);
	ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_rrb(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
}

void	ft_021(t_stack *stack)
{
	ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
}

void	ft_012(t_stack *stack)
{
	ft_rb(stack, 1);
	ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
	ft_rrb(stack, 1);
	ft_pa(stack, 1);
}

void	ft_120(t_stack *stack)
{
	ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
}
