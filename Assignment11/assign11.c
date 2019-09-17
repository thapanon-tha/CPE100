#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//Define Structure
typedef struct grade_info{
        long long id;
        char name[40];
        double mid,fnal,atten,total,gpoint;
        char grade[3];
    }gradetype;

int getint(int min,int max){
    int a;
    char l;
    while(scanf("%d%c",&a,&l)!=2||l!='\n'||(a<min)||(a>max)) //get number and check
    {
        rewind(stdin);                                      // rewind Valua
        printf("Error,please enter between %d-%d",min,max);
        printf("\nPlease input number again =");
    }
    return a;   // return Valua
}

void Load_Student_File(gradetype str[],int *strcount,char *file_check){
    FILE *fp;
    gradetype x;
        if((fp = fopen("score.csv","r")) != NULL)       //open  file
        {
            *strcount = 0;
            while(fscanf(fp,"%llu,%[^,],%lf,%lf,%lf",&x.id,x.name,&x.mid,&x.fnal,&x.atten) == 5) // read file
                {
                    x.total = x.mid + x.fnal + x.atten;     //calcurate x.total
                    str[(*strcount)++] = x;                 //keep x in str
                }
            fclose(fp);                                     // close file
            printf("\nTotal read %d records.",*strcount);   // show strcount
            *file_check='y';                                // file_check=y
        }
        else
            printf("\nError Can't Read File score.csv\n");

	printf("\n\nPress any key to menu . . .\n");
        getch();                                            // get char
        system("cls");                                         // clear screen
}

int get_menu(){
    int select;
    printf("\n=================================================\n");
    printf("*                     Function                  *\n");
    printf("=================================================\n");
    printf("*  1. Read File & Calurate Grade                *\n");
    printf("*  2. Statistic                                 *\n");
    printf("*  3. Count Grade                               *\n");
    printf("*  4. Show Data                                 *\n");
    printf("*  5. Swap By Total                             *\n");
    printf("*  6. Swap By Name                              *\n");
    printf("*  7. Swap By ID                                *\n");
    printf("*  8. Search By Score                           *\n");
    printf("*  9. Search By Geade                           *\n");
    printf("* 10. Search By Name                            *\n");
    printf("*  0. Exit program                              *\n");

    printf("=================================================\n");
    printf("Enter menu number = ");
    select = getint(0,10);                                          //call getint
    return select;                                                  //return int
}

void Search_Score (gradetype st[], int  stcount) {
    char  ch ;
    do {
        double min, max;
        int i , count,check_c=0;

        printf(" Enter Range of min score  and max score ");
        printf("\n Enter Min :  ");
        scanf("%lf",&min);          // get min Score
        printf(" Enter Max :  ");
        scanf("%lf",&max);          // get max Score
        count = 0;
        printf("\n========================================================================================================");
        printf("\n|     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
        printf("\n========================================================================================================");
        for (i=0; i<stcount; i++){
                if (st[i].total >= min && st[i].total <= max){
                    print_data(st[i]);          // call print data
                    check_c++;                  // check data
                }
        }

        if(check_c==0)                          //check data ==0?
            printf("\nYou Have No Data ");
        printf("\n========================================================================================================");
        printf("\n\n Do you want(y) to search again ? : ");
        ch = getch();   //get char
        system("cls");  //clear screen
        } while (ch == 'y'||ch == 'Y');//checl ch == y,Y ?
}

void cal_gread(gradetype st[],int stcount,int g_count[8],double *gpa_total){
    int i=0;
    for(i=0;i<stcount;i++){
        if(st[i].total>=83){            // check total score
            strcpy(st[i].grade,"A");    // keep A in st[i]
            st[i].gpoint=4.0;           // keep 4 in grade point
            g_count[0]++;               // g_count[0]+1
        }
        else if(st[i].total>=78){        // check total score
            strcpy(st[i].grade,"B+");    // keep B+ in st[i]
            st[i].gpoint=3.5;              // keep 3.5 in grade point
            g_count[1]++;                // g_count[1]+1
        }

        else if(st[i].total>=70){        // check total score
            strcpy(st[i].grade,"B");    // keep B in st[i]
            st[i].gpoint=3;             // keep 3 in grade point
            g_count[2]++;                // g_count[2]+1
        }

        else if(st[i].total>=65){        // check total score
            strcpy(st[i].grade,"C+");   // keep C+ in st[i]
            st[i].gpoint=2.5;           // keep 2.5 in grade point
            g_count[3]++;                // g_count[3]+1
        }

        else if(st[i].total>=50){        // check total score
            strcpy(st[i].grade,"C");    // keep C in st[i]
            st[i].gpoint=2;             // keep 2 in grade point
            g_count[4]++;                // g_count[4]+1
        }

        else if(st[i].total>=40){        // check total score
            strcpy(st[i].grade,"D+");   // keep D+ in st[i]
            st[i].gpoint=1.5;              // keep 1.5 in grade point
            g_count[5]++;                // g_count[5]+1
        }

        else if(st[i].total>=35){        // check total score
            strcpy(st[i].grade,"D");    // keep D in st[i]
            st[i].gpoint=1;             // keep 1 in grade point
            g_count[6]++;                // g_count[6]+1
        }

        else{
            strcpy(st[i].grade,"F");    // keep F in st[i]
            st[i].gpoint=0;             // keep 0 in grade point
            g_count[7]++;                // g_count[7]+1
        }
    *gpa_total=*gpa_total+st[i].gpoint;  // calcurate gpa tptal
    }
    *gpa_total=*gpa_total/stcount;        // calcurate gpa tptal in %
}

void print_data(gradetype x){
    printf("\n| %llu | %-40s | %5.1lf | %5.1lf | %5.1lf | %5.1lf |   %-3s | %2.1lf |",x.id,x.name,x.mid,x.fnal,x.atten,x.total,x.grade,x.gpoint);  // print data
}

void Print_All_Data(gradetype x[],int count){
    if(count>0){    //check count data
    printf("\n========================================================================================================");
    printf("\n|     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
    printf("\n========================================================================================================");
    for(int i=0;i<count;i++)
    {
    print_data(x[i]);       // call Function print data
    }
    printf("\n========================================================================================================");
    }
    else{
        printf("\nYou Have No Data");
    }
}

void Search_Name (gradetype st[], int  stcount) {
     char key[16];
     int i, count;
      do {
        int check_c=0;
        printf("\n Enter Search key (0 = Exit)  : ");
        scanf("%15s", key);     //get string
        count = 0;
        strupr(key);            // string uper
        if (strcmp(key,"0") != 0){  //check string !=0
            printf("\n========================================================================================================");
            printf("\n|     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
            printf("\n========================================================================================================");
            for (i = 0; i<stcount; i++)
                if (strstr(st[i].name, key) != NULL){   // check data and string
                print_data(st[i]);                      // call print data
                check_c++;                              // check_c ++
            }
         if(check_c==0)         //check check_c==0?
            printf("\nYou Have No Data ");
            printf("\n========================================================================================================");
        }
        } while (strcmp(key,"0")!=0);//check key == 0 ?
        system("cls");  //clear screen
}

void Search_Grade (gradetype st[], int  stcount){
    char key[3];
    int i , count ;
    do {
        int check_c=0;
        printf("\n Search Grade (A, B+, B, C+, C, D+, D, F (0 = Exit) ");
        scanf("%2s", key);  //get string
        count = 0;
        strupr(key);        // string uper
        if (strcmp(key,"0") != 0)       //check string
        printf("\n========================================================================================================");
        printf("\n|     ID      |                      Name                |   MID | FINAL | ATTEN | TOTAL | GRADE | GPA |");
        printf("\n========================================================================================================");
            for (i = 0; i<stcount; i++){
                if (strcmp(st[i].grade,key)==0){    //check data
                    print_data(st[i]);              //call print data
                    check_c++;                      //check_c ++
                }
            }
         if(check_c==0) //check check_c ==0?
            printf("\nYou Have No Data ");
        printf("\n========================================================================================================");
    }while (strcmp(key, "0") !=0);  //check key == 0?
    system("cls");      //clear screen
}

int cmpname(const void *a,const void *b) {
    char x[40],y[40];
    int i;
    strcpy(x,((gradetype *)a)->name);
    strcpy(y,((gradetype *)b)->name);
    i = strcmp(x,y);
    return i; }

void Sort_by_name (gradetype st[], int stcount) {
    qsort(st,stcount,sizeof(gradetype),cmpname);//qsort data
    Print_All_Data(st,stcount); //call print all data
    printf("\n\nPress any key to menu . . .\n");
        getch(); //get char
        system("cls");//clear screen
}

void Sort_by_total(gradetype st[],int stcount) {
     int i, j ;
     gradetype x;
     for (i = 0; i < stcount-1; i++)
         for (j = i+1; j < stcount; j++)
           if (st[j].total > st[i].total){  //check by total score
                x = st[i];      //swap data
                st[i] = st[j];
                st[j] = x;
            }
    Print_All_Data(st,stcount); //call print all data
    printf("\n\nPress any key to menu . . .\n");
    getch(); //get char
    system("cls");//clear screen
}

void Sort_by_id (gradetype st[], int stcount) {
    int i, j ;
    gradetype x;
    for (i = 0; i < stcount-1; i++)
        for (j = i+1; j < stcount; j++)
            if (st[j].id < st[i].id) { // check by id
                x = st[i];      //swap data
                st[i] = st[j];
                st[j] = x;
            }
    Print_All_Data(st,stcount);//call print all data
    printf("\n\nPress any key to menu . . .\n");
        getch();    //get char
        system("cls");//clear screen
}

void Find_Statistic( gradetype  st[], int stcount, double min, double max, double mean,double sd,double min_mid, double max_mid, double mean_mid, double sd_mid ,double min_fin, double max_fin, double mean_fin, double sd_fin,double min_atn, double max_atn, double mean_atn, double sd_atn,double gpa_total){
    int i;
    double sum=0, sumsqr=0;
    double sum_mid=0, sumsqr_mid=0;
    double sum_fin=0, sumsqr_fin=0;
    double sum_atn=0, sumsqr_atn=0;
    min = max = st[0].total ;
    min_mid = max_mid = st[0].mid ;
    min_fin = max_fin = st[0].fnal ;
    min_atn = max_atn = st[0].atten ;
    //check min,max,sum,sumsqr in table
    for (i=0; i<stcount; i++){
            if (st[i].total < min)
                min = st[i].total;
            if (st[i].total > max)
                max = st[i].total;
            sum = sum+st[i].total;
            sumsqr = sumsqr + pow(st[i].total,2);
             }
    for (i=0; i<stcount; i++){
            if (st[i].mid < min_mid)
                min_mid = st[i].mid;
            if (st[i].mid > max_mid)
                max_mid = st[i].mid;
            sum_mid = sum_mid+st[i].mid;
            sumsqr_mid = sumsqr_mid + pow(st[i].mid,2);
             }
    for (i=0; i<stcount; i++){
            if (st[i].fnal < min_fin)
                min_fin= st[i].fnal;
            if (st[i].fnal > max_fin)
                max_fin = st[i].fnal;
            sum_fin = sum_fin+st[i].fnal;
            sumsqr_fin = sumsqr_fin + pow(st[i].fnal,2);
             }
    for (i=0; i<stcount; i++){
            if (st[i].atten < min_atn)
                min_atn = st[i].atten;
            if (st[i].atten > max_atn)
                max_atn = st[i].atten;
            sum_atn = sum_atn+st[i].atten;
            sumsqr_atn = sumsqr_atn + pow(st[i].atten,2);
             }
    //cal mean
    mean  = sum/stcount;
    mean_mid  = sum_mid/stcount;
    mean_fin  = sum_fin/stcount;
    mean_atn  = sum_atn/stcount;
    //cal SD
    sd = sqrt(((sumsqr/stcount) - pow(mean, 2)));
    sd_mid = sqrt((sumsqr_mid/stcount) - pow(mean_mid, 2));
    sd_fin = sqrt((sumsqr_fin/stcount) - pow(mean_fin, 2));
    sd_atn = sqrt((sumsqr_atn/stcount) - pow(mean_atn, 2));
    //print data from calcurate
    printf("\n==================================================");
    printf("\n|  Score |   Mid   |  Final  |  Atten  |  Total  |");
    printf("\n==================================================");
    printf("\n|  Min   |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |",min_mid,min_fin,min_atn,min);
    printf("\n|  Max   |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |",max_mid,max_fin,max_atn,max);
    printf("\n|  Mean  |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |",mean_mid,mean_fin,mean_atn,mean);
    printf("\n|  SD    |  %5.2lf  |  %5.2lf  |  %5.2lf  |  %5.2lf  |",sd_mid,sd_fin,sd_atn,sd);
    printf("\n==================================================");
    printf("\nGPA = %.2lf",gpa_total);

    printf("\n\nPress any key to menu . . .\n");
    getch();//get char
    system("cls");  //clear screen
}

void grade_count(int g_count[]){
        printf("\n====================");
        printf("\n| GRADE | A  | %3d | ",g_count[0]);
        printf("\n| GRADE | B+ | %3d | ",g_count[1]);
        printf("\n| GRADE | B  | %3d | ",g_count[2]);
        printf("\n| GRADE | C+ | %3d | ",g_count[3]);
        printf("\n| GRADE | C  | %3d | ",g_count[4]);
        printf("\n| GRADE | D+ | %3d | ",g_count[5]);
        printf("\n| GRADE | D  | %3d | ",g_count[6]);
        printf("\n| GRADE | F  | %3d | ",g_count[7]);
        printf("\n====================");
        printf("\n\nPress any key to menu . . .\n");
        getch();        //get char
        system("cls");//clear screen
}

int main(){
    gradetype str[100];
    int count,i,menu;
    int g_count[8]={0};
    double min,max,mean,sd,
           min_mid,max_mid,mean_mid,sd_mid,
           min_fin,max_fin,mean_fin,sd_fin,
           min_atn,max_atn,mean_atn,sd_atn,gpa_total=0;
    char file_check='n';
    do{
        menu=get_menu();
        if(menu==1){     // check menu
            Load_Student_File(str,&count,&file_check);  //call Load Data
            cal_gread(str,count,g_count,&gpa_total);    //call cal grade
        //printf("%lf",gpa_total);
        }
        if(menu==2){    // check menu
            if(file_check=='y'){     // check file_check == y ?
            Find_Statistic(str,count,min,max,mean,sd,
                   min_mid,max_mid,mean_mid,sd_mid,
                   min_fin,max_fin,mean_fin,sd_fin,
                   min_atn,max_atn,mean_atn,sd_atn,gpa_total ); // call cal statistic
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();        //get char
                system("cls");  //clear screen
            }
        }
        if(menu==3){    // check menu

            if(file_check=='y'){     // check file_check == y ?
            grade_count(g_count);   ////call grade_count
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();    //get char
                system("cls");//clear screen
            }
        }
        if(menu==4){    // check menu
            if(file_check=='y'){     // check file_check == y ?
                Print_All_Data(str,count); //call print all data
            }
            else{
                printf("\n Please read file before");
            }
            printf("\n\nPress any key to menu . . .\n");
            getch();//get char
            system("cls");//clear screen
        }
        if(menu==5){    // check menu
            if(file_check=='y'){     // check file_check == y ?
                Sort_by_total(str,count);   //call Sort_by_total score
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();//get char
                system("cls");//clear screen
            }
        }
        if(menu==6){    // check menu
            if(file_check=='y'){     // check file_check == y ?
                Sort_by_name(str,count);    //call Sort_by_name
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();//get char
                system("cls");//clear screen
            }
        }
        if(menu==7){    // check menu
            if(file_check=='y'){     // check file_check == y ?
                Sort_by_id(str,count);  //call Sort_by_id
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();//get char
                system("cls");//clear screen
            }
        }
        if(menu==8){    // check menu
            if(file_check=='y'){     // check file_check == y ?
                Search_Score(str,count);    //call Search_Score
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();//get char
                system("cls");//clear screen
            }
        }
        if(menu==9){    // check menu
            if(file_check=='y'){     // check file_check == y ?
                Search_Grade(str,count);    //call Search_Grade
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();//get char
                system("cls");  //clear screen
            }
        }
        if(menu==10){   // check menu
            if(file_check=='y'){    // check file_check == y ?
                Search_Name(str,count); //call Search_Name
            }
            else{
                printf("\n Please read file before");
                printf("\n\nPress any key to menu . . .\n");
                getch();    //get char
                system("cls");  //clear screen
            }
        }

    }while(menu!=0);//check munu!=0?
return 0;
}
