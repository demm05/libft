#include "vector.h"

int	vec_push_back(t_vector *v, void *item)
{
	t_vector_list	*l;
	size_t			new_capacity;

	if (!v)
		return (UNDEFINE);
	l = v->v_list;
	if (l->size >= l->capacity)
	{
		new_capacity = l->capacity * 2;
		if (new_capacity == 0)
			new_capacity = 1;
		if (v->grow(v, new_capacity) == UNDEFINE)
			return (UNDEFINE);
	}
	l->items[l->size] = item;
	l->size++;
	return (SUCCESS);
}
