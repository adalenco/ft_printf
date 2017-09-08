/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_wid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 03:12:23 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 04:13:48 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wid_ulln3(t_struct *data, unsigned long long int n)
{
	if (data->plus != 0)
		data->nb_char += write(1, &data->plus, 1);
	if (data->acc > (LL)data->nblen)
		data->nb_char += ft_put_mult('0', data->acc - data->nblen);
	if (data->ash == 1 && data->base == 16)
	{
		if (data->X == 1)
			data->nb_char += write(1, "0X", 2);
		else
			data->nb_char += write(1, "0x", 2);
	}
	if (data->X == 1)
		data->nb_char += ft_put_base_maj(n, data->base);
	else
		data->nb_char += ft_put_base(n, data->base);
}

static void	ft_wid_ulln2(t_struct *data, unsigned long long int n)
{
	data->nb_char += ft_put_mult(' ', data->wid - data->size);
	if (data->plus != 0)
		data->nb_char += write(1, &data->plus, 1);
	if (data->acc > (LL)data->nblen)
		data->nb_char += ft_put_mult('0', data->acc - data->nblen);
	if (data->ash == 1 && data->base == 16)
	{
		if (data->X == 1)
			data->nb_char += write(1, "0X", 2);
		else
			data->nb_char += write(1, "0x", 2);
	}
	if (data->X == 1)
		data->nb_char += ft_put_base_maj(n, data->base);
	else
		data->nb_char += ft_put_base(n, data->base);
}

void		ft_wid_ulln(t_struct *data, unsigned long long int n)
{
	if (data->wid > data->size && data->zero == '0')
	{
		if (data->plus != 0)
			data->nb_char += write(1, &data->plus, 1);
		data->nb_char += ft_put_mult('0', (data->wid - data->size));
		if (data->ash == 1 && data->base == 16)
		{
			if (data->X == 1)
				data->nb_char += write(1, "0X", 2);
			else
				data->nb_char += write(1, "0x", 2);
		}
		if (data->X == 1)
			data->nb_char += ft_put_base_maj(n, data->base);
		else
			data->nb_char += ft_put_base(n, data->base);
	}
	else if (data->wid > data->size)
		ft_wid_ulln2(data, n);
	else
		ft_wid_ulln3(data, n);
}

void		ft_wid_ullnm(t_struct *data, unsigned long long int n)
{
	if (data->zero == '0')
		data->zero = 32;
	if (data->plus != 0)
		data->nb_char += write(1, &data->plus, 1);
	if (data->acc > (LL)data->nblen)
		data->nb_char += ft_put_mult('0', data->acc - data->nblen);
	if (data->ash == 1 && data->base == 16)
	{
		if (data->X == 1)
			data->nb_char += write(1, "0X", 2);
		else
			data->nb_char += write(1, "0x", 2);
	}
	if (data->X == 1)
		data->nb_char += ft_put_base_maj(n, data->base);
	else
		data->nb_char += ft_put_base(n, data->base);
	if (data->wid > data->size)
		data->nb_char += ft_put_mult(' ', data->wid - data->size);
}
