#include "opt.h"

void	_parse_args(t_app *app, int c, char **v)
{
	const t_opt		*opt = app->opt;
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < sizeof(opt) / sizeof(opt[0]) && i < c)
	{
		if (!ft_strncmp(opt[j].s, v[i], sizeof(v[i]) - 1))
		{
			if (i + 1 + opt[j].ac > c)
				not_enough();
			opt[j].f(app, &v[++i]);
			i += opt[j].ac;
			j = 0;
		}
		else
			j++;
	}
	_check_end(c, i, v);
}

void	_init_opt(t_opt *opt, t_app *app)
{
	app->opt = opt;
}
