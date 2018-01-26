/*
 * Exercise 1.23
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not
 * nest.
 */
#include <stdio.h>

#define MAXLINE 1000  // max size of line

int  getstring  (char s[], int lim);

/* calls getstring to read input
 * then remove comments
 * and prints the rest
 */
int main (void)
{
	int comment, quote, i;
	int  len;
	char line[MAXLINE];

	comment = quote = 0;
	while ((len = getstring(line, MAXLINE)) > 0) {
		i = 0;
		while (i < len) {
			if (comment && !quote) {
				if (line[i] == '*' && line[i + 1] == '/') {
					i++;
					comment = !comment;
				}
			} else {
				if (!quote) {
					if (line[i] == '"') {
						quote = !quote;
						printf("%c", line[i]);
					} else if (line[i] == '/' && line [i + 1] == '*') {
						comment = !comment;
					} else if (line[i] == '/' && line[i + 1] == '/') {
						i = len;
						printf("\n");
					}else {
						printf("%c", line[i]);
					}
				} else {
					if (line[i] == '"')
						quote = !quote;
					printf("%c", line[i]);
				}
			}
			i++;
		}
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
