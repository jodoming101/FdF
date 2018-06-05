/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 00:25:08 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 00:35:44 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c || s[i])
		{
			if (i != 0)
				count++;
			i++;
		}
	}
	return (count);
}

static int		ft_count_char(char const *s, int i, char c)
{
	int		count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count(s, c) + 1)))
			|| s == NULL)
		return (NULL);
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			tab[j] = (char*)malloc(sizeof(char) * ft_count_char(s, i, c) + 1);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
