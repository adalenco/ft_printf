/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unblen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 01:20:36 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:38 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_unblen_base(unsigned long long n, int base)
{
	size_t		i;

	i = 0;
	if (n / base > 0)
	{
		i = ft_unblen_base(n / base, base);
		i++;
	}
	else
		i++;
	return (i);
}
