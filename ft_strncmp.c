#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0') // n文字まで、または終端まで比較
	{
		if (s1[i] != s2[i]) // 異なる文字が見つかった場合
			return ((unsigned char)s1[i] - (unsigned char)s2[i]); // 差を返す
		i++;
	}
	if (i < n) // まだ比較する文字がある場合
		return ((unsigned char)s1[i] - (unsigned char)s2[i]); // 最後の文字の差を返す
	return (0); // すべて同じ場合は0を返す
}
