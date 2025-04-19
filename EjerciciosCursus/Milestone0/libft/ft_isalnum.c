/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:47:07 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/08 12:11:17 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isalnum(char c)
{
	if ((c > 47 && c < 58) || (c < 91 && c > 64) || (c < 123 && c > 96))
		return (1);
	else
		return (0);
}

/*int main ()
{
	printf("%d", ft_isalnum('/'));
	printf("%d", isalnum('/'));

}*/