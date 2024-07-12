/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:18:20 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/05 13:34:37 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		tmp->next->prev = tmp;
		*dest = tmp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(b, a);
	if (!checker)
		ft_printf("pb\n");
}
