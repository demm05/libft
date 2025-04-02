/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:11:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:32:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static inline int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_strchr(charset, str[i]))
			i++;
	}
	return (count);
}

static inline int	free_array(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
	return (0);
}

static inline char	*get_word(char *str, char *charset, int *ptr_i)
{
	int		i;
	char	*word;
	int		len;

	len = 0;
	while (str[len] && !ft_strchr(charset, str[len]))
		len++;
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	*ptr_i += i;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
		if (str[i])
		{
			arr[j] = get_word(str + i, charset, &i);
			if (!arr[j++])
			{
				free_array(arr, j - 1);
				return (NULL);
			}
		}
	}
	arr[j] = 0;
	return (arr);
}
