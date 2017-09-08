#include <string.h>

size_t	ft_unblen(unsigned long long int n)
{
	unsigned long long int div;
	size_t i;

	i = 20;
	div = 10000000000000000000;
	while (n / div == 0)
	{
		i--;
		if (div == 1)
			return (div);
		div /= 10;
	}
	return (i);
}