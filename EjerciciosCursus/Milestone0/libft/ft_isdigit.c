/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerezo- <dcerezo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:40:51 by dcerezo-          #+#    #+#             */
/*   Updated: 2025/04/08 12:10:52 by dcerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <ctype.h>
//#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

/*int main()
{
	printf("%d", ft_isdigit('1'));
	printf("%d", isdigit('1'));

}*/