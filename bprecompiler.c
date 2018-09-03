#include <stdio.h>
#include <string.h>

FILE *in, *out;

int main(int argc, char** argv){
	{//parse the args to open the right files
		in=fopen("input","r");
		if (in==NULL){
			perror("can't open input file");
			return 1;
		}
		//out=fopen("output","w");
		out=stdout;
		if (out==NULL){
			perror("can't open output file");
			return 2;
		}
	}
	{//check []
		int counter=0;
		int temp;
		do{
			temp=fgetc(in);
			switch(temp){
				case '[':	counter++; break;
				case ']':	counter--; break;
			}
		}while(temp!=EOF);
		if (counter!=0){
			perror("the ammount of [ and ] doesn't match");
			return 3;
		}
	}
	{//copy all bf instructions to out
		fseek(in,0,SEEK_SET);
		int temp;
		do{
			temp=fgetc(in);
			if (strchr("+-><.,[]",temp)!=NULL && temp!='\0')
				fputc(temp,out);
		}while(temp!=EOF);
	}
	{//close the files
		fclose(out);
		fclose(in);
	}
}
