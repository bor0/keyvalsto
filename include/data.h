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
enum type { STRING, INTEGER, NUMBER };

typedef union val {
    char *str;
    int integer;
    double number;
} val;

typedef struct Data {
    char *key;
    val value;
    int type;
    struct Data *next;
} Data;

Data *get_top(void);
void add_list(Data *data);
void add_string(char *key, char *val);
void add_int(char *key, int val);
void add_num(char *key, double val);
Data *get_value(char *key);
void del_value(char *key);
void print_type(Data *data);
void print_data(Data *data);
void clear_data(void);
void list_data(void);
