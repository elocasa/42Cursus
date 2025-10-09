/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:13:47 by diego             #+#    #+#             */
/*   Updated: 2025/10/09 23:36:08 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

#include "fractal.h"
#include "utils.h"

int on_key_hook_event(int key, t_engine *engine);
int on_mouse_hook_event(int key, int x, int y, t_engine *engine);
int on_destroy_event(t_engine *engine);
int on_mousemove_event(int x, int y, t_engine *engine);

#endif