#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src); // ソース文字列の長さを取得
	if (dstsize == 0) // コピー先のサイズが0の場合は長さのみ返す
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0') // ヌル終端を除いてコピー
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0'; // ヌル終端を追加
	return (src_len); // ソース文字列の長さを返す
}
