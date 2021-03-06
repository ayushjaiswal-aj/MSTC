unsigned long write(int fd, void* buffer, unsigned long buffer_size);
void _exit(int);

int main(void){
	write(1, "Ayush Jaiswal\n", 15);
	_exit(0);
}
