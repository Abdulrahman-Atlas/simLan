#include <stdio.h>
#include<string.h>
#include<stdlib.h>
//***********************************************strToInt***********************************************
int strToInt(char string[]){
int length=strlen(string);
int mult=1;
int intvalue=0;
while(0<length){
if (!(string[length-1] >= '0' && string[length-1] <= '9')){
        length--;
        continue;
    }
intvalue=intvalue+(string[length-1]-'0')*mult; 

mult*=10;
length--;
}
if(string[0]=='-'){
	return intvalue*(-1);
}
else
return intvalue;
}

//**************************************************jmpe**************************************************
void jmpeSimLan(char line[],FILE *ptr, int nums[]){
int jmpline;
int index1, index2;

int i=0;
//parsing...
int r=5; //first 'r'egister index
int comma=0;
char ind1[3], ind2[3], jmp[5];

while(line[comma]!=','){
    comma++;
}
int BegOfIndx1=comma-r-1;
while(i<BegOfIndx1){
    ind1[i]=line[r+1];
    r++;
    i++;
}
ind1[i]= '\0';
index1=strToInt(ind1);
r=comma+1; // this is second 'r'egister index
i=0;
while(line[r+1]!=','){
ind2[i]=line[r+1];
r++;
i++;
}
ind2[i]='\0';
index2=strToInt(ind2);
comma=r+1;
int end=0;
while(line[end]!='\n'){
    end++;
}
int BegOfCons=end-comma-1;
i=0;
while(i<BegOfCons){
    jmp[i]=line[comma+1];
    comma++;
    i++;
}
jmp[i]='\0';
jmpline=strToInt(jmp);

if(nums[index1]==nums[index2]){
char temp[32];
i=1;
fclose(ptr);
ptr=fopen("program.TXT","r");
while(i<jmpline){
    fgets(temp, 32, ptr);
    i++;
}
}
else return;
}

//**************************************************jmpu**************************************************
void jmpuSimLan(char line[],FILE *ptr){
    int jmpline;
//parsing...
int space=4; //space is always on the 4th index of buffer
int end=0;
int i=0;
while(line[end] != '\n')
end++;
char jmp[5];
int BegOfCons=end-space-1;
while(i<BegOfCons){
jmp[i]=line[space+1];
space++;
i++;
}
jmpline=strToInt(jmp);

char temp[100];
i=1;
fclose(ptr);
ptr=fopen("program.TXT","r");
while(i<jmpline){
    fgets(temp, 100, ptr);
    i++;
}
}
  
//**************************************************put**************************************************
void putSimLan(char line[], int nums[]){
    int cons; //constant
    int index; 
//parsing...
int i=0;
    while(line[i]!=','){
        i++;
    }
int space=3;     //space index  
char c[10];      // 'C'onstant
int j=0;
    while(line[space+1] != ','){
        c[j]=line[space+1];
        j++;
        space++;
    }
    c[j]='\0';
cons=strToInt(c);
char x[3]; //inde'X'    
i=0;
    while(line[i]!='r'){
    i++;
    }
    // now i is 'r' index
j=0;    
    while(line[i+1]!='\n'){
        x[j]=line[i+1];
        i++;
        j++;
    }
x[j]='\0';

index=strToInt(x);

    nums[index]=cons;
}

//**************************************************add**************************************************
void addSimLan(char line[], int nums[]){
int index1;
int index2;
//parsing...
int i=0;
char x1[3];
char x2[3];
int r = 4; //index of first r
while(line[i] != ','){
    i++;
}
//i has the index of comma
int j=0;
int BegOfIndx1=i-r-1;
while(j < BegOfIndx1){
    x1[j]=line[r+1];
    j++;
    r++;
}
x1[j]='\0';

index1=strToInt(x1);
j=0;
while(line[j]!='\n'){
    j++;
}
        //j has the end of string
r=i+1;  //to get the second r after the comma
int BegOfIndx2=j-r-1;
i=0;
while(i < BegOfIndx2){
    x2[i]=line[r+1];
    i++;
    r++;
}
x2[i]='\0';
index2=strToInt(x2);
nums[index2]+=nums[index1];
}

//**************************************************prn**************************************************
void prnSimLan(char line[], int nums[]){

    int index;
    
//parsing...
int r=4;
int end=0;

    while(line[end] != '\n'){
    end++;
    }
int i=0;
char x1[3];
int BegOfI=r+1;
    while(i < (end-r-1)){
        x1[i]=line[BegOfI];
        i++;
        BegOfI++;
    }
x1[i]='\0';
index=strToInt(x1); 
printf("%d\n",nums[index]);
}

//*********************************************starts_with*********************************************
int swith(char line[], char phrase[]){
if(line[0]==phrase[0]&&line[1]==phrase[1]&&line[2]==phrase[2]&&line[3]==phrase[3])
return 1;
else
return 0;
}


int main()
{
int reg[32];
char buffer[32];
FILE *pF;
/*
pF=fopen("program.TXT","r");
if(pF==NULL){
    printf("ERROR: file was not opened succesfully!\n");
    exit(1);
}
printf("input:\n\n");
while(fgets(buffer,32,pF) != NULL){
    if(swith(buffer,"halt"))
        {
        printf("%s",buffer);
        fclose(pF);
        }

    else 
    printf("%s",buffer);
}
printf("\n\noutput:\n\n");
*/


pF=fopen("program.TXT","r");

if(pF==NULL){
    printf("ERROR: file was not opened succesfully!\n");
    exit(1);
}

while(fgets(buffer,32,pF) != NULL){
    if(swith(buffer,"halt"))
        {
        printf("Successful Execution");
        return 0;
        }

    else if(swith(buffer,"put "))  
        putSimLan(buffer,reg);  

    else if(swith(buffer,"add "))
        addSimLan(buffer,reg);

    else if(swith(buffer,"jmpe"))
        jmpeSimLan(buffer,pF,reg);

    else if(swith(buffer,"jmpu"))
        jmpuSimLan(buffer,pF);

    else if(swith(buffer,"prn "))
        prnSimLan(buffer,reg);

    else
        continue; 
}
return 0;
} 