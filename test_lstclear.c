#include <stdio.h>
#include "libft.h"

// del関数の例
void del_content(void *content)
{
	printf("Deleting content: %s\n", (char *)content);
	free(content);
}

int main(void)
{
	t_list *list = NULL;
	t_list *node1, *node2, *node3;
	char *content1, *content2, *content3;

	printf("Creating test list...\n");
	
	// コンテンツを作成
	content1 = ft_strdup("Node 1");
	content2 = ft_strdup("Node 2");
	content3 = ft_strdup("Node 3");

	// ノードを作成
	node1 = ft_lstnew(content1);
	node2 = ft_lstnew(content2);
	node3 = ft_lstnew(content3);

	// リストに追加
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	printf("List size: %d\n", ft_lstsize(list));
	
	printf("\nClearing list...\n");
	
	// リスト全体を削除
	ft_lstclear(&list, del_content);
	
	printf("List cleared. list pointer is: %p (should be NULL)\n", (void *)list);
	
	return (0);
}

