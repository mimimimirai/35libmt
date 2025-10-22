#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0') // 文字列の終端までカウント
		len++;
	return (len); // 文字列の長さを返す
}

