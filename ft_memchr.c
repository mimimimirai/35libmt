#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s; // ポインタをunsigned char型にキャスト
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c) // 文字cが見つかった場合
			return ((void *)(ptr + i)); // そのアドレスを返す
		i++;
	}
	return (NULL); // 文字cが見つからなかった場合はNULLを返す
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的な文字検索（見つかる場合）
 * 2. 文字が見つからない場合（NULLを返す）
 * 3. 検索範囲内で見つかる場合と範囲外の場合
 * 4. unsigned charキャストの確認（負の値など）
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*s = "hello world";
	void		*ret1, *ret2;
	const char	*test1 = "abcdef\0ghij";
	int			failed = 0;

	printf("=== ft_memchr テスト ===\n");

	// テスト1: 基本的な文字検索（見つかる場合）
	ret1 = memchr(s, 'o', strlen(s));
	ret2 = ft_memchr(s, 'o', strlen(s));
	if (ret1 != ret2)
	{
		printf("FAIL: 基本的な文字検索\n");
		failed = 1;
	}

	// テスト2: 文字が見つからない場合
	ret1 = memchr(s, 'z', strlen(s));
	ret2 = ft_memchr(s, 'z', strlen(s));
	if (ret1 != ret2)
	{
		printf("FAIL: 文字が見つからない場合\n");
		failed = 1;
	}

	// テスト3: 検索範囲内で見つかる場合
	ret1 = memchr(test1, 'g', 11);
	ret2 = ft_memchr(test1, 'g', 11);
	if (ret1 != ret2)
	{
		printf("FAIL: 検索範囲内テスト\n");
		failed = 1;
	}

	// テスト4: unsigned charキャスト
	ret1 = memchr(s, 256 + 'o', strlen(s)); // 'o'と同等になる
	ret2 = ft_memchr(s, 256 + 'o', strlen(s));
	if (ret1 != ret2)
	{
		printf("FAIL: unsigned charキャストテスト\n");
		failed = 1;
	}

	if (!failed)
		printf("OK: すべてのテストが成功しました\n");
	return (failed);
}
#endif

