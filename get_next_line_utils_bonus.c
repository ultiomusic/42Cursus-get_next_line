/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:14:59 by beeligul          #+#    #+#             */
/*   Updated: 2023/05/11 18:15:01 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	c;
	size_t	i;
	char	*new_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (new_str == NULL)
		return (NULL);
	c = -1;
	i = 0;
	if (str)
		while (str[++c] != '\0')
			new_str[c] = str[c];
	while (buff[i] != '\0')
		new_str[c++] = buff[i++];
	new_str[c] = '\0';
	free(str);
	return (new_str);
}
