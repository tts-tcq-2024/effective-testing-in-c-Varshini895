#include <stdio.h>
#include <assert.h>

int printColorMap(int n) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
            if((i * 5 + j - 1) == n){
                return i * j;
            }
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap(24);
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
