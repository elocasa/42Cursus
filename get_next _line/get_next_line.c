/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:28:48 by diego             #+#    #+#             */
/*   Updated: 2025/06/10 22:31:37 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char **reminder)
{
	char	*line;
	char	*temp;
	size_t	i;

	if(!reminder || !*reminder)
		return (NULL);
	i = 0;
	while((*reminder)[i] && ((*reminder)[i]) != '\n')
		i++;
	line = ft_substr(*reminder, 0, i + ((*reminder)[i] == '\n'));
	if(!line)
		return(free(*reminder), *reminder = NULL, NULL);
	temp = ft_strdup(*reminder + i + ((*reminder)[i] == '\n'));
	if(!temp)
		return(free(line), free(*reminder), *reminder = NULL, NULL);
	free(*reminder);
	*reminder = temp;
	return(line);
}

static int ft_read_to_reminder(int fd, char **reminder)
{
	char	*buffer;
	int	num_bytes;

	buffer = malloc(BUFFER_SIZE + 1); //hacer el tamano de buffer uno mas para el \0
	if(!buffer)
		return(-1);
	num_bytes = read(fd, buffer, BUFFER_SIZE);
	while(num_bytes > 0)
	{
		buffer[num_bytes] = '\0'; //poner finde cadena
		*reminder = ft_strjoin(*reminder, buffer);
		if(!*reminder)
		{
			free(buffer);
			return (-1);
		}
		if (ft_strchr(*reminder, '\n'))
			break ;
		num_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return(num_bytes);
}

char	*get_next_line(int fd)
{
	static char *reminder;
	int	num_bytes;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	if(!reminder)
		reminder = ft_strdup("");
	if(!reminder)
		return(NULL);
	num_bytes = ft_read_to_reminder(fd, &reminder);
	if (num_bytes < 0 || (!num_bytes && !*reminder))
	{
		free(reminder);
		reminder = NULL;
		return (NULL);
	}
	return(ft_extract_line(&reminder));
}
