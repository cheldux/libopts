/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:37 by thschnei          #+#    #+#             */
/*   Updated: 2025/05/02 15:25:28 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H
# include <stdlib.h>
# include "utils.h"
# include <includes/ft_printf.h>

typedef enum e_behavior
{
	NO_HELP = 1 << 0,
	NO_EXIT = 1 << 1,
	NO_PRINT_USAGE = 1 << 2,
	NO_PRINT_ERROR = 1 << 3,
	GET_CALLER = 1 << 4,
	COMBO_ENABLED = 1 << 5,
}	t_behavior;

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
	t_behavior	behavior;
}	t_app;

void	_optional(const t_app app);

void	_usage(const t_app app);

int		_loop_args(t_app *app, const int ac, const char **av);

int		_parse_args(t_app *app, const int ac, const char **av);

t_app	*_init_opt(const char *usage, const t_opt *opt, size_t siz, void *data);

t_app	*_set_behavior(t_app *app, t_behavior behavior);

void	_not_enough(const t_app app);

void	_callstack_append(t_callstack *c, unsigned int i);

void	_callstack_exec(t_app *app, const char **av);

#endif
