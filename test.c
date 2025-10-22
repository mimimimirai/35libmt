
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include "libft.h"

#define CHAR_MAX 256
#define BUFFER_SIZE 11

#ifdef FT
#define ISALPHA ft_isalpha
#define ISDIGIT ft_isdigit
#define ISALNUM ft_isalnum
#define ISASCII ft_isascii
#define ISPRINT ft_isprint
#define STRLEN ft_strlen
#define MEMSET ft_memset
#define BZERO ft_bzero
#define MEMCPY ft_memcpy
#define MEMMOVE ft_memmove
#define STRLCPY ft_strlcpy
#define STRLCAT ft_strlcat
#define TOUPPER ft_toupper
#define TOLOWER ft_tolower
#define STRCHR ft_strchr
#define STRRCHR ft_strrchr
#define STRNCMP ft_strncmp
#define MEMCHR ft_memchr
#define MEMCMP ft_memcmp
#define STRNSTR ft_strnstr
#define ATOI ft_atoi
#define CALLOC ft_calloc
#define STRDUP ft_strdup
#define PART2 part2_user
#else
#define ISALPHA isalpha
#define ISDIGIT isdigit
#define ISALNUM isalnum
#define ISASCII isascii
#define ISPRINT isprint
#define STRLEN strlen
#define MEMSET memset
#define BZERO bzero
#define MEMCPY memcpy
#define MEMMOVE memmove
#define STRLCPY strlcpy
#define STRLCAT strlcat
#define TOUPPER toupper
#define TOLOWER tolower
#define STRCHR strchr
#define STRRCHR strrchr
#define STRNCMP strncmp
#define MEMCHR memchr
#define MEMCMP memcmp
#define STRNSTR strnstr
#define ATOI atoi
#define CALLOC calloc
#define STRDUP strdup
#define PART2 part2_expected
#endif

void	part2_user(void);
void	part2_expected(void);
char	mapi_func(unsigned int i, char c);

// テスト用ヘルパー関数
void	test_char_function(const char *name, int (*func)(int));
void	test_strlen_function(void);
void	test_memset_function(void);
void	test_bzero_function(void);
void	test_memcpy_function(void);
void	test_memmove_function(void);
void	test_strlcpy_function(void);
void	test_strlcat_function(void);
void	test_toupper_function(void);
void	test_tolower_function(void);
void	test_strchr_function(void);
void	test_strrchr_function(void);
void	test_strncmp_function(void);
void	test_memchr_function(void);
void	test_memcmp_function(void);
void	test_strnstr_function(void);
void	test_atoi_function(void);
void	test_calloc_function(void);
void	test_strdup_function(void);

int	main(int ac, char **av)
{
	// Part 1: 文字判定関数のテスト
	test_char_function("isalpha", ISALPHA);
	test_char_function("isdigit", ISDIGIT);
	test_char_function("isalnum", ISALNUM);
	test_char_function("isascii", ISASCII);
	test_char_function("isprint", ISPRINT);
	// Part 1: 文字列・メモリ関数のテスト
	test_strlen_function();
	test_memset_function();
	test_bzero_function();
	test_memcpy_function();
	test_memmove_function();
	test_strlcpy_function();
	test_strlcat_function();
	test_toupper_function();
	test_tolower_function();
	test_strchr_function();
	test_strrchr_function();
	test_strncmp_function();
	test_memchr_function();
	test_memcmp_function();
	test_strnstr_function();
	test_atoi_function();
	test_calloc_function();
	test_strdup_function();
	printf("=====END OF PART 1=====\n");
	printf("\n\n");
	printf("=====PART 2=====\n");
	printf("\n");
	PART2();
	return (0);
}

char	mapi_func(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper(c));
	return (tolower(c));
}

// テスト用ヘルパー関数の実装
void	test_char_function(const char *name, int (*func)(int))
{
	printf("=====%s=====\n", name);
	for (int i = 0; i < CHAR_MAX; i++)
		printf("%d, ", !!func(i));
	printf("\n");
}

void	test_strlen_function(void)
{
	printf("=====STRLEN=====\n");
	char str[BUFFER_SIZE];
	bzero(str, BUFFER_SIZE);
	strcpy(str, "hello");
	printf("%ld\n", STRLEN(str));
	bzero(str, BUFFER_SIZE);
	printf("%ld\n", STRLEN(str));
	printf("\n");
}

void	test_memset_function(void)
{
	printf("=====MEMSET=====\n");
	char mem[BUFFER_SIZE];
	bzero(mem, BUFFER_SIZE);
	MEMSET((void *)mem, '*', 10);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	int	zero = 0;
	bzero(mem, BUFFER_SIZE);
	MEMSET((void *)mem, '8', zero);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	MEMSET((void *)mem, '*' + 256, 10);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
}

void	test_bzero_function(void)
{
	printf("=====BZERO=====\n");
	char mem[BUFFER_SIZE];
	bzero(mem, BUFFER_SIZE);
	memset((void *)mem, '*', 10);
	printf("mem: %s\n", mem);
	BZERO(mem, 10);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	bzero(mem, BUFFER_SIZE);
	memset((void *)mem, '*', 10);
	int	zero = 0;
	BZERO(mem, zero);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	printf("end of BZERO\n");
}

void	test_memcpy_function(void)
{
	printf("=====MEMCPY=====\n");
	char mem[BUFFER_SIZE];
	char src[BUFFER_SIZE] = "hello";
	void *nullptr = NULL;
	
	bzero(mem, BUFFER_SIZE);
	MEMCPY((void *)mem, (void *)src, 10);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	bzero(mem, 10);
	MEMCPY((void *)mem, (void *)src, 0);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	MEMCPY((void *)mem, nullptr, 0);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	MEMCPY(nullptr, nullptr, 0);
	for(int i = 0; i < 10; i++)
		printf("%d, ", mem[i]);
	printf("\n");
}

void	test_memmove_function(void)
{
	printf("=====MEMMOVE=====\n");
	char mem[BUFFER_SIZE];
	char src[BUFFER_SIZE] = "hello";
	
	bzero(mem, 10);
	MEMMOVE(mem, src, 10);
	for(int i = 0; i < 11; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	memset((void *)mem, '0', 10);
	memset((void *)&mem[5], '1', 5);
	MEMMOVE(mem, &mem[3], 5);
	for(int i = 0; i < 11; i++)
		printf("%d, ", mem[i]);
	printf("\n");
	memset((void *)mem, '0', 10);
	memset((void *)&mem[5], '1', 5);
	MEMMOVE(&mem[3], mem, 5);
	for(int i = 0; i < 11; i++)
		printf("%d, ", mem[i]);
	printf("\n");
}

void	test_strlcpy_function(void)
{
	printf("=====STRLCPY=====\n");
	char mem[BUFFER_SIZE];
	char src[BUFFER_SIZE] = "hello";
	void *nullptr = NULL;
	int	res;
	
	bzero(mem, 10);
	res = STRLCPY(mem, src, 10);
	printf("%d, %s\n", res, mem);
	bzero(mem, 10);
	res = STRLCPY(mem, src, 3);
	printf("%d, %s\n", res, mem);
	bzero(mem, 10);
	res = STRLCPY(mem, src, 0);
	printf("%d, %s\n", res, mem);
	printf("\n");
	res = STRLCPY(nullptr, src, 0);
	printf("%d, %s\n", res, mem);
	printf("\n");
}

void	test_strlcat_function(void)
{
	printf("=====STRLCAT=====\n");
	char mem[BUFFER_SIZE];
	char src[BUFFER_SIZE] = "hello";
	void *nullptr = NULL;
	int	res;
	
	bzero(mem, 10);
	res = STRLCAT(mem, src, 10);
	printf("%d, %s\n", res, mem);
	bzero(mem, 10);
	strcpy(mem, "42");
	res = STRLCAT(mem, src, 10);
	printf("%d, %s\n", res, mem);
	bzero(mem, 10);
	strcpy(mem, "42");
	res = STRLCAT(mem, src, 3);
	printf("%d, %s\n", res, mem);
	bzero(mem, 10);
	strcpy(mem, "42");
	res = STRLCAT(mem, src, 0);
	printf("%d, %s\n", res, mem);
	printf("\n");
	res = STRLCAT(nullptr, src, 0);
	printf("%d, %s\n", res, mem);
	printf("\n");
}

void	test_toupper_function(void)
{
	printf("=====TOUPPER=====\n");
	for (int i = 0; i < CHAR_MAX; i++)
		printf("%c, ", TOUPPER(i));
	printf("\n");
}

void	test_tolower_function(void)
{
	printf("=====TOLOWER=====\n");
	for(int i = 0; i < CHAR_MAX; i++)
		printf("%c, ", TOLOWER(i));
	printf("\n");
}

void	test_strchr_function(void)
{
	printf("=====STRCHR=====\n");
	char mem[BUFFER_SIZE];
	void *nullptr = NULL;
	
	bzero(mem, 10);
	strcpy(mem, "hello42");
	char *resptr;
	resptr = STRCHR(mem, 'e');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRCHR(mem, '2');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRCHR(mem, '\0');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRCHR(mem, '8');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRCHR(mem, 'h' + 256);
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRCHR(mem, 'h' - 256);
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRCHR("", '*');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	printf("\n");
}

void	test_strrchr_function(void)
{
	printf("=====STRRCHR=====\n");
	char mem[BUFFER_SIZE];
	
	bzero(mem, 10);
	strcpy(mem, "42hello42");
	char *resptr;
	resptr = STRRCHR(mem, 'e');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRRCHR(mem, 'l');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRRCHR(mem, '2');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRRCHR(mem, '\0');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRRCHR(mem, '8');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	resptr = STRRCHR("", '*');
	if (resptr)
		printf("%s\n", resptr);
	else
		printf("NULL\n");
	printf("\n");
}

void	test_strncmp_function(void)
{
	printf("=====STRNCMP=====\n");
	char str[BUFFER_SIZE];
	char mem[BUFFER_SIZE];
	void *nullptr = NULL;
	
	strcpy(str, "hello");
	bzero(mem, 10);
	strcpy(mem, "hello42");
	printf("%d\n", STRNCMP(mem, str, 5));
	printf("%d\n", STRNCMP(mem, str, 0));
	printf("%d\n", STRNCMP(mem, str, 10));
	printf("%d\n", STRNCMP(mem, str, 20));
	bzero(mem, 10);
	printf("%d\n", STRNCMP(mem, str, 5));
	printf("%d\n", STRNCMP(mem, str, 0));
	printf("%d\n", STRNCMP(mem, str, 10));
	printf("%d\n", STRNCMP(mem, str, 20));
	printf("%d\n", STRNCMP(mem, str, 0));
	printf("%d\n", STRNCMP(mem, nullptr, 0));
	printf("%d\n", STRNCMP(nullptr, str, 0));
	printf("%d\n", STRNCMP(nullptr, nullptr, 0));
	printf("\n");
}

void	test_memchr_function(void)
{
	printf("=====MEMCHR=====\n");
	char mem[BUFFER_SIZE];
	void *nullptr = NULL;
	
	bzero(mem, 10);
	strcpy(mem, "hello");
	char	*memcharres;
	memcharres = (char *)MEMCHR((void *)mem, 'l', 5);
	if (memcharres)
		printf("%s\n", memcharres);
	else
		printf("NULL\n");
	memcharres = (char *)MEMCHR((void *)mem, 'l', 0);
	if (memcharres)
		printf("%s\n", memcharres);
	else
		printf("NULL\n");
	memcharres = (char *)MEMCHR((void *)mem, 'l', 1);
	if (memcharres)
		printf("%s\n", memcharres);
	else
		printf("NULL\n");
	memcharres = (char *)MEMCHR((void *)mem, 'l', 10);
	if (memcharres)
		printf("%s\n", memcharres);
	else
		printf("NULL\n");
	memcharres = (char *)MEMCHR((void *)mem, 128, 5);
	if (memcharres)
		printf("%s\n", memcharres);
	else
		printf("NULL\n");
	memcharres = (char *)MEMCHR((void *)mem, 'l' + 256, 5);
	if (memcharres)
		printf("%s\n", memcharres);
	else
		printf("NULL\n");
	memcharres = (char *)MEMCHR((void *)mem, 'l' - 256, 5);
	if (memcharres)
		printf("%s\n", memcharres);
	else
		printf("NULL\n");
	MEMCHR(nullptr, 42, 0);
	printf("\n");
}

void	test_memcmp_function(void)
{
	printf("=====MEMCMP=====\n");
	char mem[BUFFER_SIZE];
	char mem2[BUFFER_SIZE];
	void *nullptr = NULL;
	
	bzero(mem, 10);
	bzero(mem2, 11);
	strcpy(mem, "hello24");
	strcpy(mem2, "hello42");
	printf("%d\n", MEMCMP((void *)mem, (void *)mem2, 5));
	printf("%d\n", MEMCMP((void *)mem, (void *)mem2, 9));
	printf("%d\n", MEMCMP((void *)mem, (void *)mem2, 0));
	printf("%d\n", MEMCMP((void *)mem2, (void *)mem, 9));
	strcpy(mem, "he\0llo24");
	strcpy(mem2, "he\0llo42");
	printf("%d\n", MEMCMP((void *)mem, (void *)mem2, 0));
	printf("%d\n", MEMCMP((void *)mem, (void *)mem2, 9));
	printf("%d\n", MEMCMP(nullptr, (void *)mem2, 0));
	printf("%d\n", MEMCMP((void *)mem, nullptr, 0));
	printf("%d\n", MEMCMP(nullptr, nullptr, 0));
	printf("\n");
}

void	test_strnstr_function(void)
{
	printf("=====STRNSTR=====\n");
	char mem[BUFFER_SIZE];
	char mem2[BUFFER_SIZE];
	
	char *strnstrres;
	bzero(mem, 10);
	bzero(mem2, 10);
	strcpy(mem, "hello");
	strcpy(mem2, "he");
	strnstrres = STRNSTR(mem, mem2, 5);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strcpy(mem2, "ll");
	strnstrres = STRNSTR(mem, mem2, 5);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	bzero(mem2, 10);
	strnstrres = STRNSTR(mem, mem2, 5);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strcpy(mem2, "42");
	strnstrres = STRNSTR(mem, mem2, 5);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strnstrres = STRNSTR("", "", 0);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strnstrres = STRNSTR("", "a", 0);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strnstrres = STRNSTR("a", "", 0);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strnstrres = STRNSTR("", "", 10);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strnstrres = STRNSTR("", "a", 10);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	strnstrres = STRNSTR("a", "", 10);
	if (strnstrres)
		printf("%s\n", strnstrres);
	else
		printf("NULL\n");
	printf("\n");
}

void	test_atoi_function(void)
{
	printf("=====ATOI=====\n");
	printf("%d\n", ATOI("12345"));
	printf("%d\n", ATOI("0"));
	printf("%d\n", ATOI("-12345"));
	printf("%d\n", ATOI("\f\n\r\t\v -54321"));
	printf("%d\n", ATOI("123*45"));
	printf("%d\n", ATOI("2147483646"));
	printf("%d\n", ATOI("2147483647"));
	printf("%d\n", ATOI("2147483648"));
	printf("%d\n", ATOI("-2147483647"));
	printf("%d\n", ATOI("-2147483648"));
	printf("%d\n", ATOI("-2147483649"));
	printf("%d\n", ATOI("9223372036854775806"));
	printf("%d\n", ATOI("9223372036854775807"));
	printf("%d\n", ATOI("9223372036854775808"));
	printf("%d\n", ATOI("-9223372036854775807"));
	printf("%d\n", ATOI("-9223372036854775808"));
	printf("%d\n", ATOI("-9223372036854775809"));
	printf("%d\n", ATOI("9999999999999999999"));
	printf("%d\n", ATOI("-9999999999999999999"));
	printf("\n");
}

void	test_calloc_function(void)
{
	printf("=====CALLOC=====\n");
	int *intres;
	intres = (int *)CALLOC(5, sizeof(int));
	for (int i = 0; i < 5; i++)
		printf("%d, ", intres[i]);
	for (int i = 0; i < 5; i++)
		intres[i] = i;
	free(intres);
	printf("\n");
	intres = (int *)CALLOC(1000, sizeof(int));
	for (int i = 0; i < 1000; i++)
		printf("%d, ", intres[i]);
	for (int i = 0; i < 1000; i++)
		intres[i] = i;
	free(intres);
	intres = (int *)CALLOC(0, 0);
	printf("%d\n", intres == NULL);
	free(intres);
}

void	test_strdup_function(void)
{
	printf("=====STRDUP=====\n");
	char mem[BUFFER_SIZE];
	bzero(mem, 10);
	strcpy(mem, "hello");
	char *charres;
	charres = STRDUP(mem);
	printf("%s\n", charres);
	free(charres);
	bzero(mem, 10);
	charres = strdup(mem);
	printf("%s\n", charres);
	free(charres);
	charres = strdup("");
	printf("%s\n", charres);
	free(charres);
	printf("\n");
}

void	iteri_func(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = toupper(*c);
	else
		*c = tolower(*c);
}

#ifdef FT
void	part2_user(void)
{
	char *res;
	printf("=====SUBSTR=====\n");
	res = ft_substr("hello42!", 0, 5);
	printf("%s\n", res);
	free(res);
	res = ft_substr("hello42!", 0, 42);
	printf("%s\n", res);
	free(res);
	res = ft_substr("hello42!", 0, 0);
	printf("%s\n", res);
	free(res);
	res = ft_substr("hello42!", 5, 2);
	printf("%s\n", res);
	free(res);
	res = ft_substr("hello42!", 5, 0);
	printf("%s\n", res);
	free(res);
	res = ft_substr("hello42!", 5, 42);
	printf("%s\n", res);
	res = ft_substr(NULL, 0, 0); //NULL CHECK
	free(res);
	printf("=====STRJOIN=====\n");
	res = ft_strjoin("hello", "world");
	printf("%s\n", res);
	free(res);
	res = ft_strjoin("", "world");
	printf("%s\n", res);
	free(res);
	res = ft_strjoin("hello", "");
	printf("%s\n", res);
	free(res);
	res = ft_strjoin("", "");
	printf("%s\n", res);
	free(res);
	printf("\n");
	printf("=====STRTRIM=====\n");
	fflush(stdout);
	res = ft_strtrim("helloworld", "o");
	printf("%s\n", res);
	free(res);
	res = ft_strtrim("helloworld", "");
	printf("%s\n", res);
	free(res);
	res = ft_strtrim("helloworld", "hed");
	printf("%s\n", res);
	free(res);
	res = ft_strtrim("helloworld", "helwd");
	printf("%s\n", res);
	free(res);
	res = ft_strtrim("helloworld", "helowrd");
	printf("%s\n", res);
	free(res);
	printf("=====SPLIT=====\n");
	char **split;
	split = ft_split("hello world", ' ');
	for (int i = 0; split[i]; i++)
	{
		printf("%d, %s\n", i, split[i]);
		free(split[i]);
	}
	free(split);
	split = ft_split("  hello  world  ", ' ');
	for (int i = 0; split[i]; i++)
	{
		printf("%d, %s\n", i, split[i]);
		free(split[i]);
	}
	free(split);
	split = ft_split("    ", ' ');
	if (split[0] == NULL)
		printf("NULL\n");
	for (int i = 0; split[i]; i++)
	{
		printf("%d\n", i);
		free(split[i]);
	}
	free(split);
	printf("=====ITOA=====\n");
	res = ft_itoa(12345);
	printf("%s\n", res);
	free(res);
	res = ft_itoa(-12345);
	printf("%s\n", res);
	free(res);
	res = ft_itoa(2147483647);
	printf("%s\n", res);
	free(res);
	res = ft_itoa(-2147483648);
	printf("%s\n", res);
	free(res);
	res = ft_itoa(0);
	printf("%s\n", res);
	free(res);
	printf("=====STRMAPI=====\n");
	res = ft_strmapi("hello", &mapi_func);
	printf("%s\n", res);
	free(res);
	res = ft_strmapi("", &mapi_func);
	printf("%s\n", res);
	free(res);
	res = ft_strmapi("helloworld", mapi_func);
	printf("%s\n", res);
	free(res);
	printf("=====STRITERI=====\n");
	char *iteri;
	iteri = (char *)malloc(42);
	bzero(iteri, 42);
	strcpy(iteri, "helloworld");
	ft_striteri(iteri, &iteri_func);
	printf("%s\n", iteri);
	ft_striteri(&iteri[1], &iteri_func);
	printf("%s\n", iteri);
	printf("=====PUT_FD, STDOUT=====\n");
	fflush(stdout);
	ft_putchar_fd('*', 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("hello world!\n", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("hello world!", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(12345, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-12345, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0x7fffffff, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0x80000000, 1);
	ft_putchar_fd('\n', 1);
}

#else

void	part2_expected(void)
{
	printf("=====SUBSTR=====\n");
	printf("hello\n");
	printf("hello42!\n");
	printf("\n");
	printf("42\n");
	printf("\n");
	printf("42!\n");
	printf("=====STRJOIN=====\n");
	printf("helloworld\n");
	printf("world\n");
	printf("hello\n");
	printf("\n");
	printf("\n");
	printf("=====STRTRIM=====\n");
	printf("helloworld\n");
	printf("helloworld\n");
	printf("lloworl\n");
	printf("owor\n");
	printf("\n");
	printf("=====SPLIT=====\n");
	printf("0, hello\n");
	printf("1, world\n");
	printf("0, hello\n");
	printf("1, world\n");
	printf("NULL\n");
	printf("=====ITOA=====\n");
	printf("12345\n");
	printf("-12345\n");
	printf("2147483647\n");
	printf("-2147483648\n");
	printf("0\n");
	printf("=====STRMAPI=====\n");
	printf("HeLlO\n");
	printf("\n");
	printf("HeLlOwOrLd\n");
	printf("=====STRITERI=====\n");
	printf("HeLlOwOrLd\n");
	printf("HElLoWoRlD\n");
	printf("=====PUT_FD, STDOUT=====\n");
	printf("*");
	printf("\n");
	printf("hello world!\n");
	printf("\n");
	printf("hello world!\n");
	printf("\n");
	printf("12345");
	printf("\n");
	printf("-12345");
	printf("\n");
	printf("0");
	printf("\n");
	printf("2147483647");
	printf("\n");
	printf("-2147483648");
	printf("\n");
}

#endif