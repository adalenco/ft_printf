/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 00:12:45 by adalenco          #+#    #+#             */
/*   Updated: 2017/10/10 05:26:30 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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
	char			len[3];
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
	char			x;
}					t_struct;

int					ft_printf(const char *format, ...);
void				ft_print_uint(t_struct *data, unsigned long long int n);
void				ft_print_int(t_struct *data, long long int n);
void				ft_print_char(t_struct *data, char c);
void				ft_print_str(t_struct *data, char *str);
size_t				ft_put_mult(char c, size_t n);
void				ft_parse_conversion(t_struct *data, size_t j);
void				ft_print_wchar(t_struct *data);
void				ft_print_wstr(t_struct *data);
void				ft_print_conversion(t_struct *data, int j);
void				ft_wid_ullnm(t_struct *data, unsigned long long int n);
void				ft_wid_ulln(t_struct *data, unsigned long long int n);
void				ft_print_conversion(t_struct *data, int j);
void				ft_print_ad(t_struct *data, void *p);
void				ft_print_uchar(t_struct *data, unsigned char n);
void				ft_print_schar(t_struct *data, signed char n);
void				ft_print_shortu(t_struct *data, unsigned short int n);
void				ft_print_shorti(t_struct *data, short int n);
int					ft_printf(const char *format, ...);
void				get_width(t_struct *data, size_t i);
void				get_acc(t_struct *data);

#endif
