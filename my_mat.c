#include "my_mat.h"
#include <math.h>
#include <stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int actionA(int mat[10][10]){
    // change all values in matrix to 0 for a new connections matrix
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            mat[i][j] = 0;
        }
    }
    // get values from user that defined all connections
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    // run the shortest route finding algorithm
    for (int k=0 ; k<10 ; k++){
        for (int a=0 ; a<10 ; a++){
            for (int b=0 ; b<10 ; b++){
                // if there is no direct route, check if there is a non direct one
                if (a != b && mat[a][b] == 0){
                    if (mat[a][k] != 0 && mat[k][b] != 0){
                        mat[a][b] = (mat[a][k])+(mat[k][b]);
                    }
                }
                // if there is direct route, check if there is a shorter one
                else if (a != b && mat[a][b] != 0 && mat[a][k] != 0 && mat[k][b] != 0){
                    mat[a][b] = MIN(mat[a][b] , ((mat[a][k])+(mat[k][b])));
                }
            }
        }
    }

    return 0;
}


int actionB(int mat[10][10]){
    int i,j;
    scanf("%d %d" , &i , &j);
    // if the two given indexes are the same node -
    if (i==j){
        printf("False\n");
    }
    // if the length is more than 0, which means there is a root -
    else if (mat[i][j]>0){
        printf("True\n");
    }
    // if the length is 0, which means there is no root -
    else{
        printf("False\n");
    }
    return 0;
}


int actionC(int mat[10][10]){
    int i,j;
    scanf("%d %d" , &i , &j);
    // if the two given indexes are the same node -
    if (i==j){
        printf("-1\n");
    }
    // if the length is more than 0, print the length of the root
    else if (mat[i][j]>0){
        printf("%d\n" , mat[i][j]);
    }
    // if the length is 0, there is no root
    else{
        printf("-1\n");
    }
    return 0;
}