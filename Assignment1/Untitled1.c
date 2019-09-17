#include <stdio.h>
#include <math.h>
int main() {
  double a,b,c,x1,x2;
  char ch;
  do{
   a=b=c=0;
   printf("\nProgram calculrete root of Equation ax^2+bx+c = 0\n");
   printf("Enter parameter a ");
   scanf("%d",&a);
   printf("Enter parameter b ");
   scanf("%d",&b);
   printf("Enter parameter c ");
   scanf("%d",&c);
   x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
   x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
   printf("root of %dx^2+%dx+%d = 0 \n",a,b,c);
   printf(" x1 = %d \n x2 = %d \n",x1,x2);
   printf("Enter y to calculate again ");
   scanf(" %c",&ch);
    }while(ch == 'y');
    printf("\n End Program \n");
  return 0;
}
