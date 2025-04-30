/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:37 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/30 05:18:52 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H
# include <stdlib.h>
# include "utils.h"
# include <includes/ft_printf.h>

typedef struct s_opt
{
	const char	*s;
	const char	*desc;
	void		(*f)(void *data, const char **str);
	int			ac;
}	t_opt;

typedef struct s_opt_l
{
	const char	*usage;
	const t_opt	*opt;
	size_t		s;
}	t_opt_l;

typedef struct s_callstack
{
	size_t	*index;
	size_t	size;
	size_t	cap;
}	t_callstack;

typedef struct s_app
{
	void		*data;
	t_opt_l		opt;
	t_callstack	calls;
}	t_app;

void	_optional(const t_app app);

void	_usage(const t_app app);

int		_loop_args(t_app *app, const int ac, const char **av);

int		_parse_args(t_app *app, const int ac, const char **av);

t_app	*_init_opt(const char *usage, const t_opt *opt, size_t siz, void *data);

void	_not_enough(const t_app app);

void	_callstack_append(t_callstack *c, unsigned int i);

void	_callstack_exec(t_app *app, const char **av);

#endif
