/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:21:33 by juwong            #+#    #+#             */
/*   Updated: 2018/09/11 14:11:30 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Takes as a parameter the address of a memory area that needs to be freed
** with free(3), then puts the pointer to NULL.
** Param. #1  A pointer’s address that needs its memory freed and set to NULL.
*/

void	ft_memdel(void **ap)
{
	if (ap == NULL || *ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}
