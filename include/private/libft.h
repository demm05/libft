/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/17 11:34:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

// ------------------------------------CHAR-----------------------------------
int		ft_isspace(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
long	ft_atol(const char *str);
// ------------------------------------CHAR-----------------------------------
// ----------------------------------STRING-----------------------------------
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char *str, char *charset);
char	*ft_strdup(const char *src);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// -----------------------------------STRING-----------------------------------
// -----------------------------------MEMORY-----------------------------------
void	*ft_realloc(void *ptr, size_t new_size);;
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
// -----------------------------------MEMORY-----------------------------------
// ------------------------------------FILES-----------------------------------
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int num, int fd);
char	*get_next_line(int fd);
// ------------------------------------FILES-----------------------------------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
// ------------------------------------LIST------------------------------------
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// ------------------------------------LIST------------------------------------

typedef struct s_vector
{
	size_t	capacity;
	size_t	size;
	size_t	elem_size;
	void	*data;
}	t_vector;

t_vector	*vec_create(size_t element_type, size_t nmemb);
void		vec_grow(t_vector *vec, size_t nmemb);
void		*vec_get(t_vector *vec, size_t index);
void		vec_insert(t_vector *vec, size_t index, void *data);
void		vec_clear(t_vector *vec, void (*del)(void *));
void		vec_free(t_vector *vec, void (*del)(void *));
void		vec_set(t_vector *vec, size_t index, void *data);
void		vec_remove(t_vector *vec, size_t index);
void		vec_push(t_vector *vec, void *data);

#endif
