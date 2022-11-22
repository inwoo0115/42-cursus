/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:16:02 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/22 16:53:27 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	lens;
	size_t	size;

	i = 0;
	lens = ft_strlen(s);
	if (lens <= start)
		size = 0;
	else if (len >= lens - start)
		size = lens - start;
	else
		size = len;
	substr = (char *)ft_calloc(1, size + 1);
	if (!(substr))
		return (0);
	if (lens < start)
		return (substr);
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
