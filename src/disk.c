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

#include "data.h"
#include "parser.h"

void save_to_disk(void) {
    FILE *t = fopen("keyvalsto.data", "w+");

    if (t == NULL) {
        printf("Unable to open data file.\n");
    } else {
        Data *top = get_top();
        
        while (top != NULL) {
            switch (top->type) {
                case STRING:
                    fprintf(t, "%s = \"%s\"\n", top->key, top->value.str);
                    break;
                case INTEGER:
                    fprintf(t, "%s = %d\n", top->key, top->value.integer);
                    break;
                case NUMBER:
                    fprintf(t, "%s = %f\n", top->key, top->value.number);
                    break;
            }
            top = top->next;
        }
        printf("Saved to keyvalsto.data.\n");
        fclose(t);
    }
}

void load_from_disk(void) {
    char data[512];

    FILE *t = fopen("keyvalsto.data", "r");
    if (t == NULL) {
        printf("Unable to open data file.\n");
    } else {
        clear_data();
        while (fgets(data, 512, t) != NULL) {
            parse_line(data);
        }
        printf("Loaded keyvalsto.data.\n");
        fclose(t);
    }
}
