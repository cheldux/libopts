#include "opt.h"

void	optional(void)
{
	const char		*flags[] = {"-g <width> <height>",
		"both values should be between 200 and 2000.",
		"-c <real> <imaginary>",
		"is only used for julia rendering,",
		"both values should be between 2.0 and -2.0."};
	unsigned int	c;

	c = 0;
	ft_printf("\noptional arguments:\n");
	while (c < sizeof(flags) / sizeof(void *))
		ft_printf("\t%s\n", flags[c++]);
}

void	usage(void)
{
	ft_printf("usage:\n");
	optional();
}

void	not_enough(void)
{
	ft_dprintf(2, "not enough arguments provided.\n");
	usage();
	exit(1);
}


void	check_end(int ac, int i, char **av)
{
	if (i != ac)
	{
		ft_dprintf(2, "unknown option: %s\n\n", av[i]);
		usage();
		exit(1);
	}
}

void parse_args(t_app *app, int c, char **v)
{
	const t_opt		opt[] = {(t_opt){"-g", set_geometry, 2},
		(t_opt){"-t", set_render, 1},
		(t_opt){"-c", set_constant, 2}};
	t_app			ret;
	int				i;
	unsigned int	j;

	ft_memset(&ret, 0, sizeof(t_app));
	i = 0;
	j = 0;
	while (j < sizeof(opt) / sizeof(opt[0]) && i < c)
	{
		if (!ft_strncmp(opt[j].s, v[i], sizeof(opt[j].s) - 1))
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
	check_end(ac, i, av);
	return (ret);
}

void	init_opt(t_opt *opt, t_app *app)
{
	app->opt = opt;
}
