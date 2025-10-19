#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (dst == NULL && src == NULL) // 両方のポインタがNULLの場合は何もしない
		return (dst);
	dst_ptr = (unsigned char *)dst; // ポインタをunsigned char型にキャスト
	src_ptr = (const unsigned char *)src;
	if (dst_ptr < src_ptr) // 前方からコピー（重複しない場合）
	{
		i = 0;
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else // 後方からコピー（重複する場合）
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst_ptr[i] = src_ptr[i];
		}
	}
	return (dst); // 元のポインタを返す
}
