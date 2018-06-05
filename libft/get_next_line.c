/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <jodoming@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/24 13:18:32 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 04:21:53 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_read_fd(char **str, int fd)
{
	int			ret;
	char		*temp;
	char		buf[BUFF_SIZE + 1];

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	temp = *str;
	*str = ft_strjoin(*str, buf);
	if (*temp)
		free(temp);
	return (ret);
}

static int		get_line(char **str, char **line, char *s)
{
	int			ret;
	char		*temp;

	ret = 0;
	if (*s == '\n')
		ret = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	if (ret == 0 && ft_strlen(*str))
	{
		*str = ft_strnew(1);
		return (1);
	}
	else if (ret == 0 && !(ft_strlen(*str)))
		return (0);
	temp = *str;
	*str = ft_strjoin(s + 1, "");
	free(temp);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		*temp;
	static char	*str;

	if (!str)
		str = "";
	if (!line || BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (line)
	{
		temp = str;
		while (*temp || ret < BUFF_SIZE)
		{
			if (*temp == '\n' || !*temp || *temp == -1)
				return (get_line(&str, line, temp));
			temp++;
		}
		ret = ft_read_fd(&str, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
