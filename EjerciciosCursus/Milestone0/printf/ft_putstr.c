/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:45:31 by diego             #+#    #+#             */
/*   Updated: 2025/06/03 16:19:50 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		count_char;

	count_char = 0;
	if (!str)
	{
		count_char += ft_putstr("(null)");
		return (count_char);
	}
	while (str[count_char] != '\0')
		count_char += ft_putchar(str[count_char]);
	return (count_char);
}
