#include<stdio.h>

void rmv(char *str){ 
    int count=0,i;
    for(i=0;str[i];i++){
        if(str[i]!=' '){
            str[count++]=str[i];
        }
    }
    str[count]=0;
} 

int main(){ 
    char str[]="Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    rmv(str);
    printf("%s  \"s\" \n",str);
    //puts(str);
    if(isdigit(str[0])) printf("e um numero");
    else printf("nao ]e");
    printf("<i>sara<i>tuma");
    return 0;
}