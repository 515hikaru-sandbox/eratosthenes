// 双子素数のリストアップ

#include <stdio.h>

#define N 10000

void initialize(int *, int, int);
void eratosthenes(int *, int);

int main() {
    int flgs[N];
    eratosthenes(flgs, N);
    for(int i = 0; i < N - 2; i++){
        if(flgs[i] == 1 && flgs[i + 2] == 1) printf("%d, %d\n", i, i + 2);
    }
    return 0;
}


void initialize(int *a, int size, int initial){
    for(int i = 0; i < size; i++){
        a[i] = initial;
    }
    return;
}

void eratosthenes(int *flgs, int size) {
    initialize(flgs, N, 1);
    for(int i = 0; i < size; i++) {
        if(i < 2) {
            flgs[i] = 0;
            continue;
        }
        for(int j = i * 2; j < N; j += i) {
            flgs[j] = 0;
        }
    }
    return;
}

