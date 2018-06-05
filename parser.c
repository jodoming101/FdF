/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <jodoming@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/16 16:48:17 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 16:21:47 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./incl/fdf.h"

char	*ft_merge_str(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(new, s1);
	return (ft_strcat(new, s2));
}

t_map		*new_map(char **dmap, int h, int w)
{
	t_map	*ret;
	if((ret = malloc(sizeof (t_map))) == NULL)
			return (NULL);
	ret->h = h;
	ret->w = w;
	ret->d_map = dmap;
	return (ret);
}

t_launcher		*new_launcher(char **data, double padding, int padding_height, t_vector2 *start_pos)
{
	t_launcher	*ret;
	if((ret = malloc(sizeof (t_launcher))) == NULL)
			return (NULL);
	ret->data = data;
	ret->padding = padding;
	ret->padding_height = padding_height;
	ret->start_pos = start_pos;
	ret->mlx_ptr = mlx_init();
	ret->win_ptr = mlx_new_window(ret->mlx_ptr, 1250, 700, "FDF");
	return (ret);
}

t_reader			ft_read_file(int fd, int buff_size)
{
	int				rd;
	char			buf[buff_size + 1];
	char			*tmp;
	char			*str;
	t_reader		ret;

	str = NULL;
	while ((rd = read(fd, buf, buff_size)))
	{
		if (rd == -1)
			break ;
		tmp = str;
		buf[rd] = '\0';
		str = ft_merge_str(str, buf);
		free(tmp);
	}
	ret.rd = rd;
	ret.str = str;
	return (ret);
}
