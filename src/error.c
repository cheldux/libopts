#include "opt.h"

void	_not_enough(t_app app, char **av)
{
	dprintf(2, "not enough arguments provided.\n");
	_usage(app, av);
	exit(1);
}

void	_check_end(int ac, int i, t_app app, char **av)
{
	if (i != ac)
	{
		dprintf(2, "unknown option: %s\n\n", av[i]);
		_usage(app, av);
		exit(1);
	}
}

