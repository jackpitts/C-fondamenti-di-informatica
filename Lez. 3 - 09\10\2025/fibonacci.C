#include <stdio.h>

int main (){
    int n, curr, s1, s2;
    scanf("%d", &n);
    s1 = 1;
    s2 = 1;
    for (int i = 0; i < n-2; i++) {
        if(i==0){
            printf("%d %d ", s1, s2);
        }
        curr = s1 + s2;
        s1 = s2;
        s2 = curr;
        printf("%d ", curr);
    }
    return 0;
}