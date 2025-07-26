#include <stdio.h>

void stringcopy(char *s, char *t) {
    while (*t) {
        *s++ = *t++;
    }
}

int main() {
    char a[] = "@#Hello World!";
    stringcopy(a, a + 2);
    printf("%s", a);
    return 0;
}
