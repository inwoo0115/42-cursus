/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:18:51 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/22 16:53:01 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	locate;

	i = 0;
	locate = -1;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == (char)c)
			locate = i;
		i++;
	}
	if (locate != -1)
		return ((char *)&s[locate]);
	return (0);
}
