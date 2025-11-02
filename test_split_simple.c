#include <stdio.h>
#include "libft.h"

void	print_split(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("arr[%d] = '%s'\n", i, arr[i]);
		i++;
	}
	printf("arr[%d] = NULL\n", i);
}

int	main(void)
{
	char **result;
	
	printf("=== Test 1: 'hello world' ===\n");
	result = ft_split("hello world", ' ');
	print_split(result);
	printf("\n");
	
	printf("=== Test 2: 'a,,b,c' (複数の区切り文字) ===\n");
	result = ft_split("a,,b,c", ',');
	print_split(result);
	printf("\n");
	
	printf("=== Test 3: '   leading   spaces' ===\n");
	result = ft_split("   leading   spaces", ' ');
	print_split(result);
	printf("\n");
	
	return (0);
}

