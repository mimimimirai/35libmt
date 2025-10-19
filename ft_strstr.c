#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0') // needleが空文字列の場合
		return ((char *)haystack); // haystackの先頭を返す
	i = 0;
	while (haystack[i] != '\0') // haystackの終端まで検索
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
