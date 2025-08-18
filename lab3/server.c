#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <num1> <op> <num2>\n", argv[0]);
        return 1;
    }

    int opr1 = atoi(argv[1]);
    int opr2 = atoi(argv[3]);
    char opr = argv[2][0];

    int result;
    if (opr == '+') {
        result = opr1 + opr2;
    } else {
        result = opr1 - opr2;
    }

    // Warning: exit code limited to 0-255
    exit(result & 0xFF);
}
