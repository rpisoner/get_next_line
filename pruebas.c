#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	char	*buffer;
	int		fd;
	char	*old;
	int		verify_read;
	int		i;

	i = 5;
	fd = open("pruebas.txt", O_RDWR);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	verify_read = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n", verify_read);
	free(buffer);
	verify_read = read(fd, buffer, BUFFER_SIZE);
	free(buffer);
	printf("%d\n", verify_read);
	printf("%s\n", buffer);
	return (0);
}
