/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:17:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 11:17:05 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector_list	*vec_list_init(size_t capacity, size_t item_size, \
					void (*del)(void *))
{
	t_vector_list	*v;

	v = malloc(sizeof(t_vector_list));
	if (!v)
		return (NULL);
	v->items = malloc(item_size * capacity);
	if (!v->items)
	{
		free(v);
		return (NULL);
	}
	v->capacity = capacity;
	v->size = 0;
	v->del = del;
	v->item_size = item_size;
	return (v);
}

void	vec_list_clear(t_vector_list *v)
{
	size_t	i;

	if (!v)
		return ;
	i = 0;
	if (v->del)
		while (i < v->size)
			v->del(v->items[i++]);
	v->size = 0;
}

void	vec_list_free(t_vector_list *v)
{
	if (!v)
		return ;
	vec_list_clear(v);
	free(v->items);
	v->items = NULL;
}

int	vec_list_grow(t_vector_list *v, size_t capacity)
{
	void	**new_items;
	void	**old_items;

	if (!v)
		return (UNDEFINE);
	if (capacity <= v->capacity && capacity >= v->size)
		return (SUCCESS);
	if (capacity < v->size)
		return (UNDEFINE);
	new_items = malloc(capacity * v->item_size);
	if (!new_items)
		return (UNDEFINE);
	if (v->items && v->size > 0)
		ft_memcpy(new_items, v->items, v->size * v->item_size);
	old_items = v->items;
	v->items = new_items;
	v->capacity = capacity;
	free(old_items);
	return (SUCCESS);
}
