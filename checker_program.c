/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:02:45 by mkami             #+#    #+#             */
/*   Updated: 2019/07/24 17:02:47 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_func		*ft_funct2(t_func *func)
{
	func[6].str = "rb";
	func[6].f = &ft_rb;
	func[7].str = "rr";
	func[7].f = &ft_rr;
	func[8].str = "rra";
	func[8].f = &ft_rra;
	func[9].str = "rrb";
	func[9].f = &ft_rrb;
	func[10].str = "rrr";
	func[10].f = &ft_rrr;
	func[11].str = "End";
	func[11].f = &ft_puterror2;
	return (func);
}

t_func		*ft_funct(void)
{
	t_func *func;

	func = (t_func *)malloc(sizeof(func) * 120);
	func[0].str = "sa";
	func[0].f = &ft_sa;
	func[1].str = "sb";
	func[1].f = &ft_sb;
	func[2].str = "ss";
	func[2].f = &ft_ss;
	func[3].str = "pa";
	func[3].f = &ft_pa;
	func[4].str = "pb";
	func[4].f = &ft_pb;
	func[5].str = "ra";
	func[5].f = &ft_ra;
	func = ft_funct2(func);
	return (func);
}

void		ft_is_stack_sorted(t_stack *stack)
{
	int i;

	i = stack->min_a;
	if (i != 0 || stack->min_b >= 0)
		ft_putstr("KO\n");
	else
	{
		while (i < stack->max_a)
		{
			if (stack->a[i] >= stack->a[i + 1])
			{
				ft_putstr("KO\n");
				return ;
			}
			i++;
		}
		ft_putstr("OK\n");
	}
}

int			ft_free_if_11(t_func *func, char *line, int i)
{
	if (i == 11)
	{
		free(func);
		free(line);
		return (11);
	}
	return (0);
}

void		ft_checker_init(t_stack *stack)
{
	char	*line;
	int		i;
	t_func	*func;

	line = NULL;
	func = ft_funct();
	while (get_next_line(0, &line) > 0)
	{
		i = 0;
		while (ft_strcmp(line, func[i].str) != 0 && i != 11)
			i++;
		func[i].f(stack, 0);
		if (ft_free_if_11(func, line, i) == 11)
			return ;
		free(line);
		line = ft_strnew(10);
	}
	free(line);
	ft_is_stack_sorted(stack);
	free(stack->a);
	free(stack->b);
	free(func);
}
