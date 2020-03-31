#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SECTOR 512


int main(){
    char* buf;
    int res = posix_memalign((void**)&buf, 512, 8192);
    int lba;
    int size;
    
    printf("Start LBA: ");
    scanf("%d", &lba);
    printf("Size: ");
    scanf("%d", &size);

    int fd = open("/dev/sda", __O_DIRECT);
    if (fd == -1){
        printf("Failed to open\n");
    }
    lseek(fd, SECTOR * lba, SEEK_SET);
    read(fd, buf, SECTOR * size);

    close(fd);
}