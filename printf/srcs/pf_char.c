/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:39:58 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/16 19:33:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

char	*pf_char(va_list val, t_spec_info *s_info)
{
	char	c;
	int		i;

	c = va_arg(val, int);
	i = 1;
	s_info->is_char = 1;
	s_info->flags.zero = 0;
	if (s_info->width && !s_info->flags.minus)
	{
		while (i++ < s_info->width)
			_putchar(' ', s_info->fd);
	}
	_putchar(c, s_info->fd);
	return (ft_strdup(""));
}

char	*pf_37(va_list val, t_spec_info *s_info)
{
	char	*buffer;

	(void)val;
	s_info->flags.zero = 0;
	buffer = malloc(sizeof(char) * 2);
	buffer[0] = '%';
	buffer[1] = 0;
	return (buffer);
}
