#include <stdio.h>

long power10(int x) 
{
    long o = 1;
    for (int i = 0; i < x; i++) {
        o = o * 10;
    }
    return o;
}

int ziffern(int z[], int länge, long n) 
{
    for (int i = 0; i < länge; i++) {
        z[i] = n / power10(länge - i-1);
        n -= z[i] * power10(länge - i-1);
    }
    return 0;
}

int zahllänge(long x) {
    int o = 0;
    long i = 1;
    
    while (1) {
        if (x > i)
            o += 1;
        else
            return o;
        i = i * 10;
    }
}

int count(int liste[], int l, int x) {
    int o = 0;
    for (int i = 0; i < l; i++) {
        if (liste[i] == x)
            o += 1;
    }
    return o;
}

int main()
{
    long n;
    printf("Zahl: ");
    scanf("%ld", &n);
    int länge = zahllänge(n);
    
    int z[länge];
    ziffern(z, länge, n);

    int usrin;
    printf("Ziffer: ");
    scanf("%d", &usrin);

    printf("Anzahl von \"%d\"in %ld: %d\n", usrin, n, count(z, länge, usrin));
    return 0;
}