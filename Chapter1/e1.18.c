/*
 * Exercise 1.18
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines
 */
#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

int getstring (char line[], int maxline);

/* print input lines
 * ignores blank lines
 */
int main (void)
{
	int len; // current line length
	char line[MAXLINE]; // current input line

	while ((len = getstring(line, MAXLINE)) > 0) {
		if (len > 1)
			printf("%s", line);
	}

	return 0;
}

/* getstring: read a line into s,
 * remove trailing blanks and tabs
 * return length
 */
int getstring (char s[], int lim)
{
	int c, i, j;

	i = 0;
	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		i++;
	}

	if (c == '\n') {
		for (j = i - 1; s[j] == ' ' || s[j] == '\t'; j--)
			;
		i = j + 1;
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}
