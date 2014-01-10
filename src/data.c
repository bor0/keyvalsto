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

Data *top = NULL, *last = NULL;

Data *get_top(void) {
    return top;
}

void add_list(Data *data) {
    Data *tmp, *prev = NULL;

    if (!top) {
        top = data;
    } else {
        tmp = top;

        while (tmp != NULL) {
            prev = tmp;
            if (!strcmp(tmp->key, data->key)) {
                if (tmp->type == STRING) free(tmp->value.str);
                tmp->value = data->value;
                tmp->type = data->type;
                free(data);
                return;
            }
            tmp = tmp->next;
        }
        tmp = prev;
        if (!last) last = tmp;

        last->next = data;
    }
    last = data;
}

void add_string(char *key, char *val) {
    int len;
    Data *data;
    data = (Data *)malloc(sizeof(Data));

    data->key = (char *)malloc(sizeof(char) * strlen(key));
    strcpy(data->key, key);

    len = sizeof(char) * strlen(val) + 1;
    data->value.str = (char *)malloc(len);
    memset(data->value.str, 0, len);
    strcpy(data->value.str, val);

    data->type = STRING;

    data->next = NULL;

    add_list(data);
}

void add_int(char *key, int val) {
    Data *data;
    data = (Data *)malloc(sizeof(Data));

    data->key = (char *)malloc(sizeof(char) * strlen(key));
    strcpy(data->key, key);

    data->value.integer = val;

    data->type = INTEGER;

    data->next = NULL;

    add_list(data);
}

void add_num(char *key, double val) {
    Data *data;
    data = (Data *)malloc(sizeof(Data));

    data->key = (char *)malloc(sizeof(char) * strlen(key));
    strcpy(data->key, key);

    data->value.number = val;

    data->type = NUMBER;

    data->next = NULL;

    add_list(data);
}

void clear_data(void) {
    Data *tmp;
    while (top) {
        tmp = top;
        if (top->type == STRING) {
            free(top->value.str);
        }
        top = top->next;
        free(tmp);
    }
    last = top;
}

Data *get_value(char *key) {
    Data *tmp = top;
    while (tmp != NULL) {
        if (!strcmp(tmp->key, key)) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void del_value(char *key) {
    Data *tmp = top, *prev = top;
    while (tmp != NULL) {
        if (!strcmp(tmp->key, key)) {
            if (tmp == top) {
                top = tmp->next;
            } else {
                if (tmp == last) {
                    last = prev;
                }
                prev->next = tmp->next;
            }
            free(tmp);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void print_type(Data *data) {
    if (data) {
        switch (data->type) {
            case STRING:
                printf("string\n");
                break;
            case INTEGER:
                printf("int\n");
                break;
            case NUMBER:
                printf("double\n");
                break;
            default:
                break;
        }
    }
}

void print_data(Data *data) {
    int i, j;

    if (data) {
        switch (data->type) {
            case STRING:
                putchar('"');
                for (i = 0, j = strlen(data->value.str); i < j; i++) {
                    if (data->value.str[i] == '"') putchar('\\');
                    putchar(data->value.str[i]);
                }
                printf("\"\n");
                break;
            case INTEGER:
                printf("%d\n", data->value.integer);
                break;
            case NUMBER:
                printf("%f\n", data->value.number);
                break;
            default:
                break;
        }
    }
}

void list_data(void) {
    Data *tmp = top;
    while (tmp != NULL) {
        printf("%s ", tmp->key);
        tmp = tmp->next;
    }
    putchar('\n');
}
