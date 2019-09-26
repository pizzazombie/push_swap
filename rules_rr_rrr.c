/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:48:25 by mkami             #+#    #+#             */
/*   Updated: 2019/07/24 13:48:27 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rr(t_stack *stack, int print)
{
	ft_ra(stack, print);
	ft_rb(stack, print);
}

void	ft_rrr(t_stack *stack, int print)
{
	ft_rra(stack, print);
	ft_rrb(stack, print);
}
