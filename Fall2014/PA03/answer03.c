#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
	char * buffer;

	if((*dest == NULL) || (strlen(src) + strlen(*dest) + 1 > *n))
	{
		if (*dest == NULL)
		{
			buffer = malloc(strlen(src) * 2 + 1);

			buffer[0] = '\0';

			*n = strlen(src) * 2 + 1;

			free(*dest);

			*dest = buffer;

		} else
		{
			buffer = malloc((strlen(src) + strlen(*dest)) * 2 + 1);

			*n = (strlen(src) + strlen(*dest)) * 2 + 1;
		
			strcpy(buffer, *dest);

			free(*dest);

			*dest = buffer;
		}
	}
	
	strcat(*dest, src);

	return (*dest);
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
	return (0);
}

char * implode(char * * strArr, int len, const char * glue)
{
	int count;
	char * * newStr = NULL;
	int n = 0;

	for (count = 0; count < len; count++)
	{
		if (count == 0)
		{
			strcat_ex(&newStr, &n, strArr[count]);
		} else
		{
			strcat_ex(&newStr, &n, glue);
			strcat_ex(&newStr, &n, strArr[count]);
		}
	}

	return (*newStr);
}

int comparator(const void * a, const void * b)
{
	const char * a1 = * (const char * *) a;
	const char * b1 = * (const char * *) b;

	return strcmp(a1, b1);
}

void sortStringArray(char * * arrString, int len)
{
	qsort(arrString, len, sizeof(char *), comparator);

	return;
}

void sortStringCharacters(char * str)
{
	int count1;
	int count2;
	char buffer;

	for (count1 = 0; str[count1] != '\0'; count1++)
	{
		for (count2 = count1 + 1; str[count2] != '\0'; count2++)
		{
			if (str[count1] > str[count2])
			{
				buffer = str[count1];
				str[count1] = str[count2];
				str[count2] = buffer;
			}
		}
	}
	return;
}

void destroyStringArray(char * * strArr, int len)
{
	int count;

	if (strArr == NULL)
	{
		free(strArr);

		return;
	}

	for (count = 0; count < len; count++)
	{
		free(strArr[count]);
	}

	free(strArr);

	return;
}