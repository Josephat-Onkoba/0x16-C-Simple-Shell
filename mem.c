#include "main.h"

/**
 * _memcpy - Copy memory area from source to destination.
 *
 * @dest: Destination memory buffer.
 * @src: Source memory buffer.
 * @n: Number of bytes to copy.
 */
void _memcpy(void *dest, const void *src, size_t n)
{
	char *d = (char *)dest;          /*Pointer to the destination buffer.*/
	const char *s = (const char *)src;  /*Pointer to the source buffer.*/
	size_t i;  /* Declare the loop variable before the loop. */

	for (i = 0; i < n; i++)
	{
		d[i] = s[i];  /*Copy each byte from source to destination.*/
	}
}
