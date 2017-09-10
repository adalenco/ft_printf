#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <inttypes.h>
# include "../libft/includes/libft.h"
# define ULL unsigned long long int
# define LL long long int

typedef struct		s_struct
{
	va_list			ap;
	int				nb_char;
	char			*fcpy;
	char 			len[3];
	size_t			wid;
	char			*str_wid;
	size_t			i;
	long long int	acc;
	size_t			posi;
	char			ash;
	char			zero;
	char			moins;
	char			plus;
	char			j;
	char			z;
	char			l;
	char			h;
	int				base;
	size_t			size;
	size_t			nblen;
	char			X;
}					t_struct;

int					ft_printf(const char *format, ...);
void				ft_print_uint(t_struct *data, unsigned long long int n);
void				ft_print_int(t_struct *data, long long int n);
void				ft_print_char(t_struct *data, int j);
size_t				ft_put_mult(char c, size_t n);
void				ft_parse_conversion(t_struct *data, size_t j);
void				ft_print_wchar(t_struct *data);
void				ft_print_wstr(t_struct *data);
void				ft_print_conversion(t_struct *data, int j);
void				ft_wid_ullnm(t_struct *data, unsigned long long int n);
void				ft_wid_ulln(t_struct *data, unsigned long long int n);
void				ft_print_conversion(t_struct *data, int j)

#endif
