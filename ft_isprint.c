#include "libft.h"

// Check if character is printable
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 印字可能文字 (32-126) が1を返すことを確認
 * 2. 制御文字 (0-31, 127) が0を返すことを確認
 * 3. ASCII範囲外が0を返すことを確認
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

	printf("=== ft_isprint テスト ===\n\n");

	// テスト1: 印字可能文字（例：'A'を表示）
	printf("【テスト1】印字可能文字 (32-126)\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'A', 'A');
	result = ft_isprint('A');
	result_libc = isprint('A');
	printf("  ft_isprint('%c') = %d\n", 'A', result);
	printf("  isprint('%c')    = %d\n", 'A', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	printf("  その他の例:\n");
	printf("    32 (SPACE):  ft_isprint=%d, isprint=%d\n", ft_isprint(32), isprint(32));
	printf("    126 ('~'):   ft_isprint=%d, isprint=%d\n", ft_isprint(126), isprint(126));
	printf("\n");
	
	for (i = 32; i <= 126; i++)
	{
		result = ft_isprint(i);
		result_libc = isprint(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: %d '%c' (ft:%d, libc:%d)\n", i, i, result, result_libc);
			failed = 1;
		}
	}

	// テスト2: 制御文字（例：10('\n')を表示）
	printf("【テスト2】制御文字 (0-31, 127)\n");
	printf("  入力: %d ('\\n')\n", 10);
	result = ft_isprint(10);
	result_libc = isprint(10);
	printf("  ft_isprint(%d) = %d (0なら印字不可、非ゼロなら印字可能)\n", 10, result);
	printf("  isprint(%d)    = %d\n", 10, result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	printf("  その他の例:\n");
	printf("    0 (NULL):    ft_isprint=%d, isprint=%d\n", ft_isprint(0), isprint(0));
	printf("    31:          ft_isprint=%d, isprint=%d\n", ft_isprint(31), isprint(31));
	printf("    127 (DEL):   ft_isprint=%d, isprint=%d\n", ft_isprint(127), isprint(127));
	printf("\n");
	
	for (i = 0; i <= 31; i++)
	{
		result = ft_isprint(i);
		result_libc = isprint(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: 制御文字 %d (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}
	if ((ft_isprint(127) == 0) != (isprint(127) == 0))
	{
		printf("FAIL: DEL文字 (ft:%d, libc:%d)\n", ft_isprint(127), isprint(127));
		failed = 1;
	}

	// テスト3: ASCII範囲外（例：128を表示）
	printf("【テスト3】ASCII範囲外\n");
	printf("  入力: %d (ASCII範囲外)\n", 128);
	result = ft_isprint(128);
	result_libc = isprint(128);
	printf("  ft_isprint(%d) = %d\n", 128, result);
	printf("  isprint(%d)    = %d\n", 128, result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	if ((ft_isprint(128) == 0) != (isprint(128) == 0) ||
		(ft_isprint(255) == 0) != (isprint(255) == 0) ||
		(ft_isprint(-1) == 0) != (isprint(-1) == 0))
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
