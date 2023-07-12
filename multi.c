#include <stdio.h>
#include <stdlib.h>

struct Process{
    int at;
    int cput;
    int q;
    int tat;
    int wt;
};
struct Process p[10];

int q1[10], q2[10], f1=0, f2=0, r1=-1, r2=-1, time=0;

int FCFS(int q,int n){
    int i,k,prev;
    if (q==1){
        for (i=0; i<r1; i++){
            if (f1>r1) break;
            k=q1[f1++];
            if (i!=k){
                f1--;
                continue;
            }
            if (p[k].at>time){
                f1--;
                FCFS(2,n);
                break;
            }
            time+=p[k].cput;
            p[k].tat=time-p[k].at;
            p[k].wt=p[k].tat-p[k].cput;
        }
    }
    else{
        for (i=0; i<r2; i++){
            if (f2>r2) break;
            k=q2[f2++];
            if (i!=k){
                f2--;
                continue;
            }
            if (p[k].at>time){
                f2--;
                FCFS(1,n);
                break;
            }
            time+=p[k].cput;
            p[k].tat=time-p[k].at;
            p[k].wt=p[k].tat-p[k].cput;
        }
    }

}

int main(){
    int n, i, j, temp, time=0;
    float awt=0,atat=0;

    printf ("Enter no. of processes:\n");
    scanf ("%d",&n);

    printf ("Enter arrival and processing time and the queue:\n");
    for (i=0;i<n;i++){
        scanf ("%d %d %d", &p[i].at, &p[i].cput, &p[i].q);
        if (p[i].q==1) q1[++r1]=i;
        else if (p[i].q==2) q2[++r2]=i;
        else printf ("\nInvalid queue!\n");
    }
    //assuming q1>q2
    while (f1<=r1 && f2<=r2){
        FCFS(1,n);
        FCFS(2,n);
    }
    printf ("Turn around time:\n");
    for (i=0; i<n; i++){
        printf ("P%d\t%d\n", i+1, p[i].tat);
        atat+= p[i].tat;
    }
    printf ("Wait time:\n");
    for (i=0; i<n; i++){
        printf ("P%d\t%d\n", i+1, p[i].wt);
        awt+= p[i].wt;
    }
    atat/=n;
    awt/=n;
    printf ("\nATAT=%f  AWT=%f",atat,awt);
    return 0;
}    