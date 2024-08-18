#include <stdio.h>

void search(int data[],int i,int MAX,int x)
{
    if (data[i]==x)
    {
        printf("Number Found");
    }
    else if (i>=MAX)
    {
        printf("Number Not Found");
    }
    else
    {
        search(data,i+1,MAX,x);
    }
}

int main()
{
    int flag = 0,i,MAX=10,x;
    int data[MAX];
    printf("Enter Numbers: ");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("Search A Number: ");
    scanf("%d", &x);
    search(data,0,MAX,x);
    return 0;
}