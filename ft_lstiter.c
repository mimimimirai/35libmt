#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst || !f) // NULLポインタのチェック
		return ;
	current = lst; // 最初のノードから開始
	while (current != NULL) // リストの最後まで繰り返す
	{
		f(current->content); // 現在のノードのcontentに関数fを適用
		current = current->next; // 次のノードに移動
	}
}

#ifdef TEST_MODE
// テスト用の関数: contentを表示する
void print_content(void *content)
{
	printf("Content: %s\n", (char *)content);
}

// テスト用の関数: contentを大文字に変換する（文字列の場合）
void uppercase_content(void *content)
{
	char *str = (char *)content;
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

// テスト用の関数: contentに数値を加算する（整数ポインタの場合）
void increment_int(void *content)
{
	int *num = (int *)content;
	(*num)++;
	printf("Incremented to: %d\n", *num);
}

int main(void)
{
	t_list *list = NULL;
	t_list *node1, *node2, *node3;
	char *content1, *content2, *content3;
	int *num1, *num2, *num3;
	t_list *int_list = NULL;
	t_list *n1, *n2, *n3;

	printf("=== Test 1: 文字列リストでprint_contentを適用 ===\n");
	// 文字列コンテンツを作成
	content1 = ft_strdup("Hello");
	content2 = ft_strdup("World");
	content3 = ft_strdup("42libft");

	// ノードを作成
	node1 = ft_lstnew(content1);
	node2 = ft_lstnew(content2);
	node3 = ft_lstnew(content3);

	// リストに追加
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	printf("List size: %d\n", ft_lstsize(list));
	printf("Applying print_content to each node:\n");
	ft_lstiter(list, print_content);

	printf("\n=== Test 2: 文字列を大文字に変換 ===\n");
	printf("Before uppercase:\n");
	ft_lstiter(list, print_content);
	ft_lstiter(list, uppercase_content);
	printf("After uppercase:\n");
	ft_lstiter(list, print_content);

	printf("\n=== Test 3: 整数リストでincrement_intを適用 ===\n");
	// 整数コンテンツを作成
	num1 = malloc(sizeof(int));
	num2 = malloc(sizeof(int));
	num3 = malloc(sizeof(int));
	*num1 = 1;
	*num2 = 2;
	*num3 = 3;

	// ノードを作成
	n1 = ft_lstnew(num1);
	n2 = ft_lstnew(num2);
	n3 = ft_lstnew(num3);

	// リストに追加
	ft_lstadd_back(&int_list, n1);
	ft_lstadd_back(&int_list, n2);
	ft_lstadd_back(&int_list, n3);

	printf("Applying increment_int to each node:\n");
	ft_lstiter(int_list, increment_int);

	printf("\n=== Test 4: NULLポインタのテスト ===\n");
	printf("Testing with NULL list (should do nothing):\n");
	ft_lstiter(NULL, print_content);
	printf("Testing with NULL function (should do nothing):\n");
	ft_lstiter(list, NULL);

	printf("\n=== Test 5: 空のリストのテスト ===\n");
	t_list *empty_list = NULL;
	printf("Testing with empty list (should do nothing):\n");
	ft_lstiter(empty_list, print_content);

	// クリーンアップ
	printf("\n=== Cleaning up ===\n");
	ft_lstclear(&list, free);
	ft_lstclear(&int_list, free);

	return (0);
}
#endif

