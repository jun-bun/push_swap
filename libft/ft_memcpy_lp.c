/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_lp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 01:06:52 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 14:11:30 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Returns the pointer at the end of memcpy
*/

void	*ft_memcpy_lp(void *dst, const void *src, size_t n)
{
	while (n > 0)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		n--;
	}
	return (dst);
}
