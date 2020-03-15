#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "string.h"
#include "stdlib.h"

// 成功则返回只写文件描述符，失败返回-1
// int creat(const char *path, mode_t mode);

// 等价于 int open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);

// demo
int main(void)
{
    char *cwd, *seperator = "/";
    size_t size = 64;
    cwd = (char*)malloc(size);

    getcwd(cwd, size);

    char *file_name = "test_creat";

    char *absolute_file_path = (char*)malloc(strlen(cwd) + strlen(file_name) + 1);

    strcpy(absolute_file_path, cwd);
    strcat(absolute_file_path, seperator);
    strcat(absolute_file_path, file_name);

    int fd = creat(absolute_file_path, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (fd == -1) {
        perror("cannot create new file\n");
    } else {
        printf("create new file [%s] success.", absolute_file_path);
    }

}
