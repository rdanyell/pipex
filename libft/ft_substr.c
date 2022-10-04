/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:49:50 by rdanyell          #+#    #+#             */
/*   Updated: 2021/10/27 13:11:03 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*substr;

	i = 0;
	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	if (len > length - start)
		len = length - start;
	if ((size_t)start >= length || !len)
		return ((char *)ft_calloc(1, 1));
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && length - start > 0)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
