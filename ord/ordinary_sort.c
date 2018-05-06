#include "../threads_vs_ordinary.h"

void sort_inf(myarr * arr);

int main() {
    RAND;
    int x, y;
    
    printf("Enter array dimensions(x & y)\n");
    scanf("%d", &x);
    scanf("%d", &y);
    
    gen_inf(PATH, x, y);

    myarr * arr = insert_inf(PATH);
    //print_inf(arr);
    sort_inf(arr);
    //print_inf(arr);


    del_inf(&arr);
    return(0);
}

void sort_inf(myarr * arr) {
    unsigned int time1 = clock();
    for(int i = 0; i < arr->y; i++) {
        _Bool flag = 1;
        for(int j = 0; j < arr->x; j++) {
            for(int z = arr->x - 1; z > j; z--) {
                if(arr->arr[i][z - 1] > arr->arr[i][z]) {
                    flag = 0;

                    int temp = arr->arr[i][z - 1];
                    arr->arr[i][z - 1] = arr->arr[i][z];
                    arr->arr[i][z] = temp;
                }
            }
            if(flag) break;
        }
    }
    unsigned int time2 = clock();
    printf("Ordinary sorting takes: %f seconds\n", ((float) (time2 - time1)) / CLOCKS_PER_SEC);
}



