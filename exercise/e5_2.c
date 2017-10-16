

#include "tlpi_hdr.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]){

  int fd;
  if((fd=open("test_file_e5_2", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR))==-1){
    errExit("open");
  }

  char buffer[1024];
  memset(buffer, 'c', 1024);
  if(write(fd, buffer, 10)==-1){
    errExit("write");
  }
  
  if(close(fd)==-1){
    errExit("close");
  }
 
  if((fd=open("test_file_e5_2", O_RDWR|O_APPEND, S_IRUSR|S_IWUSR))==-1){
    errExit("open");
  }

  off_t offset;
  if ((offset=lseek(fd, 0, SEEK_SET))==-1){
    errExit("lseek");
  }
  
  memset(buffer, 'd', 1024);
  if(write(fd, buffer, 5)==-1){
    errExit("write");
  }

  if(close(fd)==-1){
    errExit("close");
  }

  exit(EXIT_SUCCESS);
}
