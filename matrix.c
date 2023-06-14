#include <stdio.h>
#include <stdlib.h>

void rowsum (int mat[10][10], int m, int n, int rows[10]){

    int i,j;

    for (i=0; i<m;i++){
        rows[i]=0;
    }
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            rows[i]+=mat[i][j];
        }
    }
}

void colsum (int mat[10][10], int m, int n, int cols[10]){

    int i,j;
    for (i=0; i<n; i++) 
        cols[i]=0;
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            cols[j]+=mat[i][j];
        }
    }
}

void disp (int a[10][10], int m, int n){
    int i,j;

    for (i=0; i<m; i++){
        printf ("\n");
        for (j=0; j<n; j++){
            printf ("%d  ", a[i][j]);
        }
    }
}

void multi (int mat[10][10], int m, int n){
    int p,q;
    int i,j,k;
    int mat1[10][10], res[10][10];

    printf ("Enter 2nd matrix order:\n");
    scanf ("%d %d", &p, &q);
    if (n!=p){
        printf ("Not multipliable!\n");
        return;
    }
    printf ("Enter elements:\n");

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            scanf ("%d", &mat1[i][j]);
        }
    }

    for (i=0; i<m; i++){
        for (j=0; j<q; j++){
            res[i][j]=0;
            for (k=0; k<n; k++){
                res[i][j]+=mat[i][k]*mat1[k][j];
            }
        }
    }
    printf ("Result:\n");
    for (i=0; i<m; i++){
        for (j=0; j<q; j++){
            printf ("%d  ", &mat1[i][j]);
        }
        printf ("\n");
    }

}

void add (int mat[10][10], int m, int n){
    int p,q;
    int i,j,k;
    int mat1[10][10], res[10][10];

    printf ("Enter 2nd matrix order:\n");
    scanf ("%d %d", &p, &q);

    if (m!=p && n!=q){
        printf ("Not multipliable!\n");
        return;
    }
    printf ("Enter elements:\n");

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            scanf ("%d", &mat1[i][j]);
        }
    }

    printf ("Result!\n");

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            res[i][j]=mat[i][j]+mat1[i][j];
            printf ("%d  ", res[i][j]);
        }
        printf ("\n");
    }
    
}

void sub (int mat[10][10], int m, int n){
    int p,q;
    int i,j,k;
    int mat1[10][10], res[10][10];

    printf ("Enter 2nd matrix order:\n");
    scanf ("%d %d", &p, &q);

    if (m!=p && n!=q){
        printf ("Not multipliable!\n");
        return;
    }
    printf ("Enter elements:\n");

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            scanf ("%d", &mat1[i][j]);
        }
    }

    printf ("Result!\n");

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            res[i][j]=mat[i][j]-mat1[i][j];
            printf ("%d  ", res[i][j]);
        }
        printf ("\n");
    }
    
}

int main (){
    int m,n,i,j, choice;

    printf ("Enter number of rows and columns:\n");
    scanf ("%d %d", &m, &n);

    int arr[10][10];

    printf ("\nEnter elements:\n");

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            scanf ("%d", &arr[i][j]);
        }
    }

    int rows[m], cols[n];

    
    while(1){
        printf ("\n1:Sum of rows and cols:\n2:Display\n3:Multiply\n4:Exit\n5:Add\n6:Subtract\n");
        scanf ("%d", &choice);
        switch(choice){
            case 1: rowsum (arr,m,n,rows);
            colsum (arr,m,n,cols);
            printf ("\nSum of rows:\n");
            for (i=0; i<m; i++){
                printf ("%d  ", rows[i]);
            }
            printf ("\nSum of columns:\n");
            for (i=0; i<n; i++){
                printf ("%d  ", cols[i]);
            }
            break;

            case 2:disp(arr,m,n);
            break;

            case 3:multi(arr,m,n);
            break;

            case 4:exit(0);
            break;

            case 5:add(arr,m,n);
            break;

            case 6:sub(arr,m,n);
            break;

            default:printf ("Enter a valid input!\n");

        }
    }

    return 0;

}