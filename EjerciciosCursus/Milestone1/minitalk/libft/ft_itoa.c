/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:52:27 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 13:34:27 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len >= 0 && str[len] != '-')
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	int		num;
// 	char	*result;

// 	num = -12345;
// 	result = ft_itoa(num);
// 	printf("El número %d como cadena es: %s\n", num, result);
// 	free(result);
// 	return (0);
// }
