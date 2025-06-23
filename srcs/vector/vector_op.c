/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:17:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 11:17:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_get(t_vector *v, size_t index, void **dest)
{
	if (!v || !dest || !v->v_list)
		return (UNDEFINE);
	if (index >= v->v_list->size)
		return (UNDEFINE);
	*dest = v->v_list->items[index];
	return (SUCCESS);
}

void	*vec_direct_get(t_vector *v, size_t index)
{
	if (!v || !v->v_list || index >= v->v_list->size)
		return (NULL);
	return (v->v_list->items[index]);
}

size_t	vec_size(t_vector *v)
{
	if (!v || !v->v_list)
		return (0);
	return (v->v_list->size);
}
