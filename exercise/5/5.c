


#include "../lib/tlpi_hdr.h"

#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

  int fd1, fd2, fd3;

  fd1 = open("file5_6", O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR );
  fd2 = dup(fd1);
  fd3 = open("file5_6",O_RDWR);

  write(fd1, "hello,", 6);
  write(fd2, "world", 6);
  
  lseek(fd2, 0, SEEK_SET);  

  write(fd1, "HELLO,", 6);
  write(fd3, "Gidday", 6); 


  exit(EXIT_SUCCESS);
}
