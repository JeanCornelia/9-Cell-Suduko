#include <stdio.h>
int count;
int basetable[3][3] = {0,0,0,0,0,0,0,0,0};
int graveyard[9] = {1,2,3,4,5,6,7,8,9};
void checkrepeat(int);
int checkIndexNumber(int, int);
void search();
void playagain();
void tableprint();

void checkrepeat(int difficulty)
{
    tableprint();
    for(int k = 1;k<=difficulty; k++)
    {
        int index; int number;
        printf("\nInput Index:");
        scanf("%d",&index);
        printf("Input Number(1-9):");
        scanf("%d",&number);
        if(0<index<=3)
        {
          if(checkIndexNumber(number,index)==1)
          {
              difficulty++;
          }
          else
          {
          basetable[0][index-1]=number;
          }
        }
    else if(3<index<=6 )
        {
          if(checkIndexNumber(number,index)==1)
          {
              difficulty++;
          }
          else
          {
            basetable[1][index-2]=number;
          }
        }
    else if(6<index<=9 )
        {
          if(checkIndexNumber(number,index)==1)
          {
              difficulty++;
          }
          else
          {
            basetable[2][index-5]=number;
          }
        }
        printf("\n");
        tableprint();
    }
    search();
    printf("\n\nFinal:");
    tableprint();
    printf("\n");
    playagain();
}
void search()
{
        for(int i = 0;i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
               for(int k=0;k<9;k++)
                {
                    if(basetable[i][j] == graveyard[k])
                    {
                      graveyard[k]=0;
                    }
                }
            }
        }
        for(int i = 0;i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
               for(int k=0;k<9;k++)
                {
                    if(basetable[i][j] == 0 && graveyard[k]!=0)
                    {
                      basetable[i][j]=graveyard[k];
                      graveyard[k]=0;
                    }
                }
            }
        }

}
void playagain()
{
    char answer;int difficulty;
    printf("\nPlay it again?(y/n):");
    scanf(" %c",&answer);
    if(answer == 'Y'||answer == 'y')
    {
        for(int i = 0;i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                basetable[i][j]=0;
            }
        }
        for(int i = 0; i <9;i++)
        {
            graveyard[i]=i+1;
        }
        tableprint();
    }
    else
    {
        printf("Program will now exit.");
    }
}
void tableprint()
{
    for(int i = 0;i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            if(count%3==0)
            {
                printf("\n");count=0;
            }
            count++;
            printf("%d ",basetable[i][j]);
        }
    }

}

int checkIndexNumber(int number, int index)
{
    int countIndex =0;
    for(int i = 0;i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
               for(int k=0;k<9;k++)
                {
                    if(graveyard[index-1]==0)
                    {
                      countIndex++;
                    }
                }
            }
        }
    for(int i = 0;i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
               for(int k=0;k<9;k++)
                {
                    if(basetable[i][j] == number)
                    {
                      countIndex++;
                    }
                }
            }
        }
    if(countIndex>0)
    {
        printf("Index or number is repeated. Type Again.");
        return 1;
    }
}


