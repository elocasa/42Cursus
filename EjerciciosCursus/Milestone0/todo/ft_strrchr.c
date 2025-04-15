/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:02:32 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/15 12:19:41 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (s[i] == c)
		{
			j = i;
			i++;
		}
		else
		{
			i++;
		}
	}
	return ((char *)s);
}

int	main(void)
{
	printf("%s", ft_strrchr("hola como estas", 'o'));
}