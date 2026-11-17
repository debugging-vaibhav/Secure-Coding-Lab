#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(5 * sizeof(int));
    if (p == NULL) {
        return 1;
    }
    p[0] = 10;
    printf("p[0] = %d\n", p[0]);

    free(p);
    free(p);
    return 0;
}
