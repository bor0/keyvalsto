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
#include <string.h>
#include <ctype.h>

void prompt(void) {
    printf("> ");
}

void trim_newlines(char *str) {
    while (*str != '\0') {
        if (*str == '\r' || *str == '\n') {
            *str = '\0';
            break;
        }
        str++;
    }
}

char *trim_space(char *str) {
    int i = strlen(str) - 1;
    while (*str == ' ') str++;

    while (str[i] == ' ') i--;
    str[i+1] = '\0';

    return str;
}

int str_contains_char(char *str, char c) {
    while (*str != '\0') {
        if (*str == c) return 1;
        str++;
    }
    return 0;
}

int is_numeric_str(char *str) {
    while (*str != '\0') {
        if (!isdigit(*str) && *str != '.') return 0;
        str++;
    }
    return 1;
}

int is_not_alpha_str(char *str) {
    while (*str != '\0') {
        if (!isalpha(*str)) return 0;
        str++;
    }
    return 1;
}
