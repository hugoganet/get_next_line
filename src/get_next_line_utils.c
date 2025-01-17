/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:24:15 by hganet            #+#    #+#             */
/*   Updated: 2025/01/17 18:37:58 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/**
 * @brief Locates the first occurence of c
 * 		  (converted to an unsigned char) in the string str.
 * @param str The string to check
 * @param c The character to search for.
 * @param n The number of bytes to search.
 * @return A pointer to the located character
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each
 * 		  and returns a pointer to the allocated memory.
 * @param nmemb Number of elements
 * @param size Size of each element
 * @return Pointer to the allocated memory
 * @attention !!! FREE !!!
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	i;
	char	*ptr;

	if(nmemb == 0 || size == 0)
		return (malloc(0));
	if(nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = (char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
		ptr[i++] = '\0';
	return (ptr);
}

/**
 * @brief Returns the length of the string
 * @param str The string to measure
 * @return The length of the string
 */
int	ft_strlen(char *str, int mode)
{
	int	i;

	if (!str || !(*str)) // check that str isn't NULL nor empty
		return (0);
	i = 0;
	while ((mode == 1 && i < BUFFER_SIZE) || (mode == 0 && str[i])) // there is no '\0' in the static_buffer
	{
		if (mode == 1 && str[i] == '\n')
		{
			printf("EOL\n");
			return (i + 1);
		}
		i++;
	}
	return (i);
}

/**
 * @brief Concatenates two strings and frees the memory of the input strings
 * @param static_buff The first string
 * @param temp_buff The second string
 * @return The concatenated string
 * @attention !!! FREE !!!
 */
char	*ft_strjoin(char static_buff[BUFFER_SIZE], char *dest)
{
	char	*new_buff_ptr;
	size_t	static_buff_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;

	static_buff_len = ft_strlen(static_buff, 1);
	// TODO if static_buff_len < BUFFER_SIZE it means that I encountered a EOL so store the remaining 
	if (static_buff_len < BUFFER_SIZE)
	{
		printf("static_buff_len = %zu\n", static_buff_len);
		
	}
	dest_len = ft_strlen(dest, 0);
	new_buff_ptr = (char *)ft_calloc((static_buff_len + dest_len + 1), sizeof(char));
	if (!new_buff_ptr)
		return (NULL);
	j = 0;
	while (j < dest_len)
	{
		new_buff_ptr[j] = dest[j];
		j++;
	}
	i = 0;
	while (i < static_buff_len)
		new_buff_ptr[j++] = static_buff[i++];
	//printf("static_buf = %s\nnew_buff   = %s\n", static_buff, new_buff_ptr);
	free(dest);
	return (new_buff_ptr);
}
