
#include <signal.h>



int main(int argc, int *argv[]) {

  if ( argc > 1 && strcmp(argv[1], "--help")) {
    usageErr("%s [init-seq-num]\n", argv[0]);
  }

  if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
    errExit("signal");
  }


}
