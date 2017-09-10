/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 03:12:20 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 04:12:06 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_int(t_struct *data, long long int n)
{
	if (data->acc == -1)
		data->acc++;
	else
		data->zero = 32;
	if (data->plus != 0 || n < 0)
		data->size++;
	if (n < 0)
	{
		n = -n;
		data->plus = '-';
	}
	data->nblen = ft_unblen((unsigned long long int)n);
	if ((LL)(data->size = data->nblen) < data->acc)
		data->size = (size_t)data->acc;
	if (data->plus != 0 || n < 0)
		data->size++;
	if (n < 0)
	{
		n = -n;
		data->plus = '-';
	}
	data->moins == 0 ? \
	ft_wid_ulln(data, (unsigned long long int)n) : \
	ft_wid_ullnm(data, (unsigned long long int)n);
}

void		ft_print_uint(t_struct *data, unsigned long long int n)
{
	data->nblen = ft_unblen_base(n, data->base);
	if (data->ash == 1 && data->base == 8 && \
			data->acc <= (long long int)data->nblen)
		data->acc = data->nblen + 1;
	if (data->acc == -1)
		data->acc++;
	else
		data->zero = 32;
	if ((LL)(data->size = data->nblen) < data->acc)
		data->size = (size_t)data->acc;
	if (data->plus != 0)
		data->size++;
	data->moins == 0 ? \
	ft_wid_ulln(data, n) : \
	ft_wid_ullnm(data, n);
}

static void	ft_put_ad(void *p)
{
	unsigned long adr;
	char *base;
	char res[9];
	int i;
 
 	res[8] = '\0';
	adr = (unsigned long) p;
	base = "0123456789ABCDEF";
	i = 7;
	while (i > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	while (i < 9)
	{
		putchar (res[i]);
		i++;
	}
}

void		ft_print_ad(t_struct *data, void *p)
{
	if (data->moins == 0)
	{
		if (data->wid > 8)
			data->nb_char += ft_put_mult(' ', data->wid - 8);
		ft_put_ad(p);
		data->nb_char += 8;
	}
	else
	{
		ft_put_ad(p);
		data->nb_char += 8;
		if (data->wid > 8)
			data->nb_char += ft_put_mult(' ', data->wid - 8);
	}
}