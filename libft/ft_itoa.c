/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:27:30 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 00:19:02 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	size_t	chk_s_n(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		else
			return (1 + chk_s_n(-n));
	}
	if (n < 10)
		return (1);
	else
		return (1 + chk_s_n(n / 10));
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		nb;
	size_t	len;

	nbr = NULL;
	nb = n;
	len = chk_s_n(nb);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	if ((nbr = ft_strnew(sizeof(char) * (len))) == NULL)
		return (NULL);
	if (nb < 0)
	{
		nbr[0] = '-';
		nb = -n;
	}
	nbr[len] = '\0';
	while (len-- && nb != 0)
	{
		nbr[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (nbr);
}
