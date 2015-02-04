#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "object.h"

char is_delimiter(int c);
char is_initial(int c);
int peek(FILE *in);
void eat_whitespace(FILE *in);
void eat_expected_string(FILE *in, char *str);
void peek_expected_delimiter(FILE *in);
object *read_character(FILE *in);
object *read_pair(FILE *in);
object *read(FILE *in);
