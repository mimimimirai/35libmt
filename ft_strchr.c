#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0') // 文字列の終端まで検索
	{
		if (s[i] == (char)c) // 文字cが見つかった場合
			return ((char *)(s + i)); // そのアドレスを返す
		i++;
	}
	if ((char)c == '\0') // 検索文字が終端文字の場合
		return ((char *)(s + i)); // 終端文字のアドレスを返す
	return (NULL); // 文字cが見つからなかった場合はNULLを返す
}

