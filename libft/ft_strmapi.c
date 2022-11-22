/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:05:51 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/22 16:52:40 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s);
	i = 0;
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
