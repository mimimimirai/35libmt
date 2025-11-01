#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

total_size = count * size; // 総サイズを計算
	if (count != 0 && total_size / count != size) // オーバーフローチェック
		return (NULL);
	ptr = malloc(total_size); // メモリを確保
	if (ptr == NULL) // メモリ確保に失敗した場合
		return (NULL);
	bzero(ptr, total_size); // 確保したメモリを0で初期化
	return (ptr); // 確保したメモリのポインタを返す
}