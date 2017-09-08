/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:32:31 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 04:14:38 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t						ft_wstr_acc(t_struct *data, wchar_t *wstr)
{
	size_t					i;
	long long int			acc;
	size_t					size;

	i = 0;
	acc = 0;
	while (wstr[i])
	{
		if (data->acc != -1)
		{
			size = ft_wcharlen(wstr[i]);
			if ((LL)(size + acc) <= data->acc)
				acc += (long long int)size;
			else
			{
				data->acc = acc;
				return (i);
			}
		}
		i++;
	}
	if (data->acc != -1)
		data->acc = acc;
	return (i);
}

void						ft_print_wstr_wid(t_struct *data, wchar_t *wstr)
{
	size_t					acc;
	size_t					i;
	size_t					size;

	acc = ft_wstr_acc(data, wstr);
	size = ft_wstrlen(wstr);
	i = 0;
	if (data->acc == -1)
		data->acc = size;
	if ((long long int)data->wid > data->acc)
	{
		data->nb_char += data->acc != -1 ? \
			ft_put_mult(data->zero, data->wid - data->acc) : \
			ft_put_mult(data->zero, data->wid - size);
	}
	while (i < acc)
	{
		data->nb_char += ft_wcharlen(wstr[i]);
		ft_put_wchar(wstr[i]);
		i++;
	}
}

void						ft_print_wstr_moins(t_struct *data, wchar_t *wstr)
{
	size_t					acc;
	size_t					i;
	size_t					size;

	acc = ft_wstr_acc(data, wstr);
	size = ft_wstrlen(wstr);
	i = 0;
	if (data->zero == '0')
		data->zero = 32;
	while (i < acc)
	{
		data->nb_char += ft_wcharlen(wstr[i]);
		ft_put_wchar(wstr[i]);
		i++;
	}
	if ((long long int)data->wid > data->acc)
	{
		data->nb_char += data->acc != -1 ? \
			ft_put_mult(data->zero, data->wid - data->acc) : \
			ft_put_mult(data->zero, data->wid - size);
	}
}

void						ft_print_wstr(t_struct *data)
{
	wchar_t					*wstr;

	wstr = va_arg(data->ap, wchar_t *);
	if (data->moins == 0)
		ft_print_wstr_wid(data, wstr);
	else
		ft_print_wstr_moins(data, wstr);
}

void						ft_print_wchar(t_struct *data)
{
	wchar_t					cu;

	cu = va_arg(data->ap, wchar_t);
	if (data->wid == 0)
		data->wid = ft_wcharlen(cu);
	if (data->moins == 0)
	{
		data->nb_char += ft_put_mult(data->zero, data->wid - ft_wcharlen(cu));
		data->nb_char += ft_put_wchar(cu);
	}
	else
	{
		data->nb_char += ft_put_wchar(cu);
		data->zero = 32;
		data->nb_char += ft_put_mult(data->zero, data->wid - ft_wcharlen(cu));
	}
}

