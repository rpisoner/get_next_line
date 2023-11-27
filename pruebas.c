#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*buffer;
	int		fd;
	char	*old;
	int		i;

	i = 5;
	fd = open("pruebas.txt", O_RDWR);
	buffer = (char *)ft_calloc(BUFFER_SIZE * sizeof(char));
	old = "\0";
	read(fd, buffer, BUFFER_SIZE);
	old = ft_strjoin(old, buffer);
	printf("%s\n", old);
	return (0);
}
