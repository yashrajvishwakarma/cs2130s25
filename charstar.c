#include <stdio.h>
#include <stdlib.h>


size_t mystrlen(const char *s) {
    size_t i = 0;
    do {
        if (s[i] != '\0') {
            i++;
        }
    } while (s[i] != '\0');
    return i;
}

char *simple_split(char *s, char delim) {
    if ((s == NULL) || (s[0] == '\0')) {
        return NULL;
    }
    int i = 0;
    do {
        if (s[i] != delim) {
            i++;
        }
    } while (s[i] != delim);

    if (s[i] == delim) {
        s[i] = '\0';
        return &s[i+1];
    }
    return NULL;


}


int main(void) {
char *s = strdup("can all aardvarks quaff?");
char *bit = simple_split(s, 'a');
puts(s);
puts(bit);
free(s);

}




