/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:53:21 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 00:55:59 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_put_base(unsigned long long n, int base)
{
	size_t		i;
	char		*strbase;

	i = 0;
	strbase = "0123456789abcdef";
	if (n / base > 0)
	{
		i = ft_put_base(n / base, base);
		ft_putchar(strbase[n % base]);
		i++;
	}
	else
	{
		ft_putchar(strbase[n % base]);
		i++;
	}
	return (i);
}
