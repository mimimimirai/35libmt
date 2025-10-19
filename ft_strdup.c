#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1); // 文字列の長さを取得
	dup = (char *)malloc(sizeof(char) * (len + 1)); // メモリを確保（+1は終端文字用）
	if (dup == NULL) // メモリ確保に失敗した場合
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i]; // 1文字ずつコピー
		i++;
	}
	dup[len] = '\0'; // 終端文字を設定
	return (dup); // 複製された文字列のポインタを返す
}
