/*
 * Exercise 1.14
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 * Horizontal Version
 */
#include <stdio.h>

#define LETTERS 26

/* prints histogram for the frequency of character
 * horizontal ver.
 */
int main (void)
{
	int letter[LETTERS];
	int c, i, j;

	for (i = 0; i < LETTERS; i++)
		letter[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			letter[c - 'a']++;
		else if (c >= 'A' && c <= 'Z')
			letter[c - 'A']++;
	}

	for (i = 0; i < LETTERS; i++) {
		printf("%c: ", i + 'a');
		for (j = 0; j < letter[i]; j++)
			printf("#");
		printf("\n");
	}
}
