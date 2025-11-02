#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dst == NULL && src == NULL) // 両方のポインタがNULLの場合は何もしない
		return (dst);
	d = (unsigned char *)dst; // ポインタをunsigned char型にキャスト
	s = (const unsigned char *)src;
	if (d < s) // 前方からコピー（重複しない場合）
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else // 後方からコピー（重複する場合）
	{
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dst); // 元のポインタを返す
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的なメモリ移動（前方から後方へ）
 * 2. 重複メモリの移動（後方から前方へ）- これがmemmoveの重要な機能
 * 3. サイズ0の場合は何も移動しないことを確認
 * 4. 戻り値が正しいポインタを返すことを確認
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[] = "hello world";
	char	str2[] = "hello world";
	char	str3[] = "memmove is useful";
	char	str4[] = "memmove is useful";
	void	*ret1, *ret2;
	int		failed = 0;

	printf("=== ft_memmove テスト ===\n");

	// テスト1: 基本的なメモリ移動（前方から後方へ）
	memmove(str1, str1 + 6, 5);
	ft_memmove(str2, str2 + 6, 5);
	if (strcmp(str1, str2) != 0)
	{
		printf("FAIL: 基本的なメモリ移動\n");
		failed = 1;
	}

	// テスト2: 重複メモリの移動（後方から前方へ）
	strcpy(str3, "memmove is useful");
	strcpy(str4, "memmove is useful");
	memmove(str3 + 8, str3, 9);
	ft_memmove(str4 + 8, str4, 9);
	if (strcmp(str3, str4) != 0)
	{
		printf("FAIL: 重複メモリの移動\n");
		printf("  libc: %s\n", str3);
		printf("  ft:   %s\n", str4);
		failed = 1;
	}

	// テスト3: サイズ0
	memset(str1, 'A', 11);
	memset(str2, 'A', 11);
	memmove(str1, str1 + 1, 0);
	ft_memmove(str2, str2 + 1, 0);
	if (memcmp(str1, str2, 11) != 0)
	{
		printf("FAIL: サイズ0テスト\n");
		failed = 1;
	}

	// テスト4: 戻り値
	ret1 = memmove(str1, str1 + 1, 5);
	ret2 = ft_memmove(str2, str2 + 1, 5);
	if (ret1 != str1 || ret2 != str2)
	{
		printf("FAIL: 戻り値テスト\n");
		failed = 1;
	}

	if (!failed)
		printf("OK: すべてのテストが成功しました\n");
	return (failed);
}
#endif
