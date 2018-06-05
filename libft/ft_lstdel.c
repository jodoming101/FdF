/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 01:09:24 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 01:10:45 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *tmp;

	current = *alst;
	while (current != NULL)
	{
		tmp = current->next;
		del(current->content, current->content_size);
		free(current);
		current = tmp;
	}
	*alst = NULL;
}
