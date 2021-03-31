#include<iostream>


struct S{
    int x;
    char y;
}  a, b;

int main(void){
    a.x = 10;
    b = a;
    printf("%d", b.x);
}

struct S  b,a = { 10 , 'a'};

int main (void){
    b = a;
    printf("%d %c", b.x , b.y);
}

