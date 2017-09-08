/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 01:27:40 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 00:56:14 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

size_t				ft_put_wstr(wchar_t *wstr)
{
	size_t			i;
	size_t			size;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		size += ft_put_wchar(wstr[i]);
		i++;
	}
	return (size);
}
