/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:39 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/27 20:24:42 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
		ptr[i++] = c;
	return (s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
