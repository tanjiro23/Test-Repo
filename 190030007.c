#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void func(int i, int n, char *st) {
	if (i < n) {
		printf("%c	%d\n", st[i], (int)getpid());
		sleep(rand() % 4 + 1);
		int proc = fork();
		int wc = wait(NULL);
		if (!proc) {
			func(i + 1, n, st);
		}
	}
	return;
}

int main() {
	char st[] = "Hello World";
	func(0, 11, st);
	return 0;
}
