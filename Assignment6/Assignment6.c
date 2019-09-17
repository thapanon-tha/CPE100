#include<stdio.h>
///////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////
    int fibonacci(int n)
    {
        int ans[50];
        
        ans[0]=0;
        ans[1]=1;
        ans[2]=1;
        int i;
        if(n>1){
        for(i=2 ;i<=n ;i++ ){
        	//aN=aN-1+aN-2 keep in array
            ans[i]=ans[i-2]+ans[i-1];
            
            }
        }
        return ans[n];
    }
//////////////////////////////////////////////////////////////////////
        int sum_two(int n)
        {
        int ans=0;
        int i;
        for(i=1;i<=n ;i++ ){
            ans+=i;
            }
        ans*=2;    
        return ans;
        }
/////////////////////////////////////////////////////////////////////
        int fac(int n)
        {
        int ans=1;
        int i;
        for(i=1;i<=n;i++)
            {
            ans=ans*i;
            }
        return ans;
        }
/////////////////////////////////////////////////////////////////////////
        double sum_ser(int n)
        {
            double ans;
            //call function Face and sum for calculate
            ans=sum_two(n)*1.0/fac(n)*1.0;
            return ans;
        }
 ////////////////////////////////////////////////////////////////////////////////////
    double Function_one(int n)
    {
        double i;
        double sum;
        double sum_all=0;

        printf("	**********************************\n	*   i  *      fi    *     sum    *\n	**********************************\n");
        for(i=1;i<=n;i++)
            {
        //call function sum_ser    	
		sum=sum_ser(i);
		//summary of all sum_ser function
        sum_all+=sum;
            printf("	*  %2.0lf  *  %.6lf  *  %.6lf  *\n",i,sum,sum_all);
            }
        printf("	**********************************\n");    
        return sum_all;
    }
//////////////////////////////////////////////////////////////////////////////////////
int Function_two(int n)
    {
        int i,fi,sum;
        printf("	**********************************\n	*  count   *     i    *     fi   *\n	**********************************\n");
        for(i=1;i<=n;i++)
            {
        //aN=ix3    	
        sum=i*3; 
		//call function Fibo   	
		fi=fibonacci(sum);        
            printf("	*  %6d  *  %6d  *  %6d  *\n",i,sum,fi);
            }
        printf("	**********************************\n");    
        return fi;
    }
//////////////////////////////////////////////////////////////////////////////////////
int Function_three(int min,int max,int n)
    {
        int i,fi,sum=0,count;
        printf("	**********************************\n	*    no    *     i    *    sum   *\n	**********************************\n");
       	//Find the number can mot n==0  and summary of number 
	    for(i=min;i<=max;i++)
            {
            if(i%n==0){
			count++;	
        	sum+=i;        
            printf("	*  %6d  *  %6d  *  %6d  *\n",count,i,sum);
        	}
            }
        printf("	**********************************\n");   
		printf("	Count = %d	Ans = %d \n",count,sum); 
        return sum;
    }
//////////////////////////////////////////////////////////////////////////////////////
int Function_four(int n)
    {
        int i,j,sum=0,count=0,k;
        printf("	**********************************\n	*    i     *    fi    *     sum  *\n	**********************************\n");
        //
        for(i=1,j=40; sum<=n ;i=i+2,j=j-2)
            {
           	count++;
           		//N1(Series1) * N1(Series2)
           		k=i*j;
           	//summary of function	
			   sum=sum+k;      
            printf("	*  %6d  *  %6d  *  %6d  *\n",count,k,sum);
            }
        printf("	**********************************\n");  
		printf("	n = %d	Ans = %d \n",count,sum);  
		
        return count;
    }
////////////////////////////////////////////////////////////////////////////////////////    
int Function_five(int n)
    {
        int i,count=1,sum=1;
        printf("	***********************\n	*    no    *     i    *\n	***********************\n");
        
        for(i=0;count<=n;i++)
            {
            //Same the number in Sequence1 and Sequence2 	
            if(i%15==0){
			sum=i+1;      
            printf("	*  %6d  *  %6d  *\n",count,sum);
            count++;
            }
        	}
        printf("	***********************\n");  
		 
		return n;
    }
///////////////////////////////////////////////////////////////////////////////////////
    int get_menu()
    {
    int select;
    
    printf("\n ***************************************************\n");
    printf(" *                      MENU                       *\n");
    printf(" ***************************************************\n");
    printf(" *   1.Summary Sequence/Factorial                  *\n");
    printf(" *   2.Fibonacci n Term                            *\n");
    printf(" *   3.Summary Integer Between Min and Max Mod N=0 *\n");
    printf(" *   4.Summary Series                              *\n");
    printf(" *   5.Same n in Sequence 1 and Sequence 2         *\n");
    printf(" *   0.Exit                                        *\n");
    printf(" ***************************************************\n");
    printf(" Enter menu number :  ");
    select = get_int(0,5);
    
    system("cls");
    return select;
    }

    int main() {
    int select, n, r, n1, n2, min, max;
    double  ans;
        do{
            select = get_menu();
            if (select==1)
             {
             	printf("\n ***************************************************\n");
    			printf(" *          1.Summary Sequence/Factorial           *\n");
    			printf(" ***************************************************\n");
             	printf("Enter the number : ");
                n = get_int(1,12);
                ans = Function_one(n);                
                printf("		Ans = %.6lf \n",ans);
             }

             else if (select==2)
              {
              	printf("\n ***************************************************\n");
    			printf(" *             2.Fibonacci n Term                  *\n");
    			printf(" ***************************************************\n");
				printf("Enter the number[1,10]: ");
                n = get_int(0,10);
                ans = Function_two(n);                
                printf("	Count = %d	Ans = %.0lf \n",n,ans);
              }

             else if (select==3)
             {
             	printf("\n ***************************************************\n");
    			printf(" *   3.Summary Integer Between Min and Max Mod N=0 *\n");
    			printf(" ***************************************************\n");
				printf("Enter the number[Min] : ");
				min = get_int(0,9999);
                printf("Enter the number[Max] : ");
                max = get_int(min,9999);
                printf("Enter the number : ");
                n = get_int(0,max);
				ans = Function_three(min,max,n);                
                
             }

             else if (select==4)
             {
             	printf("\n ***************************************************\n");
    			printf(" *                 4.Summary Series                *\n");
    			printf(" ***************************************************\n");
				printf("Enter the number : ");
                n = get_int(1,9999);
				Function_four(n);	                
             }

              else if (select==5)
             {
             	printf("\n ***************************************************\n");
    			printf(" *       5.Same n in Sequence 1 and Sequence 2     *\n");
    			printf(" ***************************************************\n");
				printf("Enter the number : ");
                n = get_int(1,9999);
                ans = Function_five(n);
                printf("	Count = %.0lf \n",ans); 
             }

        }
        while(select != 0);
        printf("\n ***************************************************\n");
    	printf(" *   			      End Program                  *\n");
    	printf(" ***************************************************\n");
        
    }









































