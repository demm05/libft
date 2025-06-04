#include "vector.h"

t_vector	*vector_create(void (*del)(void *), size_t capacity)
{
	t_vector	*v;

	v = malloc(sizeof(t_vector));
	if (!v)
		return (0);
	if (vector_init(v, del, capacity) == UNDEFINE)
	{
		free(v);
		return (NULL);
	}
	return (v);
}

void	vector_clear(t_vector *v)
{
	if (!v || !v->v_list)
		return ;
	vec_list_clear(v->v_list);
}

void	vector_free(t_vector *v)
{
	if (!v || !v->v_list)
		return ;
	vec_list_free(v->v_list);
	free(v->v_list);
	v->v_list = NULL;
}

int	vector_grow(t_vector *v, size_t new_capacity)
{
	if (!v || !v->v_list)
		return (UNDEFINE);
	return (vec_list_grow(v->v_list, new_capacity));
}
