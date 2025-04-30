# Libopts
this simple C library allows you to easily parse arguments, it is 42 norme compliant so you'll need your own ft_printf to use it.

example of how to use the lib:
```c
void	fun1(void *data, const char **av);
void	fun2(void *data, const char **av);

void	init(t_app *app)
{
	static t_opt	opts[] = {
	{.s = "-r", .ac = 1, .desc = "function 1 desc", .f = fun1},
	{.s = "-b", .ac = 0, .desc = "function 2 desc", .f = fun2}};

	_init_opt("test program", opts, sizeof(opts) / sizeof(opts[0]), app);
}

int	main(int argc, char **argv)
{
	t_test  test;
	t_app   app;

	app.data = &test;
	init(&app);
	_parse_args(&app, argc, (const char **)argv);
	return (0);
}
```
