/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <jodoming@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/16 05:36:32 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 16:23:36 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./incl/fdf.h"

static void	get_size(t_launcher *launcher)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	while (launcher->data[i])
	{
		j = 0;
		x = 0;
		while (launcher->data[i][j])
		{
			if (launcher->data[i][j] >= '0' && launcher->data[i][j] <= '9')
				x++;
			j++;
		}
		i++;
	}
	y = i;
	launcher->width = x;
	launcher->height = y;
	printf("x: %d y: %d\n", launcher->width, launcher->height);
	(void)launcher;
}

static int			**convert_data(char **data, int height, int width)
{
	int		i;
	int		j;
	int		**ret;
	char	**split;

	if (!(ret = (int **)malloc(sizeof(int *) * height)))
		return (NULL);
	i = 0;
	while (i < height)
	{
		ret[i] = malloc(sizeof(int) * width);
		split = ft_strsplit(data[i], ' ');
		j = 0;
		while (split[j])
		{
			ret[i][j] = ft_atoi(split[j]);
			j++;
		}
		i++;
	}
	return (ret);
}

void	create_tabv(t_launcher *launcher)
{
	int i;
	
	launcher->tabv = malloc(sizeof(t_vector3 *) * launcher->height + 1);
	i = 0;
	while (i < launcher->height)
	{
		launcher->tabv[i] = malloc(sizeof(t_vector3) * launcher->width + 1);
		i++;
	}
	launcher->tabv[i] = NULL;
}

void	print_lines(t_launcher *launcher)
{
	int i;
	int j;

	i = 0;
	while (launcher->tabv[i])
	{
			j = 0;
			while (launcher->tabv[i][j])
			{
				if (launcher->tabv[i][j + 1])
					print_line(launcher, launcher->tabv[i][j], launcher->tabv[i][j + 1]);
				if (i < launcher->height - 1 && launcher->tabv[i + 1][j])
					print_line(launcher, launcher->tabv[i][j], launcher->tabv[i + 1][j]);
				j++;
			}
			i++;
	}
}

void	print_map(t_launcher *launcher)
{

	int		i;
	int		j;
	int		color;
	t_vector3 *current;


	i = 0;
	j = 0;
	current = new_vector3(launcher->start_pos->x, 0.0, launcher->start_pos->y);
	while(i < launcher->height)
	{
		while(j < launcher->width)
		{
				if (launcher->tab[i][j] == 0)
					color = 0xFFFFFF;
				else
					color = 0xFF0000;
				mlx_pixel_put(launcher->mlx_ptr, launcher->win_ptr, current->x, current->z + -(launcher->tab[i][j] * launcher->padding_height), color);
				launcher->tabv[i][j] = new_vector3(current->x, 0, current->z + -(launcher->tab[i][j] * launcher->padding_height));
				current->x += launcher->padding;
			j++;
		}
		launcher->tabv[i][j] = NULL;
		i++;
		current->z += launcher->padding;
		j = 0;
		current->x = launcher->start_pos->x;
	}
}

int		main(int ac, char **av)
{
	char	**data;
	int		fd;
	t_launcher	*launcher = NULL;
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
	data = NULL;
	fd = 0;
	if (ac != 2)
		ft_putendl("Usage : ./fdf [MAP].fdf");
	else if (ac == 2)
	{
		if ((fd = (open(av[1], O_RDONLY))))
		{
			if (!(data = ft_strsplit((ft_read_file(fd, 4096)).str, '\n')))
			{
				ft_putendl("Invalid file.");
				return (0);
			}
			else
			{
				launcher = new_launcher(data, 2.0, 5, new_vector2(50.0, 15.0));
				get_size(launcher);
				launcher->tab = convert_data(launcher->data, launcher->height, launcher->width);
				int i = 0, j = 0;

				while (i < launcher->height)
				{
					while (j < launcher->width)
					{
						printf("%d", launcher->tab[i][j]);
						j++;
					}
					printf("\n");
					j = 0;
					i++;
				}

				create_tabv(launcher);
				print_map(launcher);
				print_lines(launcher);
			}
		}
		mlx_loop(launcher->mlx_ptr);
	}
	return (0);
}
