/*
 * Exercise 1.22
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input.  Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */
#include <stdio.h>

#define MAXLINE 1000  // max size of line
#define COLUMN  10    // column after which lines are to be fold

int  getstring  (char s[], int lim);
void foldstring (char s[], int column, int len);

/* calls getstring to read the input
 * pass the string to foldstring
 */
int main (void)
{
	int  len;
	char line[MAXLINE];

	while ((len = getstring(line, MAXLINE)) > 0)
		foldstring(line, COLUMN, len);

	return 0;
}

/* read input into s
 */
int getstring (char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

/* takes string and fold it
 * before 'column' column into
 * 2 or more lines
 */
void foldstring (char s[], int column, int len)
{
	if (len <= column) {
		printf("%s", s);
	} else {
		int i, j, nogap;
		i = j = 0;
		while (i < len) {
			nogap = 0;
			if (i + column < len) {
				j = i + column;
				while (i < j && s[j] != ' ')
					j--;

				if (i == j) {
					nogap = 1;
					j = i + column;
				}
			} else {
				j = len;
			}

			for (; i < j; i++)
				putchar(s[i]);

			if (nogap)
				putchar('-');

			putchar('\n');
		}
	}

	return ;
}
