/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 07:45:47 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 07:57:29 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char*)src;
	d = (char*)dst;
	if (s == d || n == 0)
		return (dst);
	while (--n)
		*d++ = *s++;
	*d = *s;
	return (dst);
}
