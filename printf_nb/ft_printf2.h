#ifndef FT_PRINTF
# define FT_PRINTF
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_struct
{
	va_list			ap;
	size_t			nb_char;
	char			*fmtcpy;
	char 			len[3];
	size_t			wid;
	long long int	acc;
	int				i;
	int				posi;
	char ash;
	char moins;
	char plus;
	char j;
	char z;
	char zero;
	size_t size;
	size_t nblen;
}				t_struct;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_unblen(long long int n);
void	ft_print_uint(t_struct *data, unsigned long long int n);
void	ft_print_int(t_struct *data, long long int n);

#endif
