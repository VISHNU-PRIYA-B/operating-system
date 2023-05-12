#include<stdio.h>

int main(){
    int n=3; 
    int bt[]={2,4,8}; 
    int wt[n],tat[n],avwt=0,avtat=0,i;

    wt[0]=0; 
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
}
    for(i=0;i<n;i++){
        avwt+=wt[i];
        avtat+=tat[i];
    }

    avwt/=n;
    avtat/=n;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time: %d\n",avwt);
    printf("Average turnaround time: %d\n",avtat);

    return 0;
}
