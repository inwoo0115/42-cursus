/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:03:21 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/22 16:53:14 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	front_set(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	num;
	size_t	flag;

	flag = 0;
	num = 0;
	i = 0;
	while (s1[i] && flag == 0)
	{
		j = 0;
		flag = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				flag = 0;
				num++;
			}
			j++;
		}
		i++;
	}
	return (num);
}

static size_t	back_set(char const *s1, char const *set)
{
	int		i;
	size_t	j;
	size_t	num;
	size_t	flag;

	flag = 0;
	num = 0;
	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && flag == 0)
	{
		j = 0;
		flag = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				flag = 0;
				num++;
			}
			j++;
		}
		i--;
	}
	return (num);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	size;
	size_t	start;
	size_t	i;

	i = 0;
	start = front_set(s1, set);
	if (ft_strlen(s1) <= start + back_set(s1, set))
		size = 0;
	else
		size = ft_strlen(s1) - back_set(s1, set) - start;
	newstr = (char *)malloc(size + 1);
	if (newstr == 0)
		return (0);
	while (i < size)
	{
		newstr[i] = s1[i + start];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
