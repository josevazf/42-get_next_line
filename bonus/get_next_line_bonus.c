/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:31:25 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/05/03 10:02:30 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_text(int fd, char *bufftxt)
{
	char	*temp;
	int		rbytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	rbytes = 1;
	while (!ft_strchr(bufftxt, '\n') && rbytes != 0)
	{
		rbytes = read(fd, temp, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free(temp);
			free(bufftxt);
			return (NULL);
		}
		temp[rbytes] = '\0';
		bufftxt = ft_strjoin(bufftxt, temp);
	}
	free(temp);
	return (bufftxt);
}

char	*get_next_line(int fd)
{
	static char	*bufftxt[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	bufftxt[fd] = ft_get_text(fd, bufftxt[fd]);
	if (!bufftxt[fd])
		return (NULL);
	line = ft_strtrim_l(bufftxt[fd]);
	bufftxt[fd] = ft_strtrim_r(bufftxt[fd]);
	return (line);
}

/* int	main(void)
{
	char	*line;
	char	*line2;
	char	*line3;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	
	
	i = 0;
	fd1 = open("docs/text1.txt", O_RDONLY);
	fd2 = open("docs/text2.txt", O_RDONLY);
	fd3 = open("docs/text3.txt", O_RDONLY);
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf(" %s", line);
		free(line);
		line2 = get_next_line(fd2);
		printf("%s", line2);
		free(line2);
		line3 = get_next_line(fd3);
		printf("%s", line3);
		free(line3);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */