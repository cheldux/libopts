#ifndef OPT_H
# define OPT_H
# include <stdlib.h>
# include <libs/ft_printf.h>

typedef struct s_opt
{
	const char	*s;
	const char	*desc;
	void		(*f)(void *app, char **str);
	int			ac;
}	t_opt;

typedef struct s_app
{
	void		*data;
	static t_opt	*opt;
}	t_app;

#endif
