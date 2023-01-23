#include "stdio.h"
#include "math.h"

#define ADD_BM 0x01
#define UPDATE_BM 0x02
#define DEL_BM 0x04

void
print_binary(int n){
    int size = sizeof(n);
    int i, tmp=0, j =0;
    char str[36] = {0}, st[3] = {0}, space = ' ';
    for(i=0;i<(8*size);i++){
        tmp = 1 & (n>>i);
        snprintf(st, 2, "%d",tmp);
        str[34-j] = st[0];
        j++;
        if((i%8) == 7){
            str[34-j] = space;
            j++;
        }
    }
    printf("%s\n",str);
}


int main() {

    unsigned int a = 20, b=5, c =0, k, l, r, root, max = 0xFFFF;
    int d = -3, pos=3, res;
    printf("\na=%i\n", a);
    printf("\nb=%i\n", b);
    c = (a^b);
    k = (int)(log2(c));
    printf("\nPosition k=%i\n", k);
    root = a&(max<<(k+1));
    l = a^root;
    r = b^root;
    printf("\nroot=%i\n", root);
    printf("\nl=%i\n", l);
    print_binary(l);
    printf("\nr=%i\n", r);
    print_binary(r);
    printf("\nd=%d, d=%u\n", d, d);
    print_binary(d);
    printf("\nleft-shift: d=%i\n", d>>2);
    print_binary(d>>2);
    printf("\nright-shift: d=%i\n", d<<2);
    print_binary(d<<2);
    d = 0;
    printf("\nd=%i\n", d);
    print_binary(d);
    printf("\nleft-shift: d=%i\n", d>>2);
    printf("\nright-shift: d=%i\n", d<<2);
    
    d = 23;
    printf("\nTogle %dth bit of d=%d\n", pos, d);
    print_binary(d);
    
    res = 1 &(d>>pos);
    res = res==1?(d&(~(1<<pos))):(d|(1<<pos));
    printf("\nTogle result=%d\n", res);
    print_binary(res);

    //printf("\na=%i\n", ~a);
    //printf("\na<<8=%i\n", (~a)<<1);
    //printf("\na>>8=%i\n", a|a>>8);
    //
    /*
    printf("Is Add:\n");
    a |= ADD_BM;
    printf("\n %i",a);
    printf("Is chg:\n");
    a |= UPDATE_BM;
    printf("\n %i",a);
    for(int i=1;i<=2;i++)
        a<<i;
    printf("\na<<8=%i\n", (~a)<<1);
    */
    return 0;
}
