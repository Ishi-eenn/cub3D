/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:58:34 by tsishika          #+#    #+#             */
/*   Updated: 2023/12/14 16:01:38 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


// void	ft_realloc(char **str, size_t size)
// {
// 	size_t	i;
// 	char	**tmp;

// 	i = 0;
// 	tmp = malloc(sizeof(char *) * size);
// 	while (str[i])
// 	{
// 		tmp[i] = str[i];
// 		i++;
// 	}
// 	free(str);
// 	str = tmp;
// }

// char	**ft_realloc(char **str, size_t size)
// {
// 	size_t	i;
// 	char	**tmp;

// 	i = 0;
// 	tmp = malloc(sizeof(char *) * (size + 1));
// 	// while (i <= size)
// 	while (str[i] && i < size)
// 	{
// 		tmp[i] = str[i];
// 		i++;
// 	}
// 	// free(str);
// 	return (tmp);
// }

// char **ft_realloc(char **prev, size_t i) {
// 	// Allocate memory for the new array
// 	char **new_array = malloc((i + 1) * sizeof(char *));

// 	// Copy the elements from the previous array to the new array
// 	for (size_t j = 0; j < i; j++) {
// 		new_array[j] = prev[j];
// 	}

// 	// Free the memory of the previous array
// 	free(prev);

// 	return new_array;
// }


char	**ft_realloc(char **str, size_t size)
{
	size_t	i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char *) * (size + 1));
	// while (i <= size)
	while (str[i] && i < size)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = NULL;
	// free(str);
	return (tmp);
}
