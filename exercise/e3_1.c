#include "tlpi_hdr.h"

#include <unistd.h>
#include <linux/reboot.h>


int main(int argc, char *argv[]){


  printf("LINUX_REBOOT_MAGIC1 in 16 is:%x\n", LINUX_REBOOT_MAGIC1);
  printf("LINUX_REBOOT_MAGIC2 in 16 is:%x\n", LINUX_REBOOT_MAGIC2);
  printf("LINUX_REBOOT_MAGIC2A in 16 is:%x\n", LINUX_REBOOT_MAGIC2A);
  printf("LINUX_REBOOT_MAGIC2B in 16 is:%x\n", LINUX_REBOOT_MAGIC2B);
  printf("LINUX_REBOOT_MAGIC2C in 16 is:%x\n", LINUX_REBOOT_MAGIC2C);

  printf("Linus Torvalds and his three daughters' birthday. Day Mon Year\n");


  exit(EXIT_SUCCESS);
}
