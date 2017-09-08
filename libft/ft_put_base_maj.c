/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 02:30:22 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 02:49:58 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_put_base_maj(unsigned long long n, int base)
{
	size_t		i;
	char		*strbase;

	i = 0;
	strbase = "0123456789ABCDEF";
	if (n / base > 0)
	{
		i = ft_put_base_maj(n / base, base);
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
