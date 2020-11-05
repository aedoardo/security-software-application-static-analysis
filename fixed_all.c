#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

ssize_t func1() {
    char buffer[1024];
    if(fgets(buffer, 1024, stdin) != NULL) {
        if(!isalpha(buffer[0])) {
            char errormsg[1044];
            strlcpy(errormsg, buffer, 1024);
            strlcat(errormsg, " is not a valid ID", sizeof(errormsg));
            return -1;
        }
    }
    
    return 0;
}

ssize_t func2(int f2d) {
    char *buf2 = NULL;
    size_t len = 0;
    size_t limit = 1024;
    ssize_t returnvar = 0;

    returnvar = read(f2d, &len, sizeof(len));

    if(returnvar < 0)
        return -1;

    if(len > limit)
        return -1;

    buf2 = calloc(len + 1, sizeof(char));

    if(buf2 == NULL)
        return -1;

    returnvar = read(f2d, buf2, len);
    if(returnvar < 0) {
        free(buf2);
        return -1;
    }

    buf2[returnvar] = '\0';
    free(buf2);
    return 0;
}

ssize_t func3(int f3d) {
    char *buf3 = NULL;
    size_t len = 0;
    ssize_t returnvar = 0;
    returnvar = read(f3d, &len, sizeof(len));

    if(returnvar < 0)
        return -1;
    
    if(len > 8000) 
        return -1;

    buf3 = calloc(len + 1, sizeof(char));

    if(buf3 == NULL)
        return -1;

    returnvar = read(f3d, buf3, len);

    if(returnvar < 0) {
        free(buf3);
        return -1;
    }

    buf3[returnvar] = '\0';

    free(buf3);
    return 0;
}

int main() {
    char *boo = "boooooooooooooooooooooooooooooooooooooooooooooo";
    char *buffer = (char *)malloc(10 * sizeof(char));
    ssize_t returnvar = 0;

    if(buffer == NULL) {
        // buffer is not allocated, so error
        return -1;
    }

    strlcpy(buffer, boo, sizeof(buffer));
    returnvar = func1();

    if(returnvar < 0) {
        free(buffer);
        return -1;
    }

    int intlengthboo = (int)(sizeof(*boo));
    
    returnvar = func3(intlengthboo);

    if(returnvar < 0) {
        free(buffer);
        return -1;
    }

    FILE *aFile = freopen("/tmp/tmpfile", "w", stdout);

    if(aFile == NULL) {
        // error
        free(buffer); // avoid memory leaks
        return -1;
    }

    int retfprint = 0;
    retfprint = fprintf(aFile, "%s", "hello world");

    if(retfprint < 0) {
        free(buffer);
        return -1;
    }

    (void) fclose(aFile);

    free(buffer); // release memory

    return 0;
}