#include<stdio.h>
    int get_int(int min, int max)
    {
    int num;
    char ch;
    while (scanf("%d%c",&num,&ch) == 0 || ch!='\n' || num>max || num<min)
                {
                    rewind(stdin);
                    printf("Invalid input, please try again : ");
                }
    return num;
    }

    int GCD(int n1,int n2){
    int ans,temp;
       if ( n2 > n1)
        {
        int temp = n2;
        n2 = n1;
        n1 = temp;
        }
    for (int i=1; i<=n2;i++)
        {
        if (n1%i==0&&n2%i==0)
            {
            ans = i;
            }
        }
    return ans;
    }

    int fibonacci(int n)
    {
        int ans[50];
        ans[0]=0;
        ans[1]=1;
        ans[2]=1;
        if(n>1){
        for(int i=2 ;i<=n ;i++ ){
            ans[i]=ans[i-2]+ans[i-1];
        }
        }
        return ans[n];
    }

    int fac(int n)
    {
        int ans=1;
        for(int i=1;i<=n;i++)
            {
            ans=ans*i;
            }
        return ans;
    }

    int Combination(int n1,int n2)
    {
        int ans;
          ans = fac(n1)/(fac(n1-n2)*fac(n2));
        return ans;
    }

    int get_menu()
    {
    int select;
    printf(" ***********************************************\n");
    printf(" *               My Test function              *\n");
    printf(" ***********************************************\n");
    printf(" *   1. Fibonacci function                     *\n");
    printf(" *   2. Combination number                     *\n");
    printf(" *   3. Find GCD(x,y)                          *\n");
    printf(" *   4. Factorial                              *\n");
    printf(" *   0. exit                                   *\n");
    printf(" ***********************************************\n");
    printf(" Enter menu number :  ");
    select = get_int(0,4);
    return select;
    }

    int main() {
    int select, n, r, ans, n1, n2;
        do{
            select = get_menu();
            printf("\n");
             if (select==1)
             {
              printf("Calculate fibonaccinumber\n");
              printf("Enter fibonacciterm f(n)[0-45] :  ");
              n = get_int(0,45);
              ans = fibonacci(n);
              printf("fibonacciterm f(%d) = %d \n\n",n,ans);
             }

             else if (select==2)
              {
              printf("Combination number \n");
              printf("Enter The Total Number of[0-14] :  ");
              n1 = get_int(0,12);
              printf("Enter you need to select[0-%d] :  ",n1);
              n2 = get_int(0,n1);
              ans = Combination(n1,n2);
              printf("Combination = %d \n\n",ans);
              }

             else if (select==3)
             {
              printf("Calculate GCD\n");
              printf("Enter First Number [0-99] :  ");
              n1 = get_int(0,99);
              printf("Enter Second Number [0-99] :  ");
              n2 = get_int(0,99);
              ans = GCD(n1,n2);
              printf("GCD = %d \n\n",ans);
             }

             else if (select==4)
             {
              printf("Calculate Factorial\n");
              printf("Enter Number [0-12] :  ");
              n1 = get_int(0,12);
              ans = fac(n1);
              printf("%d! = %d \n\n",n1,ans);
             }

            }
            while(select != 0);
    }






































	.


