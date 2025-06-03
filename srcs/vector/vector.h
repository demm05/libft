#ifndef VECTOR_H
# define VECTOR_H

# include "../../libft.h"

typedef struct s_vector_list
{
	void	**items;
	size_t	capacity;
	size_t	size;
	size_t	item_size;
	void	(*del)(void *);
}	t_vector_list;

t_vector_list	*vec_list_init(size_t capacity, size_t member_size,\
					void (*del)(void *));
void			vec_list_clear(t_vector_list *v);
void			vec_list_free(t_vector_list *v);
int				vec_list_grow(t_vector_list *v, size_t members);

int				vec_push_back(t_vector *v, void *item);

#endif
