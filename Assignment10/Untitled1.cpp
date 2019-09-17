#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int Load_Data_File (int data[], int *count){
	FILE *fp;
	int success = 0,num=0;
	num=*count;
	int a;
	fp = fopen("TXT100000.TXT", "r"); // open file in code folder
	if (fp != NULL){ //check file
		while (fscanf(fp, "%d", &a)== 1){ //scan number data
		data[num] = a;     //save data in array
		num += 1;
		}
	fclose(fp);   //close file
	printf(" Total %d records write to file %s \n", count, "TXT100000");
	return num;     //retuen count data
	}
	else {
		printf("Error can't write data to file %s \n", "TXT100000");
		return 0;
	}
}

int main(){

	int data[100000];
	int data2[100000];
	int count = 0,count_str_txt=0,count_str_bin=0;
	double t;

	count_str_txt=Load_Data_File(data,&count);              //count data from text

	printf("\nRead File Complete\n\n");


}


