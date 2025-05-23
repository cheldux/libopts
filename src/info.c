/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:33 by thschnei          #+#    #+#             */
/*   Updated: 2025/05/02 15:04:28 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt.h"

void
	_optional(const t_app app)
{
	const t_opt		*opt = app.opt.opt;
	unsigned int	c;

	c = 0;
	ft_printf("\noptions:\n");
	while (c < app.opt.s)
	{
		ft_printf("\t%s %s\n", opt[c].s, opt[c].desc);
		c++;
	}
}

void
	_usage(const t_app app)
{
	if (!(app.behavior & NO_PRINT_USAGE))
	{
		ft_printf("Usage: %s\n", app.opt.usage);
		_optional(app);
	}
}
