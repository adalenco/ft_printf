/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:42:01 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/13 00:14:57 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_shorti(t_struct *data, short int n)
{
	long long int	ln;

	ln = (LL)n;
	ft_print_int(data, ln);
}

void				ft_print_shortu(t_struct *data, unsigned short int n)
{
	long long int	ln;

	ln = (LL)n;
	ft_print_int(data, ln);
}

void				ft_print_schar(t_struct *data, signed char n)
{
	long long int	ln;

	ln = (LL)n;
	ft_print_int(data, ln);
}

void				ft_print_uchar(t_struct *data, unsigned char n)
{
	long long int	ln;

	ln = (LL)n;
	ft_print_int(data, ln);
}
