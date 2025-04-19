/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:51:44 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/08 16:02:08 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	while (n--)
	{
		((unsigned char *)dest)[n] = c;
	}
	return (dest);
}

/*int	main(void)
{
	char dest1[20];
	memset(dest1, 'A', 5);
	printf("%s", dest1);
}*/