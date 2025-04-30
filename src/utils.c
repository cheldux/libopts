/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:39 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/30 05:19:07 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void
	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr2;

	i = 0;
	ptr1 = dest;
	ptr2 = src;
	if (!dest)
		return (dest);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}

void
	*ft_realloc(void *ptr, size_t s, size_t is)
{
	char	*tmp;

	if (s < is)
		return (ptr);
	tmp = malloc(s);
	ft_memcpy(tmp, ptr, is);
	free(ptr);
	ptr = tmp;
	return (ptr);
}

int
	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				cnt;
	unsigned const char	*ls1;
	unsigned const char	*ls2;

	ls1 = (unsigned const char *)s1;
	ls2 = (unsigned const char *)s2;
	cnt = 0;
	while (ls1[cnt] && ls2[cnt] && ls1[cnt] == ls2[cnt] && cnt < n)
		cnt++;
	if (cnt == n)
		return (0);
	return (ls1[cnt] - ls2[cnt]);
}
