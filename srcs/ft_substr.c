#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	int		i;
	size_t	strln;

	if (!s)
		return (NULL);
	if ((int)start < 0)
		return (NULL);
	strln = strlen(s);
	if (len >= (strln - (size_t)start))
		len = strln - (size_t)start;
	if ((size_t)start >= strln)
		len = 0;
	if ((buffer = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (len--)
		buffer[i++] = s[start++];
	buffer[i] = '\0';
	return (buffer);
}
