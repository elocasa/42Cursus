/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:46:38 by diego             #+#    #+#             */
/*   Updated: 2025/06/03 18:13:47 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdarg.h>

static int ft_handle_format(const char **format, va_list *va)
{
	int		count;

	count = 0;
	if(**format == 'c')
		count += ft_putchar(va_arg(*va, int));
	else if(**format == 's')
		count += ft_putstr(va_arg(*va, char *));
	else if(**format == 'p')
		count += ft_putptr(va_arg(*va, void *));
	else if(**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(*va, int));
	else if(**format == 'u')
		count += ft_putnbr_unsigned(va_arg(*va, unsigned int));
	else if(**format == 'x' || **format == 'X')
		count += ft_putnbr_base(va_arg(*va, unsigned int), **format);
	else if(**format == '%')
		count += ft_putchar('%');
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list va;
	int		count;

	count = 0;
	va_start(va, format);
	while(*format)
	{
		if(*format == '%' && *(format + 1))
		{
			format++;
			count += ft_handle_format(&format, &va);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(va);
	return (count);
}

