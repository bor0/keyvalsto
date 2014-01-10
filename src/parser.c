/*
This file is part of KeyValSto.

KeyValSto is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KeyValSto is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with KeyValSto. If not, see <http://www.gnu.org/licenses/>.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "parser.h"
#include "utils.h"
#include "disk.h"

void parse_variable_assignment(char *key, char *val) {
    int len = strlen(val);
    /* check if it's a valid assignment command */
    if (!is_not_alpha_str(key) || !strcmp(key, "save") || !strcmp(key, "load") || !strcmp(key, "save") || !strcmp(key, "list")) {
        printf("Invalid variable name.\n");
    } else if (val[0] == '"' && val[len-1] == '"') { /* is it a string */
        val[len-1] = '\0';
        add_string(key, val+1);
    } else { /* maybe it's a number */
        int i; double d;
        if (!is_numeric_str(val)) printf("Cannot parse\n");
        else if (str_contains_char(val, '.') && sscanf(val, "%lf", &d) != 0) add_num(key, d); /* it's a double. */
        else if (sscanf(val, "%d", &i) != 0) add_int(key, i); /* it's an int. */
        else printf("Cannot parse.\n");
    }
}

int parse_command(char *line) {
    if (!strcmp(line, "list")) {
        list_data();
    } else if (!strcmp(line, "save")) {
        save_to_disk();
    } else if (!strcmp(line, "load")) {
        load_from_disk();
    } else if (!strcmp(line, "help")) {
        printf("Available commands: list, save, load, quit, !var, @var\n\nE.g. \
Define a variable, show its type, show its value, delete the variable:\ntest = 3\n@test\ntest\n!test\n");
    } else if (!strcmp(line, "quit") || !strcmp(line, "exit")) {
        return -1;
    } else if (line[0] == '!') {
        Data *tmp = get_value(line + 1);
        if (!tmp) {
            printf("Undefined variable.\n");
        } else {
            del_value(tmp->key);
        }
    } else if (line[0] == '@') {
        Data *tmp = get_value(line + 1);
        if (!tmp) {
            printf("Undefined variable.\n");
        } else {
            print_type(tmp);
        }
    } else {
        Data *tmp = get_value(line);
        if (!tmp) {
            printf("Undefined variable.\n");
        } else {
            print_data(tmp);
        }
    }
    return 1;
}

int parse_line(char *line) {
    char *token, *key;
    int retval = 1;

    trim_newlines(line);

    key = token = line;
    while (*token != '=' && *token != '\0') {
        token++;
    }

    if (*token == '=') {
        *token = '\0';
        token++;
        key = trim_space(key);
        token = trim_space(token);
        parse_variable_assignment(key, token);
    } else {
        trim_space(line);
        retval = parse_command(line);
    }

    return retval;
}
