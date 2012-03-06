/*
 * Brainfuck String Generator Generator
 * A program which takes a string and
 * generates a brainfuck code which
 * generates the string
 * written by the legend: Amir Watad (dot com)
 */
#include <stdio.h>
#include <string.h>
#define N 26
#define MAX_STR_LEN 100000
int main(int argc, char *argv[])
{
	char used[N] = {[0 ... N-1] = -1}; /* saves the state of the brainfuck array */
	char map[N] = {[0 ... N-1] = -1}; /* a map for fast access to relevant cells
					     in the brainfuck array */
	char string[MAX_STR_LEN]; /* input string with a newline in the end */
	char str[MAX_STR_LEN]; /* input string */
	int used_idx = 0; /* current place of the brainfuck pointer */
	int str_idx = 0; /* index of current char in the string */
	char current; /* current char */
	int i, j; /* general purpose iterators */
	char c;
	if (argc == 2) {
		strcpy(str, argv[1]);
	} else if (argc == 1) {
		i = 0;
		while (((c = getchar()) != EOF) && i < MAX_STR_LEN) {	
			str[i] = c;
			i++;
		}
	} else {
		printf("bad number of arguments\n");
		return 0;
	}
	/* copy the input string + a newline */
	strcpy(string, str);
	string[strlen(str)] = '\n';
	string[strlen(str)+1] = '\0';

	/* we'll use first index as a counter for the while loop */
	used[0] = 10;
	printf("++++++++++[");
	used_idx = 1;

	/* prepare a few places in the brainfuck array
	 * with values close to those of the characters
	 * in the string */
	while (current = string[str_idx]) {
		if (map[current/10] == -1) {
			used[used_idx] = (current/10)*10;
			map[current/10] = used_idx;
			used_idx++;
		}
		str_idx++;
	}

	str_idx = 0;

	/* fill the brainfuck array with initial values */
	for (i = 1; i < N; i++) {
		if (used[i] == -1)
			break;
		printf(">");
		for (j = 0; j < used[i]/10; j++)
			printf("+");
	}

	for (i = 1; i < N; i++) {
		if (used[i] == -1)
			break;
		printf("<");
	}
	printf("-]");
	used_idx = 0;

	while (current = string[str_idx]) {
		int relevant_idx = map[current/10];
		int diff_idx = relevant_idx - used_idx;
		int val = used[relevant_idx];
		int diff_val = current - val;
		used_idx = relevant_idx;
		if (diff_idx > 0)
			for (i = 0; i < diff_idx; i++)
				printf(">");
		else
			for (i = 0; i > diff_idx; i--)
				printf("<");
		if (diff_val > 0)
			for (i = 0; i < diff_val; i++) {
				printf("+");
				used[used_idx]++;
			}
		else
			for (i = 0; i > diff_val; i--) {
				printf("-");
				used[used_idx]--;
			}
		printf(".");
		str_idx++;
	}
	printf("\n");
	return 1;
}

