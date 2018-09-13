/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 23:21:55 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 14:11:30 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				l;

	l = ft_intlen(n);
	if (n < 0)
	{
		if (!(str = ft_strnew(++l)))
			return (NULL);
		*str = '-';
		n = -n;
	}
	else if (n >= 0)
	{
		if (!(str = ft_strnew(l)))
			return (NULL);
	}
	while (--l >= 0 && str[l] != '-')
	{
		str[l] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
