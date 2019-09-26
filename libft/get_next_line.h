/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:07:47 by mkami             #+#    #+#             */
/*   Updated: 2019/05/08 13:30:12 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 25

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft.h"

typedef struct		s_ok
{
	int			fd;
	char		*content;
	struct s_ok *next;
}					t_ok;

int					get_next_line(const int fd, char **line);

#endif
