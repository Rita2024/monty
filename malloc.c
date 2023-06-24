#include "monty.h"

/**
 * _calloc - concatenate tw strings specially
 * @nmemb: number of elements
 * @sizes: type of elements
 * Return: nothing
 */

void *_calloc(unsigned int nmemb, unsigned int sizes)
{
	void *p = NULL;
	unsigned int r = 0;

	if (nmemb == 0 || sizes == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * sizes);
	if (p == NULL)
	{
		return (NULL);
	}
	for (; r < (nmemb * sizes); r++)
	{
		*((char *)(p) + r) = 0;
	}
	return (p);
}

/**
 * _realloc - change the size and copy the content
 * @ptrs: malloc pointer to reallocate
 * @old_sizes: old number of bytes
 * @new_sizes: new number of Bytes
 * Return: nothing
 */

void *_realloc(void *ptrs, unsigned int old_sizes, unsigned int new_sizes)
{
	char *p = NULL;
	unsigned int x = 0;

	if (new_sizes == old_sizes)
		return (ptrs);
	if (ptrs == NULL)
	{
		p = malloc(new_sizes);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_sizes == 0 && ptrs != NULL)
	{
		free(ptrs);
		return (NULL);
	}
	if (new_sizes > old_sizes)
	{
		p = malloc(new_sizes);
		if (!p)
			return (NULL);
		for (; x < old_sizes; x++)
			p[x] = *((char *)ptrs + x);
		free(ptrs);
	}
	else
	{
		p = malloc(new_sizes);
		if (!p)
			return (NULL);
		for (; x < new_sizes; x++)
			p[x] = *((char *)ptrs + x);
		free(ptrs);
	}
	return (p);
}
