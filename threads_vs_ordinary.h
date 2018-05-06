#include <stdlib.h>
#include <stdio.h>

#include <time.h>

#define PATH "../matrix.txt"
#define MAX 300
#define RAND srand(time(0))

typedef struct myarr {
    int **arr;
    int x;
    int y;
} myarr;

void gen_inf(const char * path, int x, int y);
myarr * insert_inf(const char * path);
void print_inf(myarr * arr);
void del_inf(myarr ** arr);
void error(const char * msg);