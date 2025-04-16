/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:50:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/04/16 12:50:37 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	vec_grow(t_vector *vec, size_t nmemb)
{
	void	*new_data;

	if (!vec || nmemb == 0 || nmemb < vec->capacity)
		return ;
	new_data = malloc(nmemb * vec->elem_size);
	if (!new_data)
		return ;
	if (vec->data && vec->size > 0)
		ft_memcpy(new_data, vec->data, vec->size * vec->elem_size);
	free(vec->data);
	vec->data = new_data;
	vec->capacity = nmemb;
}

t_vector	*vec_create(size_t element_type, size_t nmemb)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		return (NULL);
	vec->elem_size = element_type;
	vec->capacity = 0;
	vec->size = 0;
	vec->data = NULL;
	if (nmemb)
		vec_grow(vec, nmemb);
	else
		vec_grow(vec, 5);
	return (vec);
}

void	vec_clear(t_vector *vec, void (*del)(void *))
{
	size_t	i;

	i = 0;
	if (!vec)
		return ;
	if (del)
	{
		while (i < vec->size)
			del(vec_get(vec, i++));
	}
	vec->size = 0;
}

void	vec_free(t_vector *vec, void (*del)(void *))
{
	size_t	i;

	i = 0;
	if (!vec)
		return ;
	if (del)
	{
		while (i < vec->size)
			del(vec_get(vec, i++));
	}
	free(vec->data);
	free(vec);
}
