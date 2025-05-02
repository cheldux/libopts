# Libopts
this simple C library allows you to easily parse arguments, it is 42 norme compliant so you'll need your own ft_printf to use it.

example program:
```c
typedef struct s_test
{
	char	*str;
	void	*opt_ptr;
}	t_test;

void	assign(void *data, const char **av)
{
	t_test	*var;

	var = (t_test *)data;
	var->str = (char *)*av;
}

void	test(void *data, const char **av)
{
	(void)data;
	(void)av;
	ft_printf("hello\n");
}

void	*init(t_test *s)
{
	void			*ret;
	static t_opt	opts[] = {
	{.s = "-c", .ac = 1, .desc = "assign next arg to app value", .f = assign},
	{.s = "-t", .ac = 0, .desc = "test display", .f = test}};

	ret = _init_opt("test program", opts, sizeof(opts) / sizeof(opts[0]), s);
	return _set_behavior(ret, NO_EXIT);
}

int	main(int argc, char **argv)
{
	t_test	test;

	test.str = "test";
	test.opt_ptr = init(&test);
	ft_printf("value before parsing: %s\n", test.str);
	int used = _parse_args(test.opt_ptr, argc, (const char **)argv);
	ft_printf("value after parsing: %s\n", test.str);
	ft_printf("used %d args out of %d\n", used, argc);
	return (0);
}
```
