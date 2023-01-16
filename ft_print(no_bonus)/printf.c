#include <stdio.h>
#include <unistd.h>

int	ft_itoa(unsigned int num)
{
	int		len;
	char	*str;

	str = "0123456789abcdef";
	len = 0;
	if (num == 0)
		return (0);
	len++;
	len += ft_itoa(num / 16);
	if (write(1, &str[num % 16], 1) == -1)
		return (-1);
	return (len);
}


int main ()
{
	int i = 23423422342343;
	int len = ft_itoa(i);
	printf("\n%x", i);
	return (0);
}