/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 11:15:03 by diego             #+#    #+#             */
/*   Updated: 2025-10-15 11:15:03 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

// Instructions

int					swap(t_list **stack);
int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);
int					push(t_list **stack_dest, t_list **stack_org);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);
int					rotate(t_list **stack);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);
int					reverse_rotate(t_list **stack);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);

// Utils

void				ft_checkarg(int ac, char **av);
void				ft_error(char *msg);
void				ft_free(char **str);
int					get_distance(t_list **stack, int index);
int					is_stack_sorted(t_list **stack);

// T_List

t_list				*ft_lstnews(int value);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_back(t_list **stack, t_list *new);
int					ft_lstsize(t_list *head);
void				free_stack(t_list **stack);

// Index

void				index_stack(t_list **stack);

// Sorts

void				simple_sort(t_list **stack_a, t_list **stack_b);
void				radix_sort(t_list **stack_a, t_list **stack_b);
void				index_stack(t_list **stack);

#endif