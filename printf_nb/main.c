#include "ft_printf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void get_hex_ad(void const *p)
{
   unsigned long adr;
   char const *base;
   char res[9];
   int i;
 
   adr = (unsigned long) p;
   base = "0123456789ABCDEF";
   i = 8;
   while ((adr / 16) > 0 || i >= 8)
   {
      res[i] = base[(adr % 16)];
      adr /= 16;
      i--;
   }
   res[i] = base[(adr % 16)];
   putchar ('0');
   putchar ('0');
   while (i < 9)
   {
      putchar (res[i]);
      i++;
   }
}

size_t	ft_nblen(long long int n)
{
	long long int div;
	size_t i;

	i = 19;
	div = 1000000000000000000;
	while (n / div == 0)
	{
		i--;
		if (div == 1)
		{
			if (n < 0)
				div++;
			return (div);
		}
		div /= 10;
	}
	if (n < 0)
		i++;
	return (i);
}

int			main(int ac, char **av)
{
	char *str;
	unsigned long p;

	str = "yolo";
	char str2[2];
	p = (unsigned long)str;
	int c = -1234567;
	int		i = -0; 
	//j = ft_nblen((long long int)i);
	i = printf("%hld", c);


	printf("\n%d", i);
	//printf("%d\n", j);

		//printf("%p\n", &j);
		i++;
	return (0);
}