#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "object.h"

void write_pair(FILE *out, object *pair);
void write(FILE *out, object *obj);
