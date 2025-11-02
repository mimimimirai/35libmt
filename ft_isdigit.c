#include "libft.h"

// Check if character is a digit
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 数字 ('0'-'9') が1を返すことを確認
 * 2. アルファベットが0を返すことを確認
 * 3. 特殊文字が0を返すことを確認
 * 4. ASCII範囲外が0を返すことを確認
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

	printf("=== ft_isdigit テスト ===\n\n");

	// テスト1: 数字（例：'5'を表示）
	printf("【テスト1】数字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '5', '5');
	result = ft_isdigit('5');
	result_libc = isdigit('5');
	printf("  ft_isdigit('%c') = %d (非ゼロなら数字、0なら数字ではない)\n", '5', result);
	printf("  isdigit('%c')    = %d\n", '5', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	for (i = '0'; i <= '9'; i++)
	{
		result = ft_isdigit(i);
		result_libc = isdigit(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト2: アルファベット（例：'a'を表示）
	printf("【テスト2】アルファベット\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'a', 'a');
	result = ft_isdigit('a');
	result_libc = isdigit('a');
	printf("  ft_isdigit('%c') = %d\n", 'a', result);
	printf("  isdigit('%c')    = %d\n", 'a', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'a'; i <= 'z'; i++)
	{
		result = ft_isdigit(i);
		result_libc = isdigit(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト3: 特殊文字（例：'@'を表示）
	printf("【テスト3】特殊文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '@', '@');
	result = ft_isdigit('@');
	result_libc = isdigit('@');
	printf("  ft_isdigit('%c') = %d\n", '@', result);
	printf("  isdigit('%c')    = %d\n", '@', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	if ((ft_isdigit(' ') == 0) != (isdigit(' ') == 0) ||
		(ft_isdigit('@') == 0) != (isdigit('@') == 0))
	{
		printf("FAIL: 特殊文字テスト\n");
		failed = 1;
	}

	// テスト4: ASCII範囲外（例：128を表示）
	printf("【テスト4】ASCII範囲外\n");
	printf("  入力: %d (ASCII範囲外)\n", 128);
	result = ft_isdigit(128);
	result_libc = isdigit(128);
	printf("  ft_isdigit(%d) = %d\n", 128, result);
	printf("  isdigit(%d)    = %d\n", 128, result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	if ((ft_isdigit(128) == 0) != (isdigit(128) == 0) ||
		(ft_isdigit(255) == 0) != (isdigit(255) == 0) ||
		(ft_isdigit(-1) == 0) != (isdigit(-1) == 0))
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
