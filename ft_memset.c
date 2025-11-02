#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b; // ポインタをunsigned char型にキャスト
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c; // int型のcをunsigned char型にキャスト
		i++;
	}
	return (b); // 元のポインタを返す
}

/*
 * テスト: francinette/libft-unit-test参照
 * テストケース:
 * 1. 基本的なメモリ埋め込み（正常なサイズ、正常な文字）
 * 2. unsigned charキャストテスト（負の値や範囲外の値）
 * 3. 戻り値が正しいポインタを返すことを確認
 * 4. サイズ0の場合は何も変更しないことを確認
 */
#ifdef MAIN_TEST
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	b1[100];
	char	b2[100];
	void	*ret1, *ret2;
	int		failed = 0;
	int		i;

	printf("=== ft_memset テスト ===\n\n");

	// テスト1: 基本的なメモリ埋め込み（例：'A'で20バイト埋める）
	printf("【テスト1】基本的なメモリ埋め込み\n");
	printf("  入力: バッファ100バイト, 値='A', サイズ=20\n");
	memset(b1, 'B', 100);
	memset(b2, 'B', 100);
	memset(b1, 'A', 20);      // 標準ライブラリで埋める（比較用）
	ft_memset(b2, 'A', 20);   // 自作関数で埋める（テスト対象）
	printf("  結果: 最初の20バイトを'A'で埋める\n");
	printf("  b1[0-5]: ");
	for (i = 0; i < 6; i++)
		printf("'%c' ", b1[i]);
	printf("\n  b2[0-5]: ");
	for (i = 0; i < 6; i++)
		printf("'%c' ", b2[i]);
	printf("\n  → %s\n\n", (memcmp(b1, b2, 20) == 0) ? "✓ 一致" : "✗ 不一致");
	
	if (memcmp(b1, b2, 20) != 0)
	{
		printf("FAIL: 基本的なメモリ埋め込み\n");
		failed = 1;
	}

	// テスト2: unsigned charキャストテスト
	// 128はASCII範囲(0-127)を超える値で、符号付きcharの範囲（通常-128〜127）を超える
	// int型パラメータをunsigned charに正しくキャストできることを確認
	printf("【テスト2】unsigned charキャストテスト\n");
	printf("  入力: 値=128 (ASCII範囲外、符号付きcharの範囲を超える値)\n");
	printf("  説明: 符号付きcharの範囲(127)を超える値でも、\n");
	printf("        unsigned charにキャストして正しく処理できることを確認\n");
	memset(b1, 0, 100);
	memset(b2, 0, 100);
	memset(b1, 128, 22);        // 直接数値128を使用
	ft_memset(b2, 128, 22);     // 直接数値128を使用
	printf("  結果: 最初の22バイトを128で埋める\n");
	printf("  b1[0] = %d (unsigned charとして解釈)\n", (unsigned char)b1[0]);
	printf("  b2[0] = %d\n", (unsigned char)b2[0]);
	printf("  → %s\n\n", (memcmp(b1, b2, 22) == 0) ? "✓ 一致" : "✗ 不一致");
	
	if (memcmp(b1, b2, 22) != 0)
	{
		printf("FAIL: unsigned charキャストテスト\n");
		failed = 1;
	}

	// テスト3: 戻り値の確認（例：戻り値が正しいポインタか確認）
	printf("【テスト3】戻り値の確認\n");
	printf("  入力: バッファ100バイト, 値='A', サイズ=18\n");
	memset(b1, 'B', 100);
	memset(b2, 'B', 100);
	ret1 = memset(b1, 'A', 18);
	ret2 = ft_memset(b2, 'A', 18);
	printf("  memset の戻り値 = %p (入力バッファ=%p)\n", ret1, b1);
	printf("  ft_memset の戻り値 = %p (入力バッファ=%p)\n", ret2, b2);
	printf("  → %s\n\n", (ret1 == b1 && ret2 == b2) ? "✓ 一致" : "✗ 不一致");
	
	if (ret1 != b1 || ret2 != b2)
	{
		printf("FAIL: 戻り値テスト\n");
		failed = 1;
	}
	if (memcmp(b1, b2, 100) != 0)
	{
		printf("FAIL: 戻り値後のメモリ比較\n");
		failed = 1;
	}

	// テスト4: サイズ0（例：サイズ0の場合は何も変更しない）
	printf("【テスト4】サイズ0\n");
	printf("  入力: 値='\\xff', サイズ=0 (何も変更しない)\n");
	memset(b1, 0, 100);
	memset(b2, 0, 100);
	ft_memset(b1, '\xff', 0);
	memset(b2, '\xff', 0);
	printf("  結果: バッファは0のまま\n");
	printf("  b1[0] = %d\n", (unsigned char)b1[0]);
	printf("  b2[0] = %d\n", (unsigned char)b2[0]);
	printf("  → %s\n\n", (memcmp(b1, b2, 100) == 0) ? "✓ 一致" : "✗ 不一致");
	
	if (memcmp(b1, b2, 100) != 0)
	{
		printf("FAIL: サイズ0テスト\n");
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
