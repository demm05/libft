/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:24:21 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/28 19:32:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *s)
{
	long	integer;
	double	fractional;
	double	pow;
	int		sign;

	integer = 0;
	fractional = 0;
	pow = 1;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign *= -1;
	while (*s && *s != '.')
		integer = integer * 10 + (*s++ - '0');
	if ('.' == *s)
		s++;
	while (*s)
	{
		pow /= 10;
		fractional = fractional + (*s++ - '0') * pow;
	}
	return ((integer + fractional) * sign);
}
