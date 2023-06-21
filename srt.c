#include <stdio.h>
#include <stdlib.h>

int main(){
    int AT[10], CPUT[10], WT[10], TAT[10], remaining[10];
    int n, i, j, completed=0, current=0;
    float tat=0, wt=0;

    printf ("Enter the number of processes:\n");
    scanf ("%d", &n);

    printf ("Enter the AT time and CPUT time:\n");
    for (i=0; i<n; i++){
        scanf ("%d %d", &AT[i], &CPUT[i]);
    }
    for (i=0; i<n; i++){
        printf ("P%d\t%d\t%d\n", i+1, AT[i], CPUT[i]);
    }

    for(i=0;i<n;i++){
        remaining[i]=CPUT[i];
    }

    while(completed!=n){
        int shortest=-1;
        int min=1000;

        for(i=0;i<n;i++){
            if(AT[i]<=current && remaining[i]>0 && remaining[i]<min){
                shortest=i;
                min=remaining[i];
            }
        }
            if(shortest==-1){
                current++;
                continue;
            }

            current++;
            remaining[shortest]--;
            if(remaining[shortest]==0){
            TAT[shortest]=current-AT[shortest];
            WT[shortest]=TAT[shortest]-CPUT[shortest];
            completed++;
            }
    }

    for (i=0; i<n;i++){
        wt += WT[i];
        tat += TAT[i];
    }
    wt = wt/n;
    tat = tat/n;
    printf ("\nAverage turn around time=%f\nThroughput time=%f\n", tat, wt);

    return 0;
}