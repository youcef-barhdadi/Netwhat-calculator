/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_ntw_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:39:33 by lacollar          #+#    #+#             */
/*   Updated: 2019/10/31 14:21:45 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_split.c"
#include "ft_substr.c"
#include "nt_strrchr_modified.c"
#include <string.h>

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
	char	**mask;
	char	*suffix;
	char	*ip;
	int		CIDR;
	int		i;
	int		len;
	int		a;
	
	if (!(suffix = malloc(sizeof(char) * 3)))
		return ; 
	len =   suffix - address - 1;
	suffix = nt_strrchr_modified(address, '/');	
	ip = ft_substr(address, 0, len);
	if (!(octet = malloc(sizeof(char*) * 4)))
		return ;
	octet = ft_split(ip, '.');
	CIDR = atoi(suffix);
	mask =  ft_split(getsubmask(CIDR), '.');
	i = 0;
	printf("network address\t\t");
	while (i < 4)
	{
		a = atoi(octet[i]) & atoi(mask[i]);
		printf("%d%s",a,(i != 3? ".":""));
		i++;
	}
	printf("\nbroadcast address\t");
	i = 0;
	while (i < 4)
	{	
		int oc  = atoi(mask[i]);	
		if (oc !=  255)
			printf("255%s",(i != 3? ".":""));
		else 
			printf("%s%s",octet[i],(i != 3? ".":""));
		i++;
	}
}

int 	main(int argc, char **argv)
{
    if (argc == 2)
    {
		nt_ntw_adr(argv[1]);
		return (0);
    }
	return (0);
}
