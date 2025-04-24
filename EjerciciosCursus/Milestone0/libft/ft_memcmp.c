/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:22:57 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 15:47:34 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const char *)str1)[i] != ((const char *)str2)[i])
			return (((const char *)str1)[i] - ((const char *)str2)[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d", ft_memcmp("Holo", "Hola", 4));
// }