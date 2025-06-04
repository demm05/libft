#include "vector.h"

void	vec_memmove(size_t dest, size_t src, size_t size, t_vector_list *v)
{
	ft_memmove(v->items + dest, v->items + src, v->item_size * size);
}
