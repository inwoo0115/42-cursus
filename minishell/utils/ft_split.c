/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:52:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:52:09 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**make_split(char const *s, char c, char **split_word)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (split_word[index] && s[i])
	{
		j = 0;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				split_word[index][j++] = (char)(s[i++]);
			split_word[index][j] = 0;
			index++;
		}
		else
			i++;
	}
	split_word[index] = 0;
	return (split_word);
}

int	num_word(char const *s, char c)
{
	int	check;
	int	num;
	int	i;

	i = 0;
	check = 0;
	num = 0;
	while (s[i])
	{
		if (check == 0 && s[i] != c)
		{
			num++;
			check = 1;
		}
		if (check == 1 && s[i] == c)
			check = 0;
		i++;
	}
	return (num);
}

int	num_letter(char const *s, char c, int i)
{
	int	num;

	num = 0;
	while (s[i] && s[i] != c)
	{
		num++;
		i++;
	}
	return (num);
}

char	**split_free(char **split_word)
{
	int	i;

	i = 0;
	while (split_word[i])
	{
		free(split_word[i]);
		i++;
	}
	free(split_word);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split_word;
	int		i;
	int		num;
	int		index;

	i = 0;
	index = 0;
	num = num_word(s, c);
	split_word = (char **)malloc(sizeof(char *) * (num + 1));
	if (split_word == 0)
		return (0);
	while (i < num)
	{
		while (s[index] == c)
			index++;
		split_word[i] = (char *)malloc(num_letter(s, c, index) + 1);
		if (split_word[i] == 0)
			return (split_free(split_word));
		index = index + num_letter(s, c, index);
		i++;
	}
	make_split(s, c, split_word);
	return (split_word);
}
