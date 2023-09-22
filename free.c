#include "monty.h"
#include "lists.h"

/**
 * free_all -  memory handling function 
 * @all: flag to indicate what to free
 */
void free_all(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_errthing(data.words);
		data.words = NULL;
	}

	if (all)
	{
		if (data.stack)
		{
			free_dbllinkdlst(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}
