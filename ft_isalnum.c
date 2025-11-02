#include "libft.h"

// Check if character is alphanumeric
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. アルファベット ('a'-'z', 'A'-'Z') が1を返すことを確認
 * 2. 数字 ('0'-'9') が1を返すことを確認
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

	printf("=== ft_isalnum テスト ===\n\n");

	// テスト1: アルファベット小文字（例：'a'を表示）
	printf("【テスト1】アルファベット小文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'a', 'a');
	result = ft_isalnum('a');
	result_libc = isalnum('a');
	printf("  ft_isalnum('%c') = %d\n", 'a', result);
	printf("  isalnum('%c')    = %d\n", 'a', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'a'; i <= 'z'; i++)
	{
		result = ft_isalnum(i);
		result_libc = isalnum(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト2: アルファベット大文字（例：'Z'を表示）
	printf("【テスト2】アルファベット大文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'Z', 'Z');
	result = ft_isalnum('Z');
	result_libc = isalnum('Z');
	printf("  ft_isalnum('%c') = %d\n", 'Z', result);
	printf("  isalnum('%c')    = %d\n", 'Z', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'A'; i <= 'Z'; i++)
	{
		result = ft_isalnum(i);
		result_libc = isalnum(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト3: 数字（例：'7'を表示）
	printf("【テスト3】数字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '7', '7');
	result = ft_isalnum('7');
	result_libc = isalnum('7');
	printf("  ft_isalnum('%c') = %d\n", '7', result);
	printf("  isalnum('%c')    = %d\n", '7', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	for (i = '0'; i <= '9'; i++)
	{
		result = ft_isalnum(i);
		result_libc = isalnum(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト4: 特殊文字（例：'@'を表示）
	printf("【テスト4】特殊文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '@', '@');
	result = ft_isalnum('@');
	result_libc = isalnum('@');
	printf("  ft_isalnum('%c') = %d\n", '@', result);
	printf("  isalnum('%c')    = %d\n", '@', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	if ((ft_isalnum(' ') == 0) != (isalnum(' ') == 0) ||
		(ft_isalnum('@') == 0) != (isalnum('@') == 0))
	{
		printf("FAIL: 特殊文字テスト\n");
		failed = 1;
	}

	// テスト5: ASCII範囲外（例：128を表示）
	printf("【テスト5】ASCII範囲外\n");
	printf("  入力: %d (ASCII範囲外)\n", 128);
	result = ft_isalnum(128);
	result_libc = isalnum(128);
	printf("  ft_isalnum(%d) = %d\n", 128, result);
	printf("  isalnum(%d)    = %d\n", 128, result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	if ((ft_isalnum(128) == 0) != (isalnum(128) == 0) ||
		(ft_isalnum(255) == 0) != (isalnum(255) == 0))
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
