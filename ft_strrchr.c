#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s); // 文字列の長さを取得
	i = len; // 最後の文字から開始
	while (i > 0) // 最初の文字まで逆順で検索
	{
		i--;
		if (s[i] == (char)c) // 文字cが見つかった場合
			return ((char *)(s + i)); // そのアドレスを返す
	}
	if ((char)c == '\0') // 検索文字が終端文字の場合
		return ((char *)(s + len)); // 終端文字のアドレスを返す
	return (NULL); // 文字cが見つからなかった場合はNULLを返す
}

