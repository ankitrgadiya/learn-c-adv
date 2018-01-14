/*
 * Exercise 1.20
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter?
 */
#include <stdio.h>

#define MAXLINE 1000 // maxline size of line
#define TABSTOP 8    // tab size

int  getstring (char s[], int lim);
void detab     (char s[]);

/* gets input, detab it
 * and print it
 */
int main (void)
{
	int  len;
	char line[MAXLINE];

	while ((len = getstring(line, MAXLINE)) > 0) {
		detab(line);
		printf("%s", line);
	}

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

/* replace tab character with
 * appropriate spaces
 */
void detab (char s[])
{
	int  i, j, k;
	int  tab;
	char temp[MAXLINE];

	i = 0;
	j = 0;
	while (s[i] != '\0') {
		if (s[i] == '\t') {
			tab = TABSTOP - (j % TABSTOP);
			while (tab > 0) {
				temp[j] = ' ';
				j++;
				tab--;
			}
		} else {
			temp[j] = s[i];
			j++;
		}
		i++;
	}

	for (k = 0; k < j; k++)
		s[k] = temp[k];

	s[k] = '\0';
	return ;
}
