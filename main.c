#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "libft.h"

// struct TestStruct {
//     long	num;
// 	char	c;
//     char	*str;
//     bool	true_or_false;
// };

void print_with_nulls(const char *buf, size_t total_size)
{
	for (size_t i = 0; i < total_size; i++)
	{
		if (buf[i] == '\0')
		{
			printf("\\0");
		}
		else
		{
			printf("%c", buf[i]);
		}
	}
	printf("\n");
}

void	test_strlen(size_t (*testfunc)(const char*))
{
	char str1[]= "hello, how are you doing? 42words forty-two; fifty+and+one";
	char str2[] = "T";
	char str3[] = "*Numbers8should*be_chec83839ked 376829N";
	char str4[] = "";

	// printf("Our string is: %s\n", str1);
	// printf("Its length should be %zu, and this function tells me it is: %zu\n\n", strlen(str1), testfunc(str1));
	assert(testfunc(str1) == strlen(str1));

	// printf("Our string is: %s\n", str2);
	// printf("Its length should be %zu, and this function tells me it is: %zu\n\n", strlen(str2), testfunc(str2));
	assert(testfunc(str2) == strlen(str2));

	// printf("Our string is: %s\n", str3);
	// printf("Its length should be %zu, and this function tells me it is: %zu\n\n", strlen(str3), testfunc(str3));
	assert(testfunc(str3) == strlen(str3));

	// printf("Our string is: %s\n", str4);
	// printf("Its length should be %zu, and this function tells me it is: %zu\n", strlen(str4), testfunc(str4));
	assert(testfunc(str4) == strlen(str4));
}

void	test_memset(void *(*testfunc)(void *, int, size_t))
{
	int num;
	int ft_num;
	int *int_ptr;
	int *ft_int_ptr;
	char *string;
	char *ft_string;
	unsigned char *unsigned_string;
	unsigned char *unsigned_string_copy;
	char buffer[64];
	char ft_buffer[64];
 
	num = 12;
	ft_num = 2389348839;
	string = strdup("Hello, how are you doing?");
	ft_string = strdup("Hello, how are you doing?");
	unsigned_string = (unsigned char *)strdup("Goodbye, I don't want to see you again!");

	memset(&num, 0, sizeof(num));
	testfunc(&ft_num, 0, sizeof(num));
	assert(memcmp(&num, &ft_num, sizeof(num)) == 0);

	num = 12;
	ft_num = 2389348839;

	int_ptr = &num;
	ft_int_ptr = &ft_num;

	memset(int_ptr, 0, sizeof(*int_ptr));
	testfunc(ft_int_ptr, 0, sizeof(*ft_int_ptr));
	assert(memcmp(int_ptr, ft_int_ptr, sizeof(*int_ptr)) == 0);

	memset(string, 33, 8);
	testfunc(ft_string, 33, 8);
	// printf("%s\n", string);
	// printf("%s\n", ft_string);
	assert(memcmp(string, ft_string, strlen(string)) == 0);

	memset(unsigned_string, 33, 13);
	unsigned_string_copy = (unsigned char *)strdup((char *)unsigned_string);
	testfunc(unsigned_string, 55, 0);
	// printf("%s\n", unsigned_string);
	// printf("%s\n", unsigned_string_copy);
	assert(memcmp(unsigned_string, unsigned_string_copy, strlen((char *)unsigned_string)) == 0);

	memset(buffer, 313, sizeof(buffer));
	testfunc(ft_buffer, 313, sizeof(buffer));
	// printf("%c %c\n%c %c\n%c %c\n", buffer[0], ft_buffer[0], buffer[1], ft_buffer[1], buffer[2], ft_buffer[2]);
	assert(memcmp(buffer, ft_buffer, sizeof(buffer)) == 0);
	free(string);
	free(ft_string);
	free(unsigned_string);
	free(unsigned_string_copy);
}

void	test_bzero(void *(*testfunc)(void *, size_t))
{
	// size_t ite;
	int num;
	int ft_num;
	int *int_ptr;
	int *ft_int_ptr;
	char *string;
	char *ft_string;
	unsigned char *unsigned_string;
	unsigned char *unsigned_string_copy;
 
	num = 12;
	ft_num = 2389348839;
	string = strdup("Hello, how are you doing?");
	ft_string = strdup("Hello, how are you doing?");
	unsigned_string = (unsigned char *)strdup("Goodbye, I don't want to see you again!");
	unsigned_string_copy = (unsigned char *)strdup((char *)unsigned_string);

	bzero(&num, sizeof(num));
	testfunc(&ft_num, sizeof(num));
	assert(memcmp(&num, &ft_num, sizeof(num)) == 0);

	num = 12;
	ft_num = 2389348839;

	int_ptr = &num;
	ft_int_ptr = &ft_num;

	bzero(int_ptr, sizeof(*int_ptr));
	testfunc(ft_int_ptr, sizeof(*ft_int_ptr));
	assert(memcmp(int_ptr, ft_int_ptr, sizeof(*int_ptr)) == 0);

	bzero(string, 8);
	testfunc(ft_string, 8);
	// for (ite = 0; ite < 8; ite++)
	// 	printf("%d", string[ite]);
	// for (ite = 8; ite < strlen("Hello, how are you doing?"); ite++)
	// 	printf("%c", string[ite]);
	// printf("\n");
	// for (ite = 0; ite < 8; ite++)
	// 	printf("%d", ft_string[ite]);
	// for (ite = 8; ite < strlen("Hello, how are you doing?"); ite++)
	// 	printf("%c", ft_string[ite]);
	// printf("\n");
	assert(memcmp(string, ft_string, strlen("Hello, how are you doing?")) == 0);

	bzero(unsigned_string, 13);
	bzero(unsigned_string_copy, 13);
	testfunc(unsigned_string_copy, 0);
	// for (ite = 0; ite < 13; ite++)
	// 	printf("%d", unsigned_string[ite]);
	// for (ite = 13; ite < strlen("Goodbye, I don't want to see you again!"); ite++)
	// 	printf("%c", unsigned_string[ite]);
	// printf("\n");
	// for (ite = 0; ite < 13; ite++)
	// 	printf("%d", unsigned_string_copy[ite]);
	// for (ite = 13; ite < strlen("Goodbye, I don't want to see you again!"); ite++)
	// 	printf("%c", unsigned_string_copy[ite]);
	// printf("\n");
	assert(memcmp(unsigned_string, unsigned_string_copy, strlen("Goodbye, I don't want to see you again!")) == 0);
	free(string);
	free(ft_string);
	free(unsigned_string);
	free(unsigned_string_copy);
}

void	test_memcpy(void *(*testfunc)(void *restrict, const void *restrict, size_t))
{
	unsigned char src[64];
	/*Here, I am making the destination buffer 16 bytes bigger than it needs to be,
	because those extra bytes will help me check if my function doesn't accidentally writes too far in memory*/
	unsigned char extended_dest[8 + 64 + 8];
	/*My destination I will write therefore needs to start 8 bytes after the "guard clauses"*/
	unsigned char *dest = extended_dest + 8;
	unsigned char expected[64];
	void *returned_ptr;
	int ite;

	/*Putting a bunch of "random" bits in my source, because random stuff is notable, and I can compare it*/
	for (ite = 0; ite < 64; ite++)
	{
		src[ite] = (unsigned char)(ite * 7);
	}
	/*using the real memcpy to have a thing to test against*/
	memcpy(expected, src, 64);

	/*Filling the whole destination with bits set to 1*/
	memset(extended_dest, -1, sizeof(extended_dest));

	/*Actually doing the thing*/
	returned_ptr = testfunc(dest, src, 64);

	/* Just checking I returned the actual destination pointer*/
	assert(returned_ptr == dest);

	/* Now for the true test, the data should be correct*/
	// for (ite = 0; ite < 64; ite++)
		// printf("expected: %hhd, dest: %hhd\n", expected[ite], dest[ite]);
	assert(memcmp(expected, dest, 64) == 0);

	/*Here I'm making use of my larger extended_dest to check that nothing was written
	before or after the amount of stated amount of bytes */
	for (ite = 0; ite < 8; ite++)
	{
		// printf("front: %hhd\n", extended_dest[ite]);
		// printf("back: %hhd\n", extended_dest[8 + 64 + ite]);
		assert((char)extended_dest[ite] == -1);
		assert((char)extended_dest[8 + 64 + ite] == -1);
	}

	/*Finally, just making sure my source wasn't modified*/
	assert(memcmp(src, expected, 64) == 0);

	/* Nevermind, I should test this so I don't forget to make sure I actually cast to unsigned char*/
	int test_int_src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int test_int_dest[10];
	int test_int_expected[10];

	// for (ite = 0; ite < 10; ite++)
		// printf("src: %hhd\n", test_int_src[ite]);

	// printf("%zu\n",sizeof(test_int_expected));
	memset(test_int_dest, -1, sizeof(test_int_dest));
	memset(test_int_expected, -1, sizeof(test_int_expected));
	// for (ite = 0; ite < 10; ite++)
		// printf("expected: %hhd, dest: %hhd\n", test_int_expected[ite], test_int_dest[ite]);

	memcpy(test_int_expected, test_int_src, sizeof(test_int_expected));
	testfunc(test_int_dest, test_int_src, sizeof(test_int_expected));
	// for (ite = 0; ite < 10; ite++)
		// printf("expected: %hhd, dest: %hhd\n", test_int_expected[ite], test_int_dest[ite]);

	assert(memcmp(test_int_expected, test_int_dest, sizeof(test_int_expected)) == 0);

	/* Okay well, I should also test for if the memory area overlap,
	because that's the only difference between memcpy and memmove*/

	// char overlapping_buffer[] = "abcdefghijklmnopqrstuvwxyz";
	// testfunc(overlapping_buffer + 6, overlapping_buffer + 6, 8);
	// for (ite = 0; ite < 26; ite++)
	// 	printf("%c", overlapping_buffer[ite]);
	// printf("\n");

}

void	test_memmove(void *(*testfunc)(void *, const void *, size_t))
{
	unsigned char src[64];
	/*Here, I am making the destination buffer 16 bytes bigger than it needs to be,
	because those extra bytes will help me check if my function doesn't accidentally writes too far in memory*/
	unsigned char extended_dest[8 + 64 + 8];
	/*My destination I will write therefore needs to start 8 bytes after the "guard clauses"*/
	unsigned char *dest = extended_dest + 8;
	unsigned char expected[64];
	void *returned_ptr;
	int ite;

	/*Putting a bunch of "random" bits in my source, because random stuff is notable, and I can compare it*/
	for (ite = 0; ite < 64; ite++)
	{
		src[ite] = (unsigned char)(ite * 7);
	}
	/*using the real memmove to have a thing to test against*/
	memmove(expected, src, 64);

	/*Filling the whole destination with bits set to 1*/
	memset(extended_dest, -1, sizeof(extended_dest));

	/*Actually doing the thing*/
	returned_ptr = testfunc(dest, src, 64);

	/* Just checking I returned the actual destination pointer*/
	assert(returned_ptr == dest);

	/* Now for the true test, the data should be correct*/
	// for (ite = 0; ite < 64; ite++)
		// printf("expected: %hhd, dest: %hhd\n", expected[ite], dest[ite]);
	assert(memcmp(expected, dest, 64) == 0);

	/*Here I'm making use of my larger extended_dest to check that nothing was written
	before or after the amount of stated amount of bytes */
	for (ite = 0; ite < 8; ite++)
	{
		// printf("front: %hhd\n", extended_dest[ite]);
		// printf("back: %hhd\n", extended_dest[8 + 64 + ite]);
		assert((char)extended_dest[ite] == -1);
		assert((char)extended_dest[8 + 64 + ite] == -1);
	}

	/*Finally, just making sure my source wasn't modified*/
	assert(memcmp(src, expected, 64) == 0);

	/* Nevermind, I should test this so I don't forget to make sure I actually cast to unsigned char*/
	int test_int_src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int test_int_dest[10];
	int test_int_expected[10];

	// for (ite = 0; ite < 10; ite++)
		// printf("src: %hhd\n", test_int_src[ite]);

	// printf("%zu\n",sizeof(test_int_expected));
	memset(test_int_dest, -1, sizeof(test_int_dest));
	memset(test_int_expected, -1, sizeof(test_int_expected));
	// for (ite = 0; ite < 10; ite++)
		// printf("expected: %hhd, dest: %hhd\n", test_int_expected[ite], test_int_dest[ite]);

	memmove(test_int_expected, test_int_src, sizeof(test_int_expected));
	testfunc(test_int_dest, test_int_src, sizeof(test_int_expected));
	// for (ite = 0; ite < 10; ite++)
		// printf("expected: %hhd, dest: %hhd\n", test_int_expected[ite], test_int_dest[ite]);

	assert(memcmp(test_int_expected, test_int_dest, sizeof(test_int_expected)) == 0);

	/* Okay well, I should also test for if the memory area overlap,
	because that's the only difference between memcpy and memmove*/

	// char overlapping_buffer[] = "abcdefghijklmnopqrstuvwxyz";
	// testfunc(overlapping_buffer + 6, overlapping_buffer + 6, 8);
	// for (ite = 0; ite < 26; ite++)
	// 	printf("%c", overlapping_buffer[ite]);
	// printf("\n");
}

void	test_strlcpy(size_t (*testfunc)(char*, const char*, size_t))
{
	size_t returned_value;
	size_t ft_returned_value;
	char source[] = "abcdefghijklmnopqrstuvwxyzhhhhh";
	char source2[] = "abcdefghijklmnopqrstuvwxyzhhhhh";
    char destination[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ft_destination[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *buffer_dest = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source = strdup("abcdefghijklmnopqrstuvwxyzhhhhh");
	char *buffer_dest2 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source2 = strdup("abcdefghijklmnopqrstuvwxyzhhhhh");
	char *buffer_dest3 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source3 = strdup("abcdef");
	char *buffer_dest4 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source4 = strdup("abcdef");
	char *buffer_dest5 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source5 = strdup("123456789");
	char *buffer_dest6 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source6 = strdup("123456789");
	char *buffer_dest7 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source7 = strdup("123456789");
	char *buffer_dest8 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source8 = strdup("123456789");
	char *buffer_dest9 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source9 = strdup("abcdef");
	char *buffer_dest10 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source10 = strdup("abcdef");
	char *buffer_dest11 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source11 = strdup("");
	char *buffer_dest12 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source12 = strdup("");
	char *buffer_dest13 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source13 = strdup("");
	char *buffer_dest14 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source14 = strdup("");
	char *malloced_destination;
	char *ft_malloced_destination;

	malloced_destination = malloc(40);
	ft_malloced_destination = malloc(40);

	printf("Testing without memory allocation;\n");

    testfunc(ft_destination, source, 24);
	strlcpy(destination, source, 24);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: (24 bytes) %s\n", ft_destination);
	printf("Destination string with the real strlcpy: (24 bytes) %s\n", destination);
	assert(strcmp(ft_destination, destination) == 0);

	printf("\nTesting with memory allocation;\n");

    testfunc(ft_malloced_destination, source, 24);
	strlcpy(malloced_destination, source, 24);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: (24 bytes) %s\n", ft_malloced_destination);
	printf("Destination string with the real strlcpy: (24 bytes) %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	printf("\nTesting overwritting string;\n");

    testfunc(ft_malloced_destination, source2, 14);
	strlcpy(malloced_destination, source2, 14);
	printf("Second source string: %s\n", source2);
    printf("Destination string with our function: (14 bytes) %s\n", ft_malloced_destination);
	printf("Destination string with the real strlcpy: (14 bytes) %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	returned_value = strlcpy(buffer_dest, buffer_source, sizeof(buffer_dest));
	// print_with_nulls(buffer_dest, 32);
	// printf("%zu\n", returned_value);
	ft_returned_value = ft_strlcpy(buffer_dest2, buffer_source2, sizeof(buffer_dest2));
	// print_with_nulls(buffer_dest2, 32);
	// printf("%zu\n", returned_value);

	assert(memcmp(buffer_dest, buffer_dest2, sizeof(*buffer_dest)) == 0);
	assert(returned_value == ft_returned_value);

	returned_value = strlcpy(buffer_dest4, buffer_source4, sizeof(buffer_dest4));
	// print_with_nulls(buffer_dest4, 32);
	// printf("%zu\n", returned_value);
	ft_returned_value = ft_strlcpy(buffer_dest3, buffer_source3, sizeof(buffer_dest3));
	// print_with_nulls(buffer_dest3, 32);
	// printf("%zu\n", returned_value);

	assert(memcmp(buffer_dest4, buffer_dest3, sizeof(*buffer_dest4)) == 0);
	assert(returned_value == ft_returned_value);


	returned_value = strlcpy(buffer_dest5, buffer_source5, strlen(buffer_source5) + 1);
	// print_with_nulls(buffer_dest5, 32);
	// printf("%zu\n", returned_value);

	ft_returned_value = ft_strlcpy(buffer_dest6, buffer_source6, strlen(buffer_source6) + 1);
	// print_with_nulls(buffer_dest6, 32);
	// printf("%zu\n", returned_value);

	assert(memcmp(buffer_dest4, buffer_dest3, sizeof(*buffer_dest4)) == 0);
	assert(returned_value == ft_returned_value);

	returned_value = strlcpy(buffer_dest7, buffer_source7, strlen(buffer_source7));
	// print_with_nulls(buffer_dest7, 32);
	// printf("%zu\n", returned_value);

	ft_returned_value = ft_strlcpy(buffer_dest8, buffer_source8, strlen(buffer_source8));
	// print_with_nulls(buffer_dest8, 32);
	// printf("%zu\n", returned_value);

	assert(memcmp(buffer_dest4, buffer_dest3, sizeof(*buffer_dest4)) == 0);
	assert(returned_value == ft_returned_value);

	returned_value = strlcpy(buffer_dest9, buffer_source9, 0);
	// print_with_nulls(buffer_dest9, 32);
	// printf("%zu\n", returned_value);

	ft_returned_value = ft_strlcpy(buffer_dest10, buffer_source10, 0);
	// print_with_nulls(buffer_dest10, 32);
	// printf("%zu\n", returned_value);

	assert(memcmp(buffer_dest4, buffer_dest3, sizeof(*buffer_dest4)) == 0);
	assert(returned_value == ft_returned_value);

	returned_value = strlcpy(buffer_dest9, buffer_source9, 1);
	// print_with_nulls(buffer_dest9, 32);
	// printf("%zu\n", returned_value);

	ft_returned_value = ft_strlcpy(buffer_dest10, buffer_source10, 1);
	// print_with_nulls(buffer_dest10, 32);
	// printf("%zu\n", returned_value);

	assert(memcmp(buffer_dest4, buffer_dest3, sizeof(*buffer_dest4)) == 0);
	assert(returned_value == ft_returned_value);

	returned_value = strlcpy(buffer_dest11, buffer_source11, 0);
	// print_with_nulls(buffer_dest11, 32);
	// printf("%zu\n", returned_value);

	ft_returned_value = ft_strlcpy(buffer_dest12, buffer_source12, 0);
	// print_with_nulls(buffer_dest12, 32);
	// printf("%zu\n", returned_value);

	assert(memcmp(buffer_dest4, buffer_dest3, sizeof(*buffer_dest4)) == 0);
	assert(returned_value == ft_returned_value);

	returned_value = strlcpy(buffer_dest11, buffer_source11, 1);
	// print_with_nulls(buffer_dest11, 32);
	// printf("%zu\n", returned_value);

	ft_returned_value = ft_strlcpy(buffer_dest12, buffer_source12, 1);
	// print_with_nulls(buffer_dest12, 32);
	// printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest13, buffer_source13, 10);
	// print_with_nulls(buffer_dest13, 32);
	// printf("%zu\n", returned_value);

	ft_returned_value = ft_strlcpy(buffer_dest14, buffer_source14, 10);
	// print_with_nulls(buffer_dest14, 32);
	// printf("%zu\n", returned_value);

	// returned_value = strlcpy(buffer_dest14, NULL, 0);
	// print_with_nulls(NULL, 32);
	// printf("%zu\n", returned_value);

	// ft_returned_value = ft_strlcpy(NULL, buffer_source14, 0);
	// print_with_nulls(NULL, 32);
	// printf("%zu\n", returned_value);

	free(malloced_destination);
	free(ft_malloced_destination);
}

int	main(void)
{
	printf("Testing ft_isalpha:\n");
	assert((bool)ft_isalpha('a') == (bool)isalpha('a'));
	assert((bool)ft_isalpha('A') == (bool)isalpha('A'));
	assert((bool)ft_isalpha('0') == (bool)isalpha('0'));
	assert((bool)ft_isalpha(')') == (bool)isalpha(')'));
	printf("...\nTests ft_isalpha passed!\n\n\n");

	printf("Testing ft_isdigit:\n");
	assert((bool)ft_isdigit('a') == (bool)isdigit('a'));
	assert((bool)ft_isdigit('A') == (bool)isdigit('A'));
	assert((bool)ft_isdigit('0') == (bool)isdigit('0'));
	assert((bool)ft_isdigit(')') == (bool)isdigit(')'));
	printf("...\nTests ft_isdigit passed!\n\n\n");\

	printf("Testing ft_isalnum:\n");
	assert((bool)ft_isalnum('a') == (bool)isalnum('a'));
	assert((bool)ft_isalnum('A') == (bool)isalnum('A'));
	assert((bool)ft_isalnum('0') == (bool)isalnum('0'));
	assert((bool)ft_isalnum(')') == (bool)isalnum(')'));
	printf("...\nTests ft_isalnum passed!\n\n\n");

	printf("Testing ft_isascii:\n");
	assert((bool)ft_isascii('a') == (bool)isascii('a'));
	assert((bool)ft_isascii('A') == (bool)isascii('A'));
	assert((bool)ft_isascii('0') == (bool)isascii('0'));
	assert((bool)ft_isascii(')') == (bool)isascii(')'));
	assert((bool)ft_isascii(256) == (bool)isascii(256));
	assert((bool)ft_isascii(-1) == (bool)isascii(-1));
	assert((bool)ft_isascii(127) == (bool)isascii(127));
	assert((bool)ft_isascii(128) == (bool)isascii(128));
	printf("...\nTests ft_isascii passed!\n\n\n");

	printf("Testing ft_isprint:\n");
	assert((bool)ft_isprint('a') == (bool)isprint('a'));
	assert((bool)ft_isprint('A') == (bool)isprint('A'));
	assert((bool)ft_isprint('0') == (bool)isprint('0'));
	assert((bool)ft_isprint(')') == (bool)isprint(')'));
	assert((bool)ft_isprint(13) == (bool)isprint(13));
	assert((bool)ft_isprint(31) == (bool)isprint(31));
	assert((bool)ft_isprint(32) == (bool)isprint(32));
	assert((bool)ft_isprint(256) == (bool)isprint(256));
	assert((bool)ft_isprint(-1) == (bool)isprint(-1));
	assert((bool)ft_isprint(127) == (bool)isprint(127));
	assert((bool)ft_isprint(128) == (bool)isprint(128));
	printf("...\nTests ft_isprint passed!\n\n\n");

	// printf("...\n%ld\n\n", sizeof(size_t));

	printf("Testing ft_strlen:\n");
	test_strlen(ft_strlen);
	printf("...\nTests ft_strlen passed!\n\n\n");

	printf("Testing ft_memset:\n");
	test_memset(ft_memset);
	printf("...\nTests ft_memset passed!\n\n\n");

	printf("Testing ft_bzero:\n");
	test_bzero(ft_bzero);
	printf("...\nTests ft_bzero passed!\n\n\n");

	printf("Testing ft_memcpy:\n");
	test_memcpy(ft_memcpy);
	/* I have to test this here because my compiler is not taking into account
	my declaration of the restrict keyword when I pass ft_memcpy as a function pointer,
	changing its behavior */

	// char overlapping_buffer[] = "abcdefghijklmnopqrstuvwxyz";
	// ft_memcpy(overlapping_buffer + 8, overlapping_buffer + 8, 8);
	// for (int ite = 0; ite < 26; ite++)
	// 	printf("%c", overlapping_buffer[ite]);
	// printf("\n");
	printf("...\nTests ft_memcpy passed!\n\n\n");

	printf("Testing ft_memmove:\n");
	test_memmove(ft_memmove);
	printf("...\nTests ft_memmove passed!\n\n\n");

	printf("Testing ft_strlcpy:\n");
	test_strlcpy(ft_strlcpy);
	printf("...\nTests ft_strlcpy passed!\n\n\n");


	// char buffer_dest[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// char buffer_source[6] = "abcde";
	// char buffer_dest2[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// char buffer_source2[6] = "abcde";
	char *buffer_dest = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source = strdup("abcdefghijklmnopqrstuvwxyzhhhhh");
	char *buffer_dest2 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source2 = strdup("abcdefghijklmnopqrstuvwxyzhhhhh");
	char *buffer_dest3 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source3 = strdup("abcdef");
	char *buffer_dest4 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source4 = strdup("abcdef");
	char *buffer_dest5 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source5 = strdup("123456789");
	char *buffer_dest6 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source6 = strdup("123456789");
	char *buffer_dest7 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source7 = strdup("123456789");
	char *buffer_dest8 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source8 = strdup("123456789");
	char *buffer_dest9 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source9 = strdup("abcdef");
	char *buffer_dest10 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source10 = strdup("abcdef");
	char *buffer_dest11 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source11 = strdup("");
	char *buffer_dest12 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source12 = strdup("");
	char *buffer_dest13 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source13 = strdup("");
	char *buffer_dest14 = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	char *buffer_source14 = strdup("");

	size_t returned_value;
 
	returned_value = strlcpy(buffer_dest, buffer_source, sizeof(buffer_dest));
	print_with_nulls(buffer_dest, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest2, buffer_source2, sizeof(buffer_dest2));
	print_with_nulls(buffer_dest2, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest4, buffer_source4, sizeof(buffer_dest4));
	print_with_nulls(buffer_dest4, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest3, buffer_source3, sizeof(buffer_dest3));
	print_with_nulls(buffer_dest3, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest5, buffer_source5, strlen(buffer_source5) + 1);
	print_with_nulls(buffer_dest5, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest6, buffer_source6, strlen(buffer_source6) + 1);
	print_with_nulls(buffer_dest6, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest7, buffer_source7, strlen(buffer_source7));
	print_with_nulls(buffer_dest7, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest8, buffer_source8, strlen(buffer_source8));
	print_with_nulls(buffer_dest8, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest9, buffer_source9, 0);
	print_with_nulls(buffer_dest9, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest10, buffer_source10, 0);
	print_with_nulls(buffer_dest10, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest9, buffer_source9, 1);
	print_with_nulls(buffer_dest9, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest10, buffer_source10, 1);
	print_with_nulls(buffer_dest10, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest11, buffer_source11, 0);
	print_with_nulls(buffer_dest11, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest12, buffer_source12, 0);
	print_with_nulls(buffer_dest12, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest11, buffer_source11, 1);
	print_with_nulls(buffer_dest11, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest12, buffer_source12, 1);
	print_with_nulls(buffer_dest12, 32);
	printf("%zu\n", returned_value);

	returned_value = strlcpy(buffer_dest13, buffer_source13, 10);
	print_with_nulls(buffer_dest13, 32);
	printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(buffer_dest14, buffer_source14, 10);
	print_with_nulls(buffer_dest14, 32);
	printf("%zu\n", returned_value);

	// returned_value = strlcpy(buffer_dest14, NULL, 0);
	// print_with_nulls(NULL, 32);
	// printf("%zu\n", returned_value);

	returned_value = ft_strlcpy(NULL, buffer_source14, 0);
	// print_with_nulls(NULL, 32);
	printf("%zu\n", returned_value);

	// test_ex0(ft_create_elem);
	// printf("\nTests Ex0 Passed!\n\n\n\n");
	// printf("%i\n", ft_isalpha('a'));
	// printf("%i\n", ft_isalpha('A'));
	// printf("%i\n", ft_isalpha('0'));
	// printf("%i\n", isascii('a'));
	// printf("%i\n", isascii('A'));
	// printf("%i\n", isascii('0'));
	// printf("%i\n", isascii(256));
	// printf("%i\n", isascii(-1));
	// printf("%i\n", isascii(127));	
	// printf("%i\n", ft_isascii(128));
}
