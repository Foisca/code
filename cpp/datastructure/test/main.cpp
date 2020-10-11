#include<stdio.h>
#include<stdlib.h>
void show(){
    FILE *fp;
    int beds;
    float price;
    char name[100];
    if(NULL==(fp=fopen("E:\\data.txt","r"))){
        printf("Open file error ");
        exit(0);
    }

    while (!feof(fp)){
        fscanf(fp,"%s %f,%d",name,&price,&beds);
        // printf("%s %f,%d\n",name,price,beds);
        printf("%s %f %d\n",name,price,beds);
        
    }
}
int main(){
    show();
}