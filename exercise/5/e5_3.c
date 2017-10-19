

#include "../lib/tlpi_hdr.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <fcntl.h>



int main(int argc, char *argv[]){
/*
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
*/
    int numBytes, j, flags, fd;
    Boolean useLseek;

    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file num-bytes [x]\n"
                 "        'x' means use lseek() instead of O_APPEND\n",
                 argv[0]);

    useLseek = argc > 3;
    flags = useLseek ? 0 : O_APPEND;
    numBytes = getInt(argv[2], 0, "num-bytes");

    fd = open(argv[1], O_RDWR | O_CREAT | flags, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");

    for (j = 0; j < numBytes; j++) {
        if (useLseek)
            if (lseek(fd, 0, SEEK_END) == -1)
                errExit("lseek");
        if (write(fd, "x", 1) != 1)
            fatal("write() failed");
    }

    printf("%ld done\n", (long) getpid());
    exit(EXIT_SUCCESS);
}
