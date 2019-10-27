#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	i = 0;
	if (!dst || !src || (n == 0))
		return (0);
	source = (unsigned char*)src;
	dest = (unsigned char*)dst;
	while (i < n)
	{
		dest[i] = source[i];
		if (dest[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (0);
}
