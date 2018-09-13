/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:40:16 by juwong            #+#    #+#             */
/*   Updated: 2018/07/23 20:59:00 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*make_str(char **content, t_list *l_content)
{
	if (!l_content)
		return (NULL);
	if (l_content->next)
		*content = make_str(content, l_content->next);
	*content = ft_strncat(*content, l_content->content,
				l_content->content_size);
	ft_lstdelone(&l_content, ft_freecontent);
	return (*content);
}

static size_t	get_fd_reads(t_list *l_file_reads, int fd,
				char (*content)[BUFF_SIZE + 1])
{
	t_list		*c;
	char		*n;
	size_t		size;

	c = l_file_reads;
	while (c)
	{
		if ((int)c->content_size == fd)
		{
			n = ft_strchr(c->content, '\n');
			n ? (size = ++n - (char*)c->content)
				: (size = ft_strlen(c->content));
			ft_strncpy(*content, c->content, size);
			if (n)
				c->content = n;
			else
			{
				ft_strclr(c->content);
				c->content_size = 0;
			}
			return (size);
		}
		c = c->next;
	}
	return (0); 
}

static size_t	get_reads(int fd, t_list **l_fr, t_list **l_buff, size_t t)
{
	char		content[BUFF_SIZE + 1];
	char		*ptr_n;
	size_t		bytes_read;

	bytes_read = 1;
	ptr_n = NULL;
	while (bytes_read > 0 && !ptr_n)
	{
		if (!(bytes_read = get_fd_reads(*l_fr, fd, &content)))
			bytes_read = read(fd, content, BUFF_SIZE);
		content[bytes_read] = '\0';
		if ((ptr_n = ft_memchr(content, '\n', bytes_read)))
		{
			*ptr_n++ = '\0';
			if (ft_strlen(ptr_n) > 0)
			{
				ft_lst_pushfront(l_fr, ptr_n, ft_strlen(ptr_n) + 1);
				bytes_read -= (*l_fr)->content_size - 1;
				(*l_fr)->content_size = (size_t)fd;
			}
		}
		(bytes_read > 0) ? ft_lst_pushfront(l_buff, content, bytes_read) : t;
		t += bytes_read;
	}
	return (t);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*l_file_reads;
	t_list			*l_buff;
	char			*c;
	size_t			total_bytes;

	total_bytes = 0;
	l_buff = NULL;
	c = NULL;
	if (fd < 0 || !line || read(fd, c, 0) < 0)
		return (-1);
	total_bytes = get_reads(fd, &l_file_reads, &l_buff, total_bytes);
	if (total_bytes <= 0)
		return (0);
	CHECKNULL((*line = ft_strnew(total_bytes)));
	make_str(line, l_buff);
	return (1);
}
