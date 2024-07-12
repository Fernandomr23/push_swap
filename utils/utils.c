/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:53:11 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/12 13:46:26 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_printf("Error\n");
	exit (1);
}

void	ft_free(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*head;

	head = stack;
	while (head->next)
	{
		if (head->value > (head->next->value))
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_lstsize(t_stack_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		++len;
		stack = stack->next;
	}
	return (len);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*next;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}
