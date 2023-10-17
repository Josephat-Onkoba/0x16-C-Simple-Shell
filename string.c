#include "main.h"

/**
 * _strncat - Concatenates two strings, ensuring the result is null-terminated.
 *
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of characters to concatenate from src.
 */
void _strncat(char *dest, const char *src, size_t n)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
}


/**
 * _strlen - Computes the length of a string.
 *
 * @s: The string whose length is to be determined.
 *
 * Return: The number of characters in the string
 *         (excluding the null terminator).
 */
int _strlen(const char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string to compare.
 * @s2: Second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 *
 * @s: The string to search within.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence of @c in @s, or NULL if not found.
 */
const char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	if (*s == c)
	{
		return (s);
	}

	return (NULL); /* Character not found */
}

/**
 * _strncmp - Compare the first 'n' characters of two strings.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
		n--;
	}

	return (0);
}
