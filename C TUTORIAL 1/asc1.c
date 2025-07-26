#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char num[1000];
    int l,i,a;
    scanf("%s",num);
    l=strlen(num);
    for(i=0;i<=l;i++){
        if (num[i]>=48&&num[i]<=57){
            a++;
        }
    }
    printf("%d  ",a);
    return 0;
}
