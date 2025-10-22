#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst); // 現在のdstの長さを取得
	src_len = ft_strlen(src); // srcの長さを取得
	if (dstsize <= dst_len) // dstsizeが現在のdstの長さ以下の場合
		return (dstsize + src_len); // 必要な長さを返す
	i = 0;
	while (dst_len + i + 1 < dstsize && src[i] != '\0') // 安全にコピー
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0'; // 終端文字を設定
	return (dst_len + src_len); // 連結後の長さを返す
}

