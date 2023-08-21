#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	size_t i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (s1[i] - s2[i]);
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchr(const char *s, int c)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
	}

	if (c == '\0')
		return ((char *)&s[i]);

	return (NULL);
}

/**
 * _strdup - Creates a duplicate of a string.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL if
 *         memory allocation fails.
 */
char *_strdup(const char *s)
{
	size_t len = _strlen(s) + 1;
	char *duplicate = (char *)malloc(len);

	if (duplicate == NULL)
	return (NULL);

	_strcpy(duplicate, s);
	return (duplicate);
}

/**
 * _strncmp - Compares two strings up to a specified length.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if the
 *         substring of s1 is found, respectively, to be less than, to match,
 *         or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}

	return (0);
}
