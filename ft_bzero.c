#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s; // ポインタをunsigned char型にキャスト
	i = 0;
	while (i < n)
	{
		ptr[i] = 0; // 0で埋める
		i++;
	}
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的なbzero（メモリを0で埋める）
 * 2. サイズ0の場合は何も変更しないことを確認
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[100];
	char	str2[100];
	int		failed = 0;

	printf("=== ft_bzero テスト ===\n");

	// テスト1: 基本的なbzero
	memset(str1, 'a', 100);
	memset(str2, 'a', 100);
	bzero(str1, 20);
	ft_bzero(str2, 20);
	if (memcmp(str1, str2, 100) != 0)
	{
		printf("FAIL: 基本的なbzeroテスト\n");
		failed = 1;
	}

	// テスト2: サイズ0
	memset(str1, '\x1', 100);
	memset(str2, '\x1', 100);
	ft_bzero(str1, 0);
	bzero(str2, 0);
	if (memcmp(str1, str2, 100) != 0)
	{
		printf("FAIL: サイズ0テスト\n");
		failed = 1;
	}

	if (!failed)
		printf("OK: すべてのテストが成功しました\n");
	return (failed);
}
#endif
