/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:17:18 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 11:17:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_memmove(size_t dest, size_t src, size_t size, t_vector_list *v)
{
	ft_memmove(v->items + dest, v->items + src, v->item_size * size);
}
