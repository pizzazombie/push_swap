/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:10:45 by mkami             #+#    #+#             */
/*   Updated: 2019/04/12 17:57:48 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *u;

	u = (t_list *)malloc(sizeof(*u));
	if (u == NULL)
		return (NULL);
	if (content == NULL)
	{
		u->content = NULL;
		u->content_size = 0;
		u->next = NULL;
		return (u);
	}
	if (!((u->content = malloc(content_size)) == NULL))
	{
		u->content = ft_memcpy(u->content, content, content_size);
		u->content_size = content_size;
		u->next = NULL;
	}
	return (u);
}
