/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <jodoming@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 15:15:08 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 15:27:58 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./incl/fdf.h"

static void                drawline_point(t_launcher *options, int step,
		t_vector3 *a, t_vector3 *b)
{
	int                i;
	double            xi;
	double            yi;
	t_vector2        pix;

	pix.x = a->x;
	pix.y = a->z;
	xi = (double)(b->x - a->x) / step;
	yi = (double)(b->z - a->z) / step;
	i = -1;
	while (++i <= step)
	{
		mlx_pixel_put(options->mlx_ptr, options->win_ptr, pix.x, pix.y, 0x0AACCFF);
		pix.x = a->x + round((double)i * xi);
		pix.y = a->z + round((double)i * yi);
	}
}

void                    print_line(t_launcher *options, t_vector3 *a,
		t_vector3 *b)
{
	int    step;

	if (fabs(a->x - b->x) <= fabs(a->y - b->y))
		step = 1 + fabs(a->z - b->z);
	else
		step = 1 + fabs(a->x - b->x);
	drawline_point(options, step, a, b);
}

t_vector2        *new_vector2(double x, double y)
{
	t_vector2 *ret;

	ret = malloc(sizeof(t_vector2));
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_vector3        *new_vector3(double x, double y, double z)
{
	t_vector3 *ret;

	ret = malloc(sizeof(t_vector3));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}
