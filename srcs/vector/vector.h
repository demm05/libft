/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:17:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/06/23 11:17:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

typedef struct s_vector_list	t_vl;

typedef struct s_vector_list
{
	void	**items;
	size_t	capacity;
	size_t	size;
	size_t	item_size;
	void	(*del)(void *);
}	t_vector_list;

t_vl	*vec_list_init(size_t capacity, size_t member_size, \
					void (*del)(void *));
void	vec_list_clear(t_vector_list *v);
void	vec_list_free(t_vector_list *v);
int		vec_list_grow(t_vector_list *v, size_t members);

int		vec_push_back(t_vector *v, void *item);
int		vec_push_front(t_vector *v, void *item);
int		vec_get(t_vector *v, size_t index, void **dest);
size_t	vec_size(t_vector *v);
int		vec_insert(t_vector *v, size_t index, void *item);
void	vec_set_defaults(t_vector *v);
void	*vec_direct_get(t_vector *v, size_t index);
void	vec_memmove(size_t dest, size_t src, size_t size, t_vl *v);

void	vector_clear(t_vector *v);
void	vector_free(t_vector *v);
int		vector_grow(t_vector *v, size_t new_capacity);

#endif
