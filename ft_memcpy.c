#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (dst == NULL && src == NULL) // 両方のポインタがNULLの場合は何もしない
		return (dst);
	dst_ptr = (unsigned char *)dst; // ポインタをunsigned char型にキャスト
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i]; // 1バイトずつコピー
		i++;
	}
	return (dst); // 元のポインタを返す
}
