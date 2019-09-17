#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void add_space(char *str)
{
    char buff[255] = "", old[255]="";
    int i, j;
    for(i=0,j = strlen(str); i<j; i++) //loop = length of word
    {
        if(strchr("+-*/^()",str[i]) != NULL)//find operator in string
            sprintf(buff,"%s %c ",old,str[i]);//save string "(string) (operator)"
        else
            sprintf(buff,"%s%c",old,str[i]);////Just keep string in buff
        strcpy(old,buff);
    }
    strcpy(str,buff);//copy string in pointer
}

int string_segment(char word[][100], char *buff)
{
    char *token;
    int count=0;
    token = strtok(buff," "); //Separate word by space
    while (token!=NULL)				
    {
        strcpy(word[count++],token);//Copy token to word
        token = strtok(NULL," ");  //Separate NULL by space
    }
    return count;
}

int is_function (char *word)
{
    int i;
    char fname[11][10] = {"sin","cos","tan","asin","acos","atan","sqrt","pow","log","exp"} ;
    for(i=0; i<10; i++) //loop for check function and word
    {
        if(strcmp(fname[i],word)==0)		//compare string and function
            return 1;
    }
    return 0;
}

int is_operator (char *word)
{
    int i;
    char fname[8][7] = {"+","-","*","/","^","(",")"} ;
    for(i=0; i<7; i++)  //loop for check operator and word
    {
        if(strcmp(fname[i],word)==0)  //compare string and operator
            return 1;
    }
    return 0;
}

int is_realnum (char *word){
    int i, count_dot=0;
    for(i=0; i<strlen(word); i++)	//loop = length of word
    {
        if(isdigit(word[i])==0 && word[i]!='.')
            return 0;
        if(word[i]=='.') count_dot++; //count_dot for check Ex. 1.1.1.
    }
    if(count_dot>1)
        return 0;
    else
		return 1;
}

int is_identi(char *word){
    int i;
    if(isdigit(word[0]))
        return 0;
    for(i=0;i<strlen(word);i++){ //loop = length of word
       if(isalpha(word[i])==0 && word[i]!='_' && isdigit(word[i])==0) //check Identifier
            return 0;
    }
    return 1;
}

int main ()
{
    while(1){
    char str[100],buff[100],sho[100],word[100][100],word_show[100][100],k;
    int i,len,count,mean[5][100], count_mean[5] = {0},check,typ[10000];
	printf("Enter Your strings : ");
    gets(str);
    strcpy(buff,str); //copy string to check
    strcpy(sho,str); //copy string to show
    strlwr(buff); //do string to low string
    add_space(buff); //add space to string check
    add_space(sho); //add space to string show
    printf("Your string is : %s",sho);
    string_segment(word_show,sho);
    count = string_segment(word,buff);  //check count number
        	if(count==1)
				if(strcmp(word[i],"end")==0||strcmp(word[i],"exit")==0)		//ckeck str == end or exit for end program
    				return 0;
   		
    printf("\ncount : %d \n",count); //show count string
    printf("=================================\n");
    for(i=0; i<count; i++)//loop to count
    {		
        check = is_function(word[i]); //check string[i]==function ?
        if(check == 1){
		mean[0][count_mean[0]++] = i; // mean[0][]<==count_mean[0]++  == i 
		typ[i]=0;					  // tpy array [i] = 0 
		}
        if(!check)
        {
            check = is_operator(word[i]);
            if(check == 1){
			mean[1][count_mean[1]++] = i; // mean[1][]<==count_mean[1]++ == i 
			typ[i]=1; // tpy array [i] = 1
			}
        }
        if(!check)
        {
            check = is_realnum(word[i]);
            if(check == 1){
			mean[2][count_mean[2]++] = i; // mean[2][]<==count_mean[2]++ == i 
			typ[i]=2; // tpy array [i] = 2
			}         
        }
        if(!check)
        {
            check = is_identi(word[i]);
            if(check == 1){
				mean[3][count_mean[3]++] = i; // mean[3][]<==count_mean[3]++ == i 
				typ[i]=3; // tpy array [i] = 3 
			}
        }
        if(!check)
        {
                mean[4][count_mean[4]++] = i; // mean[4][]<==count_mean[4]++ == i 
                typ[i]=4; // tpy array [i] = 4 
        }
        
        printf("| %10s   |",word_show[i]); //show string word_show[i]
        if(typ[i]==0)						// check tpy == 0?
        	printf("   Function     |\n");	// print typ of string
        else if(typ[i]==1)					// check tpy == 1?
        	printf("   Operater     |\n");	// print typ of string
        else if(typ[i]==2)					// check tpy == 2?
        	printf("   Number       |\n");	// print typ of string
        else if(typ[i]==3)					// check tpy == 3?
        	printf("   Identifier   |\n");	// print typ of string
        else if(typ[i]==4)					// check tpy == 4?
        	printf("   Errer        |\n");	// print typ of string
    }
    printf("=================================");
    printf("\nFunction   %3d  : ",count_mean[0]);
    for(i=0;i<count_mean[0];i++)	//loop print string is function in mean[0]
        printf("%s ",word_show[mean[0][i]]);
    printf("\nOperater   %3d  : ",count_mean[1]);
    for(i=0;i<count_mean[1];i++)	//loop print string is function in mean[1]
        printf("%s ",word_show[mean[1][i]]);
    printf("\nNumber     %3d  : ",count_mean[2]);
    for(i=0;i<count_mean[2];i++)	//loop print string is function in mean[2]
        printf("%s ",word_show[mean[2][i]]);
    printf("\nIdentifier %3d  : ",count_mean[3]);
    for(i=0;i<count_mean[3];i++)	//loop print string is function in mean[3]
        printf("%s ",word_show[mean[3][i]]);
    printf("\nErrer      %3d  : ",count_mean[4]);
    for(i=0;i<count_mean[4];i++)	//loop print string is function in mean[4]
        printf("%s ",word_show[mean[4][i]]);
    printf("\n=====================================================\n");
	printf("Press any key to continue . . .\n");
    getch(); 	// geat string
    system("cls");	 //clear screen
    }
}
