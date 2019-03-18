#include <stdio.h>
#include <dlfcn.h>

int main() {
	void *addr = dlopen("libadd.so", RTLD_LAZY);

	if (addr == NULL) {
			return 1;
		}

	int (*p)(int, int) = dlsym(addr, "add");
	
	printf("10 + 20 = %d \n", p(10, 20));

	return 0;
}
