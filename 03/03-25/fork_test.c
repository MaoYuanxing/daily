#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
	// pid_t pid_1 = fork();
	// pid_t pid_2 = fork();
	// pid_t pid_3 = fork();

	// printf("Hello World from (%d, %d, %d)\n", pid_1, pid_2, pid_3);
	for (int i = 0; i < 2; i++)
	{
		fork();
		printf("Hello\n");
	}
	for (int i = 0; i < 2; i++)
	{
		wait(NULL);
	}
}
