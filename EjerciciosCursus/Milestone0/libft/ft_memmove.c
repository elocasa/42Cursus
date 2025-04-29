/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:16:59 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/29 13:43:00 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (!dest2 && !src2)
		return (NULL);
	if (dest2 == src2 || n == 0)
		return (dest);
	if (dest2 < src2)
	{
		while (n--)
			*dest2++ = *src2++;
	}
	else
	{
		dest2 += n;
		src2 += n;
		while (n--)
			*(--dest2) = *(--src2);
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "hola como estas";

	ft_memmove(src + 15, src + 9, 6);
	printf("%s", src);
}*/
