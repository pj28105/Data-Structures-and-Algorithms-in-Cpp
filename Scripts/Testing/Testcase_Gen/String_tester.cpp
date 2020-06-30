#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 100);
    for(int i = 0; i < n; ++i) {
        char x = 'a' + rand(0,25);
        printf("%c", x);
    }
    printf("\n");
}