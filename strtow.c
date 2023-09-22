#include "monty.h"
#include "lists.h"

/**
 * count_word - helper function to count the number of words in a string 
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, count, increment;

	flag = 0;
	increment = 0;

	for (count = 0; s[count] != '\0'; count++)
	{

		if (s[count] == ' ')
			flag = 0;
		else if (flag == 0)
		{
		
			flag = 1;
			increment++;
		}
	}

	return (increment);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int index, k = 0, lenth = 0, words, count = 0, start, end;

	lenth = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (index = 0; index <= lenth; index++)
	{
		if (isspace(str[index]) || str[index] == '\0' || str[index] == '\n')
		{
			if (count)
			{
				end = index;
				tmp = (char *) malloc(sizeof(char) * (count + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - count;
				k++;
				count = 0;
			}
		}
		else if (count++ == 0)
			start = index;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * free_errthing - frees array of strings
 * @args: array of strings to free
 */
void free_errthing(char **args)
{
	int index;

	if (!args)
		return;

	for (index = 0; args[index]; index++)
		free(args[index]);

	free(args);
}
