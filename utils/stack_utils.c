/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:54:48 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/12 13:40:07 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lastnode(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	to_the_stack(t_stack_node **stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = num;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = ft_lastnode(*stack);
		last->next = node;
		node->prev = last;
	}
}

t_stack_node	*ft_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheap;

	cheap = stack;
	while (stack)
	{
		if (stack->cheapest)
		{
			cheap = stack;
			return (cheap);
		}
		stack = stack->next;
	}
	return (cheap);
}

t_stack_node	*ft_lsthigh(t_stack_node *stack)
{
	t_stack_node	*high;

	if (stack == NULL)
		return (NULL);
	high = stack;
	while (stack)
	{
		if (high->value < stack->value)
			high = stack;
		stack = stack->next;
	}
	return (high);
}

t_stack_node	*ft_lstsmall(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*small;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			small = stack;
		}
		stack = stack->next;
	}
	return (small);
}
