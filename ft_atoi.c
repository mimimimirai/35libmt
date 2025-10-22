#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	size_t	i;

	sign = 1; // 符号を初期化（正の数）
	result = 0; // 結果を初期化
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
		   str[i] == '\v' || str[i] == '\f' || str[i] == '\r') // 空白文字をスキップ
		i++;
	if (str[i] == '+' || str[i] == '-') // 符号をチェック
	{
		if (str[i] == '-')
			sign = -1; // 負の数の場合
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') // 数字を読み取り
	{
		result = result * 10 + (str[i] - '0'); // 数値に変換
		i++;
	}
	return ((int)(result * sign)); // 符号を適用して返す
}

