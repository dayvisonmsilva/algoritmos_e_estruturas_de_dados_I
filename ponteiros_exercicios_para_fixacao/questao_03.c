#include <stdio.h>

int main(void) {
    int a, b, c, d;
    int *p1; 
    int *p2 = &a; // p2 -> &a
    int *p3 = &c; // p3 -> &c
    p1 = p2; // p1 -> p2 -> &a
    *p2 = 10; // *p2, *p1 = 10 = a 
    b = 20; // b = 20
    int **pp;
    pp = &p1; // pp -> &p1 -> &a -> a = 10
    *p3 = **pp; // p3 -> &pp 
    int *p4 = &d; // p4 -> &d
    *p4 = b + (*p1)++; // *p4 -> 20 + 10
    // (a = a+1 = 10 + 1)

    // a = 11, b = 20, c = 10, d = 30 
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);
    return 0;
}