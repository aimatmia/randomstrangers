#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


int gen_rand() { //generates a random int
   int fd;
   int random;
   fd = open("/dev/random", O_RDONLY);
   //printf("fd: %d \n", fd);
   if (fd < 0) 
      printf("error: %d - %s\n", errno, strerror(errno));
   read(fd, &random, 4);
   close(fd);
   return abs(random);
}

int main(){

//populating array with random #s
   printf("Generating random numbers: \n");
   int i=0;
   int arr[10];
   while (i<10) {
        int rand = gen_rand();
        printf("\t random #%d: %d \n", i, rand);
        arr[i] = rand;
        i++;
   }

//writing array into file random.txt
   printf("\n Writing numbers to file... \n");
   int fd;
   fd = open("random.txt", O_CREAT, 0666);
   close(fd);
   fd = open("random.txt", O_RDWR);
   write(fd, arr, 10*sizeof(int));
   close(fd);

//reading file into other array
   printf("\n Reading numbers from file... \n");
   fd = open("random.txt", O_RDONLY);
   int arr2[10];   
   read(fd, arr2, 10*sizeof(int));
   close(fd);
 
//printing numbers from other array
   printf("\n Verifying that numbers match... \n");
   i = 0;
   while (i<10) {
        printf("\t random #%d: %d \n", i, arr2[i]);
        i++;
   }


   return 0;
     
}
