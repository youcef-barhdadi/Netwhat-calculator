/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:08:01 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/27 10:26:28 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char		*str;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	str = (char*)s;
	while (i <= strlen(s))
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
