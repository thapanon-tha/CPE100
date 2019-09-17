#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int getint(int min,int max)
{
    int a;
    char l;
    while(scanf("%d%c",&a,&l)!=2||l!='\n'||(a<min)||(a>max))
    {
        rewind(stdin);
        printf("Error,please enter between %d-%d",min,max);
        printf("\nPlease input number again =");
    }
    return a;
}

double getdouble(int min)
{
    double a;
    char l;
    while(scanf("%lf%c",&a,&l)==0||l!='\n'||(a<min))
    {
        rewind(stdin);
        printf("Error,please enter more %d",min);
        printf("\nPlease input number again =");
    }
    return a;
}

int get_menu()
{
    int select;
    printf("\n================================================\n");
    printf("*                My Test Function              *\n");
    printf("================================================\n");
    printf("* 1. Add Data                                  *\n");
    printf("* 2. Delete Data                               *\n");
    printf("* 3. Calculate                                 *\n");
    printf("* 4. Show Data                                 *\n");
    printf("* 0. Exit program                              *\n");
    printf("================================================\n");
    printf("Enter menu number = ");
    select = getint(0,4);
    return select;
}


void Read_Data_Array(double data[],int*count){
 	double a;
 	printf("\nEnter Data =");
 	while(scanf("%lf",&a)==1){
  		data[*count]=a;
  		printf("data[%d]=%g\n",*count,data[*count]);
  		*count=*count+1;
 	}
 	rewind(stdin);
 	printf("End of input\n");
}


void Add_Data(double data[],int*count) {
	int i; 
 	double  a; 
 	char ch;
	printf("Enter Number : "); 
 	do {
	 	i= scanf("%lf%c",&a,&ch); 
 		if (a>0&&i>0) { //check a & i > 0
 			data[*count] = a;  //keep a in data[*count]
 			*count = *count +1; //(*count)++
 		}
		else printf("\nInvalid input\n\n");
		}	  
 while (i!=0 && ch!='\n'); 
 rewind(stdin);
}

void Print_All_Data(double data[],int count){
	int i;
	printf("######################################\n");
 	if(count==0) printf("No data\n");
	else for(i=0;i<count;i++){
  			printf("Data[%d]=%g\n",i,data[i]);
 		}
 	printf("######################################\n");
}

void delete_data(int n,double data[],int *count){
	int i,pos;
	char ch,chack=n;
	for(i = 0;i<*count;i++){ //loop = Amount of data
		if(data[i]==n){ 
			printf("Want delete %d at data[%d] ?: ",n,i);
			scanf(" %c",&ch);
			while(ch!='y'&&ch!='n'){ //check yes or no
				printf("try again : ");
				scanf(" %c",&ch);
			}
			if(ch=='y'){ 
				pos=i;
				while(pos < *count){
				data[pos]=data[++pos]; //keep data[i++] in data[i]
				}	
				(*count)--;
				i--; //i-- for check 
				printf("Deleted\n");
			}
			else {
				printf("Cancaled Delete\n");
			}
			chack='y'; //delet Success
		}
	}
	if(chack=='n')	printf("The Number doesn't Deleted\n"); //delet fail
}

void  Calc_Statistic (double data[], int count, double *min, double *max, double *mean, double *sd ) {
 	int i; 
 	double sum1 = 0, sum2 = 0; 
 	*min = *max = data[0] ; 
 	for (i=0; i<count; i++) { 
 		if (data[i] < *min) *min = data[i] ; 
 		if (data[i] > *max) *max = data[i]; 
 		sum1 = sum1+data[i]; 
 		sum2 = sum2+data[i]*data[i]; 
 	} 
 	*mean = sum1/count; 
 	*sd = sqrt(sum2/count - pow(*mean,2)); 
 }

int main()
{
 	double data[100];
 	int count=0;
 	int select;
 	double mean,sd,max,min;
 	do
 	{
  		select = get_menu();
  		if(select==1){
  			//system("cls");
  			Add_Data(data,&count);
  			Print_All_Data(data,count);
     	}
     	else if (select==2){
     		//system("cls");
     	if(count<1) printf("No Data\n");
  		else{
		printf("Enter Data to Deleted : ");
		int en;
		en = getdouble(0);
		delete_data(en,data,&count);
		Print_All_Data(data,count);
			}
		}
  		else if(select==3){
  			//system("cls");
  			if(count<2) printf("Data Less than 2 or No Data\n");
  			else{
  			 Calc_Statistic(data,count,&min,&max,&mean,&sd );
  			 printf("MIN is : %g\n",min);
			 printf("MAX is : %g\n",max);
			 printf("MEAN is : %g\n",mean);
			 printf("SD is : %g\n",sd);
			} 
  		}
  		else if(select==4){
  			//system("cls");
  			Print_All_Data(data,count);
		}	
    }while(select!=0);
    
    printf("\nEnd Program\n");
    return 0;
}
