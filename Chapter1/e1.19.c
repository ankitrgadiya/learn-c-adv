/*
 * Exercise 1.19
 * Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time
 */
#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

int getstring (char s[], int lim);
void reverse (char s[]);

/* gets input, reverses it and then print
 */
int main (void)
{
	int len;
	char line[MAXLINE];

	while((len = getstring(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}

/* read a line into s
 */
int getstring (char s[], int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

/* reverses the string
 */
void reverse (char s[])
{
	int len, i;
	char temp[MAXLINE];
	for (len = 0; s[len] != '\n'; len++)
		;

	for (i = 0; i < len; i++)
		temp[i] = s[len - i - 1];

	for (i = 0; i < len; i++)
		s[i] = temp[i];

	s[i] = '\n';
	s[i + 1] = '\0';
	return ;
}
