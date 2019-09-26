/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:39:01 by mkami             #+#    #+#             */
/*   Updated: 2019/08/19 13:28:48 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

# define ABS(Value) ((Value > 0) ? (Value) : (-Value))

typedef struct	s_stack
{
	int *a;
	int *b;
	int wide_b[25];
	int wide_a[25];
	int ind_b;
	int ind_a;
	int min_a;
	int min_b;
	int max_a;
	int max_b;
	int nums;
	int odd;
	int sorted;
}				t_stack;

typedef struct	s_func
{
	char *str;
	void (*f)(t_stack *stack, int print);
}				t_func;

void			ft_puterror(char *str);
void			ft_puterror2(t_stack *stack, int i);
long long int	ft_atoi2(const char *str1);
void			ft_print_stacks(t_stack *stack, int max);
int				ft_validate(int argc, char **argv, t_stack *stack);
int				ft_valid(long long int a);
int				ft_double_num(t_stack *stack);
int				ft_put_nums(t_stack *stack, int argc, char **argv);
void			ft_stack_init(t_stack *stack);
void			ft_sa(t_stack *stack, int print);
void			ft_sb(t_stack *stack, int print);
void			ft_ss(t_stack *stack, int print);
void			ft_pb(t_stack *stack, int print);
void			ft_pa(t_stack *stack, int print);
void			ft_ra(t_stack *stack, int print);
void			ft_rb(t_stack *stack, int print);
void			ft_rr(t_stack *stack, int print);
void			ft_rra(t_stack *stack, int print);
void			ft_rrb(t_stack *stack, int print);
void			ft_rrr(t_stack *stack, int print);
void			ft_checker_init(t_stack *stack);
/*
**push_swap
*/
void			ft_alg2(t_stack *stack);
void			ft_201(t_stack *stack);
void			ft_102(t_stack *stack);
void			ft_021(t_stack *stack);
void			ft_012(t_stack *stack);
void			ft_120(t_stack *stack);
void			ft_a_201(t_stack *stack);
void			ft_a_120(t_stack *stack);
void			ft_a_210(t_stack *stack);
void			ft_a_021(t_stack *stack);
int				ft_median_b(t_stack *stack);
int				ft_median_a(t_stack *stack);
void			ft_sort_two_or_three_elements_b_and_pa(t_stack *stack);
void			ft_sort_two_or_three_elements_a(t_stack *stack);
int				ft_push_small_nums_to_b(t_stack *stack, int mid);
int				ft_push_small_nums_to_a(t_stack *stack, int mid);
void			ft_cut_b(t_stack *stack);
void			ft_cut_a(t_stack *stack);

#endif
