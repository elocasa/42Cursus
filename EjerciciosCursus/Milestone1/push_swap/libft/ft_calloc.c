/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:02:13 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 12:15:49 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

// void	*ft_calloc(size_t number, size_t size)
// {
// 	size_t			i;
// 	size_t			total_size;
// 	unsigned char	*ptr;

// 	total_size = number * size;
// 	ptr = (unsigned char *)malloc(total_size);
// 	if (!ptr)
// 		return ((void *)0);
// 	i = 0;
// 	while (i < number)
// 	{
// 		ptr[i] = 0;
// 		i++;
// 	}
// 	return ((void *)ptr);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	while (n--)
// 	{
// 		((unsigned char *)s)[n] = '\0';
// 	}
// }

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

// int	main(void)
// {
// 	printf("%p", ft_calloc(5, 6));
// }