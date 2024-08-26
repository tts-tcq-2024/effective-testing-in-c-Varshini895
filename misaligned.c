#include <stdio.h>
#include <assert.h>
#include <string.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

void TestPrintColorMap() {
    // Redirect stdout to a string buffer
    char buffer[1024];
    FILE* pipe = popen("./color_map", "r"); // execute the compiled program and read output
    if (pipe == NULL) {
        perror("popen");
        return;
    }
    
    // Read the output into buffer
    size_t bytesRead = fread(buffer, 1, sizeof(buffer) - 1, pipe);
    buffer[bytesRead] = '\0'; // Null-terminate the string
    pclose(pipe);
    
    // Test Case 1: Verify the sequence number
    assert(strstr(buffer, "0 | White | Blue") != NULL);
    assert(strstr(buffer, "24 | Violet | Slate") != NULL);
    
    // Test Case 2: Verify the combination of major and minor colors
    assert(strstr(buffer, "1 | White | Orange") != NULL);
    assert(strstr(buffer, "5 | Red | Blue") != NULL);
    
    // Test Case 3: Verify the total number of lines printed
    int lineCount = 0;
    for(char* p = buffer; *p != '\0'; p++) {
        if(*p == '\n') lineCount++;
    }
    assert(lineCount == 25);
    
    // Check the return value
    assert(lineCount == 25);
    
    printf("All test cases passed!\n");
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    TestPrintColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
