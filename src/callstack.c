/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:43:35 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/30 05:22:51 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt.h"

inline void
	_callstack_append(t_callstack *c, unsigned int i)
{
	const unsigned long	s = sizeof(c->index);

	if (!c->cap)
	{
		c->cap = 8;
		c->index = malloc(s * c->cap);
	}
	else if (c->cap <= c->size)
	{
		c->index = ft_realloc(c->index, s * c->cap * 2, s * c->cap);
		c->cap *= 2;
	}
	c->index[c->size++] = i;
}

inline void
	_callstack_exec(t_app *app, const char **av)
{
	t_callstack	*c;
	size_t		i;

	c = &app->calls;
	i = 0;
	while (i < app->calls.size)
		app->opt.opt[c->index[i++]].f(app->data, av);
	c->size = 0;
}
