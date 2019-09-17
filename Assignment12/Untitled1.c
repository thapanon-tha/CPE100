#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>

int get_int(int min,int max){
    int ans;
	char ch;
 	while ((scanf("%d%c",&ans,&ch)!=2) || (ans<min) || (ans>max) || (ch!='\n' )) ///Check ans
 	{
 	    rewind(stdin); ///Clear Input Data
 		printf("Error, please enter between (%d - %d) : ",min, max); ///Ark when Invalid
 	}
 	return ans;
}

void separate_space(char *key, char *command, char parameter[][10], int *count){ /// get command and parameter
    char *token;
    token = strtok(key, " ");///separate string in token
    strlwr(token);///token to lower
    while(token != NULL){ ///loop token != Null
        if((*count)==0) strcpy(command, token);///save token[1]
        else strcpy(parameter[(*count)-1], token);///save token in parameter[count-1]
        token = strtok(NULL, " ");
        strlwr(token);
        (*count)++;///count+1
    }
    (*count)--; /// cut for parameter
}

int read_file(char *filename, int data[][10], int *row, int *col){ /// read file
    FILE *fp;
    int i, j, value;
    if((fp = fopen(filename, "r")) != NULL){ ///open and read file
        fscanf(fp, "%d",row); ///scan row
        fscanf(fp, "%d",col); ///scan col
        for(i = 0; i < *row; ++i){
            for(j = 0; j < *col; ++j){
                fscanf(fp, "%d",&value);  ///scan data and save in value
                data[i][j] = value;   ///save data in array
            }
        }
        printf("read file '%s' success\n",filename);
        fclose(fp);///close file
        return 1;
    }
    else {
        printf("cannot open file '%s' because file not found or invalid input.\n", filename);
        return 0;
    }
}

void present_data(char *parameter,int data[][10],int *row, int *col){ /// get data from matrix and show matrix
    int i, j;
    if(read_file(parameter, data, row, col)){ ///call read file function
        if(*row == 0 || *col == 0){///check row and col
            printf("file is empty.\n");
        }
        else {
            printf("%s is Matrix %dx%d\n",parameter,*row,*col);
            for(i = 0; i < *row; ++i) {
                printf("|");
                for(j = 0; j < *col; ++j) {
                    printf("%4d",data[i][j]);  /// print data in file
                }
                printf("   |");
                printf("\n");
            }
        }
    }
}

void build_file(char parameter[][10],int count){
if(count < 1) printf("too few parameter for function 'generate': generate [filename] [attribute]\n");       ///check file name and out file name
    else if(count > 1) printf("too many parameter for function 'generate': generate [filename] [attribute]\n");  ///check file name and out file name
    else {
        FILE *fp;
        fp = fopen(parameter[0],"w"); ///open file
        int row,col,value;
        printf("Enter no. row of matrix %s [0-100]: ",parameter[0]);     row = get_int(0,100); ///input row data
        printf("Enter no. column of matrix %s [0-100]: ",parameter[0]);  col = get_int(0,100); ///input col data
        printf("%s is Matrix %d x %d \n",parameter[0],row,col);         fprintf(fp,"%-3d%-3d\n",row,col);  ///save row and data in text
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                printf("input data[%d][%d]: ",i,j);
                scanf("%d",&value);  ///input data
                fprintf(fp,"%d ",value);  ///save data in file
            }
        fprintf(fp,"\n");
        }
        printf("build success\n");
        fclose(fp);  ///close file
        }
}

void show(char parameter[][10], int count){ /// show matrix
    if(count < 1) printf("too few parameter for function 'show': show [filename]\n");       ///check file name and out file name
    else if(count > 1) printf("too many parameter for function 'show': show [filename]\n"); ///check file name and out file name
    else {
        int data[10][10];
        int row, col;
        present_data(parameter[0], data, &row, &col); ///call present data function
    }
}

void transpose(char parameter[][10], int count){ /// transpose matrix
    if(count < 2) printf("too few parameter for function 'transpose': transpose [input file] [output file]\n");            ///check file name and out file name
    else if(count > 2) printf("too many parameter for function 'transpose': transpose [input file] [output file]\n");      ///check file name and out file name
    else {
        int data[10][10];
        int i, j, row, col;
        present_data(parameter[0], data, &row, &col);///show data
        FILE *fp;
        fp = fopen(parameter[1], "w");          ///create or open file
        fprintf(fp, "%d %d\n", col, row);       ///save row and col in file
        for(i = 0; i < col; ++i){
            for(j = 0; j < row; ++j){
                fprintf(fp, "%d ", data[j][i]); ///save data in file
            }
            fprintf(fp, "\n");
        }
        fclose(fp);      ///close file
        present_data(parameter[1], data, &row, &col);///show output file
    }
}

void add(char parameter[][10], int count){ /// add matrix
    if(count < 3) printf("too few parameter for function 'add': add [input file 1] [input file 2] [output file]\n");        ///check file name and out file name
    else if(count > 3) printf("too many parameter for function 'add': add [input file 1] [input file 2] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data1[10][10], data2[10][10];
        int i, j, row1, col1, row2, col2;
        present_data(parameter[0], data1, &row1, &col1); ///call present data function
        present_data(parameter[1], data2, &row2, &col2); ///call present data function
        if(row1 == row2 && col1 == col2) { ///check matrix1 = matrix2
            fp = fopen(parameter[2], "w");  /// open or create file
            fprintf(fp, "%d %d\n", row1, col2);
            for(i = 0; i < row1; ++i){
                for(j = 0; j < col2; ++j){
                    fprintf(fp, "%d ", data1[i][j] + data2[i][j]); /// save out data in file
                }
                fprintf(fp, "\n");
            }
            fclose(fp); ///close file
            present_data(parameter[2], data1, &row2, &col1);///call precent data output
        }
        else printf("cannot add matrix because two matrix are not same dimension.\n");
    }
}

void subtract(char parameter[][10], int count){ /// subtract matrix
    if(count < 3) printf("too few parameter for function 'subtract': subtract [input file 1] [input file 2] [output file]\n");        ///check file name and out file name
    else if(count > 3) printf("too many parameter for function 'subtract': subtract [input file 1] [input file 2] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data1[10][10], data2[10][10];
        int i, j, row1, col1, row2, col2;
        present_data(parameter[0], data1, &row1, &col1);///show data from file1
        present_data(parameter[1], data2, &row2, &col2);///show data from file2
        if(row1 == row2 && col1 == col2) {///check row and col between file
            fp = fopen(parameter[2], "w");///create or open file
            fprintf(fp, "%d %d\n", row1, col2);
            for(i = 0; i < row1; ++i){
                for(j = 0; j < col2; ++j){
                    fprintf(fp, "%d ", data1[i][j] - data2[i][j]);///sace output data in file
                }
                fprintf(fp, "\n");
            }
            fclose(fp);///close file
            present_data(parameter[2], data1, &row2, &col1);///show output data
        }
        else printf("cannot subtract matrix because two matrix are not same dimension.\n");
    }
}

void scalar_multiplication(char parameter[][10], int count){ /// subtract matrix
    if(count < 2) printf("too few parameter for function 'scalarmultiplication': scalarmultiplication [input file 1] [output file]\n");        ///check file name and out file name
    else if(count > 2) printf("too many parameter for function 'scalarmultiplication': scalar_multiplication [input file 1] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data[10][10];
        int i, j, row, col;
        present_data(parameter[0], data, &row, &col); ///call precent data
            printf("input scalar :");
            int sa=get_int(-10000000,1000000);  ///input scalar
            fp = fopen(parameter[1], "w");      ///open or create file
            fprintf(fp, "%d %d\n", row, col);
            for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                    fprintf(fp, "%d ", data[i][j] * sa); ///save output in file
                }
                fprintf(fp, "\n");
            }
            fclose(fp);///close file
            present_data(parameter[1], data, &row, &col);///show output data
    }
}

int  Matrix_Multiplication(char parameter[][10], int count) {
     if(count < 3) printf("too few parameter for function 'matrixmultiplication': matrixmultiplication [input file 1] [input file 2] [output file]\n");        ///check file name and out file name
    else if(count > 3) printf("too many parameter for function 'matrixmultiplication': matrixmultiplication [input file 1] [input file 2] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data1[10][10],data2[10][10],data3[10][10];
        int i, j,m, row1, col1,row2, col2,row3, col3;
        present_data(parameter[0], data1, &row1, &col1);
        present_data(parameter[1], data2, &row2, &col2);
        if (col1 == row2) {
            row3 = row1;
            col3 = col2;
            fp = fopen(parameter[2], "w");      ///open or create file
            fprintf(fp, "%d %d\n", row3, col3);
            for (i =0; i < row3; i++){
                for (j=0; j< col3; j++){
                    for (data3[i][j] = 0,m = 0; m < col1; m++){
                        data3[i][j] = data3[i][j]+data1[i][m]*data2[m][j];
                    }
                 fprintf(fp, "%d ",data3[i][j]);
                }
            fprintf(fp, "\n");
            }
        fclose(fp);
        present_data(parameter[2], data3, &row3, &col3);
        }
        else {
            printf("Can't Multiply Matrix [col[A]=row[B]]\n");
        }
    }
}



void  help_user(){
    printf("===========================================================================================================================\n");
    printf("| >'generate'(g) [filename] [attribute]                                   | create file text and data                     |\n");
    printf("| >'show' [filename]                                                      | show data in file                             |\n");
    printf("| >'transpose'(t) [input file] [output file]                              | transpose file input to output                |\n");
    printf("| >'add'(a) [input file 1] [input file 2] [output file]                   | add matrix between file input to output       |\n");
    printf("| >'subtract'(s) [input file 1] [input file 2] [output file]              | subtract matrix between file input to output  |\n");
    printf("| >'scalarmultiplication'(sm) [input file 1] [output file]                | multiply matrix between scalar input to output|\n");
    printf("| >'matrixmultiplication'(mm) [input file 1] [input file 2] [output file] | multiply matrix between file input to output  |\n");
    printf("| >'cls'                                                                  | clear screen                                  |\n");
    printf("===========================================================================================================================");
    printf("\n\n");
}

int main(){
    char key[100], command[10], parameter[3][10];
    int count;
    help_user();
    do{
        count = 0;
        printf("Users:\\command>");
        gets(key);
        separate_space(key, command, parameter, &count);
        if(strlen(key)){ /// select commands
            if(strcmp(command, "show")==0) show(parameter, count);
            else if(strcmp(command, "generate")==0 || strcmp(command, "g")==0)
                build_file(parameter, count);
            else if(strcmp(command, "transpose")==0|| strcmp(command, "t")==0)
                transpose(parameter, count);
            else if(strcmp(command, "add")==0 || strcmp(command, "a")==0)
                add(parameter, count);
            else if(strcmp(command, "subtract")==0 || strcmp(command, "s")==0)
                subtract(parameter, count);
            else if(!strcmp(command, "scalarmultiplication") || !strcmp(command, "sm"))
                scalar_multiplication(parameter, count);
            else if(!strcmp(command, "matrixmultiplication") || !strcmp(command, "mm"))
                Matrix_Multiplication(parameter, count);
            else if(strcmp(command, "cls")==0){
                system("cls"); help_user();}
            else if(strcmp(command, "end") && strcmp(command, "exit"))
                printf("%s is not a command.\n", command);
        }

    }while(strcmp(command, "end") && strcmp(command, "exit"));
    return 0;
}
