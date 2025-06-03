/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:55:09 by diego             #+#    #+#             */
/*   Updated: 2025/06/03 18:07:03 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <unistd.h>

int	ft_putnbr_base(unsigned long nbr, int upper)
{
	int		count;
	char	*base;

	if (upper == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_base(nbr / 16, upper);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
