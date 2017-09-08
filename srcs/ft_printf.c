/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 00:03:45 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 05:40:10 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static void					ft_data_init(t_struct *data)
{
	data->ash = 0;
	data->wid = 0;
	data->zero = 32;
	data->moins = 0;
	data->plus = 0;
	data->acc = -1;
	data->l = 0;
	data->h = 0;
	data->j = 0;
	data->z = 0;
	data->base = 10;
	data->size = 0;
	data->nblen = 0;
	data->X = 0;
}

size_t						ft_put_mult(char c, size_t n)
{
	char					str[n + 1];
	size_t					i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	write(1, str, n);
	return (n);
}

void						ft_print_conversion(t_struct *data, int j)
{
	if (j == 9 || j == 10)
		data->base = 8;
	if (j == 11 || j == 12)
		data->base = 16;
	if (j == 12)
		data->X = 1;
	if (data->z == 1)
	{
		if (j >= 7 && j <= 12)
		{
			ft_print_uint(data, (ULL)va_arg(data->ap, size_t));
			return;
		}
	}
	if ((j == 0 || j == 1) && data->l != 1)
		ft_print_char(data, j);
	else if (j == 3 || (j == 1 && data->l == 1))
		ft_print_wchar(data);
	else if (j == 2 || (j == 0 && data->l == 1))
		ft_print_wstr(data);
	else if ((j == 4 || j == 6) && \
			(data->l == 0 && data->h == 0 && data->z == 0))
		ft_print_int(data, (LL)va_arg(data->ap, int));
	else if (((j == 4 || j == 6) && (data->l == 1 || data->z == 1)) || \
			(j == 5 && ((data->l == 0 && data->h == 0) || data->l == 1 )))
		ft_print_int(data, (LL)va_arg(data->ap, long int));
	else if ((j >= 4 && j <= 6) && data->l == 2)
		ft_print_int(data, va_arg(data->ap, long long int));
	else if ((j >= 7 && j <= 12 && j != 10) && data->l == 0 && data->h == 0)
		ft_print_uint(data, (ULL)va_arg(data->ap, unsigned int));
	else if (((j >= 7 && j <= 12 && j != 10) && data->l == 1) || \
			((j == 8 || j == 10) && (data->l == 0 && data->h == 0)))
		ft_print_uint(data, (ULL)va_arg(data->ap, unsigned long int));
	else if ((j >= 7 && j <= 12) && data->l == 2)
		ft_print_int(data, va_arg(data->ap, unsigned long long int));
}

int							ft_parse_format(t_struct *data)
{
	size_t	i;

	i = 0;
	while (data->fcpy[i])
	{
		if (data->fcpy[i] != '%')
		{
			ft_putchar(data->fcpy[i]);
			i++;
			data->nb_char++;
		}
		 else
		{
			ft_data_init(data);
			data->posi = i;
			ft_parse_conversion(data, i + 1);
			i = data->i + 1;
		}
	}
	return (0);
}

int							ft_printf(const char *format, ...)
{
	t_struct	data;

	va_start(data.ap, format);
	data.nb_char = 0;
	data.fcpy = (char *)format;
	if (format == NULL)
	{
		if ((data.fcpy = va_arg(data.ap, char *)) == NULL)
			data.nb_char += write(1, "(null)", 6);
		else
			data.nb_char = ft_strlen(data.fcpy);
			ft_putstr(data.fcpy);
	}
	else
		ft_parse_format(&data);
	va_end(data.ap);
	return (data.nb_char);
}
