/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unblen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:39:50 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 00:56:48 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t						ft_unblen(unsigned long long int n)
{
	unsigned long long int	div;
	size_t					i;

	i = 20;
	div = 10000000000000000000U;
	while (n / div == 0)
	{
		i--;
		if (div == 1)
			return (div);
		div /= 10;
	}
	return (i);
}
