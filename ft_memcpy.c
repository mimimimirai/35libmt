#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (dst == NULL && src == NULL) // 両方のポインタがNULLの場合は何もしない
		return (dst);
	dst_ptr = (unsigned char *)dst; // ポインタをunsigned char型にキャスト
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i]; // 1バイトずつコピー
		i++;
	}
	return (dst); // 元のポインタを返す
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的なメモリコピー
 * 2. サイズ0の場合は何もコピーしないことを確認
 * 3. 戻り値が正しいポインタを返すことを確認
 * 注意: 重複メモリにはmemmoveを使用する必要がある
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "test basic du memcpy !";
	char	buff1[22];
	char	buff2[22];
	void	*ret1, *ret2;
	int		failed = 0;

	printf("=== ft_memcpy テスト ===\n");

	// テスト1: 基本的なメモリコピー
	memcpy(buff1, src, 22);
	ft_memcpy(buff2, src, 22);
	if (memcmp(buff1, buff2, 22) != 0)
	{
		printf("FAIL: 基本的なメモリコピー\n");
		failed = 1;
	}

	// テスト2: サイズ0
	memset(buff1, 'A', 22);
	memset(buff2, 'A', 22);
	memcpy(buff1, src, 0);
	ft_memcpy(buff2, src, 0);
	if (memcmp(buff1, buff2, 22) != 0)
	{
		printf("FAIL: サイズ0テスト\n");
		failed = 1;
	}

	// テスト3: 戻り値
	ret1 = memcpy(buff1, src, 22);
	ret2 = ft_memcpy(buff2, src, 22);
	if (ret1 != buff1 || ret2 != buff2)
	{
		printf("FAIL: 戻り値テスト\n");
		failed = 1;
	}

	if (!failed)
		printf("OK: すべてのテストが成功しました\n");
	return (failed);
}
#endif
