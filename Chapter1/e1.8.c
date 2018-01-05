/*
 * Exercise 1.8
 * Write a program to count blanks, tabs, and newlines
 */
#include <stdio.h>

/* counts blanks, tabs and newlines
 * from input
 */
int main (void)
{
	int blank, tab, nl, c;
	blank = tab = nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++tab;
		else if (c == ' ')
			++blank;
	}

	printf("Tabs: %d\nBlanks: %d\nNew lines: %d\n", tab, blank, nl);
}
