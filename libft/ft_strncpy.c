/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:26:33 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:11:29 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	while (i < len)
	{
		if (i < lensrc)
			dst[i] = src[i];
		else
			dst[i] = 0;
		i++;
	}
	return (dst);
}
