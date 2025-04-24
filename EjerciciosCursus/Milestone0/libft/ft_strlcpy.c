/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:59:45 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/24 15:48:07 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (size--)
	{
		dest[size] = src[size];
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char	*src;
	char	dest[] = "";

	src = "hola";
	// ft_strlcpy(dest, src, 4);
	//printf("%zu", ft_strlcpy(dest, src, sizeof(src)));
	// printf("%s", dest);
}*/
