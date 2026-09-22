#include <stdio.h>
#include <stdlib.h>

void process(void) {
    char *buf = malloc(64);
    if (buf == NULL) {
        return;
    }
    snprintf(buf, 64, "Hello, memory leak");
    printf("%s\n", buf);
}

int main(void) {
    process();
    return 0;
}
