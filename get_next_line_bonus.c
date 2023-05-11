#include "get_next_line_bonus.h"

char	*ft_trim(char *str)
{
	char	*dest;

	dest = ft_strchr(str, '\n');
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*dest;
	int			size;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = '\0';
	while (size > 0)
	{
		if (!str[fd])
			str[fd] = ft_strdup(buffer);
		else
			str[fd] = ft_strjoin(str[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	free(buffer);
	if (!str[fd])
	    return (NULL);
	dest = ft_substr(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd] + 1);
	str[fd] = ft_trim(str[fd]);
	return (dest);
}
