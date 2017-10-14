

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  
  // int getopt(int argc, char * const argv[], const char *optstring);

  int opt;
  char *file_name = NULL;
  int output_fd;

  while((opt = getopt(argc, argv, "a:")) != -1){
    switch(opt){
      // printf("%c\n", opt);
      case 'a': 
        file_name = optarg;        
        break;
      case '?':
      // Unrecognized option
        break;
      case ':':
      // Missing argument
        break;
      default:  
      // Unexpected case in switch()
        break;
    }
  }  

  if (file_name == NULL){
//    output_fd = open(argv[1], );
  }
  else{
    output_fd = open(file_name, O_CREAT|O_APPEND|O_WRONLY, S_IRUSR|S_IWUSR); 
  }
   

  char buf[1024];
  ssize_t num_read;
  while(1){
    num_read = read(STDIN_FILENO, buf, 1024);
    if (num_read == -1){
      
    }
    printf("%s", buf);

    write(output_fd, buf, num_read);
  }
    

  if(close(output_fd)==-1){
    printf("sss\n");
  }

 
    printf("zzz\n");

  exit(EXIT_SUCCESS);
}
