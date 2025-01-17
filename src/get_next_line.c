/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:24:44 by hganet            #+#    #+#             */
/*   Updated: 2025/01/17 18:38:51 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_strlen(char *str, int mode);
char 	*ft_strjoin(char static_buff[BUFFER_SIZE], char *dest);

int	ft_read(int	fd, char static_buffer[BUFFER_SIZE])
{
	int	bytes_read;

	// ? should I read BUFFER_SIZE or stop before in some case ?
	bytes_read = read(fd, static_buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		// "clear" the static_buffer
		static_buffer[0] = '\0';
		return (0);
	}
	return (bytes_read);
}

char *get_next_line(int fd)
{
	static char	static_buffer[BUFFER_SIZE];
	char		*dest;
	
	// TODO : check edges cases
	if (fd < 0)
		return (NULL);
	// ft_read(fd, static_buffer);
	if (!ft_read(fd, static_buffer))
		return (NULL);
	dest = NULL;
	// TODO stop if EOF
	while (static_buffer[0]
			&& !ft_memchr((const void *)dest, '\n', ft_strlen(dest, 0)))
	{
		dest = ft_strjoin(static_buffer, dest);
		if (!dest)
		{
			free (dest);
			return (NULL);
		}
		ft_read(fd, static_buffer);
	}
	return(dest);
	//return (ft_strjoin(static_buffer, dest));
}

