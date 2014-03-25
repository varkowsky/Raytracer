/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 17:39:23 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/25 20:59:37 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_set_sphere_rad(char **line, int fd, double *radius)
{
	get_next_line(fd, line);
	if (ft_check_if_nbr(*line) == -1)
		ft_error("[ERROR SCENE] - Sphere's radius is not a digit");
	*radius = ft_atod(line);
}

static void		ft_set_sphere_origin(t_data *data, char **line, int fd)
{
	get_next_line(fd, line);
	if (ft_check_if_nbr(*line) == -1)
		ft_error("[ERROR SCENE] - Sphere's origin x is not a digit");
	data->x = ft_atod(line);
	get_next_line(fd, line);
	if (ft_check_if_nbr(*line) == -1)
		ft_error("[ERROR SCENE] - Sphere's origin y is not a digit");
	data->y = ft_atod(line);
	get_next_line(fd, line);
	if (ft_check_if_nbr(*line) == -1)
		ft_error("[ERROR SCENE] - Sphere's origin z is not a digit");
	data->z = ft_atod(line);
}

static void		ft_set_sphere_color(t_data *data, char **line, int fd)
{
	get_next_line(fd, line);
	if (ft_check_if_nbr(*line) == -1)
		ft_error("[ERROR SCENE] - Sphere's color RED is not a digit");
	data->x2 = ft_atoi(*line);
	get_next_line(fd, line);
	if (ft_check_if_nbr(*line) == -1)
		ft_error("[ERROR SCENE] - Sphere's color GREEN is not a digit");
	data->y2 = ft_atoi(*line);
	get_next_line(fd, line);
	if (ft_check_if_nbr(*line) == -1)
		ft_error("[ERROR SCENE] - Sphere's color BLUE is not a digit");
	data->z2 = ft_atoi(*line);
}

void			ft_set_sphere(t_data *data, char **line, int fd)
{
	double		radius;

	while (ft_strcmp("#end_object", *line) != 0)
	{
		if (ft_strcmp("#radius", *line) == 0)
			ft_set_sphere_rad(line, fd, &radius);
		else if (ft_strcmp("#origin", *line) == 0)
			ft_set_sphere_origin(data, line, fd);
		else if (ft_strcmp("#color", *line) == 0)
			ft_set_sphere_color(data, line, fd);
		get_next_line(fd, line);
	}
	sphere_new(vector_new(data->x, data->y, data->z), radius \
	, color_norm((int)data->x2, (int)data->y2, (int)data->z2));
}
