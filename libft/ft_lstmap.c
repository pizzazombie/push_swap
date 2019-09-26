/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:34:39 by mkami             #+#    #+#             */
/*   Updated: 2019/04/12 17:50:02 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *u;
	t_list *p;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((u = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	u = f(lst);
	p = u;
	u = u->next;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((u = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		u = f(lst);
		ft_list_push_back(p, u);
		lst = lst->next;
		u = u->next;
	}
	return (p);
}
