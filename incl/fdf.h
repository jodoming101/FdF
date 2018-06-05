/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <jodoming@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/16 05:02:22 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 16:18:58 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct		s_reader
{
	int				rd;
	char			*str;
}					t_reader;

typedef struct		s_map
{
	char	**d_map;	//map data
	int		h;			//height
	int		w;			//width
}					t_map;

typedef struct s_vector2
{
	double x;
	double y;
}				t_vector2;

typedef struct s_vector3
{
	double x;
	double y;
	double z;
}				t_vector3;


typedef struct		s_launcher
{
	t_map	*map;
	char	**data;
	int		**tab;
	int		width;
	int 	height;
	t_vector3 	***tabv;
	void	*mlx_ptr;
	void	*win_ptr;
	double	padding;
	int		padding_height;
	t_vector2 *start_pos;
}					t_launcher;

typedef struct		s_bresen
{
	double dx;
	double dy;
	double err;
	double sx;
	double sy;
}					t_bresen;

void                print_line(t_launcher *options, t_vector3 *a,
					t_vector3 *b);
t_vector2			*new_vector2(double x, double y);
t_vector3			*new_vector3(double x, double y, double z);
t_reader			ft_read_file(int fd, int buff_size);
t_launcher			*new_launcher(char **data, double padding, int padding_height, t_vector2 *start_pos);
#endif
