#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct process {
    char na[20];
    int at,bt,ft,tat,rem;
    float ntat;
}Q[5],temp;

int rr[20],q,x,k;

int main() {
    int f,r,n,i,j,tt=0,qt,t,flag,wt=0;
    float awt=0,antat=0,atat=0;
    system("cls");
    printf("\nEnter the no. of jobs: ");
    scanf("%d",&n);

    for(r=0;r<n;r++) {
        printf("\nEnter process name, arrival time and burst time: ");
        scanf("%s%d%d",Q[r].na,&Q[r].at,&Q[r].bt);
    }

    printf("\nEnter quantum: ");
    scanf("%d",&qt);
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(Q[i].at>Q[j].at) {
                temp=Q[i];
                Q[i]=Q[j];
                Q[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++) {
        Q[i].rem=Q[i].bt;
        Q[i].ft=0;
    }

    tt=0;
    q=0;
    rr[q]=0;
    do {
        for(j=0;j<n;j++)
        if(tt>=Q[j].at) {
            x=0;
            for(k=0;k<=q;k++)
            if(rr[k]==j)
            x++;
            if(x==0) {
                q++;
                rr[q]=j;
            }
        }

        if(q==0)
            i=0;
        if(Q[i].rem==0)
            i++;
        if(i>q)
            i=(i-1)%q;
        if(i<=q) {
            if(Q[i].rem>0) {
                if(Q[i].rem<qt) {
                    tt+=Q[i].rem;
                    Q[i].rem=0;
                }
                else {
                    tt+=qt;
                    Q[i].rem-=qt;
                }
                Q[i].ft=tt;
            }
            i++;
        }

        flag=0;
        for(j=0;j<n;j++)
        if(Q[j].rem>0)
            flag++;

    } while(flag!=0);
    system("cls");
    printf("\n\n\t\tROUND ROBIN ALGORITHM");
    printf("\n***************************");
    printf("\nProcesses Arrival time Burst time Finish time tat wt ntat");
    for(f=0;f<n;f++) {
        wt=Q[f].ft-Q[f].bt-Q[f].at;
        Q[f].tat=Q[f].ft-Q[f].at;
        Q[f].ntat=(float)Q[f].tat/Q[f].bt;
        antat+=Q[f].ntat;
        atat+=Q[f].tat;
        awt+=wt;
        printf("\n%s\t%d\t\t%d\t%d\t%d\t%d %f",
        Q[f].na, Q[f].at, Q[f].bt, Q[f].ft, Q[f].tat, wt, Q[f].ntat);
    }
    antat/=n;
    atat/=n;
    awt/=n;

    printf("\nAverage turn around time: %f", atat);
    printf("\nAverage normalised tat is %f", antat);
    printf("\nAverage waiting time is %f", awt);
    getch();

}