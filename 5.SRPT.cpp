#include<stdio.h>
int main()
{
    int n=4; 
    int at[4]={0,1,2,4}; 
    int bt[4]={5,3,3,1}; 
    int rt[4]={5,3,3,1}; 
    int ct[4]={0}; 
    int tat[4]={0}; 
    int wt[4]={0}; 
    int min_bt=9999; 
    int i,j,smallest,time=0,complete=0;
    float avgwt=0,avgtat=0;
    while(complete!=n) 
    {
        smallest=3;
        min_bt=9999;
        for(i=0;i<n;i++) 
        {
            if((at[i]<=time)&&(rt[i]<min_bt)&&(rt[i]>0)) 
            {
                min_bt=rt[i];
                smallest=i;
            }
        }
        rt[smallest]--; 
        if(rt[smallest]==0) 
        {
            complete++; 
            ct[smallest]=time+1; 
            tat[smallest]=ct[smallest]-at[smallest]; 
            wt[smallest]=tat[smallest]-bt[smallest]; 
            avgwt+=wt[smallest];
            avgtat+=tat[smallest]; 
        }
        time++; 
    }
    avgwt/=n; 
    avgtat/=n;
    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Waiting Time: %f\n",avgwt);
    printf("Average Turnaround Time: %f\n",avgtat);
    return 0;
}
