#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>

int Get_Int(int min,int max){
    int ans;
	char ch;
 	while ((scanf("%d%c",&ans,&ch)!=2) || (ans<min) || (ans>max) || (ch!='\n' )) ///Check ans
 	{
 	    rewind(stdin); ///Clear Input Data
 		printf("Error, please enter between (%d - %d) : ",min, max); ///Ark when Invalid
 	}
 	return ans;
}

void Separate_Space(char *key, char *command, char parameter[][10], int *count){ /// get command and parameter
    char *token;
    token = strtok(key, " ");///separate string in token
    strlwr(token);///token to lower
    while(token != NULL){ ///loop token != Null
        if((*count)==0) strcpy(command, token);///save token[1]
        else strcpy(parameter[(*count) - 1], token);///save token in parameter[count-1]
        token = strtok(NULL, " ");
        strlwr(token);
        (*count)++;///count+1
    }
    (*count)--; /// cut for parameter
}

int Read_File(char *filename, int data[][10], int *row, int *col){ /// read file
    FILE *fp;
    int i, j, value;
    if((fp = fopen(filename, "r")) != NULL){ ///open and read file
        fscanf(fp, "%d",row); ///scan row
        fscanf(fp, "%d",col); ///scan col
        for(i = 0; i < *row; i++){
            for(j = 0; j < *col; j++){
                fscanf(fp, "%d",&value);  ///scan data and save in value
                data[i][j] = value;   ///save data in array
            }
        }
        printf("Read file '%s' success\n",filename);
        fclose(fp);///close file
        return 1;
    }
    else {
        printf("Cannot open file '%s' [file not found or invalid input].\n", filename);
        return 0;
    }
}

void Pre_Data(char *parameter,int data[][10],int *row, int *col){ /// get data from matrix and show matrix
    int i, j;
    if(Read_File(parameter, data, row, col)){ ///call read file function
        if(*row == 0 || *col == 0){///check row and col
            printf("File is empty.\n");
        }
        else {
            printf("%s is Matrix %dx%d\n",parameter,*row,*col);
            for(i = 0; i < *row; i++) {
                printf("|");
                for(j = 0; j < *col; j++) {
                    printf("%4d",data[i][j]);  /// print data in file
                }
                printf("   |");
                printf("\n");
            }
        }
    }
}

void Build_File(char parameter[][10],int count){
if(count < 1) printf("too few parameter for function 'Generate': generate [filename] [attribute]\n");       ///check file name and out file name
    else if(count > 1) printf("too many parameter for function 'Generate': generate [filename] [attribute]\n");  ///check file name and out file name
    else {
        FILE *fp;
        fp = fopen(parameter[0],"w"); ///open file
        int row,col,value;
        printf("Enter no. row of matrix %s [0-100]: ",parameter[0]);     row = Get_Int(0,100); ///input row data
        printf("Enter no. column of matrix %s [0-100]: ",parameter[0]);  col = Get_Int(0,100); ///input col data
        printf("%s is Matrix %d x %d \n",parameter[0],row,col);         fprintf(fp,"%-3d%-3d\n",row,col);  ///save row and data in text
        for(int i=1;i<=row; i++){
            for(int j=1;j<=col; j++){
                printf("input data[%d][%d]: ",i,j);
                scanf("%d",&value);  ///input data
                fprintf(fp,"%d ",value);  ///save data in file
            }
        fprintf(fp,"\n");
        }
        printf("Build success\n");
        fclose(fp);  ///close file
        }
}

void Show(char parameter[][10], int count){ /// Show matrix
    if(count < 1) printf("too few parameter for function 'Show': show [filename]\n");       ///check file name and out file name
    else if(count > 1) printf("too many parameter for function 'Show': show [filename]\n"); ///check file name and out file name
    else {
        int data[10][10];
        int row, col;
        Pre_Data(parameter[0], data, &row, &col); ///call present data function
    }
}

void Transpose(char parameter[][10], int count){ /// Transpose matrix
    if(count < 2) printf("too few parameter for function 'Transpose': transpose [input file] [output file]\n");            ///check file name and out file name
    else if(count > 2) printf("too many parameter for function 'Transpose': transpose [input file] [output file]\n");      ///check file name and out file name
    else {
        int data[10][10];
        int i, j, row, col;
        Pre_Data(parameter[0], data, &row, &col);///Show data
        FILE *fp;
        fp = fopen(parameter[1], "w");          ///create or open file
        fprintf(fp, "%d %d\n", col, row);       ///save row and col in file
        for(i = 0; i < col; i++){
            for(j = 0; j < row; j++){
                fprintf(fp, "%d ", data[j][i]); ///save data in file
            }
            fprintf(fp, "\n");
        }
        fclose(fp);      ///close file
        Pre_Data(parameter[1], data, &row, &col);///Show output file
    }
}

void Add(char parameter[][10], int count){ /// Add matrix
    if(count < 3) printf("too few parameter for function 'Add': add [input file 1] [input file 2] [output file]\n");        ///check file name and out file name
    else if(count > 3) printf("too many parameter for function 'Add': add [input file 1] [input file 2] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data1[10][10], data2[10][10];
        int i, j, row1, col1, row2, col2;
        Pre_Data(parameter[0], data1, &row1, &col1); ///call present data function
        Pre_Data(parameter[1], data2, &row2, &col2); ///call present data function
        if(row1 == row2 && col1 == col2) { ///check matrix1 = matrix2
            fp = fopen(parameter[2], "w");  /// open or create file
            fprintf(fp, "%d %d\n", row1, col2);
            for(i = 0; i < row1; i++){
                for(j = 0; j < col2; j++){
                    fprintf(fp, "%d ", data1[i][j] + data2[i][j]); /// save out data in file
                }
                fprintf(fp, "\n");
            }
            fclose(fp); ///close file
            Pre_Data(parameter[2], data1, &row2, &col1);///call precent data output
        }
        else printf("Cannot add matrix because two matrix are not same dimension.\n");
    }
}

void Subtract(char parameter[][10], int count){ /// subtract matrix
    if(count < 3) printf("too few parameter for function 'Subtract': subtract [input file 1] [input file 2] [output file]\n");        ///check file name and out file name
    else if(count > 3) printf("too many parameter for function 'Subtract': subtract [input file 1] [input file 2] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data1[10][10], data2[10][10];
        int i, j, row1, col1, row2, col2;
        Pre_Data(parameter[0], data1, &row1, &col1);///Show data from file1
        Pre_Data(parameter[1], data2, &row2, &col2);///Show data from file2
        if(row1 == row2 && col1 == col2) {///check row and col between file
            fp = fopen(parameter[2], "w");///create or open file
            fprintf(fp, "%d %d\n", row1, col2);
            for(i = 0; i < row1; i++){
                for(j = 0; j < col2; j++){
                    fprintf(fp, "%d ", data1[i][j] - data2[i][j]);///sace output data in file
                }
                fprintf(fp, "\n");
            }
            fclose(fp);///close file
            Pre_Data(parameter[2], data1, &row2, &col1);///Show output data
        }
        else printf("Cannot subtract matrix because two matrix are not same dimension.\n");
    }
}

void Scalar_Multiplication(char parameter[][10], int count){ /// subtract matrix
    if(count < 2) printf("too few parameter for function 'Scalar Multiplication': scalarmultiplication [input file 1] [output file]\n");        ///check file name and out file name
    else if(count > 2) printf("too many parameter for function 'Scalar Multiplication': scalar_multiplication [input file 1] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data[10][10];
        int i, j, row, col;
        Pre_Data(parameter[0], data, &row, &col); ///call precent data
            printf("input scalar :");
            int sa=Get_Int(-10000000,1000000);  ///input scalar
            fp = fopen(parameter[1], "w");      ///open or create file
            fprintf(fp, "%d %d\n", row, col);
            for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                    fprintf(fp, "%d ", data[i][j] * sa); ///save output in file
                }
                fprintf(fp, "\n");
            }
            fclose(fp);///close file
            Pre_Data(parameter[1], data, &row, &col);///Show output data
    }
}

int  Matrix_Multiplication(char parameter[][10], int count) {
     if(count < 3) printf("too few parameter for function 'Matrix Multiplication': matrixmultiplication [input file 1] [input file 2] [output file]\n");        ///check file name and out file name
    else if(count > 3) printf("too many parameter for function 'Matrix Multiplication': matrixmultiplication [input file 1] [input file 2] [output file]\n");  ///check file name and out file name
    else {
        FILE *fp;
        int data1[10][10],data2[10][10],data3[10][10];
        int i, j, m, row1, col1, row2, col2, row3, col3;
        Pre_Data(parameter[0], data1, &row1, &col1); ///call data 1	
        Pre_Data(parameter[1], data2, &row2, &col2); ///call data 2
        if (col1 == row2) { ///check row and col
            row3 = row1;	
            col3 = col2;
            fp = fopen(parameter[2], "w");      ///open or create file
            fprintf(fp, "%d %d\n", row3, col3);
            for (i =0; i < row3; i++){
                for (j=0; j< col3; j++){
                    for (data3[i++][j] = 0,m = 0; m < col1; m++){
                        data3[i][j] = data3[i][j]+data1[i][m]*data2[m][j];
                    }
                 fprintf(fp, "%d ",data3[i][j]); ///save data in file
                }
            fprintf(fp, "\n");
            }
        fclose(fp); ///close file
        Pre_Data(parameter[2], data3, &row3, &col3);	///show output data 
        }
        else {
            printf("Can't Multiply Matrix [col[A]=row[B]]\n");
        }
    }
}

void  Help_User(){
    printf("===========================================================================================================================\n");
    printf("| >'generate'(g) [filename] [attribute]                                   | create file text and data                     |\n");
    printf("| >'show' [filename]                                                      | Show data in file                             |\n");
    printf("| >'Transpose'(t) [input file] [output file]                              | Transpose file input to output                |\n");
    printf("| >'add'(a) [input file 1] [input file 2] [output file]                   | Add matrix between file input to output       |\n");
    printf("| >'subtract'(s) [input file 1] [input file 2] [output file]              | subtract matrix between file input to output  |\n");
    printf("| >'scalarmultiplication'(sm) [input file 1] [output file]                | multiply matrix and scalar input to output    |\n");
    printf("| >'matrixmultiplication'(mm) [input file 1] [input file 2] [output file] | multiply matrix between file input to output  |\n");
    printf("| >'cls'                                                                  | clear screen                                  |\n");
    printf("===========================================================================================================================");
    printf("\n\n");
}

int main(){
    char key[100], command[10], parameter[3][10];
    int count;
    Help_User();
    do{
        count = 0;
        printf("Users:\\command>");
        gets(key);
        Separate_Space(key, command, parameter, &count);
        if(strlen(key)){ /// select commands
            if(strcmp(command, "show")==0) Show(parameter, count);
            else if(strcmp(command, "generate")==0 || strcmp(command, "g")==0)
                Build_File(parameter, count);
            else if(strcmp(command, "transpose")==0|| strcmp(command, "t")==0)
                Transpose(parameter, count);
            else if(strcmp(command, "add")==0 || strcmp(command, "a")==0)
                Add(parameter, count);
            else if(strcmp(command, "subtract")==0 || strcmp(command, "s")==0)
                Subtract(parameter, count);
            else if(!strcmp(command, "scalarsultiplication") || !strcmp(command, "sm")==0)
                Scalar_Multiplication(parameter, count);
            else if(!strcmp(command, "matrixmultiplication") || !strcmp(command, "mm")==0)
                Matrix_Multiplication(parameter, count);
            else if(strcmp(command, "cls")==0){
                system("cls"); Help_User();		}
            else if(strcmp(command, "end") && strcmp(command, "exit"))
                printf("%s is not a command.\n", command);
        }
    }while(strcmp(command, "end") && strcmp(command, "exit"));
    return 0;
}
