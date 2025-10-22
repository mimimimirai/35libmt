#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (dst == NULL && src == NULL) // 両方のポインタがNULLの場合は何もしない
		return (NULL);
	dst_ptr = (unsigned char *)dst; // ポインタをunsigned char型にキャスト
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i]; // 1バイトずつコピー
		if (src_ptr[i] == (unsigned char)c) // 文字cが見つかった場合
			return (dst_ptr + i + 1); // 次のバイトのアドレスを返す
		i++;
	}
	return (NULL); // 文字cが見つからなかった場合はNULLを返す
}
