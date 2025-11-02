#include "libft.h"

// Check if character is alphabetic
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. アルファベット小文字 ('a'-'z') が1を返すことを確認
 * 2. アルファベット大文字 ('A'-'Z') が1を返すことを確認
 * 3. 数字 ('0'-'9') が0を返すことを確認
 * 4. 特殊文字が0を返すことを確認
 * 5. ASCII範囲外が0を返すことを確認
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

	printf("=== ft_isalpha テスト ===\n\n");

	// テスト1: アルファベット小文字（例：'a'を表示）
	printf("【テスト1】アルファベット小文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'a', 'a');
	result = ft_isalpha('a');
	result_libc = isalpha('a');
	printf("  ft_isalpha('%c') = %d\n", 'a', result);
	printf("  isalpha('%c')    = %d\n", 'a', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	// 全範囲もチェック
	for (i = 'a'; i <= 'z'; i++)
	{
		result = ft_isalpha(i);
		result_libc = isalpha(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト2: アルファベット大文字（例：'Z'を表示）
	printf("【テスト2】アルファベット大文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'Z', 'Z');
	result = ft_isalpha('Z');
	result_libc = isalpha('Z');
	printf("  ft_isalpha('%c') = %d\n", 'Z', result);
	printf("  isalpha('%c')    = %d\n", 'Z', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'A'; i <= 'Z'; i++)
	{
		result = ft_isalpha(i);
		result_libc = isalpha(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト3: 数字（例：'5'を表示）
	printf("【テスト3】数字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '5', '5');
	result = ft_isalpha('5');
	result_libc = isalpha('5');
	printf("  ft_isalpha('%c') = %d (非ゼロならアルファベット、0ならアルファベットではない)\n", '5', result);
	printf("  isalpha('%c')    = %d\n", '5', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	for (i = '0'; i <= '9'; i++)
	{
		result = ft_isalpha(i);
		result_libc = isalpha(i);
		if ((result == 0) != (result_libc == 0))
		{
			printf("FAIL: '%c' (ft:%d, libc:%d)\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト4: 特殊文字（例：'@'を表示）
	printf("【テスト4】特殊文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '@', '@');
	result = ft_isalpha('@');
	result_libc = isalpha('@');
	printf("  ft_isalpha('%c') = %d\n", '@', result);
	printf("  isalpha('%c')    = %d\n", '@', result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	if ((ft_isalpha(' ') == 0) != (isalpha(' ') == 0) ||
		(ft_isalpha('@') == 0) != (isalpha('@') == 0) ||
		(ft_isalpha('[') == 0) != (isalpha('[') == 0))
	{
		printf("FAIL: 特殊文字テスト\n");
		failed = 1;
	}

	// テスト5: ASCII範囲外（例：128を表示）
	printf("【テスト5】ASCII範囲外\n");
	printf("  入力: %d (ASCII範囲外)\n", 128);
	result = ft_isalpha(128);
	result_libc = isalpha(128);
	printf("  ft_isalpha(%d) = %d\n", 128, result);
	printf("  isalpha(%d)    = %d\n", 128, result_libc);
	printf("  → %s\n\n", (result == 0) == (result_libc == 0) ? "✓ 一致" : "✗ 不一致");
	
	if ((ft_isalpha(128) == 0) != (isalpha(128) == 0) ||
		(ft_isalpha(255) == 0) != (isalpha(255) == 0) ||
		(ft_isalpha(-1) == 0) != (isalpha(-1) == 0))
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
