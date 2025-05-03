/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libopts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:57 by thschnei          #+#    #+#             */
/*   Updated: 2025/05/03 13:02:48 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBOPTS_H
# define LIBOPTS_H
# include <stdlib.h>

typedef enum e_behavior
{
	NO_RESERVE_HELP = 1 << 0,
	NO_EXIT = 1 << 1,
	NO_PRINT_USAGE = 1 << 2,
	NO_PRINT_ERROR = 1 << 3,
	NO_PRINT = NO_PRINT_ERROR | NO_PRINT_USAGE,
	GET_CALLER = 1 << 4,
	COMBO_ENABLED = 1 << 5,
}	t_behavior;

typedef struct s_opt
{
	const char	*s;
	const char	*desc;
	void		(*f)(void *data, const char **str);
	int			ac;
}	t_opt;

int		
_parse_args(void *opt_ptr, const int ac, const char **av);

void	
*_init_opt(const char *usage, const t_opt *opt, size_t siz, void *data);

void	
*_set_behavior(void *opts, t_behavior behavior);

#endif
