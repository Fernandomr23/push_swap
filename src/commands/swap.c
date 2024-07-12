/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:46:59 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/05 13:44:34 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	*(stack) = second;
}

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_printf("ss\n");
}
