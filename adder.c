#include<stdio.h>
#include<string.h>

int main(int argc, const char* argv[]) {
    char st[10];
    int a, b;
    float c, d;
    char e[30], f[30];

        if (argc > 1) {
        if (strcmp(argv[1], "-s") == 0) {
            strcpy(st, "S");
        } 
        else if (strcmp(argv[1], "-i") == 0) {
            strcpy(st, "I");
        } 
        else if (strcmp(argv[1], "-f") == 0) {
            strcpy(st, "F");
        } 
        else {
            printf("Invalid flag supplied\n");
            return 0;
        }
    }

    else {
    printf("What type of values do you want to add? ");
    scanf("%s", st);
    }

    if (strcmp(st, "S") == 0) {
        printf("Enter the first value: ");
        scanf("%10s", e);
        printf("Enter the second value: ");
        scanf("%10s", f);
        strcat(e, f);
        printf("%s\n", e);
    }

    else if (strcmp(st, "I") == 0) {
        printf("Enter the first value: ");
        scanf("%d", &a);
        printf("Enter the second value: ");
        scanf("%d", &b);
        a = a + b;
        printf("The result is %d\n", a);
    }
    else if (strcmp(st,"F") == 0) {
        printf("Enter the first value: ");
        scanf("%f", &c);
        printf("Enter the second value: ");
        scanf("%f", &d);
        c = c+d;
        printf("The result is %.6f\n", c);
    } 

    return 0;
}