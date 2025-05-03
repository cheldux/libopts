/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:31 by thschnei          #+#    #+#             */
/*   Updated: 2025/05/03 12:58:53 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt.h"

int
	_not_enough(const t_app app)
{
	if (!(app.behavior & NO_PRINT_ERROR))
		ft_dprintf(2, "not enough arguments provided.\n");
	if (app.calls.index)
		free(app.calls.index);
	_usage(app);
	if (!(app.behavior & NO_EXIT))
		exit(1);
	return (-1);
}
