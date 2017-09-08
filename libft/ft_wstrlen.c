/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 23:42:48 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 00:56:29 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

size_t			ft_wstrlen(wchar_t *wstr)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		size += ft_wcharlen(wstr[i]);
		i++;
	}
	return (size);
}
