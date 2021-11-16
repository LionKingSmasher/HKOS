#include <stdarg.h>
#include <HKOS.h>

extern void __attribute__((weak)) __io_format(const u8);

int printk(const PCHAR msg, ...) {
	int index = 0; // index
	va_list ap;
	va_start(ap, *msg);
	while(msg[index] != 0){
		__io_format(msg[index]);
	}
	va_end(ap);
}

int scank(const PCHAR msg, ...) {
	// TODO
}