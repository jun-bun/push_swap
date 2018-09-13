/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 19:51:58 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 14:11:30 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** The strlcat() function appends the NUL-terminated string src to the end
** of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi-
** nating the result.
*/

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstsize <= dstl)
		return (srcl + dstsize);
	dst = dst + dstl;
	i = dstl;
	while (i++ < dstsize - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dstl + srcl);
}
