/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 11:55:09 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:11:45 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 && str[i + 1] != 45)
		i++;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res + str[i] - 48) * 10;
		i++;
	}
	return ((res * sign) / 10);
}
