/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:02:13 by marvin            #+#    #+#             */
/*   Updated: 2025/04/18 15:02:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t			i;
	size_t			total_size;
	unsigned char	*ptr;

	total_size = number * size;
	ptr = (unsigned char *)malloc(total_size);
	if (!ptr)
		return ((void *)0);
	i = 0;
	while (i < number)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

// int	main(void)
// {
// 	printf("%p", ft_calloc(5, 6));
// }