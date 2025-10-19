#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s; // ポインタをunsigned char型にキャスト
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c) // 文字cが見つかった場合
			return ((void *)(ptr + i)); // そのアドレスを返す
		i++;
	}
	return (NULL); // 文字cが見つからなかった場合はNULLを返す
}
