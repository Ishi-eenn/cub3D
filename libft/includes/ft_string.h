/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:18:09 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/27 15:36:26 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

# include "ft_stdlib.h"

// ft_memchr.c
void	*ft_memchr(const void *s, int c, size_t n);

// ft_memcmp.c
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// ft_memcpy.c
void	*ft_memcpy(void *dst, const void *src, size_t n);

// ft_memmove.c
void	*ft_memmove(void *dst, const void *src, size_t len);

// ft_memset.c
void	*ft_memset(void *b, int c, size_t len);

// ft_split.c
char	**ft_split(char const *s, char c);

// ft_strchr.c
char	*ft_strchr(const char *s, int c);

// ft_strcmp.c
int		ft_strcmp(const char *s1, const char *s2);

// ft_strdup.c
char	*ft_strdup(const char *s1);

// ft_striteri.c
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);

// ft_strlcat.c
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// ft_strlcpy.c
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// ft_strlen.c
size_t	ft_strlen(const char *s);

// ft_strmapi.c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// ft_strnstr.c
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// ft_strrchr.c
char	*ft_strrchr(const char *s, int c);

// ft_strtrim.c
char	*ft_strtrim(char const *s1, char const *set);

// ft_substr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
