#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s; // ポインタをunsigned char型にキャスト
	i = 0;
	while (i < n)
	{
		ptr[i] = 0; // 0で埋める
		i++;
	}
}
