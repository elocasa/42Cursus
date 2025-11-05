/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 11:20:36 by diego             #+#    #+#             */
/*   Updated: 2025-10-15 11:20:36 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int swap(t_list **stack)
{
    t_list *head;
    t_list *next;
    int temp_val;
    int temp_index;

    if(ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    next = head->next;
    if(!head && !next)
        ft_putstr_fd("An error has ocurred", 1);
    temp_index = head->index;
    temp_val = head->value;
    head->index = next->index;
    head->value = next->value;
    next->value = temp_val;
    next->index = temp_index;
    return (0);
}

int sa(t_list **stack_a)
{
    if(swap(stack_a) == -1)
        return (-1);
    ft_putendl_fd("sa", 1);
    return(0);
}

int sb(t_list **stack_b)
{
    if(swap(stack_b) == -1)
        return(-1);
    ft_putendl_fd("sb", 1);
    return(0);
}

int ss(t_list **stack_a, t_list **stack_b)
{
    if(ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
        return(-1);
    swap(stack_a);
    swap(stack_b);
    ft_putendl_fd("ss", 1);
    return (0);
}

int push(t_list **stack_dest, t_list **stack_org)
{
    t_list  *tmp;
    t_list  *head_dest;
    t_list  *head_org;

    if(ft_ltssize(stack_org) == 0)
        return (-1);
    head_dest = *stack_dest;
    head_org = *stack_org;
    tmp = head_org;
    *stack_org = head_org;
    if(!head_dest) //If dest is empty
    {
        head_dest = tmp; // the node I move becomes the only and first node in the destination
        head_dest->next = NULL; // NEXT is set NUll bcs there's nothing more
        *stack_dest = head_dest;
    }
    else // And if it's not empty
    {
        tmp->next = head_dest; // it puts the node wich has been moved before the actual node
        *stack_dest = tmp; 
    }
    return (0);
}

int pa(t_list **stack_a, t_list **stack_b)
{
    if(push(stack_a, stack_b) == -1)
        return (-1);
    ft_putendl_fd("pa", 1);
    return (0);
}

int pb(t_list **stack_a, t_list **stack_b)
{
    if(push(stack_b, stack_a) == -1)
        return (-1);
    ft_putendl_fd("pb", 1);
    return (0);
}

int rotate(t_list **stack)
{
    t_list *head;
    t_list *tail;

    if(ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    *stack = head->next;
    head->next = NULL;
    tail->next = head;
    return (0);
}

int ra(t_list **stack_a)
{
    if(rotate(stack_a) == -1)
        return (-1);
    ft_putendl_fd("ra", 1);
    return (0);
}

int rb(t_list **stack_b)
{
    if(rotate(stack_b) == -1)
        return (-1);
    ft_putendl_fd("rb", 1);
    return (0);
}

int rr(t_list **stack_a, t_list **stack_b)
{
    if((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
        return (-1);
    rotate(stack_a);
    rotate(stack_b);
    ft_putendl_fd("rr", 1);
    return (0);
}

int reverse_rotate(t_list **stack)
{
    t_list *head;
    t_list *tail;

    if(ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    while(head)
    {
        if (head->next->next == NULL)
        {
            head->next = NULL;
            break;
        }
        head = head->next;
    }
    tail->next = *stack;
    *stack = tail;
    return (0);
}

int rra(t_list **stack_a)
{
    if(reverse_rotate(stack_a) == -1)
        return (-1);
    ft_putendl_fd("rra", 1);
    return (0);
}

int rrb(t_list **stack_b)
{
    if(reverse_rotate(stack_b) == -1)
        return(-1);
    ft_putendl_fd("rrb", 1);
    return (0);
}

int rrr(t_list **stack_a, t_list **stack_b)
{
    if((ft_lstsize(stack_a) < 2) || (ft_lstsize(stack_b) < 2))
        return (-1);
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_putendl_fd("rrr", 1);
    return (0);
}

