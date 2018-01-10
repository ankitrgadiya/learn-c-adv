/*
 * Exercise 1.14
 * Write a program to print a histogram of the frewuencies of different
 * characters in its input
 * Vertical Version
 */
#include <stdio.h>

#define LETTERS 26

/* prints histogram for the frequency of character
 * vertical ver.
 */
int main (void)
{
	int letter[LETTERS];
	int print, c, i, j;

	print = 1;
	for (i = 0; i < LETTERS; i++)
		letter[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			letter[c - 'a']++;
		else if (c >= 'A' && c <= 'Z')
			letter[c - 'A']++;
	}

	for (i = 0; i < LETTERS; i++)
		printf("%c ", i + 'a');
	printf("\n");

	for (j = 0; print != 0; j++) {
		print = 0;
		for (i = 0; i < LETTERS; i++) {
			if (letter[i] > j) {
				printf("# ");
				print++;
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
}
