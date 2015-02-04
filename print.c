#include "model.h"
#include "print.h"

void write_pair(FILE *out, object *pair) {
    object *car_obj;
    object *cdr_obj;

    car_obj = car(pair);
    cdr_obj = cdr(pair);
    write(out, car_obj);
    if (cdr_obj->type == PAIR) {
        fprintf(out, " ");
        write_pair(out, cdr_obj);
    }
    else if (cdr_obj->type == THE_EMPTY_LIST) {
        return;
    }
    else {
        fprintf(out, " . ");
        write(out, cdr_obj);
    }
}

void write(FILE *out, object *obj) {
    char c;
    char *str;

    switch (obj->type) {
        case THE_EMPTY_LIST:
            fprintf(out, "()");
            break;
        case BOOLEAN:
            fprintf(out, "#%c", is_false(obj) ? 'f' : 't');
            break;
        case SYMBOL:
            fprintf(out, "%s", obj->data.symbol.value);
            break;
        case FIXNUM:
            fprintf(out, "%ld", obj->data.fixnum.value);
            break;
        case CHARACTER:
            c = obj->data.character.value;
            fprintf(out, "#\\");
            switch (c) {
                case '\n':
                    fprintf(out, "newline");
                    break;
                case ' ':
                    fprintf(out, "space");
                    break;
                default:
                    putc(c, out);
            }
            break;
        case STRING:
            str = obj->data.string.value;
            putchar('"');
            while (*str != '\0') {
                switch (*str) {
                    case '\n':
                        fprintf(out, "\\n");
                        break;
                    case '\\':
                        fprintf(out, "\\\\");
                        break;
                    case '"':
                        fprintf(out, "\\\"");
                        break;
                    default:
                        putc(*str, out);
                }
                str++;
            }
            putchar('"');
            break;
        case PAIR:
            fprintf(out, "(");
            write_pair(out, obj);
            fprintf(out, ")");
            break;
        case PRIMITIVE_PROC:
            fprintf(out, "#<primitive-procedure>");
            break;
        case COMPOUND_PROC:
            fprintf(out, "#<compound-procedure>");
            break;
        case INPUT_PORT:
            fprintf(out, "#<input-port>");
            break;
        case OUTPUT_PORT:
            fprintf(out, "#<output-port>");
            break;
        case EOF_OBJECT:
            fprintf(out, "#<eof>");
            break;
        default:
            fprintf(stderr, "cannot write unknown type\n");
            exit(1);
    }
}
