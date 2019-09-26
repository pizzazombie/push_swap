/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:01:41 by mkami             #+#    #+#             */
/*   Updated: 2019/04/11 20:37:50 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list *begin_list, t_list *nw)
{
	t_list *p;

	p = begin_list;
	while (p->next != NULL)
		p = p->next;
	p->next = nw;
}
