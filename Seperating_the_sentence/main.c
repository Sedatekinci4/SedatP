#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIMIT 100

int main()
{
	char str[MAX_LIMIT];
   	fgets(str, MAX_LIMIT, stdin);
  	char *p;
  	p = strtok(str, " ");

  	while(p != NULL)
  	{
		printf("%s\n", p);
		p = strtok(NULL, " ");
  	}
  	return 0;
}
