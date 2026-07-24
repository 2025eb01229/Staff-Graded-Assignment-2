#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int fd;
    char buffer[100];
    fd = open("employees.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1){
        printf("File could not be opened.\n");
        return 1;
    }
    write(fd, "101 Ridhi HR\n", 13);
    write(fd, "102 Ram IT\n", 11);
    write(fd, "103 Mohit Sales\n", 16);
    lseek(fd, 13, SEEK_SET);
    write(fd, "Smriti", 6);
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, 100);
    printf("%s", buffer);
    close(fd);
    return 0;
}
