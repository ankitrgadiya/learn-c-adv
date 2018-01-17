/*
 * Exercise 1.21
 * Write a program entab that replaces strings of blanks by minimum number of
 * tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab.  When either a tab or a single blank would suffice to reach a tab
 * stop, which should be given preference.
 */
#include <stdio.h>

#define MAXLINE 1000 // maxline size of line
#define TABSTOP 8    // tab size

int  getstring (char s[], int lim);
void entab     (char s[]);

/* gets input, entab it
 * and print it
 */
int main (void)
{
	int  len;
	char line[MAXLINE];

	while ((len = getstring(line, MAXLINE)) > 0) {
		entab(line);
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
void entab (char s[])
{
	int i, j, k;
	int  blank, tab;
	char temp[MAXLINE];

	i = j = 0;
	while (s[i] != '\0') {
		if (s[i] == ' ') {
			blank = 0;
			while (s[i] == ' ') {
				i++;
				blank++;
			}
			while (blank > 0) {
				tab = TABSTOP - ((i - blank) % TABSTOP);
				if (tab <= blank) {
					printf("tab\n");
					temp[j++] = '\t';
					blank = blank - tab;
				} else {
					temp[j++] = ' ';
					blank--;
				}
			}
		} else {
			temp[j++] = s[i++];
		}
	}
	for (k = 0; k < j; k++)
		s[k] = temp[k];

	s[k] = '\0';
	return ;
}
