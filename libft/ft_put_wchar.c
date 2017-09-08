/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 22:10:32 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/04 23:57:41 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

static int	ft_put_wchar2(wchar_t wc)
{
	char	c;

	if (wc <= 0xFFFF)
	{
		c = (wc >> 12) + 0xE0;
		write(1, &c, 1);
		c = ((wc >> 6) & 0x3F) + 0x80;
		write(1, &c, 1);
		c = (wc & 0x3F) + 0x80;
		write(1, &c, 1);
		return (3);
	}
	else if (wc <= 0x10FFFF)
	{
		c = (wc >> 18) + 0xF0;
		write(1, &c, 1);
		c = ((wc >> 12) & 0x3F) + 0x80;
		write(1, &c, 1);
		c = ((wc >> 6) & 0x3F) + 0x80;
		write(1, &c, 1);
		c = (wc & 0x3F) + 0x80;
		write(1, &c, 1);
		return (4);
	}
	return (0);
}

int			ft_put_wchar(wchar_t wc)
{
	char	c;

	if (wc <= 0x7F)
	{
		c = wc;
		write(1, &c, 1);
		return (1);
	}
	else if (wc <= 0x7FF)
	{
		c = (wc >> 6) + 0xC0;
		write(1, &c, 1);
		c = (wc & 0x3F) + 0x80;
		write(1, &c, 1);
		return (2);
	}
	return (ft_put_wchar2(wc));
}
