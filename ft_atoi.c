#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int	i;

	sign = 1; // 符号を初期化（正の数）
	result = 0; // 結果を初期化
	i = 0;
	while (is_space(str[i])) // 空白文字をスキップ
		i++;
	if (str[i] == '+' || str[i] == '-') // 符号をチェック
	{
		if (str[i] == '-')
			sign = -1; // 負の数の場合
		i++;
	}
	while (ft_isdigit(str[i])) // 数字を読み取り
	{
		result = result * 10 + (str[i] - '0'); // 数値に変換
		i++;
	}
	return (result * sign); // 符号を適用して返す
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的な正の数（"945"など）
 * 2. 基本的な負の数（"-085"など）
 * 3. 0の処理（"0"）
 * 4. 空白文字のスキップ（"\t\v\f\r\n \f-06050"など）
 * 5. プラス記号の処理（"+1234"など）
 * 6. 文字列の途中で数字が終わる場合（"-123THERE..."など）
 * 7. INT_MAX, INT_MINの処理
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int	main(void)
{
	char	*test_strs[] = {
		"0", "945", "-085", "+1234",
		"\t\v\f\r\n \f-06050",
		"-123THERE IS A NYANCAT UNDER YOUR BED",
		NULL
	};
	char	buf[30];
	int		i, result, result_libc, failed = 0;

	printf("=== ft_atoi テスト ===\n\n");

	// テスト1: 基本的な正の数（例："945"を表示）
	printf("【テスト1】基本的な正の数\n");
	printf("  入力: \"%s\"\n", "945");
	result = ft_atoi("945");
	result_libc = atoi("945");
	printf("  ft_atoi(\"%s\") = %d\n", "945", result);
	printf("  atoi(\"%s\")    = %d\n", "945", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	i = 0;
	while (test_strs[i] != NULL)
	{
		result = ft_atoi(test_strs[i]);
		result_libc = atoi(test_strs[i]);
		if (result != result_libc)
		{
			printf("FAIL: \"%s\" -> ft:%d, libc:%d\n", test_strs[i], result, result_libc);
			failed = 1;
		}
		i++;
	}

	// テスト2: 負の数（例："-085"を表示）
	printf("【テスト2】負の数\n");
	printf("  入力: \"%s\"\n", "-085");
	result = ft_atoi("-085");
	result_libc = atoi("-085");
	printf("  ft_atoi(\"%s\") = %d\n", "-085", result);
	printf("  atoi(\"%s\")    = %d\n", "-085", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");

	// テスト3: 空白文字のスキップ（例：タブと空白を含む文字列）
	printf("【テスト3】空白文字のスキップ\n");
	printf("  入力: \"\\t\\t-06050\" (タブと'-'を含む)\n");
	result = ft_atoi("\t\t-06050");
	result_libc = atoi("\t\t-06050");
	printf("  ft_atoi(\"\\t\\t-06050\") = %d\n", result);
	printf("  atoi(\"\\t\\t-06050\")    = %d\n", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");

	// テスト4: プラス記号（例："+1234"を表示）
	printf("【テスト4】プラス記号\n");
	printf("  入力: \"%s\"\n", "+1234");
	result = ft_atoi("+1234");
	result_libc = atoi("+1234");
	printf("  ft_atoi(\"%s\") = %d\n", "+1234", result);
	printf("  atoi(\"%s\")    = %d\n", "+1234", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");

	// テスト5: 数字の後に文字がある場合（例："-123THERE..."を表示）
	printf("【テスト5】数字の後に文字がある場合\n");
	printf("  入力: \"%s\"\n", "-123THERE IS A NYANCAT UNDER YOUR BED");
	result = ft_atoi("-123THERE IS A NYANCAT UNDER YOUR BED");
	result_libc = atoi("-123THERE IS A NYANCAT UNDER YOUR BED");
	printf("  ft_atoi(...) = %d (数字部分のみを抽出)\n", result);
	printf("  atoi(...)    = %d\n", result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");

	// テスト6: INT_MAX
	printf("【テスト6】INT_MAX\n");
	sprintf(buf, "%d", INT_MAX);
	result = ft_atoi(buf);
	result_libc = atoi(buf);
	printf("  入力: \"%s\"\n", buf);
	printf("  ft_atoi(\"%s\") = %d\n", buf, result);
	printf("  atoi(\"%s\")    = %d\n", buf, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	if (result != result_libc)
	{
		printf("FAIL: INT_MAX -> ft:%d, libc:%d\n", result, result_libc);
		failed = 1;
	}

	// テスト7: INT_MIN
	printf("【テスト7】INT_MIN\n");
	sprintf(buf, "%d", INT_MIN);
	result = ft_atoi(buf);
	result_libc = atoi(buf);
	printf("  入力: \"%s\"\n", buf);
	printf("  ft_atoi(\"%s\") = %d\n", buf, result);
	printf("  atoi(\"%s\")    = %d\n", buf, result_libc);
	printf("  → %s\n\n", (result == result_libc) ? "✓ 一致" : "✗ 不一致");
	
	if (result != result_libc)
	{
		printf("FAIL: INT_MIN -> ft:%d, libc:%d\n", result, result_libc);
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

