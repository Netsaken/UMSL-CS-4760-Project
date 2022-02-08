#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
   pid_t childpid = 0;
   int i, option, index;
   int k = 1;
   int m = 3;
   int n = 4;

   while ((option = getopt (argc, argv, ":hp:cs:i:")) != -1) {
      switch (option)
         {
         case 'h':
            printf("h is working!\n");
            break;
         case 'p':
            //Number of processes
            n = atoi(optarg);
            break;
         case 'c':
            printf("c (nchars goes here) is working!\n");
            break;
         case 's':
            //Sleep time 'm', in seconds
            m = atoi(optarg);
            break;
         case 'i':
            //Number of iterations 'k'
            k = atoi(optarg);
            break;
         case '?':
            printf("Usage: %s -p [# of processes]\n",argv[0]);
            return 1;
         default:
            break;
      }
   }

   for (index = optind; index < argc; index++) {
      printf ("Non-option argument %s\n", argv[index]);
   }

   //Reset processes to 4 if no number was passed through
   if (n == 0) {
      n = 4;
   }

   for (i = 1; i < n; i++)
      if (childpid = fork())
         break;

   for (i = 1; i < k + 1; i++) {
      sleep(m);
      wait;
      fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
         i, (long)getpid(), (long)getppid(), (long)childpid);
   }

   return 0;
}