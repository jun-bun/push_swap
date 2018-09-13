/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 02:21:43 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 14:11:30 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** returns the index of char c in string s
** if c does not exist in s then the function returns the size of the string
*/

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (0);
	while (*s != (char)c && *s)
	{
		i++;
		s++;
	}
	return (i);
}
