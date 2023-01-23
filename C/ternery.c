#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(){

    char *str1 = "aa";
    char *str2 = "aa";
    char *str3 = "aab";

    !strcmp(str1, str1)?printf("\nStrings are same:%s\n", str1):printf("\nStrings are unique:%s & %s\n", str1, str2);
    !strcmp(str1, str3)?printf("\nStrings are same:%s\n", str1):printf("\nStrings are unique:%s & %s\n", str1, str3);

    return 0;

}
