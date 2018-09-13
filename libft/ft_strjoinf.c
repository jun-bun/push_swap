/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:52:37 by juwong            #+#    #+#             */
/*   Updated: 2018/08/30 16:00:01 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoinf(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char*)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	ptr = str;
	str = ft_memcpy_lp(str, s1, len_s1);
	str = ft_memcpy_lp(str, s2, len_s2);
	*str = '\0';
	free(s1);
	return (ptr);
}
