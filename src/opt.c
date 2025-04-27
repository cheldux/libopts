/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:35 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/27 20:41:51 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt.h"

int	_loop_args(t_app *app, const int ac, const char **av)
{
	const t_opt		*opt = app->opt.opt;
	int				i;
	unsigned int	j;

	i = 1;
	j = 0;
	while (j < app->opt.s && i < ac)
	{
		if (!ft_strncmp(opt[j].s, av[i], sizeof(av[i]) - 1))
		{
			if (i + 1 + opt[j].ac > ac)
				_not_enough(*app);
			opt[j].f(app->data, &av[++i]);
			i += opt[j].ac;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

void
	_parse_args(t_app *app, const int ac, const char **av)
{
	const int	ret = _loop_args(app, ac, av);

	if (ret != ac)
	{
		ft_dprintf(2, "unknown option: %s\n\n", av[ret]);
		_usage(*app);
		exit(1);
	}
}

void
	_init_opt(const char *usage, const t_opt *opt, size_t siz, t_app *app)
{
	app->opt.usage = usage;
	app->opt.opt = opt;
	app->opt.s = siz;
}
