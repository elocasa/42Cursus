/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:28:52 by diego             #+#    #+#             */
/*   Updated: 2025/10/10 00:12:13 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void	ft_strlower(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[i++])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

static int	parse_double(const char **sp, double *val)
{
	char	*end;

	if (!sp || !*sp || !val)
		return (-1);
	errno = 0;
	*val = strtod(*sp, &end);
	if (end == *sp)
		return (-1);
	*sp = end;
	return (0);
}

int	parse_complex_arg(const char *s, double *re, double *im)
{
	const char	*p;
	double		r;
	double		imv;

	if (!s || !re || !im)
		return (-1);
	p = s;
	if (parse_double(&p, &r) == -1)
		return (-1);
	while (*p && isspace((unsigned char)*p))
		p++;
	if (*p++ != ',')
		return (-1);
	while (*p && isspace((unsigned char)*p))
		p++;
	if (parse_double(&p, &imv) == -1)
		return (-1);
	while (*p && isspace((unsigned char)*p))
		p++;
	if (*p != '\0')
		return (-1);
	*re = r;
	*im = imv;
	return (0);
}

void	set_julia_defaults(t_fractal *fract, int preset)
{
	(void)preset;
	if (!fract)
		return ;
	fract->julia_param.re = -0.7;
	fract->julia_param.im = 0.27015;
	fract->zoom = WIN_SIZE / 4;
	fract->offset_x = -2;
	fract->offset_y = -2;
	fract->iterations = MIN_ITERATIONS;
	fract->color = DEFAULT_COLOR;
	fract->is_julia_block = true;
}
