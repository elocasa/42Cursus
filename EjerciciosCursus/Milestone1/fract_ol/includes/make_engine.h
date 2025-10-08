/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 17:16:55 by diego             #+#    #+#             */
/*   Updated: 2025-10-08 17:16:55 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_ENGINE_H
#define MAKE_ENGINE_H

# include "fractal.h"

void    init_engine(t_engine *engine, char *arg);
void    reset_engine(t_engine *engine, char *fractal_type);
void    set_fractal_type(t_engine *engine, char *str);

#endif