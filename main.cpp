#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

#define N 100

using namespace std;

string solution(char s[],char m[3])
{
    char *p;
    char r[N][N];
    char result[N]="";
    int i=1;

    //split the string and saved in a char each row separately
    p = strtok(s, "\n");
    strcpy(r[0],p);
    while(p=strtok(NULL,"\n"))
    {
        strcpy(r[i],p);
        i++;
    }

    //the program goes through all the lines one by one and saved in "result" only the text without comments
    for(int j=0;j<=i;j++)
    {
        if(p = strtok(r[j],m))
        {
            strcat(result,p);
            strcat(result,"\n");
        }

    }
    return result;
}

void p1()
{
    char s[N]="apples, pears # and bananas\ngrapes\nbananas !apples"; //input string
    char m[3]="#!"; //comment markers
    //input string and comment markers can be changed or read from the keyboard
    //I chose to run the problem on the given example
    string result = solution(s,m); //function call
    cout<<result; //display result
}

void bubbleSort(int v[], int n)
{
    int i, j;
    for (i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
        if(v[j]>v[j+1])
            swap(v[j],v[j+1]);

}

bool verify(int v[],int n)
{
    //check if there are 2 consecutive equal values in vector
    for(int i=0;i<n-1;i++)
        if(v[i]==v[i+1])
            return false;
    return true;
}

bool sudoku(int a[N][N],int n)
{
    int v[N];

    //I copied each row into a vector that I ordered in ascending order and checked if there are 2 consecutive equal values
    //if there is 2 consecutive equal values=> Sudoku is not correct => return false
    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
            v[j]=a[i][j];
         bubbleSort(v,n);
         if(verify(v,n)==false)
            return false;

    }

    //I copied each column into a vector that I ordered in ascending order and checked if there are 2 consecutive equal values
    //if there is 2 consecutive equal values=> Sudoku is not correct => return false
    for(int j=0;j<n;j++)
    {
         for(int i=0;i<n;i++)
            v[i]=a[i][j];
         bubbleSort(v,n);
         if(verify(v,n)==false)
            return false;

    }

    //I went through each box to see if there were equal values
    //if there is 2 consecutive equal values => Sudoku is not correct => return false
    int sqrt_n=sqrt(n);
    for(int i=0;i<n;i+=sqrt(n))
       for(int j=0;j<n;j+=sqrt_n)
          for(int p1=0;p1<n-1;p1++)
             for(int p2=p1+1;p2<n;p2++)
                if(a[i+p1%sqrt_n][j+p1/sqrt_n]==a[i+p2%sqrt_n][j+p2/sqrt_n])
                   return false;
    //if the function has not returned anything so far it means that Sudoku is correct => return true
    return true;
}

void p2()
{
    //input data
    int n=9;
    int a[N][N]={{7,8,4, 1,5,9, 3,2,6},{5,3,9, 6,7,2, 8,4,1},{6,1,2, 4,3,8, 7,5,9},{9,2,8, 7,1,5, 4,6,3},{3,5,7, 8,4,6, 1,9,2},
                {4,6,1, 9,2,3, 5,8,7},{8,7,6, 3,9,4, 2,1,5},{2,4,3, 5,6,1, 9,7,8},{1,9,5, 2,8,7, 6,3,4}};
    //input data can be changed or read from the keyboard
    //I chose to run the problem on the given example


    //verify if Sudoku is correct
    bool k=sudoku(a,n);
    if(k==true)
        cout<<"Correct\n";
    else
        cout<<"Wrong answer\n";
}

int main()
{
    // I created a menu to be able to choose the desired problem during the runtime

    int opt=-1;
    while(opt!=3)
    {
        cout<<"1. Strips all text that follows any of a set of comment markers passed in.\n2. Sudoku\n3. Exit\n";
        cout<<"Option:";
        cin>>opt;
        switch(opt){
        case 1: p1(); break;
        case 2: p2(); break;
        case 3: break;
        }
    }

    return 0;

}
