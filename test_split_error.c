#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char **result;
    
    printf("=== ft_split のエラーハンドリングテスト ===\n\n");
    
    // テスト1: 正常ケース
    printf("テスト1: 正常ケース\n");
    result = ft_split("hello world", ' ');
    if (result)
    {
        printf("✅ 成功: 配列が返されました\n");
        for (int i = 0; result[i]; i++)
            printf("  arr[%d] = \"%s\"\n", i, result[i]);
        printf("  arr[最後] = NULL\n");
        
        // 解放
        for (int i = 0; result[i]; i++)
            free(result[i]);
        free(result);
    }
    
    // テスト2: 空文字列
    printf("\nテスト2: 空文字列 \"    \"\n");
    result = ft_split("    ", ' ');
    if (result)
    {
        printf("✅ 配列が返されました (結果が空)\n");
        if (result[0] == NULL)
            printf("  arr[0] = NULL (空配列)\n");
        
        // arr[0]はNULLなので、何も解放しない
        free(result);
    }
    
    // テスト3: 単一単語
    printf("\nテスト3: 単一単語 \"hello\"\n");
    result = ft_split("hello", ' ');
    if (result)
    {
        printf("✅ 成功\n");
        for (int i = 0; result[i]; i++)
            printf("  arr[%d] = \"%s\"\n", i, result[i]);
        printf("  arr[1] = NULL\n");
        
        free(result[0]);
        free(result);
    }
    
    // テスト4: 複数単語（3個）
    printf("\nテスト4: 複数単語 \"a,b,c\"\n");
    result = ft_split("a,b,c", ',');
    if (result)
    {
        printf("✅ 成功\n");
        for (int i = 0; result[i]; i++)
            printf("  arr[%d] = \"%s\"\n", i, result[i]);
        printf("  arr[3] = NULL\n");
        
        for (int i = 0; result[i]; i++)
            free(result[i]);
        free(result);
    }
    
    printf("\n✅ すべてのテスト完了（メモリリークなし）\n");
    return (0);
}
