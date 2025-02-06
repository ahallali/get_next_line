/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:40:54 by ahallali          #+#    #+#             */
/*   Updated: 2022/11/13 15:05:56 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	check_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_line(char *keep, size_t nl_index)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!nl_index)
	{
		if (!keep || (keep && keep[0] == '\0'))
			tmp = NULL;
		else
			tmp = ft_strdup(keep);
	}
	else
	{
		tmp = (char *)malloc (sizeof (char) * nl_index +1);
		if (!tmp)
			return (NULL);
		while (keep[i] && i < (int)nl_index)
		{
			tmp [i] = keep[i];
			i++;
		}
		tmp[i] = 0;
	}
	return (tmp);
}

char	*ft_getline(int fd,	char **keep)
{
	int		nb;
	char	*tmp;
	char	*buff;
	size_t	nl_index;

	buff = alloc_buff();
	nl_index = 0;
	nb = 1;
	while (nb > 0)
	{
		nb = read (fd, buff, BUFFER_SIZE);
		if (nb)
		{
			buff[nb] = '\0';
			tmp = ft_strjoin(*keep, buff);
			*keep = tmp;
			tmp = NULL;
			nl_index = check_nl(*keep);
			if (nl_index)
				break ;
		}
	}
	if (*keep)
	nl_index = check_nl(*keep);
	return (free(buff), ft_filter(&tmp, nl_index, keep));
}

char	*ft_filter(char **tmp, size_t nl_index, char **keep)
{
	char	*line;

	line = ft_line(*keep, nl_index);
	*tmp = *keep;
	if (!nl_index)
		*keep = NULL;
	else
		*keep = ft_strdup(*tmp + nl_index);
	free(*tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keep[10240];

	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	return (ft_getline(fd, &(keep[fd])));
}


int main(void)
{
    int fd1, fd2;
    char *line1, *line2;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    if (fd1 == -1 || fd2 == -1)
    {
        perror("Error opening files");
        return (1);
    }

    printf("Reading from file1.txt and file2.txt simultaneously:\n");
    while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
    {
        if (line1)
        {
            printf("File1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("File2: %s", line2);
            free(line2);
        }
    }

    close(fd1);
    close(fd2);
    return (0);
}