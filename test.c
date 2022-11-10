/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:02:24 by ahallali          #+#    #+#             */
/*   Updated: 2022/11/07 03:09:49 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
char	*ft_strjoin(char  *s1, char *s2)
{
	int i=0;
    int j=0;

	size_t	sz_s1;
	size_t	sz_s2;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	sz_s1 = ft_strlen(s1);
	sz_s2 = ft_strlen(s2);
	ptr = (char *)malloc((sz_s1 + sz_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	// ft_strlcpy(ptr, s1, sz_s1 + 1);
	while (i<sz_s1)
	{
		ptr[i]=s1[i];
		i++;
	}
    while (j+sz_s1<sz_s1+sz_s2)
    {
        ptr [i+1]=s2[j];
        j++;
    }
    ptr[i]='\0';
	// ft_strlcat(ptr, s2, (sz_s1 + sz_s2 +1));
	return (ptr);
}
int main ()
{
    char t[20]="ahmed";
    char t1 [20]="all";
    printf("%s",ft_strjoin(t,t1));
    
}