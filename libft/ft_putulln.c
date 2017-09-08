/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ull_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 22:10:47 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/07 22:57:07 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putulln(unsigned long long int n)
{
	size_t i;

	i = 0;
	if (n > 9)
	{
		i += ft_putulln(n / 10);
		ft_putchar(n % 10 + '0');
		return (i + 1);
	}
	else
		ft_putchar(n + '0');
	return (i + 1);
}
