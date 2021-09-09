/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:58 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/19 14:52:41 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *ptr)
{
	if (!ptr)
		return (0);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
