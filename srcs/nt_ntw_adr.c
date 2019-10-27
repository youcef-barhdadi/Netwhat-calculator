/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_ntw_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:39:33 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/27 12:36:02 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_split.c"
#include "ft_strtrim.c"
#include "ft_itoa.c"
#include "ft_memccpy.c"

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

char	*nt_print_adr(char **octet, int CIDR)
{
	char	*new_addr;
	int		i;
	int		j;
	int		k;
	
	if (!(new_addr = malloc(sizeof(char) * 17)))
		return (NULL);
	i = 0;
	k = 0;
	while (new_addr[i] && k < 4)
	{
		j = 0;
		while (CIDR >= ft_iterative_power(2, k))
		{
			new_addr[i] = octet[k][j];
			i++;
			new_addr[i] = '.';
			i++;
			j++;
		}
		if (CIDR < ft_iterative_power(2, k))
		{
			new_addr[i] = 'X';
			i++;
			new_addr[i] = '.';
			i++;
		}
		k++;
	}	
	return (new_addr);
}

char	*nt_ntw_adr(char *address)
{
	//char	**octet;
	int		CIDR;
	char	suffix[5];
	
	ft_memccpy(suffix, address, '/', strlen(address));
	ft_strtrim(address, "/");
	//f (!(octet = malloc(sizeof(char*) * 4)))
	//	return (NULL);
	//**octet = ft_split(address, '.');
	CIDR = atoi(suffix);
	return (nt_print_adr(/*octet*/ft_split(address, '.'), CIDR));
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