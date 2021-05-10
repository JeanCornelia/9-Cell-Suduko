

#include <stdio.h>
#include "suduko.c"

int main()
{
    int num;
    printf("\n");
    printf("Enter the difficulty you want (1 - Easy , 2 - Average, 3-Hard , 4- Exit):");
    scanf("%d",&num);
    if(num==1){checkrepeat(6);}
    else if(num==2){checkrepeat(5);}
    else if(num==3){checkrepeat(4);}
    else if(num==4){"Program will not stop.";}
    else
        {
            printf("That is not in the choices.");
            main();
        }
    return 0;
}
