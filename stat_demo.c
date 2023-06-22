#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void main(){

	struct stat info;
	int fd = open("demo.txt", O_RDONLY);
	fstat(fd, &info);
	printf(" inode: %d\n", (int) info.st_ino);
	printf(" device_id: %d\n", (int) info.st_dev);
	printf(" mode of device: %08x\n", info.st_mode);
	printf("\n User id: %d", (int) info.st_uid);
	printf("\n Group id: %d", (int) info.st_gid);
	printf("\n size of file: %d \n\n", (int) info.st_size);
	close(fd);
}
