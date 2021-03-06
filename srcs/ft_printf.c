/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 00:03:45 by adalenco          #+#    #+#             */
/*   Updated: 2017/10/10 04:50:33 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_data_init(t_struct *data)
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
	data->x = 0;
}

size_t				ft_put_mult(char c, size_t n)
{
	char			str[n + 1];
	size_t			i;

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

int					ft_parse_format(t_struct *data)
{
	size_t			i;

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
			if (data->fcpy[i + 1] == 0)
				return (0);
			ft_data_init(data);
			data->posi = i;
			ft_parse_conversion(data, i + 1);
			i = data->i + 1;
		}
	}
	return (0);
}

int					ft_printf(const char *format, ...)
{
	t_struct		data;

	va_start(data.ap, format);
	data.nb_char = 0;
	data.fcpy = (char *)format;
	if (format == NULL)
	{
		if ((data.fcpy = va_arg(data.ap, char *)) == NULL)
			data.nb_char += write(1, "(null)", 6);
		else
			data.nb_char = write(1, data.fcpy, ft_strlen(data.fcpy));
	}
	else
		ft_parse_format(&data);
	va_end(data.ap);
	return (data.nb_char);
}
