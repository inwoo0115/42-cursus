/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:27:20 by wonjilee          #+#    #+#             */
/*   Updated: 2022/08/28 16:29:24 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a, char b, char c, char d)
{
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, " ", 1);
    write (1, &c, 1);
    write (1, &d, 1);

}

struct	nums{
	char a;
	char b;
};

struct nums	digit_change(char a, char b)
{
	struct nums t;
	if ( b == '9' )
	{
		t.a = a + 1;
		t.b = '0';
	}
	else
	{
		t.a = a;
		t.b = b + 1;
	}
	return t;
}

void	ft_print_comb2(void)
{
	struct nums first = {'0', '0'};

	while ( first.a != '9' || first.b != '9' )
	{

		struct nums last = digit_change(first.a, first.b);
		while (1)
		{
			ft_putchar(first.a, first.b, last.a, last.b);
			write (1, ", ", 1);
			last  = digit_change(last.a, last.b);
			if (last.a  == '9' || last.b == '9' )
				break;
		}
		struct nums first = digit_change(first.a, first.b);
	}
}

	

int main(void)
{
	void ft_print_comb2();
}


