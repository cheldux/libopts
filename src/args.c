/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:28:19 by thschnei          #+#    #+#             */
/*   Updated: 2025/05/02 15:39:16 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt.h"
#include "utils.h"

static inline unsigned int
	_parse_combo(t_app *app, const char **av, int *i)
{
	const t_opt		*opt = app->opt.opt;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	k = 1;
	while (j < app->opt.s && *(av[*i] + k))
	{
		if (*(opt[j].s + 1) == *(av[*i] + k))
		{
			if (!opt[j].ac && k++)
				_callstack_append(&app->calls, j);
			else
				break ;
		}
		else
			j++;
	}
	if (*(av[*i] + k))
		return (app->opt.s);
	(*i)++;
	_callstack_exec(app, av);
	return (j);
}

static inline unsigned int
	_simple_hyphen(t_app *app, const int ac, const char **av, int *i)
{
	const t_opt		*opt = app->opt.opt;
	unsigned int	j;

	j = 0;
	if ((app->behavior & COMBO_ENABLED) && ft_strlen(av[*i]) > 2)
		return (_parse_combo(app, av, i));
	while (j < app->opt.s)
	{
		if (!ft_strncmp(opt[j].s, av[*i], ft_strlen(av[*i])))
		{
			if (*i + 1 + opt[j].ac > ac)
			{
				_not_enough(*app);
				return (app->opt.s);
			}
			if (!(app->behavior & GET_CALLER))
				(*i)++;
			opt[j].f(app->data, &av[*i]);
			*i += opt[j].ac + 1 * !!(app->behavior & GET_CALLER);
			break ;
		}
		else
			j++;
	}
	return (j);
}

static inline unsigned int
	_double_hyphen(t_app *app, const int ac, const char **av, int *i)
{
	const t_opt		*opt = app->opt.opt;
	unsigned int	j;

	j = 0;
	while (j < app->opt.s)
	{
		if (!ft_strncmp(opt[j].s, av[*i], ft_strlen(av[*i])))
		{
			if (*i + 1 + opt[j].ac > ac)
			{
				_not_enough(*app);
				return (app->opt.s);
			}
			if (!(app->behavior & GET_CALLER))
				(*i)++;
			opt[j].f(app->data, &av[*i]);
			*i += opt[j].ac;
			break ;
		}
		else
			j++;
	}
	return (j);
}

int
	_loop_args(t_app *app, const int ac, const char **av)
{
	int				i;
	unsigned int	j;

	i = 1;
	j = 0;
	while (j < app->opt.s && i < ac && *av[i] == '-')
	{
		if (!ft_strncmp(av[i], "--", 2))
		{
			if (!(app->behavior & NO_HELP) && !ft_strncmp(av[i], "--help", 6))
			{
				_usage(*app);
				return (-1);
			}
			j = _double_hyphen(app, ac, av, &i);
		}
		else
			j = _simple_hyphen(app, ac, av, &i);
	}
	return (i);
}
