/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:55:09 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/27 10:30:18 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			ft_nbr_of_digits(int n)
{
	int	i;

	i = 1;
	if (!n)
		return (i);
	while (n)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

static char			*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	new;

	i = 0;
	while (str[i])
		i++;
	i--;
	j = -1;
	while (i > j++)
	{
		new = str[i];
		str[i] = str[j];
		str[j] = new;
		i--;
	}
	return (str);
}

static void			ft_check_non_null_nbr(int n, char *string)
{
	int		i;
	int		neg;
	long	nb;

	nb = (long)n;
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	i = 0;
	if (nb)
	{
		while (nb <= -10 || nb >= 10)
		{
			string[i] = (nb % 10) + 48;
			nb /= 10;
			i++;
		}
		string[i] = (nb % 10) + 48;
	}
	if (neg == 1)
		string[i + 1] = '-';
}

char				*ft_itoa(int n)
{
	char	*string;
	char	*result;
	long	nb;

	nb = (long)n;
	if (!(string = (char*)malloc(sizeof(char) * (ft_nbr_of_digits(nb) +
						1))))
		return (NULL);
	if (!nb)
		string[0] = '0';
	if (nb)
		ft_check_non_null_nbr(nb, string);
	string[ft_nbr_of_digits(nb)] = '\0';
	result = ft_strrev(string);
	return (result);
}
