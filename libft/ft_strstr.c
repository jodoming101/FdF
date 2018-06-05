/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:58:02 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:47:20 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(needle);
	if (j == 0)
		return (char *)(haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			j++;
			if (!needle[j])
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
