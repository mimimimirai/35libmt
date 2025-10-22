#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s1; // ポインタをunsigned char型にキャスト
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i]) // 異なるバイトが見つかった場合
			return (ptr1[i] - ptr2[i]); // 差を返す
		i++;
	}
	return (0); // すべて同じ場合は0を返す
}

