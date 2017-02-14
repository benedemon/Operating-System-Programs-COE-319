//
//  main.cpp
//  Scheduling_Algorithms
//
//  Created by Raj Singh on 14/02/17.
//  Copyright © 2017 benedemon. All rights reserved.
// RAJ SINGH
// RAJ SINGH RAJ SINGH

#include <iostream>
#include <stdio.h>

using namespace std;

class cpuschedule
{
        int n,bu[20];
        float twt,awt,wt[20],tat[20];
    public:
        void Getdata();
        void fcfs();
        void sjf();
        void roundrobin();
};

//Getting no of processes and Burst time
void cpuschedule::Getdata()
{
    int i;
    cout<<"Enter the no of processes: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter the Burst Time for Process P"<<i<<"=";
        cin>>bu[i];
    }
}

//First come First served Algorithm
void cpuschedule::fcfs()
{
    int i,b[10];
    float sum=0.0;
    twt=0.0;
    for(i=1;i<=n;i++)
    {
        b[i]=bu[i];
        cout<<"\nBurst time for process p"<<i<<" = ";
        cout<<b[i];
    }
    wt[1]=0;
    for(i=2;i<=n;i++)
    {
        wt[i]=b[i-1]+wt[i-1];
    }
    for(i=1;i<=n;i++)
    {
        twt=twt+wt[i];
        tat[i]=b[i]+wt[i];
        sum+=tat[i];
    }
    awt = twt/n;
    sum = sum/n;
    cout<<"\nTotal Waiting Time = "<<twt;
    cout<<"\nAverage Waiting Time = "<<awt;
    cout<<"\nAverage Turnaround time = "<<sum;
}

//Shortest job First Algorithm
void cpuschedule::sjf()
{
    int i,j,temp,b[10];
    float sum=0.0;
    twt=0.0;
    for(i=1;i<=n;i++)
    {
        b[i]=bu[i];
        cout<<"\nBurst time for process p"<<i<<"=";
        cout<<b[i];
    }
    for(i=n;i>=1;i--)
    {
        for(j=2;j<=n;j++)
        {
            if(b[j-1]>b[j])
            {
                temp=b[j-1];
                b[j-1]=b[j];
                b[j]=temp;
            }
        }
    }
    wt[1]=0;
    for(i=2;i<=n;i++)
    {
        wt[i]=b[i-1]+wt[i-1];
    }
    for(i=1;i<=n;i++)
    {
        twt=twt+wt[i];
        tat[i]=b[i]+wt[i];
        sum+=tat[i];
    }
    awt = twt/n;
    sum = sum/n;
    cout<<"\nTotal Waiting Time = "<<twt;
    cout<<"\nAverage Waiting Time = "<<awt;
    cout<<"\nAverage turnaround time = "<<sum;
}
//Round Robin Algorithm
void cpuschedule::roundrobin()
{
    int i,j,tq,k,b[10],Rrobin[10][10],count[10];
    int max=0;
    int m;
    float sum=0.0;
    twt=0.0;
    for(i=1;i<=n;i++)
    {
        b[i]=bu[i];
        cout<<"\nBurst time for process P"<<i<<" = ";
        cout<<b[i];
        if(max<b[i])
            max=b[i];
        wt[i]=0;
    }
    cout<<"\nEnter the Time Quantum = ";
    cin>>tq;
    //TO find the dimension of the Round robin array
    m=max/tq+1;
    //initializing Round robin array
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            Rrobin[i][j]=0;
        }
    }
    //placing value in the Rrobin array
    i=1;
    while(i<=n)
    {
        j=1;
        while(b[i]>0)
        {
            if(b[i]>=tq)
            {
                b[i]=b[i]-tq;
                Rrobin[i][j]=tq;
                j++;
            }
            else
            {
                Rrobin[i][j]=b[i];
                b[i]=0;
                j++;
            }
        }
        count[i]=j-1;
        i++;
    }
    cout<<"Display";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<"\nRr["<<i<<","<<j<<"] = "<<Rrobin[i][j];
            cout<<"     ";
        }
        cout<<"\ncount = "<<count[i];
    }
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=count[j];i++)
        {
            if(i==count[j])
            {
                for(k=1;k<j;k++)
                {
                    if(k!=j)
                        wt[j]+=Rrobin[k][i];
                }
            }
            else
                for(k=1;k<=n;k++)
                {
                    if(k!=j)
                        wt[j]+=Rrobin[k][i];
                }
        }
    }
    for(i=1;i<=n;i++)
        cout<<"\nWaiting Time for process P "<<i<<" = "<<wt[i];
    //calculating Average Weighting Time
    for(i=1;i<=n;i++)
    {
        twt=twt+wt[i];
        tat[i]=b[i]+wt[i];
        sum+=tat[i];
    }
    awt=twt/n;
    sum=sum/n;
    cout<<"\nTotal Waiting Time = "<<twt;
    cout<<"\nAverage Waiting Time = "<<awt;
    cout<<"\nAverage turnaround time = "<<sum;
}

int main()
{
    int ch=0;
    cpuschedule c;
    //clrscr();
    do
    {
        switch(ch)
        {
            case 0:
                cout<<"\nMENU";
                cout<<"\n1.Getting BurstTime";
                cout<<"\n2.FirstComeFirstServed";
                cout<<"\n3.ShortestJobFirst";
                cout<<"\n4.RoundRobin";
                cout<<"\n5.EXIT";
                break;
            case 1:
                c.Getdata();
                break;
            case 2:
                cout<<"FIRST COME FIRST SERVED SCHEDULING";
                c.fcfs();
                break;
            case 3:
                cout<<"SHORTEST JOB FIRST SCHEDULING";
                c.sjf();
                break;
            case 4:
                cout<<"ROUND ROBIN SCHEDULING";
                c.roundrobin();
                break;
            case 5:
                break;
        }
        cout<<"\nEnter your choice : ";
        cin>>ch;
    }while(ch<5);
    
    return 0;
}
