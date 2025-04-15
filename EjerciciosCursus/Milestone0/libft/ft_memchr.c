/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:30:50 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/15 14:08:13 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((char *)s == c)
			return ((unsigned char)s);
		else
			s++;
	}
	return (NULL);
}

int	main(void)
{
	printf("%s", ft_memchr("hola", 'o', 3));
}