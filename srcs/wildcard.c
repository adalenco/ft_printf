/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 05:25:25 by adalenco          #+#    #+#             */
/*   Updated: 2017/10/10 05:29:42 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_acc(t_struct *data)
{
	size_t		i;
	int			acc;

	i = data->i + 1;
	if (data->fcpy[i] == '*')
	{
		data->i = i;
		if ((acc = va_arg(data->ap, int)) < 0)
			return ;
		data->acc = acc;
	}
	else
	{
		data->acc = ft_atoi(data->fcpy + i);
		while (data->fcpy[i] <= '9' && data->fcpy[i] >= '0')
			i++;
		data->i = i - 1;
	}
}

void			get_width(t_struct *data, size_t i)
{
	int			wid;

	if (data->fcpy[i] == '*')
	{
		if ((wid = va_arg(data->ap, int)) < 0)
		{
			wid = -wid;
			data->wid = (size_t)wid;
			data->moins = 1;
		}
		else
			data->wid = (size_t)wid;
		data->i = i;
	}
	else
	{
		data->wid = ft_atoi(data->fcpy + i);
		while (data->fcpy[i] <= '9' && data->fcpy[i] >= '0')
			i++;
		data->i = i - 1;
	}
}
