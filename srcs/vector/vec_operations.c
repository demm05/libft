/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:50:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/04/16 12:50:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*vec_get(t_vector *vec, size_t index)
{
	if (!vec || index >= vec->size)
		return (NULL);
	return ((char *)vec->data + (index * vec->elem_size));
}

void	vec_set(t_vector *vec, size_t index, void *data)
{
	if (!vec || index >= vec->size)
		return ;
	ft_memcpy(
		(char *)vec->data + (index * vec->elem_size),
		data,
		vec->elem_size);
}

void	vec_remove(t_vector *vec, size_t index)
{
	if (!vec || index >= vec->size)
		return ;
	ft_memmove(
		(char *)vec->data + index * vec->elem_size,
		(char *)vec->data + (index + 1) * vec->elem_size,
		(vec->size - index) * vec->elem_size);
	vec->size--;
}

void	vec_push(t_vector *vec, void *data)
{
	if (!vec)
		return ;
	vec_insert(vec, vec->size, data);
}

void	vec_insert(t_vector *vec, size_t index, void *data)
{
	if (!vec)
		return ;
	if (vec->size >= vec->capacity)
	{
		if (vec->capacity == 0)
			vec_grow(vec, 1);
		else
			vec_grow(vec, vec->capacity * 2);
		if (vec->capacity == 0)
			return ;
	}
	if (index < vec->size)
		ft_memmove(
			(char *)vec->data + (index + 1) * vec->elem_size,
			(char *)vec->data + index * vec->elem_size,
			(vec->size - index) * vec->elem_size);
	ft_memcpy(
		(char *)vec->data + index * vec->elem_size,
		data,
		vec->elem_size);
	vec->size++;
}
