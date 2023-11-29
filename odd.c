#include <stdio.h>
#include <stdlib.h>

int main (int argv, char *argc[]){
    // Error handling for number of arguments
    if(argv != 2){
        perror("Error: incorrect argument usage. Ex: ./f_test <value>");
        return 1;
    }

    int N = atoi(argv[1]);

    for(int i = 0; i <= N; i++){
        if(i % 2!== 0){
            printf("%d\n", i);
        }
    }
    
    return 0;
}