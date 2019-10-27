/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:07:57 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/27 12:11:03 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int				ft_count_charset(char const *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			x++;
		while (s[i] != c && s[i])
			i++;
	}
	return (x);
}

static int				ft_smallstr_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void				*ft_free_substr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = NULL;
		free(str[i]);
		i++;
	}
	str = NULL;
	free(str);
	return (NULL);
}

char					**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	if (!s || !(new = (char**)malloc(sizeof(char*) * (ft_count_charset(s, c) + 1))))
		return (NULL);
	while (++i < ft_count_charset(s, c))
	{
		k = 0;
		if (!(new[i] = (char*)malloc(sizeof(char) * (ft_smallstr_len(&s[j], c)
							+ 1))))
			return (ft_free_substr(new));
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			new[i][k++] = s[j++];
		new[i][k] = '\0';
	}
	new[i] = 0;
	return (new);
}
