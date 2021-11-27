#include "my_mat.h"
#include <math.h>
#include <stdio.h>

int main(){
    int mat[10][10] = {0};
    char action = 'g';
    while (action!='D'){
        scanf(" %c" , &action);
        if ('A' == action){
            actionA(&mat);
        }
        else if ('B' == action){
            actionB(&mat);
        }
        else if ('C' == action){
            actionC(&mat);
        }
        else if ('D' == action){
            break;
        }
    }
    return 0;
}