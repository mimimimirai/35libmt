#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little); // littleの長さを取得
	if (little_len == 0) // littleが空文字列の場合
		return ((char *)big); // bigの先頭を返す
	i = 0;
	while (big[i] && i + little_len <= len) // len文字以内で検索
	{
		j = 0;
		while (big[i + j] == little[j] && little[j]) // 部分文字列を比較
			j++;
		if (little[j] == '\0') // littleの終端に達した場合（見つかった）
			return ((char *)(big + i)); // その位置のアドレスを返す
		i++;
	}
	return (NULL); // 見つからなかった場合はNULLを返す
}
