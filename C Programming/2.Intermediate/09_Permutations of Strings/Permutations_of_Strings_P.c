#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int i = 1;
    return i;
}

int main()
{
	char **s;
	int n, i;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
