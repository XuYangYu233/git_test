#include<stdio.h>

void st_copy(char *destination, char *source){
    char *ptr_a, *ptr_b;
    ptr_a = source;
    ptr_b = destination;
    while(*ptr_a!='\0'){
        *ptr_b = *ptr_a;
        ptr_b++;
        ptr_a++;
    }
    *ptr_b = '\0';
}

int main(){
    char str1[128], str2[128];
    printf("«Î ‰»Îstr2:");
    scanf("%s", str2);
    st_copy(str1, str2);
    printf("str1Œ™:%s\n",str1);

    return 0;
}