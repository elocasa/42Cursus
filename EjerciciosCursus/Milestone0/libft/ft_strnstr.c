/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:36:04 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 15:48:17 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] && i < n)
	{
		j = 0;
		while (small[j] && big[i + j] == small[j] && (i + j) < n)
			j++;
		if (!small[j])
			return ((char *)(big + i));
		i++;
	}
	return ((void *)0);
}

// int	main(void)
// {
// 	printf("%s", ft_strnstr("hola como", "la", 4));
// }