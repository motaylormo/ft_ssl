/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:45:26 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/09 13:17:43 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_listnew(int fd, t_gnl *prev, t_gnl *next)
{
	t_gnl	*i;

	if (!(i = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	i->str = NULL;
	i->overflow = NULL;
	i->fd = fd;
	i->next = NULL;
	i->prev = NULL;
	if (prev)
	{
		i->prev = prev;
		prev->next = i;
	}
	if (next)
	{
		i->next = next;
		next->prev = i;
	}
	return (i);
}

static t_gnl	*listfetch(t_gnl *list, int fd)
{
	if (!(list))
		return (ft_listnew(fd, NULL, NULL));
	while ((int)list->fd < fd && list)
	{
		if (!list->next)
			list->next = ft_listnew(fd, list, NULL);
		list = list->next;
	}
	while ((int)list->fd > fd && list)
	{
		if (!list->prev)
			list->prev = ft_listnew(fd, NULL, list);
		list = list->prev;
	}
	if ((int)list->fd == fd)
	{
		list->str = NULL;
		return (list);
	}
	return (NULL);
}

static char		*get_overflow(char *old, char buf[])
{
	int		n;
	char	*new;

	free(old);
	if ((ft_strchr(buf, '\n')))
	{
		n = ft_strchrindex(buf, '\n') + 1;
		new = ft_strsub(buf, n, BUFF_SIZE - n);
		if (ft_strcmp(new, ""))
			return (new);
		free(new);
	}
	return (NULL);
}

static char		*update_str(char *str, char *buf)
{
	char	*temp;
	char	*buf_seg;

	if (str == NULL && buf[0] == '\0')
		return (NULL);
	if ((ft_strchr(buf, '\n')))
		buf_seg = ft_strsub(buf, 0, ft_strchrindex(buf, '\n'));
	else
		buf_seg = ft_strdup(buf);
	if (str != NULL)
	{
		temp = ft_strjoin(str, buf_seg);
		free(str);
	}
	else
		temp = ft_strdup(buf_seg);
	free(buf_seg);
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	char			buf[BUFF_SIZE + 1];
	int				read_return;

	RET_IF((BUFF_SIZE < 1 || fd < 0 || !line || read(fd, buf, 0) < 0), -1);
	ft_bzero(buf, BUFF_SIZE + 1);
	RET_IF(((list = listfetch(list, fd)) == 0), -1);
	if (list->overflow != NULL)
		ft_strcpy(buf, list->overflow);
	read_return = (ft_strchr(buf, '\n')) ? ft_strlen(buf) : BUFF_SIZE;
	while ((ft_strchr(buf, '\n') == 0) && (read_return == BUFF_SIZE))
	{
		list->str = update_str(list->str, buf);
		read_return = read(fd, buf, BUFF_SIZE);
		RET_IF((read_return < 0), -1);
		RET_IF((read_return == 0
					&& list->str == NULL && list->overflow == NULL), 0);
		buf[read_return] = '\0';
	}
	list->overflow = get_overflow(list->overflow, buf);
	list->str = update_str(list->str, buf);
	RET_IF(!(list->str), -1);
	*line = list->str;
	return (1);
}
