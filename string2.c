#include "main.h"

/**
 * _strdup - Duplicates (copies) a string.
 *
 * @s: The string to be duplicated.
 *
 * Return: A pointer to the newly allocated memory containing the duplicated
 *  string. Returns NULL if memory allocation fails or if @s is NULL.
 */
char *_strdup(const char *s)
{
	size_t len = _strlen(s) + 1; /*+1 for the null terminator*/
	char *dup = (char *)malloc(len);

	if (dup == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(dup, s);
	return (dup);
}

/**
 * _strcpy - a function that copies a string from src to dest
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
