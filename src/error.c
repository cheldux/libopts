/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thschnei <thschnei@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:31 by thschnei          #+#    #+#             */
/*   Updated: 2025/04/27 22:05:00 by thschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt.h"

void
	_not_enough(const t_app app)
{
	ft_dprintf(2, "not enough arguments provided.\n");
	_usage(app);
	exit(1);
}
