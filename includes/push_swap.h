/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:26:51 by fmorenil          #+#    #+#             */
/*   Updated: 2024/06/12 12:31:16 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					index;
	int					push_price;
	bool				above_median;
	bool				cheapest;	
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Manejo de errores
void			check_args(int argc, char **argv);
int				ft_error(void);
void			ft_free(char **args);
// Iniciar Stack
int				is_sorted(t_stack_node *stack_a);
void			fast_sort(t_stack_node **a, t_stack_node **b);
void			sort_3(t_stack_node **a);
void			sort_5(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			node_current_position(t_stack_node *stack);
void			move_nodes(t_stack_node **a, t_stack_node **b);
void			node_price(t_stack_node *a, t_stack_node *b);	
void			node_cheapest(t_stack_node *b);
void			finish_rotation(t_stack_node **stack, t_stack_node *head,
					char stack_name);
// Utilidades Stack
t_stack_node	*ft_lastnode(t_stack_node *stack);
t_stack_node	*ft_lsthigh(t_stack_node *stack);
t_stack_node	*ft_lstsmall(t_stack_node *stack);
t_stack_node	*ft_cheapest(t_stack_node *stack);
void			to_the_stack(t_stack_node **stack, int num);
void			free_stack(t_stack_node **stack);
int				ft_lstsize(t_stack_node *stack);
// Comandos
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);

#endif
