/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:11:39 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/08 12:10:28 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <ctype.h>
int	ft_isalpha(char c)
{
	if ((c < 91 && c > 64) || (c < 123 && c > 96))
		return (1);
	else
		return (0);
}

/*int main()
{
	printf("%d", ft_isalpha('a'));
	printf("%d", isalpha('a'));
}*/
