/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:26:41 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/12 23:48:44 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_print_conversion3(t_struct *data, int j)
{
	if ((j >= 7 && j <= 13 && j != 10 && j != 8) \
			&& data->l == 0 && data->h == 0)
		ft_print_uint(data, (ULL)va_arg(data->ap, unsigned int));
	else if (((j >= 7 && j <= 13) && data->l == 1) || \
			(j == 8 || j == 10))
		ft_print_uint(data, (ULL)va_arg(data->ap, unsigned long int));
	else if ((j >= 7 && j <= 13) && data->l == 2)
		ft_print_uint(data, va_arg(data->ap, unsigned long long int));
	else if (data->h == 1 && data->l == 0)
	{
		if (j >= 4 && j <= 6)
			ft_print_shorti(data, va_arg(data->ap, int));
		if (j >= 7 && j <= 13)
			ft_print_shortu(data, (ULL)va_arg(data->ap, int));
	}
	else if (data->h == 2 && data->l == 0)
	{
		if (j >= 4 && j <= 6)
			ft_print_schar(data, (LL)va_arg(data->ap, int));
		if (j >= 7 && j <= 13)
			ft_print_uchar(data, (ULL)va_arg(data->ap, int));
	}
}

void						ft_print_conversion2(t_struct *data, int j)
{
	if (data->z == 1)
	{
		if (j >= 4 && j <= 6)
			ft_print_int(data, va_arg(data->ap, long long int));
		if (j >= 7 && j <= 13)
			ft_print_uint(data, (ULL)va_arg(data->ap, size_t));
		return ;
	}
	if (data->j == 1)
	{
		if (j >= 4 && j <= 6)
			ft_print_int(data, (LL)va_arg(data->ap, intmax_t));
		if (j >= 7 && j <= 13)
			ft_print_uint(data, (ULL)va_arg(data->ap, uintmax_t));
		return ;
	}
	if ((j == 4 || j == 6) && (data->l == 0 && data->h == 0))
		ft_print_int(data, (LL)va_arg(data->ap, int));
	else if (((j >= 4 && j <= 6) && data->l == 1) || \
			(j == 5 && (data->l == 0)))
		ft_print_int(data, (LL)va_arg(data->ap, long int));
	else if ((j >= 4 && j <= 6) && data->l == 2)
		ft_print_int(data, va_arg(data->ap, long long int));
	else
		ft_print_conversion3(data, j);
}

void						ft_print_conversion(t_struct *data, int j)
{
	if (j == 0 && data->l != 1)
		ft_print_str(data, va_arg(data->ap, char *));
	else if (j == 1 && data->l == 0)
		ft_print_char(data, va_arg(data->ap, int));
	else if (j == 3 || (j == 1 && data->l == 1))
		ft_print_wchar(data);
	else if (j == 2 || (j == 0 && data->l == 1))
		ft_print_wstr(data);
	else if (j == 14)
		ft_print_ad(data, va_arg(data->ap, void *));
	else
	{
		if (j == 13)
			data->base = 2;
		else if (j == 9 || j == 10)
			data->base = 8;
		else if (j == 11 || j == 12)
			data->base = 16;
		if (j == 12)
			data->X = 1;
		ft_print_conversion2(data, j);
	}
}
