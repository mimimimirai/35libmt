#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	// オーバーフローチェック: nmemb * sizeがSIZE_MAXを超える場合
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的なcalloc（メモリが0で初期化されることを確認）
 * 2. calloc(0, 0)の動作確認
 * 3. calloc(0, size)の動作確認
 * 4. calloc(nmemb, 0)の動作確認
 * 5. オーバーフローチェック（非常に大きい値）
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int	main(void)
{
	void	*p1, *p2;
	int		failed = 0;

	printf("=== ft_calloc テスト ===\n");

	// テスト1: 基本的なcalloc
	p1 = calloc(2, 2);
	p2 = ft_calloc(2, 2);
	if (p1 && p2 && memcmp(p1, p2, 4) == 0)
		printf("OK: 基本的なcalloc\n");
	else
	{
		printf("FAIL: 基本的なcalloc\n");
		failed = 1;
	}
	free(p1);
	free(p2);

	// テスト2: calloc(0, 0)
	p1 = calloc(0, 0);
	p2 = ft_calloc(0, 0);
	if ((p1 != NULL) != (p2 != NULL))
	{
		printf("FAIL: calloc(0, 0)\n");
		failed = 1;
	}
	else
		printf("OK: calloc(0, 0)\n");
	if (p1) free(p1);
	if (p2) free(p2);

	// テスト3: calloc(0, 5)
	p1 = calloc(0, 5);
	p2 = ft_calloc(0, 5);
	if ((p1 != NULL) != (p2 != NULL))
	{
		printf("FAIL: calloc(0, 5)\n");
		failed = 1;
	}
	else
		printf("OK: calloc(0, 5)\n");
	if (p1) free(p1);
	if (p2) free(p2);

	// テスト4: calloc(5, 0)
	p1 = calloc(5, 0);
	p2 = ft_calloc(5, 0);
	if ((p1 != NULL) != (p2 != NULL))
	{
		printf("FAIL: calloc(5, 0)\n");
		failed = 1;
	}
	else
		printf("OK: calloc(5, 0)\n");
	if (p1) free(p1);
	if (p2) free(p2);

	// テスト5: オーバーフローチェック
	p2 = ft_calloc(SIZE_MAX, SIZE_MAX);
	if (p2 != NULL)
	{
		printf("FAIL: オーバーフローチェック\n");
		failed = 1;
	}
	else
		printf("OK: オーバーフローチェック\n");

	if (!failed)
		printf("\nOK: すべてのテストが成功しました\n");
	return (failed);
}
#endif