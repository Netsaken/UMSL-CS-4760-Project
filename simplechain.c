#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char *argv[]) {
   pid_t childpid = 0;
   int i, option, index, status;
   int k = 1;
   int m = 3;
   int n = 4;
   int nchars = 80;

   //Command line options
   while ((option = getopt (argc, argv, ":hp:c:s:i:")) != -1) {
      switch (option)
         {
         case 'h':
            printf("h is working!\n");
            return 1;
            break;
         case 'p':
            //Number of processes
            n = atoi(optarg);
            break;
         case 'c':
            //Number of characters to read from stdin
            nchars = atoi(optarg);
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
      return 1;
   }

   //Initialize char array for stdin
   char c;
   int cpos = 0;
   char mybuf[nchars];

   //Construct format for "perror"
   char* title = argv[0];
   char report[] = ": Error";
   char* message = strcat(title, report);

   //Reset processes to 4 if no number was passed through
   if (n == 0) {
      n = 4;
   }

   for (i = 1; i < n; i++) {
      if (childpid = fork()) {
         if (childpid < 0) {
            perror(message);
         }
         break;
      }
   }

   //Loop through processes and print information
   for (i = 1; i < k + 1; i++) {
      sleep(m);

      wait(NULL);
      if (wait(&status) < 0) {
         perror(message);
      }
      
      while ((c != EOF) && (cpos < nchars)) {
      c = getchar();
      mybuf[cpos] = c;
      cpos++;
      }

      mybuf[nchars] = '\0';
      fprintf(stderr, "process ID:%ld: %s\n", (long)getpid(), mybuf);
   }

   return 0;
}