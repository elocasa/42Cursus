/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:05:36 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/08 16:28:26 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n--)
	{
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}

int	main(void)
{
	char	*src;
	char	dest[sizeof(src)];

	src = "hola";
	printf("%p", ft_memcpy(dest, src, 4));
}
