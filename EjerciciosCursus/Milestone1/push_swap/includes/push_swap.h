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
#define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_list
{
    int value;
    int index;
    struct t_list *next;
} t_list;

#endif PUSH_SWAP_H