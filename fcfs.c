#include <stdio.h>
#include <stdlib.h>

int main(){

    int AT[10], CPUT[10], WT[10], TAT[10];
    int n, i;
    float tat=0, wt=0;

    printf ("Enter the number of processes:\n");
    scanf ("%d", &n);

    printf ("Enter the arrival time and CPU time:\n");
    for (i=0; i<n; i++){
        scanf ("%d %d", &AT[i], &CPUT[i]);
    }
    for (i=0; i<n; i++){
        printf ("P%d\t%d\t%d\n", i+1, AT[i], CPUT[i]);
    }

    TAT[0] = CPUT[0];
    for(i=1; i<n; i++){
        TAT[i] = TAT[i-1]+CPUT[i];
    }
    for (i=0; i<n; i++){
        TAT[i] = TAT[i]-AT[i];
        WT[i] = TAT[i]-CPUT[i];
        tat += TAT[i];
        wt += WT[i];
    }
    printf ("Turn around time:\n");
    for (i=0; i<n; i++){
        printf ("P%d\t%d\n", i+1, TAT[i]);
    }
    printf ("Wait time:\n");
    for (i=0; i<n; i++){
        printf ("P%d\t%d\n", i+1, WT[i]);
    }
    wt = wt/n;
    tat = tat/n;

    printf ("\nAverage turn around time=%f\nThroughput time=%f\n", tat, wt);

    return 0;
}