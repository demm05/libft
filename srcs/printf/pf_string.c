/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:42:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 19:33:55 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	_pf_putstr(char *s, int fd)
{
	if (!s)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}

char	*pf_string(va_list val, t_spec_info *s_info)
{
	char	*s;

	s = va_arg(val, char *);
	s_info->flags.zero = 0;
	if (!s)
	{
		if (s_info->precision <= 5 && s_info->is_precision)
			return (ft_strdup(""));
		s = "(null)";
	}
	if (s_info->is_precision)
		return (ft_substr(s, 0, s_info->precision));
	return (ft_strdup(s));
}
