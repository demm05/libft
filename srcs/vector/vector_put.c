#include "vector.h"

static inline int	resize_if_nedeed(t_vector *v)
{
	if (v->v_list->size < v->v_list->capacity)
		return (SUCCESS);
	if (v->v_list->capacity == 0)
		return (v->grow(v, 1));
	else
		return (v->grow(v, v->v_list->capacity * 2));
}

int	vec_push_back(t_vector *v, void *item)
{
	if (!v)
		return (UNDEFINE);
	if (resize_if_nedeed(v) == UNDEFINE)
		return (UNDEFINE);
	v->v_list->items[v->v_list->size] = item;
	v->v_list->size++;
	return (SUCCESS);
}

int	vec_push_front(t_vector *v, void *item)
{
	t_vector_list	*l;

	if (!v)
		return (UNDEFINE);
	if (resize_if_nedeed(v) == UNDEFINE)
		return (UNDEFINE);
	l = v->v_list;
	vec_memmove(1, 0, v->size(v), l);
	l->items[0] = item;
	l->size++;
	return (SUCCESS);
}

int	vec_insert(t_vector *v, size_t index, void *item)
{
	t_vector_list	*l;

	if (!v || !v->v_list)
		return (UNDEFINE);
	if (index >= v->v_list->size)
		return (v->push_back(v, item));
	if (resize_if_nedeed(v) == UNDEFINE)
		return (UNDEFINE);
	l = v->v_list;
	vec_memmove(index + 1, index, v->size(v) - index, l);
	l->items[index] = item;
	l->size++;
	return (SUCCESS);
}

void	*vec_pop(t_vector *v, size_t index)
{
	t_vector_list	*l;
	void			*item;

	if (!v || !v->v_list || index >= v->v_list->size)
		return (NULL);
	l = v->v_list;
	if (l->size == 1)
	{
		l->size = 0;
		return (l->items[0]);
	}
	item = l->items[index];
	vec_memmove(index, index + 1, v->size(v) - index, l);
	l->size--;
	return (item);
}
