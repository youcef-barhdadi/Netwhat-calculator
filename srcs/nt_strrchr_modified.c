/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_strrchr_modified.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:08:01 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/27 15:19:15 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>

char	*nt_strrchr_modified(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	str = (char*)s;
	i = (int)strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i + 1);
		i--;
	}
	return (0);
}