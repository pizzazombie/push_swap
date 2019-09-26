/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:07:59 by mkami             #+#    #+#             */
/*   Updated: 2019/05/07 18:30:32 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*ft_strjoin2(char *s1, char *s2)
{
	char *str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		str = ft_strnew(ft_strlen(s2));
	else
		str = (char *)malloc(sizeof(char) *
				(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
		str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	if (s1 != NULL)
		free(s1);
	return (str);
}

t_ok	*ft_makelist(int fd)
{
	t_ok *new;

	new = (t_ok *)malloc(sizeof(t_ok));
	if (new == NULL)
		return (NULL);
	new->content = NULL;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

t_ok	*ft_findlist(t_ok *list, t_ok *runner, int fd)
{
	runner = list;
	while (fd != runner->fd && runner->next != NULL)
		runner = runner->next;
	if ((int)runner->fd == fd)
		return (runner);
	runner->next = ft_makelist(fd);
	runner = runner->next;
	return (runner);
}

int		ft_rewrite(char **line, t_ok *runner, int r)
{
	char *temp;
	char *str;

	if (r == 0 && (runner->content == NULL || runner->content[0] == '\0'))
		return (0);
	temp = ft_strchr(runner->content, '\n');
	if (temp == NULL)
	{
		*line = ft_strdup(runner->content);
		free(runner->content);
		runner->content = NULL;
		return (1);
	}
	temp[0] = '\0';
	*line = ft_strdup(runner->content);
	str = ft_strdup(temp + 1);
	temp[0] = '\n';
	free(runner->content);
	runner->content = str;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			r;
	char		buff[BUFF_SIZE + 1];
	static t_ok	*list;
	t_ok		*runner;

	if (fd < 0 || fd > 20240 || BUFF_SIZE <= 0 ||
			line == NULL || (r = read(fd, buff, 0)) < 0)
		return (-1);
	if (list == NULL)
		list = ft_makelist(fd);
	runner = list;
	runner = ft_findlist(list, runner, fd);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		runner->content = ft_strjoin2(runner->content, buff);
		if (ft_strchr(runner->content, '\n') != NULL)
			break ;
	}
	if (r < 0)
		return (-1);
	return (ft_rewrite(line, runner, r));
}
