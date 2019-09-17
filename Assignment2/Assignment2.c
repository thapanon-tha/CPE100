#include <stdio.h>
#include <math.h>
int main()
{
	int k;
    double x,temp,i,j;
    char ch;
printf("Enter Value : ");
scanf("%lf",&x);
for(k=1;k<=10;k++)
	printf("    %2d%0%",k);
printf("\n");
for(i=1;i<=5;i++){
	printf("%.0lf  ",i);
	for(j=1;j<=10;j++){
		double per=pow(1+(j/100),i);
		printf("%.3lf  ",x*per);
	}
	printf("\n");
}
    return 0;
}

