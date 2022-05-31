#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "hrushov"

int main(int argc, char ** argv) {
	sem_t *sem;
	if (argc != 2) 
	{
		if ((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED)
		{
			fprintf(stderr, "hrushov sem_open error");
			return 1;
		}
		printf("hrushov sem_open. hrushov semaphore is taken.\nwaiting for it to be dropped.\n");
		if (sem_wait(sem) < 0)
			fprintf(stderr, "hrushov sem_wait error");
		if (sem_close(sem) < 0)
			fprintf(stderr , "hrushov sem_close error ");
		return 0;
	}
	else
	{
		printf("Dropping hrushov semaphore...\n");
		if ((sem = sem_open (SEMAPHORE_NAME, 0)) == SEM_FAILED)
		{
			fprintf(stderr, "hrushovs sem_open error");
			return 1;
		}
		sem_post(sem);
		printf("hrushov sem_post. hrushov semaphore dropped. \n");
		return 0;
	}
}