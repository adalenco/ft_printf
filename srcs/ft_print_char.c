/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:35:15 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 04:10:53 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_wid_moins(t_struct *data, char *str)
{
	data->zero = 32;
	if (data->acc != -1 && data->acc < (LL)ft_strlen(str))
		data->nb_char += write(1, str, data->acc);
	else
	{
		ft_putstr(str);
		data->nb_char += ft_strlen(str);
	}
	if (((LL)data->wid > data->acc && data->acc != -1) || \
			(data->wid > ft_strlen(str) && data->acc == -1))
		data->nb_char += data->acc == -1 ? \
			ft_put_mult(data->zero, data->wid - ft_strlen(str)) : \
			ft_put_mult(data->zero, data->wid - (size_t)data->acc);
}

void						ft_wid(t_struct *data, char *str)
{
	if (((LL)data->wid > data->acc && data->acc != -1) || \
			(data->wid > ft_strlen(str) && data->acc == -1))
		data->nb_char += data->acc == -1 ? \
			ft_put_mult(data->zero, data->wid - ft_strlen(str)) : \
			ft_put_mult(data->zero, data->wid - (size_t)data->acc);
	if (data->acc != -1 && data->acc < (LL)ft_strlen(str))
		data->nb_char += write(1, str, data->acc);
	else
	{
		ft_putstr(str);
		data->nb_char += ft_strlen(str);
	}
}

void						ft_print_char(t_struct *data, int j)
{
	char					*str;
	char					c;

	if (j == 0)
	{
		if ((str = va_arg(data->ap, char *)) == NULL)
			data->nb_char += write(1, "(null)", 6);
		else
			data->moins == 0 ? ft_wid(data, str) : ft_wid_moins(data, str);
		return;
	}
	c = va_arg(data->ap, int);
	if (data->wid == 0)
		data->wid = 1;
	if (data->moins == 0)
	{
		data->nb_char += ft_put_mult(data->zero, data->wid - 1) + 1;
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		data->zero = 32;
		data->nb_char += ft_put_mult(data->zero, data->wid - 1) + 1;
	}
}

