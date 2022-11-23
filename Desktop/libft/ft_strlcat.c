/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:59:43 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/22 16:52:14 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	srclen;

	i = 0;
	j = 0;
	start = ft_strlen(dst);
	srclen = ft_strlen(src);
	while (dst[i])
		i++;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (size > ft_strlen(dst))
		return (start + srclen);
	else
		return (srclen + size);
}
