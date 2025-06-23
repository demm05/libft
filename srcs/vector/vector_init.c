/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:17:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 11:17:01 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vec_set_defaults(t_vector *v)
{
	if (!v)
		return ;
	v->clear = vector_clear;
	v->free = vector_free;
	v->grow = vector_grow;
	v->push_back = vec_push_back;
	v->push_front = vec_push_front;
	v->get = vec_get;
	v->size = vec_size;
	v->insert = vec_insert;
	v->dget = vec_direct_get;
}

int	vector_init(t_vector *v, void (*del)(void *), size_t capacity)
{
	if (!v)
		return (UNDEFINE);
	v->v_list = vec_list_init(capacity, sizeof(void *), del);
	if (!v->v_list)
		return (UNDEFINE);
	vec_set_defaults(v);
	return (SUCCESS);
}
