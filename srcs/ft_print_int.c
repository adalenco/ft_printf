/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 03:12:20 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/13 00:14:58 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_print_int2(t_struct *data, long long int n)
{
	if (n < 0)
	{
		n = -n;
		data->plus = '-';
	}
	if (data->acc != -1)
		data->zero = 32;
	if (data->acc == 0 && n == 0)
	{
		data->nblen = 0;
		data->size = 0;
	}
	data->moins == 0 ? \
	ft_wid_ulln(data, (ULL)n) : \
	ft_wid_ullnm(data, (ULL)n);
}

void					ft_print_int(t_struct *data, long long int n)
{
	if (data->plus != 0 || n < 0)
		data->size++;
	if (n < 0)
	{
		n = -n;
		data->plus = '-';
	}
	data->nblen = ft_unblen((ULL)n);
	if ((LL)(data->size = data->nblen) < data->acc)
		data->size = (size_t)data->acc;
	if (data->plus != 0 || n < 0)
		data->size++;
	ft_print_int2(data, n);
}

void					ft_put_ad(t_struct *data, void *p)
{
	unsigned long long	adr;
	char				*base;
	char				res[19];
	int					i;

	adr = (ULL)p;
	i = ft_unblen_base(adr, 16) + 1;
	data->nb_char += i + 1;
	res[i + 1] = '\0';
	base = "0123456789abcdef";
	while (i > 1)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[1] = 'x';
	res[0] = '0';
	ft_putstr(res);
}

void					ft_print_ad(t_struct *data, void *p)
{
	size_t				size;

	size = ft_unblen_base((ULL)p, 16) + 2;
	if (data->moins == 0)
	{
		if (data->wid > size)
			data->nb_char += ft_put_mult(' ', data->wid - size);
		if (p == 0 && data->acc == 0)
			data->nb_char += write(1, "0x", 2);
		else
			ft_put_ad(data, p);
	}
	else
	{
		if (p == 0 && data->acc == 0)
			data->nb_char += write(1, "0x", 2);
		else
			ft_put_ad(data, p);
		if (data->wid > size)
			data->nb_char += ft_put_mult(' ', data->wid - size);
	}
}

void					ft_print_uint(t_struct *data, unsigned long long int n)
{
	data->nblen = ft_unblen_base(n, data->base);
	if (data->ash == 1 && data->base == 8 && \
			data->acc <= (LL)data->nblen && n != 0)
		data->acc = data->nblen + 1;
	if (data->ash == 1 && data->base == 8 && \
			data->acc <= (LL)data->nblen && n == 0)
		data->acc = data->nblen;
	if ((LL)(data->size = data->nblen) < data->acc)
		data->size = (size_t)data->acc;
	if (data->ash == 1 && data->base == 16)
		data->size += 2;
	if (data->plus == '+' || data->plus == ' ')
		data->plus = 0;
	if (data->plus != 0)
		data->size++;
	if (data->acc == 0 && n == 0 && data->base == 8)
		data->nblen = 1;
	if (data->acc == 0 && n == 0)
	{
		data->nblen = 0;
		data->size = 0;
	}
	data->moins == 0 ? \
	ft_wid_ulln(data, n) : \
	ft_wid_ullnm(data, n);
}
