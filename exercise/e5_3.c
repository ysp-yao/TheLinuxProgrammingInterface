

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <fcntl.h>



int main(int argc, char *argv[]){

  if (argc != 3 || strcmp(argv[1], "--help")==0){
    usageErr("%s filename num-bytes [x]\n", argv[0]);
  }

  int fd;
  if((fd=open(argv[1], O_CREAT | O_RDWR  |O_APPEND, S_IRUSR| S_IWUSR))==-1){
    errExit("open");
  }
  
  char byte = 'c';

  int max = getInt(argv[2]); 
  int i;
  for (i=0;i<max;++i){
    if(write(fd, &byte, 1)==-1){
      errExit("write");
    }
  }

  close(fd);

  exit(EXIT_SUCCESS);
}
