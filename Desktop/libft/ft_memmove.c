/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:29:45 by wonjin            #+#    #+#             */
/*   Updated: 2022/11/22 16:49:59 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = dst;
	temp2 = (unsigned char *)src;
	if (temp1 < temp2)
	{
		while (i < len)
		{
			temp1[i] = temp2[i];
			i++;
		}
	}
	else if (temp1 > temp2)
	{
		while (len > 0)
		{
			temp1[len - 1] = temp2[len - 1];
			len--;
		}
	}
	return (dst);
}
