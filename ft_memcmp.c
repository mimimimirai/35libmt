#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s1; // ポインタをunsigned char型にキャスト
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i]) // 異なるバイトが見つかった場合
			return (ptr1[i] - ptr2[i]); // 差を返す
		i++;
	}
	return (0); // すべて同じ場合は0を返す
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 同じメモリ領域の比較（0を返す）
 * 2. 異なるメモリ領域の比較（非0を返す）
 * 3. サイズ0の場合は0を返すことを確認
 * 4. unsigned charキャストの確認（負の値の比較）
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*s1 = "hello";
	const char	*s2 = "hello";
	const char	*s3 = "world";
	int			result1, result2;
	int			failed = 0;

	printf("=== ft_memcmp テスト ===\n");

	// テスト1: 同じメモリ領域の比較
	result1 = memcmp(s1, s2, 5);
	result2 = ft_memcmp(s1, s2, 5);
	if ((result1 == 0) != (result2 == 0))
	{
		printf("FAIL: 同じメモリ領域の比較 (libc:%d, ft:%d)\n", result1, result2);
		failed = 1;
	}

	// テスト2: 異なるメモリ領域の比較
	result1 = memcmp(s1, s3, 5);
	result2 = ft_memcmp(s1, s3, 5);
	if ((result1 > 0) != (result2 > 0) && (result1 < 0) != (result2 < 0))
	{
		printf("FAIL: 異なるメモリ領域の比較 (libc:%d, ft:%d)\n", result1, result2);
		failed = 1;
	}

	// テスト3: サイズ0
	result1 = memcmp(s1, s3, 0);
	result2 = ft_memcmp(s1, s3, 0);
	if (result1 != result2)
	{
		printf("FAIL: サイズ0テスト (libc:%d, ft:%d)\n", result1, result2);
		failed = 1;
	}

	// テスト4: unsigned charキャスト（負の値）
	const char	str1[] = "\xff\x00";
	const char	str2[] = "\x00\x00";
	result1 = memcmp(str1, str2, 2);
	result2 = ft_memcmp(str1, str2, 2);
	if ((result1 > 0) != (result2 > 0))
	{
		printf("FAIL: unsigned charキャストテスト (libc:%d, ft:%d)\n", result1, result2);
		failed = 1;
	}

	if (!failed)
		printf("OK: すべてのテストが成功しました\n");
	return (failed);
}
#endif

