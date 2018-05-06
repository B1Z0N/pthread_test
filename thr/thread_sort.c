#include <pthread.h>
#include "../threads_vs_ordinary.h"

void * sort_inf(void * arr_ptr);

typedef struct thread_arr {
    int * arr;
    int len;
}thread_arr;

int main() {
    RAND;
    int x, y;
    
    printf("Enter array dimensions(x & y)\n");
    scanf("%d", &x);
    scanf("%d", &y);
    
    //gen_inf(PATH, x, y);
    myarr * arr = insert_inf(PATH);
    //print_inf(arr);

    thread_arr temp_arr[y];
    pthread_t thr[y];

    for(int i = 0; i < y; i++) {
        temp_arr[i].arr = arr->arr[i];
        temp_arr[i].len = arr->x;

        if(pthread_create(&thr[i], NULL, sort_inf, (void *) &(temp_arr[i])) == -1)
            error("THREADS::CREATION");
    }

    unsigned int time2, time1 = clock();
    for(int i = 0; i < y; i++) {
        if(pthread_join(thr[i], NULL) == -1)
            error("THREADS::JOINING");
    }

    time2 = clock();

    printf("Thread sorting takes: %f seconds\n", ((float) (time2 - time1)) / CLOCKS_PER_SEC);

    //print_inf(arr);

    del_inf(&arr);

    return(0);
}

void * sort_inf(void * arr_ptr) {
thread_arr * arr = (thread_arr *) arr_ptr;

_Bool flag = 1;
    for(int j = 0; j < arr->len; j++) {
        for(int z = arr->len - 1; z > j; z--) {
            if(arr->arr[z - 1] > arr->arr[z]) {
                flag = 0;

                int temp = arr->arr[z - 1];
                arr->arr[z - 1] = arr->arr[z];
                arr->arr[z] = temp;
            }
        }
        if(flag) break;
    }
}