/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:40:10 by aderugo           #+#    #+#             */
/*   Updated: 2022/02/10 16:42:37 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(const char *s, char c)
{
	size_t	flag;
	size_t	counter;

	flag = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c && !flag)
		{
			counter++;
			flag = 1;
		}
		else if (*s == c)
		{
			flag = 0;
		}
		s++;
	}
	return (counter);
}

static void	copy_to_arr(char **arr, const char *s, char c)
{
	int		finish;
	int		start;
	int		size;
	size_t	i;

	finish = 0;
	start = -1;
	size = ft_strlen(s);
	i = 0;
	while (finish <= size)
	{
		if (s[finish] != c && start == -1)
			start = finish;
		else if ((s[finish] == c || finish == size) && start != -1)
		{
			arr[i] = ft_substr(s, start, finish - start);
			i++;
			start = -1;
		}
		finish++;
	}
	arr[i] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	copy_to_arr(arr, s, c);
	return (arr);
}
