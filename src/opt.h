/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:37 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/28 00:20:33 by thschnei         ###   ########.fr       */
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

typedef struct s_app
{
	void	*data;
	t_opt_l	opt;
}	t_app;

void	_optional(const t_app app);

void	_usage(const t_app app);

int		_parse_args(t_app *app, const int ac, const char **av);

t_app	*_init_opt(const char *usage, const t_opt *opt, size_t siz, void *data);

void	_not_enough(const t_app app);

#endif
