#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle); // needleの長さを取得
	if (needle_len == 0) // needleが空文字列の場合
		return ((char *)haystack); // haystackの先頭を返す
	i = 0;
	while (haystack[i] != '\0' && i + needle_len <= len) // len文字以内で検索
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0') // 部分文字列を比較
			j++;
		if (needle[j] == '\0') // needleの終端に達した場合（見つかった）
			return ((char *)(haystack + i)); // その位置のアドレスを返す
		i++;
	}
	return (NULL); // 見つからなかった場合はNULLを返す
}

