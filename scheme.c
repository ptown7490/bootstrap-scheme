/*
 * Bootstrap Scheme - a quick and very dirty Scheme interpreter.
 * Copyright (C) 2010 Peter Michaux (http://peter.michaux.ca/)
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public
 * License version 3 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License version 3 for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License version 3 along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "model.h"
#include "read.h"
#include "eval.h"
#include "print.h"




/***************************** REPL ******************************/

int main(void) {
    object *exp;

    printf("Welcome to Bootstrap Scheme. "
           "Use ctrl-c to exit.\n");

    init();

    while (1) {
        printf("> ");
        exp = read(stdin);
        if (exp == NULL) {
            break;
        }
        write(stdout, eval(exp, the_global_environment));
        printf("\n");
    }

    printf("Goodbye\n");

    return 0;
}

/**************************** MUSIC *******************************

Slipknot, Neil Young, Pearl Jam, The Dead Weather,
Dave Matthews Band, Alice in Chains, White Zombie, Blind Melon,
Priestess, Puscifer, Bob Dylan, Them Crooked Vultures,
Black Sabbath, Pantera, Tool, ZZ Top, Queens of the Stone Age,
Raised Fist, Rage Against the Machine, Primus, Black Label Society,
The Offspring, Nickelback, Metallica, Jeff Beck, M.I.R.V.,
The Tragically Hip, Willie Nelson, Highwaymen

*/
