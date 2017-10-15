

#include "tlpi_hdr.h"



#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int agrc, char *agrv[]){
  
  printf("hello world\n");

  int fd;
  fd = open("hole", O_RDWR | O_CREAT|O_TRUNC, S_IRUSR | S_IWUSR);
  if (fd == -1){
    errExit("%s", "open");
  }

  if (lseek(fd, 15, SEEK_SET) == -1){

  }


  char buf[1024] = "c";
  if (write(fd, buf, 1) == -1){

  }

  if(read(fd, buf, 16)==-1){

  }

  int i;
  for (i=0;i<16;++i){
    printf("%c\n", buf[i]);
  }

  if(close(fd)==-1){

  }


  exit(EXIT_SUCCESS);
}
