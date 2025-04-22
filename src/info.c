#include "opt.h"

void	_optional(t_app app)
{
	const char		*flags[] = {"-g <width> <height>",
		"both values should be between 200 and 2000.",
		"-c <real> <imaginary>",
		"is only used for julia rendering,",
		"both values should be between 2.0 and -2.0."};
	unsigned int	c;

	c = 0;
	printf("\noptional arguments:\n");
	while (c < sizeof(flags) / sizeof(void *))
		printf("\t%s\n", flags[c++]);
}

void	_mandatory(t_app app)
{

}

void	_usage(t_app app, char **av)
{
	printf("usage:%s\n", av[0]);
	_optional(app);
}
