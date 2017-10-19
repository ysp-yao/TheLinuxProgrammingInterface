

#include "../lib/tlpi_hdr.h"


#include <stdlib.h>

#include <fcntl.h>



int dup_(int oldfd){

  int newfd = fcntl(oldfd, F_DUPFD, 0); 
  // int newfd = fcntl(oldfd, F_DUPFD); // error 

  if (newfd == -1){
    errExit("dup");
  }

  return newfd;
}

int dup2_(int oldfd, int newfd){

  int flags;

  flags = fcntl(oldfd, F_GETFL);
  if (flags == -1){
    errno = EBADF;
    return -1;
  }

  flags = fcntl(newfd, F_GETFL);
  if (flags == -1){
    errno = EBADF;
    return -1;
  }


}


int main(int argc, char *argv[]){

  int newfd;

  newfd = dup_(1);

  printf("%d\n", newfd);

  close(newfd);
  close(2);

  newfd = dup_(1);

  printf("%d\n", newfd);

  newfd = dup2_(10,12);
  if (newfd == -1){
    errExit("dup2_");
  }


  exit(EXIT_SUCCESS);
}
