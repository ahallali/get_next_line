/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:12:32 by ahallali          #+#    #+#             */
/*   Updated: 2022/11/10 02:51:07 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_nl(char * buffer)
{
	int i =0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *ft_line(char *keep)
{
	char * tmp;
	int i;
	i = 0;
	if (!check_nl(keep))
		return (keep);
	else 
		while (keep[i]!='\n')
		{
			tmp[i]=keep[i];
			i++;
		}
		return (ft_strdup(tmp));
}

char	*ft_getline(int fd,char *buff,char *keep)
{
	int nb;
	char * tmp;
	buff = (char *)malloc (sizeof (char )* BUFFER_SIZE+1);
	if (!buff)
		return (NULL);
	nb = -1;
	
	while (1)
	{
		nb = read (fd,buff,BUFFER_SIZE);
		if (nb != -1)
		{	
			tmp = ft_strjoin(keep,buff);
			free(keep);
			keep=tmp;
			tmp =NULL;
			if (check_nl(keep))
				break;
		}
	}
	return (keep);
}

char * ft_filter(char * keep)
{
	int i=0;
	int len=0;
	
	if (!keep)
		return (NULL);
	len=ft_strlen (keep);
	while (keep [i])
	{
		if (keep [i]!='\n')
			return (ft_substr(keep,0,i));
		else if (keep[i+1] && keep[i+1]!='\n')
			
		i++;
	}
}

int main ()
{
	int fd;
	fd = open("yaaqoub",O_RDONLY);	
		
	printf("%s",ft_line("12345678"));
	return(0);
}