#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - prints PID and PPID
 *
 * Return: 0
 */
int main(void)
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("pid: %u\n", pid);
	printf("ppid: %u\n", ppid);

	return (0);
}
