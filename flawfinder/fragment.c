#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void func1()
{	
char buffer[1024];
printf("Please enter your user id :");
fgets(buffer, 1024, stdin);
if (!isalpha(buffer[0]))
     {   
char errormsg[1044]; 
strncpy(errormsg, buffer,1024);   
strcat(errormsg, " is not  a valid ID");
 	}
}


/* f2d and f3d are file descriptors obtained after opening files*/
void func2(int f2d) {   
char *buf2;	
size_t len;    
read(f2d, &len, sizeof(len));   
buf = malloc(len+1);   
read(f2d, buf2, len);  
buf2[len] = '\0';
} 

void func3(int f3d){   
char *buf3;
int i, len;
read(f3d, &len, sizeof(len));
if (len > 8000) { 
error("too long"); 
return; 
}
      
buf3 = malloc(len);     
read(f3d, buf3,len);         
}


void main()
{
char *boo = "boooooooooooooooooooooooooooooooooooooooooooooo";
char *buffer = (char *)malloc(10 * sizeof(char));
strcpy(buffer, boo);
func1();
func3(len(*boo));
FILE *aFile = fopen("/tmp/tmpfile", "w");
fprintf(aFile, "%s", "hello world")
fclose(aFile);
}


