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
