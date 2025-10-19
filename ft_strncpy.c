#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0') // len文字まで、または文字列の終端までコピー
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len) // 残りの部分を0で埋める
	{
		dst[i] = '\0';
		i++;
	}
	return (dst); // コピー先のポインタを返す
}
