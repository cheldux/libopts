/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:35 by thschnei          #+#    #+#             */
/*   Updated: 2025/05/02 14:12:53 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt.h"

int
	_parse_args(t_app *app, const int ac, const char **av)
{
	const int	ret = _loop_args(app, ac, av);

	if (app->calls.index)
		free(app->calls.index);
	return (ret);
}

t_app
	*_init_opt(const char *usage, const t_opt *opt, size_t siz, void *data)
{
	static t_app	app;

	app.data = data;
	app.opt.usage = usage;
	app.opt.opt = opt;
	app.opt.s = siz;
	app.calls.cap = 0;
	app.calls.size = 0;
	app.calls.index = 0;
	app.behavior = 0;
	return (&app);
}

t_app	*_set_behavior(t_app *app, t_behavior behavior)
{
	app->behavior = behavior;
	return (app);
}
