/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:44:31 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/08 01:03:09 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int		ft_power(int n, int power)
{
	unsigned long long int	res;

	res = 1;
	if (power == 0)
		return (res);
	if (power == 1)
		return ((unsigned long long int)n);
	while (power > 0)
	{
		res *= n;
		power--;
	}
	return (res);
}
