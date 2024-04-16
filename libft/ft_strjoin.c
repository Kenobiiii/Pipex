/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:10:02 by paromero          #+#    #+#             */
/*   Updated: 2023/10/18 12:34:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	final = malloc((a + b + 1));
	if (!final)
		return (NULL);
	while (a--)
	{
		final[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		final[a++] = s2[i++];
	final[a] = '\0';
	return (final);
}
/*int main()
{
    char *str1 = "buenos ";
    char *str2 = "dias";
    printf("%s\n", ft_strjoin(str1, str2));
    return (0);
}*/
