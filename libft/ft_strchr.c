/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:41:58 by paromero          #+#    #+#             */
/*   Updated: 2023/10/25 12:13:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	int		i;
	int		tmp;

	s1 = (char *)s;
	tmp = ft_strlen(s1);
	i = 0;
	while (i <= tmp)
	{
		if ((unsigned char)c == s1[i])
		{
			return (&s1[i]);
		}
		i++;
	}
	return (NULL);
}
/*int main ()
{
 const char *largestring = "buenos dias";
           int c = 'a';
           char *ptr;
           ptr = ft_strchr(largestring, c);
   printf("%s\n", ptr);
   return(0);
}*/
