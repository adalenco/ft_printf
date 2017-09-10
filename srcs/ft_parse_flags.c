/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:08:45 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 03:45:52 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int							ft_no_conversion(t_struct *data, char c)
{
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
	return (1);
}

static void						ft_parse_flags3(t_struct *data, int j)
{
	int							i;

	i = 0;
	if (j == 10 && data->l == 0)
		data->l = 2;
	if (j == 6)
	{
		if (data->l == 0 || data->l == 1)
			data->l++;
		else
			data->l--;
	}
	else if (j == 7)
		data->j = 1;
	else if (j == 8)
		data->z = 1;
	else if (j == 9)
	{
		i = data->i + 1;
		data->acc = ft_atoi(data->fcpy + i);
		while (data->fcpy[i] <= '9' && data->fcpy[i] >= '0')
			i++;
		data->i = i - 1;
	}
}

static void						ft_parse_flags2(t_struct *data, int j)
{
	if (j == 0)
		data->ash = 1;
	else if (j == 1)
		data->zero = 48;
	else if (j == 2)
		data->plus = '+';
	else if (j == 3)
		data->moins = 1;
	else if (j == 4 && data->plus == 0)
		data->plus = ' ';
	else if (j == 11 && data->h == 0)
		data->h = 2;
	else if (j == 5)
	{
		if (data->h == 0 || data->h == 1)
			data->h++;
		else
			data->h--;
	}
	else
		ft_parse_flags3(data, j);
}

int								ft_parse_flags(t_struct *data, size_t i)
{
	char	*mask;
	int		j;

	j = 0;
	mask = "#0+- hljz.LH";
	while (mask[j])
	{
		if (mask[j] == data->fcpy[i])
		{
			ft_parse_flags2(data, j);
			return (0);
		}
		j++;
	}
	if (data->fcpy[i] <= '9' && data->fcpy[i] >= '1')
	{
		data->wid = ft_atoi(data->fcpy + i);
		while (data->fcpy[i] <= '9' && data->fcpy[i] >= '0')
		{
			if (data->fcpy[i] == 0)
				return (1);
			i++;
		}
		data->i = i - 1;
	}
	else
		return (ft_no_conversion(data, data->fcpy[i]));
	return (0);
}

void						ft_parse_conversion(t_struct *data, size_t i)
{
	int		j;
	char	*mask;

	j = 0;
	mask = "scSCdDiuUoOxXbp";
	while (data->fcpy[i])
	{
		data->i = i;
		j = 0;
		while(mask[j])
		{
			if (data->fcpy[i] == mask[j])
			{
				ft_print_conversion(data, j);
				return;
			}
			j++;
		}
		if (ft_parse_flags(data, i) == 1)
			return;
		i = data->i + 1;
	}
	return;
}

