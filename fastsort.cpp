#include<iostream>
#include<stdlib.h>
using namespace std;

void sort(int *array,int length)
{
    int i,j,k;
    for(i=0;i<=length-1;i++)
    {
        int min=array[i];
        k=i;
        for(j=i+1;j<=length-1;j++)
        {
            if(array[j]<min)
            {
                 min=array[j];
                k=j;
            }

        }
        array[k]=array[i];
        array[i]=min;


    }



}

int partition(int* a, int low,int high)
{
    int pivotal=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>pivotal) high--;
        a[low]=a[high];

        while(low<high&&a[low]<pivotal) low++;
        a[high]=a[low];


    }
    a[low]=pivotal;
    return low;
}//多层while循环是依层次出循环


void fastsort(int*a,int low,int high)
{
    if(low<high)
    {
    int pivo=partition(a,low,high);
    fastsort(a,low,pivo-1);
    fastsort(a,pivo+1,high);

    }

}
int main()
{

    int array[5]={5,1,3,4,6};
    fastsort(array,0,4);
     cout<<array[0]<<array[1]<<array[2]<<array[3]<<array[4];
}


