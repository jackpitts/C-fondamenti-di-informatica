#include <stdio.h>

int main (){
    int n, c=0;

    scanf("%d", &n);

    for(char i='a'; c<n; i++){
        printf("%c ", i);
        c++;
        if(i=='z') i='a'-1;
    }
    
    return 0;

}