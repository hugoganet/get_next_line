#include "include/get_next_line.h"

char	*get_next_line(int fd);

int main(int ac, char **av)
{
	int		fd;
	char	*buffer;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	//printf("gnl return : %s\n", get_next_line(fd));
	//free(buffer);
	while ((buffer = get_next_line(fd)))
	{
		printf("%s", buffer);
		free(buffer);
	}
	close(fd);
	return (0);
}