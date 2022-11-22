/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:38:54 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/14 22:05:20 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if ((count * size < count) || (count * size < size))
		return (0);
	tmp = (void *)malloc(size * count);
	if (tmp == 0)
		return (0);
	ft_bzero(tmp, count * size);
	return (tmp);
}
