#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0') // 文字列の終端までコピー
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0'; // 終端文字を設定
	return (dst); // コピー先のポインタを返す
}

