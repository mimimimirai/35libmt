#include "libft.h"

// Convert character to lowercase
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 大文字 ('A'-'Z') が小文字に変換されることを確認
 * 2. 小文字 ('a'-'z') がそのまま返されることを確認
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

	printf("=== ft_tolower テスト ===\n\n");

	// テスト1: 大文字を小文字に変換（例：'A'を表示）
	printf("【テスト1】大文字を小文字に変換\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'A', 'A');
	result = ft_tolower('A');
	result_libc = tolower('A');
	printf("  ft_tolower('%c') = '%c' (ASCII: %d)\n", 'A', result, result);
	printf("  tolower('%c')    = '%c' (ASCII: %d)\n", 'A', result_libc, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'A'; i <= 'Z'; i++)
	{
		result = ft_tolower(i);
		result_libc = tolower(i);
		if (result != result_libc)
		{
			printf("FAIL: '%c' -> ft:'%c' libc:'%c'\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト2: 小文字はそのまま（例：'z'を表示）
	printf("【テスト2】小文字はそのまま\n");
	printf("  入力: '%c' (ASCII: %d)\n", 'z', 'z');
	result = ft_tolower('z');
	result_libc = tolower('z');
	printf("  ft_tolower('%c') = '%c' (ASCII: %d)\n", 'z', result, result);
	printf("  tolower('%c')    = '%c' (ASCII: %d)\n", 'z', result_libc, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	for (i = 'a'; i <= 'z'; i++)
	{
		result = ft_tolower(i);
		result_libc = tolower(i);
		if (result != result_libc)
		{
			printf("FAIL: '%c' -> ft:'%c' libc:'%c'\n", i, result, result_libc);
			failed = 1;
		}
	}

	// テスト3: 数字と特殊文字（例：'9'と'@'を表示）
	printf("【テスト3】数字と特殊文字\n");
	printf("  入力: '%c' (ASCII: %d)\n", '9', '9');
	result = ft_tolower('9');
	result_libc = tolower('9');
	printf("  ft_tolower('%c') = '%c' (ASCII: %d)\n", '9', result, result);
	printf("  tolower('%c')    = '%c' (ASCII: %d)\n", '9', result_libc, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	printf("  特殊文字の例:\n");
	printf("    '@':          ft_tolower='%c', tolower='%c'\n", ft_tolower('@'), tolower('@'));
	printf("    ' ':          ft_tolower='%c', tolower='%c'\n", ft_tolower(' '), tolower(' '));
	printf("\n");
	
	for (i = '0'; i <= '9'; i++)
	{
		result = ft_tolower(i);
		result_libc = tolower(i);
		if (result != result_libc)
		{
			printf("FAIL: '%c' -> ft:'%c' libc:'%c'\n", i, result, result_libc);
			failed = 1;
		}
	}

	if ((ft_tolower(' ') != tolower(' ')) ||
		(ft_tolower('@') != tolower('@')))
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
