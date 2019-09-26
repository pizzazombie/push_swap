# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkami <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 16:28:31 by mkami             #+#    #+#              #
#    Updated: 2019/08/19 13:02:52 by mkami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

CC = gcc $(FLAGS)

FLAGS = -Wall -Wextra -Werror

SRC = checker_program.c \
	put_nums_in_stack.c \
	helpers.c \
	rules_sa_sb_ss_pa_pb.c \
	rules_ra_rb_rra_rrb.c \
	rules_rr_rrr.c \
	checker.c \
	print.c \
	validation.c

SRC2 = ft_push_swap.c \
	put_nums_in_stack.c \
	helpers.c \
	rules_sa_sb_ss_pa_pb.c \
	rules_ra_rb_rra_rrb.c \
	rules_rr_rrr.c \
	print.c \
	validation.c \
	sort_b_commands.c \
	sort_a_commands.c \
	medians.c \
	sort_two_or_three_elements.c \
	cut_and_push.c \
	algorithm.c

OBJ = $(SRC:%.c=%.o)

OBJ2 = $(SRC2:%.c=%.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -I libft/ -c $(SRC)
	@gcc $(FLAGS)  $(OBJ) -L./libft/ -lft -o $(NAME)
	@echo "$(NAME) created successfully"

$(NAME2): $(OBJ2)
	@make -C ./libft/
	@gcc -I libft/ -c $(SRC2)
	@gcc $(FLAGS)  $(OBJ2) -L./libft/ -lft -o $(NAME2)
	@echo "$(NAME2) created successfully"

clean:
	@/bin/rm -f $(OBJ) $(OBJ2)
	@make -C libft/ clean
	@echo "Erasing .o files"

fclean: clean
	@/bin/rm -f $(NAME) $(NAME2)
	@/bin/rm -f libft/libft.a
	@echo "Erasing $(NAME) and $(NAME2)"

re: fclean all clean

.PHONY: all, clean, fclean, re
