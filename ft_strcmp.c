#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0') // 両方の文字列の終端まで比較
	{
		if (s1[i] != s2[i]) // 異なる文字が見つかった場合
			return ((unsigned char)s1[i] - (unsigned char)s2[i]); // 差を返す
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]); // 最後の文字の差を返す
}
