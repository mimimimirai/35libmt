#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0') // 文字列の終端までカウント
		len++;
	return (len); // 文字列の長さを返す
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的な文字列（"sais-tu compter ?"など）
 * 2. 空文字列（""）が0を返すことを確認
 * 3. 文字列の中に\0がある場合（"HAHAHAHA \0 TA FAIL XD"）
 * 4. 長い文字列
 * 5. 特殊文字を含む文字列
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*test1 = "sais-tu compter ?";
	const char	*test2 = "";
	const char	*test3 = "HAHAHAHA \0 TA FAIL XD";
	size_t		result, result_libc;
	int			failed = 0;

	printf("=== ft_strlen テスト ===\n\n");

	// テスト1: 基本的な文字列（例："sais-tu compter ?"を表示）
	printf("【テスト1】基本的な文字列\n");
	printf("  入力: \"%s\"\n", test1);
	result = ft_strlen(test1);
	result_libc = strlen(test1);
	printf("  ft_strlen(\"%s\") = %zu\n", test1, result);
	printf("  strlen(\"%s\")    = %zu\n", test1, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	if (result != result_libc)
	{
		printf("FAIL: \"%s\" -> ft:%zu, libc:%zu\n", test1, result, result_libc);
		failed = 1;
	}

	// テスト2: 空文字列（例：""を表示）
	printf("【テスト2】空文字列\n");
	printf("  入力: \"\" (空文字列)\n");
	result = ft_strlen(test2);
	result_libc = strlen(test2);
	printf("  ft_strlen(\"\") = %zu\n", result);
	printf("  strlen(\"\")    = %zu\n", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	if (result != result_libc)
	{
		printf("FAIL: 空文字列 -> ft:%zu, libc:%zu\n", result, result_libc);
		failed = 1;
	}

	// テスト3: 文字列の中に\0がある場合（例："HAHAHAHA \0 TA FAIL XD"を表示）
	printf("【テスト3】文字列の中に\\0がある場合\n");
	printf("  入力: \"HAHAHAHA \\0 TA FAIL XD\" (\\0を含む)\n");
	result = ft_strlen(test3);
	result_libc = strlen(test3);
	printf("  ft_strlen(...) = %zu (\\0までをカウント)\n", result);
	printf("  strlen(...)    = %zu\n", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	if (result != result_libc)
	{
		printf("FAIL: \\0を含む文字列 -> ft:%zu, libc:%zu\n", result, result_libc);
		failed = 1;
	}

	// テスト4: 長い文字列（例：長い文字列を表示）
	printf("【テスト4】長い文字列\n");
	const char *long_str = "01234567, AAAAAA, abc\xba e, ......, end of string !";
	printf("  入力: \"%s\"\n", long_str);
	result = ft_strlen(long_str);
	result_libc = strlen(long_str);
	printf("  ft_strlen(...) = %zu\n", result);
	printf("  strlen(...)    = %zu\n", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	if (result != result_libc)
	{
		printf("FAIL: 長い文字列 -> ft:%zu, libc:%zu\n", result, result_libc);
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

