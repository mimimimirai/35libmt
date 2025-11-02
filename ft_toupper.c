#include "libft.h"

// Convert character to uppercase
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 小文字 ('a'-'z') が大文字に変換されることを確認
 * 2. 大文字 ('A'-'Z') がそのまま返されることを確認
 * 3. 数字や特殊文字がそのまま返されることを確認
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

	printf("=== ft_toupper テスト ===\n\n");

	// テスト1: 小文字を大文字に変換（例：'a'を表示）
	printf("【テスト1】小文字を大文字に変換\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'a', 'a');
	result = ft_toupper('a');
	result_libc = toupper('a');
	printf("  ft_toupper('%c') = '%c' (ASCII: %d)\n", 'a', result, result);
	printf("  toupper('%c')    = '%c' (ASCII: %d)\n", 'a', result_libc, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'a'; i <= 'z'; i++)
	{
		result = ft_toupper(i);
		result_libc = toupper(i);
		if (result != result_libc)
		{
			printf("FAIL: '%c' -> ft:'%c' libc:'%c'\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト2: 大文字はそのまま（例：'Z'を表示）
	printf("【テスト2】大文字はそのまま\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'Z', 'Z');
	result = ft_toupper('Z');
	result_libc = toupper('Z');
	printf("  ft_toupper('%c') = '%c' (ASCII: %d)\n", 'Z', result, result);
	printf("  toupper('%c')    = '%c' (ASCII: %d)\n", 'Z', result_libc, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'A'; i <= 'Z'; i++)
	{
		result = ft_toupper(i);
		result_libc = toupper(i);
		if (result != result_libc)
		{
			printf("FAIL: '%c' -> ft:'%c' libc:'%c'\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト3: 数字と特殊文字（例：'5'と'@'を表示）
	printf("【テスト3】数字と特殊文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '5', '5');
	result = ft_toupper('5');
	result_libc = toupper('5');
	printf("  ft_toupper('%c') = '%c' (ASCII: %d)\n", '5', result, result);
	printf("  toupper('%c')    = '%c' (ASCII: %d)\n", '5', result_libc, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	printf("  特殊文字の例:\n");
	printf("    '@':          ft_toupper='%c', toupper='%c'\n", ft_toupper('@'), toupper('@'));
	printf("    ' ':          ft_toupper='%c', toupper='%c'\n", ft_toupper(' '), toupper(' '));
	printf("\n");
	
	for (i = '0'; i <= '9'; i++)
	{
		result = ft_toupper(i);
		result_libc = toupper(i);
		if (result != result_libc)
		{
			printf("FAIL: '%c' -> ft:'%c' libc:'%c'\n", i, result, result_libc);
			failed = 1;
		}
	}

	if ((ft_toupper(' ') != toupper(' ')) ||
		(ft_toupper('@') != toupper('@')))
	{
		printf("FAIL: 特殊文字テスト\n");
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
