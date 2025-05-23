#include "libft.h"

t_vector	*vec_create_int(size_t nmemb)
{
	t_vector	*vec;

	vec = vec_create(sizeof(int), nmemb);
	return (vec);
}

bool	vec_get_int(t_vector *vec, size_t index, int *res)
{
	int	*temp;

	temp = vec_get(vec, index);
	if (temp)
		*res = *temp;
	return (temp != NULL);
}

void		vec_insert_int(t_vector *vec, size_t index, int data)
{
	vec_insert(vec, index, &data);
}

void		vec_set_int(t_vector *vec, size_t index, int data)
{
	vec_set(vec, index, &data);
}

void		vec_push_int(t_vector *vec, int data)
{
	vec_push(vec, &data);
}
