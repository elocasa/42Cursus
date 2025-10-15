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
    if(!head_dest) // si el destino esta vacio
    {
        head_dest = tmp; // el nodo que muevo se convierte en el unico y primero del dest
        head_dest->next = NULL; // el next lo hacemos NULL ya que no hay mas
        *stack_dest = head_dest;
    }
    else // sino esta vacío
    {
        tmp->next = head_dest; // el nodo que se ha movido lo ponemos antes del primer nodo actual
        *stack_dest = tmp; // se updatea el dest para que comience desde el nodo que hemos metido
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