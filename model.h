#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "object.h"

object *the_empty_list;
object *false;
object *true;
object *symbol_table;
object *quote_symbol;
object *define_symbol;
object *set_symbol;
object *ok_symbol;
object *if_symbol;
object *lambda_symbol;
object *begin_symbol;
object *cond_symbol;
object *else_symbol;
object *let_symbol;
object *and_symbol;
object *or_symbol;
object *eof_object;
object *the_empty_environment;
object *the_global_environment;

object *cons(object *car, object *cdr);
object *car(object *pair);
object *cdr(object *pair);



char is_the_empty_list(object *obj);
char is_boolean(object *obj);
char is_false(object *obj);
char is_true(object *obj);
object *make_symbol(char *value);
char is_symbol(object *obj);
object *make_fixnum(long value);
char is_fixnum(object *obj);
object *make_character(char value);
char is_character(object *obj);
object *make_string(char *value);
char is_string(object *obj);
object *cons(object *car, object *cdr);
char is_pair(object *obj);
object *car(object *pair);
void set_car(object *obj, object* value);
object *cdr(object *pair);
void set_cdr(object *obj, object* value);
object *make_primitive_proc(object *(*fn)(struct object *arguments));
char is_primitive_proc(object *obj);
object *is_null_proc(object *arguments);
object *is_boolean_proc(object *arguments);
object *is_symbol_proc(object *arguments);
object *is_integer_proc(object *arguments);
object *is_char_proc(object *arguments);
object *is_string_proc(object *arguments);
object *is_pair_proc(object *arguments);
object *is_procedure_proc(object *arguments);
object *char_to_integer_proc(object *arguments);
object *integer_to_char_proc(object *arguments);
object *number_to_string_proc(object *arguments);
object *string_to_number_proc(object *arguments);
object *symbol_to_string_proc(object *arguments);
object *string_to_symbol_proc(object *arguments);
object *add_proc(object *arguments);
object *sub_proc(object *arguments);
object *mul_proc(object *arguments);
object *quotient_proc(object *arguments);
object *remainder_proc(object *arguments);
object *is_number_equal_proc(object *arguments);
object *is_less_than_proc(object *arguments);
object *is_greater_than_proc(object *arguments);
object *cons_proc(object *arguments);
object *car_proc(object *arguments);
object *cdr_proc(object *arguments);
object *set_car_proc(object *arguments);
object *set_cdr_proc(object *arguments);
object *list_proc(object *arguments);
object *is_eq_proc(object *arguments);
object *apply_proc(object *arguments);
object *interaction_environment_proc(object *arguments);
object *setup_environment(void);
object *null_environment_proc(object *arguments);
object *environment_proc(object *arguments);
object *eval_proc(object *arguments);
object *load_proc(object *arguments);
object *open_input_port_proc(object *arguments);
object *close_input_port_proc(object *arguments);
object *is_input_port_proc(object *arguments);
object *read_proc(object *arguments);
object *read_char_proc(object *arguments);
object *peek_char_proc(object *arguments);
object *is_eof_object_proc(object *arguments);
object *open_output_port_proc(object *arguments);
object *close_output_port_proc(object *arguments);
object *is_output_port_proc(object *arguments);
object *write_char_proc(object *arguments);
object *write_proc(object *arguments);
object *error_proc(object *arguments);
object *make_compound_proc(object *parameters, object *body, object* env);
char is_compound_proc(object *obj);
object *make_input_port(FILE *stream);
char is_input_port(object *obj);
object *make_output_port(FILE *stream);
char is_output_port(object *obj);
char is_eof_object(object *obj);
object *enclosing_environment(object *env);
object *first_frame(object *env);
object *make_frame(object *variables, object *values);
object *frame_variables(object *frame);
object *frame_values(object *frame);
void add_binding_to_frame(object *var, object *val, object *frame);
object *extend_environment(object *vars, object *vals, object *base_env);
object *lookup_variable_value(object *var, object *env);
void set_variable_value(object *var, object *val, object *env);
void define_variable(object *var, object *val, object *env);
object *setup_environment(void);
void populate_environment(object *env);
object *make_environment(void);
void init(void);

#define caar(obj)   car(car(obj))
#define cadr(obj)   car(cdr(obj))
#define cdar(obj)   cdr(car(obj))
#define cddr(obj)   cdr(cdr(obj))
#define caaar(obj)  car(car(car(obj)))
#define caadr(obj)  car(car(cdr(obj)))
#define cadar(obj)  car(cdr(car(obj)))
#define caddr(obj)  car(cdr(cdr(obj)))
#define cdaar(obj)  cdr(car(car(obj)))
#define cdadr(obj)  cdr(car(cdr(obj)))
#define cddar(obj)  cdr(cdr(car(obj)))
#define cdddr(obj)  cdr(cdr(cdr(obj)))
#define caaaar(obj) car(car(car(car(obj))))
#define caaadr(obj) car(car(car(cdr(obj))))
#define caadar(obj) car(car(cdr(car(obj))))
#define caaddr(obj) car(car(cdr(cdr(obj))))
#define cadaar(obj) car(cdr(car(car(obj))))
#define cadadr(obj) car(cdr(car(cdr(obj))))
#define caddar(obj) car(cdr(cdr(car(obj))))
#define cadddr(obj) car(cdr(cdr(cdr(obj))))
#define cdaaar(obj) cdr(car(car(car(obj))))
#define cdaadr(obj) cdr(car(car(cdr(obj))))
#define cdadar(obj) cdr(car(cdr(car(obj))))
#define cdaddr(obj) cdr(car(cdr(cdr(obj))))
#define cddaar(obj) cdr(cdr(car(car(obj))))
#define cddadr(obj) cdr(cdr(car(cdr(obj))))
#define cdddar(obj) cdr(cdr(cdr(car(obj))))
#define cddddr(obj) cdr(cdr(cdr(cdr(obj))))
