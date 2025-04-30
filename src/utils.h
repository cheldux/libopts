/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:40 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/29 20:36:26 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include <malloc.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_realloc(void *ptr, size_t s, size_t is);

int		ft_strlen(const char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
