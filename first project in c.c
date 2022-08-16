#include<stdio.h>
#include<conio.h>
#include<string.h>
void game(int arr[][4],char str[]);
void rules();
int sort(int arr[][4]);
void move_left(int arr[][4],int i,int j);
void move_right(int arr[][4],int i,int j);
void move_up(int arr[][4],int i,int j);
void move_down(int arr[][4],int i,int j);
int left(int arr[][4]);
int right(int arr[][4]);
int up(int arr[][4]);
int down(int arr[][4]);
void display (int arr[][4]);
void game(int arr[][4],char str[])
{
    int i=50,j=1;
    char input;
    printf("\nHello %s , Move remaining : %d\n\n",str,i);
        display(arr);
    while(i)
    {
        input=getch();
        switch(input)
    {
    case -32: //This value is returned by all arrow key. So, we don't want to do something.
        break;
    case 72:
        if(up(arr))
         {
             --i;
             j=0;
         }
        if(sort(arr))
        {
            printf("YOU WIN\n\n\n");
            display(arr);
            getch();
            exit(0);
        }
        if(!j)
        {
        system("cls");
        printf("\nHello %s , Move remaining : %d\n\n",str,i);
        display(arr);
        }
        break;

    case 75:
        if(left(arr))
        {
            --i;
            j=0;
        }
        if(sort(arr))
        {
            printf("YOU WIN\n\n\n");
            display(arr);
            getch();
            exit(0);
        }
        if(!j)
        {
        system("cls");
        printf("\nHello %s , Move remaining : %d\n\n",str,i);
        display(arr);
        }
        break;

    case 77:
        if(right(arr))
         {
            --i;
            j=0;
         }
        if(sort(arr))
        {
            printf("YOU WIN\n\n\n");
            display(arr);
            getch();
            exit(0);
        }
        if(!j)
        {
        system("cls");
        printf("\nHello %s , Move remaining : %d\n\n",str,i);
        display(arr);
        }
        break;

    case 80:
        if(down(arr))
         {
            --i;
            j=0;
         }
        if(sort(arr))
        {
            printf("YOU WIN\n\n\n");
            display(arr);
            getch();
            exit(0);
        }
        if(!j)
        {
        system("cls");
        printf("\nHello %s , Move remaining : %d\n\n",str,i);
        display(arr);
        }
        break;

    case ('E') : exit(0);
    case ('e') : exit(0);
    }
}
printf("you don't win the game please try again");
exit(0);
}
void rules()
{
    system("cls");
    int arr[][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,50};
    printf("\t\t\t\t\tRULES OF THIS GAME\n\n\n");
    printf("1. You can move only 1 step at a time by arrow key\n");
    printf("MOVE UP    : by up arrow key\n");
    printf("MOVE DOWN  : by down arrow key\n");
    printf("MOVE LEFT  : by left arrow key\n");
    printf("MOVE RIGHT : by right arrow key\n\n");
    printf("2. You can move number at empty position only\n\n");
    printf("3. For each valid move : your total number of move will decreased by 1\n\n");
    printf("4. Wining situation : number in 4*4 matrix should be in order from 1 to 15\n\n");
    printf("\t\t\tWining situation\n\n");
    display(arr);
    printf("5. You can exit the game at any time by pressing 'E' or 'e'\n\n");
    printf("So try to win minimum no of move\n\n");
    printf("\t\t\tHappy gaming, Good LUCK\n\n");
    printf("Enter any key to start......");
}
int sort(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
            if(arr[i][j]>arr[i][j+1])
            return 0;
    }
    return 1;
}
void move_down(int arr[][4],int i,int j)
{
    arr[i][j]=arr[i+1][j];
    arr[i+1][j]=50;
}
int down(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]>15)
                break;
        }
        if(j<4)
            break;
    }
    if(i<3)
       {
         move_down(arr,i,j);
         return 1;
       }
       return 0;
}
void move_up(int arr[][4],int i,int j)
{
    arr[i][j]=arr[i-1][j];
    arr[i-1][j]=50;
}
int up(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]>15)
                break;
        }
        if(j<4)
            break;
    }
    if(i)
        {
          move_up(arr,i,j);
          return 1;
        }
        return 0;
}
void move_right(int arr[][4],int i,int j)
{
    arr[i][j]=arr[i][j+1];
    arr[i][j+1]=50;
}
int right(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]>15)
                break;
        }
        if(j<4)
            break;
    }
    if(j<3)
        {
         move_right(arr,i,j);
         return 1;
        }
        return 0;
}
void move_left(int arr[][4],int i,int j)
{
    arr[i][j]=arr[i][j-1];
    arr[i][j-1]=50;
}
int left(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]>15)
                break;
        }
        if(j<4)
            break;
    }
    if(j)
        {
            move_left(arr,i,j);
            return 1;
        }
            return 0;
}


void display (int arr[][4])
{
    int i,j;
    printf("---------------------------\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(!j)
            printf("|");
            if(arr[i][j]>15)
                printf("     |");
            else if(arr[i][j]<10)
            printf("  %d  |",arr[i][j]);
            else
            printf("  %d |",arr[i][j]);
        }

        printf("\n");
    }
     printf("---------------------------\n");
}
int main()
{
int arr[4][4]={5,9,10,15,12,1,13,3,7,8,4,14,6,2,11,50};
char str[30];
printf("enter your name:- ");
fflush(stdin);
fgets(str,30,stdin);
str[strlen(str)-1]='\0';
rules();
getch();
system("cls");
game(arr,str);
return 0;
}




