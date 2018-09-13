/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:42:20 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 14:11:30 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s == c)
		return ((char*)s);
	while (*s)
	{
		s++;
		if (*s == c)
			return ((char*)s);
	}
	return (NULL);
}
