/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:29:20 by diego             #+#    #+#             */
/*   Updated: 2025/06/10 22:24:01 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);

#endif