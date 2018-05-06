#include "threads_vs_ordinary.h"


void error(const char * msg) {
    printf("ERROR::%s", msg);
    exit(-1);
}
void gen_inf(const char * path, int x, int y) {
    FILE * f;
    if((f = fopen(path, "w")) == NULL) error("FILE::WRITING");

    fprintf(f, "%d\n%d\n", y, x);

    for(int i = 0; i < y * x; i++)
        fprintf(f, "%d\n", rand() % MAX);

    fclose(f);
}
void print_inf(myarr * arr) {
    for(int i = 0; i < arr->y; i++) {
        for(int j = 0; j < arr->x; j++)
            printf("%d  ", arr->arr[i][j]);
        printf("\n");
    }
}
myarr * insert_inf(const char * path) {
    int y, x;
    FILE * f;
    if((f = fopen(path, "r")) == NULL) error("FILE::READING");

    myarr * arr = (myarr *) malloc(sizeof(myarr));

    fscanf(f, "%d", &y); 
    arr->arr = (int **) malloc(y * sizeof(int *));

    fscanf(f, "%d", &x);
    for(int i = 0; i < y; i++)
        arr->arr[i] = (int *) malloc(x * sizeof(int));

    arr->x = x;
    arr->y = y;

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++)
            fscanf(f, "%d", &(arr->arr[i][j]));
    }

    fclose(f);

    return(arr);
}
void del_inf(myarr ** arr) {
    for(int i = 0; i < (*arr)->y; i++)
        free( (*arr)->arr[i] );
    free( (*arr)->arr );
    free( (*arr) );
}