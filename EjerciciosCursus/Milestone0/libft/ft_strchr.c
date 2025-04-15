/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:40:01 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/15 14:08:34 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	if (*s == c)
		return ((char *)s);
	else
		s++;
	return ((char *)s);
}

/*int	main(void)
{
	printf("%s", ft_strchr("hola", 'o'));
}*/