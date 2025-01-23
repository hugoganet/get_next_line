#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2, size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);

#endif