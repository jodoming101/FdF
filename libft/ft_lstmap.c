/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 01:13:36 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 01:14:07 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list	*elem))
{
	t_list*tmp;
	t_list*tmp2;
	t_list*base;

	tmp2 = NULL;
	while (lst)
	{
		if ((tmp = ft_lstnew(f(lst)->content, f(lst)->content_size)) == NULL)
			return (NULL);
		if (tmp2 != NULL)
			tmp2->next = tmp;
		else
			base = tmp;
		lst = lst->next;
		tmp2 = tmp;
	}
	return (base);
}
