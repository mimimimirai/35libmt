#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b; // ポインタをunsigned char型にキャスト
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c; // int型のcをunsigned char型にキャスト
		i++;
	}
	return (b); // 元のポインタを返す
}
