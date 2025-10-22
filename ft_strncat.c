#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1); // s1の終端位置を取得
	j = 0;
	while (j < n && s2[j] != '\0') // n文字まで、またはs2の終端まで追加
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0'; // 終端文字を設定
	return (s1); // 連結された文字列のポインタを返す
}

