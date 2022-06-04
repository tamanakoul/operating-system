
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
//case1	
void childTask() {
	  printf("WELCOME TO CSE DEPARTMENT\n");
}
 
void parentTask() {
	  printf("Main task in execution\n");
}
 
int main(void) {
	  pid_t pid = fork();
	   
	    if(pid == 0) {
		        childTask();
			    exit(EXIT_SUCCESS);
			      }
	      else if(pid > 0) {
		          wait(NULL);
			      parentTask();
			        }
	      					   
	    else{
		    printf("Unable to create child process.");
		 }
					    
		 return EXIT_SUCCESS;
}

//CASE2 WAITS FOR TERMINATION OF THE CHILD
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main(void) {
	  for(int i = 1; i <= 5; i++) {
		      pid_t pid = fork();
		       
		          if(pid == 0) {
				        printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
					      exit(0);
					          }
			      else  {
				            printf("Parent process => PID=%d\n", getpid());
					          printf("Waiting for child processes to finish...\n");
						        wait(NULL);
							      printf("child process finished.\n");
							          }
			        }
	   
	    return EXIT_SUCCESS;
}

//CASE 3 PROCESS IDENTIFIER
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main(void) {
	  pid_t pid = fork();
	   
	    if(pid == 0) {
		        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
			    exit(EXIT_SUCCESS);
			      }
	      else if(pid > 0) {
		          printf("Parent => PID: %d\n", getpid());
			      printf("Waiting for child process to finish.\n");
			          wait(NULL);
				      printf("Child process finished.\n");
				        }
	        else {
			    printf("Unable to create child process.\n");
			      }
		 
		  return EXIT_SUCCESS;
}
