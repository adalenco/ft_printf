/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:42:32 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/12 23:57:27 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>
#include <limits.h>

int			main(void)
{
	int yo;

	printf("retour : %d\n", ft_printf("%#.o", 42));
	//printf("retour : %d\n", ft_printf("%S\n", NULL));
	printf("retour : %d\n", printf("%#.o", 42));
	return (0);
}
