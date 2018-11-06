/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 18:27:01 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/27 21:04:51 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"
#include "libft.h"

int		eb_debug(char *str, int free_str)
{
	t_data	*data;

	data = data_init();
	if (!DEBUG || !data->debug) {
		if (free_str)
			free(str);
		return 0;
	}
	ft_putstr("[DEBUG] ");
	ft_putendl(str);
	if (free_str)
		eb_help_atextf(str);
	else
		eb_help_atext(str);
	return 1;
}

void	eb_debug_object(void *object)
{
	char	*str;
	t_data	*data;

	data = data_init();
	if (!DEBUG || !data->debug) {
		return;
	}
	if (((t_struct *)object)->type == 's')
		str = print_sphere((t_sphere *)object);
	else if (((t_struct *)object)->type == 'p')
		str = print_plan((t_plan *)object);
	else if (((t_struct *)object)->type == 'c')
		str = print_cylinder((t_cylind *)object);
	else if (((t_struct *)object)->type == 'o')
		str = print_cone((t_cone *)object);
	eb_debug(str, 1);
}
