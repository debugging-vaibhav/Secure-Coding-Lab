#include <stdio.h>
#include <stdlib.h>

void process(void) {
    char *buf = malloc(64);
    if (buf == NULL) {
        return;
    }
    snprintf(buf, 64, "Hello, no memory leak");
    printf("%s\n", buf);
    free(buf);
}

int main(void) {
    process();
    return 0;
}
