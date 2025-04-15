/*************************************************
 * CS 2130 Homework 7
 * Spring 2023 - Writing C
 *
 * Computing ID: wsm7rw
 ************************************************/

// ===============================================
// Write your functions here:

void titlecase(char *s) {
    int i = 1;
    while (s[i] != '\0') {
        if (s[i-1] == ' ' && s[i] > 90) { // ascii values
            s[i] -= 32;
            i++;
        }
        else {
            i++;
        }
    }
}

long recpow(long x, unsigned char e) {
    if (e == 1) {
        return x;
    }
    if (e == 0) {
        return 1;
    }
    else {
        return (x * recpow(x,e-1));
    }
}

unsigned long nextprime(unsigned long x) {
    if (x == 2) {
        return 3;
    }
    if (x == 0 || x == 1) {
        return 2;
    }

    else {
    for (unsigned long i = x+1; i <= 2*x; i++) {
        int z = 1;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                z = 0;
                break;
            }
        }
        if (z == 1) {
            return i;
        }
    }
    }


    

}

void pull0(int *arr, unsigned length) {
    
}

int nondup(int *arr, unsigned length) {
    int f = 0;
    for(int i = 0; i < length; i++) {
        f = f^arr[i]; // 0 ^ arr[i] = arr[i], arr[i] ^ arr[i] = 0

    }
    return f;
}

void fibarray(unsigned short *dest, unsigned num) { // place first num fibonacci numbers into dest

    if (num == 1) {
        dest[0] = 1;
    }
    else if (num == 2) {
        dest[0] = 1;
        dest[1] = 1;
    }

    else {
        dest[0] = 1;
        dest[1] = 1;
        dest[2] = 2;
    for (unsigned i = 3; i < num; i++) {
        dest[i] = dest[i-1] + dest[i-2];
    }
    }
}
// TODO: Write functions here





// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Update the followng main function to test your
// code.  You should test normal input values as
// well as edge cases.  Do NOT rely only on the
// Gradescope submission site, as submissions are
// limited.
// Note: You must leave this comment block to ensure
// proper grading of your submission.


int main() {
    // TODO: Add tests here
    return 0;
}
