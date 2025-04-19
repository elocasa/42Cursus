/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:20:02 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/15 13:29:19 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (int)n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			i++;
	}
	return (s1[i] - s2[i]);
}

/*int	main(void)
{
	printf("%d\n", ft_strncmp("hola", "hola", 4));
	printf("%d\n", ft_strncmp("hol", "hola", 4));
	printf("%d\n", ft_strncmp("hola", "hol", 4));
}*/