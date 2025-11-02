#include "libft.h"

// Check if character is ASCII
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. ASCII範囲内 (0-127) が1を返すことを確認
 * 2. ASCII範囲外 (128以上、負の数) が0を返すことを確認
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int		i;
	int		result;
	int		result_libc;
	int		failed = 0;

	printf("=== ft_isascii テスト ===\n\n");

	// テスト1: ASCII範囲内（例：65('A')を表示）
	printf("【テスト1】ASCII範囲内\n");
	printf("  入力: %d ('%c')\n", 65, 65);
	result = ft_isascii(65);
	result_libc = isascii(65);
	printf("  ft_isascii(%d) = %d\n", 65, result);
	printf("  isascii(%d)    = %d\n", 65, result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	printf("  その他の例:\n");
	printf("    0 (NULL):    ft_isascii=%d, isascii=%d\n", ft_isascii(0), isascii(0));
	printf("    127 (DEL):   ft_isascii=%d, isascii=%d\n", ft_isascii(127), isascii(127));
	printf("\n");
	
	// 全範囲もチェック
	for (i = 0; i <= 127; i++)
	{
		result = ft_isascii(i);
		result_libc = isascii(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: %d (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト2: ASCII範囲外（例：128を表示）
	printf("【テスト2】ASCII範囲外\n");
	printf("  入力: %d (ASCII範囲外)\n", 128);
	result = ft_isascii(128);
	result_libc = isascii(128);
	printf("  ft_isascii(%d) = %d\n", 128, result);
	printf("  isascii(%d)    = %d\n", 128, result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	printf("  その他の例:\n");
	printf("    255:        ft_isascii=%d, isascii=%d\n", ft_isascii(255), isascii(255));
	printf("    -1:         ft_isascii=%d, isascii=%d\n", ft_isascii(-1), isascii(-1));
	printf("    256:        ft_isascii=%d, isascii=%d\n", ft_isascii(256), isascii(256));
	printf("\n");
	
	if ((ft_isascii(128) == 0) != (isascii(128) == 0) ||
		(ft_isascii(255) == 0) != (isascii(255) == 0) ||
		(ft_isascii(-1) == 0) != (isascii(-1) == 0) ||
		(ft_isascii(256) == 0) != (isascii(256) == 0))
	{
		printf("FAIL: ASCII範囲外テスト\n");
		failed = 1;
	}

	printf("=== 結果 ===\n");
	if (!failed)
		printf("✓ すべてのテストが成功しました\n");
	else
		printf("✗ テストに失敗しました\n");
	return (failed);
}
#endif
