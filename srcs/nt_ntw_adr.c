/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_ntw_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:39:33 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/31 05:40:13 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_split.c"
#include "ft_itoa.c"
#include "ft_memccpy.c"
#include "ft_substr.c"
#include "nt_strrchr_modified.c"
#include <string.h>

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
char *getsubmask(int cid)
{
	if (cid == 8)
		return "255.0.0.0";
	if (cid == 9)
		return "225.128.0.0";
	if (cid == 10)
		return "255.192.0.0";
	if (cid == 11)
		return "255.224.0.0";
	if (cid == 12)
		return "255.240.0.0";
	if(cid == 13)
		return "255.248.0.0";
	if (cid == 14)
		return "255.252.0.0";
	if (cid == 15)
		return "255.254.0.0";
	if (cid == 16)
		return "255.255.0.0";
	if (cid == 17)
		return "255.255.128.0";
	if (cid == 18)
		return "255.255.192.0";
	if (cid == 19)
		return "255.255.224.0";
	if (cid == 20)
		return "255.255.240.0";
	if (cid == 21)
		return "255.255.248.0";
	if (cid == 22)
		return "255.255.252.0";
	if (cid == 23)
		return "255.255.254.0";
	if (cid == 24)
		return "255.255.255.0";
	if (cid == 25)
		return "225.255.255.128";
	if (cid == 26)
		return "255.255.255.192";
	if (cid == 27)
		return "255.255.255.224";
	if (cid == 28)
		return "255.255.255.240";
	if (cid == 29)
		return "255.255.255.252";
	return NULL;

}
void nt_ntw_adr(char *address)
{
	char	**octet;
	int		CIDR;
	char	*suffix;
	char	*ip;
	int		i;
	int len = 0;
	
	if (!(suffix = malloc(sizeof(char) * 3)))
		return ; 
	suffix = nt_strrchr_modified(address, '/');	
	len =   suffix - address - 1;
	ip = ft_substr(address, 0, len);
	if (!(octet = malloc(sizeof(char*) * 4)))
		return ;
	octet = ft_split(ip, '.');
	CIDR = atoi(suffix);
	char **musk =  ft_split(getsubmask(CIDR), '.');
	i = 0;
	printf("network addresse  ");
	while (i < 4)
	{

		int a = atoi(octet[i]) & atoi(musk[i]);
		printf("%d%s",a,(i != 3? ".":""));
		i++;
	}


	printf(" \nbroadcast ");
	i = 0;
	while  ( i < 4)
	{	
			int oc  = atoi(musk[i]);	
			if (oc !=  255)
				printf("255%s",(i != 3? ".":""));
			else 
				printf("%s%s",octet[i],(i != 3? ".":""));
			i++;
	
	}
}

int 	main(int argc, char **argv)
{
	(void)argv;
    if (argc == 2)
    {
		nt_ntw_adr(argv[1]);
		return (0);
    }
	return (0);
}
