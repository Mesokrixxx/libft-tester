#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "libft.h"

# define OK "\x1B[32mOK\x1B[37m"
# define KO "\x1B[31mKO\x1B[37m"
# define SLEEPTIME 25000

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define SIGN(value) ((value < 0) ? -1 : (value > 0) ? 1 : 0)

# define ASSERT(a) printf("%s\n", a ? OK : KO); usleep(SLEEPTIME)
# define ASSERT_SIGN(a, b) printf("%s - Expected: %d Getting: %d\n", (SIGN(a) == SIGN(b)) ? OK : KO, SIGN(a), SIGN(b)); usleep(SLEEPTIME)
# define ASSERT_SIZE_T(a, b) printf("%s - Expected: %ld Getting: %ld\n", (a == b) ? OK : KO, a, b); usleep(SLEEPTIME)
# define ASSERT_INT(a, b) printf("%s - Expected: %d Getting: %d\n", (a == b) ? OK : KO, a, b); usleep(SLEEPTIME)
# define ASSERT_STRING(a, b) printf("%s - Expected: %s Getting: %s\n", ((a == NULL && b == NULL) ? 1 : (a == NULL && b != NULL) ? 0 : (a != NULL && b == NULL) ? 0 : !strcmp(a, b)) ? OK : KO, a ? a : "(null)", b ? b : "(null)"); usleep(SLEEPTIME)
# define ASSERT_CHAR(a, b) printf("%s - Expected: %c Getting: %c\n", (a == b) ? OK : KO, a, b); usleep(SLEEPTIME)
# define ASSERT_VOID(a, b, n) printf("%s\n", ((a == NULL && b == NULL) ? 1 : (a == NULL && b != NULL) ? 0 : (a != NULL && b == NULL) ? 0 : !memcmp(a, b, n)) ? OK : KO); usleep(SLEEPTIME)

int main ()
{
	printf("TESTING\n");

	printf("\n--> ISALPHA <--\n");
	ASSERT_SIGN(isalpha('A'), ft_isalpha('A'));
	ASSERT_SIGN(isalpha('z'), ft_isalpha('z'));
	ASSERT_SIGN(isalpha('0'), ft_isalpha('0'));
	ASSERT_SIGN(isalpha('9'), ft_isalpha('9'));

	printf("\n--> ISDIGIT <--\n");
	ASSERT_SIGN(isdigit('A'), ft_isdigit('A'));
	ASSERT_SIGN(isdigit('z'), ft_isdigit('z'));
	ASSERT_SIGN(isdigit('0'), ft_isdigit('0'));
	ASSERT_SIGN(isdigit('9'), ft_isdigit('9'));

	printf("\n--> ISALNUM <--\n");
	ASSERT_SIGN(isalnum('A'), ft_isalnum('A'));
	ASSERT_SIGN(isalnum('9'), ft_isalnum('9'));
	ASSERT_SIGN(isalnum('@'), ft_isalnum('@'));
	ASSERT_SIGN(isalnum('&'), ft_isalnum('&'));

	printf("\n--> ISASCII <--\n");
	ASSERT_SIGN(isalnum('A'), ft_isalnum('A'));
	ASSERT_SIGN(isalnum('9'), ft_isalnum('9'));
	ASSERT_SIGN(isalnum('@'), ft_isalnum('@'));
	ASSERT_SIGN(isalnum('&'), ft_isalnum('&'));
	ASSERT_SIGN(isalnum(800), ft_isalnum(800));
	ASSERT_SIGN(isalnum(-547), ft_isalnum(-547));

	printf("\n--> ISPRINT <--\n");
	ASSERT_SIGN(isprint('A'), ft_isprint('A'));
	ASSERT_SIGN(isprint('9'), ft_isprint('9'));
	ASSERT_SIGN(isprint('@'), ft_isprint('@'));
	ASSERT_SIGN(isprint('&'), ft_isprint('&'));
	ASSERT_SIGN(isalnum(10), ft_isalnum(10));
	ASSERT_SIGN(isalnum(9), ft_isalnum(9));

	printf("\n--> STRLEN <--\n");
	ASSERT_SIZE_T(strlen("Test"), ft_strlen("Test"));
	ASSERT_SIZE_T(strlen("fdsuihfsbjsnjfuishvcxkjsbuifhskjdnfuisdgfuihuwbfdksb"), ft_strlen("fdsuihfsbjsnjfuishvcxkjsbuifhskjdnfuisdgfuihuwbfdksb"));
	ASSERT_SIZE_T(strlen(""), ft_strlen(""));
	ASSERT_SIZE_T(strlen("\n"), ft_strlen("\n"));

	printf("\n--> MEMSET <--\n");
	char memsetTest[100] = "Ceci est un test pour memset";
	ASSERT_STRING((char *)memset((void *)memsetTest, '0', strlen(memsetTest)), (char *)ft_memset((void *)memsetTest, '0', strlen(memsetTest)));
	ASSERT_STRING((char *)memset((void *)memsetTest, '@', strlen(memsetTest)), (char *)ft_memset((void *)memsetTest, '@', strlen(memsetTest)));
	ASSERT_STRING((char *)memset((void *)memsetTest, '&', 15), (char *)ft_memset((void *)memsetTest, '0', 15));
	ASSERT_STRING((char *)memset((void *)memsetTest, '+', 10), (char *)ft_memset((void *)memsetTest, '0', 10));
	ASSERT_STRING((char *)memset((void *)memsetTest, '*', 5), (char *)ft_memset((void *)memsetTest, '0', 5));
	ASSERT_STRING((char *)memset((void *)memsetTest, '9', 0), (char *)ft_memset((void *)memsetTest, '0', 0));
	ASSERT_STRING((char *)memset((void *)memsetTest, '\0', 1), (char *)ft_memset((void *)memsetTest, '0', 1));

	printf("\n--> BZERO <--\n");
	char testBZERO[50];
	char test2BZERO[50];
	bzero(testBZERO, 0); ft_bzero(test2BZERO, 0);
	ASSERT(memcmp(testBZERO, test2BZERO, 50));
	bzero(testBZERO, 5); ft_bzero(test2BZERO, 5);
	ASSERT(memcmp(testBZERO, test2BZERO, 50));
	bzero(testBZERO, 25); ft_bzero(test2BZERO, 25);
	ASSERT(memcmp(testBZERO, test2BZERO, 50));
	bzero(testBZERO, 48); ft_bzero(test2BZERO, 48);
	ASSERT(memcmp(testBZERO, test2BZERO, 50));

	printf("\n--> MEMCPY <--\n");
	char dstMEMCPY[100];
	char srcMEMCPY[100] = "JE SUIS LE TEST";
	ASSERT_VOID(memcpy(dstMEMCPY, srcMEMCPY, strlen(srcMEMCPY)), ft_memcpy(dstMEMCPY, srcMEMCPY, strlen(srcMEMCPY)), strlen(srcMEMCPY));
	ASSERT_VOID(memcpy(dstMEMCPY, srcMEMCPY, strlen(srcMEMCPY) / 2), ft_memcpy(dstMEMCPY, srcMEMCPY, strlen(srcMEMCPY) / 2), strlen(srcMEMCPY) / 2);
	ASSERT_VOID(memcpy(dstMEMCPY, srcMEMCPY, 0), ft_memcpy(dstMEMCPY, srcMEMCPY, 0), 0);
	ASSERT_VOID(memcpy(dstMEMCPY, srcMEMCPY, 1), ft_memcpy(dstMEMCPY, srcMEMCPY, 1), 1);
	ASSERT_VOID(memcpy(dstMEMCPY, srcMEMCPY, 50), ft_memcpy(dstMEMCPY, srcMEMCPY, 50), 50);
	ASSERT_VOID(memcpy(dstMEMCPY, srcMEMCPY, 300), ft_memcpy(dstMEMCPY, srcMEMCPY, 300), 300);


	printf("\n--> MEMMOVE <--\n");

	printf("\n--> STRLCPY <--\n");
	char destSTRLCPY[100]; "";
	char destSTRLCPY2[100]; "";
	char srcSTRLCPY[100] = "Je suis la";
	ASSERT_SIZE_T(strlcpy(destSTRLCPY, srcSTRLCPY, strlen(srcSTRLCPY) + 1), ft_strlcpy(destSTRLCPY2, srcSTRLCPY, strlen(srcSTRLCPY) + 1));
	ASSERT_SIZE_T(strlcpy(destSTRLCPY, srcSTRLCPY, strlen(srcSTRLCPY) / 2), ft_strlcpy(destSTRLCPY2, srcSTRLCPY, strlen(srcSTRLCPY) / 2));
	ASSERT_SIZE_T(strlcpy(destSTRLCPY, srcSTRLCPY, 1), ft_strlcpy(destSTRLCPY2, srcSTRLCPY, 1));
	ASSERT_SIZE_T(strlcpy(destSTRLCPY, srcSTRLCPY, 0), ft_strlcpy(destSTRLCPY2, srcSTRLCPY, 0));

	printf("\n--> STRLCAT <--\n");
	char destSTRLCAT[100]; "Je";
	char destSTRLCAT2[100]; "Je";
	char srcSTRLCAT[100] = " suis la";
	ASSERT_SIZE_T(strlcat(destSTRLCAT, srcSTRLCAT, strlen(srcSTRLCAT) + 1), ft_strlcat(destSTRLCAT2, srcSTRLCAT, strlen(srcSTRLCAT) + 1));
	ASSERT_SIZE_T(strlcat(destSTRLCAT, srcSTRLCAT, strlen(srcSTRLCAT) / 2), ft_strlcat(destSTRLCAT2, srcSTRLCAT, strlen(srcSTRLCAT) / 2));
	ASSERT_SIZE_T(strlcat(destSTRLCAT, srcSTRLCAT, strlen(destSTRLCAT)), ft_strlcat(destSTRLCAT2, srcSTRLCAT, strlen(destSTRLCAT2)));
	ASSERT_SIZE_T(strlcat(destSTRLCAT, srcSTRLCAT, strlen(destSTRLCAT) / 2), ft_strlcat(destSTRLCAT2, srcSTRLCAT, strlen(destSTRLCAT2) / 2));
	ASSERT_SIZE_T(strlcat(destSTRLCAT, srcSTRLCAT, 0), ft_strlcat(destSTRLCAT2, srcSTRLCAT, 0));

	printf("\n--> TOUPPER <--\n");
	ASSERT_CHAR(toupper('c'), ft_toupper('c'));
	ASSERT_CHAR(toupper('C'), ft_toupper('C'));
	ASSERT_CHAR(toupper('0'), ft_toupper('0'));
	ASSERT_CHAR(toupper('@'), ft_toupper('@'));

	printf("\n--> TOLOWER <--\n");
	ASSERT_CHAR(tolower('c'), ft_tolower('c'));
	ASSERT_CHAR(tolower('C'), ft_tolower('C'));
	ASSERT_CHAR(tolower('0'), ft_tolower('0'));
	ASSERT_CHAR(tolower('@'), ft_tolower('@'));

	printf("\n--> STRCHR <--\n");
	ASSERT_STRING(strchr("Test", 'e'), ft_strchr("Test", 'e'));
	ASSERT_STRING(strchr("Test", '0'), ft_strchr("Test", '0'));
	ASSERT_STRING(strchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 'k'), ft_strchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 'k'));
	ASSERT_STRING(strchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 0), ft_strchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 0));

	printf("\n--> STRRCHR <--\n");
	ASSERT_STRING(strrchr("Test", 'e'), ft_strrchr("Test", 'e'));
	ASSERT_STRING(strrchr("Test", '0'), ft_strrchr("Test", '0'));
	ASSERT_STRING(strrchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 'k'), ft_strrchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 'k'));
	ASSERT_STRING(strrchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 'l'), ft_strrchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 'l'));
	ASSERT_STRING(strrchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 0), ft_strrchr("Longasstestidkwhatimwritingbutmaybeullknowhehe", 0));

	printf("\n--> STRNCMP <--\n");
	ASSERT_SIGN(strncmp("Hello", "Hello", 5), ft_strncmp("Hello", "Hello", 5));
	ASSERT_SIGN(strncmp("Hello5", "Hello", 5), ft_strncmp("Hello5", "Hello", 5));
	ASSERT_SIGN(strncmp("hello5", "Hello", 5), ft_strncmp("hello5", "Hello", 5));
	ASSERT_SIGN(strncmp("Hello5", "hello", 5), ft_strncmp("Hello5", "hello", 5));
	ASSERT_SIGN(strncmp("Hello5", "hello", 10), ft_strncmp("Hello5", "hello", 10));
	ASSERT_SIGN(strncmp("Hello5", "hello", 0), ft_strncmp("Hello5", "hello", 0));
	ASSERT_SIGN(strncmp("Hello5", "", 6), ft_strncmp("Hello5", "", 6));
	ASSERT_SIGN(strncmp("", "", 6), ft_strncmp("", "", 6));
	ASSERT_SIGN(strncmp("", "Hello5", 6), ft_strncmp("", "Hello5", 6));

	printf("\n--> MEMCHR <--\n");
	char *testMEMCHR = "Ceci est un test donc stp marche mon frr";
	ASSERT_VOID(memchr((void *)testMEMCHR, 'i', strlen(testMEMCHR) + 1), ft_memchr((void *)testMEMCHR, 'i', strlen(testMEMCHR) + 1), strlen(testMEMCHR) + 1);
	ASSERT_VOID(memchr((void *)testMEMCHR, 'i', 0), ft_memchr((void *)testMEMCHR, 'i', 0), 0);
	ASSERT_VOID(memchr((void *)testMEMCHR, 'r', 5), ft_memchr((void *)testMEMCHR, 'r', 5), 5);
	ASSERT_VOID(memchr((void *)testMEMCHR, '0', strlen(testMEMCHR) + 1), ft_memchr((void *)testMEMCHR, '0', strlen(testMEMCHR) + 1), strlen(testMEMCHR) + 1);
	ASSERT_VOID(memchr((void *)testMEMCHR, 0, strlen(testMEMCHR) + 1), ft_memchr((void *)testMEMCHR, 0, strlen(testMEMCHR) + 1), strlen(testMEMCHR) + 1);

	printf("\n--> MEMCMP <--\n");
	char *test1MEMCMP = "Test1";
	char *test2MEMCMP = "Test2";
	ASSERT_SIGN(memcmp(test1MEMCMP, test2MEMCMP, 4), ft_memcmp(test1MEMCMP, test2MEMCMP, 4));
	ASSERT_SIGN(memcmp(test1MEMCMP, test2MEMCMP, 0), ft_memcmp(test1MEMCMP, test2MEMCMP, 0));
	ASSERT_SIGN(memcmp(test1MEMCMP, test2MEMCMP, 10), ft_memcmp(test1MEMCMP, test2MEMCMP, 10));
	ASSERT_SIGN(memcmp(test1MEMCMP, test2MEMCMP, strlen(test1MEMCMP)), ft_memcmp(test1MEMCMP, test2MEMCMP, strlen(test1MEMCMP)));
	ASSERT_SIGN(memcmp(test2MEMCMP, test1MEMCMP, strlen(test1MEMCMP)), ft_memcmp(test2MEMCMP, test1MEMCMP, strlen(test1MEMCMP)));

	printf("\n--> STRNSTR <--\n");
	ASSERT_STRING(strnstr("Bonjour je suis un gros test", "je", 30), ft_strnstr("Bonjour je suis un gros test", "je", 30));
	ASSERT_STRING(strnstr("Bonjour je suis un gros test", "jours", 30), ft_strnstr("Bonjour je suis un gros test", "jours", 30));
	ASSERT_STRING(strnstr("Bonjour je suis un gros test", "", 30), ft_strnstr("Bonjour je suis un gros test", "", 30));
	ASSERT_STRING(strnstr("Bonjour je suis un gros test", "i", 30), ft_strnstr("Bonjour je suis un gros test", "i", 30));
	ASSERT_STRING(strnstr("Bonjour je suis un gros test", "je", 5), ft_strnstr("Bonjour je suis un gros test", "je", 5));
	ASSERT_STRING(strnstr("Bonjour je suis un gros test", "je", 0), ft_strnstr("Bonjour je suis un gros test", "je", 0));

	printf("\n--> ATOI <--\n");
	ASSERT_INT(atoi("abc"), ft_atoi("abc"));
	ASSERT_INT(atoi("-5abc"), ft_atoi("-5abc"));
	ASSERT_INT(atoi("-j5abc"), ft_atoi("-j5abc"));
	ASSERT_INT(atoi("--5"), ft_atoi("--5"));
	ASSERT_INT(atoi("+5"), ft_atoi("+5"));
	ASSERT_INT(atoi("++5"), ft_atoi("++5"));
	ASSERT_INT(atoi("0"), ft_atoi("0"));
	ASSERT_INT(atoi("05"), ft_atoi("05"));
	ASSERT_INT(atoi("-05"), ft_atoi("-05"));
	ASSERT_INT(atoi("0000000"), ft_atoi("0000000"));
	ASSERT_INT(atoi("-0000000"), ft_atoi("-0000000"));
	ASSERT_INT(atoi("2147483647"), ft_atoi("2147483647"));
	ASSERT_INT(atoi("-2147483648"), ft_atoi("-2147483648"));

	printf("\n--> FT_SUBSTR <--\n");


	printf("\n--> FT_STRTRIM <--\n");


	printf("\n--> FT_SPLIT <--\n");


	printf("\n--> FT_ITOA <--\n");
	ASSERT_STRING("2147483647", ft_itoa(MAX_INT));
	ASSERT_STRING("2100000000", ft_itoa(2100000000));
	ASSERT_STRING("-2147483648", ft_itoa(MIN_INT));
	ASSERT_STRING("-2100000000", ft_itoa(-2100000000));
	ASSERT_STRING("0", ft_itoa(0));
	ASSERT_STRING("-42", ft_itoa(-42));
	ASSERT_STRING("42", ft_itoa(42));

	printf("\n--> FT_STRMAPI <--\n");


	printf("\n--> FT_STITERI <--\n");


	printf("\n--> FT_PUTCHAR_FD <--\n");


	printf("\n--> FT_PUTSTR_FD <--\n");


	printf("\n--> FT_PUTENDL_FD <--\n");


	printf("\n--> FT_PUTNBR_FD <--\n");

	printf("\nDONE\n");
}