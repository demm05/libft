/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:38:13 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/03/22 17:42:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	char	*new;
	size_t	cur_size;

	if (!ptr)
		return (malloc(new_size));
	cur_size = sizeof(ptr);
	if (new_size <= cur_size)
		return (ptr);
	new = malloc(new_size);
	ft_memcpy(new, ptr, cur_size);
	free(ptr);
	return (new);
}
