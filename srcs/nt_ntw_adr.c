/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_ntw_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:39:33 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/27 17:34:14 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_split.c"
#include "ft_itoa.c"
#include "ft_memccpy.c"
#include "ft_substr.c"
#include "nt_strrchr_modified.c"

int		ft_iterative_power(int nb, int power)
{
	int total;
	int x;

	total = nb;
	x = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	while (x < power)
	{
		total = total * nb;
		x++;
	}
	return (total);
}

char	*nt_print_adr(char *octet, int CIDR, int i)
{
	char	*new_addr;
	int		j;
	int		k;
	
	if (!(new_addr = malloc(sizeof(char) * 17)))
		return (NULL);
	k = 0;
	while (new_addr[k] && k < 4)
	{
		j = 0;
		while (CIDR >= ft_iterative_power(2, i))
		{
			new_addr[k] = octet[j];
			k++;
			new_addr[k] = '.';
			j++;
		}
		if (CIDR < ft_iterative_power(2, i))
		{
			new_addr[k] = 'X';
			k++;
			new_addr[k] = '.';
		}
		k++;
	}	
	return (new_addr);
}

char	*nt_ntw_adr(char *address)
{
	char	**octet;
	int		CIDR;
	char	*suffix;
	char	*ip;
	int		i;
	
	if (!(suffix = malloc(sizeof(char) * 3)))
		return (NULL);
	suffix = nt_strrchr_modified(address, '/');
	ip = ft_substr(address, 0, 13);
	if (!(octet = malloc(sizeof(char*) * 4)))
		return (NULL);
	octet = ft_split(ip, '.');
	CIDR = atoi(suffix);
	i = 0;
	while (i < 4)
	{
		nt_print_adr(octet[i], CIDR, i);
		if (i != 0)
			strcat(octet[i - 1], octet[i]);
		i++;
	}
	return ();
}

int 	main(int argc, char **argv)
{
    char *res;

    if (argc == 2)
    {
        res = nt_ntw_adr(argv[1]);
		printf("%s", res);
		return (0);
    }
	return (0);
}