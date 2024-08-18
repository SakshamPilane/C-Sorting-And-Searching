#include <stdio.h>

void search(int data[],int x)
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (data[i]==x)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        printf("Number Found");
    }
    else
    {
        printf("Number Not Found");
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
    search(data,x);
    return 0;
}