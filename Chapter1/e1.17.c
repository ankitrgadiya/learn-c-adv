/*
 * Exercise 1.17
 * Wrtie a program to print all input lines that are longer than 80 characters
 */
#include <stdio.h>

#define MAXLINE 1000 // maximum input line size
#define LIM 80 // limit for shortest line

int getstring (char line[], int maxline);

/* print input lines
 * longer then 80 characters
 */
int main (void)
{
	int len; // current line length
	char line[MAXLINE]; // current input line

	while ((len = getstring(line, MAXLINE)) > 0) {
		if (len > LIM)
			printf("%s", line);
	}

	return 0;
}

/* getstring: read a line into s,
 * return length
 */
int getstring (char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}
