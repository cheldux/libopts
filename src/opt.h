#ifndef OPT_H
# define OPT_H
#include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include "utils.h"

typedef struct s_opt
{
	const char	*s;
	const char	*desc;
	void		(*f)(void *app, char **str);
	int			ac;
}	t_opt;

typedef struct s_opt_l
{
	const t_opt	*opt;
	size_t		s;
}	t_opt_l;

typedef struct s_app
{
	void			*data;
	const t_opt_l	opt;
}	t_app;

void	_optional(t_app app);

void	_usage(t_app app, char **av);

void	_parse_args(t_app *app, int ac, char **av);

void	_init_opt(t_opt *opt, t_app app);

void	_not_enough(t_app app, char **av);

void	_check_end(int ac, int i, t_app app, char **av);

#endif
