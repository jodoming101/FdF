/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:40:43 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 00:16:54 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if ((d = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = (*f)(s[i]);
		i++;
	}
	return (d);
}
