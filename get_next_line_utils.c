/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:03:13 by namatias          #+#    #+#             */
/*   Updated: 2025/08/30 09:59:08 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = ft_strlen(s);
	dup = malloc ((i + 1) * sizeof(const char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*ptr;

	if (s == NULL)
		return (ft_strdup(""));
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	i = 0;
	while (i < len && s[start + i] != '\0')
		i++;
	ptr = malloc ((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	protect(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	int		size;

	if (!s1)
		size_s1 = 0;
	else
		size_s1 = ft_strlen(s1);
	if (!s2)
		size_s2 = 0;
	else
		size_s2 = ft_strlen(s2);
	size = size_s1 + size_s2;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	str = malloc ((protect(s1, s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			str[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i])
			str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}