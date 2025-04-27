/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:57 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/28 00:52:25 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H
# include <stdlib.h>

typedef struct s_opt
{
	const char	*s;
	const char	*desc;
	void		(*f)(void *data, const char **str);
	int			ac;
}	t_opt;

int		_parse_args(void *opt_ptr, const int ac, const char **av);

void	*_init_opt(const char *usage, const t_opt *opt, size_t siz, void *data);

#endif
