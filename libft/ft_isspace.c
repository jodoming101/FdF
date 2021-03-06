/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isspace.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 12:06:57 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:23:08 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || c
			== ' ')
		return (1);
	else
		return (0);
}
