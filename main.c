#include <stdio.h>

#include "parser.h"
#include "data.h"
#include "utils.h"

int main(int argc, char **argv) {
    char line[512];
    printf("KeyValSto v1.0 by Boro Sitnikovski.\n\nType \"help\" for more information.\nWrite \"quit\" at any time to quit.\n\n");

    prompt();

    while (fgets(line, 512, stdin) != NULL) {
        if (parse_line(line) == -1) {
            break;
        }
		prompt();
    }

    printf("\nTerminated.\n");
    clear_data();

    return 0;
}
