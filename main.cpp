#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class task
{
public:
    double preparationtime;
    double timeStart;
    double timeStop;
    string subject;
};

void createtask(task *a)
{
    double preparationtime;
    double timeStart;
    double timeStop;
    string subject;

    cout<<"Give the imfo for the task:"<<endl;
    cout<<"     Subject          : ";
    cin >> subject;
    cout<<"     preparation time : ";
    cin>>preparationtime;
    cout<<"     time to start    : ";
    cin>>timeStart;
    cout<<"     time to end      : ";
    cin>>timeStop;

    a->subject=subject;
    a->preparationtime=preparationtime;
    a->timeStart=timeStart;
    a->timeStop=timeStop;
}

void addtask(task *arr[],int len,task *t)
{
    task **copy;
    copy=(task**)malloc(len+1);
    for(int i=0; i<len; i++)
    {
        copy[i]=arr[i];
    }
    copy[len]=t;
    cout<< sizeof(arr)<<"   "<<sizeof(copy)<<"  "<<len<<endl;
    arr=copy;
}

void printarray(task **arr, int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<"Task "<<i<<": Subject:"<<arr[i]->subject<<
            " ,Start time:"<<arr[i]->timeStart<<" ,End time:"<<
            arr[i]->timeStop<<" ,preparation time:"<<arr[i]->preparationtime<<endl;
    }
}


int main()
{
    task **tasks;
    tasks=(task**)malloc(3);

    task a;
    tasks[0]=&a;
    tasks[1]=&a;

    createtask(tasks[0]);
    createtask(tasks[1]);

    addtask(tasks,sizeof(tasks)/sizeof(tasks[0]),&a);

    int len=sizeof(tasks[0])/sizeof(tasks[0]);
    printarray(tasks,len);





    return 0;
}
