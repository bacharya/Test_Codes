#include "stdio.h"
#include "string.h"


static int longest = 0;
static int idx = -1;
int max(int a, int b){
    return a>b?a:b;
}

int palindrome_check(char *str, int m){

    int i, len;

    len=strlen(str);
    i=0;
    while(m>0 && i<=m){
        if(str[m-i] != str[m+i])
            break;
        i++;
    }
    return 2*(i-1)+1;
}

int palindrome(char *str, int l, int h){
    int m, res;
    if(l<h){
        if((h-l) == 1){
            if(str[l] != str[h])
                res = 1;
            else
                res = 2;
            if(res > longest){
                longest = res;
                idx = l;
            }
            return res;
        }

        m = (l+h)/2;
        res = palindrome_check(str, m);
        if(res > longest){
            longest = res;
            idx = res/m;
        }
        return(max(palindrome(str, l, m), palindrome(str, m+1,h)));
    }
}

int main(){

    char *str = "aaaaamalaabcyalama";
    //char *str = "baab";
    //char *str = "aa";
    int len;

    len = strlen(str)-1;

    printf("\nGiven string is:%s and len:%d", str, len+1);
    palindrome(str,0,len);
    printf("\nMaximum length of the palidrome substring is:%d at index:%d\n", longest, idx);
    return 0;
}
