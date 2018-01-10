/*
 * Exercise 1.13
 * Write a program to print a histogram of the lengths of words in its input.
 * Horizontal Version
 */
#include <stdio.h>

#define MAX_LENGTH 31  // max length of the word

/* prints histogram for the length of words
 * horizontal ver.
 */
int main (void)
{
	int words[MAX_LENGTH];
	int length, c, i, j;

	length = 0;
	for (i = 0; i < MAX_LENGTH; i++)
		words[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			words[length]++;
			length = 0;
		} else {
			length++;
		}
	}

	for (i = 1; i < MAX_LENGTH; i++) {
		printf("%2d: ", i);
		for (j = 0; j < words[i]; j++)
			printf("#");
		printf("\n");
	}
}
