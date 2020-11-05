#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void func1()
{	
     char buffer[1024];
     printf("Please enter your user id :");
     if(fgets(buffer, 1024, stdin) != NULL) {
     
          if (!isalpha(buffer[0])){   
               char errormsg[1044]; 
               strncpy(errormsg, buffer, 1024);   
               strcat(errormsg, " is not  a valid ID");
          }
     }
}


/* f2d and f3d are file descriptors obtained after opening files*/

/*@unused@*/ 
void func2(int f2d) {   
     size_t len = 0;    
     ssize_t retvar = read(f2d, &len, sizeof(len)); // signed size_t

     if(retvar < 0) {
          // we have an error
     } else {
          // give memory to buf2
          char *buf2 = calloc(len + 1, sizeof(char));   
          // check the buf2
          if(buf2 == NULL) {
               // give some error
          }

          // re-use retvar to check the length of read
          retvar = read(f2d, buf2, len);
          if(retvar < 0 || retvar == NULL) {
               // free the memory and handle an error
               free(buf2);
               return; // return, otherwise we'll free twice the buffer memory.
          } else {
               buf2[retvar] = '\0'; // add terminator
               free(buf2); // free the memory to avoid memory leaks
          }
     }
} 
/*@unused@*/

void func3(int f3d){   
     char *buf3 = NULL;
     int len = 0;
     ssize_t returnvar = 0;
     returnvar = read(f3d, &len, sizeof(len));
     if(returnvar < 0) {
          // show some error and return
          return;
     } else {
          if (len > 8000) { 
               perror("too long"); 
               return; 
          }

          // initialize buf3.
          buf3 = calloc((size_t)len, sizeof(char));
          returnvar = read(f3d, buf3, len);
          if(returnvar < 0) {
               // show some error and free
               free(buf3);
               return;
          } else {
               // success and free buf3
               free(buf3);
          }
         
     }
           
}


void main()
{
     char *boo = "boooooooooooooooooooooooooooooooooooooooooooooo";
     char *buffer = (char *)malloc(10 * sizeof(char));

     if(buffer == NULL) {
          // buffer is not allocated, so error
          return -1;
     }

     strcpy(buffer, boo);
     func1();

     int intlengthboo = (int)(sizeof(*boo));
     func3(intlengthboo);

     FILE *aFile = fopen("/tmp/tmpfile", "w");

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


