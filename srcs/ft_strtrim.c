/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:08:27 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/27 10:29:22 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	bzero(buffer, count * size);
	return (buffer);
}

char	*ft_strdup(const char *s1)
{
	char		*buffer;
	size_t		i;
	size_t		len;

	if (!s1)
		return (0);
	len = strlen(s1);
	if ((buffer = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static int		ft_isinset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		len;

	if ((!s1) || (!s1 && !set))
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	j = 0;
	k = strlen(s1);
	while (ft_isinset(s1[j], set))
		j++;
	if (j < k)
		k--;
	while (ft_isinset(s1[k], set))
		k--;
	len = k - j + 1;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = s1[j++];
	return (str);
}
