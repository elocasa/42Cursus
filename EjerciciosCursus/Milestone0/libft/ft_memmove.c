/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:59 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/08 17:06:01 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	temp[sizeof(src)];
	size_t	tempnum;

	tempnum = n;
	while (n--)
	{
		temp[n] = ((unsigned char *)src)[n];
	}
	while (tempnum--)
	{
		((unsigned char *)dest)[tempnum] = temp[tempnum];
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "hola como estas";

	ft_memmove(src + 15, src + 9, 6);
	printf("%s", src);
}*/
